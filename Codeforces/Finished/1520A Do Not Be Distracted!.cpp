#ifndef EMBAILEY_TEMPLATE
#define EMBAILEY_TEMPLATE

#include <cstring>
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
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
	return value & 0xffffffff00000000ull ? __lzcnt(static_cast<unsigned long int>(value >> 32)) : 32 + __lzcnt(static_cast<unsigned long int>(value));
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

#define tCases() uli testCaseCount; cin >> testCaseCount; for (uli testCaseIndex = 0; testCaseIndex < testCaseCount; testCaseIndex++)

//#define endl '\n'

using namespace std;

typedef bool                       bi;
typedef char                       ci;
typedef unsigned char              uci;
typedef short                      si;
typedef unsigned short             usi;
typedef int                        li;
typedef unsigned                   uli;
typedef long long                  lli;
typedef unsigned long long         ulli;
typedef float                      sf;
typedef double                     df;
typedef long double                ldf;

typedef pair<bi, bi>               pbi;
typedef pair<ci, ci>               pci;
typedef pair<uci, uci>             puci;
typedef pair<si, si>               psi;
typedef pair<usi, usi>             pusi;
typedef pair<li, li>               pli;
typedef pair<uli, uli>             puli;
typedef pair<lli, lli>             plli;
typedef pair<ulli, ulli>           pulli;
typedef pair<sf, sf>               psf;
typedef pair<df, df>               pdf;
typedef pair<ldf, ldf>             pldf;

typedef vector<bi>                 vbi;
typedef vector<ci>                 vci;
typedef vector<uci>                vuci;
typedef vector<si>                 vsi;
typedef vector<usi>                vusi;
typedef vector<li>                 vli;
typedef vector<uli>                vuli;
typedef vector<lli>                vlli;
typedef vector<ulli>               vulli;
typedef vector<sf>                 vsf;
typedef vector<df>                 vdf;
typedef vector<ldf>                vldf;

typedef vector<pbi>                vpbi;
typedef vector<pci>                vpci;
typedef vector<puci>               vpuci;
typedef vector<psi>                vpsi;
typedef vector<pusi>               vpusi;
typedef vector<pli>                vpli;
typedef vector<puli>               vpuli;
typedef vector<plli>               vplli;
typedef vector<pulli>              vpulli;
typedef vector<psf>                vpsf;
typedef vector<pdf>                vpdf;
typedef vector<pldf>               vpldf;

typedef vector<vbi>                vvbi;
typedef vector<vci>                vvci;
typedef vector<vuci>               vvuci;
typedef vector<vsi>                vvsi;
typedef vector<vusi>               vvusi;
typedef vector<vli>                vvli;
typedef vector<vuli>               vvuli;
typedef vector<vlli>               vvlli;
typedef vector<vulli>              vvulli;
typedef vector<vsf>                vvsf;
typedef vector<vdf>                vvdf;
typedef vector<vldf>               vvldf;

typedef vector<vpbi>               vvpbi;
typedef vector<vpci>               vvpci;
typedef vector<vpuci>              vvpuci;
typedef vector<vpsi>               vvpsi;
typedef vector<vpusi>              vvpusi;
typedef vector<vpli>               vvpli;
typedef vector<vpuli>              vvpuli;
typedef vector<vplli>              vvplli;
typedef vector<vpulli>             vvpulli;
typedef vector<vpsf>               vvpsf;
typedef vector<vpdf>               vvpdf;
typedef vector<vpldf>              vvpldf;

typedef forward_list<bi>           l1bi;
typedef forward_list<ci>           l1ci;
typedef forward_list<uci>          l1uci;
typedef forward_list<si>           l1si;
typedef forward_list<usi>          l1usi;
typedef forward_list<li>           l1li;
typedef forward_list<uli>          l1uli;
typedef forward_list<lli>          l1lli;
typedef forward_list<ulli>         l1ulli;
typedef forward_list<sf>           l1sf;
typedef forward_list<df>           l1df;
typedef forward_list<ldf>          l1ldf;

typedef forward_list<pbi>          l1pbi;
typedef forward_list<pci>          l1pci;
typedef forward_list<puci>         l1puci;
typedef forward_list<psi>          l1psi;
typedef forward_list<pusi>         l1pusi;
typedef forward_list<pli>          l1pli;
typedef forward_list<puli>         l1puli;
typedef forward_list<plli>         l1plli;
typedef forward_list<pulli>        l1pulli;
typedef forward_list<psf>          l1psf;
typedef forward_list<pdf>          l1pdf;
typedef forward_list<pldf>         l1pldf;

typedef list<bi>                   l2bi;
typedef list<ci>                   l2ci;
typedef list<uci>                  l2uci;
typedef list<si>                   l2si;
typedef list<usi>                  l2usi;
typedef list<li>                   l2li;
typedef list<uli>                  l2uli;
typedef list<lli>                  l2lli;
typedef list<ulli>                 l2ulli;
typedef list<sf>                   l2sf;
typedef list<df>                   l2df;
typedef list<ldf>                  l2ldf;

