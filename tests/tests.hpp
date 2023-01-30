/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:25:24 by jferrer-          #+#    #+#             */
/*   Updated: 2023/01/30 00:25:54 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>
#include <iterator>
#include <cstddef>
#include "../containers/vector.hpp"
#include "../containers/iterator.hpp"

#define LINE_SIZE_TEST 80
#define RESET_COLOR "\033[0m"
#define SELECT_COLOR(num1, num2) ((num1 * 20 < num2) && (num1 > 0) ? "\033[31m" : "\033[32m")


// enum class Types {
// 	INT,
// 	FLOAT,
// 	CHAR,
// };

/*				Iterator Tests				*/

int		test_iterator_traits_categories();
int		test_iterator_constructors();
int		test_reverse_iterator();
void	top(std::string temp);
void	bot(std::string temp);


/*				Vector Tests				*/



#endif