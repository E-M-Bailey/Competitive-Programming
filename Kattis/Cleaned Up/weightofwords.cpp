/*
BEGIN ANNOTATION
PROBLEM URL: open.kattis.com/problems/weightofwords
TAGS: string, cases
EXPLANATION:
If the weight is too small for a string of a's or too big for a string of z's, it is impossible. Otherwise, start with
a string of a's, swtich them to z's until the weight of the string is within 25 of the goal. If you have not yet reached
the correct weight, increase an a by the difference.
END ANNOTATION
*/
#include <iostream>
#include <string>

using namespace std;

constexpr const unsigned UI_MAX = numeric_limits<unsigned>::max();

int main()
{
	unsigned l, w;
	cin >> l >> w;
	if (w < l || w > 26 * l)
	{
		cout << "impossible";
		return 0;
	}
	if (w == l)
	{
		cout << string(l, 'a');
		return 0;
	}
	unsigned cur = l;
	string word(l, 'a');
	unsigned idx = 0;
	while (cur + 25 < w)
	{
		word[idx] = 'z';
		cur += 25;
		idx++;
	}
	word[idx] += w - cur;
	cout << word;

	return 0;
}