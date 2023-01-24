#pragma once

#include <limits>
#include "enable_if.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"
#include "node.hpp"
#include "pair.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key> >
	class map {

		public:

		class														value_compare;
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef pair<const key_type, mapped_type>					value_type;
		typedef Compare												key_compare;
		typedef std::allocator<pair<const Key,T> >					allocator_type;
		typedef ft::node<value_type>								tree_node;
		typedef tree_node*											tree_node_pointer;
		typedef ft::map_iterator<value_type, tree_node>				iterator;
		typedef ft::map_iterator<const value_type, tree_node>		const_iterator;
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef size_t												size_type;
		typedef std::ptrdiff_t										difference_type;

		explicit map(): _content(new tree_node), _size(0) {}
		template <class InputIterator>
		map(InputIterator first, InputIterator last): _content(new tree_node), _size(0) {
			insert(first, last);
		}
		map(const map &other): _content(new tree_node), _size(0) {
			*this = other;
		}
		~map() {
			clear();
			delete _content;
		}
		map	&operator=(map const &other) {
			if (this == &other)
				return *this;
			clear();
			insert(other.begin(), other.end());
			return *this;
		}
		iterator begin() {
			return iterator(goBegin(_content));
		}
		const_iterator begin() const {
			return const_iterator(goBegin(_content));
		}
		iterator end()  {
			return iterator(goEnd(_content));
		}
		const_iterator end() const {
			return const_iterator(goEnd(_content));
		}
		reverse_iterator rbegin() {
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin() const  {
			return const_reverse_iterator(end());
		}
		reverse_iterator rend()  {
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend() const{
			return const_reverse_iterator(begin());
		}
		size_type size() const {
			return _size;
		}
		size_type max_size() const{
			return _allocator.max_size();
		}
		bool empty() const {
			return (_size == 0);
		}
		mapped_type	&operator[](const key_type &key){
			return (insert(value_type(key, mapped_type()))).first->second;
		}
		ft::pair<iterator, bool> insert(const value_type &val) {
			ft::pair<iterator, bool> pr;
			if (!count(val.first))
			{
				pr.second = true;
				add_node(new tree_node(val));
			}
			pr.first = find(val.first);
			return pr;
		}
		iterator insert(iterator position, const value_type &val) {
			(void)position;
			return insert(val).first;
		}
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last) {
			while (first != last)
				insert(*first++);
		}
		void erase(iterator position) {
			remove_node(position._node);
		}
		size_type erase(const key_type &key) {
			iterator it = find(key);
			if (it == end())
				return 0;
			remove_node(it._node);
			return 1;
		}
		void erase(iterator first, iterator last) {
			while (first != last)
				remove_node((first++)._node);
		}
		void swap(map &x) {
			map tmp;
			tree_node_pointer ptr = tmp._content;
			tmp._content = x._content;
			tmp._size = x._size;
			x._content = ptr;
			x._size = 0;
			x.clear();
			ptr = x._content;
			x._content = _content;
			x._size = _size;
			_content = ptr;
			_size = 0;			
			clear();
			ptr = _content;
			_content = tmp._content;
			_size = tmp._size;
			tmp._content = ptr;
			tmp._size = 0;
			ptr = NULL;
		}
		void clear() {
			if (_size == 0)
				return ;
			tree_node_pointer tmp = end()._node;
			tmp->parent->right = NULL;
			clear_tree(_content);
			_content = tmp;
			_size = 0;
		}
		key_compare	 key_comp() const {
			return (key_compare());
		}
		value_compare value_comp() const  {
			return (value_compare(key_compare()));
		}
		iterator find(const key_type &k) {
			for (iterator tmp = begin(); tmp != end(); ++tmp)
			{
				if (tmp->first == k)
					return tmp;
			}
			return end();
		}
		const_iterator find(const key_type &k) const {
			for (const_iterator tmp = begin(); tmp != end(); ++tmp)
			{
				if (tmp->first == k)
					return tmp;
			}
			return end();
		}
		size_type count(const key_type &k) const {
			const_iterator	it = begin();
			const_iterator ite = end();
			for (const_iterator tmp = begin(); tmp != end(); ++tmp)
			{
				if (tmp->first == k)
					return 1;
			}
			return 0;
		}
		iterator lower_bound(const key_type &k) {
			for (iterator tmp = begin(); tmp != end(); ++tmp)
			{
				if (!_cmp(tmp->first, k))
					return (tmp);
			}
			return end();
		}
		const_iterator lower_bound(const key_type &k) const {
			for (const_iterator tmp = begin(); tmp != end(); ++tmp)
			{
				if (!_cmp(tmp->first, k))
					return tmp;
			}
			return end();
		}
		iterator upper_bound(const key_type &k) {
			for (iterator tmp = begin(); tmp != end(); ++tmp)
			{
				if (_cmp(k, tmp->first))
					return tmp;
			}
			return end();
		}
		const_iterator upper_bound(const key_type &k) const {
			for (const_iterator tmp = begin(); tmp != end(); ++tmp)
			{
				if (_cmp(k, tmp->first))
					return tmp;
			}
			return end();
		}
		pair<const_iterator,const_iterator>	equal_range(const key_type &k) const {
			return (pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
		}
		pair<iterator,iterator>	 equal_range(const key_type &k) {
			return (pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		}

		private:

		void clear_tree(tree_node_pointer node) {
				if (!node)
					return ;
				clear_tree(node->left);
				clear_tree(node->right);
				delete node;
		}
		void add_node(tree_node_pointer node_ptr) {
			tree_node_pointer	*parent = &_content;
			tree_node_pointer	*node = &_content;
			tree_node_pointer	end = goEnd(_content);
			++_size;
			while (*node && *node != end)
			{
				parent = node;
				if (_cmp(node_ptr->content.first, (*node)->content.first))
					node = &(*node)->left;
				else
					node = &(*node)->right;
			}
			if (*node == NULL)
			{
				node_ptr->parent = (*parent);
				*node = node_ptr;
			}
			else
			{
				*node = node_ptr;
				node_ptr->parent = end->parent;
				end->parent = goEnd(node_ptr);
				goEnd(node_ptr)->right = end;
			}
		}
		void remove_node(tree_node_pointer node_ptr) {
			tree_node_pointer	new_node_ptr = NULL;
			tree_node_pointer	*node_adr = &_content;
			if (node_ptr->parent)
				node_adr = (node_ptr->parent->left == node_ptr ? &node_ptr->parent->left : &node_ptr->parent->right);
			if (node_ptr->left == NULL && node_ptr->right == NULL)
				;
			else if (node_ptr->left == NULL)
				new_node_ptr = node_ptr->right;
			else
			{
				new_node_ptr = goEnd(node_ptr->left);
				if (new_node_ptr != node_ptr->left)
					if ((new_node_ptr->parent->right = new_node_ptr->left))
						new_node_ptr->left->parent = new_node_ptr->parent;
			}
			if (new_node_ptr)
			{
				new_node_ptr->parent = node_ptr->parent;
				if (node_ptr->left && node_ptr->left != new_node_ptr)
				{
					new_node_ptr->left = node_ptr->left;
					new_node_ptr->left->parent = new_node_ptr;
				}
				if (node_ptr->right && node_ptr->right != new_node_ptr)
				{
					new_node_ptr->right = node_ptr->right;
					new_node_ptr->right->parent = new_node_ptr;
				}
			}
			*node_adr = new_node_ptr;
			--_size;
			delete node_ptr;
		}

		tree_node_pointer	_content;
		key_compare			_cmp;
		allocator_type		_allocator;
		size_type			_size;
	};

	template <class Key, class T, class Compare>
	bool operator==(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs) {
		if (lhs.size() != rhs.size())
			return 0;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <class Key, class T, class Compare>
	bool operator!=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs) {
		return !(lhs == rhs);
	}
	template <class Key, class T, class Compare>
	bool operator< (const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class Key, class T, class Compare>
	bool operator<=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs) {
		return !(rhs < lhs);
	}
	template <class Key, class T, class Compare>
	bool operator>(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs) {
		return (rhs < lhs);
	}
	template <class Key, class T, class Compare>
	bool operator>=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs) {
		return !(lhs < rhs);
	}
	template <class Key, class T, class Compare>
	void swap(map<Key, T, Compare> &a, map<Key, T, Compare> &b) {
		a.swap(b);
	}
	template <class Key, class T, class Compare>
	class map<Key, T, Compare>::value_compare {
		public:
		Compare comp;
		value_compare(Compare x): comp(x){};

		bool	operator()(const value_type &a, const value_type &b) const {
			return comp(a.first, b.first);
		}
	};
}
