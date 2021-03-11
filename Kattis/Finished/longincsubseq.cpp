#include <iostream>
#include <limits>
#include <sstream>

//using namespace std;

long long int A[100000];
long long int I[100000];
unsigned int L[100000];
unsigned int indices[100000];

int main()
{
	std::stringstream stream;
	unsigned int n;
	while (std::cin >> n)
	{

		for (unsigned int i = 0; i < n; i++)
		{
			std::cin >> A[i];
			I[i] = std::numeric_limits<long long int>::max();
		}

		unsigned int len = 0;
		unsigned int endI = 0;
		for (unsigned int i = 0; i < n; i++)
		{
			long long int a = A[i];
			unsigned int min = 0, max = std::min(len, n - 1), mid = max / 2;
			while (max > min)
			{
				if (I[mid] < a)
				{
					min = mid + 1;
				}
				else
				{
					max = mid;
				}
				mid = (max + min) / 2;
			}
			if (mid == len)
			{
				len++;
				endI = i;
			}
			I[mid] = a;
			L[i] = mid + 1;
		}
		stream << len << std::endl;

		unsigned int l = L[endI] - 1;
		long long int prevA = A[endI];

		indices[l] = endI;

		for (unsigned int i = endI; l; i--)
		{
			long long int a = A[i];
			if (L[i] == l && a < prevA)
			{
				indices[--l] = i;
				prevA = a;
			}
		}

		stream << indices[0];
		for (unsigned int i = 1; i < len; i++)
		{
			stream << " " << indices[i];
		}
		stream << std::endl;
	}
	std::cout << stream.str();
}