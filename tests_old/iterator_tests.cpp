// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   iterator_tests.cpp                                 :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/01/28 01:25:21 by jferrer-          #+#    #+#             */
// /*   Updated: 2023/01/29 21:06:47 by jferrer-         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "tests.hpp"

// int	test_reverse_iterator()
// {

// 	top("Test reverse iterator elements");
// 	{
// 		std::cout << "Original reverse_iterator construction iterator_category: " << typeid(std::iterator_traits<std::reverse_iterator<std::iterator<std::bidirectional_iterator_tag, int> > >::iterator_category).name() << std::endl;
// 		std::cout << "My reverse_iterator construction iterator_category      : " << typeid(ft::iterator_traits<ft::reverse_iterator<ft::iterator<std::bidirectional_iterator_tag, int> > >::iterator_category).name() << std::endl;
// 		static_assert(std::is_same<std::iterator_traits<std::reverse_iterator<std::iterator<std::bidirectional_iterator_tag, int> > >::iterator_category,
// 									ft::iterator_traits<ft::reverse_iterator<ft::iterator<std::bidirectional_iterator_tag, int> > >::iterator_category>::value, "failed reverse iterator category");
// 		std::cout << std::endl;
// 		std::cout << "Original reverse_iterator construction value_type: " << typeid(std::iterator_traits<std::reverse_iterator<std::iterator<std::bidirectional_iterator_tag, std::string> > >::value_type).name() << std::endl;
// 		std::cout << "My reverse_iterator construction value_type      : " << typeid(ft::iterator_traits<ft::reverse_iterator<ft::iterator<std::bidirectional_iterator_tag, std::string> > >::value_type).name() << std::endl;
// 		static_assert(std::is_same<std::iterator_traits<std::reverse_iterator<std::iterator<std::bidirectional_iterator_tag, std::string> > >::value_type,
// 									ft::iterator_traits<ft::reverse_iterator<ft::iterator<std::bidirectional_iterator_tag, std::string> > >::value_type>::value, "failed reverse iterator category");
// 		std::cout << std::endl;
// 		std::cout << "Original reverse_iterator construction value_type: " << typeid(std::iterator_traits<std::reverse_iterator<std::iterator<std::forward_iterator_tag, std::string> > >::__primary_template).name() << std::endl;
// 		std::cout << "My reverse_iterator construction value_type      : " << typeid(ft::iterator_traits<ft::reverse_iterator<ft::iterator<std::forward_iterator_tag, std::string> > >::value_type).name() << std::endl;
// 		static_assert(std::is_same<std::iterator_traits<std::reverse_iterator<std::iterator<std::forward_iterator_tag, std::string> > >::value_type,
// 									ft::iterator_traits<ft::reverse_iterator<ft::iterator<std::forward_iterator_tag, std::string> > >::value_type>::value, "failed reverse iterator category");
// 	}
// 	bot("Test reverse iterator elements done");
// 	return 0;
// }

// int	test_iterator_constructors()
// {
// 	// double		time;
// 	// std::string	tmp;
// 	// clock_t		start, end;
// 	top("Test iterator constructors");
// 	{
// 		//static_assert(std::is_same<std::iterator<std::bidirectional_iterator_tag, std::string>, ft::iterator<std::bidirectional_iterator_tag, std::string> >::operator(), "failed iterator constructor");
// 		std::vector<int> vec1;
// 		std::vector<int> vec2;

		

// 		vec1.push_back(1);
// 		vec2.push_back(1);
// 		vec1.push_back(2);
// 		vec2.push_back(2);
// 		vec1.push_back(3);
// 		vec2.push_back(3);

// 		std::iterator<std::random_access_iterator_tag, int> it1;
// 		ft::iterator<std::random_access_iterator_tag, int> it2;

// 		std::cout << "default constructors test 1 done" << std::endl;

// 		//std::iterator<std::random_access_iterator_tag, int> it11(arr);
// 		//ft::iterator<std::random_access_iterator_tag, int>((vec2[0]));
// 		//std::cout << 

// 		(void)it1;
// 		(void)it2;

// 	}

// 	bot("Test iterator constructors done");

// 	return 0;
// }

// int	test_iterator_traits_categories()
// {

