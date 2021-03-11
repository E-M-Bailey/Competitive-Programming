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

int main()
{
	unsigned n, m;
	cin >> n >> m;

	unsigned size = 2 << n;
	unsigned* tree = new unsigned[size - 1];
	tree--; // Element 0 is never used.
	unsigned s = size;

	// Build
	for (unsigned p = s / 2; p < s; p++)
	{
		cin >> tree[p];
	}
	for (unsigned level = 0; level < n; level++)
	{
		s /= 2;
		if (level & 1)
		{
			for (unsigned p = s / 2; p < s; p++)
			{
				tree[p] = tree[2 * p] ^ tree[2 * p + 1];
			}
		}
		else
		{
			for (unsigned p = s / 2; p < s; p++)
			{
				tree[p] = tree[2 * p] | tree[2 * p + 1];
			}
		}
	}

	for (unsigned i = 0; i < m; i++)
	{
		// Modify
		unsigned p, b;
		cin >> p >> b;
		p += size / 2 - 1;
		tree[p] = b;
		for (unsigned level = 0; level < n; level++)
		{
			p /= 2;
			if (level & 1)
			{
				tree[p] = tree[2 * p] ^ tree[2 * p + 1];
			}
			else
			{
				tree[p] = tree[2 * p] | tree[2 * p + 1];
			}
		}
		cout << tree[1] << endl;
	}
}