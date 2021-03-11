#include <array>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Encodes each board state as a unique id.
inline constexpr unsigned toNum(const array<array<unsigned, 3>, 3>& b)
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

// Returns the winner of board or 0 if there is no winner
inline constexpr unsigned winner(const array<array<unsigned, 3>, 3>& board)
{
	for (unsigned i = 0; i < 3; i++)
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

// Finds all reachable board states starting with board
inline void search(vector<unsigned long long>& reachable, array<array<unsigned, 3>, 3>& board, unsigned player)
{
	unsigned num = toNum(board);
	reachable[num / 64] |= 1ull << num % 64;
	if (!winner(board))
	{
		for (unsigned i = 0; i < 3; i++)
			for (unsigned j = 0; j < 3; j++)
			{
				if (board[i][j] == 0)
				{
					board[i][j] = player;
					search(reachable, board, 3 - player);
					board[i][j] = 0;
				}
			}
	}
}

// Finds all reachable board positions starting with a new game
inline void search(vector<unsigned long long>& reachable)
{
	array<array<unsigned, 3>, 3> start
	{
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
	};
	search(reachable, start, 1);
}

int main()
{
	// Generates all reachable board positions
	vector<unsigned long long> reachable(19683u / 64 + 1, 0);
	search(reachable);

	// Prints the C++ array initializer for the lookup table.
	stringstream stream;
	stream << "{ " << hex;
	for (unsigned i = 0; i < 19683 / 64 + 1; i++)
		stream << "0x" << reachable[i] << ", ";
	stream << "}";
	cout << stream.str();

	return 0;
}