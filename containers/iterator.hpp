/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:38:55 by jferrer-          #+#    #+#             */
/*   Updated: 2023/03/09 17:32:22 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <type_traits>
#include <iterator>
#include <cstddef>
#include "../utils/utils.hpp"
#include <unistd.h>


namespace ft
{

//primitives

template<class Iterator> struct iterator_traits;
template<class T> struct iterator_traits<T*>;
// template<class T> struct iterator_traits<const T*>;
// template<class Category, class T, class Distance = ptrdiff_t,
// 	class Pointer = T*, class Reference = T&> struct iterator;

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag: public input_iterator_tag {};
struct bidirectional_iterator_tag: public forward_iterator_tag {};
struct random_access_iterator_tag: public bidirectional_iterator_tag {};


//iterator operations
/*
template <class InputIterator, class Distance>
	void advance(InputIterator& i, Distance n);
template <class InputIterator>
typename iterator_traits<InputIterator>::difference_type
	distance(InputIterator first, InputIterator last);
*/

//predefined iterators

/*
template <class Iterator> class reverse_iterator;

template <class Iterator>
	bool operator==(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y);
template <class Iterator>
	bool operator<(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y);
template <class Iterator>
	bool operator!=(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y);
template <class Iterator>
	bool operator>(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y);
template <class Iterator>
	bool operator>=(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y);
template <class Iterator>
	bool operator<=(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y);

template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y);
template <class Iterator>
	reverse_iterator<Iterator>
		operator+(
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& x);

template <class Container> class back_insert_iterator;
template <class Container>
	back_insert_iterator<Container> back_inserter(Container& x);

template <class Container> class front_insert_iterator;
template <class Container>
	front_insert_iterator<Container> front_inserter(Container& x);

template <class Container> class insert_iterator;
template <class Container, class Iterator>
	insert_iterator<Container> inserter(Container& x, Iterator i);

*/



/*
template <class T>
struct input_iterator_tag
{
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef const T* pointer;
    typedef const T& reference;
    typedef ft::input_iterator_tag iterator_category;
};




template <class T>
struct forward_iterator_tag: public input_iterator_tag
{
    // Define the operations that can be performed on iterators
    // that are identified by this tag
    //...

    typedef std::ptrdiff_t difference_type;
    typedef ft::forward_iterator_tag iterator_category;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
};




template <class T>
struct bidirectional_iterator_tag
{
    // Define the operations that can be performed on iterators
    // that are identified by this tag
    //...

    typedef std::ptrdiff_t difference_type;
    typedef ft::bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
};
*/











// template<class Category, class T, class Distance = ptrdiff_t,
// 			class Pointer = T*, class Reference = T&>
// struct iterator {
// 	typedef T			value_type;
// 	typedef Distance	difference_type;
// 	typedef Pointer		pointer;
// 	typedef Reference 	reference;
// 	typedef Category 	iterator_category;
// };

template <class Category, class T, class Distance = ptrdiff_t,
	class Pointer = T*, class Reference = T&>
class iterator
{
	public:
		typedef T           value_type;
		typedef Distance    difference_type;
		typedef Pointer     pointer;
		typedef Reference   reference;
		typedef Category    iterator_category;
};


// template<class _Category, class _Tp, class _Distance = ptrdiff_t, class _Pointer = _Tp *, class _Reference = _Tp &>
template <typename T>
class random_access_iterator: ft::iterator<ft::random_access_iterator_tag, T>
{
	public:

		typedef T* iterator_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer               pointer;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference             reference;

		// typedef _Category                                                  iterator_type;
		// typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
		// typedef typename iterator_traits<iterator_type>::value_type        value_type;
		// typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
		// typedef typename iterator_traits<iterator_type>::pointer           pointer;
		// typedef typename iterator_traits<iterator_type>::reference         reference;

		// typedef _Tp										value_type;
		// typedef _Pointer								pointer;
		typedef const T*							const_pointer;
		// typedef _Reference								reference;
		typedef const T&						const_reference;
		// typedef _Distance								difference_type; // usually as long as an int
		// typedef _Category								iterator_category;
		// typedef iterator								iterator_type;
		//typedef iterator< const _Category, const _Tp>	const_iterator;
	


