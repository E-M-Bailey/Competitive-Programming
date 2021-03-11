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
typedef vector<bool>       vb;

int main()
{
	ui N;
	cin >> N;
	vui tea(N);
	for (ui i = 0; i < N; i++)
	{
		cin >> tea[i];
	}
	ui M;
	cin >> M;
	vui toppings(M);
	for (ui i = 0; i < M; i++)
	{
		cin >> toppings[i];
	}
	ui minPrice = 2000000000;
	for (ui i = 0; i < N; i++)
	{
		ui teaPrice = tea[i];
		ui K;
		cin >> K;
		for (ui k = 0; k < K; k++)
		{
			ui j;
			cin >> j;
			ui price = teaPrice + toppings[j - 1];
			if (price < minPrice)
				minPrice = price;
		}
	}

	ui X;
	cin >> X;

	ui a = X / minPrice;
	if (a)
	{
		cout << a - 1;
	}
	else
	{
		cout << a;
	}

	return 0;
}