#pragma once 

namespace ft {

	template <class T>
	struct node
	{
		public:
		T			content;
		node		*parent;
		node		*left;
		node		*right;

		node(const T &src = T()) : content(src), parent(NULL), left(NULL), right(NULL) {};
	};
	template <class T>
	node<T>	*goEnd(node<T> *node) {
		while (node->right)
			node = node->right;
		return node;
	}
	template <class T>
	node<T>	*goBegin(node<T> *node) {
		while (node->left)
			node = node->left;
		return node;
	}
}