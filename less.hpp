#pragma once

#include <stdbool.h>

namespace ft{
	template <class Key> struct less {
		bool operator() (const Key& x, const Key& y) const {return x<y;}
	};
	template <class Key> struct more {
		bool operator() (const Key& x, const Key& y) const {return x>y;}
	};
}
