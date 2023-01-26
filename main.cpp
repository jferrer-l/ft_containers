/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:55:01 by jferrer-          #+#    #+#             */
/*   Updated: 2023/01/26 02:24:39 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "containers/vector.hpp"
//#include "containers/iterator.hpp"
#include <vector>
#include <iterator>
//#include "vector_iterator.hpp"

int	test_iterator_0a();
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

	ft::vector<int>::iterator it;
	

	test_iterator_0a();
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

int	test_iterator_0a()
{

	// //ft::vector<int>::iterator va;
	// //fd::iterator<ft::vector<int> >  it2;
	// //fd::iterator<ft::vector<int> >  it;
	// ft::vector<int>::iterator it;
	// ft::iterator<ft::vector<int> >  it2;
	// //std::iterator<std::random_access_iterator_tag, int> it3;
	// std::vector<int>::iterator it3;
	// std::cout << it.base() << std::endl;
	// it++;
	// std::cout << it.base() << std::endl;

	// std::cout << it2.base() << std::endl;
	// it2++;
	// std::cout << it2.base() << std::endl;

	// std::cout << it3.base() << std::endl;
	// it3++;
	// std::cout << it3.base() << std::endl;


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