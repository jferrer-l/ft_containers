/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:29:54 by jferrer-          #+#    #+#             */
/*   Updated: 2023/04/03 00:09:24 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
#define BST_HPP

#include "utils.hpp"
// #include <map>
#include "../containers/iterator.hpp"
#include <memory>

namespace ft
{

template <typename T, class _Compare2, class _Compare = ft::less<T>, class Node = ft::BST_node<T>,
	class _Allocator = std::allocator<T>, class _Allocator_node = std::allocator<Node> >
class BST
{
	public:
		typedef T										value_type;
		typedef _Compare								value_compare;
		// typedef _Allocator								allocator_type;
		typedef _Allocator_node							allocator_type_node;

	// private:
	// 	typedef allocator_traits<allocator_type>         __alloc_traits;

	public:
		// typedef typename allocator_type::pointer			pointer;
		// typedef typename allocator_type::const_pointer		const_pointer;
		// typedef typename allocator_type::size_type			size_type;
		// typedef typename allocator_type::difference_type	difference_type;

		typedef typename allocator_type_node::pointer			node_pointer;
		typedef typename allocator_type_node::const_pointer		const_pointer;
		typedef typename allocator_type_node::size_type			size_type;
		typedef typename allocator_type_node::difference_type	difference_type;

		// typedef typename iterator<T, _compare> 
		typedef ft::BST_iterator<Node> iterator;
		typedef ft::BST_iterator<Node> const const_iterator;

		node_pointer		_last_node;
		_Allocator_node		_node_alloc;
		value_compare		comp2;
		_Compare2			comp;

		BST(const allocator_type_node& node_alloc = allocator_type_node()): _node_alloc(node_alloc)
		{
			// std::cerr << "constructor called\n";

			_last_node = _node_alloc.allocate(1);
			_node_alloc.construct(_last_node, Node(_last_node, _last_node, _last_node));
			// std::cerr << "_last_node = " << &_last_node << std::endl;
		}

		~BST()
		{
			// system("leaks a.out");
			// std::cerr << "destructor called\n";
			// std::cerr << "_last_node = " << &_last_node << std::endl;
			// _last_node = _node_alloc.allocate(1);
			_node_alloc.destroy(_last_node);
			_node_alloc.deallocate(_last_node, 1);
		}

		// BST &operator=(const BST& x)
		// {
		// 	if (*this == x)
		// 		return *this;
		// 	_node_alloc = x._node_alloc;
		// 	_last_node = _node_alloc.allocate(1);
		// 	_node_alloc.construct(_last_node, Node(_last_node, _last_node, _last_node));
		// 	_last_node->
			
		// 	// this->_allocator = x._allocator;
		// 	// this->_compare = x._compare;
		// 	// this->insert(x.begin(), x.end());
		// 	return *this;
		// }
		void printTree(node_pointer root, int indent = 1, char symbol = '-')
		{
			if (root == _last_node) {
				return;
			}

			// Print the right subtree
			printTree(root->right, indent + 4);

			// Print the current node
			for (int i = 0; i < indent; i++) {
				std::cout << " ";
			}
			// if (root->parent = _last_node)
			// 	std::cout << std::endl;
			std::cout << symbol << root->value.first;
			if (root->_color)
				std::cout << "R\n";
			else
				std::cout << "B\n";
			// if (root->parent = _last_node)
			// 	std::cout << std::endl;

			// Print the left subtree
			printTree(root->left, indent + 4);
		}
	private:
		

		void insert_i2(node_pointer temp)//parent and uncle RED
		{
			temp->parent->parent->right->_color = false;
			temp->parent->parent->left->_color = false;
			temp->parent->parent->_color = true;
		}

		void insert_i56(node_pointer temp)//parent RED and uncle BLACK
		{
			bool rotated = true;
			if (temp->parent->right == temp && temp->parent->parent->left == temp->parent)
				rotate_Left(temp);
			else if (temp->parent->left == temp && temp->parent->parent->right == temp->parent)
				rotate_Right(temp);
			else
				rotated = false;
			if (!rotated && temp->parent->parent->left == temp->parent)
				rotate_Right(temp->parent);
			else if (!rotated)
				rotate_Left(temp->parent);
			else if (temp->parent->left == temp)
				rotate_Right(temp);
			else
				rotate_Left(temp);
			if (rotated)
			{
				if (!temp->right->_color)
					temp->right->_color = true;
				else
					temp->left->_color = true;
				temp->_color = false;
			}
			else
			{
				if (!temp->parent->right->_color)
					temp->parent->right->_color = true;
				else
					temp->parent->left->_color = true;
				temp->parent->_color = false;
			}
		}
		
		void reorder(node_pointer temp)
		{
			if (temp->parent->_color && !temp->_color)//parent RED and temp BLACK
			{
				reorder(temp->parent);
				return ;
			}
			if (!temp->parent->_color)//parent BLACK
				return ;
			else if (temp->parent->parent == _last_node)//parent root
			{
				temp->parent->_color = false;
				return ;
			}
			else if (temp->parent->parent->right->_color && temp->parent->parent->left->_color)//parent and uncle RED
			{
				insert_i2(temp);
				reorder(temp->parent);
				return ;
			}
			else if (temp->parent->_color)//parent RED and uncle BLACK
			{
				insert_i56(temp);
				reorder(temp->parent);
				return ;
			}
		}

		void rotate_Right(node_pointer temp)
		{
			// std::cerr << "right\n";
			// if (temp->left->_color && temp->_color)
			// {
			// 	temp->parent->_color = true;
			// 	temp->_color = false;
			// }
			temp->parent->left = temp->right;
			temp->right->parent = temp->parent;
			temp->right = temp->parent;
			if (temp->parent == temp->parent->parent->left)
				temp->parent->parent->left = temp;
			else
				temp->parent->parent->right = temp;
			temp->parent = temp->parent->parent;
			temp->right->parent = temp;
		}

		void rotate_Left(node_pointer temp)
		{
			// std::cerr << "left\n";
			// if (temp->right->_color && temp->_color)
			// {
			// 	temp->parent->_color = true;
			// 	temp->_color = false;
			// }
			temp->parent->right = temp->left;
			temp->left->parent = temp->parent;
			temp->left = temp->parent;
			if (temp->parent == temp->parent->parent->right)
				temp->parent->parent->right = temp;
			else
				temp->parent->parent->left = temp;
			temp->parent = temp->parent->parent;
			temp->left->parent = temp;
		}
		
		bool check_compare() {
        if (std::is_same<_Compare, std::minus<int> >::value)
		{
            return true;
        }
		return false;
    }

	public:
	// ft::pair<iterator, bool> insert(value_type to_insert)
	// 		{
	// 			Node * new_node = _node_alloc.allocate(1);
	// 			Node * prev_node = _last_node;
	// 			Node * start_node = _last_node->parent;

	// 			// side == false = left; side == true = right;
	// 			bool side = true;

	// 			while (start_node != _last_node)
	// 			{
	// 				// size_type curkey = start_node->value.first;
	// 				if (start_node->value.first == to_insert.first)
	// 					return (ft::make_pair(iterator(start_node, _last_node), false));
	// 				prev_node = start_node;
	// 				if (to_insert.first > start_node->value.first)
	// 				{
	// 					side = true;
	// 					start_node = start_node->right;
	// 				}
	// 				else
	// 				{
	// 					side = false;
	// 					start_node = start_node->left;
	// 				}
	// 			}
	// 			_node_alloc.construct(new_node, Node(to_insert, prev_node, _last_node, _last_node));
				
	// 			if (prev_node == _last_node)
	// 				_last_node->parent = new_node;
	// 			else if (side == true)
	// 				prev_node->right = new_node;
	// 			else
	// 				prev_node->left = new_node;
				
	// 			_last_node->parent = get_root();
	// 			_last_node->left = get_smaller();//_BST_get_lower_node(_last_node->parent);
	// 			_last_node->right = get_bigger();//_BST_get_higher_node(_last_node->parent);
	// 			// _last_node->value.first += 1;
	// 			return (ft::make_pair(iterator(new_node, _last_node), true));
	// 		}
		pair<iterator, bool> insert(value_type x)
		{
			// std::cout << "insert " << x.first << std::endl;
			// std::cerr << "insert\n";
			node_pointer temp = _node_alloc.allocate(1);
			// std::cout << "allocation\n";
			node_pointer temp_node = _last_node->parent;
			// node_pointer base = _last_node->parent;

			// std::cout << x.first << std::endl;
			while (temp_node != _last_node)
			{
				// int i = (!comp(temp_node->value.first, x.first) && !comp(x.first, temp_node->value.first));
				// int j = (!comp2(temp_node->value, x) && !comp2(x, temp_node->value));
				// std::cout << i << j << std::endl;
				// if (i != j)
				// {
				// 	std::cout << i << j << std::endl;
				// 	std::cout << "i = " << i << std::endl;
				// 	std::cout << "j = " << j << std::endl;
				// 	// std::cout << "temp_node = " << temp_node.first << std::endl;
				// 	// std::cout << "x = " << x.first << std::endl;
				// }

				// i = (comp(temp_node->value.first, x.first) != true);
				// j = (comp2(temp_node->value, x) != true);
				// // std::cout << i << j << std::endl;
				// if (i != j)
				// {
				// 	std::cout << "i1 = " << comp(temp_node->value.first, x.first) << " true = " << true << std::endl;
				// 	std::cout << "j1 = " << comp2(temp_node->value, x) << " true = " << true << std::endl;
				// 	// std::cout << i << j << std::endl;
				// 	std::cout << "i = " << i;
				// 	std::cout << " j = " << j;
				// 	std::cout << " temp_node = " << temp_node->value.first;
				// 	std::cout << " x = " << x.first;
				// 	std::cout << " iid " << typeid(comp).name();
				// 	std::cout << " jid " << typeid(comp2).name();
				// 	std::cout << endl;
				// }

				// std::cout << temp_node->value.first << " " << x.first << std::endl;
				// if (!comp(temp_node->value, x) && !comp(x, temp_node->value))
				if (temp_node->value.first == x.first)
				{
					// std::cout << "sahdkjasjhdkjashdkjsahjkdhkjashkd\n";
					_node_alloc.deallocate(temp, 1);
					return (ft::make_pair(iterator(temp_node, _last_node), false));
				}
				// else if ((comp(temp_node->value, x) != true || check_compare()) && temp_node->left != _last_node)
				// 	temp_node = temp_node->left;
				// else if (comp(temp_node->value, x) == true && temp_node->right != _last_node)
				// 	temp_node = temp_node->right;
				else if ((comp(x, temp_node->value)) && temp_node->left != _last_node)
					temp_node = temp_node->left;
				else if ((comp(temp_node->value, x)) && temp_node->right != _last_node)
					temp_node = temp_node->right;
				// else
				// {
				// 	_node_alloc.deallocate(temp, 1);
				// 	return (ft::make_pair(iterator(temp_node, _last_node), false));
				// }
				else
					break;

				// if (temp_node->value.first == x.first)
				// {
				// 	_node_alloc.deallocate(temp, 1);
				// 	return (ft::make_pair(iterator(temp_node, _last_node), false));
				// }
				// else if ((comp(temp_node->value.first, x.first) != true || check_compare()) && temp_node->left != _last_node)
				// 	temp_node = temp_node->left;
				// else if (comp(temp_node->value.first, x.first) == true && temp_node->right != _last_node)
				// 	temp_node = temp_node->right;
				// else
				// 	break;
			}
			_node_alloc.construct(temp, Node(x, temp_node, _last_node, _last_node));
			// std::cerr << " e = " << temp->value.first << " ";
			if (temp_node == _last_node)
				_last_node->parent = temp;
			else if (comp(temp_node->value, x) == true)
				temp_node->right = temp;
			// else if (temp_node->value.first < x.first)
			// 	temp_node->right = temp;
			else if (comp(temp_node->value, x) != true)
				temp_node->left = temp;
			temp->_color = true;

			reorder(temp);
			
			
			_last_node->parent = get_root();
			_last_node->right = get_bigger();
			_last_node->left = get_smaller();

			// printTree(_last_node->parent);
			// std::cout << "\n\n\n\n\n\n";
			// system("leaks a.out");
			return (ft::make_pair(iterator(temp, _last_node), true));
			
		}

		node_pointer get_root()
		{
			// node_pointer temp;
			// base != nullptr ? temp = base : temp = _last_node->parent;
			if (_last_node->parent == _last_node)
				return _last_node;
			if (_last_node->parent->parent != _last_node)
			{
				node_pointer temp = _last_node->parent;
				while (temp->parent != _last_node)
					temp = temp->parent;
					return temp;
			}
			return _last_node->parent;
		}

		node_pointer get_bigger()
		{
			// if (_last_node->right->right == _last_node)
			// 	return _last_node->right;
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
			// printTree(_last_node->parent);
			node_pointer temp = _last_node->parent;
			if (_last_node->parent == _last_node)
				return _last_node;
			// while (temp != _last_node && (comp(temp->value, x) || comp(x, temp->value)))
			while (temp != _last_node && temp->value.first != x.first)
			{
				// std::cout << x.first << std::endl;
				// std::cout << temp->value.first << std::endl;
				// if (!(!comp(temp->value, x) && !comp(x, temp->value)) != (temp->value.first != x.first))
				// {
				// 	std::cout << typeid(comp).name() << std::endl;
				// 	std::cout << "temp->value = " << temp->value.first << " x = " << x.first << std::endl;
				// 	std::cout << !(!comp(temp->value, x) && !comp(x, temp->value)) << std::endl;
				// 	std::cout << (temp->value.first != x.first) << std::endl;
				// }
				

				// else if ((comp(x, temp->value)) && temp_node->left != _last_node)
				// 	temp = temp->left;
				// else if ((comp(temp->value, x)) && temp_node->right != _last_node)
				// 	temp = temp->right;

				// std::cout << "comp" << temp->value.first << " " <<  temp->value.second << " " << x.first << " " <<  x.second <<  std::endl;
				// std::cout << (temp->value == x) << std::endl;


				// if (temp->value.first == x.first)
				// // if (!comp(x, temp->value) && !comp(temp->value, x))
				// {
				// 	// std::cout << "ret = " << temp->value.first << " " << x.first << std::endl;
				// 	return temp;
				// }
				// else if ((comp(x, temp->value)) && temp->left != _last_node)
				// 	temp = temp->left;
				// else if ((comp(temp->value, x)) && temp->right != _last_node)
				// 	temp = temp->right;
				// else
				// 	break;
				// if (temp == _last_node)
				// 	return _last_node;

				

				// if (comp(x, temp->value))
				// 	temp = temp->left;
				// else if (comp(temp->value, x))
				// 	temp = temp->right;---------------------------------------------------------------------------------------------------------------------------------------------------------------
				// else
				// {
				// 	// if (x.first != temp->value.first)
				// 	// {
				// 		std::cout << x.first << std::endl;
				// 		std::cout << temp->value.first << std::endl;
				// 	// }

				// 	return temp;
				// }
				// if (temp == _last_node)
				// 	return _last_node;

				if (comp(temp->value, x) == true)
					temp = temp->right;
				else if (comp(temp->value, x) != true)
					temp = temp->left;


				// if (temp->value.first < x.first)
				// 	temp = temp->right;
				// else if (temp->value.first > x.first)
				// 	temp = temp->left;
			}
			// std::cout << "temp->value = " << temp->value.first << " x = " << x.first << std::endl;

			return temp;
		}
		
		size_type delete_by_key(const value_type& x)
		{
			// printTree(_last_node->parent);
			// std::cout << "\n\n\n\n\n\n";
			node_pointer temp = search_by_key(x);
			// printTree(_last_node->parent);
			// std::cout << "\n\n\n";

			// pid_t pid = getpid();
			// string a = "leaks ";
			// a += std::to_string(static_cast<int>(pid));
			// usleep(500);
			// string s = get_leak_string(exec(a.c_str()));
			// if (strlen(s.c_str()) > 50)
			// {
				// std::cout << typeid(comp).name() << std::endl;
				// std::cout << s << std::endl;
				// std::cout << "x = " << x.first << " " << x.second << std::endl;
				// std::cout << temp->value.first << std::endl;
				// printTree(_last_node->parent);
				// std::cout << "\n\n\n";
			// }

			// std::cout << "x = " << x.first << " " << x.second << std::endl;
			// std::cout << temp->value.first << std::endl;
			// printTree(_last_node->parent);
			// std::cout << "\n\n\n";
			if (temp == _last_node)
			{
				// std::cout << "x = " << x.first << x.second << std::endl;
				// printTree(_last_node->parent);
				// std::cout << "\n\n\n";
				return (0);
			}
			iterator it(temp, _last_node);
			size_type gi = delete_by_iterator(temp);
			// printTree(_last_node->parent);
			// std::cout << "\n\n\n";
			return (gi);
		}

		size_type delete_by_iterator(node_pointer node)
		{
			if (node->left == _last_node)
			{
				if (node->parent != _last_node)
				{
					if (node->parent->right == node)
						node->parent->right = node->right;
					else
						node->parent->left = node->right;
				}
				else
					_last_node->parent = node->right;
				if (node->right != _last_node)
					node->right->parent = node->parent;
				else if (_last_node->right == node)
					_last_node->right = node->parent;
				if (_last_node->left == node)
					_last_node->left = get_smaller();
			}
			else
			{
				iterator temp(node, _last_node);
				node_pointer replace((--temp)._node);
				if (replace == _last_node->left)
					_last_node->left = replace->parent;
				replace->right = node->right;
				if (node->right != _last_node)
					node->right->parent = replace;
				if (replace == replace->parent->right)
					replace->parent->right = replace->left;
				else
					replace->parent->left = replace->left;
				if (replace->left != _last_node)
					replace->left->parent = replace->parent;
				if (replace->parent->left != replace)
					replace->left = node->left;
				replace->parent = node->parent;
				if (node->parent != _last_node && node->parent->left == node)
					node->parent->left = replace;
				else if (node->parent != _last_node)
					node->parent->right = replace;
			}
			if (node->parent == _last_node)
			{
				if (node->right != _last_node)
					_last_node->parent = node->right;
				else if (node->left != _last_node)
					_last_node->parent = node->left;
				else
					_last_node->parent = _last_node;
			}
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node, 1);
			_last_node->parent = get_root();
			_last_node->right = get_bigger();
			_last_node->left = get_smaller();
			// printTree(_last_node->parent);
			// std::cout << "\n\n\n\n\n\n";
			
			return (1);
		}

		void swap(BST& x)
		{
			if (&x == this)
				return ;
			
			node_pointer temp = this->_last_node;
			this->_last_node = x._last_node;
			x._last_node = temp;
		}

		// size_type delete_by_range(iterator first, iterator last)
		// {
		// 	node_pointer temp = search_by_key(x);
		// }



		// node_pointer delete_by_key(const value_type& x)
		// {
		// 	node_pointer temp = _last_node->parent;
		// 	if (_last_node->parent == _last_node)
		// 		return _last_node;
		// 	while (temp != _last_node && temp->value.first != x.first)
		// 	{
		// 		if (temp->left.first < x)
		// 			temp = temp->right;
		// 		else if (temp->left.first > x)
		// 			temp = temp->left;
		// 	}
		// 	if (temp->value.first == x.first)
		// 	{
		// 		node_pointer temp2;
		// 		bool side = false;
		// 		if (temp->right != _last_node)
		// 		{
		// 			temp2 = temp->right;
		// 			side = true;
		// 		}
		// 		else if (temp->left != _last_node)
		// 			temp2 = temp->left;
		// 		else
		// 		{
		// 			if (temp->parent->left == temp)
		// 				temp->parent->left = _last_node;
		// 			else if (temp->parent->right == temp)
		// 				temp->parent->right = _last_node;
		// 			_node_alloc.destroy(temp);
		// 			_node_alloc.deallocate(temp, 1);
		// 			return _last_node;
		// 		}
		// 		if (!side)
		// 		{
		// 			if (temp2->left == _last_node)
		// 			{
		// 				if (temp2->right == _last_node)
		// 					temp2->parent->right = _last_node;
		// 				else
		// 					temp2->parent->right = temp2->right;
		// 				if (temp->parent->left == temp)
		// 					temp->parent->left = temp2;
		// 				else if (temp->parent->right == temp)
		// 					temp->parent->right = temp2;
		// 				temp2->right = temp->right;
		// 				temp2->left = temp->left;
		// 				_node_alloc.destroy(temp);
		// 				_node_alloc.deallocate(temp, 1);
		// 				return temp2;
		// 			}
		// 			while(temp2->left != _node_alloc)
		// 				temp2 = temp2->left;
		// 			if (temp2->right == _last_node)
		// 				temp2->parent->left = _last_node;
		// 			else
		// 				temp2->parent->left = temp2->right;
		// 			if (temp->parent->left == temp)
		// 				temp->parent->left = temp2;
		// 			else if (temp->parent->right == temp)
		// 				temp->parent->right = temp2;
		// 			temp2->right = temp->right;
		// 			temp2->left = temp->left;
		// 			_node_alloc.destroy(temp);
		// 			_node_alloc.deallocate(temp, 1);
		// 			return temp2;
		// 		}
		// 		else
		// 		{
		// 			if (temp2->right == _last_node)
		// 			{
		// 				if (temp2->left == _last_node)
		// 					temp2->parent->left = _last_node;
		// 				else
		// 					temp2->parent->left = temp2->left;
		// 				if (temp->parent->right == temp)
		// 					temp->parent->right = temp2;
		// 				else if (temp->parent->left == temp)
		// 					temp->parent->left = temp2;
		// 				temp2->left = temp->left;
		// 				temp2->right = temp->right;
		// 				_node_alloc.destroy(temp);
		// 				_node_alloc.deallocate(temp, 1);
		// 				return temp2;
		// 			}
		// 			while(temp2->right != _node_alloc)
		// 				temp2 = temp2->right;
		// 			if (temp2->left == _last_node)
		// 				temp2->parent->right = _last_node;
		// 			else
		// 				temp2->parent->right = temp2->left;
		// 			if (temp->parent->right == temp)
		// 				temp->parent->right = temp2;
		// 			else if (temp->parent->left == temp)
		// 				temp->parent->left = temp2;
		// 			temp2->left = temp->left;
		// 			temp2->right = temp->right;
		// 			_node_alloc.destroy(temp);
		// 			_node_alloc.deallocate(temp, 1);
		// 			return temp2;
		// 		}
		// 	}
		// 	return _last_node;
		// }
};

}

// namespace ft
// {
// 	template <class T, class Compare = ft::less<T>, class Node = ft::BST_node<T>,
// 			class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
// 	class BST
// 	{
// 		public :

// 			/* Self type */
// 			typedef BST  self;