typedef list<pbi>                  l2pbi;
typedef list<pci>                  l2pci;
typedef list<puci>                 l2puci;
typedef list<psi>                  l2psi;
typedef list<pusi>                 l2pusi;
typedef list<pli>                  l2pli;
typedef list<puli>                 l2puli;
typedef list<plli>                 l2plli;
typedef list<pulli>                l2pulli;
typedef list<psf>                  l2psf;
typedef list<pdf>                  l2pdf;
typedef list<pldf>                 l2pldf;

typedef set<bi>                    sbi;
typedef set<ci>                    sci;
typedef set<uci>                   suci;
typedef set<si>                    ssi;
typedef set<usi>                   susi;
typedef set<li>                    sli;
typedef set<uli>                   suli;
typedef set<lli>                   slli;
typedef set<ulli>                  sulli;
typedef set<sf>                    ssf;
typedef set<df>                    sdf;
typedef set<ldf>                   sldf;

typedef set<pbi>                   spbi;
typedef set<pci>                   spci;
typedef set<puci>                  spuci;
typedef set<psi>                   spsi;
typedef set<pusi>                  spusi;
typedef set<pli>                   spli;
typedef set<puli>                  spuli;
typedef set<plli>                  splli;
typedef set<pulli>                 spulli;
typedef set<psf>                   spsf;
typedef set<pdf>                   spdf;
typedef set<pldf>                  spldf;

typedef multiset<bi>               msbi;
typedef multiset<ci>               msci;
typedef multiset<uci>              msuci;
typedef multiset<si>               mssi;
typedef multiset<usi>              msusi;
typedef multiset<li>               msli;
typedef multiset<uli>              msuli;
typedef multiset<lli>              mslli;
typedef multiset<ulli>             msulli;
typedef multiset<sf>               mssf;
typedef multiset<df>               msdf;
typedef multiset<ldf>              msldf;

typedef multiset<pbi>              mspbi;
typedef multiset<pci>              mspci;
typedef multiset<puci>             mspuci;
typedef multiset<psi>              mspsi;
typedef multiset<pusi>             mspusi;
typedef multiset<pli>              mspli;
typedef multiset<puli>             mspuli;
typedef multiset<plli>             msplli;
typedef multiset<pulli>            mspulli;
typedef multiset<psf>              mspsf;
typedef multiset<pdf>              mspdf;
typedef multiset<pldf>             mspldf;

typedef unordered_multiset<bi>     umsbi;
typedef unordered_multiset<ci>     umsci;
typedef unordered_multiset<uci>    umsuci;
typedef unordered_multiset<si>     umssi;
typedef unordered_multiset<usi>    umsusi;
typedef unordered_multiset<li>     umsli;
typedef unordered_multiset<uli>    umsuli;
typedef unordered_multiset<lli>    umslli;
typedef unordered_multiset<ulli>   umsulli;
typedef unordered_multiset<sf>     umssf;
typedef unordered_multiset<df>     umsdf;
typedef unordered_multiset<ldf>    umsldf;

typedef unordered_multiset<pbi>    umspbi;
typedef unordered_multiset<pci>    umspci;
typedef unordered_multiset<puci>   umspuci;
typedef unordered_multiset<psi>    umspsi;
typedef unordered_multiset<pusi>   umspusi;
typedef unordered_multiset<pli>    umspli;
typedef unordered_multiset<puli>   umspuli;
typedef unordered_multiset<plli>   umsplli;
typedef unordered_multiset<pulli>  umspulli;
typedef unordered_multiset<psf>    umspsf;
typedef unordered_multiset<pdf>    umspdf;
typedef unordered_multiset<pldf>   umspldf;

typedef unordered_set<bi>          usbi;
typedef unordered_set<ci>          usci;
typedef unordered_set<uci>         usuci;
typedef unordered_set<si>          ussi;
typedef unordered_set<usi>         ususi;
typedef unordered_set<li>          usli;
typedef unordered_set<uli>         usuli;
typedef unordered_set<lli>         uslli;
typedef unordered_set<ulli>        usulli;
typedef unordered_set<sf>          ussf;
typedef unordered_set<df>          usdf;
typedef unordered_set<ldf>         usldf;

typedef unordered_set<pbi>         uspbi;
typedef unordered_set<pci>         uspci;
typedef unordered_set<puci>        uspuci;
typedef unordered_set<psi>         uspsi;
typedef unordered_set<pusi>        uspusi;
typedef unordered_set<pli>         uspli;
typedef unordered_set<puli>        uspuli;
typedef unordered_set<plli>        usplli;
typedef unordered_set<pulli>       uspulli;
typedef unordered_set<psf>         uspsf;
typedef unordered_set<pdf>         uspdf;
typedef unordered_set<pldf>        uspldf;

