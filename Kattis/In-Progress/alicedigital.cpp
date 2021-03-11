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

inline constexpr ui l2ru(ui n)
{
	if (n == 0) return 0;
	n *= 2; n--;
	ui log = 0;
	while (n > 0)
	{
		log++;
		n /= 2;
	}
	return log - 1;
}

struct SegmentTree
{
	ui n;

	ui* offsets; // offsets[0] = total size; offsets[r + 1] = size of row r (r=0: leaves, r=n-1: root). Equal to offset of that row.

	ui* data;

	inline SegmentTree(const vui& A) :
		n(l2ru(A.size())),
		offsets(new ui[n + 2]),
		data(new ui[(2 << n) - 1])
	{
		ui i = 0;
		for (; i < n + 2; i++)
		{
			offsets[i] = (1u << n + 1 - i) - 1;
		}
		ui j = 0;
		for (i = offsets[1]; i < offsets[0]; i++, j++)
		{
			data[i] = j < A.size() ? A[j] : 0u;
			//cin >> data[i];
		}
		i = offsets[1];
		while (i--)
		{
			data[i] = data[2 * i + 1] + data[2 * i + 2];
		}
	}

	// Row 0 = leaves, Row n = root
	inline constexpr ui& get(ui index, ui row = 0)
	{
		ui offset = offsets[row + 1];
		return data[offset + index];
	}

	inline constexpr void evalRange(ui& sum, ui row, ui index, ui lo, ui hi)
	{
		if (lo == 0 && hi == offsets[n + 1 - row])
		{
			sum += get(index, row);
			return;
		}
		ui next = offsets[n + 2 - row];
		bool goLo = lo <= next;
		bool goR = hi > next;
		if (goLo)
		{
			evalRange(sum, row - 1, index * 2, lo, goR ? next : hi);
		}
		if (goR)
		{
			evalRange(sum, row - 1, index * 2 + 1, goLo ? 0 : lo - (next + 1), hi - (next + 1));
		}
	}
};

int main()
{
	ui tCases; cin >> tCases;
	loop(0, tCases, tCase)
	{
		ui n, m; cin >> n >> m;

		vui A(n);
		vui mIdx;
		loop(0, n, i)
		{
			ui a; cin >> a; A[i] = a;
			if (a == m) mIdx.push_back(i);
		}

		SegmentTree st(A);
		if (mIdx.size() == 1)
		{
			ui sum = 0;
			cout << st.evalRange(sum, )
		}
	}
	return 0;
}