// 			/* A reference to the self type */
// 			typedef self&   self_reference;
			
// 			/* The first template argument */
// 			typedef T   value_type;

// 			/* Stored Node type */
// 			typedef Node node_type;

// 			/* Pointer to stored node */
// 			typedef Node *  node_pointer;
			
// 			/* Node allocator */
// 			typedef Node_Alloc  node_alloc;

// 			/* Iterator on stored node */
// 			typedef ft::BST_iterator<Node, Compare> iterator;

// 			/* Same than iterator, here for base container template */
// 			typedef ft::BST_const_iterator<Node, Compare> const_iterator;
			
// 			/* Size_t */
// 			typedef size_t size_type;

// 			/*
// 			** @brief Contruct an empty binary search tree
// 			*/
// 			BST (const node_alloc& node_alloc_init = node_alloc())
// 			:
// 				_node_alloc(node_alloc_init)
// 			{
// 				_last_node = _node_alloc.allocate(1);
// 				_node_alloc.construct(_last_node, Node(_last_node, _last_node, _last_node));
// 			}

// 			/*
// 			** It's at that use the tree to delete all nodes.
// 			*/
// 			~BST ()
// 			{
// 				_node_alloc.destroy(_last_node);
// 				_node_alloc.deallocate(_last_node, 1);	
// 			}

