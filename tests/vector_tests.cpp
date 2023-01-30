/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:05:34 by jferrer-          #+#    #+#             */
/*   Updated: 2023/01/30 00:26:11 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"



int	test_max_size() //test more types
{
	std::vector<int >		ovec;
	ft::vector<int >		myvec;

	std::vector<std::vector<int> >		ovec3;
	ft::vector<std::vector<int> >		myvec3;

	std::cout << typeid(std::vector<char>::size_type).name() << std::endl;
	std::cout << typeid(ft::vector<char>::size_type).name() << std::endl;
	std::cout << "max size: " << ovec.max_size() << std::endl;
	std::cout << "max size: " << ovec3.max_size() << std::endl;

	std::cout << "max size: " << myvec.max_size() << std::endl;
	std::cout << "max size: " << myvec3.max_size() << std::endl;

	return 0;
}