		random_access_iterator(): _it(){}
		random_access_iterator(pointer ptr): _it(ptr){}
		random_access_iterator(const random_access_iterator& newit): _it(newit._it){}
		virtual ~random_access_iterator(){}

		pointer				base	() const { return _it; }

		random_access_iterator			operator	=	(const random_access_iterator& r)				{ _it = r._it; return *this; };
		random_access_iterator&			operator	++	()								{ _it += 1; return *this; }
		random_access_iterator			operator	++	(int)							{ random_access_iterator tmp(*this); operator++(); return tmp; }
		random_access_iterator&			operator	--	()								{ _it -= 1; return *this; }
		random_access_iterator			operator	--	(int)							{ random_access_iterator tmp(*this); operator--(); return tmp; }
		random_access_iterator&			operator	+=	(difference_type tmp)			{ _it += tmp; return *this; }
		random_access_iterator&			operator	-=	(difference_type tmp)			{ _it -= tmp; return *this; }
		random_access_iterator			operator	+	(difference_type tmp)			{ return (base() + tmp); }
		random_access_iterator			operator	-	(difference_type tmp)			{ return (base() - tmp); }

		int		operator-(random_access_iterator const &obj) const 						{ return (base() - obj._it); }
		int		operator+(random_access_iterator const &obj) const 						{ return (base() + obj._it); }

		reference			operator	[]	(difference_type index)			{ return *this->_it[index]; }
		//const_reference		operator	[]	(difference_type index) const	{ return base()[index]; }

		reference			operator	*	()	const							{ return *_it; }
		//const_reference		operator	*	() const						{ return *_it; }
		pointer				operator	->	()	const							{ return &(*_it); }
		//const_pointer		operator	->	() const						{ return &(*_it); }
		

		bool				operator	==	(const random_access_iterator& other) const	{ return _it == other._it; }
		bool				operator	!=	(const random_access_iterator& other) const	{ return !(*this == other); }
		bool				operator	>	(const random_access_iterator& other) const	{ return _it > other._it; }
		bool				operator	<	(const random_access_iterator& other) const	{ return _it < other._it; }
		bool				operator	>=	(const random_access_iterator& other) const	{ return _it >= other._it; }
		bool				operator	<=	(const random_access_iterator& other) const	{ return _it <= other._it; }

		//operator 			const_iterator	() const						{ return const_iterator(_it); };


	private:
		pointer	_it;
	
};


// template<class _Category, class T, class _Distance = ptrdiff_t, class _Pointer = T *, class _Reference = T &>
template <typename T>
class BST_iterator: ft::iterator<ft::bidirectional_iterator_tag, T>
{
	public:
		// typedef typename T::value_type					value_type;
		// typedef _Distance								difference_type;
		// typedef _Pointer								pointer;
		// typedef _Reference								reference;
		// typedef typename ft::bidirectional_iterator_tag	iterator_category;

		typedef T* iterator_type;
		typedef typename T::value_type            value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category     iterator_category;
		
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type       difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer               pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference             reference;

		T*		_node;
		// Compare	comp;
		T*		_last_node;

		// BST_iterator(): _node(nullptr)
		// {}
		BST_iterator(T* node, T* last_node): _node(node), _last_node(last_node)
		{}
		BST_iterator(const BST_iterator& _iterator): _node(_iterator._node), _last_node(_iterator._last_node)
		{}
		BST_iterator(): _node(), _last_node()
		{}

		BST_iterator &operator=(const BST_iterator& _iterator)
		{
			if (*this == _iterator)
				return *this;
			_node = _iterator._node;
			_last_node = _iterator._last_node;
			// comp = _iterator.comp;
			return *this;
		}

		virtual ~BST_iterator() {}

		bool operator==(const BST_iterator& _iterator)
		{
			return (_node == _iterator._node);
		}

		bool operator!=(const BST_iterator& _iterator)
		{
			return (_node != _iterator._node);
		}
		
		reference operator*() const
		{
			return _node->value;
		}

		pointer operator->() const
		{
			return &(_node->value);
		}

