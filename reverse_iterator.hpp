#pragma once

#include <iostream>
#include <memory>
#include <stdbool.h>
#include "iterator_traits.hpp"
#include "node.hpp"
#include "map_iterator.hpp"
#include "random_access_iterator.hpp"

namespace ft{

	template <class iterator>
	class reverse_iterator {

		public:

			typedef typename ft::iterator_traits<iterator>::value_type value_type;
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef typename ft::iterator_traits<iterator>::pointer pointer;
			typedef typename ft::iterator_traits<iterator>::reference reference;

			reverse_iterator() : _ptr(iterator()) {}
			explicit reverse_iterator(iterator it) : _ptr(it) {}
			explicit reverse_iterator(pointer ptr) : _ptr(ptr) {}
			template <class iit> reverse_iterator(const reverse_iterator<iit> &other) {
				_ptr = other.base();
			}
			reverse_iterator &operator=(const reverse_iterator &other){
				if (reinterpret_cast<const void *>(this) == reinterpret_cast<const void *>(&other))
					return (*this);
				_ptr = other.base();
				return (*this);
			}
			~reverse_iterator() {}
			iterator base() const {
				return _ptr;
			}
			reference operator*() const {
				iterator tmp = _ptr;
				return *(--tmp);
			}
			pointer operator->() const {
				return &(operator*());
			}
			reverse_iterator& operator++() {
				--_ptr;
				return *this;
			}
			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this;
				++(*this);
				return tmp;
			}
			reverse_iterator& operator--() {
				++_ptr;
				return *this;
			}
			reverse_iterator operator--(int) {
				reverse_iterator tmp = *this;
				++_ptr;
				return tmp;
			}
			reverse_iterator operator+(difference_type n) const {
				return reverse_iterator(_ptr - n);
			}
			reverse_iterator operator-(difference_type n) const {
				return reverse_iterator(_ptr + n);
			}
			reverse_iterator &operator+=(difference_type n) {
				_ptr -= n;
				return *this;
			}
			reverse_iterator &operator-=(difference_type n) {
				_ptr += n;
				return *this;
			}
			reference	operator[](difference_type n) const {
				return base()[-n-1];
			}
			template <class it>
			difference_type	operator-(const reverse_iterator<it> &other) const {
				return (other._ptr._ptr - _ptr._ptr);
			}
			friend reverse_iterator	operator+(difference_type n, const reverse_iterator &other) {
				return other.operator+(n);
			}
			template <class it>
			bool operator==(const reverse_iterator<it> &other) const {
				return (_ptr == other._ptr);
			}
			template <class it>
			bool operator!=(const reverse_iterator<it> &other) const {
				return (_ptr != other._ptr);
			}
			template <class it>
			bool operator<(const reverse_iterator<it> &other) const {
				return (_ptr > other._ptr);
			}
			template <class it>
			bool operator<=(const reverse_iterator<it> &other) const {
				return (_ptr >= other._ptr);
			}
			template <class it>
			bool operator>(const reverse_iterator<it> &other) const {
				return (_ptr < other._ptr);
			}
			template <class it>
			bool operator>=(const reverse_iterator<it> &other) const {
				return (_ptr <= other._ptr);
			}
			iterator _ptr;
			private:
	};
}