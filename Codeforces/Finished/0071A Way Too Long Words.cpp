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
	unsigned n, len;
	string str;
	cin >> n;
	while (n > 0)
	{
		cin >> str;
		len = str.size();
		if (len <= 10)
		{
			cout << str << endl;
		}
		else
		{
			cout << str[0] << len - 2 << str[len - 1] << endl;
		}
		n--;
	}
	return 0;
}