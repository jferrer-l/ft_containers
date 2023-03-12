/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:06:24 by jferrer-          #+#    #+#             */
/*   Updated: 2023/01/29 21:06:51 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	top(std::string temp)
{
	std::cout << std::endl << std::string((LINE_SIZE_TEST - temp.size()) / 2, ' ') << temp << std::endl;
	std::cout << std::string(LINE_SIZE_TEST, '*') << std::endl;
}

void	bot(std::string temp)
{
	std::cout << std::string(LINE_SIZE_TEST, '*') <<
	 std::endl << std::string((LINE_SIZE_TEST - temp.size()) / 2, ' ') << temp << std::endl << std::endl;
}