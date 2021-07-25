#pragma once

#include <Template.h>

template<typename Iter>
inline size_t mergeSortInversionCount(Iter first, Iter last)
{
	using Elem = typename iterator_traits<Iter>::value_type;
	using AIter = typename vector<Elem>::iterator;
	size_t n = last - first;
	vector<Elem> aux(n);
	size_t inversions = 0;
	for (size_t halfM = 1; halfM <= n; halfM *= 2)
	{
		size_t m = 2 * halfM;
		for (Iter lo = first; lo != last; lo += min(m, static_cast<size_t>(last - lo)))
		{
			if (static_cast<size_t>(last - lo) <= halfM) break;
			bool stop = static_cast<size_t>(last - lo) <= m;
			Iter mid = lo + halfM;
			Iter hi = stop ? last : mid + halfM;
			Iter lItr = lo, rItr = mid;
			AIter aItr = aux.begin();
			while (lItr != mid && rItr != hi)
			{
				Elem l = move(*lItr), r = move(*rItr);
				if (l <= r)
				{
					*aItr = move(l);
					aItr++;
					lItr++;
				}
				else
				{
					*aItr = move(r);
					aItr++;
					rItr++;
					inversions += mid - lItr;
				}
			}
			while (lItr < mid)
			{
				*aItr = move(*lItr);
				aItr++;
				lItr++;
			}
			while (rItr < hi)
			{
				*aItr = move(*rItr);
				aItr++;
				rItr++;
			}
			move(aux.begin(), aItr, lo);
			if (stop) break;
			lo += m;
		}
	}
	return inversions;
}