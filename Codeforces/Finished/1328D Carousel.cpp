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

#define _CRT_SECURE_NO_DEPRECATE

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

int main()
{
	ui q;
	cin >> q;
	for (ui tCase = 0; tCase < q; tCase++)
	{
		ui n;
		cin >> n;
		ui* t = new ui[n];
		for (ui i = 0; i < n; i++)
		{
			cin >> t[i];
		}
		ui first = t[0];
		bool allSame = true;
		bool hasBreak = false;
		for (ui i = 1; i < n; i++)
		{
			if (t[i] != first)
			{
				allSame = false;
			}
			if (t[i] == t[i - 1])
			{
				hasBreak = true;
			}
		}
		if (first == t[n - 1])
		{
			hasBreak = true;
		}

		if (allSame)
		{
			cout << "1" << endl << "1";
			for (ui i = 1; i < n; i++)
			{
				cout << " 1";
			}
		}
		else if (!(n & 1))
		{
			cout << "2" << endl << "1 2";
			for (ui i = 2; i < n; i += 2)
			{
				cout << " 1 2";
			}
		}
		else if (hasBreak)
		{
			cout << "2" << endl << "1";
			bool doneBreak = false;
			for (ui i = 1; i < n; i += 2)
			{
				if (doneBreak)
				{
					cout << " 1 2";
				}
				else if (t[i - 1] == t[i])
				{
					doneBreak = true;
					cout << " 1 2";
				}
				else if (t[i] == t[i + 1])
				{
					doneBreak = true;
					cout << " 2 2";
				}
				else
				{
					cout << " 2 1";
				}
			}
		}
		else
		{
			cout << "3" << endl << "3";
			for (ui i = 1; i < n; i += 2)
			{
				cout << " 1 2";
			}
		}
		cout << endl;
	}
	return 0;
}