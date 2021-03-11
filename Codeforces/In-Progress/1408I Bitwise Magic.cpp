#include <cstring>
#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <functional>
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

constexpr const ull MODULUS = 998244353;

inline constexpr ull modPowInv(ui n, ui k)
{
	ull res = n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;
	res = res * res % MODULUS * n % MODULUS;

	ull res2 = res;
	loop(1, k, i)
		res2 = (res2 * res) % MODULUS;
	return res2;
}

void rec(ui i, ui k, ui x, ui n, const vui& A, vull& prob)
{
	if (k == 0) prob[x]++;
	else if (i < n)
		for (ui m = 0; m <= k; m++)
			rec(i + 1, k - m, x ^ A[i] ^ (A[i] - m), n, A, prob);
}

int main()
{
	ui n, k, c;
	cin >> n >> k >> c;

	ui l = 1u << c;

	ull qInv = modPowInv(n, k);

	ui x = 0;
	vui A(n);
	loop(0, n, i)
	{
		cin >> A[i];
		x ^= A[i];
	}

	vull prob(l, 0);

	rec(0, k, x, n, A, prob);

	for (ull p : prob)
		cout << (p * qInv) % MODULUS << " ";

	return 0;
}




//m = 1 << c;
//vull DP1(m, 0), DP2(m, 0);
//ull qInv = 748683265; // todo actually calculate
//vui A(n);
//{
//	ui p = 0;
//	loop(0, n, i)
//	{
//		cin >> A[i];
//		p ^= A[i];
//	}
//	DP1[p] = 1ull;
//}
//
//loop(0, k, iter)
//{
//	loop(0, m, i)
//	{
//		ull x = DP1[i];
//		if (x == 0)
//			continue;
//		for (ull a : A)
//		{
//			
//		}
//	}
//}