		BST_iterator& operator++()
		{
			if (_node == _last_node)
				_node = _last_node->left;
			else if (_node->right != _last_node)
			{
				_node = _node->right;
				while (_node->left != _last_node)
					_node = _node->left;
			}
			else if (_node->parent != _last_node && _node == _node->parent->left)
				_node = _node->parent;
			else if (_node->parent != _last_node && _node == _node->parent->right)
			{
				while (_node->parent != _last_node && _node == _node->parent->right)
					_node = _node->parent;
				if (_node->parent != _last_node)
					_node = _node->parent;
				else
					_node = _last_node;
			}
			else
				_node = _last_node;
			return *this;
		}

		BST_iterator operator++(int)
		{
			BST_iterator temp(*this);
			operator++();
			return temp;
		}

		BST_iterator& operator--()
		{
			if (_node == _last_node)
				_node = _last_node->right;
			else if (_node->left != _last_node)
			{
				_node = _node->left;
				while (_node->right != _last_node)
					_node = _node->right;
			}
			else if (_node->parent != _last_node && _node == _node->parent->right)
				_node = _node->parent;
			else if (_node->parent != _last_node && _node == _node->parent->left)
			{
				while (_node->parent != _last_node && _node == _node->parent->left)
					_node = _node->parent;
				if (_node->parent != _last_node)
					_node = _node->parent;
				else
					_node = _last_node;
			}
			else
				_node = _last_node;
			return *this;
		}

		BST_iterator operator--(int)
		{
			BST_iterator temp(*this);
			operator--();
			return temp;
		}
};


template <typename T>
class BST_const_iterator: ft::iterator<ft::bidirectional_iterator_tag, T>
{
	public:
		// typedef typename T::value_type					value_type;
		// typedef _Distance								difference_type;
		// typedef _Pointer								pointer;
		// typedef _Reference								reference;
		// typedef typename ft::bidirectional_iterator_tag	iterator_category;

		typedef T* iterator_type;
		typedef typename T::value_type            value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category     iterator_category;
		
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type       difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer               pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference             reference;

		T*		_node;
		// Compare	comp;
		T*		_last_node;

		// BST_iterator(): _node(), _last_node()
		// {}
		BST_const_iterator(T* node, T* last_node): _node(node), _last_node(last_node)
		{}
		BST_const_iterator(const BST_const_iterator& _iterator): _node(_iterator._node), _last_node(_iterator._last_node)
		{}
		BST_const_iterator(const BST_iterator<T>& _iterator): _node(_iterator._node), _last_node(_iterator._last_node)
		{}
		BST_const_iterator(): _node(), _last_node()
		{}

		BST_const_iterator &operator=(const BST_const_iterator& _iterator)
		{
			if (*this == _iterator)
				return *this;
			_node = _iterator._node;
			_last_node = _iterator._last_node;
			// comp = _iterator.comp;
			return *this;
		}

		virtual ~BST_const_iterator() {}

		bool operator==(const BST_const_iterator& _iterator)
		{
			return (_node == _iterator._node);
		}

		bool operator!=(const BST_const_iterator& _iterator)
		{
			return (_node != _iterator._node);
		}
		
		reference operator*() const
		{
			return _node->value;
		}

		pointer operator->() const
		{
			return &(_node->value);
		}

		BST_const_iterator& operator++()
		{
			
			if (_node == _last_node)
				_node = _last_node->left;
			else if (_node->right != _last_node)
			{
				_node = _node->right;
				while (_node->left != _last_node)
					_node = _node->left;
			}
			else if (_node->parent != _last_node && _node == _node->parent->left)
				_node = _node->parent;
			else if (_node->parent != _last_node && _node == _node->parent->right)
			{
				while (_node->parent != _last_node && _node == _node->parent->right)
					_node = _node->parent;
				if (_node->parent != _last_node)
					_node = _node->parent;
				else
					_node = _last_node;
			}
			else
				_node = _last_node;
			return *this;
		}

		BST_const_iterator operator++(int)
		{
			BST_const_iterator temp(*this);
			(*this)--;
			return temp;
		}

		BST_const_iterator& operator--()
		{
			if (_node == _last_node)
				_node = _last_node->right;
			else if (_node->left != _last_node)
			{
				_node = _node->left;
				while (_node->right != _last_node)
					_node = _node->right;
			}
			else if (_node->parent != _last_node && _node == _node->parent->right)
				_node = _node->parent;
			else if (_node->parent != _last_node && _node == _node->parent->left)
			{
				while (_node->parent != _last_node && _node == _node->parent->left)
					_node = _node->parent;
				if (_node->parent != _last_node)
					_node = _node->parent;
				else
					_node = _last_node;
			}
			else
				_node = _last_node;
			return *this;
		}

