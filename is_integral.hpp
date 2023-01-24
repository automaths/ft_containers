#pragma once

namespace ft {

	template <class T>
	struct is_integral {
		static const bool value = 0;
	};
	template<>
	struct is_integral<int> {
		static const bool value = 1;
	};
	template<>
	struct is_integral<long int> {
		static const bool value = 1;
	};
	template<>
	struct is_integral<long long int> {
		static const bool value = 1;
	};
	template<>
	struct is_integral<unsigned char> {
		static const bool value = 1;
	};
	template<>
	struct is_integral<unsigned short int> {
		static const bool value = 1;
	};
	template<>
	struct is_integral<unsigned int> {
		static const bool value = 1;
	};
	template<>
	struct is_integral<unsigned long int> {
		static const bool value = 1;
	};
	template<>
	struct is_integral<unsigned long long int> {
		static const bool value = 1;
	};
	template<>
	struct is_integral<char> {
		static const bool value = 1;
	};
	template<>
	struct is_integral<wchar_t> {
		static const bool value = 1;
	};
	template<>
	struct is_integral<signed char> {
		static const bool value = 1;
	};
	template<>
	struct is_integral<bool> {
		static const bool value = 1;
	};
	template<>
	struct is_integral<short int> {
		static const bool value = 1;
	};
} 