typedef stack<bi>                  stbi;
typedef stack<ci>                  stci;
typedef stack<uci>                 stuci;
typedef stack<si>                  stsi;
typedef stack<usi>                 stusi;
typedef stack<li>                  stli;
typedef stack<uli>                 stuli;
typedef stack<lli>                 stlli;
typedef stack<ulli>                stulli;
typedef stack<sf>                  stsf;
typedef stack<df>                  stdf;
typedef stack<ldf>                 stldf;

typedef stack<pbi>                 stpbi;
typedef stack<pci>                 stpci;
typedef stack<puci>                stpuci;
typedef stack<psi>                 stpsi;
typedef stack<pusi>                stpusi;
typedef stack<pli>                 stpli;
typedef stack<puli>                stpuli;
typedef stack<plli>                stplli;
typedef stack<pulli>               stpulli;
typedef stack<psf>                 stpsf;
typedef stack<pdf>                 stpdf;
typedef stack<pldf>                stpldf;

typedef queue<bi>                  qbi;
typedef queue<ci>                  qci;
typedef queue<uci>                 quci;
typedef queue<si>                  qsi;
typedef queue<usi>                 qusi;
typedef queue<li>                  qli;
typedef queue<uli>                 quli;
typedef queue<lli>                 qlli;
typedef queue<ulli>                qulli;
typedef queue<sf>                  qsf;
typedef queue<df>                  qdf;
typedef queue<ldf>                 qldf;

typedef queue<pbi>                 qpbi;
typedef queue<pci>                 qpci;
typedef queue<puci>                qpuci;
typedef queue<psi>                 qpsi;
typedef queue<pusi>                qpusi;
typedef queue<pli>                 qpli;
typedef queue<puli>                qpuli;
typedef queue<plli>                qplli;
typedef queue<pulli>               qpulli;
typedef queue<psf>                 qpsf;
typedef queue<pdf>                 qpdf;
typedef queue<pldf>                qpldf;

typedef deque<bi>                  dbi;
typedef deque<ci>                  dci;
typedef deque<uci>                 duci;
typedef deque<si>                  dsi;
typedef deque<usi>                 dusi;
typedef deque<li>                  dli;
typedef deque<uli>                 duli;
typedef deque<lli>                 dlli;
typedef deque<ulli>                dulli;
typedef deque<sf>                  dsf;
typedef deque<df>                  ddf;
typedef deque<ldf>                 dldf;

typedef deque<pbi>                 dpbi;
typedef deque<pci>                 dpci;
typedef deque<puci>                dpuci;
typedef deque<psi>                 dpsi;
typedef deque<pusi>                dpusi;
typedef deque<pli>                 dpli;
typedef deque<puli>                dpuli;
typedef deque<plli>                dplli;
typedef deque<pulli>               dpulli;
typedef deque<psf>                 dpsf;
typedef deque<pdf>                 dpdf;
typedef deque<pldf>                dpldf;

typedef priority_queue<bi>         pqbi;
typedef priority_queue<ci>         pqci;
typedef priority_queue<uci>        pquci;
typedef priority_queue<si>         pqsi;
typedef priority_queue<usi>        pqusi;
typedef priority_queue<li>         pqli;
typedef priority_queue<uli>        pquli;
typedef priority_queue<lli>        pqlli;
typedef priority_queue<ulli>       pqulli;
typedef priority_queue<sf>         pqsf;
typedef priority_queue<df>         pqdf;
typedef priority_queue<ldf>        pqldf;

typedef priority_queue<pbi>        pqpbi;
typedef priority_queue<pci>        pqpci;
typedef priority_queue<puci>       pqpuci;
typedef priority_queue<psi>        pqpsi;
typedef priority_queue<pusi>       pqpusi;
typedef priority_queue<pli>        pqpli;
typedef priority_queue<puli>       pqpuli;
typedef priority_queue<plli>       pqplli;
typedef priority_queue<pulli>      pqpulli;
typedef priority_queue<psf>        pqpsf;
typedef priority_queue<pdf>        pqpdf;
typedef priority_queue<pldf>       pqpldf;

template<class T, class Container = vector<T>>
using max_heap = priority_queue<T, Container, less<T>>;

template<class T, class Container = vector<T>>
using min_heap = priority_queue<T, Container, greater<T>>;

#define MIN(T) (numeric_limits<T>::min())
#define MAX(T) (numeric_limits<T>::max())
#define INF(T) (numeric_limits<T>::infinity())

// Based partially on:
// https://codeforces.com/blog/entry/74684
#define ALL(c) (c).begin(), (c).end()
#define CALL(c) (c).cbegin(), (c).cend()
#define RALL(c) (c).rbegin(), (c).rend()
#define CRALL(c) (c).crbegin(), (c).crend()

