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

//inline void printTime(chrono::system_clock::time_point start)
//{
//	chrono::duration dur = chrono::system_clock::now() - start;
//	cout << endl << endl << dur.count() << "ms" << endl << endl;
//}

int main()
{
	ui n, m;
	cin >> n >> m;
	vui a;
	for (ui i = 0; i < n; i++)
	{
		ui ai;
		cin >> ai;
		if (ai) a.push_back(ai);
		else n--;
	}

	//chrono::time_point start = chrono::system_clock::now();

	if (n <= 1)
	{
		cout << ((n && a[0] % m == 0) ? "YES" : "NO");
		//printTime(start);
		return 0;
	}

	set<ui> mods;
	vui newMods;
	//vb mods(m, false);

	for (ui ai : a)
	{
		ai %= m;
		if (!ai)
		{
			//printTime(start);
			cout << "YES";
			return 0;
		}
		for (ui aj : mods)
		{
			ui mod = ai + aj;
			if (mod >= m)
			{
				if (mod == m)
				{
					cout << "YES";
					//printTime(start);
					return 0;
				}
				mod -= m;
			}
			newMods.push_back(mod);
		}
		mods.insert(ai);
		for (ui mod : newMods)
		{
			mods.insert(mod);
		}
		newMods.resize(0);
		newMods.shrink_to_fit();
	}
	cout << "NO";
	//printTime(start);

	return 0;
}