// 			/*
// 			** @brief Insert a new node that contain "to_insert".
// 			*/
// 			ft::pair<iterator, bool> insert(value_type to_insert)
// 			{
// 				Node * new_node = _node_alloc.allocate(1);
// 				Node * prev_node = _last_node;
// 				Node * start_node = _last_node->parent;

// 				// side == false = left; side == true = right;
// 				bool side = true;

// 				while (start_node != _last_node)
// 				{
// 					int curkey = start_node->value.first;
// 					if (curkey == to_insert.first)
// 						return (ft::make_pair(iterator(start_node, _last_node), false));
// 					prev_node = start_node;
// 					if (to_insert.first > curkey)
// 					{
// 						side = true;
// 						start_node = start_node->right;
// 					}
// 					else
// 					{
// 						side = false;
// 						start_node = start_node->left;
// 					}
// 				}
// 				_node_alloc.construct(new_node, Node(to_insert, prev_node, _last_node, _last_node));
				
// 				if (prev_node == _last_node)
// 					_last_node->parent = new_node;
// 				else if (side == true)
// 					prev_node->right = new_node;
// 				else
// 					prev_node->left = new_node;
				
// 				_last_node->left = _BST_get_lower_node(_last_node->parent);
// 				_last_node->right = _BST_get_higher_node(_last_node->parent);
// 				_last_node->value.first += 1;
// 				return (ft::make_pair(iterator(new_node, _last_node), true));
// 			}

