/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:38:55 by jferrer-          #+#    #+#             */
/*   Updated: 2023/01/30 04:42:49 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <type_traits>
#include <cstddef>


namespace ft
{

template <typename iterator> struct iterator_traits;
template<typename T> struct iterator_traits<T*>;
template<class T> struct iterator_traits<const T*>;

/*
namespace std {
	template<class Category, class T, class Distance = ptrdiff_t,
				class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference 	reference;
		typedef Category 	iterator_category;
	}; 
}
*/


template<class _Category, class _Tp, class _Distance = ptrdiff_t, class _Pointer = _Tp *, class _Reference = _Tp &>
class iterator
{
	public:
		typedef _Tp										value_type;
		typedef _Pointer								pointer;
		typedef const _Pointer							const_pointer;
		typedef _Reference								reference;
		typedef const _Reference						const_reference;
		typedef _Distance								difference_type; // usually as long as an int
		typedef _Category								iterator_category;
		//typedef iterator< const _Category, const _Tp>	const_iterator;
	


		//iterator(): _it(){}
		iterator(pointer ptr = NULL): _it(ptr){}
		iterator(const iterator& newit): _it(newit._it){}
		virtual ~iterator(){}

		pointer				base	() const { return _it; }

		iterator			operator	=	(const iterator& r)				{ _it = r.base(); return *this; };
		iterator&			operator	++	()								{ _it += 1; return *this; }
		iterator			operator	++	(int)							{ iterator tmp(*this); operator++(); return tmp; }
		iterator&			operator	--	()								{ _it -= 1; return *this; }
		iterator			operator	--	(int)							{ iterator tmp(*this); operator--(); return tmp; }
		iterator&			operator	+=	(difference_type tmp)			{ _it += tmp; return *this; }
		iterator&			operator	-=	(difference_type tmp)			{ _it -= tmp; return *this; }
		iterator			operator	+	(difference_type tmp)			{ return (base() + tmp); }
		iterator			operator	-	(difference_type tmp)			{ return (base() - tmp); }

		int		operator-(iterator const &obj) const 						{ return _it - obj._it; }
		int		operator+(iterator const &obj) const 						{ return _it + obj._it; }

		reference			operator	[]	(difference_type index)			{ return *this->_it[index]; }
		//const_reference		operator	[]	(difference_type index) const	{ return base()[index]; }

		reference			operator	*	()								{ return *_it; }
		//const_reference		operator	*	() const						{ return *_it; }
		pointer				operator	->	()								{ return &(*_it); }
		//const_pointer		operator	->	() const						{ return &(*_it); }
		

		bool				operator	==	(const iterator& other) const	{ return _it == other._it; }
		bool				operator	!=	(const iterator& other) const	{ return !(*this == other); }
		bool				operator	>	(const iterator& other) const	{ return _it > other._it; }
		bool				operator	<	(const iterator& other) const	{ return _it < other._it; }
		bool				operator	>=	(const iterator& other) const	{ return _it >= other._it; }
		bool				operator	<=	(const iterator& other) const	{ return _it <= other._it; }

		//operator 			const_iterator	() const						{ return const_iterator(_it); };


	private:
		pointer	_it;
	
};