#define CONTAINS(c, x) ((c).find(x) != (c).end())

template<size_t I>
struct TupleReadHelper
{
	template<typename... Ts>
	static inline void read(tuple<Ts...>& c, istream& strm);
	template<typename... Ts>
	static inline void read(tuple<Ts&...>&& c, istream& strm);
};

template<>
struct TupleReadHelper<0>
{
	template<typename... Ts>
	static inline void read(tuple<Ts...>& c, istream& strm) {}
	template<typename... Ts>
	static inline void read(tuple<Ts&...>&& c, istream& strm) {}
};

template<size_t I>
struct TupleReadNHelper
{
	template<typename... Ts>
	static inline void read(tuple<Ts...>& t, istream& strm);
	template<typename... Ts, typename... S>
	static inline void read(tuple<Ts...>& t, istream& strm, size_t n, S... s);
};

template<>
struct TupleReadNHelper<0>
{
	template<typename... Ts, typename... S>
	static inline void read(tuple<Ts...>&, istream& strm, S...) {}
};

template<typename Iter>
inline void read_rng(Iter first, Iter last);
template<typename Iter>
inline void read_rng(Iter first, Iter last, istream& strm);

template<typename T>
inline void read(T& t, istream& strm)
{
	strm >> t;
}

template<typename T, typename U>
inline void read(pair<T, U>& c, istream& strm)
{
	read(c.first, strm);
	read(c.second, strm);
}

template<typename... Ts>
inline void read(tuple<Ts...>& c, istream& strm)
{
	TupleReadHelper<tuple_size<tuple<Ts...>>::value>::read(c, strm);
}

template<typename... Ts>
inline void read(tuple<Ts&...>&& c, istream& strm)
{
	TupleReadHelper<tuple_size<tuple<Ts...>>::value>::read(c, strm);
}

template<typename T, size_t Size>
inline void read(array<T, Size>& c, istream& strm)
{
	read_rng(ALL(c), strm);
}

template<typename T, typename Alloc>
inline void read(vector<T, Alloc>& c, istream& strm)
{
	read_rng(ALL(c), strm);
}

template<typename T, typename Alloc>
inline void read(deque<T, Alloc>& c, istream& strm)
{
	read_rng(ALL(c), strm);
}

template<typename T, typename Alloc>
inline void read(list<T, Alloc>& c, istream& strm)
{
	read_rng(ALL(c), strm);
}

template<typename T, typename Alloc>
inline void read(forward_list<T, Alloc>& c, istream& strm)
{
	read_rng(ALL(c), strm);
}

template<typename T>
inline void read(T t)
{
	read(t, cin);
}

template<size_t I>
template<typename... Ts>
inline void TupleReadHelper<I>::read(tuple<Ts...>& c, istream& strm)
{
	TupleReadHelper<I - 1>::read(c, strm);
	::read(get<I - 1>(c), strm);
}

template<size_t I>
template<typename... Ts>
inline void TupleReadHelper<I>::read(tuple<Ts&...>&& c, istream& strm)
{
	TupleReadHelper<I - 1>::read(c, strm);
	::read(get<I - 1>(c), strm);
}

template<typename T>
inline T readr(istream& strm)
{
	T t;
	::read(t, strm);
	return t;
}

template<typename T>
inline T readr()
{
	return readr<T>(cin);
}

template<typename Iter>
inline void read_rng(Iter first, Iter last, istream& strm)
{
	while (first != last)
		read(*(first++), strm);
}

template<typename T>
struct ReadNHelper
{
	static inline T read(istream& strm)
	{
		return ::readr<T>();
	}

	template<typename... S>
	static inline T read(istream& strm, size_t n, S... s)
	{
		return ReadNHelper<T>::read(strm, s...);
	}
};

template<typename T, typename U>
struct ReadNHelper<pair<T, U>>
{
	static inline pair<T, U> read(istream& strm)
	{
		pair<T, U> c;
		c.first = ReadNHelper<T>::read(strm);
		c.second = ReadNHelper<U>::read(strm);
		return c;
	}

	template<typename... S>
	static inline pair<T, U> read(istream& strm, size_t n, S... s)
	{
		pair<T, U> c;
		c.first = ReadNHelper<T>::read(strm, s...);
		c.second = ReadNHelper<U>::read(strm, s...);
		return c;
	}
};

template<typename... Ts>
struct ReadNHelper<tuple<Ts...>>
{
	static inline tuple<Ts...> read(istream& strm)
	{
		tuple<Ts...> c;
		TupleReadNHelper<tuple_size<tuple<Ts...>>::value>::read(c, strm);
		return c;
	}

	template<typename... S>
	static inline tuple<Ts...> read(istream& strm, size_t n, S... s)
	{
		tuple<Ts...> c;
		TupleReadNHelper<tuple_size<tuple<Ts...>>::value>::read(c, strm, n, s...);
		return c;
	}
};