		BST_const_iterator operator--(int)
		{
			BST_const_iterator temp(*this);
			(*this)--;
			return temp;
		}
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
		typedef iterator															iterator_type;
		typedef typename iterator_traits<iterator>::difference_type					difference_type;
		typedef typename iterator_traits<iterator>::value_type						value_type;
		typedef typename iterator_traits<iterator>::reference						reference;
		typedef typename iterator_traits<iterator>::pointer							pointer;
		typedef typename iterator_traits<iterator>::iterator_category				iterator_category;

		// typedef typename iterator::difference_type		difference_type;
		// typedef typename iterator::value_type			value_type;
		// typedef typename iterator::pointer				pointer;
		// typedef typename iterator::const_pointer		const_pointer;
		// typedef typename iterator::reference			reference;
		// typedef typename iterator::const_reference		const_reference;
		// typedef typename iterator::iterator_category	iterator_category;

		//reverse_iterator(): _it(){}
		explicit reverse_iterator(iterator_type x = iterator()): _it(x) {}
		template <class U>
			reverse_iterator(const reverse_iterator<U>& u,
				typename ft::enable_if<std::is_convertible<U, iterator>::value>::type* = 0)
				: _it(u.base()) {}

		// reverse_iterator(iterator const &it): _it(it) {}
		// reverse_iterator(reverse_iterator const &it): _it(it._it) {}

		iterator					base() const { return _it; }
		reference					operator	*	()								{ return *_it; }
		pointer						operator	->	()								{ return &(operator*()); }

		reverse_iterator&			operator	++	()								{ --_it; return *this; }
		reverse_iterator			operator	++	(int)							{ reverse_iterator tmp(*this); --_it; return tmp; }
		reverse_iterator&			operator	--	()								{ ++_it; return *this; }
		reverse_iterator			operator	--	(int)							{ reverse_iterator tmp(*this); ++_it; return tmp; }

		reverse_iterator			operator	+	(difference_type tmp) const		{ return reverse_iterator(base() - tmp); }
		reverse_iterator&			operator	+=	(difference_type tmp)			{ _it -= tmp; return *this; }
		reverse_iterator			operator	-	(difference_type tmp) const		{ return reverse_iterator(base() + tmp); }
		reverse_iterator&			operator	-=	(difference_type tmp)			{ _it += tmp; return *this; }

		reference					operator	[]	(difference_type tmp)		 	{ return  base()[-tmp - 1]; };

		// template <class iterator>
		// typename reverse_iterator<iterator>::difference_type operator-(const reverse_iterator<iterator>& x, const reverse_iterator<iterator>& y) {
		// 	return (x.base() - y.base());
		// }

		// template <class iterator>
		// reverse_iterator<iterator> operator+(typename reverse_iterator<iterator>::difference_type n, const reverse_iterator<iterator>& x) {
		// 	return (x.base() - n);
		// }

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
    typedef ft::random_access_iterator_tag		iterator_category;
};

template<class T>
struct iterator_traits<const T*>
{
	typedef ptrdiff_t						difference_type;
	typedef T								value_type;
	typedef const T*						pointer;
	typedef const T&						reference;
	typedef ft::random_access_iterator_tag	iterator_category;
};




template <class _InputIter>
typename iterator_traits<_InputIter>::difference_type
__distance(_InputIter __first, _InputIter __last, input_iterator_tag)
{
    typename iterator_traits<_InputIter>::difference_type __r(0);
    for (; __first != __last; ++__first)
        ++__r;
    return __r;
}

template <class _RandIter>
typename iterator_traits<_RandIter>::difference_type
__distance(_RandIter __first, _RandIter __last, random_access_iterator_tag)
{
    return __last - __first;
}

template <class _InputIter>
typename iterator_traits<_InputIter>::difference_type
distance(_InputIter __first, _InputIter __last)
{
    return __distance(__first, __last, typename iterator_traits<_InputIter>::iterator_category());
}

};

#endif