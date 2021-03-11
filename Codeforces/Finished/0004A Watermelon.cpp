#include <cstring>
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

using namespace std;

int main()
{
	unsigned w;
	cin >> w;
	bool even = w > 3 && w % 2 == 0;
	cout << (even ? "YES" : "NO");
	return 0;
}