#include <cstring>
#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct SegmentTree
{
	unsigned bitmask; // LSB = leaves, MSB = root
	unsigned n;

	unsigned* offsets; // offsets[0] = total size; offsets[r + 1] = size of row r (r=0: leaves, r=n-1: root). Equal to offset of that row.

	unsigned long long* data;

	inline SegmentTree(unsigned n) :
		bitmask(0),
		n(n),
		offsets(new unsigned[n + 2]),
		data(new unsigned long long[(2 << n) - 1])
	{
		unsigned i = 0;
		for (; i < n + 2; i++)
		{
			offsets[i] = (1u << n + 1 - i) - 1;
		}
		for (i = offsets[1]; i < offsets[0]; i++)
		{
			cin >> data[i];
		}
		i = offsets[1];
		while (i--)
		{
			data[i] = data[2 * i + 1] + data[2 * i + 2];
		}
	}

	// Row 0 = leaves, Row n = root
	inline constexpr unsigned long long& get(unsigned index, unsigned row = 0)
	{
		unsigned offset = offsets[row + 1];
		index ^= bitmask >> row;
		return data[offset + index];
	}

	inline void replace()
	{
		unsigned x, k;
		cin >> x >> k;
		x--;
		long long diff = k - get(x);

		for (unsigned row = 0; row <= n; row++)
		{
			get(x, row) += diff;
			x /= 2;
		}
	}

	inline void reverse()
	{
		unsigned k;
		cin >> k;
		bitmask ^= (1u << k) - 1;
	}

	inline void swap()
	{
		unsigned k;
		cin >> k;
		bitmask ^= 1u << k;
	}

	inline constexpr void evalRange(unsigned long long& sum, unsigned row, unsigned index, unsigned lo, unsigned hi)
	{
		if (lo == 0 && hi == offsets[n + 1 - row])
		{
			sum += get(index, row);
			return;
		}
		unsigned next = offsets[n + 2 - row];
		bool goLo = lo <= next;
		bool goR = hi > next;
		if (goLo)
		{
			evalRange(sum, row - 1, index * 2, lo, goR ? next : hi);
		}
		if (goR)
		{
			evalRange(sum, row - 1, index * 2 + 1, goLo ? 0 : lo - (next + 1), hi - (next + 1));
		}
	}

	inline void sum()
	{
		unsigned l, r;
		cin >> l >> r;
		unsigned long long sum = 0;
		evalRange(sum, n, 0, l - 1, r - 1);
		cout << sum << endl;
	}
};

int main()
{
	unsigned n, q;
	cin >> n >> q;
	SegmentTree tree(n);

	for (unsigned tc = 0; tc < q; tc++)
	{
		unsigned type;
		cin >> type;
		switch (type)
		{
		case 1:
			tree.replace();
			break;
		case 2:
			tree.reverse();
			break;
		case 3:
			tree.swap();
			break;
		case 4:
			tree.sum();
			break;
		default:
			__assume(0);
		}
	}

	return 0;
}