// 	double		time;
// 	std::string	tmp;
// 	clock_t		start, end;

// 	top("Test iterator_traits elements");
// 	{
// 		std::cout << "Elements tested in order:" << "\n\n" <<
// 		"std::iterator_traits<std::iterator<std::random_access_iterator_tag, int> >" << std::endl <<
// 		"ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >" << std::endl <<
// 		"std::iterator_traits<std::vector<int>::iterator>" << std::endl <<
// 		"ft::iterator_traits<ft::vector<int>::iterator>" << std::endl << std::endl;

// 		{
// 			static_assert(std::is_same<std::iterator_traits<std::iterator<std::random_access_iterator_tag, int> >::iterator_category, ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >::iterator_category>::value, "failed iterator_category");
// 			static_assert(std::is_same<std::iterator_traits<std::vector<int>::iterator>::iterator_category, ft::iterator_traits<ft::vector<int>::iterator>::iterator_category>::value, "failed iterator_category");
// 			std::cout << "iterator_category:" << std::endl << std::endl;
// 			start = clock();
// 			tmp = typeid(std::iterator_traits<std::iterator<std::random_access_iterator_tag, int> >::iterator_category).name();
// 			end = clock();
// 			time = end - start;
// 			std::cout << tmp << "		original time spent: " << time << std::endl;
// 			start = clock();
// 			tmp = typeid(ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >::iterator_category).name();
// 			end = clock();
// 			std::cout << tmp << SELECT_COLOR(time, end - start) <<  "		my time spent: " << end - start << RESET_COLOR << std::endl;
// 			start = clock();
// 			tmp = typeid(std::iterator_traits<std::vector<int>::iterator>::iterator_category).name();
// 			end = clock();
// 			time = end - start;
// 			std::cout << tmp << "		original time spent: " << end - start << std::endl;
// 			start = clock();
// 			tmp = typeid(ft::iterator_traits<ft::vector<int>::iterator>::iterator_category).name();
// 			end = clock();
// 			std::cout << tmp << SELECT_COLOR(time, end - start) <<  "		my time spent: " << end - start << RESET_COLOR << std::endl;
// 		}
// 		std::cout << std::endl;
// 		{
// 			static_assert(std::is_same<std::iterator_traits<std::iterator<std::random_access_iterator_tag, int> >::difference_type, ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >::difference_type>::value, "failed difference_type");
// 			static_assert(std::is_same<std::iterator_traits<std::vector<int>::iterator>::difference_type, ft::iterator_traits<ft::vector<int>::iterator>::difference_type>::value, "failed difference_type");
// 			std::cout << "difference_type:" << std::endl << std::endl;
// 			start = clock();
// 			tmp = typeid(std::iterator_traits<std::iterator<std::random_access_iterator_tag, int> >::difference_type).name();
// 			end = clock();
// 			time = end - start;
// 			std::cout << tmp << "		original time spent: " << end - start << std::endl;
// 			start = clock();
// 			tmp = typeid(ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >::difference_type).name();
// 			end = clock();
// 			std::cout << tmp << SELECT_COLOR(time, end - start) <<  "		my time spent: " << end - start << RESET_COLOR << std::endl;
// 			start = clock();
// 			tmp = typeid(std::iterator_traits<std::vector<int>::iterator>::difference_type).name();
// 			end = clock();
// 			time = end - start;
// 			std::cout << tmp << "		original time spent: " << end - start << std::endl;
// 			start = clock();
// 			tmp = typeid(ft::iterator_traits<ft::vector<int>::iterator>::difference_type).name();
// 			end = clock();
// 			std::cout << tmp << SELECT_COLOR(time, end - start) <<  "		my time spent: " << end - start << RESET_COLOR << std::endl;
// 		}
// 		std::cout << std::endl;
// 		{
// 			static_assert(std::is_same<std::iterator_traits<std::iterator<std::random_access_iterator_tag, int> >::value_type, ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >::value_type>::value, "failed value_type");
// 			static_assert(std::is_same<std::iterator_traits<std::vector<int>::iterator>::value_type, ft::iterator_traits<ft::vector<int>::iterator>::value_type>::value, "failed value_type");
// 			std::cout << "value_type:" << std::endl << std::endl;
// 			start = clock();
// 			tmp = typeid(std::iterator_traits<std::iterator<std::random_access_iterator_tag, int> >::value_type).name();
// 			end = clock();
// 			time = end - start;
// 			std::cout << tmp << "		original time spent: " << end - start << std::endl;
// 			start = clock();
// 			tmp = typeid(ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >::value_type).name();
// 			end = clock();
// 			std::cout << tmp << SELECT_COLOR(time, end - start) <<  "		my time spent: " << end - start << RESET_COLOR << std::endl;
// 			start = clock();
// 			tmp = typeid(std::iterator_traits<std::vector<int>::iterator>::value_type).name();
// 			end = clock();
// 			time = end - start;
// 			std::cout << tmp << "		original time spent: " << end - start << std::endl;
// 			start = clock();
// 			tmp = typeid(ft::iterator_traits<ft::vector<int>::iterator>::value_type).name();
// 			end = clock();
// 			std::cout << tmp << SELECT_COLOR(time, end - start) <<  "		my time spent: " << end - start << RESET_COLOR << std::endl;
// 		}
// 		std::cout << std::endl;
// 		{
// 			static_assert(std::is_same<std::iterator_traits<std::iterator<std::random_access_iterator_tag, int> >::pointer, ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >::pointer>::value, "failed pointer");
// 			static_assert(std::is_same<std::iterator_traits<std::vector<int>::iterator>::pointer, ft::iterator_traits<ft::vector<int>::iterator>::pointer>::value, "failed pointer");
// 			std::cout << "pointer:" << std::endl << std::endl;
// 			start = clock();
// 			tmp = typeid(std::iterator_traits<std::iterator<std::random_access_iterator_tag, int> >::pointer).name();
// 			end = clock();
// 			time = end - start;
// 			std::cout << tmp << "		original time spent: " << end - start << std::endl;
// 			start = clock();
// 			tmp = typeid(ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >::pointer).name();
// 			end = clock();
// 			std::cout << tmp << SELECT_COLOR(time, end - start) <<  "		my time spent: " << end - start << RESET_COLOR << std::endl;
// 			start = clock();
// 			tmp = typeid(std::iterator_traits<std::vector<int>::iterator>::pointer).name();
// 			end = clock();
// 			time = end - start;
// 			std::cout << tmp << "		original time spent: " << end - start << std::endl;
// 			start = clock();
// 			tmp = typeid(ft::iterator_traits<ft::vector<int>::iterator>::pointer).name();
// 			end = clock();
// 			std::cout << tmp << SELECT_COLOR(time, end - start) <<  "		my time spent: " << end - start << RESET_COLOR << std::endl;
// 		}
// 		std::cout << std::endl;
// 		{
// 			static_assert(std::is_same<std::iterator_traits<std::iterator<std::random_access_iterator_tag, int> >::reference, ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >::reference>::value, "failed reference");
// 			static_assert(std::is_same<std::iterator_traits<std::vector<int>::iterator>::reference, ft::iterator_traits<ft::vector<int>::iterator>::reference>::value, "failed reference");
// 			std::cout << "reference:" << std::endl << std::endl;
// 			start = clock();
// 			tmp = typeid(std::iterator_traits<std::iterator<std::random_access_iterator_tag, int> >::reference).name();
// 			end = clock();
// 			time = end - start;
// 			std::cout << tmp << "		original time spent: " << end - start << std::endl;
// 			start = clock();
// 			tmp = typeid(ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >::reference).name();
// 			end = clock();
// 			std::cout << tmp << SELECT_COLOR(time, end - start) <<  "		my time spent: " << end - start << RESET_COLOR << std::endl;
// 			start = clock();
// 			tmp = typeid(std::iterator_traits<std::vector<int>::iterator>::reference).name();
// 			end = clock();
// 			time = end - start;
// 			std::cout << tmp << "		original time spent: " << end - start << std::endl;
// 			start = clock();
// 			tmp = typeid(ft::iterator_traits<ft::vector<int>::iterator>::reference).name();
// 			end = clock();
// 			std::cout << tmp << SELECT_COLOR(time, end - start) <<  "		my time spent: " << end - start << RESET_COLOR << std::endl;
// 		}
// 		std::cout << std::endl;

// 	}
// 	bot("Test iterator_traits elements done");

// 	return 0;
// }