template<typename T, size_t Size>
struct ReadNHelper<array<T, Size>>
{
	static inline array<T, Size> read(istream& strm)
	{
		array<T, Size> c;
		for (size_t i = Size; i--;) c[i] = ReadNHelper<T>::read(strm);
		return c;
	}

	template<typename... S>
	static inline array<T, Size> read(istream& strm, size_t n, S... s)
	{
		array<T, Size> c;
		for (size_t i = Size; i--;) c[i] = ReadNHelper<T>::read(strm, s...);
		return c;
	}
};

template<typename T, typename Alloc>
struct ReadNHelper<vector<T, Alloc>>
{
	static inline vector<T, Alloc> read(istream& strm)
	{
		//static_assert(false, "size needed for read_n<vector>.");
	}

	template<typename... S>
	static inline vector<T, Alloc> read(istream& strm, size_t n, S... s)
	{
		vector<T, Alloc> c;
		c.reserve(n);
		while (n--) c.push_back(ReadNHelper<T>::read(strm, s...));
		return c;
	}
};

template<typename T, typename Alloc>
struct ReadNHelper<deque<T, Alloc>>
{
	static inline deque<T, Alloc> read(istream& strm)
	{
		//static_assert(false, "size needed for read_n<deque>.");
	}

	template<typename... S>
	static inline deque<T, Alloc> read(istream& strm, size_t n, S... s)
	{
		deque<T, Alloc> c;
		while (n--) c.push_back(ReadNHelper<T>::read(strm, s...));
		return c;
	}
};

template<typename T, typename Alloc>
struct ReadNHelper<list<T, Alloc>>
{
	static inline list<T, Alloc> read(istream& strm)
	{
		//static_assert(false, "size needed for read_n<list>.");
	}

	template<typename... S>
	static inline list<T, Alloc> read(istream& strm, size_t n, S... s)
	{
		list<T, Alloc> c;
		while (n--) c.push_back(ReadNHelper<T>::read(strm, s...));
		return c;
	}
};

template<typename T, typename Alloc>
struct ReadNHelper<forward_list<T, Alloc>>
{
	static inline forward_list<T, Alloc> read(istream& strm)
	{
		//static_assert(false, "size needed for read_n<forward_list>.");
	}

	template<typename... S>
	static inline forward_list<T, Alloc> read(istream& strm, size_t n, S... s)
	{
		forward_list<T, Alloc> c;
		typename forward_list<T, Alloc>::const_iterator itr = c.cbefore_begin();
		while (n--)
		{
			c.insert_after(itr, ReadNHelper<T>::read(strm, s...));
			itr++;
		}
		return c;
	}
};

template<typename T, typename Pr, typename Alloc>
struct ReadNHelper<set<T, Pr, Alloc>>
{
	static inline set<T, Pr, Alloc> read(istream& strm)
	{
		//static_assert(false, "size needed for read_n<set>.");
	}

	template<typename... S>
	static inline set<T, Pr, Alloc> read(istream& strm, size_t n, S... s)
	{
		set<T, Pr, Alloc> c;
		while (n--) c.insert(ReadNHelper<T>::read(strm, s...));
		return c;
	}
};

template<typename T, typename Pr, typename Alloc>
struct ReadNHelper<multiset<T, Pr, Alloc>>
{
	static inline multiset<T, Pr, Alloc> read(istream& strm)
	{
		//static_assert(false, "size needed for read_n<multiset>.");
	}

	template<typename... S>
	static inline multiset<T, Pr, Alloc> read(istream& strm, size_t n, S... s)
	{
		multiset<T, Pr, Alloc> c;
		while (n--) c.insert(ReadNHelper<T>::read(strm, s...));
		return c;
	}
};

template<typename T, typename Hash, typename Eq, typename Alloc>
struct ReadNHelper<unordered_set<T, Hash, Eq, Alloc>>
{
	static inline unordered_set<T, Hash, Eq, Alloc> read(istream& strm)
	{
		//static_assert(false, "size needed for read_n<unordered_set>.");
	}

	template<typename... S>
	static inline unordered_set<T, Hash, Eq, Alloc> read(istream& strm, size_t n, S... s)
	{
		unordered_set<T, Hash, Eq, Alloc> c;
		while (n--) c.insert(ReadNHelper<T>::read(strm, s...));
		return c;
	}
};

template<typename T, typename Hash, typename Eq, typename Alloc>
struct ReadNHelper<unordered_multiset<T, Hash, Eq, Alloc>>
{
	static inline unordered_multiset<T, Hash, Eq, Alloc> read(istream& strm)
	{
		//static_assert(false, "size needed for read_n<unordered_multiset>.");
	}

