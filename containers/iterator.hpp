/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:38:55 by jferrer-          #+#    #+#             */
/*   Updated: 2023/01/26 02:22:10 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

// #include <iterator>
// #include <memory>
// #include <cstddef>


// namespace ft
// {

// template <typename C>
// class iterator
// {
// 	public:
// 		typedef C									value_type;
// 		typedef C*									pointer;
// 		typedef const C*							const_pointer;
// 		typedef C&									reference;
// 		typedef const C&							const_reference;
// 		typedef ptrdiff_t							ptr_diff; // usually as long as an int
// 		typedef std::random_access_iterator_tag		iterator_category;
// 		typedef iterator< const C >					const_iterator;



// 		iterator(): _it(){}
// 		iterator(pointer ptr): _it(ptr){}
// 		iterator(const iterator& newit): _it(newit._it){}
// 		~iterator(){}

// 		pointer base() const { return _it; }

// 		iterator operator=(const iterator& r) { _it = r.base(); return *this; };
// 		iterator& operator++() { _it += 1; return *this; }
// 		iterator operator++(int) { _it += 1; iterator tmp(*this); operator++(); return tmp; }
// 		iterator& operator--() { _it -= 1; return *this; }
// 		iterator operator--(int) { _it -= 1; iterator tmp(*this); operator--(); return tmp; }
// 		iterator& operator+=(ptr_diff tmp) {_it += tmp; return *this; }
// 		iterator& operator-=(ptr_diff tmp) {_it -= tmp; return *this; }
// 		iterator operator+(ptr_diff tmp) { return (base() + tmp); }
// 		iterator operator-(ptr_diff tmp) { return (base() - tmp); }

// 		reference			operator[](ptr_diff index) { return base()[index]; }
// 		const_reference		operator[](ptr_diff index) const { return base()[index]; }

// 		reference			operator*() { return *_it; }
// 		const_reference		operator*() const { return *_it; }
// 		pointer				operator->() { return &(*_it); }
// 		const_pointer		operator->() const { return &(*_it); }

// 		//bool				operator==()


// 	private:
// 		pointer	_it;







	
// };











// };








template<typename C, typename ValueType>
struct MyIterator {
	typedef C									value_type;
	typedef C*									pointer;
	typedef const C*							const_pointer;
	typedef C&									reference;
	typedef const C&							const_reference;
	typedef std::ptrdiff_t						difference_type; // usually as long as an int
	typedef std::random_access_iterator_tag		iterator_category;
	//typedef iterator< const C >					const_iterator;

	// using iterator_category = std::random_access_iterator_tag;  // specify the iterator category
	// using value_type = ValueType; 
	// using difference_type = std::ptrdiff_t;
	// using pointer = ValueType*;
	// using reference = ValueType&;

	
	MyIterator& operator++(){
		// implementation here
		return *this;
	}
	MyIterator& operator--(){
		// implementation here
		return *this;
	}
	ValueType& operator*(){
		// implementation here
		return *p;
	}
	ValueType* operator->(){
		// implementation here
		return p;
	}
	MyIterator& operator+=(difference_type n){
		(void)n;
		// implementation here
		return *this;
	}
	MyIterator& operator-=(difference_type n){
		(void)n;
		// implementation here
		return *this;
	}
	ValueType& operator[](difference_type n){
		(void)n;

		return *this;
	}
	private:
		pointer p;
};
































#endif

// template<typename IteratorCategory, typename T>
// struct MyIterator : public std::iterator<IteratorCategory, T>
// {
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

// using iterator = MyIterator<std::random_access_iterator_tag, T>;
// iterator begin() { return iterator(this, 0); }
// iterator end() { return iterator(this, size()); }

// template <typename T>
// class MyContainer {
//     public:
//         T getElement(int index) { /* ... */ }
//         int size() {/*...*/}

//         template <typename IteratorCategory>
//         struct iterator {
//             // constructor
//             iterator(MyContainer* container, int index) : m_container(container), m_index(index) {}

//             // overload the increment operator
//             iterator& operator++() {
//                 ++m_index;
//                 return *this;
//             }

//             // overload the dereference operator
//             T& operator*() {
//                 return m_container->getElement(m_index);
//             }

//             // overload the comparison operators
//             bool operator==(const iterator& other) {
//                 return m_index == other.m_index;
//             }
//             bool operator!=(const iterator& other) {
//                 return !(*this == other);
//             }
//             private:
//                 MyContainer* m_container;
//                 int m_index;
//         };

//         iterator<std::random_access_iterator_tag> begin() { return iterator<std::random_access_iterator_tag>(this, 0); }
//         iterator<std::random



// // iterator.h
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