// 			/*
// 			** @brief need a pair create like : make_pair(key, mapped_type())
// 			*/
// 			void delete_by_key(value_type to_remove)
// 			{ _removeByKey(_last_node->parent, to_remove); }

// 			/*
// 			** @brief need a pair create like : make_pair(key, mapped_type())
// 			*/
// 			node_pointer search_by_key(value_type to_remove)
// 			{
// 				node_pointer node = _last_node->parent;

// 				while (node != _last_node)
// 				{
// 					if (node->value.first == to_remove.first)
// 						return (node);
// 					if (node->value.first > to_remove.first)
// 						node = node->left;
// 					else
// 						node = node->right;
// 				}
// 				return (node);
// 			}

// 			/*
// 			** @brief Swap this elements with "x" elements
// 			*/
// 			void swap(self& x)
// 			{
// 				if (&x == this)
// 					return ;
				
// 				node_pointer save = this->_last_node;
// 				this->_last_node = x._last_node;
// 				x._last_node = save;
// 			}

// 			/*
// 			** @brief return max_size of allocator.
// 			*/
// 			size_type max_size() const
// 			{ return (node_alloc().max_size()); }

// 			// last_node parent = root of tree, last_node right = last node, last_node left = first node
// 			node_pointer    _last_node;
// 			node_alloc      _node_alloc;

