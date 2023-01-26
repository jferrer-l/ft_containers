/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:56:27 by jferrer-          #+#    #+#             */
/*   Updated: 2023/01/23 17:40:21 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

//#include <type_traits>

namespace ft
{

	/*		enable_if		*/

	template <bool B>
	struct enable_if {};

	template <>
	struct enable_if<true> { typedef int type; };


	/*									  	is_integral			    								*/
	/*	https://stackoverflow.com/questions/23070099/c98-compile-time-detect-floating-point-type    */

	template <typename T>
	struct is_integral
	{
		static const bool value;
	};

	template <typename T>
	const bool is_integral<T>::value = std::numeric_limits<T>::is_integer;


	// template <class _Tp>
	// struct __is_cpp17_forward_iterator : public __has_iterator_category_convertible_to<_Tp, forward_iterator_tag> {};






}

#endif