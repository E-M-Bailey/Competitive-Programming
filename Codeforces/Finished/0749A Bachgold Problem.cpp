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
	unsigned n;
	cin >> n;
	unsigned len = n / 2;
	unsigned rdn = len * 2;
	char* str = new char[rdn];
	*str = n & 1u ? '3' : '2';
	char* end = str + rdn - 1;
	char* ptr = str + 1;
	while (ptr < end)
	{
		*ptr++ = ' ';
		*ptr++ = '2';
	}
	*end = '\0';
	cout << len << endl << str;
	return 0;
}