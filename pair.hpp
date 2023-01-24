#pragma once

namespace ft {
	template <class T1, class T2>
	struct	pair
	{
		typedef T1		first_type;
		typedef T2		second_type;
		first_type		first;
		second_type		second;

		pair() : first(), second() { };
		template<class U, class V>
		pair(const pair<U, V> &other) : first(other.first), second(other.second) { };
		pair(const first_type &a, const second_type &b) : first(a), second(b) { };
		pair	&operator=(const pair &other) {
			if (this == &other)
				return (*this);
			first = other.first;
			second = other.second;
			return (*this);
		}
	};
	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &one, const pair<T1, T2> &two) {
		return (one.first == two.first && one.second == two.second);
	}
	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &one, const pair<T1, T2> &two) {
		return !(one == two);
	}
	template <class T1, class T2>
	bool operator< (const pair<T1, T2> &one, const pair<T1, T2> &two) {
		return one.first < two.first || (!(two.first < one.first) && one.second < two.second);
	}
	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &one, const pair<T1, T2> &two) {
		return !(two < one);
	}
	template <class T1, class T2>
	bool operator> (const pair<T1, T2> &one, const pair<T1, T2> &two) {
		return (two < one);
	}
	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &one, const pair<T1, T2> &two) {
		return !(one < two);
	}
	template <class T1, class T2>
	pair<T1, T2>	make_pair(T1 x, T2 y) {
		return pair<T1, T2>(x, y);
	}
	template <typename T1, typename T2>
	std::ostream	&operator<<(std::ostream &stream, pair<T1, T2> const &one) {
		stream << one.first << "(" << one.second << ")";
		return stream;
	}
}