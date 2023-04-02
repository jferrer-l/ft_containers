/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:53:55 by jferrer-          #+#    #+#             */
/*   Updated: 2023/03/13 01:40:15 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
#define TESTS_HPP

// #ifndef STD
// 	#define STD true
// #endif

// #ifdef STD
//     #define _vector std::vector
//     #define _map std::map
//     #define _stack std::stack
// #else
//     #define _vector ft::vector
//     #define _map ft::map
//     #define _stack ft::stack
// #endif

// #ifdef STDVA
//     #define STDVA true
// #else
//     #define STDVA false
// #endif


#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <string>
#include "../containers/vector.hpp"


// #ifdef STDVA
// 	#define _vector std::vector
// 	#define _map std::map
// 	#define _stack std::stack
// #else
// 	#define _vector ft::vector
// 	#define _map ft::map
// 	#define _stack ft::stack
// #endif


#define _elements 50

void print_test_name(std::string name);

void execute_vector_tests();

void execute_map_tests();

void execute_stack_tests();

void execute_utils_tests();

#endif