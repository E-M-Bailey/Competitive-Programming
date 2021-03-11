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
	string line = "";
	while (getline(cin, line), line != "END")
	{
		ui x = line.length();
		string prev, cur;
		cur = to_string(x);
		if (cur == line)
		{
			cout << "1" << endl;
			continue;
		}
		for (ui i = 2;; i++)
		{
			x = cur.size();
			prev = cur;
			cur = to_string(x);
			if (prev == cur)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}