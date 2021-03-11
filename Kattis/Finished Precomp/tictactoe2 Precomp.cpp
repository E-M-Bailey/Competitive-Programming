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

#define loop(n, i) for (ui i = 0; i < (n); i++)

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

typedef array<array<ui, 3>, 3> bs;

inline constexpr ui toNum(const bs& b)
{
	return
		b[0][0] * 6561 +
		b[0][1] * 2187 +
		b[0][2] * 729 +
		b[1][0] * 243 +
		b[1][1] * 81 +
		b[1][2] * 27 +
		b[2][0] * 9 +
		b[2][1] * 3 +
		b[2][2] * 1;
}

inline constexpr ui winner(const bs& board)
{
	loop(3, i)
	{
		if (board[i][0] && board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			return board[i][0];
		}
		if (board[0][i] && board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			return board[0][i];
		}
	}
	if (board[0][0] && board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return board[0][0];
	}
	if (board[0][2] && board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return board[0][2];
	}
	return 0;
}

inline constexpr void search(ui* all, bs& board, ui turn)
{
	ui num = toNum(board);
	all[num / 32] |= 1u << num % 32;
	if (!winner(board))
	{
		loop(3, i) loop(3, j)
		{
			if (board[i][j] == 0)
			{
				board[i][j] = turn;
				search(all, board, 3 - turn);
				board[i][j] = 0;
			}
		}
	}
}

inline void init(ui* all)
{
	bs start = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	search(all, start, 1);
}

int main()
{
	ui* all = new ui[19683u / 32 + 1]{ 0u };
	init(all);
	stringstream stream;
	stream << "{ " << hex;
	loop(19683u / 32 + 1, i)
	{
		stream << "0x" << all[i] << ", ";
	}
	stream << "}";
	cout << stream.str();
}