/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:06:06 by jferrer-          #+#    #+#             */
/*   Updated: 2023/02/23 22:07:45 by jferrer-         ###   ########.fr       */
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
	typedef ft::random_access_iterator<value_type>				iterator;
	typedef ft::random_access_iterator<const value_type>	const_iterator;

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
		ptrdiff_t range = ft::distance(first, last);
		if (range == 0)
			return ;
		// else if (EXTENDED && !iterators_are_valid(first, last)) //This behaviour is undefined in c++98 but i prefer to throw an exception, when EXTENDED == true only
        // 	throw std::invalid_argument("Invalid input iterators");
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

		for (size_type i = 0; i < x._capacity; i++)
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
		// if (_capacity == 3)
		// size_type temp_capacity = _capacity;
		// _capacity = 0;
		// std::cerr << "size = " << _size << " xdxxdd\n";
		// std::cerr << "capacity = " << _capacity << " xdxxdd\n";
		if (!_capacity)
			return ;
		size_t i = 0;
		for (pointer temp = &(_vector_pointer[0]); i < _capacity; temp++, i++)
			_alloc.destroy(temp);
		_alloc.deallocate(_vector_pointer, _capacity);
		_capacity = 0;
		_size = 0;
	}

	/*								Iterators								*/
	iterator begin()													{ return (iterator(this->_vector_pointer)); }
	const_iterator begin() const 										{ return (const_iterator(this->_vector_pointer)); }

	iterator end()														{ return (iterator(this->_vector_pointer + _size)); }
	const_iterator end() const											{ return (const_iterator(this->_vector_pointer + _size)); }

	reverse_iterator rbegin()											{ return reverse_iterator(iterator(_vector_pointer + _size - 1)); }
	const_reverse_iterator rbegin() const								{ return const_reverse_iterator(iterator(_vector_pointer + _size - 1)); }

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
		pointer temp = nullptr;
		try
		{
			temp = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&temp[i], _vector_pointer[i]);
		}
		catch(...) { throw; }
		size_t i = 0;
		for (pointer temp = &(_vector_pointer[0]); i < _size; temp++, i++)
			_alloc.destroy(temp);
		if (_capacity)
			_alloc.deallocate(_vector_pointer, _capacity);
		_capacity = n;
		_vector_pointer = temp;
		
		
	}

	// /*								Element access							*/

	reference operator[](size_type n)							{ return _vector_pointer[n]; }
	const_reference operator[](size_type n) const				{ return _vector_pointer[n]; }
	reference at(size_type n)									{ assert(n < size()); return _vector_pointer[n]; } //in later versions it throws std::out_of_range
	const_reference at(size_type n) const						{ assert(n < size()); return _vector_pointer[n]; } //in later versions it throws std::out_of_range
	reference front()											{ assert(!empty()); return *_vector_pointer; }
	const_reference front() const								{ assert(!empty()); return *_vector_pointer; }
	reference back()											{ assert(!empty()); return _vector_pointer[_size - 1]; }
	const_reference back() const								{ assert(!empty()); return _vector_pointer[_size - 1]; }

	// /*								Modifiers								*/

	template <class InputIterator>
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
	assign (InputIterator first, InputIterator last)
	{
		ptrdiff_t range = ft::distance(first, last);
		// if (EXTENDED && !iterators_are_valid(first, last)) //This behaviour is undefined in c++98 but i prefer to throw an exception, when EXTENDED == true only
		// 	throw std::invalid_argument("Invalid input iterators");
		while (_size)
			_alloc.destroy(_vector_pointer + --_size);
		this->reserve(range);
		for (InputIterator temp = first; temp != last; temp++, _size++)
			_alloc.construct(&_vector_pointer[_size], *temp);
	}
	void assign (size_type n, const value_type& val)
	{
		// if (EXTENDED && n < 0) //This behaviour is undefined in c++98 but i prefer to throw an exception, when EXTENDED == true only
		// 	throw std::invalid_argument("Invalid size_type");
		while (_size)
			_alloc.destroy(_vector_pointer + --_size);
		this->reserve(n);
		while (_size != n)
		{
			_alloc.construct(&_vector_pointer[_size], val);
			_size++;
		}
	}

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

	iterator insert (iterator position, const value_type& val)
	{
		assert(begin() <= position && position <= end());
		vector<T> strong_guarantee(*this);
		size_type index = position - begin();
		if (_size == _capacity)
			reserve(_capacity * 2);
		size_t i = _size;
		try
		{
			for (; i > index; --i)
			{
				_alloc.construct(&_vector_pointer[i], _vector_pointer[i - 1]);
				_alloc.destroy(_vector_pointer + i - 1);
			}
			_alloc.construct(&_vector_pointer[i], val);
			_size++;
		}
		catch(...)
		{
			this->swap(strong_guarantee);
			throw;
		}

		return iterator(begin() + index);
	}
	
	void insert (iterator position, size_type n, const value_type& val)
	{
		assert(begin() <= position && position <= end());
		vector<T> strong_guarantee(*this);
		size_type index = position - begin();
		if (_size + n > _capacity)
		{
			if (_size + n < _capacity * 2)
				reserve(_capacity * 2);
			else
				reserve(_size + n);
		}
		size_t i = _size;
		try
		{
			for (; i > index; --i)
			{
				_alloc.construct(&_vector_pointer[i + n - 1], _vector_pointer[i - 1]);
				_alloc.destroy(_vector_pointer + i - 1);
			}
			for (i = 0; i < n; i++)
				_alloc.construct(&_vector_pointer[i + index], val);
			_size += n;
		}
		catch(...)
		{
			this->swap(strong_guarantee);
			throw;
		}
	}

	template <class InputIterator>
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
	insert (iterator position, InputIterator first, InputIterator last)
	{
		assert(begin() <= position && position <= end());
		vector<T> strong_guarantee(*this);
		difference_type diff = ft::distance(first, last);
		size_type index = position - begin();
		InputIterator temp = first;
		if (_size + diff > _capacity)
		{
			if (_size + diff < _capacity * 2)
				reserve(_capacity * 2);
			else
				reserve(_size + diff);
		}
		size_t i = _size;
		try
		{
			for (; i > index; --i)
			{
				_alloc.construct(&_vector_pointer[i + diff - 1], _vector_pointer[i - 1]);
				_alloc.destroy(&(_vector_pointer[i - 1]));
			}
			for (i = 0; i < diff; i++, temp++)
				_alloc.construct(&_vector_pointer[i + index], *temp);
		}
		catch(...)
		{
			this->swap(strong_guarantee);
			throw;
		}
		_size += diff;
	}





	// iterator erase(iterator pos) //implementation of the original version of erase c++98 (tests don't like it)
	// {
	// 	if (pos + 1 != end()) {
	// 		std::swap(*pos, *(end() - 1));
	// 	}
	// 	pop_back();
	// 	return pos;
	// }

	// iterator erase(iterator position) //implementation of the new version of erase and more efficient in most cases except in test cases with small data elements
	// {
	// 	if (position + 1 != end())
	// 		std::copy(position + 1, end(), position);
	// 	--_size;
	// 	destroy(this->_vector_pointer + _size);
	// 	return position;
	// }

	iterator erase( iterator pos )//implementation of the new version of erase and usually less efficient but the most liked by the tests 
	{
		assert(begin() <= pos && pos < end());
		// vector<T> strong_guarantee(*this);
		// try
		// {
			size_type index = pos - begin();
			_alloc.destroy(this->_vector_pointer + index);//check this
			for (size_type i = index; i < _size; ++i)
			{
				_alloc.construct(&_vector_pointer[i], _vector_pointer[i + 1]); //this is better but usually less optimal
				// _vector_pointer[i] = _vector_pointer[i + 1];
			}
		// }
		// catch(...)
		// {
		// 	this->swap(strong_guarantee);
		// 	throw;
		// }
		
		_size--;
		return pos;
	}

	iterator erase (iterator first, iterator last)
	{
		assert(begin() <= first && first < end());
		// vector<T> strong_guarantee(*this);
		// try
		// {
			difference_type index = first - begin();
			for (iterator temp = first; temp != last; index++, temp++)
				_alloc.destroy(this->_vector_pointer + (temp - begin()));
			if (first + 1 != end())
				std::copy(last, end(), first);
		// }
		// catch(...)
		// {
		// 	this->swap(strong_guarantee);
		// 	throw;
		// }
		difference_type len = last - first;
		_size -= len;
		while (len)
			_alloc.destroy(this->_vector_pointer + _size + --len);
		
		return first;
	}

	void swap (vector& other)
	{
		std::swap(_size, other._size);
		std::swap(_capacity, other._capacity);
		std::swap(_vector_pointer, other._vector_pointer);
		std::swap(_alloc, other._alloc);
	}

	void clear()
	{
		while (_size)
			_alloc.destroy(_vector_pointer + --_size);
	}
	
	// /*								Allocator								*/

	allocator_type get_allocator() const { return _alloc; } 



