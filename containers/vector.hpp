/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:06:06 by jferrer-          #+#    #+#             */
/*   Updated: 2023/01/30 05:08:14 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

//#include <iostream>
#include <memory>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cstddef>
//#include <type_traits>
#include "../utils/utils.hpp"
#include "iterator.hpp"
// #include <cstddef>
// # include <tgmath.h>
//# include <typeinfo>

#define EXTENDED false

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class vector
{

public:

	typedef T																value_type;
	typedef Alloc															allocator_type;
	typedef typename allocator_type::reference								reference;
	typedef typename allocator_type::const_reference						const_reference;


	typedef typename allocator_type::size_type								size_type;
	typedef typename allocator_type::difference_type						difference_type;
	typedef typename allocator_type::pointer								pointer;
	typedef typename allocator_type::const_pointer							const_pointer;


	// typedef ft::iterator<T*>				iterator;
	// typedef ft::iterator<const T*>	const_iterator;
	typedef ft::iterator<std::random_access_iterator_tag, T>				iterator;
	typedef ft::iterator<std::random_access_iterator_tag const, T const>	const_iterator;

	typedef ft::reverse_iterator<iterator>									reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;

private:

	Alloc			_alloc;
	pointer			_vector_pointer;
	size_type		_size;
	size_type		_capacity;

public:

	/*									vector constructors									*/

	explicit vector (const allocator_type& alloc = allocator_type()): _alloc(alloc), _vector_pointer(nullptr) , _size(0), _capacity(0)
	{
		// _vector_pointer = _alloc.allocate(_capacity);
	}

	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(n), _capacity(n)
	{
		if (!n)
			return ;
		_vector_pointer = _alloc.allocate(_capacity);

		for (size_type i = 0; i < _capacity; i++)
			_alloc.construct(&_vector_pointer[i], val);
	}

	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
	 typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
	 : _alloc(alloc), _size(0), _capacity(0) //vector.hpp line 528
	{
		ptrdiff_t range = std::distance(first, last);
		if (range == 0)
			return ;
		else if (EXTENDED && !iterators_are_valid(first, last)) //This behaviour is undefined in c++98 but i prefer to throw an exception
        	throw std::invalid_argument("Invalid input iterators");
		_size = range;
		_capacity = _size;
		_vector_pointer = _alloc.allocate(_capacity);

		for (size_type i = 0; first != last; first++, i++)
			_alloc.construct(&_vector_pointer[i], *first);
	}
	
	vector (const vector& x): _alloc(x._alloc), _size(x._size), _capacity(x._capacity)
	{
		if (!x._capacity)
			return ;
		_vector_pointer = _alloc.allocate(_capacity);

		for (size_type i = 0; i < x._size; i++)
			_alloc.construct(&_vector_pointer[i], x._vector_pointer[i]);
	}

	vector<value_type, allocator_type>& operator=(const vector& x)
	{
		if (_capacity)
		{
			size_t i = 0;
			for (pointer temp = &(_vector_pointer[0]); i < _size; temp++, i++)
				_alloc.destroy(temp);
			_alloc.deallocate(_vector_pointer, _capacity);
		}
		_alloc = x._alloc;
		_size= x._size;
		_capacity = x._capacity;
		if (!_capacity)
			return *this;
		_vector_pointer = _alloc.allocate(_capacity);
		for (size_type i = 0; i < x._capacity; i++)
			_alloc.construct(&_vector_pointer[i], x._vector_pointer[i]);
		return *this;
	}

	~vector()
	{
		if (!_capacity)
			return ;
		size_t i = 0;
		for (pointer temp = &(_vector_pointer[0]); i < _size; temp++, i++)
			_alloc.destroy(temp);
		_alloc.deallocate(_vector_pointer, _capacity);
	}

	/*								Iterators								*/
	iterator begin()													{ return (iterator(this->_vector_pointer)); }
	const_iterator begin() const 										{ return (const_iterator(this->_vector_pointer)); }

	iterator end()														{ return (iterator(&(_vector_pointer[_size]))); }
	const_iterator end() const											{ return (const_iterator(&(_vector_pointer[_size]))); }

	reverse_iterator rbegin()											{ return reverse_iterator(end()); }
	const_reverse_iterator rbegin() const								{ return const_reverse_iterator(end()); }

	reverse_iterator rend()												{ return reverse_iterator(begin());	}
	const_reverse_iterator	rend() const								{ return const_reverse_iterator(begin());	}

	/*								Capacity								*/

	size_type size() const										{ return _size; }
	size_type max_size() const									{ return std::min<size_type>(_alloc.max_size(), std::numeric_limits<difference_type>::max()); }

	void resize (size_type n, value_type val = value_type())
	{
		if (n < _size)
			while (_size != n)
				_alloc.destroy(_vector_pointer + --_size);
		else
		{
			if (_capacity * 2 < n)
				reserve(n);
			else if (_capacity < n)
				reserve(_capacity * 2);
			else if (!_capacity && n)
				reserve(n);
			while (_size != n)
			{
				_alloc.construct(&_vector_pointer[_size], val);
				_size++;
			}
		}
	}
	size_type capacity() const									{ return _capacity; }
	bool empty() const											{ return _size == 0; }
	void reserve(size_type n)
	{
		if (!(n > _capacity)) // _capacity always >= 0 so if n == 0 always true
			return ;
		pointer temp = _alloc.allocate(n);
		for (size_type i = 0; i < _size; i++)
			// temp[i] = _vector_pointer[i];
			_alloc.construct(&temp[i], _vector_pointer[i]);
		if (_capacity)
			_alloc.deallocate(_vector_pointer, _capacity);
		_capacity = n;
		_vector_pointer = temp;
	}

	// /*								Element access							*/

	reference operator[](size_type n)							{ return _vector_pointer[n]; }
	const_reference operator[](size_type n) const				{ return _vector_pointer[n]; }
	reference at(size_type n)									{ return _vector_pointer[n]; } //in later versions it throws std::out_of_range
	const_reference at(size_type n) const						{ return _vector_pointer[n]; } //in later versions it throws std::out_of_range
	reference front()											{ return *_vector_pointer; }
	const_reference front() const								{ return *_vector_pointer; }
	reference back()											{ return _vector_pointer[_size - 1]; }
	const_reference back() const								{ return _vector_pointer[_size - 1]; }

	// /*								Modifiers								*/

	// template <class InputIterator>
	// typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type
	// void assign (InputIterator first, InputIterator last)
	// {
	// 	for (InputIterator temp = first; temp != last; temp++)
	// 		_alloc.construct(&_vector_pointer[i], *temp);
	// }
	// void assign (size_type n, const value_type& val)
	// {
		
	// }

	void push_back (const value_type& val)
	{
		if (_size == _capacity)
			(!_capacity) ? this->reserve(1) : this->reserve(_capacity * 2);
		_alloc.construct(&_vector_pointer[_size], val);
		_size++;
	}
	void pop_back()
	{
		if (_size)
			_alloc.destroy(_vector_pointer + --_size);
	}

	// iterator insert (iterator position, const value_type& val)						{ }
	// void insert (iterator position, size_type n, const value_type& val)				{ }
	// template <class InputIterator>
	// 	void insert (iterator position, InputIterator first, InputIterator last)	{ }

	// iterator erase (iterator position)												{ }
	// iterator erase (iterator first, iterator last)									{ }

	// void swap (vector<value_type, allocator_type>&)												{ }
	// void clear()																	{ }
	
	// /*								Allocator								*/

	// allocator_type get_allocator() const											{ }



private:

	/*								Not a std::vector() Function								*/
	template<class InputIterator>
	typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type
	iterators_are_valid(InputIterator first, InputIterator last)
	{
		try 
		{
			if (std::distance(first, last) < 0)
				throw std::invalid_argument("Input iterators are invalid.");
		} catch (const std::exception& e) { return false; }
		for (InputIterator i = first; i != last; ++i)
		{
			try
			{
				typename ft::iterator_traits<InputIterator>::value_type value = *i;
				(void)value;
			} catch (const std::exception& e) { return false; }
		}
		return true;
	}
};

template <class T, class Allocator>
	bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
	bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
	bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
	bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
	bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
	bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);


// specialized algorithms:
template <class T, class Allocator>
	void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);



}

#endif