// 		private :

// 			/*
// 			** @brief Give node pointer on lower key.
// 			*/
// 			node_pointer _BST_get_lower_node(node_pointer root)
// 			{
// 				while (root != _last_node && root->left != _last_node)
// 					root = root->left;
// 				return (root);
// 			}

// 			/*
// 			** @brief Give node pointer on higher key.
// 			*/
// 			node_pointer _BST_get_higher_node(node_pointer root)
// 			{
// 				while (root != _last_node && root->right != _last_node)
// 					root = root->right;
// 				return (root);
// 			}

// 			/*
// 			** @brief Used to re set link between node is necessary, and
// 			** delete node.
// 			*/
// 			void _replaceNodeInParent(node_pointer node, node_pointer new_node)
// 			{
// 				if (node->parent != _last_node)
// 				{
// 					if (_last_node->parent == node)
// 						_last_node->parent = new_node;

// 					if (node == node->parent->left)
// 						node->parent->left = new_node;
// 					else
// 						node->parent->right = new_node;
// 				}
// 				else
// 					_last_node->parent = new_node;

// 				_last_node->left = _BST_get_lower_node(_last_node->parent);
// 				_last_node->right = _BST_get_higher_node(_last_node->parent);
// 				_last_node->value.first -= 1;
				
// 				new_node->parent = node->parent;
				
