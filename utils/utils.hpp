/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:56:27 by jferrer-          #+#    #+#             */
/*   Updated: 2023/02/23 21:37:59 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
// #include "../containers/vector.hpp"
// #include "../containers/iterator.hpp"
// #include "../containers/stack.hpp"

//#include <type_traits>

namespace ft
{

	/*		enable_if		*/

	template <bool B, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> { typedef T type; };


	/*									  	is_integral			    								*/
	/*	https://stackoverflow.com/questions/23070099/c98-compile-time-detect-floating-point-type    */

	template <typename T>
	struct is_integral
	{
		typedef T type;
		static const bool value;
		operator type() const { return value; }
	};

	template <typename T>
	const bool is_integral<T>::value = std::numeric_limits<T>::is_integer;


	// template <class _Tp>
	// struct __is_cpp17_forward_iterator : public __has_iterator_category_convertible_to<_Tp, forward_iterator_tag> {};



}

namespace ft
{
	template <class T1, class T2>
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;
		T1 first;
		T2 second;
		pair(): first(T1()), second(T2()) {}
		pair(const T1& x, const T2& y): first(x), second(y) {}
		template<class U, class V> pair(const pair<U, V> &p): first(p.first), second(p.second) {}
		pair& operator= (const pair& pr)
		{
			if (&pr == this)
				return *this;
			first = pr.first;
			second = pr.second;
			return *this;
		}

	};

	template <class T1, class T2>
	bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{
		return (x.first == y.first && x.second == y.second);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
	{
		return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
	}

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(const T1& x, const T2& y)
	{
		return (pair<T1, T2>(x, y));
	}

	template <typename T>
	struct BST_node
	{
		public:
			typedef T value_type;

			value_type	value;
			T*			parent;
			T*			right;
			T*			left;

		BST_node()
			: value(), parent(nullptr), right(nullptr), left(nullptr) {}

		BST_node(BST_node* _parent = nullptr, BST_node* _left = nullptr, BST_node* _right = nullptr)
			: value(), parent(_parent), left(_left), right(_right) {}

		BST_node(const value_type& _value, BST_node* _parent = nullptr, BST_node* _left = nullptr, BST_node* _right = nullptr)
			: value(_value), parent(_parent), left(_left), right(_right) {}

		BST_node(const BST_node& _node)
			: value(_node.value), parent(_node.parent), right(_node.right), left(_node.left) {}

		virtual ~BST_node() {}

		BST_node &operator=(const BST_node& _node)
		{
			if (*this == _node)
				return *this;
			value = _node.value;
			parent = _node.parent;
			left = _node.left;
			right = _node.left;
			return *this;
		}

		bool operator==(const BST_node& _node)
		{
			return (value == _node.value);
		}
	};
}

#endif