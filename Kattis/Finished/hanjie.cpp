#include <cstring>
#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <iomanip>
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

#ifdef _MSC_VER
inline int __builtin_clz(unsigned int value)
{
	return __lzcnt(value);
}
inline int __builtin_clzl(unsigned long int value)
{
	return __lzcnt(value);
}
inline int __builtin_clzll(unsigned long long int value)
{
	return value & 0xffffffff00000000ull ? __lzcnt(value >> 32) : 32 + __lzcnt(value);
}
inline constexpr int __builtin_ctzll(unsigned long long int value);
inline constexpr int __builtin_ctz(unsigned int value)
{
	return __builtin_ctzll(value);
}
inline constexpr int __builtin_ctzl(unsigned long int value)
{
	return __builtin_ctzll(value);
}
inline constexpr int __builtin_ctzll(unsigned long long int value)
{
	if (value == 0)
	{
		return 437; // undefined
	}
	int ctr = 0;
#define CTZ_SEGMENT(n) do { if (!(value & ((1ull << (n)) - 1))) { ctr |= (n); value >>= (n); } } while (0)
	CTZ_SEGMENT(1 << 5);
	CTZ_SEGMENT(1 << 4);
	CTZ_SEGMENT(1 << 3);
	CTZ_SEGMENT(1 << 2);
	CTZ_SEGMENT(1 << 1);
	CTZ_SEGMENT(1 << 0);
#undef CTZ_SEGMENT
	return ctr;
}
#endif

#define loop(m, n, i) for (uli i = (m); i < (n); i++)
#define rloop(m, n, i) for (uli i = (n); i-- > (m);)
#define loop_each(vec, i, x) auto x = vec.front(); for (uli i = 0; i < (vec).size(); i++, x = vec[i])
#define rloop_each(vec, i, x) auto x = vec.back(); for (uli i = (vec).size(); i-- > 0; x = vec[i - 1])

#define tCases() uli testCaseCount; cin >> testCaseCount; for (uli testCaseIndex = 0; testCaseIndex < testCaseCount; testCaseIndex++)

#define endl '\n'

using namespace std;

template<class T>
struct frac;

typedef bool                 bi;
typedef char                 ci;
typedef unsigned char        uci;
typedef frac<ci>             fci;
typedef frac<uci>            fuci;
typedef short                si;
typedef unsigned short       usi;
typedef frac<si>             fsi;
typedef frac<usi>            fusi;
typedef int                  li;
typedef unsigned             uli;
typedef frac<li>             fli;
typedef frac<uli>            fuli;
typedef long long            lli;
typedef unsigned long long   ulli;
typedef frac<lli>            flli;
typedef frac<ulli>           fulli;
typedef float                sf;
typedef double               df;
typedef long double          ldf;

typedef pair<bi, bi>         pbi;
typedef pair<ci, ci>         pci;
typedef pair<uci, uci>       puci;
typedef pair<fci, fci>       pfci;
typedef pair<fuci, fuci>     pfuci;
typedef pair<si, si>         psi;
typedef pair<usi, usi>       pusi;
typedef pair<fsi, fsi>       pfsi;
typedef pair<fusi, fusi>     pfusi;
typedef pair<li, li>         pli;
typedef pair<uli, uli>       puli;
typedef pair<fli, fli>       pfli;
typedef pair<fuli, fuli>     pfuli;
typedef pair<lli, lli>       plli;
typedef pair<ulli, ulli>     pulli;
typedef pair<flli, flli>     pflli;
typedef pair<fulli, fulli>   pfulli;
typedef pair<sf, sf>         psf;
typedef pair<df, df>         pdf;
typedef pair<ldf, ldf>       pldf;

typedef vector<bi>           vbi;
typedef vector<ci>           vci;
typedef vector<uci>          vuci;
typedef vector<fci>          vfci;
typedef vector<fuci>         vfuci;
typedef vector<si>           vsi;
typedef vector<usi>          vusi;
typedef vector<fsi>          vfsi;
typedef vector<fusi>         vfusi;
typedef vector<li>           vli;
typedef vector<uli>          vuli;
typedef vector<fli>          vfli;
typedef vector<fuli>         vfuli;
typedef vector<lli>          vlli;
typedef vector<ulli>         vulli;
typedef vector<flli>         vflli;
typedef vector<fulli>        vfulli;
typedef vector<sf>           vsf;
typedef vector<df>           vdf;
typedef vector<ldf>          vldf;