// 				_node_alloc.destroy(node);
// 				_node_alloc.deallocate(node, 1);
// 			}

// 			/*
// 			** @brief used to move replacer node and re set all link between
// 			** node where it's necessary and delete to_remove.
// 			*/
// 			void _replaceDoubleChildren(node_pointer& to_remove, node_pointer new_node)
// 			{
// 				if (new_node->parent != _last_node)
// 				{
// 					if (new_node->parent != to_remove)
// 						new_node->parent->left = new_node->right;
// 				}
				
// 				new_node->parent = to_remove->parent;
// 				if (to_remove->left != new_node)
// 					new_node->left = to_remove->left;
// 				if (to_remove->right != new_node)
// 					new_node->right = to_remove->right;

// 				if (to_remove->parent != _last_node)
// 				{
// 					if (to_remove->parent->left == to_remove)
// 						to_remove->parent->left = new_node;
// 					else if (to_remove->parent->right == to_remove)
// 						to_remove->parent->right = new_node;
// 				}
// 				else
// 					_last_node->parent = new_node;
					
// 				if (to_remove->left != _last_node && to_remove->left != new_node)
// 					to_remove->left->parent = new_node;
// 				if (to_remove->right != _last_node && to_remove->right != new_node)
// 					to_remove->right->parent = new_node;

