/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:54:40 by jferrer-          #+#    #+#             */
/*   Updated: 2023/03/13 01:48:59 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef STDVA
	#define _vector std::vector
	#define _map std::map
	#define _stack std::stack
#else
	#define _vector ft::vector
	#define _map ft::map
	#define _stack ft::stack
#endif

#include "tests.hpp"


// #ifdef STDVA
//     #define STDVA true
// #else
//     #define STDVA false
// #endif

template<typename T>
void print_vec(std::vector<T> vtemp)
{
	for (size_t it = 0; it != vtemp.size(); it++)
		std::cout << "[" << vtemp[it] << "] ";
	std::cout << std::endl;
}

void execute_vector_tests()
{
	std::cout << BUFFER_SIZE << std::endl;
	std::vector<int> results;
	_vector<int> values;
	// typename _vector<int>::iterator it;
	
	std::cout << typeid(_vector<int>::iterator::iterator_category).name() << std::endl;
	// std::cout << temp_values.capacity() << std::endl;
	for (int i = 0; i < _elements; i++)
		values.push_back(i);
	print_test_name("VECTOR TEST");
	{
		_vector<int> vtemp;
		results.push_back(vtemp.size());
		results.push_back(vtemp.capacity());
		_vector<int> vtemp2(8, 42);
		results.push_back(vtemp2.size());
		results.push_back(vtemp2.capacity());
		results.push_back(vtemp2[5]);
		vtemp2.push_back(6);
		vtemp2.push_back(7);
		vtemp2.push_back(8);
		results.push_back(vtemp2[9]);
		results.push_back(vtemp2.front());
		results.push_back(vtemp2.back());
		_vector<int> vtemp3(vtemp2.begin(), vtemp2.end());
		results.push_back(vtemp3.size());
		results.push_back(vtemp3.capacity());
		results.push_back(vtemp3[5]);
		results.push_back(vtemp3[8]);
		results.push_back(vtemp3[9]);
		results.push_back(vtemp3.front());
		results.push_back(vtemp3.back());
		results.push_back(*(++vtemp3.begin()));
		_vector<int> vtemp4 = vtemp3;
		results.push_back(vtemp4.size());
		results.push_back(vtemp4.capacity());
		results.push_back(vtemp4[5]);
		results.push_back(vtemp4[8]);
		results.push_back(vtemp4[9]);
		results.push_back(vtemp4.front());
		results.push_back(vtemp4.back());
		results.push_back(*(++vtemp4.begin()));

		print_vec(results);
	}
	results.clear();
	{
		results.push_back(*values.begin());
		results.push_back(*(++values.begin()));
		results.push_back(*values.end());
		results.push_back(*(--values.end()));
		results.push_back(*values.rbegin());
		results.push_back(*(++values.rbegin()));
		results.push_back(*values.rend());
		results.push_back(*(--values.rend()));

		
		print_vec(results);
	}
	results.clear();
	{
		std::vector<size_t> results2;
		_vector<char> cvec;
		_vector<std::string> svec;
		_vector<_vector<int> > vivec;
		_vector<_vector<char> > vcvec;
		_vector<long> lvec;

		results2.push_back(cvec.max_size());
		results2.push_back(svec.max_size());
		results2.push_back(vivec.max_size());
		results2.push_back(vcvec.max_size());
		results2.push_back(lvec.max_size());

		print_vec(results2);
	}
	results.clear();
	{
		_vector<int> tempv;
		results.push_back(tempv.size());
		results.push_back(tempv.capacity());

		tempv.reserve(5);

		results.push_back(tempv.size());
		results.push_back(tempv.capacity());

		tempv.reserve(2);

		results.push_back(tempv.size());
		results.push_back(tempv.capacity());

		tempv.insert(tempv.begin(), values.begin(), values.end());
		results.push_back(tempv.size());
		results.push_back(tempv.capacity());

		print_vec(results);
	}
	

}