typedef vector<pbi>          vpbi;
typedef vector<pci>          vpci;
typedef vector<puci>         vpuci;
typedef vector<pfci>         vpfci;
typedef vector<pfuci>        vpfuci;
typedef vector<psi>          vpsi;
typedef vector<pusi>         vpusi;
typedef vector<pfsi>         vpfsi;
typedef vector<pfusi>        vpfusi;
typedef vector<pli>          vpli;
typedef vector<puli>         vpuli;
typedef vector<pfli>         vpfli;
typedef vector<pfuli>        vpfuli;
typedef vector<plli>         vplli;
typedef vector<pulli>        vpulli;
typedef vector<pflli>        vpflli;
typedef vector<pfulli>       vpfulli;
typedef vector<psf>          vpsf;
typedef vector<pdf>          vpdf;
typedef vector<pldf>         vpldf;

template<class T, class Container = vector<T>>
using max_heap = priority_queue<T, Container, less<T>>;

template<class T, class Container = vector<T>>
using min_heap = priority_queue<T, Container, greater<T>>;

#define MIN(T) (numeric_limits<T>::min())
#define MAX(T) (numeric_limits<T>::max())

inline constexpr uli gcd(uli l, uli r)
{
	if (!(l && r))
	{
		return l | r;
	}
	int s = __builtin_ctz(l | r);
	l >>= __builtin_ctz(l);
	do
	{
		r >>= __builtin_ctz(r);
		if (l > r)
		{
			swap(l, r);
		}
		r -= l;
	}
	while (r);
	return l << s;
}

inline constexpr ulli gcd(ulli l, ulli r)
{
	if (!(l && r))
	{
		return l | r;
	}
	int s = __builtin_ctzll(l | r);
	l >>= __builtin_ctzll(l);
	do
	{
		r >>= __builtin_ctzll(r);
		if (l > r)
		{
			swap(l, r);
		}
		r -= l;
	}
	while (r);
	return l << s;
}

template<class T>
struct frac
{
	using N = T;
	using D = make_unsigned_t<T>;

	N n;
	D d;

	inline constexpr frac r() const
	{
		D g = gcd(abs(n), d);
		return { n / g, d / g };
	}

	inline constexpr frac i() const
	{
		return n < 0 ? frac{ -(N)d, (D)-n } : frac{ (N)d, (D)n };
	}

	inline constexpr frac operator+() const
	{
		return { n, d };
	}

	inline constexpr frac operator-() const
	{
		return { -n, d };
	}

	inline constexpr frac operator+(const frac& f) const
	{
		return { n * (N)f.d + f.n * (N)d, d * f.d };
	}

	inline constexpr frac operator-(const frac& f) const
	{
		return { n * (N)f.d - f.n * (N)d, d * f.d };
	}

	inline constexpr frac operator*(const frac& f) const
	{
		return { n * f.n, d * f.d };
	}

	inline constexpr frac operator/(const frac& r) const
	{
		return n < 0 ? frac{ n * -(N)r.d, d * (D)-r.n } : frac{ n * (N)r.d, d * (D)r.n };
	}

	template<class S>
	inline constexpr frac operator<<(const S& s)
	{
		return { n << s, d };
	}

	template<class S>
	inline constexpr frac operator>>(const S& s)
	{
		return { n, d << s };
	}

	inline constexpr bool operator==(const frac& f)
	{
		return n * f.d == f.n * d;
	}

	inline constexpr bool operator!=(const frac& f)
	{
		return n * f.d != f.n * d;
	}

	inline constexpr bool operator<(const frac& f)
	{
		return n * f.d < f.n * d;
	}

	inline constexpr bool operator<=(const frac& f)
	{
		return n * f.d <= f.n * d;
	}

	inline constexpr bool operator>(const frac& f)
	{
		return n * f.d > f.n * d;
	}

	inline constexpr bool operator>=(const frac& f)
	{
		return n * f.d >= f.n * d;
	}

	inline constexpr operator bool() const
	{
		return d;
	}

	template<class S>
	inline constexpr explicit operator frac<S>() const
	{
		return frac<S>{ (typename frac<S>::N)n, (typename frac<S>::D)(d) };
	}
};

