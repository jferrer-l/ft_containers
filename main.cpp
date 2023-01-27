/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:55:01 by jferrer-          #+#    #+#             */
/*   Updated: 2023/01/27 23:22:35 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "containers/vector.hpp"
//#include "containers/iterator.hpp"
#include <vector>
#include <iterator>
#include <cassert>
// #include <gtest/gtest.h>
//#include "vector_iterator.hpp"

int	test_iterator();
int	test_iterator_0b();

// template<typename T>
// class MyContainer;

// template <typename T>
// struct MyIterator {
//     // constructor
//     MyIterator(MyContainer<T>* container, int index) : m_container(container), m_index(index) {}
//     // overload the increment operator
//     MyIterator& operator++() {
//         ++m_index;
//         return *this;
//     }
//     // overload the dereference operator
//     T& operator*() {
//         return m_container->getElement(m_index);
//     }
//     // overload the comparison operators
//     bool operator==(const MyIterator& other) {
//         return m_index == other.m_index;
//     }
//     bool operator!=(const MyIterator& other) {
//         return !(*this == other);
//     }
//     private:
//         MyContainer<T>* m_container;
//         int m_index;
// };

// template<typename T>
// class MyContainer {
//     // implementation here
//     public:
// 	MyIterator<MyContainer> iterator;
//     //using iterator = MyIterator<MyContainer>;
//     // iterator begin();
//     // iterator end();
// };

int main()
{
	{
	std::vector<int>	ovec(4, 6);
	std::vector<int>	ovec2(ovec.begin(), ovec.end());
	ft::vector<int>		myvec(ovec.begin(), ovec.end());
	ft::vector<int>		myvec2(myvec);

	// ft::vector<int>::iterator *it;
	// ft::iterator_traits<ft::vector<int>::iterator>::iterator_category temp;
	//static_assert(std::is_same_v<ft::iterator_traits<ft::vector<int>::iterator>::iterator_category, std::random_access_iterator_tag>>);
	static_assert(std::is_same<ft::iterator_traits<ft::vector<int>::iterator>::iterator_category, std::random_access_iterator_tag>::value, "va");
	//ft::iterator<ft::vector<int>, int > it900;
	// std::iterator<std::vector<int> , int > it5;
	// std::iterator<
	// ft::iterator<
	test_iterator();
	//test_iterator_0b();
	
	//std::vector<int>::iterator temp = myvec2.begin();

	// for (; temp != myvec2.end(); *temp++)
	// 	std::cerr << *temp << std::endl;

	std::cout << ovec2[0] << std::endl;
	ovec2[0] = 9;
	std::cout << ovec[0] << std::endl;
	}
	//system("leaks exec");
	return 0;
}

int	test_iterator()
{

	// std::vector<int> container0 {1, 2, 3, 4, 5, 6, 7, 8, 9};
	// std::vector<int> container1 {1, 2, 3, 4, 5, 6, 7, 8, 9};

	//std::iterator<std::vector<int>, int> it0;
	//it0 = container0.begin();

	// std::vector<int>::iterator it0 = container0.begin();
	//std::vector<int>::ft::iterator 


	// (void)it0;
	//(void)it1;
	std::cout << "Default constructor test:" << std::endl;
	{
		//it0.begin();
		//assert(it0 == it2);
	}
	std::cout << "Pointer constructor test:" << std::endl;
	{
		
	}
	std::cout << "Copy constructor test:" << std::endl;
	{
		
	}
	std::cout << "Copy assignment operator test:" << std::endl;
	{
		
	}
	std::cout << "Dereference operator test:" << std::endl;
	{
		
	}
	std::cout << "Arrow operator test:" << std::endl;
	{
		
	}
	std::cout << "Pre-increment operator test:" << std::endl;
	{
		
	}
	std::cout << "Post-increment operator test:" << std::endl;
	{
		
	}
	std::cout << "Equality operator test:" << std::endl;
	{
		
	}
	std::cout << "Inequality operator test:" << std::endl;
	{
		
	}
	std::cout << "Less than operator test:" << std::endl;
	{
		
	}
	std::cout << "Random access test:" << std::endl;
	{
		
	}
	std::cout << "Conversion to const iterator test:" << std::endl;
	{
		
	}
	std::cout << "Input iterator test:" << std::endl;
	{
		
	}
	std::cout << "Output iterator test:" << std::endl;
	{
		
	}
	
	

	//MyContainer<int>::iterator it;

	return 0;
}

// int	test_iterator_0b()
// {
// 	std::vector<int>::iterator it;
// 	//std::iterator<std::vector<int> >  it;
// 	std::cout << it.base() << std::endl;
// 	it++;
// 	std::cout << it.base() << std::endl;

// 	return 0;
// }