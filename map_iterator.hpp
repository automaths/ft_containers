#pragma once

namespace ft {

	template <typename T, typename tree_node>
	class map_iterator {

		public:
			typedef T						value_type;
			typedef value_type&				reference;
			typedef value_type*				pointer;
			typedef std::ptrdiff_t			difference_type;

			operator map_iterator<const T, tree_node>() const {return map_iterator<const T, tree_node>(_node);}
			template <class, class, class> friend class map;
			template <class, class> friend class map_iterator;

			map_iterator() : _node(NULL) {}
			map_iterator(const map_iterator &other) {*this = other;}
			~map_iterator() {}
			map_iterator &operator=(map_iterator const &other) {
				if (this == &other)
					return (*this);
				_node = other._node;
				return (*this);
			}
			bool operator==(const map_iterator &other) const {
				return (_node == other._node);
			}
			bool operator!=(const map_iterator &other) const {
				return (_node != other._node);
			}
			map_iterator &operator++() {
				tree_node *previous = _node;
				if (_node->right)
					_node = goBegin(_node->right);
				else
				{
					_node = _node->parent;
					while (_node && previous == _node->right)
					{
						previous = _node;
						_node = _node->parent;
					}
				}
				return (*this);
			}
			map_iterator operator++(int) {
				map_iterator tmp(*this);
				++(*this);
				return (tmp);
			}
			map_iterator &operator--() {
				tree_node *previous = _node;
				if (_node->left != NULL)
					_node = goEnd(_node->left);
				else
				{
					_node = _node->parent;
					while (_node && previous == _node->left)
					{
						previous = _node;
						_node = _node->parent;
					}
				}
				return (*this);
			}
			map_iterator operator--(int) {
				map_iterator tmp(*this);
				--(*this);
				return (tmp);
			}
			reference operator*() const {
				return (_node->content);
			}
			pointer operator->() const {
				return &_node->content;
			}

			private:
			tree_node						*_node;
			map_iterator(tree_node *other) {_node = other;}
	};
}

