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
	unsigned max = 0;
	unsigned n;
	cin >> n;
	unsigned* a = new unsigned[n];
	for (unsigned i = 0; i < n; i++)
	{
		unsigned ai;
		cin >> ai;
		a[i] = ai;
		if (ai > max)
		{
			max = ai;
		}
	}

	// Compute sieve
	__assume(max >= 2);
	unsigned* divs = new unsigned[2 * max + 2]{ 0 };
	divs[0] = divs[1] = divs[2] = divs[3] = 0;
	for (unsigned p = 2; p <= max; p++)
	{
		if (divs[2 * p + 1] == 0)
		{
			for (unsigned long long pow = p; pow <= max; pow *= p)
			{
				divs[2 * pow] = 0;
				divs[2 * pow + 1] = p;
				for (unsigned n = 2, mul = pow * 2; mul <= max; n++, mul += pow)
				{
					divs[2 * mul] = p;
					divs[2 * mul + 1] = n;
				}
			}
		}
	}

	unsigned* ans = new unsigned[2 * n];
	// Check for powers of primes.
	for (unsigned i = 0; i < n; i++)
	{
		if (!divs[2 * a[i]])
		{
			ans[i] = ans[i + n] = 0;
		}
		else
		{
			ans[i] = divs[2 * a[i]];
			ans[i + n] = divs[2 * a[i] + 1];
		}
	}
	for (unsigned i = 0; i < n; i++)
	{
		cout << (ans[i] ? to_string(ans[i]) : "-1") << " ";
	}
	cout << endl;
	for (unsigned i = 0; i < n; i++)
	{
		cout << (ans[i + n] ? to_string(ans[i + n]) : "-1") << " ";
	}
	return 0;
}