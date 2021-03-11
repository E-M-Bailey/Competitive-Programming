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

string DELIMITER = " ";

template<typename T>
inline ostream& operator<<(ostream& stream, const tuple<T>& container)
{
	bool first = true;
	for (const T& x : container)
	{
		if (!first) stream << DELIMITER;
		first = false;
		stream << x;
	}
	return stream;
}
template<typename T, size_t size>
inline ostream& operator<<(ostream& stream, const array<T, size>& container)
{
	bool first = true;
	for (const T& x : container)
	{
		if (!first) stream << DELIMITER;
		first = false;
		stream << x;
	}
	return stream;
}
template<typename T>
inline ostream& operator<<(ostream& stream, const vector<T>& container)
{
	bool first = true;
	for (const T& x : container)
	{
		if (!first) stream << DELIMITER;
		first = false;
		stream << x;
	}
	return stream;
}
template<typename T>
inline ostream& operator<<(ostream& stream, const deque<T>& container)
{
	bool first = true;
	for (const T& x : container)
	{
		if (!first) stream << DELIMITER;
		first = false;
		stream << x;
	}
	return stream;
}
template<typename T>
inline ostream& operator<<(ostream& stream, const forward_list<T>& container)
{
	bool first = true;
	for (const T& x : container)
	{
		if (!first) stream << DELIMITER;
		first = false;
		stream << x;
	}
	return stream;
}
template<typename T>
inline ostream& operator<<(ostream& stream, const list<T>& container)
{
	bool first = true;
	for (const T& x : container)
	{
		if (!first) stream << DELIMITER;
		first = false;
		stream << x;
	}
	return stream;
}
template<typename T>
inline ostream& operator<<(ostream& stream, const stack<T>& container)
{
	bool first = true;
	for (const T& x : container)
	{
		if (!first) stream << DELIMITER;
		first = false;
		stream << x;
	}
	return stream;
}
template<typename T>
inline ostream& operator<<(ostream& stream, const queue<T>& container)
{
	bool first = true;
	for (const T& x : container)
	{
		if (!first) stream << DELIMITER;
		first = false;
		stream << x;
	}
	return stream;
}
template<typename T>
inline ostream& operator<<(ostream& stream, const priority_queue<T>& container)
{
	bool first = true;
	for (const T& x : container)
	{
		if (!first) stream << DELIMITER;
		first = false;
		stream << x;
	}
	return stream;
}
template<typename T>
inline ostream& operator<<(ostream& stream, const set<T>& container)
{
	bool first = true;
	for (const T& x : container)
	{
		if (!first) stream << DELIMITER;
		first = false;
		stream << x;
	}
	return stream;
}
template<typename T>
inline ostream& operator<<(ostream& stream, const multiset<T>& container)
{
	bool first = true;
	for (const T& x : container)
	{
		if (!first) stream << DELIMITER;
		first = false;
		stream << x;
	}
	return stream;
}
template<typename K, typename V>
inline ostream& operator<<(ostream& stream, const multiset<K, V>& container)
{
	bool first = true;
	for (const pair<K, V>& x : container)
	{
		if (!first) stream << DELIMITER;
		first = false;
		stream << x;
	}
	return stream;
}

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

	pui* minData;
	pui* maxData;

	inline SegmentTree(const vui& A) :
		n(l2ru(A.size())),
		offsets(new ui[n + 2]),
		minData(new pui[(2 << n) - 1]),
		maxData(new pui[(2 << n) - 1])
	{
		ui i = 0;
		for (; i < n + 2; i++)
		{
			offsets[i] = (1u << n + 1 - i) - 1;
		}
		ui j = 0;
		for (i = offsets[1]; i < offsets[0]; i++, j++)
		{
			minData[i] = { j, j < A.size() ? A[j] : 0u };
			//cin >> data[i];
		}
		i = offsets[1];
		while (i--)
		{
			if (minData[2 * i + 1] < minData[2 * i + 2])
				minData[i] = minData[2 * i + 1];
			else
				minData[i] = minData[2 * i + 2];
			if (maxData[2 * i + 1] > maxData[2 * i + 2])
				maxData[i] = maxData[2 * i + 1];
			else
				maxData[i] = maxData[2 * i + 2];
		}
	}

	// Row 0 = leaves, Row n = root
	inline constexpr pui& getMin(ui index, ui row = 0)
	{
		ui offset = offsets[row + 1];
		return minData[offset + index];
	}

	inline constexpr pui& getMax(ui index, ui row = 0)
	{
		ui offset = offsets[row + 1];
		return maxData[offset + index];
	}

	inline constexpr void evalRange(pui& sum, ui row, ui index, ui lo, ui hi)
	{
		if (lo == 0 && hi == offsets[n + 1 - row])
		{
			sum += getMin(index, row);
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

#include <fstream>

int main()
{
	ifstream in("out.txt");
	ui n; in >> n;
	vui H(n); loop(0, n, i) in >> H[i];
	SegmentTree st(H);
	vector<vui> nontrivial(n);
	loop(0, n - 2, i)
	{
		ui hi = H[i];
		ui M = H[i + 1], m = H[i + 1];
		loop(i + 2, n, j) // all higher (_--_)
		{
			if (m <= hi) break;
			ui hj = H[j];
			if (max(hi, hj) < m) nontrivial[i].push_back(j);
			if (hj < m) m = hj;
		}
		loop(i + 2, n, j) // all lower(-__-)
		{
			if (M >= hi) break;
			ui hj = H[j];
			if (min(hi, hj) > M) nontrivial[i].push_back(j);
			if (hj > M) M = hj;
		}
	}

	vui dp(n, UI_MAX);
	dp[0] = 0;
	loop(0, n, i)
	{
		ui inc = dp[i] + 1;
		if (i < n - 1 && dp[i + 1] > inc) dp[i + 1] = inc;
		for (ui j : nontrivial[i]) if (dp[j] > inc) dp[j] = inc;
	}
	cout << dp[n - 1];
	return 0;
}