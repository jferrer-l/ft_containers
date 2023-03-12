/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:58:07 by jferrer-          #+#    #+#             */
/*   Updated: 2023/03/12 19:58:16 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void print_test_name(std::string name)
{
	std::cout << "*" << std::string(150, '-') << "*" << std::endl;
	std::cout << "|" << std::string((150 - name.size()) / 2, ' ') << name << std::string((150 - name.size()) / 2 + ((150 - name.size()) % 2), ' ') << "|" << std::endl;
	std::cout << "*" << std::string(150, '-') << "*" << std::endl;
}