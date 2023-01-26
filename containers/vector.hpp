/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:06:06 by jferrer-          #+#    #+#             */
/*   Updated: 2023/01/26 02:23:20 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

//#include <iostream>
#include <memory>
#include <algorithm>
#include <iterator>
//#include <type_traits>
#include "../utils/utils.hpp"
#include "iterator.hpp"
// #include <cstddef>
// # include <tgmath.h>
//# include <typeinfo>

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class vector
{

public:

	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;


	typedef typename allocator_type::size_type			size_type;
	typedef typename allocator_type::difference_type	difference_type;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;

	typedef MyIterator<vector, T>								iterator;
	//typedef implementation-defined						const_iterator;

	// typedef std::reverse_iterator<iterator>		reverse_iterator;
	// typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

private:

	Alloc			_alloc;
	pointer			_vector;
	size_type		_size;
	size_type		_capacity;

public:

	/*									vector constructors									*/

	explicit vector (const allocator_type& alloc = allocator_type()): _alloc(alloc), _vector(nullptr), _size(0), _capacity(0)
	{
		_vector = _alloc.allocate(_capacity);
		std::cerr << "constructor 1" << std::endl;
	}

	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(n), _capacity(n)
	{
		_vector = _alloc.allocate(_capacity);

		for (size_t i = 0; i < _capacity; i++)
			_alloc.construct(&_vector[i], val);
		std::cerr << "constructor 2" << std::endl;
	}

	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
	 typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)/*
	 typename std::enable_if<std::__is_cpp17_input_iterator  <InputIterator>::value && 
	 std::is_constructible< value_type, typename std::iterator_traits<InputIterator>::reference>::value>::type* = 0)*/
	 : _alloc(alloc), _size(0) //vector.hpp line 528
	{
		for (InputIterator temp(first); temp != last; temp++)
			_size++;
		_capacity = _size;
		_vector = _alloc.allocate(_capacity);

		for (size_t i = 0; first != last; first++, i++)
			_alloc.construct(&_vector[i], *first);
		std::cerr << "constructor 3" << std::endl;
	}
	
	vector (const vector& x): _alloc(x._alloc), _size(x._size), _capacity(x._capacity)
	{
		_vector = _alloc.allocate(_capacity);

		for (size_t i = 0; i < x._size; i++)
			_alloc.construct(&_vector[i], x._vector[i]);
		
		std::cerr << _vector[1] << std::endl;
	}

	vector& operator=(const vector& x)
	{
		_alloc = x._alloc;
		_size= x._size;
		_capacity = x._capacity;
		_vector = _alloc.allocate(_capacity);
		for (size_t i = 0; i < x._capacity; i++)
			_alloc.construct(&_vector[i], x._vector[i]);

	}

	~vector()
	{
		//delete[] _vector;
		size_t i = 0;
		for (pointer temp = &(_vector[0]); i < _capacity; temp++, i++)
			_alloc.destroy(temp);
		_alloc.deallocate(_vector, _capacity);
	}

	//template <T>
	typename std::vector<T>::iterator begin()
	{
		return (this->_vector);
	}

	pointer end()
	{
		return (&(_vector[_capacity]));
	}

	// template <typename T>
	// typename std::Nuage<T>::const_iterator std::Nuage<T>::begin() const{
	// 	return v.begin();
	// }

	//std::iterator::const_iterator begin() const;

	// vector()
    //     noexcept(is_nothrow_default_constructible<allocator_type>::value);
    // explicit vector(const allocator_type&);
    // explicit vector(size_type n);
    // explicit vector(size_type n, const allocator_type&); // C++14
    // vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
    // template <class InputIterator>
    //     vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
    // vector(const vector& x);
    // vector(vector&& x)
    //     noexcept(is_nothrow_move_constructible<allocator_type>::value);
    // vector(initializer_list<value_type> il);
    // vector(initializer_list<value_type> il, const allocator_type& a);



private:




};








}

#endif