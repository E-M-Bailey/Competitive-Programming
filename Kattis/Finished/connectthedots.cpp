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

#define loop(m, n, i) for (ui i = (m); i < (n); i++)
#define rloop(m, n, i) for (ui i = (n); i-- > (m);)
#define loop_each(vec, i, x) auto x = vec.front(); for (ui i = 0; i < (vec).size(); i++, x = vec[i])
#define rloop_each(vec, i, x) auto x = vec.back(); for (ui i = (vec).size(); i-- > 0; x = vec[i - 1])

#define tCases() ui testCaseCount; cin >> testCaseCount; for (ui testCaseIndex = 0; testCaseIndex < testCaseCount; testCaseIndex++)

using namespace std;

typedef unsigned           ui;
typedef long long          ll;
typedef unsigned long long ull;
typedef pair<int, int>     pi;
typedef pair<ui, ui>       pui;
typedef pair<ll, ll>       pll;
typedef pair<ull, ull>     pull;
typedef vector<int>        vi;
typedef vector<ui>         vui;
typedef vector<ll>         vll;
typedef vector<ull>        vull;
typedef vector<pi>         vpi;
typedef vector<pui>        vpui;
typedef vector<pll>        vpll;
typedef vector<pull>       vpull;
typedef vector<bool>       vb;

constexpr const ui UI_MAX = numeric_limits<ui>::max();

ui toIdx(char name)
{
	return
		name <= '9' ? name - '0' :
		name >= 'a' ? name - 'a' + 10 :
		name - 'A' + 36;
}

char toName(ui idx)
{
	const static char names[63] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQUSTUVWXYZ";
	return names[idx];
}

int main()
{
	while (!cin.eof())
	{
		pui dots[62]{ {0, 0} };
		char grid[100][100]{ 0 };

		ui w, h;
		ui n = 0;

		ui i = 0;
		while (!cin.eof())
		{
			string line;
			getline(cin, line);
			if (line == "") break;

			if (i == 0) w = line.size();

			loop(0, w, j)
			{
				char ch = line[j];
				grid[i][j] = ch;
				if (ch != '.')
				{
					ui idx = toIdx(ch);
					dots[idx] = { i, j };
					n = max(idx + 1, n);
				}
			}

			i++;
		}
		h = i;

		loop(1, n, idx)
		{
			pui prev = dots[idx - 1], cur = dots[idx];
			if (prev.first == cur.first)
			{
				if (prev.second > cur.second)
				{
					ui temp = prev.second;
					prev.second = cur.second;
					cur.second = temp;
				}
				
				ui& i = cur.first;
				loop(prev.second + 1, cur.second, j)
				{
					if (grid[i][j] == '.') grid[i][j] = '-';
					else if (grid[i][j] == '|') grid[i][j] = '+';
				}
			}
			else
			{
				if (prev.first > cur.first)
				{
					ui temp = prev.first;
					prev.first = cur.first;
					cur.first = temp;
				}

				ui& j = cur.second;
				loop(prev.first + 1, cur.first, i)
				{
					if (grid[i][j] == '.') grid[i][j] = '|';
					else if (grid[i][j] == '-') grid[i][j] = '+';
				}
			}
		}

		loop(0, h, i)
		{
			loop(0, w, j)
			{
				cout << grid[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}