	template<typename... S>
	static inline unordered_multiset<T, Hash, Eq, Alloc> read(istream& strm, size_t n, S... s)
	{
		unordered_multiset<T, Hash, Eq, Alloc> c;
		while (n--) c.insert(ReadNHelper<T>::read(strm, s...));
		return c;
	}
};

template<typename K, typename V, typename Pr, typename Alloc>
struct ReadNHelper<map<K, V, Pr, Alloc>>
{
	static inline map<K, V, Pr, Alloc> read(istream& strm)
	{
		//static_assert(false, "size needed for read_n<map>.");
	}

	template<typename... S>
	static inline map<K, V, Pr, Alloc> read(istream& strm, size_t n, S... s)
	{
		map<K, V, Pr, Alloc> c;
		while (n--) c.insert(ReadNHelper<pair<K, V>>::read(strm, s...));
		return c;
	}
};

template<typename K, typename V, typename Pr, typename Alloc>
struct ReadNHelper<multimap<K, V, Pr, Alloc>>
{
	static inline multimap<K, V, Pr, Alloc> read(istream& strm)
	{
		//static_assert(false, "size needed for read_n<multimap>.");
	}

	template<typename... S>
	static inline multimap<K, V, Pr, Alloc> read(istream& strm, size_t n, S... s)
	{
		multimap<K, V, Pr, Alloc> c;
		while (n--) c.insert(ReadNHelper<pair<K, V>>::read(strm, s...));
		return c;
	}
};

template<typename K, typename V, typename Hash, typename Eq, typename Alloc>
struct ReadNHelper<unordered_map<K, V, Hash, Eq, Alloc>>
{
	static inline unordered_map<K, V, Hash, Eq, Alloc> read(istream& strm)
	{
		//static_assert(false, "size needed for read_n<unordered_map>.");
	}

	template<typename... S>
	static inline unordered_map<K, V, Hash, Eq, Alloc> read(istream& strm, size_t n, S... s)
	{
		unordered_map<K, V, Hash, Eq, Alloc> c;
		while (n--) c.insert(ReadNHelper<pair<K, V>>::read(strm, s...));
		return c;
	}
};

template<typename K, typename V, typename Hash, typename Eq, typename Alloc>
struct ReadNHelper<unordered_multimap<K, V, Hash, Eq, Alloc>>
{
	static inline unordered_multimap<K, V, Hash, Eq, Alloc> read(istream& strm)
	{
		//static_assert(false, "size needed for read_n<unordered_multimap>.");
	}

	template<typename... S>
	static inline unordered_multimap<K, V, Hash, Eq, Alloc> read(istream& strm, size_t n, S... s)
	{
		unordered_multimap<K, V, Hash, Eq, Alloc> c;
		while (n--) c.insert(ReadNHelper<pair<K, V>>::read(strm, s...));
		return c;
	}
};

template<typename T>
inline T read_n()
{
	return ReadNHelper<T>::read(cin);
}

template<typename T, typename... S>
inline T read_n(size_t size0, S... sizes)
{
	return ReadNHelper<T>::read(std::cin, size0, sizes...);
}

template<typename T, typename... S>
inline T read_n(istream& strm, S... sizes)
{
	return ReadNHelper<T>::read(strm, sizes...);
}

template<size_t I>
template<typename... Ts>
inline void TupleReadNHelper<I>::read(tuple<Ts...>& t, istream& strm)
{
	TupleReadNHelper<I - 1>::read(t, strm);
	typedef typename tuple_element<I - 1, tuple<Ts...>>::type Type;
	get<I - 1>(t) = ReadNHelper<Type>::read(strm);
}

template<size_t I>
template<typename... Ts, typename... S>
inline void TupleReadNHelper<I>::read(tuple<Ts...>& t, istream& strm, size_t n, S... s)
{
	TupleReadNHelper<I - 1>::read(t, strm, n, s...);
	typedef typename tuple_element<I - 1, tuple<Ts...>>::type Type;
	get<I - 1>(t) = ReadNHelper<Type>::read(strm, s...);
}

template<size_t Depth, size_t I>
struct TupleWriteHelper
{
	template<typename... Ts, typename Delim0, typename... Delims>
	static inline void write(const tuple<Ts...>& c, ostream& strm, const tuple<Delim0, Delims...>& delims);
	template<typename... Ts>
	static inline void write(const tuple<Ts...>& c, ostream& strm);
	template<typename... Ts, typename Delim0, typename... Delims>
	static inline void write(tuple<Ts&...>&& c, ostream& strm, const tuple<Delim0, Delims...>& delims);
	template<typename... Ts>
	static inline void write(tuple<Ts&...>&& c, ostream& strm);
};

template<size_t Depth>
struct TupleWriteHelper<Depth, 0>
{
	template<typename... Ts, typename Delim0, typename... Delims>
	static inline void write(const tuple<Ts...>& c, ostream& strm, const tuple<Delim0, Delims...>& delims) {}
	template<typename... Ts>
	static inline void write(const tuple<Ts...>& c, ostream& strm) {}
};

