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

constexpr const ull IS_PRIME_TABLE[1] = { 1 };

inline string genSieve()
{
	vb isPrime(40000, true);
	isPrime[0] = false;
	loop(2, 40001, i)
	{
		if (isPrime[i - 1])
		{
			for (ui j = i * 2; j < 40001; j += i)
			{
				isPrime[j - 1] = false;
			}
		}
	}
	vull compressed(625, 0ull);
	loop(0, 625, i)
	{
		loop(0, 64, j)
		{
			if (isPrime[i * 64 + j])
			{
				compressed[i] |= 1ull << j;
			}
		}
	}
	//ostream& stream = cout;
	stringstream stream;
	stream << "constexpr const ull IS_PRIME_TABLE[625] =" << endl << "{";
	loop(0, 625, i)
	{
		if (i % 25 == 0) stream << endl;
		else stream << " ";
		stream << "0x" << hex << compressed[i];
		if (i < 624) stream << ",";
	}
	stream << endl << "};" << endl;
	return stream.str();
}

inline string genPos()
{
	vector<pair<ui, ui>> pos(40000);
	vector<vector<uint16_t>> vals(200, vector<uint16_t>(200));
	ui dir = 0;
	ui len = 1;
	ui cur = 0;
	int x = 0, y = 0;
	loop(0, 40000, i)
	{
		pos[i] = { x + 99, y + 99 };
		vals[x + 99][y + 99] = i + 1;
		if (cur < len)
		{
			cur++;
		}
		else
		{
			dir++;
			if (dir == 4) dir = 0;
			if (dir % 2 == 0) len++;
			cur = 1;
		}
		switch (dir)
		{
		case 0:
			x++;
			break;
		case 1:
			y++;
			break;
		case 2:
			x--;
			break;
		case 3:
			y--;
			break;
		default:
			__assume(false);
		}
	}
	vull compressedPos(10000, 0);
	loop(0, 10000, i)
	{
		loop(0, 4, j)
		{
			compressedPos[i] |= ((ull)pos[i * 4 + j].first) << (j * 16ull);
			compressedPos[i] |= ((ull)pos[i * 4 + j].second) << (j * 16ull + 8ull);
		}
	}
	stringstream stream;
	stream << "constexpr const ull POS_TABLE[10000] =" << endl << "{";
	loop(0, 10000, i)
	{
		if (i % 25 == 0) stream << endl;
		else stream << " ";
		stream << "0x" << hex << compressedPos[i];
		if (i < 9999) stream << ",";
	}
	stream << endl << "};" << endl;

	vull compressedVals(10000, 0);
	loop(0, 10000, i)
	{
		loop(0, 4, j)
		{
			ui idx = i * 4 + j;
			compressedVals[i] |= ((ull)vals[idx / 200][idx % 200]) << (j * 16ull);
		}
	}
	stream << "constexpr const ull VAL_TABLE[10000] =" << endl << "{";
	loop(0, 10000, i)
	{
		if (i % 25 == 0) stream << endl;
		else stream << " ";
		stream << "0x" << hex << compressedVals[i];
		if (i < 9999) stream << ",";
	}
	stream << endl << "};" << endl;

	return stream.str();
}

int main()
{
	cout << genSieve() << genPos();
	return 0;
}