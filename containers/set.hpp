/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:50:31 by jferrer-          #+#    #+#             */
/*   Updated: 2023/04/02 16:54:23 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:01:43 by jferrer-          #+#    #+#             */
/*   Updated: 2023/03/12 22:03:45 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.hpp"
#include "../utils/BST.hpp"
#include "iterator.hpp"
#include <memory>
// #include <sys/socket.h>
#include <map>
// #include <map>

namespace ft {

template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class map
{
	public:
	// types:
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::pair<const key_type, mapped_type>	value_type;
		typedef Compare									key_compare;
		typedef Alloc								allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference		const_reference;

		// typedef typename ft::Binary_search_tree<value_type, key_compare>::iterator iterator;
		// typedef typename ft::Binary_search_tree<value_type, key_compare>::const_iterator const_iterator;

		typedef typename ft::BST<value_type, key_compare>::iterator iterator;
		typedef typename ft::BST<value_type, key_compare>::const_iterator const_iterator;
		
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		// typedef ft::BST_iterator<ft::BST_node<ft::pair<Key, T> > const, const Compare> const_iterator;
		// typedef implementation defined iterator; // See 23.1
		// typedef implementation defined const_iterator; // See 23.1
		typedef typename allocator_type::size_type size_type;
		typedef typename allocator_type::difference_type difference_type;
		// typedef implementation defined size_type; // See 23.1
		// typedef implementation defined difference_type;// See 23.1
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		// typedef std::reverse_iterator<iterator>			reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
		
		class value_compare: public binary_function<value_type,value_type,bool>
		{
			friend class map;
			protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {}
			public:
				bool operator()(const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};
		
	protected:
		ft::BST<value_type, Compare>				_bst;
		allocator_type								_allocator;
		key_compare									_compare;
		




	public:
		// 23.3.1.1 construct/copy/destroy:
		explicit map(const Compare& comp = Compare(), const Alloc& alloc = Alloc()): _bst(), _allocator(alloc), _compare(comp)
		{

		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Alloc& alloc = Alloc(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr): _bst(), _allocator(alloc), _compare(comp)
		{
			insert(first, last);
		}

		map(const map<Key,T,Compare,Alloc>& x): _bst(), _allocator(x._allocator), _compare(x._compare)
		{
			insert(x.begin(), x.end());
		}

		~map()
		{
			clear();
		}
		
		map<Key,T,Compare,Alloc>&
		operator=(const map<Key,T,Compare,Alloc>& x)
		{
			if (this == &x)
				return *this;
			clear();
			this->_allocator = x._allocator;
			this->_compare = x._compare;
			this->insert(x.begin(), x.end());
			return *this;
		}
		
		// iterators:
		iterator begin() { return (iterator(_bst._last_node->left, _bst._last_node)); }
		const_iterator begin() const { return (const_iterator(_bst._last_node->left, _bst._last_node)); }
		iterator end() { return (iterator(_bst._last_node, _bst._last_node)); }
		const_iterator end() const { return (const_iterator(_bst._last_node, _bst._last_node)); }
		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
		
		// capacity:
		bool empty() const { return (_bst._last_node == _bst._last_node->parent); }
		size_type size() const
		{
			return distance(begin(), end());
		}
		size_type max_size() const
		{
			return std::min<size_type>(_allocator.max_size(), std::numeric_limits<difference_type>::max());
		}

		// 23.3.1.2 element access:
		T& operator[](const key_type& x)
		{
			iterator it = find(x);
			if (it == end())
				insert(ft::make_pair(x, mapped_type()));
			
			return ((*find(x)).second);
		}

		// modifiers:
		pair<iterator, bool> insert(const value_type& x) { return (_bst.insert(x)); }
		iterator insert(iterator position, const value_type& x) { (void)position; return (_bst.insert(x).first); }
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
		{
			while (first != last)
				_bst.insert(*(first++));
		}
		void erase(iterator position) { erase((*position).first); }
		size_type erase(const key_type& x)
		{
			if (find(x) == end())
				return (0);
			_bst.delete_by_key(ft::make_pair(x, mapped_type()));
			return (1);
		}
		void erase(iterator first, iterator last)
		{
			while (first != last)
				erase((*first++).first);
		}
		void swap(map<Key,T,Compare,Alloc>& temp)
		{
			if (this == &temp)
				return ;
			_bst.swap(temp._bst);
		}
		void clear() { erase(begin(), end()); }

		// // observers:
		key_compare key_comp() const
		{
			return (key_compare());
		}
		value_compare value_comp() const
		{
			return (value_compare(key_compare()));
		}

		// // 23.3.1.3 map operations:
		iterator find(const key_type& x) { return (iterator(_bst.search_by_key(ft::make_pair(x, mapped_type())), _bst._last_node)); }
		const_iterator find(const key_type& x) const { return (const_iterator(_bst.search_by_key(ft::make_pair(x, mapped_type())), _bst._last_node)); }
		size_type count(const key_type& x) const
		{
			iterator it = begin();
			for (; it != end(); it++)
				if ((*it).first == x)
					return (1);
			return (0);
		}
		iterator lower_bound(const key_type& x)
		{
			iterator it = begin();
			for (; it != end(); it++)
				if (_compare((*it).first, x) != true)
					return it;
			return end();
		}
		const_iterator lower_bound(const key_type& x) const
		{
			return (const_iterator(this->lower_bound(x)));
		}
		iterator upper_bound(const key_type& x)
		{
			iterator it = begin();
			for (; it != end(); it++)
				if (_compare(x, (*it).first))
					return it;
			return end();
		}
		const_iterator upper_bound(const key_type& x) const
		{
			return (const_iterator(this->upper_bound(x)));
		}
		pair<iterator,iterator>
		equal_range(const key_type& x)
		{
			return (ft::make_pair(lower_bound(x), upper_bound(x)));
		}
		pair<const_iterator,const_iterator>
		equal_range(const key_type& x) const
		{
			return (ft::make_pair(lower_bound(x), upper_bound(x)));
		}
};

template <class Key, class T, class Compare, class Alloc>
bool operator==(const map<Key,T,Compare,Alloc>& x, const map<Key,T,Compare,Alloc>& y)
{
	// typename ft::map<Key,T,Compare,Alloc>::iterator it1 = x.begin();
	// typename ft::map<Key,T,Compare,Alloc>::iterator it2 = y.begin();
	// if (x.size() != y.size())
	// 	return (false);
	return (ft::equal(x.begin(), x.end(), y.begin()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator< (const map<Key,T,Compare,Alloc>& x, const map<Key,T,Compare,Alloc>& y)
{
	typename ft::map<Key,T,Compare,Alloc>::iterator it1 = x.begin();
	typename ft::map<Key,T,Compare,Alloc>::iterator it2 = y.begin();

	if (x.size() < y.size())
		return true;
	else if (y.size() < x.size())
		return false;
	for (; it1 != x.end() && it2 != y.end(); it1++, it2++)
	{
		if (x.key_comp()(it1->first, it2->first)) {
			return true;
		} else if (y.key_comp()(it2->first, it1->first)) {
			return false;
		} else if (it1->second < it2->second) {
			return true;
		} else if (it2->second < it1->second) {
			return false;
		}
	}
	return (false);
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key,T,Compare,Alloc>& x, const map<Key,T,Compare,Alloc>& y)
{
	return (!ft::equal(x.begin(), x.end(), y.begin()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator> (const map<Key,T,Compare,Alloc>& x, const map<Key,T,Compare,Alloc>& y)
{
	typename ft::map<Key,T,Compare,Alloc>::iterator it1 = x.begin();
	typename ft::map<Key,T,Compare,Alloc>::iterator it2 = y.begin();

	if (x.size() > y.size())
		return true;
	else if (y.size() > x.size())
		return false;
	for (; it1 != x.end() && it2 != y.end(); it1++, it2++)
	{
		if (x.key_comp()(it2->first, it1->first)) {
			return true;
		} else if (y.key_comp()(it1->first, it2->first)) {
			return false;
		} else if (it1->second > it2->second) {
			return true;
		} else if (it2->second > it1->second) {
			return false;
		}
	}
	return (false);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key,T,Compare,Alloc>& x, const map<Key,T,Compare,Alloc>& y)
{
	return (x == y || x > y);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key,T,Compare,Alloc>& x, const map<Key,T,Compare,Alloc>& y)
{
	return (x == y || x < y);
}

// specialized algorithms:
template <class Key, class T, class Compare, class Alloc>
void swap(map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
{
	
}

}