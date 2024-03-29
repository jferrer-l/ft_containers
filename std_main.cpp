/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:02:08 by jferrer-          #+#    #+#             */
/*   Updated: 2023/03/13 01:47:53 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <string>
#include <unistd.h>
#include "tests/tests.hpp"

void execute_all_tests();
// void execute_vector_tests();
// void execute_map_tests();
// void execute_stack_tests();
// void execute_utils_tests();
// void print_test_name(std::string name);


int main(int argc, char **argv)
{
	// std::cout << STDVA << std::endl;
	if (argc != 1)
	{
		std::string arg(argv[1]);
		if (arg == std::string("-v"))
		{
			execute_vector_tests();
		}
		else if (arg == std::string("-m"))
		{
			execute_map_tests();
		}
		else if (arg == std::string("-s"))
		{
			execute_stack_tests();
		}
		else if (arg == std::string("-u"))
			execute_utils_tests();
	}
	else
		execute_all_tests();
	
	// {
	// 	std::string a = "leaks ";
	// 	a += std::to_string(static_cast<int>(getpid()));
	// 	system(a.c_str());
	// }
	return 0;
}

void execute_all_tests()
{
	execute_vector_tests();
	execute_map_tests();
	execute_stack_tests();
	execute_utils_tests();
}









