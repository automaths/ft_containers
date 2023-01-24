#pragma once

#include <iostream>
#include <memory>
#include <stdbool.h>
#include "iterator_traits.hpp"

namespace ft{
	template <class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	class random_access_iterator{

		public:

		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;
		typedef std::ptrdiff_t						difference_type;
	
		random_access_iterator(): _ptr(NULL) {}
		random_access_iterator(pointer ptr): _ptr(ptr) {}
		random_access_iterator(random_access_iterator const &other): _ptr(other._ptr) {}
		~random_access_iterator(){}
		random_access_iterator& operator=(random_access_iterator const &other) {
			if (this == &other)
				return (*this);
			this->_ptr = other._ptr;
				return (*this);
		}
		reference operator*() { 
			return *_ptr;
		}
		pointer operator->() {
			return &this->operator*();
		}
		operator random_access_iterator<T const>() const {
			return random_access_iterator<T const>(_ptr);
		}
		operator random_access_iterator<T>() {
			return random_access_iterator<T>(_ptr);
		}
		random_access_iterator& operator++(){
			_ptr++; return *this;
		}
		random_access_iterator operator++(int){
			random_access_iterator tmp(_ptr); _ptr++; return tmp;
		}
		random_access_iterator& operator--(){
			--_ptr; return *this;
		}
		random_access_iterator operator--(int){
			random_access_iterator tmp(*this); --_ptr; return tmp;
		}
		random_access_iterator operator+(difference_type n) const {
			return random_access_iterator(_ptr + n);
		}
		random_access_iterator operator-(difference_type n) const {
			return random_access_iterator(_ptr - n);
		}
		difference_type operator+(random_access_iterator const &other) const {
			return (_ptr + other._ptr);
		}
		difference_type operator-(random_access_iterator const &other) const {
			return (_ptr - other._ptr);
		}
		random_access_iterator operator+=(int n){
			_ptr = _ptr + n; return *this;
		}
		random_access_iterator operator-=(int n){
			_ptr = _ptr - n; return *this;
		}
		friend bool operator==(random_access_iterator const &one, random_access_iterator const &two) {
			return (one._ptr == two._ptr);
		}
		friend bool operator!=(random_access_iterator const &one, random_access_iterator const &two) {
			return (one._ptr != two._ptr);
		}
		friend bool operator<(random_access_iterator const &one, random_access_iterator const &two) {
			return (one._ptr < two._ptr);
		}
		friend bool operator<=(random_access_iterator const &one, random_access_iterator const &two) {
			return (one._ptr <= two._ptr);
		}
		friend bool operator>(random_access_iterator const &one, random_access_iterator const &two) {
			return (one._ptr > two._ptr);
		}
		friend bool operator>=(random_access_iterator const &one, random_access_iterator const &two) {
			return (one._ptr >= two._ptr);
		}
		reference operator[](int n){
			return (*(_ptr + n));
		}

		pointer _ptr;
		protected:
	};

	template <class T>
	random_access_iterator<T> operator+(int i, random_access_iterator<T> const &other) {
		return random_access_iterator<T>(other._ptr + i);
	}
	template <class T>
	random_access_iterator<T> operator-(int i, random_access_iterator<T> const &other) {
		return random_access_iterator<T>(other._ptr - i);
	}

}