// 				if (to_remove->parent != _last_node)
// 				{
// 					to_remove->left = _last_node;
// 					to_remove->right = _last_node;
// 					to_remove->parent = new_node;
// 				}

// 				_last_node->left = _BST_get_lower_node(_last_node->parent);
// 				_last_node->right = _BST_get_higher_node(_last_node->parent);
// 				_last_node->value.first -= 1;

// 				_node_alloc.destroy(to_remove);
// 				_node_alloc.deallocate(to_remove, 1);
// 			}

// 			/*
// 			** @brief need a pair create like : make_pair(key, mapped_type())
// 			*/
// 			void _removeByKey(node_pointer node, value_type to_remove)
// 			{
// 				if (to_remove.first < node->value.first)
// 				{
// 					_removeByKey(node->left, to_remove);
// 					return ;
// 				}

// 				if (to_remove.first > node->value.first)
// 				{
// 					_removeByKey(node->right, to_remove);
// 					return ;
// 				}

// 				if (node->left != _last_node && node->right != _last_node)
// 				{
// 					node_pointer successor = _BST_get_lower_node(node->right);
// 					_replaceDoubleChildren(node, successor);
// 					return ;
// 				}
// 				else if (node->left != _last_node)
// 					_replaceNodeInParent(node, node->left);
// 				else if (node->right != _last_node)
// 					_replaceNodeInParent(node, node->right);
// 				else
// 					_replaceNodeInParent(node, _last_node);
// 			}
// 	};
// }

#endif