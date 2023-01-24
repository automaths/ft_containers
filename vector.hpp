#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include <string.h>
#include "lexicographical_compare.hpp"
#include "equal.hpp"


namespace ft{

	template < class T , class Alloc = std::allocator<T> >
	class vector {

		public:

		typedef T												value_type;
		typedef std::allocator<T>								allocator_type;
		typedef value_type&										reference;
		typedef const value_type&								const_reference;
		typedef value_type*										pointer;
		typedef const value_type*								const_pointer;
		typedef ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef std::ptrdiff_t									difference_type;
		typedef size_t											size_type;

		explicit vector(): _capacity(0), _size(0), _data(NULL) {}
		explicit vector(size_type n, const value_type& val = value_type()): _capacity(0), _size(0), _data(NULL) {
			assign(n, val);
		}
		template <class InputIterator>
		vector (InputIterator first, InputIterator last): _capacity(0), _size(0), _data(NULL) {
			assign(first, last);
		}
		vector (const vector& x): _capacity(0), _size(0), _data(NULL) {
			assign(x.begin(), x.end());
		}
		~vector() {
			while (_size-- > 1)
				_allocator.destroy(_data + _size);
			if (_capacity > 0)
				_allocator.deallocate(_data, _capacity);
		}
		vector& operator=(vector const &x) {
			clear();
			if (this == &x)
				return (*this);
			assign(x.begin(), x.end());
			return *this;
		}
		iterator begin() {
			return iterator(_data);
		}
		const_iterator begin() const {
			return const_iterator(_data);
		}
		iterator end() {
			return iterator(_data + _size);
		}
		const_iterator end() const {
			return const_iterator(_data + _size);
		}
		reverse_iterator rbegin() {
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(end());
		}
		reverse_iterator rend() {
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend() const {
			return const_reverse_iterator(begin());
		}
		const_iterator cbegin() const {
			return const_iterator(_data);
		}
		const_iterator cend() const {
			return const_iterator(_data + _size);
		}
		const_reverse_iterator crbegin() const {
			return const_reverse_iterator(end());
		}
		const_reverse_iterator crend() const {
			return const_reverse_iterator(begin());
		}
		size_type size() const {
			return _size;
		}
		size_type max_size() const {
			return (_allocator.max_size());
		}
		void resize (size_type n, value_type val = value_type()) {
			reserve(n);
			while (_size < n)
				_allocator.construct(_data + _size++, val);
			while (_size > n)
				_allocator.destroy(_data + --_size);
		}
		size_type capacity() const {
			return _capacity;
		}
		bool empty() const {
			return (_size == 0);
		}
		void reserve (size_type n){
			if (_capacity < n)
				_reallocate(n);
		}
		void shrink_to_fit(){
			if (_capacity > _size)
			{
				_allocator.deallocate(_data + _size, _capacity - _size);
				_capacity = _size;
			}
		}
		reference operator[] (size_type n) {
			return (*(_data + n));
		}
		const_reference operator[] (size_type n) const {
			return (*(_data + n));
		}
		reference at (size_type n) {
			if (n >= _size)
				throw std::out_of_range("too far");
			return (*(_data + n));
		}
		const_reference at (size_type n) const {
			if (n >= _size)
				throw std::out_of_range("too far");
			return (*(_data + n));
		}
		reference front() {
			return *_data;
		}
		const_reference front() const {
			return *_data;
			}
		reference back(){
			if (_size == 0)
				return *_data;
			return *(_data + _size - 1);
		}
		const_reference back() const {
			if (_size == 0)
				return *_data;
			return *(_data + _size - 1);
		}
		value_type* data() {
			return *_data;
		}
		const value_type* data() const {
			return *_data;
		}
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			clear();
			size_type i = 0;
			for (InputIterator tmp = first; tmp != last; ++tmp)
				++i;
			reserve(i);
			for (size_type j = 0; j < i; j++)
				_allocator.construct(_data + j, *first++);
			_size = i;
			_capacity = i;
		}
		void assign (size_type n, const value_type& val){
			clear();
			reserve(n);
			for (size_type i = 0; i < n; i++)
				_allocator.construct(_data + i, val);
			_size = n;
			_capacity = n;
		}
		void push_back (const value_type& val){
			reserve(_size + 1);
			_allocator.construct(_data + _size, val);
			++_size;
		}
		void pop_back(){
			if (_size > 0)
				_allocator.destroy(_data + --_size);
		}
		iterator insert (iterator position, const value_type& val){
			size_t p = position - begin();
			reserve(_size + 1);
			++_size;
			for (size_t i = _size - 1; i > p; --i)
				_allocator.construct(_data + i, *(_data + i - 1));
			_allocator.construct(_data + p, val);
			position = begin();
			for (size_t i = 0; i < p; ++i)
				++position;
			return (position);
		}
    	void insert (iterator position, size_type n, const value_type& val){
			size_t p = position - begin();
			reserve(_size + n);
			_size += n;

			for (size_t i = _size - 1; i >= n; --i)
				_allocator.construct(_data + i, *(_data + i - n));
			while (n > 0)
				_allocator.construct(_data + p + n-- - 1, val);
		}
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
			size_type n = 0;
			if (!(first != last))
				n = 1;
			else
			{
				for (InputIterator tmp = first; tmp != last; ++tmp)
					++n;
			}
			size_type p = position - begin();
			reserve(_size + n);
			_size += n;
			size_type j = n;
			for (size_t i = _size - 1; i >= n + p; --i)
				_allocator.construct(_data + i, *(_data + i - n));
			j = 0;
			while (n > j)
				_allocator.construct(_data + p + j++, *first++);
		}
		iterator erase (iterator position){
			size_type p = position - begin();
			--_size;
			for (size_t i = p; i <= _size; ++i)
				_allocator.construct(_data + i, *(_data + i + 1));
			_allocator.destroy(_data + _size);
			return (position);
		}
		iterator erase (iterator first, iterator last){
			size_type n;
			if (first == last)
				n = 1;
			else
				n = last - first;
			size_type p = first - begin();
			_size -= n;
			for (size_t i = p; i <= _size; ++i)
				_allocator.construct(_data + i, *(_data + i + n));
			while (n > 0)
				_allocator.destroy(_data + _size - n--);
			return (first);
		}
		void swap (vector& x){
			size_type one = _size;
			size_type two = _capacity;
			pointer three = _data;
			allocator_type four = _allocator;
			_size = x._size;
			_capacity = x._capacity;
			_allocator = x._allocator;
			_data = x._data;
			x._size = one;
			x._capacity = two;
			x._data = three;
			x._allocator = four;
		}
		void clear(){
			if (_capacity > 0)
				_allocator.deallocate(_data, _capacity);
			_capacity = 0;
			_size = 0;
			_data = NULL;
		}
		allocator_type get_allocator() const {
			return _allocator;
		}