template<size_t Depth = 0, typename Iter, typename Delim0, typename... Delims>
inline void write_rng(Iter first, Iter last, ostream& strm, const tuple<Delim0, Delims...>& delims);

template<typename Iter>
inline void write_rng(Iter first, Iter last, ostream& strm);

template<typename T>
inline void write(const T& t, ostream& strm)
{
	strm << t;
}

template<size_t Depth, typename T, typename Delim0, typename... Delims>
inline void write_tdelim(const T& t, ostream& strm, const tuple<Delim0, Delims...>&)
{
	write(t, strm);
}

// TODO pass strm recursively

template<typename T, typename U>
inline void write(const pair<T, U>& c, ostream& strm)
{
	write(c.first, strm);
	write(c.second, strm);
}

template<size_t Depth, typename T, typename U, typename Delim0, typename... Delims>
inline void write_tdelim(const pair<T, U>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	constexpr bool hasDelim = Depth < tuple_size<tuple<Delim0, Delims...>>::value;
	constexpr size_t safeDepth = hasDelim ? Depth : 0;
	if (hasDelim)
	{
		write_tdelim<Depth + 1>(c.first, strm, delims);
		write(get<safeDepth>(delims), strm);
		write_tdelim<Depth + 1>(c.second, strm, delims);
	}
	else
	{
		write(c.first, strm);
		write(c.second, strm);
	}
}

template<typename... Ts>
inline void write(const tuple<Ts...>& c, ostream& strm)
{
	TupleWriteHelper<0, tuple_size<tuple<Ts...>>::value>::write(c);
}

template<size_t Depth, typename... Ts, typename Delim0, typename... Delims>
inline void write_tdelim(const tuple<Ts...>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	TupleWriteHelper<Depth, tuple_size<tuple<Ts...>>::value>::write(c, strm, delims);
}

template<typename... Ts>
inline void write(tuple<Ts&...>&& c, ostream& strm)
{
	TupleWriteHelper<0, tuple_size<tuple<Ts...>>::value>::write(c);
}

template<size_t Depth, typename... Ts, typename Delim0, typename... Delims>
inline void write_tdelim(tuple<Ts&...>&& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	TupleWriteHelper<Depth, tuple_size<tuple<Ts...>>::value>::write(c, delims);
}