private:

	/*								Not a std::vector() Function								*/
	template<class InputIterator>
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type
	iterators_are_valid(InputIterator first, InputIterator last)
	{
		try
		{
			if (ft::distance(first, last) < 0)
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
	bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		if (x.size() != y.size())
			return false;
		for (size_t i = 0; i < x.size(); i++)
			if (x[i] != y[i])
				return false;
		return true;
	}
template <class T, class Allocator>
	bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		if (x.size() < y.size())
			return true;
		else if (x.size() > y.size())
			return false;
		for (size_t i = 0; i < x.size(); i++)
		{
			if (x[i] < y[i])
				return true;
			else if (x[i] > y[i])
				return false;
		}
		return false;
	}
template <class T, class Allocator>
	bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return (!(x == y));
	}
template <class T, class Allocator>
	bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		if (x.size() > y.size())
			return true;
		else if (x.size() < y.size())
			return false;
		for (size_t i = 0; i < x.size(); i++)
		{
			if (x[i] > y[i])
				return true;
			else if (x[i] < y[i])
				return false;
		}
		return false;
	}
template <class T, class Allocator>
	bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return (!(x < y));
	}
template <class T, class Allocator>
	bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return (!(x > y));
	}


// specialized algorithms:
// template <class T, class Allocator>
// 	void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);


	template <class T, class A>
	void swap(vector<T, A> &v1, vector<T, A> &v2 ) {
		v1.swap(v2);
	}
};

namespace std
{
	template <class T, class A>
		void swap(ft::vector<T, A> &v1, ft::vector<T, A> &v2 ) {
			v1.swap(v2);
		}
};

#endif