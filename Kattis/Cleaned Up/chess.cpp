/*
BEGIN ANNOTATION
PROBLEM URL: open.kattis.com/problems/chess
TAGS: coordinate, transformation, cases
EXPLANATION:
Converts X and Y from (x, y) coordinates to (u, v) coordinates, where u = x - y and v = x + y.
Each bishop move only changes one of u and v, so calculations are easier.
Checks for impossibility (different colors), 0 moves (X == Y), and
1 move (only one of u and v is different from X to Y).
Otherwise, tries moving in one direction to get to Y; if that goes outside the board, tries the
other direction.
END ANNOTATION
*/
#include <iostream>

using namespace std;

// Given (x, y), returns (u, v)
inline constexpr pair<int, int> toUV(pair<int, int> xy)
{
	return { xy.first - xy.second, xy.first + xy.second };
}

// Given (u, v), returns (x, y)
inline constexpr pair<int, int> toXY(pair<int, int> uv)
{
	return { (uv.second + uv.first) / 2, (uv.second - uv.first) / 2 };
}

int main()
{
	unsigned testCaseCount;
	cin >> testCaseCount;
	for (unsigned testCaseIndex = 0; testCaseIndex < testCaseCount; testCaseIndex++)
	{
		// Reads test case data: X = (x1, y1), Y = (x2, y2)
		char ch;
		int x1, y1, x2, y2;
		cin >> ch; x1 = ch - 'A';
		cin >> ch; y1 = ch - '1';
		cin >> ch; x2 = ch - 'A';
		cin >> ch; y2 = ch - '1';

		// Checks if X and Y are different colors
		if ((x1 ^ y1 ^ x2 ^ y2) & 1)
		{
			cout << "Impossible" << endl;
			continue;
		}

		// Checks if X == Y
		if (x1 == x2 && y1 == y2)
		{
			cout << "0 " << (char)(x1 + 'A') << " " << (char)(y1 + '1') << endl;
			continue;
		}

		// Creates int pairs for the xy and uv coords of X and Y
		pair<int, int> xy1 = { x1, y1 }, xy2 = { x2, y2 };
		pair<int, int> uv1 = toUV(xy1), uv2 = toUV(xy2);

		// Checks if Y is reachable from X in just one move
		if (uv1.first == uv2.first || uv1.second == uv2.second)
		{
			cout << "1 " << (char)(x1 + 'A') << " " << (char)(y1 + '1') << " " << (char)(x2 + 'A') << " " << (char)(y2 + '1') << endl;
			continue;
		}

		// Generates the intermediate point (the bishop's location after 1 move)
		pair<int, int> uvImd = { uv1.first, uv2.second };
		pair<int, int> xyImd = toXY(uvImd);

		// Checks if the intermediate point is out of bounds
		if (xyImd.first < 0 || xyImd.first >= 8 || xyImd.second < 0 || xyImd.second >= 8)
		{
			// Generates the second intermediate point
			uvImd = { uv2.first, uv1.second };
			xyImd = toXY(uvImd);
		}

		cout << "2 " << (char)(x1 + 'A') << " " << (char)(y1 + '1') << " " << (char)(xyImd.first + 'A') << " " << (char)(xyImd.second + '1') << " " << (char)(x2 + 'A') << " " << (char)(y2 + '1') << endl;
	}
	return 0;
}