template <class iterator>
class reverse_iterator: public ft::iterator<typename ft::iterator_traits<iterator>::iterator_category,
											typename ft::iterator_traits<iterator>::value_type,
											typename ft::iterator_traits<iterator>::difference_type,
											typename ft::iterator_traits<iterator>::pointer,
											typename ft::iterator_traits<iterator>::reference>
{
	protected:
		iterator _it;

	public:
		typedef iterator 												iterator_type;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef typename ft::iterator_traits<iterator>::reference		reference;
		typedef typename ft::iterator_traits<iterator>::pointer			pointer;

		// typedef typename iterator::difference_type		difference_type;
		// typedef typename iterator::value_type			value_type;
		// typedef typename iterator::pointer				pointer;
		// typedef typename iterator::const_pointer		const_pointer;
		// typedef typename iterator::reference			reference;
		// typedef typename iterator::const_reference		const_reference;
		// typedef typename iterator::iterator_category	iterator_category;

		reverse_iterator(): _it(){}
		explicit reverse_iterator(iterator x): _it(x) {}
		template <class U>
			reverse_iterator(const reverse_iterator<U>& u): _it(u._it) {}

		// reverse_iterator(iterator const &it): _it(it) {}
		// reverse_iterator(reverse_iterator const &it): _it(it._it) {}

		iterator					base() const { return _it; }
		reference					operator	*	()								{ iterator tmp = _it; return *--_it; }
		pointer						operator	->	()								{ return &(operator*()); }

		reverse_iterator&			operator	++	()								{ --_it; return *this; }
		reverse_iterator			operator	++	(int)							{ reverse_iterator tmp(*this); --_it; return tmp; }
		reverse_iterator&			operator	--	()								{ ++_it; return *this; }
		reverse_iterator			operator	--	(int)							{ reverse_iterator tmp(*this); ++_it; return tmp; }

		reverse_iterator			operator	+	(difference_type tmp) const		{ return reverse_iterator(_it - tmp); }
		reverse_iterator&			operator	+=	(difference_type tmp)			{ _it -= tmp; return *this; }
		reverse_iterator			operator	-	(difference_type tmp) const		{ return reverse_iterator(_it + tmp); }
		reverse_iterator&			operator	-=	(difference_type tmp)			{ _it += tmp; return *this; }

		reference					operator	[]	(difference_type tmp)		 	{ return  base()[-tmp - 1]; };

		// reverse_iterator&			operator	=	(reverse_iterator const &other) { this->_it = other._it; return *this; }
		// reference					operator	[]	(difference_type tmp) const 	{ return  base()[-tmp - 1]; };
		// const_reference				operator	*	() const						{ iterator tmp = _it; return *--_it; }
		// const_pointer				operator	->	() const						{ return &(operator*()); }

};

template <class iterator>
bool operator==(const reverse_iterator<iterator>& lhs, const reverse_iterator<iterator>& rhs) {
    return lhs.base() == rhs.base();
}

template <class iterator>
bool operator<(const reverse_iterator<iterator>& lhs, const reverse_iterator<iterator>& rhs) {
    return lhs.base() < rhs.base();
}

template <class iterator>
bool operator!=(const reverse_iterator<iterator>& lhs, const reverse_iterator<iterator>& rhs) {
    return !(lhs == rhs);
}

template <class iterator>
bool operator>(const reverse_iterator<iterator>& lhs, const reverse_iterator<iterator>& rhs) {
    return rhs < lhs;
}

template <class iterator>
bool operator>=(const reverse_iterator<iterator>& lhs, const reverse_iterator<iterator>& rhs) { 
    return !(lhs < rhs);
}

template <class iterator>
bool operator<=(const reverse_iterator<iterator>& lhs, const reverse_iterator<iterator>& rhs) {
    return !(rhs < lhs);
}

template <class iterator>
typename reverse_iterator<iterator>::difference_type operator-(const reverse_iterator<iterator>& x, const reverse_iterator<iterator>& y) {
	return (x.base() - y.base());
}

template <class iterator>
reverse_iterator<iterator> operator+(typename reverse_iterator<iterator>::difference_type n, const reverse_iterator<iterator>& x) {
	return (x.base() - n);
}






/*--------------------------------------------------------------------------------------*
			Iterator categories for iterator_traits (since C++20)

	struct input_iterator_tag { };													(1)

	struct output_iterator_tag { };													(2)

	struct forward_iterator_tag : public input_iterator_tag { };					(3)

	struct bidirectional_iterator_tag : public forward_iterator_tag { };			(4)

	struct random_access_iterator_tag : public bidirectional_iterator_tag { };		(5)

	struct contiguous_iterator_tag : public random_access_iterator_tag { };			(6)

*--------------------------------------------------------------------------------------*/

template <class iterator>
struct iterator_traits
{
  typedef typename iterator::difference_type	difference_type;
  typedef typename iterator::value_type			value_type;
  typedef typename iterator::pointer			pointer;
  typedef typename iterator::reference			reference;
  typedef typename iterator::iterator_category	iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
    typedef ptrdiff_t							difference_type;
    typedef T									value_type;
    typedef T*									pointer;
    typedef T&									reference;
    typedef std::random_access_iterator_tag		iterator_category;
};

template<class T>
struct iterator_traits<const T*>
{
	typedef ptrdiff_t						difference_type;
	typedef T								value_type;
	typedef const T*						pointer;
	typedef const T&						reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

};

#endif