#include <cstring>
#include <algorithm>
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

#define loop(n, i) for (ui i = 0; i < (n); i++)
#define rloop(n, i) for (ui i = (n); i-- > 0;)
#define loop_each(vec, i, x) auto x = vec.front(); for (ui i = 0; i < (vec).size(); i++, x = vec[i])
#define rloop_each(vec, i, x) auto x = vec.back(); for (ui i = (vec).size(); i-- > 0; x = vec[i - 1])

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef unsigned           ui;
typedef pair<int, int>     pi;
typedef pair<ui, ui>       pui;
typedef vector<int>        vi;
typedef vector<ui>         vui;
typedef vector<pi>         vpi;
typedef vector<pui>        vpui;
typedef vector<bool>       vb;

int main()
{
	ui tCases; cin >> tCases;
	loop(tCases, tCase)
	{
		ui n; cin >> n;
		ui table[26]{ 0 };
		string str;
		loop(n, i)
		{
			cin >> str;
			for (char ch : str)
			{
				table[ch - 'a']++;
			}
		}
		bool success = true;
		for (ui x : table)
		{
			if (x % n)
			{
				success = false;
				cout << "NO" << endl;
				break;
			}
		}
		if (success)
		{
			cout << "YES" << endl;
		}
	}
	return 0;
}