//template<uli r, uli c>
//struct runner
//{
//	//array<array<uli, (c + 1) / 2>, r> rows{};
//	//array<array<uli, (r + 1) / 2>, c> cols{};
//	//array<uli, r> rowK;
//	//array<uli, c> colK;
//	array<ulli, r> rowBitmasks{};
//	array<ulli, c> colBitmasks{};
//
//	template<uli idx>
//	constexpr inline void phase1Row(uli cur = 0, uli pos = 0, uli clueIdx = 0)
//	{
//		if constexpr (idx < r)
//		{
//			if (clueIdx >= rowK[idx])
//			{
//				rowBitmasks[idx] |= 1ull << cur;
//				return;
//			}
//			uli clue = rows[idx][clueIdx];
//			uli end = c - clue;
//			for (uli i = pos; i <= end; i++)
//			{
//				phase1Row<idx>(cur | (1 << clue) - 1 << i, i + clue + 1, clueIdx + 1);
//			}
//		}
//	}
//
//	template<uli idx>
//	inline constexpr void phase1Col(uli cur = 0, uli pos = 0, uli clueIdx = 0)
//	{
//		if constexpr (idx < c)
//		{
//			if (clueIdx >= colK[idx])
//			{
//				colBitmasks[idx] |= 1ull << cur;
//				return;
//			}
//			uli clue = cols[idx][clueIdx];
//			uli end = r - clue;
//			for (uli i = pos; i <= end; i++)
//			{
//				phase1Row<idx>(cur | (1 << clue) - 1 << i, i + clue + 1, clueIdx + 1);
//			}
//		}
//	}
//
//	void run()
//	{
//		//loop(0, r, i)
//		//{
//		//	cin >> rowK[i];
//		//	loop(0, rowK[i], j)
//		//	{
//		//		cin >> rows[i][j];
//		//	}
//		//}
//		//loop(0, c, i)
//		//{
//		//	cin >> colK[i];
//		//	loop(0, colK[i], j)
//		//	{
//		//		cin >> cols[i][j];
//		//	}
//		//}
//
//		//vector<vuli> possibleRows(r), possibleCols(c);
//
//		phase1Row<0>();
//		phase1Row<1>();
//		phase1Row<2>();
//		phase1Row<3>();
//		phase1Row<4>();
//		phase1Row<5>();
//
//		phase1Col<0>();
//		phase1Col<1>();
//		phase1Col<2>();
//		phase1Col<3>();
//		phase1Col<4>();
//		phase1Col<5>();
//
//		array<array<ulli, 1u << c>, r> comb{};
//
//		for (uli rowIdx = 0; rowIdx < r; rowIdx++)
//		{
//			for (uli rowP = 0; rowP < 1u << c; rowP++)
//			{
//				if (rowBitmasks[rowIdx] & 1ull << rowP)
//				{
//					for (uli colIdx = 0; colIdx < c; colIdx++)
//					{
//						for (uli colP = 0; colP < 1u << r; colP++)
//						{
//							if ((colBitmasks[colIdx] & 1ull << colP) && ((rowP & 1 << colIdx) == 0) == ((colP & 1 << rowIdx) == 0))
//							{
//								comb[rowIdx][rowP]
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//};

inline void phase1(vuli& pVector, ulli& pBitmask, const vuli& rowCol, uli len, uli cur = 0, uli pos = 0, uli idx = 0)
{
	if (idx >= rowCol.size())
	{
		pVector.push_back(cur);
		pBitmask |= 1ull << cur;
		return;
	}
	uli clue = rowCol[idx];
	uli end = len - clue;
	for (uli i = pos; i <= end; i++)
	{
		phase1(pVector, pBitmask, rowCol, len, cur | (1 << clue) - 1 << i, i + clue + 1, idx + 1);
	}
}


