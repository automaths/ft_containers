#include "library.hpp"

void testing_map()
{
	std::cout << "\nLAUNCHING MAP ERROR CHECK:\nDefault Constructor, Range Constructor, Copy Constructor, Begin, End, Rbegin, Rend, Empty, Size, Access Operator, Insert, Erase, Swap, Clear, Key_comp, Value_comp, Allocator" << std::endl;

	{
		ft::map<int, char> test_type_one;
		ft::map<char, int> test_type_two;
		ft::map<bool, bool> test_type_three;
	}
	{
		ft::map<char, int> first;

		first['a'] = 24;
		first['b'] = 42;
		first['c'] = 240;
		first['d'] = 420;

		ft::map<char, int> second(first.begin(), first.end());
		if (second.size() != 4 || second.empty())
			std::cout << "Map -> Range Constructor: error 1" << std::endl;

		ft::map<char, int> third(second.begin(), second.end());
		if (third.size() != 4 || third.empty())
			std::cout << "Map -> Range Constructor: error 2" << std::endl;

		if (third.find('a')->second != 24)
			std::cout << "Map -> Range Constructor: error 3" << std::endl;

		if (third.find('b')->second != 42)
			std::cout << "Map -> Range Constructor: error 4" << std::endl;

		if (third.find('c')->second != 240)
			std::cout << "Map -> Range Constructor: error 5" << std::endl;

		if (third.find('d')->second != 420)
			std::cout << "Map -> Range Constructor: error 6" << std::endl;

		if (third['d'] != 420)
			std::cout << "Map -> Range Constructor: error 7" << std::endl;
	}
	{
		ft::map<char, int> first;

		first['a'] = 24;
		first['b'] = 42;
		first['c'] = 240;
		first['d'] = 420;

		ft::map<char, int> second(first);

		if (second.size() != 4 || second.empty())
			std::cout << "Map -> Copy Constructor: error 1" << std::endl;

		if (second.find('a')->second != 24)
			std::cout << "Map -> Copy Constructor: error 2" << std::endl;

		if (second.find('b')->second != 42)
			std::cout << "Map -> Copy Constructor: error 3" << std::endl;

		if (second.find('c')->second != 240)
			std::cout << "Map -> Copy Constructor: error 4" << std::endl;

		if (second.find('d')->second != 420)
			std::cout << "Map -> Copy Constructor: error 5" << std::endl;
	}
	{
		ft::map<char, int> first;
		ft::map<char, int> second;

		first['x'] = 24;
		first['y'] = 42;
		first['z'] = 240;

		second = first;
		if (second.size() != 3)
			std::cout << "Map -> Assignment Operator: error 1" << std::endl;

		first = ft::map<char, int>();
		if (first.size() != 0 || !first.empty())
			std::cout << "Map -> Assignment Operator: error 2" << std::endl;

		first = second;
		if (first.size() != 3 || first.size() != second.size() || first.empty())
			std::cout << "Map -> Assignment Operator: error 3" << std::endl;

		if (first['x'] != 24)
			std::cout << "Map -> Assignment Operator: error 4" << std::endl;

		if (first['z'] != second['z'])
			std::cout << "Map -> Assignment Operator: error 5" << std::endl;
	}
	{
		int myints[] = {24, 42, 240, 420, 2400};
		ft::map<int, int> the_ft_map;
		std::map<int, int> stdmap;

		for (int i = 0; i < 5; i++) {
			the_ft_map.insert(ft::make_pair<int, int>(i, myints[i]));
			stdmap.insert(std::pair<int, int>(i, myints[i]));
		}

		ft::map<int, int>::iterator it = the_ft_map.begin();
		std::map<int, int>::iterator it2 = stdmap.begin();
		for (; it != the_ft_map.end(); ++it, ++it2) {
			if (it->second != it2->second)
			std::cout << "Map -> Begin: error 1" << std::endl;
		}
	}
	{
		int myints[] = {24, 42, 240, 420, 2400};
		ft::map<int, int> the_ft_map;
		std::map<int, int> stdmap;

		for (int i = 0; i < 5; i++) {
			the_ft_map.insert(ft::make_pair<int, int>(i, myints[i]));
			stdmap.insert(std::pair<int, int>(i, myints[i]));
		}

		ft::map<int, int>::iterator it = the_ft_map.end();
		std::map<int, int>::iterator it2 = stdmap.end();

		--it;
		--it2;
		for (; it != the_ft_map.begin(); --it, --it2) {
			if (it->second != it2->second)
			std::cout << "Map -> End: error 1" << std::endl;
		}
	}
	{
		int myints[] = {24, 42, 240, 420, 2400};
		ft::map<int, int> the_ft_map;
		std::map<int, int> stdmap;

		for (int i = 0; i < 5; i++) {
			the_ft_map.insert(ft::make_pair<int, int>(i, myints[i]));
			stdmap.insert(std::pair<int, int>(i, myints[i]));
		}

		ft::map<int, int>::reverse_iterator it = the_ft_map.rbegin();
		std::map<int, int>::reverse_iterator it2 = stdmap.rbegin();
		for (; it != the_ft_map.rend(); ++it, ++it2) {
			if (it->second != it2->second)
			std::cout << "Map -> Rbegin: error 1" << std::endl;
		}
	}
	{
		int myints[] = {24, 42, 240, 420, 2400};
		ft::map<int, int> the_ft_map;
		std::map<int, int> stdmap;

		for (int i = 0; i < 5; i++) {
			the_ft_map.insert(ft::make_pair<int, int>(i, myints[i]));
			stdmap.insert(std::pair<int, int>(i, myints[i]));
		}

		ft::map<int, int>::reverse_iterator it = the_ft_map.rend();
		std::map<int, int>::reverse_iterator it2 = stdmap.rend();

		--it;
		--it2;
		for (; it != the_ft_map.rbegin(); --it, --it2) {
			if (it->second != it2->second)
			std::cout << "Map -> Rend: error 1" << std::endl;
		}
	}
	{
		ft::map<char, int> the_ft_map;

		if (!the_ft_map.empty())
			std::cout << "Map -> Empty: error 1" << std::endl;

		the_ft_map['a'] = 1;
		if (the_ft_map.empty())
			std::cout << "Map -> Empty: error 2" << std::endl;

		the_ft_map['b'] = 2;
		the_ft_map['c'] = 3;

		if (the_ft_map.empty())
			std::cout << "Map -> Empty: error 4" << std::endl;

		the_ft_map.erase('a');
		if (the_ft_map.empty())
			std::cout << "Map -> Empty: error 5" << std::endl;

		the_ft_map.erase('b');
		if (the_ft_map.empty())
			std::cout << "Map -> Empty: error 6" << std::endl;

		the_ft_map.erase('c');
		if (!the_ft_map.empty())
			std::cout << "Map -> Empty: error 7" << std::endl;
	}
	{
		ft::map<char, int> the_ft_map;

		if (the_ft_map.size() != 0)
			std::cout << "Map -> Size: error 1" << std::endl;

		the_ft_map['a'] = 1;
		if (the_ft_map.size() != 1)
			std::cout << "Map -> Size: error 2" << std::endl;

		the_ft_map['b'] = 2;
		if (the_ft_map.size() != 2)
			std::cout << "Map -> Size: error 3" << std::endl;

		the_ft_map.erase('a');
		if (the_ft_map.size() != 1)
			std::cout << "Map -> Size: error 4" << std::endl;

		the_ft_map.erase('b');
		if (the_ft_map.size() != 0)
			std::cout << "Map -> Size: error 5" << std::endl;

		the_ft_map['a'] = 1;
		the_ft_map['b'] = 2;
		the_ft_map['c'] = 3;
		if (the_ft_map.size() != 3)
			std::cout << "Map -> Size: error 6" << std::endl;
	}
	{
		ft::map<char, int> the_ft_map;

		the_ft_map['a'] = 1;
		the_ft_map['b'] = 2;
		the_ft_map['c'] = the_ft_map['b'];

		if (the_ft_map['a'] != 1)
			std::cout << "Map -> Access Operator: error 1" << std::endl;

		if (the_ft_map['b'] != 2)
			std::cout << "Map -> Access Operator: error 2" << std::endl;

		if (the_ft_map['c'] != the_ft_map['b'])
			std::cout << "Map -> Access Operator: error 3" << std::endl;
	}
	{
		ft::map<char, int> the_ft_map;

		the_ft_map.insert(ft::make_pair<char, int>('a', 100));
		the_ft_map.insert(ft::make_pair<char, int>('z', 200));

		ft::pair<ft::map<char, int>::iterator, bool> ret;
		ret = the_ft_map.insert(ft::make_pair<char, int>('z', 500));
		if (ret.second)
			std::cout << "Map -> Insert: error 1" << std::endl;

		ft::map<char, int>::iterator it = the_ft_map.begin();
		the_ft_map.insert(it, ft::make_pair<char, int>('b', 300));
		the_ft_map.insert(it, ft::make_pair<char, int>('c', 400));

		if (the_ft_map['a'] != 100)
			std::cout << "Map -> Insert: error 2" << std::endl;
		if (the_ft_map['b'] != 300)
			std::cout << "Map -> Insert: error 3" << std::endl;
		if (the_ft_map['c'] != 400)
			std::cout << "Map -> Insert: error 4" << std::endl;
		if (the_ft_map['z'] != 200)
			std::cout << "Map -> Insert: error 5" << std::endl;

		ft::map<char, int> anothermap;
		anothermap.insert(the_ft_map.begin(), the_ft_map.find('c'));

		if (the_ft_map.size() != 4)
			std::cout << "Map -> Insert: error 6" << std::endl;
		if (anothermap.size() != 2)
			std::cout << "Map -> Insert: error 7" << std::endl;

		if (the_ft_map['a'] != 100)
			std::cout << "Map -> Insert: error 8" << std::endl;
		if (the_ft_map['b'] != 300)
			std::cout << "Map -> Insert: error 9" << std::endl;
		if (the_ft_map['c'] != 400)
			std::cout << "Map -> Insert: error 10" << std::endl;
		if (the_ft_map['z'] != 200)
			std::cout << "Map -> Insert: error 11" << std::endl;

		if (anothermap['a'] != 100)
			std::cout << "Map -> Insert: error 12" << std::endl;
		if (anothermap['b'] != 300)
			std::cout << "Map -> Insert: error 43" << std::endl;
	}
	{
		ft::map<char, int> the_ft_map;
		ft::map<char, int>::iterator it;

		the_ft_map['a'] = 24;
		the_ft_map['b'] = 42;
		the_ft_map['c'] = 240;
		the_ft_map['d'] = 420;
		the_ft_map['e'] = 2400;
		the_ft_map['f'] = 4200;

		it = the_ft_map.find('b');
		the_ft_map.erase(it);
		if (the_ft_map.size() != 5)
			std::cout << "Map -> Erase: error 1" << std::endl;

		the_ft_map.erase('c');
		if (the_ft_map.size() != 4)
			std::cout << "Map -> Erase: error 2" << std::endl;

		it = the_ft_map.find('e');
		the_ft_map.erase(it, the_ft_map.end());

		if (the_ft_map.size() != 2)
			std::cout << "Map -> Erase: error 3" << std::endl;

		if (the_ft_map['a'] != 24)
			std::cout << "Map -> Erase: error 4" << std::endl;

		if (the_ft_map['d'] != 420)
			std::cout << "Map -> Erase: error 5" << std::endl;
	}
	{
		ft::map<char, int> foo, bar;

		foo['d'] = 420;
		foo['e'] = 2400;

		bar['a'] = 24;
		bar['b'] = 42;
		bar['c'] = 240;

		foo.swap(bar);

		if (foo.size() != 3)
			std::cout << "Map -> Swap: error 1" << std::endl;

		if (bar.size() != 2)
			std::cout << "Map -> Swap: error 2" << std::endl;

		if (foo['a'] != 24)
			std::cout << "Map -> Swap: error 3" << std::endl;

		if (foo['b'] != 42)
			std::cout << "Map -> Swap: error 4" << std::endl;

		if (foo['c'] != 240)
			std::cout << "Map -> Swap: error 5" << std::endl;

		if (bar['d'] != 420)
			std::cout << "Map -> Swap: error 6" << std::endl;

		if (bar['e'] != 2400)
			std::cout << "Map -> Swap: error 7" << std::endl;
	}
	{
		ft::map<char, int> the_ft_map;

		the_ft_map['d'] = 24;
		the_ft_map['e'] = 42;
		the_ft_map['f'] = 240;

		if (the_ft_map.size() != 3)
			std::cout << "Map -> Clear: error 1" << std::endl;

		the_ft_map.clear();

		if (the_ft_map.size() != 0)
			std::cout << "Map -> Clear: error 2" << std::endl;

		the_ft_map['a'] = 420;
		the_ft_map['b'] = 2400;

		if (the_ft_map.size() != 2)
			std::cout << "Map -> Clear: error 3" << std::endl;

		if (the_ft_map['a'] != 420)
			std::cout << "Map -> Clear: error 4" << std::endl;
		if (the_ft_map['b'] != 2400)
			std::cout << "Map -> Clear: error 5" << std::endl;
	}
	{
		ft::map<char, int> the_ft_map;
		ft::map<char, int>::key_compare mycomp = the_ft_map.key_comp();

		if (mycomp('a', 'b') != true)
			std::cout << "Map -> Key_comp: error 1" << std::endl;

		if (mycomp('b', 'a') != false)
			std::cout << "Map -> Key_comp: error 2" << std::endl;

		if (mycomp('a', 'a') != false)
			std::cout << "Map -> Key_comp: error 3" << std::endl;

		if (mycomp('b', 'b') != false)
			std::cout << "Map -> Key_comp: error 4" << std::endl;

		the_ft_map['a'] = 24;
		the_ft_map['b'] = 42;
		the_ft_map['c'] = 240;

		char highest = the_ft_map.rbegin()->first;

		if (mycomp(highest, 'c') != 0)
			std::cout << "Map -> Key_comp: error 5" << std::endl;

		if (mycomp('c', highest) != 0)
			std::cout << "Map -> Key_comp: error 6" << std::endl;

		if (mycomp('c', 'b') > 0)
			std::cout << "Map -> Key_comp: error 7" << std::endl;
	}
	{
		ft::map<char, int> the_ft_map;

		the_ft_map['x'] = 1001;
		the_ft_map['y'] = 2002;
		the_ft_map['z'] = 3003;

		ft::pair<char, int> highest = *the_ft_map.rbegin();
		ft::map<char, int>::iterator it = the_ft_map.begin();
		for (int i = 1; the_ft_map.value_comp()(*it, highest); i++) {
			if (it->second != i * 1001)
			std::cout << "Map -> Value_comp: error 1" << std::endl;
			++it;
		}
	}
	{
		ft::map<char, int> the_ft_map;
		ft::map<char, int>::iterator it;

		the_ft_map['a'] = 24;
		the_ft_map['b'] = 42;
		the_ft_map['c'] = 240;
		the_ft_map['d'] = 420;

		it = the_ft_map.find('b');
		if (it != the_ft_map.end())
			the_ft_map.erase(it);

		if (the_ft_map.size() != 3)
			std::cout << "Map -> Find: error 1" << std::endl;

		if (the_ft_map['a'] != 24)
			std::cout << "Map -> Find: error 2" << std::endl;

		if (the_ft_map['c'] != 240)
			std::cout << "Map -> Find: error 3" << std::endl;

		if (the_ft_map['d'] != 420)
			std::cout << "Map -> Find: error 4" << std::endl;
	}

	std::cout << "If no error message is displayed, everything is ok" << std::endl;
}
