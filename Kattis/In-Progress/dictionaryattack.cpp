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

#define loop(m, n, i) for (ui i = m; i < (n); i++)
#define rloop(m, n, i) for (ui i = (n); i-- > m;)
#define loop_each(vec, i, x) auto x = vec.front(); for (ui i = 0; i < (vec).size(); i++, x = vec[i])
#define rloop_each(vec, i, x) auto x = vec.back(); for (ui i = (vec).size(); i-- > 0; x = vec[i - 1])

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

//inline bool similar2(string& dict, string& pass, ui l, ui r)
//{
//	if (dict == pass) return true;
//	if (r == 0) return false;
//	loop(0, l, i)
//	{
//		if (dict[i] != pass[i] && (pass[i] < '0' || pass[i] > '9')) return false;
//	}
//	loop(0, l, i)
//	{
//		if (dict[i] != pass[i])
//		{
//			char temp = dict[i];
//			dict[i] = pass[i];
//			bool sim = similar2(dict, pass, l, r - 1);
//			dict[i] = temp;
//			if (sim) return true;
//		}
//	}
//	return false;
//}
//
//inline bool similar(string& dict, string& pass, ui l, ui r = 3)
//{
//	if (similar2(dict, pass, l, r)) return true;
//	if (r == 0) return false;
//
//	loop(1, l, i)
//	{
//		char temp = dict[i];
//		dict[i] = dict[i - 1];
//		dict[i - 1] = temp;
//		bool sim = similar(dict, pass, l, r - 1);
//		dict[i - 1] = dict[i];
//		dict[i] = temp;
//		if (sim) return true;
//	}
//	return false;
//}

inline bool similar(string& dict, string& pass, ui i, ui l, ui r = 3)
{
	if (i == l) return true;
	while (dict[i] == pass[i])
	{
		i++;
		if (i == l) return true;
	}
	char d = dict[i], p = pass[i];

	if (r == 0) return false;

	if (d >= '0' && d <= '9' && similar(dict, pass, i + 1, l, r - 1)) return true;
	
	if (i == l - 1) return false;

	if (p == dict[i + 1])
	{
		char temp = dict[i];
		dict[i] = dict[i + 1];
		dict[i + 1] = temp;
		bool sim = similar(dict, pass)
	}
}

bool similar(const string& dict, const string& pass, )

int main()
{
	ui N; cin >> N;
	vector<vector<string>> dicts(15);
	loop(0, N, i)
	{
		string str; cin >> str;
		vector<string>& vec = dicts[str.size()];
		vec.push_back(move(str));
	}
	//unordered_set<string> passes;
	while (true)
	{
		string pass; cin >> pass;
		//ui pSize = passes.size();
		//passes.insert(pass);
		//if (passes.size() == pSize) continue;
		ui l = pass.size();
		bool strong = true;
		for (string& dict : dicts[l])
		{
			ui ct = 0;
			loop(0, l, i)
			{
				if (dict[i] != pass[i])
				{
					ct++;
					if (ct == 4)
					{
						break;
					}
				}
			}
			if (ct == 4) continue;
			if (similar(dict, pass, l))
			{
				strong = false;
				break;
			}
		}
		if (strong)
		{
			cout << pass << endl;
		}
	}
	return 0;
}