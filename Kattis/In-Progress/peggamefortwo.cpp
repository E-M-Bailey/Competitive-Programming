#include <array>
#include <iostream>
#include <limits>

using namespace std;

constexpr const long long int INF = numeric_limits<long long int>::max();

long long int VALUES[15];

// A table of all possible triples in any direction. The 4 * allows these to be used for bitshifting by nibbles (units of 4 bits).
constexpr const array<array<unsigned char, 3>, 36> TRIPLES
{
	array<unsigned char, 3>{4 * 0x0, 4 * 0x1, 4 * 0x3}, array<unsigned char, 3>{4 * 0x3, 4 * 0x1, 4 * 0x0},
	array<unsigned char, 3>{4 * 0x3, 4 * 0x4, 4 * 0x5}, array<unsigned char, 3>{4 * 0x5, 4 * 0x4, 4 * 0x3},
	array<unsigned char, 3>{4 * 0x0, 4 * 0x2, 4 * 0x5}, array<unsigned char, 3>{4 * 0x5, 4 * 0x2, 4 * 0x0},
	array<unsigned char, 3>{4 * 0x1, 4 * 0x3, 4 * 0x6}, array<unsigned char, 3>{4 * 0x6, 4 * 0x3, 4 * 0x1},
	array<unsigned char, 3>{4 * 0x6, 4 * 0x7, 4 * 0x8}, array<unsigned char, 3>{4 * 0x8, 4 * 0x7, 4 * 0x6},
	array<unsigned char, 3>{4 * 0x1, 4 * 0x4, 4 * 0x8}, array<unsigned char, 3>{4 * 0x8, 4 * 0x4, 4 * 0x1},
	array<unsigned char, 3>{4 * 0x2, 4 * 0x4, 4 * 0x7}, array<unsigned char, 3>{4 * 0x7, 4 * 0x4, 4 * 0x2},
	array<unsigned char, 3>{4 * 0x7, 4 * 0x8, 4 * 0x9}, array<unsigned char, 3>{4 * 0x9, 4 * 0x8, 4 * 0x7},
	array<unsigned char, 3>{4 * 0x2, 4 * 0x5, 4 * 0x9}, array<unsigned char, 3>{4 * 0x9, 4 * 0x5, 4 * 0x2},
	array<unsigned char, 3>{4 * 0x3, 4 * 0x6, 4 * 0xa}, array<unsigned char, 3>{4 * 0xa, 4 * 0x6, 4 * 0x3},
	array<unsigned char, 3>{4 * 0xa, 4 * 0xb, 4 * 0xc}, array<unsigned char, 3>{4 * 0xc, 4 * 0xb, 4 * 0xa},
	array<unsigned char, 3>{4 * 0x3, 4 * 0x7, 4 * 0xc}, array<unsigned char, 3>{4 * 0xc, 4 * 0x7, 4 * 0x3},
	array<unsigned char, 3>{4 * 0x4, 4 * 0x7, 4 * 0xb}, array<unsigned char, 3>{4 * 0xb, 4 * 0x7, 4 * 0x4},
	array<unsigned char, 3>{4 * 0xb, 4 * 0xc, 4 * 0xd}, array<unsigned char, 3>{4 * 0xd, 4 * 0xc, 4 * 0xb},
	array<unsigned char, 3>{4 * 0x4, 4 * 0x8, 4 * 0xd}, array<unsigned char, 3>{4 * 0xd, 4 * 0x8, 4 * 0x4},
	array<unsigned char, 3>{4 * 0x5, 4 * 0x8, 4 * 0xc}, array<unsigned char, 3>{4 * 0xc, 4 * 0x8, 4 * 0x5},
	array<unsigned char, 3>{4 * 0xc, 4 * 0xd, 4 * 0xe}, array<unsigned char, 3>{4 * 0xe, 4 * 0xd, 4 * 0xc},
	array<unsigned char, 3>{4 * 0x5, 4 * 0x9, 4 * 0xe}, array<unsigned char, 3>{4 * 0xe, 4 * 0x9, 4 * 0x5},
};

// Negamax w/ alpha beta pruning
long long int evaluate(unsigned long long int state, long long int score = 0, long long int alpha = -INF, long long int beta = INF)
{
	bool found = false;
	long long int value = -INF;
	// This generates the list of potential next moves
	for (const array<unsigned char, 3> & triple : TRIPLES)
	{
		unsigned long long a, b;
		// This checks each move to see if its first point is empty and the other two have pins.
		if (!(state >> triple[0] & 0xfull) && (a = state >> triple[1] & 0xfull) && (b = state >> triple[2] & 0xfull))
		{
			found = true;
			// This evaluates the next state.
			unsigned long long int newState = state;
			// Places b where the empty spot was.
			newState |= b << triple[0];
			// Replaces a and b with empty spots.
			newState &= ~(0xfull << triple[1] | 0xfull << triple[2]);
			// Evaluates the change in the score.
			long long int delta = VALUES[a - 1] * VALUES[b - 1];
			// This recursively evaluates the current move.
			// The negative signs and the swapping of alpha and beta are because the other player is playing.
			long long int childValue = -evaluate(-beta, -alpha, newState, -(score + delta));
			// Updates the current value.
			value = max(value, childValue);
			// This prunes the current path if it is impossible to be chosen higher up.
			alpha = max(alpha, value);
			if (alpha >= beta)
				break;
		}
	}
	// This returnes the recursively evaluated value unless no moves were possible, in which case score is returned.
	return found ? value : score;
}

int main()
{
	// Holds fifteen 1-based indices to VALUES (0 means empty); each occupies 1 nibble.
	// The MSB is the lower right corner and the LSB is the top corner.
	unsigned long long int state = 0xfedcba987654321ull;

	for (unsigned int i = 0; i < 15; i++)
	{
		cin >> VALUES[i];
		if (VALUES[i] == 0)
			// Sets indices of empty points to 0
			state &= ~(0xfull << 4 * i);
	}

	cout << evaluate(state);

	return 0;
}