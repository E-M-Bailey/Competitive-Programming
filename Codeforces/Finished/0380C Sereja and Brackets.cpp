#include <iostream>
#include <cstring>
#include <array>
#include <deque>
#include <forward_list>
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

struct Node
{
	unsigned v, l, r;
};

inline constexpr void merge(Node& p, const Node& l, const Node& r)
{
	unsigned u = min(l.l, r.r);
	p.v = l.v + r.v + 2 * u;
	p.l = l.l + r.l - u;
	p.r = l.r + r.r - u;
}

struct EvalInfo
{
	unsigned i, s, l, r;
};
void eval(Node* __restrict tree, Node& a, unsigned i, unsigned s, unsigned l, unsigned r)
{
	if (l == 0 && r == s)
	{
		merge(a, a, tree[i]);
	}
	else
	{
		s /= 2;
		bool goL = l <= s;
		bool goR = r > s;
		if (goL) eval(tree, a, 2 * i + 1, s, l, goR ? s : r);
		if (goR) eval(tree, a, 2 * i + 2, s, goL ? 0 : l - (s + 1), r - (s + 1));
	}
}

int main()
{
	string str;
	cin >> str;

	unsigned inputSize = str.size();

	// Next highest power of 2 (src: bit twiddling hacks)
	unsigned size = inputSize - 1;
	size |= size >> 1;
	size |= size >> 2;
	size |= size >> 4;
	size |= size >> 8;
	size |= size >> 16;
	size = 2 * (size)+1;

	unsigned s = size / 2;

	Node* tree = new Node[size];
	Node* up = tree + s;
	unsigned i = 0;
	for (; i < inputSize; i++)
	{
		unsigned l = str[i] == '(';
		up[i] = { 0, l, 1 - l };
	}
	for (; i <= s; i++)
	{
		up[i] = { 0, 0, 0 };
	}
	Node* down;
	while (s)
	{
		down = up;
		up = tree + (s /= 2);
		for (i = 0; i <= s; i++)
		{
			merge(up[i], down[i * 2], down[i * 2 + 1]);
		}
	}

	unsigned m;
	cin >> m;

	for (unsigned q = 0; q < m; q++)
	{
		unsigned l, r;
		cin >> l >> r;
		Node accumulator{ 0, 0, 0 };
		eval(tree, accumulator, 0, size / 2, l - 1, r - 1);
		cout << accumulator.v << endl;
	}

	return 0;
}