template<typename T>
inline void write(const initializer_list<T>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Delim0, typename... Delims>
inline void write_tdelim(const initializer_list<T>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, size_t Size>
inline void write(const array<T, Size>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, size_t Size, typename Delim0, typename... Delims>
inline void write_tdelim(const array<T, Size>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Alloc>
inline void write(const vector<T, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Alloc, typename Delim0, typename... Delims>
inline void write_tdelim(const vector<T, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Alloc>
inline void write(const deque<T, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Alloc, typename Delim0, typename... Delims>
inline void write_tdelim(const deque<T, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Alloc>
inline void write(const list<T, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Alloc, typename Delim0, typename... Delims>
inline void write_tdelim(const list<T, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Alloc>
inline void write(const forward_list<T, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Alloc, typename Delim0, typename... Delims>
inline void write_tdelim(const forward_list<T, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Pr, typename Alloc>
inline void write(const set<T, Pr, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Pr, typename Alloc, typename Delim0, typename... Delims>
inline void write_tdelim(const set<T, Pr, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Pr, typename Alloc>
inline void write(const multiset<T, Pr, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Pr, typename Alloc, typename Delim0, typename... Delims>
inline void write_tdelim(const multiset<T, Pr, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Hash, typename Eq, typename Alloc>
inline void write(const unordered_set<T, Hash, Eq, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Hash, typename Eq, typename Alloc, typename Delim0, typename... Delims>
inline void write_tdelim(const unordered_set<T, Hash, Eq, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Hash, typename Eq, typename Alloc>
inline void write(const unordered_multiset<T, Hash, Eq, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Hash, typename Eq, typename Alloc, typename Delim0, typename... Delims>
inline void write_tdelim(const unordered_multiset<T, Hash, Eq, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename K, typename V, typename Pr, typename Alloc>
inline void write(const map<K, V, Pr, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename K, typename V, typename Pr, typename Alloc, typename Delim0, typename... Delims>
inline void write_tdelim(const map<K, V, Pr, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename K, typename V, typename Pr, typename Alloc>
inline void write(const multimap<K, V, Pr, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename K, typename V, typename Pr, typename Alloc, typename Delim0, typename... Delims>
inline void write_tdelim(const multimap<K, V, Pr, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename K, typename V, typename Hash, typename Eq, typename Alloc>
inline void write(const unordered_map<K, V, Hash, Eq, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename K, typename V, typename Hash, typename Eq, typename Alloc, typename Delim0, typename... Delims>
inline void write_tdelim(const unordered_map<K, V, Hash, Eq, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename K, typename V, typename Hash, typename Eq, typename Alloc>
inline void write(const unordered_multimap<K, V, Hash, Eq, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename K, typename V, typename Hash, typename Eq, typename Alloc, typename Delim0, typename... Delims>
inline void write_tdelim(const unordered_multimap<K, V, Hash, Eq, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<size_t Depth, size_t I>
template<typename... Ts, typename Delim0, typename... Delims>
inline void TupleWriteHelper<Depth, I>::write(const tuple<Ts...>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	constexpr bool hasDelim = Depth < tuple_size<tuple<Delim0, Delims...>>::value;
	constexpr size_t safeDepth = hasDelim ? Depth : 0;
	TupleWriteHelper<Depth, I - 1>::write(c, strm, delims);
	write_tdelim<Depth + 1>(get<I - 1>(c), strm, delims);
	if (hasDelim && I < tuple_size<tuple<Ts...>>::value) ::write(get<safeDepth>(delims), strm);
}

template<size_t Depth, size_t I>
template<typename... Ts>
inline void TupleWriteHelper<Depth, I>::write(const tuple<Ts...>& c, ostream& strm)
{
	TupleWriteHelper<Depth, I - 1>::write(c, strm);
	::write(get<I - 1>(c), strm);
}

template<size_t Depth, size_t I>
template<typename... Ts, typename Delim0, typename... Delims>
inline void TupleWriteHelper<Depth, I>::write(tuple<Ts&...>&& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	constexpr bool hasDelim = Depth < tuple_size<tuple<Delim0, Delims...>>::value;
	constexpr size_t safeDepth = hasDelim ? Depth : 0;
	TupleWriteHelper<Depth, I - 1>::write(c, strm, delims);
	write_tdelim<Depth + 1>(get<I - 1>(c), strm, delims);
	if (hasDelim && I < tuple_size<tuple<Ts...>>::value) ::write(get<safeDepth>(delims), strm);
}

template<size_t Depth, size_t I>
template<typename... Ts>
inline void TupleWriteHelper<Depth, I>::write(tuple<Ts&...>&& c, ostream& strm)
{
	TupleWriteHelper<Depth, I - 1>::write(c, strm);
	::write(get<I - 1>(c), strm);
}

template<size_t Depth, typename Iter, typename Delim0, typename... Delims>
inline void write_rng(Iter first, Iter last, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	if (first == last) return;
	constexpr bool hasDelim = Depth < tuple_size<tuple<Delim0, Delims...>>::value;
	constexpr size_t safeDepth = hasDelim ? Depth : 0;
	if (hasDelim)
	{
		for (;;)
		{
			write_tdelim<Depth + 1>(*(first++), strm, delims);
			if (first == last) break;
			write(get<safeDepth>(delims), strm);
		}
	}
	else
	{
		do
			write(*(first++), strm);
		while (first != last);
	}
}

template<typename Iter>
inline void write_rng(Iter first, Iter last, ostream& strm)
{
	while (first != last) write(*(first++), strm);
}

template<typename T>
inline void write(const T& t)
{
	write(t, cout);
}

template<typename T, typename Delim0, typename... Delims>
inline void write_delim(const T& t, const Delim0& delim0, const Delims&... delims)
{
	write_tdelim<0>(t, cout, tie(delim0, delims...));
}

template<typename T, typename Delim0, typename... Delims>
inline void write_delim(const T& t, ostream& strm, const Delim0& delim0, const Delims&... delims)
{
	write_tdelim<0>(t, strm, tie(delim0, delims...));
}

template<typename T>
inline constexpr T gcd(T l, T r)
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

template<typename T>
inline constexpr T gcd(initializer_list<T> args)
{
	return accumulate(ALL(args), (T)0, gcd<T>);
}

template<typename T>
inline constexpr T lcm(T l, T r) // l and r should be nonzero
{
	return l / gcd(l, r) * r;
}

template<typename T>
inline constexpr T lcm(initializer_list<T> args) // all elements of args (if any) should be nonzero
{
	return accumulate(ALL(args), (T)1, lcm<T>);
}

void go();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	go();

	return 0;
}

#endif

void go()
{
	uli T = readr<uli>();
	loop(0, T, t)
	{
		uli n = readr<uli>();
		string str = readr<string>();
		vbi hit0(26, 0);
		bool sus = false;
		uli i = 0;
		while (i < n)
		{
			char ch = str[i];
			while (i < n && str[i] == ch)
				i++;
			if (hit0[ch - 'A'])
			{
				sus = true;
				break;
			}
			hit0[ch - 'A'] = true;
		}
		write(!sus ? "YES\n" : "NO\n");
	}
}