#pragma once

#include <deque>
namespace ft {
	template <class T, class Container = std::deque<T> >
	class stack {
		public:
		
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

		explicit stack (const container_type& ctnr = container_type()): _cont(ctnr) {}
		bool empty() const {
			return _cont.empty();
		}
		size_type size() const {
			return _cont.size();
		}
		value_type& top() {
			return _cont.back();
		}
		const value_type& top() const {
			return _cont.back();
		}
		void push (const value_type& val) {
			_cont.push_back(val);
		}
		void pop() {
			_cont.pop_back();
		}
		void swap (stack& x) {
			_cont.swap(x._cont);
		}
		Container _cont;
	};
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont == rhs._cont);
	}
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont != rhs._cont);
	}
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont < rhs._cont);
	}
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont <= rhs._cont);
	}
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont > rhs._cont);
	}
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont >= rhs._cont);
	}
}

