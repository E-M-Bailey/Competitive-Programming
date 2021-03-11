#include <cstring>
#include <array>
#include <deque>
#include <forward_list>
#include <intrin.h>
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

inline constexpr unsigned gcd(unsigned a, unsigned b)
{
	if (!(a && b))
	{
		return a | b;
	}
	do
	{
		if (a > b)
		{
			unsigned t = a;
			a = b;
			b = t;
		}
		b -= a;
	}
	while (a);
	return b;
}

void doRun()
{
	unsigned a, b;
	cin >> a >> b;

	bool* grid = new bool[a * b]{ false };
	const bool doBreak = false;

	unsigned max = a + b;
	unsigned count = 0;
	for (unsigned period = 2; period <= max; period++)
	{
		unsigned start = period > b ? period - b : 1;
		unsigned end = period > a ? a : period - 1;
		for (unsigned a1 = start; a1 <= end; a1++)
		{
			unsigned b1 = period - a1;
			unsigned na = a / a1, nb = b / b1;
			if (na > nb)
			{
				if (a <= (nb + 1) * a1)
				{
					//cout << a1 << " " << b1 << endl;
					grid[a1 * b + b1] = true;
					count++;
					if (doBreak) break;
				}
			}
			else
			{
				if (b <= (na + 1) * b1)
				{
					//cout << a1 << " " << b1 << endl;
					grid[a1 * b + b1] = true;
					count++;
					if (doBreak) break;
				}
			}
		}
	}

	cout << '\\';
	for (unsigned i = 0; i < b; i++)
	{
		cout << '-';
	}
	cout << endl;
	for (unsigned i = 0; i < a; i++)
	{
		cout << '|';
		for (unsigned j = 0; j < b; j++)
		{
			cout << (grid[i * b + j] ? '#' : ' ');
		}
		cout << endl;
	}

	cout << count << endl;
}

int main()
{
	while (true) doRun();
	return 0;
}
