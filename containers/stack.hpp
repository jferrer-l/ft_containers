/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:32:28 by jferrer-          #+#    #+#             */
/*   Updated: 2023/02/23 11:59:59 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"


namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef typename Container::value_type	value_type;
			typedef typename Container::size_type	size_type;
			typedef Container						container_type;
		protected:
			Container c;
		public:
			explicit stack(const Container& _c = Container()): c(_c) {}
			bool				empty() const				{ return c.empty(); }
			size_type			size() const				{ return c.size(); }
			value_type&			top()						{ return c.back(); }
			const value_type&	top() const					{ return c.back(); }
			void				push(const value_type& x)	{ c.push_back(x); }
			void				pop()						{ c.pop_back(); }

			template <typename valuetype, typename container_type>
			friend bool operator==(const stack<valuetype, container_type>& x,
			const stack<valuetype, container_type>& y)
			{
				return x.c == y.c;
			}

			template <typename valuetype, typename container_type>
			friend bool operator< (const stack<valuetype, container_type>& x,
			const stack<valuetype, container_type>& y)
			{
				return x.c < y.c;
			}

			template <typename valuetype, typename container_type>
			friend bool operator!=(const stack<valuetype, container_type>& x,
			const stack<valuetype, container_type>& y)
			{
				return x.c != y.c;
			}

			template <typename valuetype, typename container_type>
			friend bool operator> (const stack<valuetype, container_type>& x,
			const stack<valuetype, container_type>& y)
			{
				return x.c > y.c;
			}

			template <typename valuetype, typename container_type>
			friend bool operator>=(const stack<valuetype, container_type>& x,
			const stack<valuetype, container_type>& y)
			{
				return x.c >= y.c;
			}

			template <typename valuetype, typename container_type>
			friend bool operator<=(const stack<valuetype, container_type>& x,
			const stack<valuetype, container_type>& y)
			{
				return x.c <= y.c;
			}

	};
	
	

	
	
}