struct vecHash
{
	size_t operator()(const vuli& vec) const
	{
		size_t ret = 0;
		for (uli x : vec)
		{
			ret = ret * 10 + x;
		}
		return ret;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	uli r, c;
	cin >> r >> c;

	vector<vuli> rows(r), cols(c);
	vulli rowBitmasks(r, 0), colBitmasks(c, 0);

	loop(0, r, i)
	{
		uli k;
		cin >> k;
		loop(0, k, j)
		{
			uli clue;
			cin >> clue;
			rows[i].push_back(clue);
		}
	}
	loop(0, c, i)
	{
		uli k;
		cin >> k;
		loop(0, k, j)
		{
			uli clue;
			cin >> clue;
			cols[i].push_back(clue);
		}
	}

	vector<vuli> rowPs(r), colPs(c);

	loop(0, r, i)
	{
		phase1(rowPs[i], rowBitmasks[i], rows[i], c);
	}
	loop(0, c, i)
	{
		phase1(colPs[i], colBitmasks[i], cols[i], r);
	}

	unordered_set<vuli, vecHash> all;
	for (uli rowIdx = 0; rowIdx < r; rowIdx++)
	{
		vector<vector<vuli>> pre(rowPs[rowIdx].size(), vector<vuli>(c));
		loop(0, rowPs[rowIdx].size(), i)
		{
			uli rowP = rowPs[rowIdx][i];
			for (uli colIdx = 0; colIdx < c; colIdx++)
			{
				loop(0, colPs[colIdx].size(), j)
				{
					uli colP = colPs[colIdx][j];
					if (static_cast<bool>(rowP & 1 << colIdx) == static_cast<bool>(colP & 1 << rowIdx))
					{
						pre[i][colIdx].push_back(j);
					}
				}
			}
		}

		if (rowIdx == 0)
		{
			for (const vector<vuli>& preElem : pre)
			{
				bool skip = false;
				loop(0, c, i)
				{
					if (preElem[i].size() == 0)
					{
						skip = true;
						break;
					}
				}
				if (skip)
				{
					continue;
				}
				vuli indices(c + 1, 0);
				bool overflow = false;
				while (!overflow)
				{
					vuli vec(c);
					loop(0, c, i)
					{
						vec[i] = preElem[i][indices[i]];
					}
					all.insert(vec);
					overflow = true;
					loop(0, c, i)
					{
						indices[i]++;
						if (indices[i] == preElem[i].size())
						{
							indices[i] = 0;
						}
						else
						{
							overflow = false;
							break;
						}
					}
				}
			}
		}
		else
		{
			unordered_set<vuli, vecHash> newAll;
			for (const vector<vuli>& preElem : pre)
			{
				bool skip = false;
				loop(0, c, i)
				{
					if (preElem[i].size() == 0)
					{
						skip = true;
						break;
					}
				}
				if (skip)
				{
					continue;
				}
				vuli indices(c + 1, 0);
				bool overflow = false;
				while (!overflow)
				{
					vuli vec(c);
					loop(0, c, i)
					{
						vec[i] = preElem[i][indices[i]];
					}
					if (all.find(vec) != all.end())
					{
						newAll.insert(vec);
					}
					overflow = true;
					loop(0, c, i)
					{
						indices[i]++;
						if (indices[i] == preElem[i].size())
						{
							indices[i] = 0;
						}
						else
						{
							overflow = false;
							break;
						}
					}
				}
			}
			swap(all, newAll);
		}
	}
	cout << all.size();
}


//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	uli r, c;
//	cin >> r >> c;
//
//	switch (r)
//	{
//	case 1:
//		switch (c)
//		{
//		case 1:
//			runner<1, 1>().run();
//			break;
//		case 2:
//			runner<1, 2>().run();
//			break;
//		case 3:
//			runner<1, 3>().run();
//			break;
//		case 4:
//			runner<1, 4>().run();
//			break;
//		case 5:
//			runner<1, 5>().run();
//			break;
//		case 6:
//			runner<1, 6>().run();
//			break;
//		}
//		break;
//	case 2:
//		switch (c)
//		{
//		case 1:
//			runner<2, 1>().run();
//			break;
//		case 2:
//			runner<2, 2>().run();
//			break;
//		case 3:
//			runner<2, 3>().run();
//			break;
//		case 4:
//			runner<2, 4>().run();
//			break;
//		case 5:
//			runner<2, 5>().run();
//			break;
//		case 6:
//			runner<2, 6>().run();
//			break;
//		}
//		break;
//	case 3:
//		switch (c)
//		{
//		case 1:
//			runner<3, 1>().run();
//			break;
//		case 2:
//			runner<3, 2>().run();
//			break;
//		case 3:
//			runner<3, 3>().run();
//			break;
//		case 4:
//			runner<3, 4>().run();
//			break;
//		case 5:
//			runner<3, 5>().run();
//			break;
//		case 6:
//			runner<3, 6>().run();
//			break;
//		}
//		break;
//	case 4:
//		switch (c)
//		{
//		case 1:
//			runner<4, 1>().run();
//			break;
//		case 2:
//			runner<4, 2>().run();
//			break;
//		case 3:
//			runner<4, 3>().run();
//			break;
//		case 4:
//			runner<4, 4>().run();
//			break;
//		case 5:
//			runner<4, 5>().run();
//			break;
//		case 6:
//			runner<4, 6>().run();
//			break;
//		}
//		break;
//	case 5:
//		switch (c)
//		{
//		case 1:
//			runner<5, 1>().run();
//			break;
//		case 2:
//			runner<5, 2>().run();
//			break;
//		case 3:
//			runner<5, 3>().run();
//			break;
//		case 4:
//			runner<5, 4>().run();
//			break;
//		case 5:
//			runner<5, 5>().run();
//			break;
//		case 6:
//			runner<5, 6>().run();
//			break;
//		}
//		break;
//	case 6:
//		switch (c)
//		{
//		case 1:
//			runner<6, 1>().run();
//			break;
//		case 2:
//			runner<6, 2>().run();
//			break;
//		case 3:
//			runner<6, 3>().run();
//			break;
//		case 4:
//			runner<6, 4>().run();
//			break;
//		case 5:
//			runner<6, 5>().run();
//			break;
//		case 6:
//			runner<6, 6>().run();
//			break;
//		}
//		break;
//	}
//
//	return 0;
//}