#include <chrono>
#include <iostream>
using namespace std;
int main()
{
    int t, n, c1 = 0, c2 = 0, k = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int a = n / 3;
            int b = n % 3;
            c1 = a; c2 = a;
            if (b == 1) { ++c1; break; }
            if (b == 2) { ++c2; break; }
        }
        cout << c1 << " " << c2 << endl;
    }

    return 0;
}
