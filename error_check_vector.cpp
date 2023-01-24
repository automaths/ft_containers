#include "library.hpp"

void testing_vector()
{
	std::cout << "\nLAUNCHING VECTOR ERROR CHECK:\nDefault Constructor, Fill Constructor, Range Constructor, Copy Constructor, Copy Assignment Operator, Begin, End, Rbegin, Rend, Size, Max_size, Resize, Empty, Reserve, Access Operator, At, Front, Assign, Pop_back, Swap, Clear, Allocator, Relational Operator, Non member Swap" << std::endl;
	{
		ft::vector<int>		i;
		std::vector<int>	i_og;
		if (i.size() != 0 || i.capacity() != 0)
			std::cout << "Vector -> Default constructor: error 1" << std::endl;
		if (i_og.size() != i.size() || i_og.capacity() != i.capacity())
			std::cout << "Vector -> Default constructor: error 2" << std::endl;
	}
	{
		ft::vector<int> i(10);
		std::vector<int> i_og(10);
		if (i.size() != i_og.size() || i.capacity() != i_og.capacity())
			std::cout << "Vector -> Fill constructor: error 1" << std::endl;

		ft::vector<int> i1(42, 42);
		std::vector<int> i1_og(42, 42);
		if (i1.size() != i1_og.size() || i1.capacity() != i1_og.capacity())
			std::cout << "Vector -> Fill constructor: error 2" << std::endl;
		for (size_t i = 0; i < i1.size(); i++)
			if (i1[i] != i1_og[i])
				std::cout << "Vector -> Fill constructor: error 3" << std::endl;

		ft::vector<int> i2(24, 42);
		std::vector<int> i2_og(24, 42);
		if (i2.size() != i2_og.size() || i2.capacity() != i2_og.capacity())
			std::cout << "Vector -> Fill constructor: error 4" << std::endl;
		for (size_t i = 0; i < i2.size(); i++)
			if (i2[i] != i2_og[i])
				std::cout << "Vector -> Fill constructor: error 5" << std::endl;
	}
	{
		ft::vector<int> ref(10, 42);
		std::vector<int> ref_og(10, 42);

		ft::vector<int> v(ref.begin(), ref.end());
		std::vector<int> v_og(ref_og.begin(), ref_og.end());
		if (v.size() != v_og.size() || v.capacity() != v_og.capacity())
			std::cout << "Vector -> Range constructor: error 1" << std::endl;
		for (size_t i = 0; i < v.size(); i++)
			if (v[i] != v_og[i])
				std::cout << "Vector -> Range constructor: error 2" << std::endl;
	}
	{
		ft::vector<int> ref(10, 42);
		std::vector<int> ref_og(10, 42);

		ft::vector<int> v(ref);
		std::vector<int> v_og(ref_og);

		if (v.size() != v_og.size() || v.size() != ref.size()
			|| v.capacity() != v_og.capacity() || v.capacity() != ref.capacity())
			std::cout << "Vector -> Copy constructor: error 1" << std::endl;
		for (size_t i = 0; i < v.size(); i++)
			if (v[i] != v_og[i])
				std::cout << "Vector -> Copy constructor: error 2" << std::endl;
	}
	// {
	// 	ft::vector<int> *v = new ft::vector<int>(42, 42);
	// 	delete v;
	// }
	{
		ft::vector<int> ref(10, 42);
		std::vector<int> ref_og(10, 42);

		ft::vector<int> v = ref;
		std::vector<int> v_og = ref_og;

		if (v.size() != v_og.size() || v.capacity() != v_og.capacity())
			std::cout << "Vector -> Copy assignment operator: error 1" << std::endl;

		for (size_t i = 0; i < v.size(); i++)
			if (v[i] != v_og[i])
			std::cout << "Vector -> Copy assignment operator: error 2" << std::endl;
	}
	{
		ft::vector<int> v;
		std::vector<int> v_og;

		for (int i = 1; i <= 5; i++) {
			v.push_back(i);
			v_og.push_back(i);
		}

		ft::vector<int> store_v;
		std::vector<int> store_v_og;

		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			store_v.push_back(*it);
		for (std::vector<int>::iterator it = v_og.begin(); it != v_og.end(); it++)
			store_v_og.push_back(*it);

		for (int i = 0; i < 5; i++) {
			if (store_v[i] != store_v_og[i])
				std::cout << "Vector -> Begin: error 1" << std::endl;
		}

		ft::vector<int> store_v2;
		for (ft::vector<int>::const_iterator it = v.begin(); it 	!= v.end(); it++)
			store_v2.push_back(*it);
		for (int i = 0; i < 5; i++) {
			if (store_v[i] != store_v_og[i])
				std::cout << "Vector -> Begin: error 2" << std::endl;
		}
	}
	{
		ft::vector<int> v;
		std::vector<int> v_og;

		for (int i = 0; i < 5; i++) {
			v.push_back(i);
			v_og.push_back(i);
		}

		ft::vector<int> store_v;
		std::vector<int> store_v_og;

		for (ft::vector<int>::const_iterator it = v.end();
			it != v.begin(); it--)
			store_v.push_back(*it);
		for (std::vector<int>::const_iterator it = v_og.end();
			it != v_og.begin(); it--)
			store_v_og.push_back(*it);

		if (store_v.size() != store_v_og.size())
			std::cout << "Vector -> End: error 1" << std::endl;

		for (unsigned i = 1; i < store_v_og.size(); i++) {
			if (store_v[i] != store_v_og[i])
				std::cout << "Vector -> End: error 2" << std::endl;
		}
	}
	{
		ft::vector<int> v(5);
		std::vector<int> v_og(5);

		ft::vector<int>::reverse_iterator it = v.rbegin();
		std::vector<int>::reverse_iterator it_og = v_og.rbegin();
		for (int i = 0; it != v.rend(); ++it)
			*it = ++i;
		for (int i = 0; it_og != v_og.rend(); ++it_og)
			*it_og = ++i;

		for (int i = 0; i < 5; i++)
			if (v[i] != v_og[i])
			std::cout << "Vector -> Rbegin: error 1" << std::endl;

		int i = 1;
		for (ft::vector<int>::const_reverse_iterator it = v.rbegin();
			it != v.rend(); it++)
			if (*it != i++)
			std::cout << "Vector -> Rbegin: error 2" << std::endl;
	}
	{
		ft::vector<int> v(10, 42);
		std::vector<int> v_og(10, 42);

		ft::vector<int> v1;
		std::vector<int> v1_og;

		if (v.size() != v_og.size())
			std::cout << "Vector -> Size: error 1" << std::endl;
		if (v1.size() != v1_og.size())
			std::cout << "Vector -> Size: error 2" << std::endl;
	}
	{
		ft::vector<int> v(10, 42);
		std::vector<int> v_og(10, 42);

		ft::vector<int> v1;
		std::vector<int> v1_og;

		if (v.max_size() != v_og.max_size())
			std::cout << "Vector -> Max_size: error 1" << std::endl;
		if (v1.max_size() != v1_og.max_size())
			std::cout << "Vector -> Max_size: error 2" << std::endl;
	}
	{
		ft::vector<int> v(10, 5);
		std::vector<int> v_og(10, 5);

		v.resize(5);
		v_og.resize(5);
		if (v.size() != v_og.size())
			std::cout << "Vector -> Resize: error 1" << std::endl;

		v.resize(24);
		v_og.resize(24);
		if (v.size() != v_og.size())
			std::cout << "Vector -> Resize: error 2" << std::endl;

		ft::vector<int> v1(24, 24);
		std::vector<int> v_og1(24, 24);

		v1.resize(23);
		v_og1.resize(23);

		if (v1.size() != v_og1.size())
			std::cout << "Vector -> Resize: error 3" << std::endl;

		v1.resize(22);
		v_og1.resize(22);

		if (v1.size() != v_og1.size())
			std::cout << "Vector -> Resize: error 4" << std::endl;

		v1.resize(420);
		v_og1.resize(420);

		if (v1.size() != v_og1.size())
			std::cout << "Vector -> Resize: error 5" << std::endl;
	}
	{
		ft::vector<int> v(10, 42);
		std::vector<int> v_og(10, 42);

		ft::vector<int> v1;
		std::vector<int> v1_og;

		if (v.empty() != v_og.empty())
			std::cout << "Vector -> Empty: error 5" << std::endl;
		if (v1.empty() != v1_og.empty())
			std::cout << "Vector -> Empty: error 6" << std::endl;
	}
	{
		ft::vector<int> v;
		std::vector<int> v_og;

		if (v.capacity() < 0)
			std::cout << "Vector -> Reserve: error 1" << std::endl;

		v.reserve(10);;
		if (v.capacity() < 10)
			std::cout << "Vector -> Reserve: error 2" << std::endl;

		v.reserve(42);
		if (v.capacity() < 42)
			std::cout << "Vector -> Reserve: error 3" << std::endl;

		ft::vector<int> v1(10, 42);

		if (v1.capacity() < 10)
			std::cout << "Vector -> Reserve: error 4" << std::endl;

		v1.reserve(10);
		if (v1.capacity() < 10)
			std::cout << "Vector -> Reserve: error 5" << std::endl;

		v1.reserve(42);
		if (v1.capacity() < 42)
			std::cout << "Vector -> Reserve: error 6" << std::endl;
	}
	{
		ft::vector<int> v(10, 42);
		std::vector<int> v_og(10, 42);

		for (size_t i = 0; i < v.size(); i++)
			if (v[i] != v_og[i])
			std::cout << "Vector -> Access Operator: error 1" << std::endl;

		ft::vector<int> v1(10);
		ft::vector<int>::size_type sz = v1.size();
		for (size_t i = 0; i < sz; i++)
			v1[i] = i;
		for (size_t i = 0; i < sz / 2; i++) {
			int tmp = v1[sz-1-i];
			v1[sz-1-i] = v1[i];
			v1[i] = tmp;
		}
		for (size_t i = 0; i < sz; i++)
			if (v1[i] != 10 - static_cast<int>(i) - 1)
			std::cout << "Vector -> Access Operator: error 2" << std::endl;
	}
	{
		ft::vector<int> v(10);
		std::vector<int> v_og(10);

		for (size_t i = 0; i < v.size(); i++)
			v.at(i) = i;
		for (size_t i = 0; i < v_og.size(); i++)
			v_og.at(i) = i;

		for (size_t i = 0; i < v.size(); i++)
			if (v.at(i) != v_og.at(i))
			std::cout << "Vector -> At: error 1" << std::endl;
	}
	{
		ft::vector<int> v;
		std::vector<int> v_og;

		v.push_back(78);
		v_og.push_back(78);

		if (v.front() != v_og.front())
			std::cout << "Vector -> Front: error 1" << std::endl;

		v.push_back(16);
		v_og.push_back(16);

		v.front() -= v.back();
		v_og.front() -= v_og.back();

		if (v.front() != v_og.front() || v.front() != 62)
			std::cout << "Vector -> Front: error 2" << std::endl;
	}
	{
		ft::vector<int> first;
		ft::vector<int> second;
		ft::vector<int> third;

		first.assign(7, 42);

		ft::vector<int>::iterator it = first.begin() + 1;
		second.assign(it, first.end() - 1);
		int myints[] = {1776, 7, 4};
		third.assign(myints, myints + 3);

		if (first.size() != 7)
			std::cout << "Vector -> Assign: error 1" << std::endl;
		if (second.size() != 5)
			std::cout << "Vector -> Assign: error 2" << std::endl;
		if (third.size() != 3)
			std::cout << "Vector -> Assign: error 3" << std::endl;
	}
	{
		ft::vector<int> v;

		int sum(0);
		v.push_back(42);
		v.push_back(420);
		v.push_back(4200);

		while (!v.empty()) {
			sum += v.back();
			v.pop_back();
		}
		if (sum != 4662)
			std::cout << "Vector -> Pop_back: error 1" << std::endl;
	}
	{
		ft::vector<int> v1(3, 42);
		ft::vector<int> v2(5, 42);

		v1.swap(v2);
		if (v1.size() != 5 || v1.capacity() != 5 || v1[0] != 42 || v1[1] != 42
			|| v1[2] != 42 || v1[3] != 42 || v1[4] != 42)
			std::cout << "Vector -> Swap: error 1" << std::endl;
		if (v2.size() != 3 || v2.capacity() != 3 || v2[0] != 42 || v2[1] != 42
			|| v2[2] != 42)
			std::cout << "Vector -> Swap: error 2" << std::endl;
	}
	{
		ft::vector<int> myvector;
		myvector.push_back(42);
		myvector.push_back(420);
		myvector.push_back(4200);

		int	nums[] = {42, 420, 4200};
		for (unsigned i = 0; i < myvector.size(); i++)
			if (myvector[i] != nums[i])
			std::cout << "Vector -> Clear: error 1" << std::endl;

		myvector.clear();
		myvector.push_back(1101);
		myvector.push_back(2202);

		int nums2[] = {1101, 2202};
		for (unsigned i = 0; i < myvector.size(); i++)
			if (myvector[i] != nums2[i])
			std::cout << "Vector -> Clear: error 2" << std::endl;

	}
	{
		ft::vector<int> v;
		int	*p = 0;
		unsigned int i = 0;

		p = v.get_allocator().allocate(5);
		for (i = 0; i < 5; i++)
			v.get_allocator().construct(&p[i], i);
		for (i = 0; i < 5; i++)
			if (p[i] != static_cast<int>(i))
			std::cout << "Vector -> Allocator: error 1" << std::endl;
		for (i = 0; i < 5; i++)
			v.get_allocator().destroy(&p[i]);
		v.get_allocator().deallocate(p, 5);
	}
	{
		ft::vector<int> v1(3, 42);
		ft::vector<int> v2(2, 420);

		std::vector<int> v1_og(3, 42);
		std::vector<int> v2_og(2, 420);

		if ((v1 == v2) != (v1_og == v2_og))
			std::cout << "Vector -> relational operator: error 1" << std::endl;
		if ((v1 != v2) != (v1_og != v2_og))
			std::cout << "Vector -> relational operator: error 2" << std::endl;
		if ((v1 < v2) != (v1_og < v2_og))
			std::cout << "Vector -> relational operator: error 3" << std::endl;
		if ((v1 > v2) != (v1_og > v2_og))
			std::cout << "Vector -> relational operator: error 4" << std::endl;
		if ((v1 <= v2) != (v1_og <= v2_og))
			std::cout << "Vector -> relational operator: error 5" << std::endl;
		if ((v1 >= v2) != (v1_og >= v2_og))
			std::cout << "Vector -> relational operator: error 6" << std::endl;
	}
	{
		ft::vector<int> v1(3, 42);
		ft::vector<int> v2(5, 42);

		v1.swap(v2);
		if (v1.size() != 5 || v1.capacity() != 5 || v1[0] != 42 || v1[1] != 42
			|| v1[2] != 42 || v1[3] != 42 || v1[4] != 42)
			std::cout << "Vector -> Non member swap: error 1" << std::endl;
		if (v2.size() != 3 || v2.capacity() != 3 || v2[0] != 42 || v2[1] != 42
			|| v2[2] != 42)
			std::cout << "Vector -> Non member swap: error 2" << std::endl;
	}
	std::cout << "If no error message is displayed, everything is ok" << std::endl;
}




