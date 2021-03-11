#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; t++)
	{
		unsigned n;
		cin >> n;
		unordered_set<string> cityNames;
		for (unsigned i = 0; i < n; i++)
		{
			string cityName;
			cin >> cityName;
			cityNames.insert(cityName);
		}
		cout << cityNames.size() << endl;
	}
	return 0;
}