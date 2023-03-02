/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:29:54 by jferrer-          #+#    #+#             */
/*   Updated: 2023/02/28 21:00:09 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
#define BST_HPP

#include "utils.hpp"
#include "../containers/iterator.hpp"
#include <memory>

namespace ft
{

template <typename T,  class _Compare = std::less<T>, class Node = ft::BST_node<T>,
	class _Allocator = std::allocator<T>, class _Allocator_node = std::allocator<Node> >
class BST
{
	public:
		typedef T										value_type;
		typedef _Compare								value_compare;
		typedef _Allocator								allocator_type;
		typedef _Allocator_node							allocator_type_node;

	// private:
	// 	typedef allocator_traits<allocator_type>         __alloc_traits;

	public:
		typedef typename _Allocator::pointer			pointer;
		typedef typename _Allocator::const_pointer		const_pointer;
		typedef typename _Allocator::size_type			size_type;
		typedef typename _Allocator::difference_type	difference_type;

		typedef typename _Allocator_node::pointer			node_pointer;
		typedef typename _Allocator_node::const_pointer		const_pointer;
		typedef typename _Allocator_node::size_type			size_type;
		typedef typename _Allocator_node::difference_type	difference_type;

		// typedef typename iterator<T, _compare> 
		typedef ft::BST_iterator<Node, _Compare> iterator;
		// typedef ft::BST_iterator<Node, _Compare> const_iterator;

		node_pointer		_last_node;
		_Allocator_node		_node_alloc;

		BST(const allocator_type_node& node_alloc = allocator_type_node()): _node_alloc(node_alloc)
		{
			_last_node = _node_alloc.allocate(1);
			_node_alloc.construct(_last_node, Node(_last_node, _last_node, _last_node));
		}

		~BST()
		{
			_node_alloc.destroy(_last_node);
			_node_alloc.deallocate(_last_node, 1);
		}

		pair<iterator, bool> insert(const value_type& x)
		{
			node_pointer temp = _node_alloc.allocate(1);
			node_pointer temp_node = _last_node->parent;

			while (temp_node != _last_node)
			{
				if (temp_node->value.first < x.first && temp_node->left != _last_node)
					temp_node = temp_node->left;
				else if (temp_node->value.first > x.first && temp_node->right != _last_node)
					temp_node = temp_node->right;
				else if (temp_node->value.first == x.first)
				{
					_node_alloc.deallocate(temp, 1);
					return (ft::make_pair(iterator(temp_node, _last_node), _Compare));
				}
				else
					break;
			}
			_node_alloc.construct(temp, Node(x, temp_node, _last_node, _last_node));
			if (temp_node == _last_node)
				_last_node->parent = temp;
			else if (temp_node->value.first < x.first)
				temp_node->left = temp;
			else
				temp_node->right = temp;
			_last_node->right = get_bigger();
			_last_node->left = get_smaller();

			return (ft::make_pair(iterator(temp, _last_node), _Compare));
			
		}

		node_pointer get_bigger()
		{
			node_pointer temp = _last_node->parent;
			if (_last_node->parent == _last_node)
				return _last_node;
			while (temp->right != _last_node)
				temp = temp->right;
			return temp;
		}

		node_pointer get_smaller()
		{
			node_pointer temp = _last_node->parent;
			if (_last_node->parent == _last_node)
				return _last_node;
			while (temp->left != _last_node)
				temp = temp->left;
			return temp;
		}

		node_pointer search_by_key(const value_type& x)
		{
			node_pointer temp = _last_node->parent;
			if (_last_node->parent == _last_node)
				return _last_node;
			while (temp != _last_node && temp->value.first != x.first)
			{
				if (temp->left.first < x)
					temp = temp->right;
				else if (temp->left.first > x)
					temp = temp->left;
			}

			return temp;
		}
		
		node_pointer delete_by_key(const value_type& x)
		{
			node_pointer temp = _last_node->parent;
			if (_last_node->parent == _last_node)
				return _last_node;
			while (temp != _last_node && temp->value.first != x.first)
			{
				if (temp->left.first < x)
					temp = temp->right;
				else if (temp->left.first > x)
					temp = temp->left;
			}
			if (temp->value.first == x.first)
			{
				node_pointer temp2;
				bool side;
				if (temp->right != _last_node)
				{
					temp2 = temp->right;
					side = true;
				}
				else if (temp->left != _last_node)
				{
					temp2 = temp->left;
					side = false;
				}
				else
				{
					if (temp->parent->left == temp)
						temp->parent->left = _last_node;
					else if (temp->parent->right == temp)
						temp->parent->right = _last_node;
					_node_alloc.destroy(temp);
					_node_alloc.deallocate(temp, 1);
					return _last_node;
				}
				if (side == true)
				{
					if (temp2->left == _last_node)
					{
						if (temp2->right == _last_node)
							temp2->parent->right = _last_node;
						else
							temp2->parent->right = temp2->right;
						if (temp->parent->left == temp)
							temp->parent->left = temp2;
						else if (temp->parent->right == temp)
							temp->parent->right = temp2;
						temp2->right = temp->right;
						temp2->left = temp->left;
						_node_alloc.destroy(temp);
						_node_alloc.deallocate(temp, 1);
						return temp2;
					}
					while(temp2->left != _node_alloc)
						temp2 = temp2->left;
					if (temp2->right == _last_node)
						temp2->parent->left = _last_node;
					else
						temp2->parent->left = temp2->right;
					if (temp->parent->left == temp)
						temp->parent->left = temp2;
					else if (temp->parent->right == temp)
						temp->parent->right = temp2;
					temp2->right = temp->right;
					temp2->left = temp->left;
					_node_alloc.destroy(temp);
					_node_alloc.deallocate(temp, 1);
					return temp2;
				}
				else
				{
					if (temp2->right == _last_node)
					{
						if (temp2->left == _last_node)
							temp2->parent->left = _last_node;
						else
							temp2->parent->left = temp2->left;
						if (temp->parent->right == temp)
							temp->parent->right = temp2;
						else if (temp->parent->left == temp)
							temp->parent->left = temp2;
						temp2->left = temp->left;
						temp2->right = temp->right;
						_node_alloc.destroy(temp);
						_node_alloc.deallocate(temp, 1);
						return temp2;
					}
					while(temp2->right != _node_alloc)
						temp2 = temp2->right;
					if (temp2->left == _last_node)
						temp2->parent->right = _last_node;
					else
						temp2->parent->right = temp2->left;
					if (temp->parent->right == temp)
						temp->parent->right = temp2;
					else if (temp->parent->left == temp)
						temp->parent->left = temp2;
					temp2->left = temp->left;
					temp2->right = temp->right;
					_node_alloc.destroy(temp);
					_node_alloc.deallocate(temp, 1);
					return temp2;
				}
			}
			return _last_node;
		}
};

}

#endif