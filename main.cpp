/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:55:01 by jferrer-          #+#    #+#             */
/*   Updated: 2023/02/22 18:52:30 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "containers/vector.hpp"
//#include "containers/iterator.hpp"
#include <vector>
#include <iterator>

#include "tests/tests.hpp"

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

// template <class T>
void	print_vec(std::vector<int> T)
{
	std::cout << "vector size = " << T.size() << ", capacity = " << T.capacity() << std::endl;
	for (size_t i = 0; i < T.size(); i++)
		std::cout << T[i] << " ";
	std::cout << std::endl;
}

int main()
{
	{
		ft::vector<int *> temp;
		

		std::unique_ptr<void *> k2;

		ft::vector<int> A;

		size_t peta = 100000000;
		while (1)
			A.reserve((peta *= 2));
		// temp.push_back(&(*k2));
		// temp.push_back(A);
		// temp.push_back(2);

		// std::cout << *temp.begin() << std::endl;
		temp.begin();

		

		temp.assign(temp.end(), temp.begin());
		// temp.reserve(87356768734699756);
		// temp.at(5);
		// temp.front();
		// temp.back();
	}
	{



		std::vector<int>	assignvec(5, 1);

		std::vector<int>	assignvec2(6, 2);

		// assignvec2.at(9);

		print_vec(assignvec);

		assignvec.assign(assignvec2.begin(), assignvec2.end());

		print_vec(assignvec);





		std::vector<int>	tvec;

		std::cout << "capacity = " << tvec.capacity() << " size = " << tvec.size() << std::endl;
		tvec.push_back(1);
		std::cout << "capacity = " << tvec.capacity() << " size = " << tvec.size() << std::endl;
		tvec.resize(24, 1);
		std::cout << "capacity = " << tvec.capacity() << " size = " << tvec.size() << std::endl;
		tvec.resize(12, 2);
		std::cout << "capacity = " << tvec.capacity() << " size = " << tvec.size() << std::endl;
		tvec.reserve(100);
		std::cout << "capacity = " << tvec.capacity() << " size = " << tvec.size() << std::endl;
		tvec.reserve(10);
		std::cout << "capacity = " << tvec.capacity() << " size = " << tvec.size() << std::endl;
		
		ptrdiff_t dist = std::distance(tvec.end(), tvec.begin());

		std::cout << "distance = " << dist << std::endl;

		std::vector<int> tvec2(tvec.begin(), tvec.begin() + 1);

		std::vector<int>::iterator first = tvec.begin();
		std::vector<int>::iterator last = tvec.end();

		std::cout << "capacity2 = " << tvec2.capacity() << " size2 = " << tvec2.size() << std::endl;
		ft::vector<int> tempvec(tvec.begin(), tvec.end());
		std::cout << "capacity2 = " << tempvec.capacity() << " size2 = " << tempvec.size() << std::endl;

		size_t dist2 = std::distance(first, last);

		size_t i = 0;
		for (; i < dist2 && first != last; ++first, ++i) {}
		std::cout << "result = " << (i == dist2) << std::endl;
		std::cout << "distance2 = " << dist2 << std::endl;


		std::cout << "capacity = " << tvec2.capacity() << " size = " << tvec2.size() << std::endl;

		std::vector<int>	ovec(4, 6);
		std::vector<int>	ovec2(ovec.begin(), ovec.end());
		ft::vector<int>		myvec(ovec.begin(), ovec.end());
		ft::vector<int>		myvec2(myvec);


		std::vector<std::vector<int> >		ovec3;
		ft::vector<std::vector<int> >		myvec3;

		std::cout << typeid(std::vector<char>::size_type).name() << std::endl;
		std::cout << typeid(ft::vector<char>::size_type).name() << std::endl;
		std::cout << "max size: " << ovec.max_size() << std::endl;
		std::cout << "max size: " << ovec3.max_size() << std::endl;

		std::cout << "max size: " << myvec.max_size() << std::endl;
		std::cout << "max size: " << myvec3.max_size() << std::endl;
		

		// ft::iterator<std::random_access_iterator_tag, int> it1;

		// std::iterator<std::random_access_iterator_tag, int> it2;

		//ft::vector<int>::iterator **it3;

		//static_assert(std::is_same<ft::iterator_traits<ft::vector<int>::iterator>, ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >::iterator_category>::value, "temp");

		// test_reverse_iterator();
		// test_iterator_traits_categories();
		// test_iterator_constructors();

		// static_assert(std::is_same<ft::iterator<std::random_access_iterator_tag, int>::iterator_category, std::iterator<std::random_access_iterator_tag, int>::iterator_category>::value, "failed iterator_category");

		// // ft::vector<int>::iterator *it;
		// // ft::iterator_traits<ft::vector<int>::iterator>::iterator_category temp;
		// //static_assert(std::is_same_v<ft::iterator_traits<ft::vector<int>::iterator>::iterator_category, std::random_access_iterator_tag>>);
		// static_assert(std::is_same<ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >::iterator_category, std::random_access_iterator_tag>::value, "failed iterator_category");
		// static_assert(std::is_same<ft::iterator_traits<ft::vector<int>::iterator>::difference_type, ptrdiff_t>::value, "failed difference_type");
		//static_assert(std::is_same<ft::iterator_traits<ft::vector<int>::iterator>::value_type, int>::value, "failed difference_type");

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