		private:
	
		size_type _capacity;
		size_type _size;
		pointer _data;
		allocator_type _allocator;

		void _reallocate(size_t n)
		{
			pointer _new;
			pointer tmp;
			tmp = _data;
			_new = _allocator.allocate(n * 5);
			for (size_t i = 0; i < _size; ++i)
				_allocator.construct(_new + i, *(_data + i));
			if (_capacity > 0)
				_allocator.deallocate(_data, _capacity);
			_capacity = n * 5;
			_data = _new;
		}
	};
	template <class T>
	bool operator==(const vector<T> &lhs, const vector<T> &rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <class T>
	bool operator!=(const vector<T> &lhs, const vector<T> &rhs) {
		return !(lhs == rhs);
	}
	template <class T>
	bool operator< (const vector<T> &lhs, const vector<T> &rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class T>
	bool operator<=(const vector<T> &lhs, const vector<T> &rhs) {
		return !(rhs < lhs);
	}
	template <class T>
	bool operator> (const vector<T> &lhs, const vector<T> &rhs) {
		return (rhs < lhs);
	}
	template <class T>
	bool operator>=(const vector<T> &lhs, const vector<T> &rhs) {
		return !(lhs < rhs);
	}
	template <class T>
	void swap(vector<T> &a, vector<T> &b) {
		a.swap(b);
	}
}
