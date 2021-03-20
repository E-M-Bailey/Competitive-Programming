#pragma once

#include "../Template.h"


inline ulli mergeSortInversionCount(vuli& vec)
{
	uli n = vec.size();
	vuli aux(n);
	ulli inversions = 0;
	for (uli halfM = 1; halfM <= n; halfM *= 2)
	{
		uli m = 2 * halfM;
		for (uli lo = 0; lo < n; lo += m)
		{
			uli mid = lo + halfM;
			uli hi = min(mid + halfM, n);
			if (hi <= mid)
				break;
			uli lIdx = lo, rIdx = mid, idx = 0;
			while (lIdx < mid && rIdx < hi)
			{
				uli l = vec[lIdx], r = vec[rIdx];
				if (l <= r)
				{
					aux[idx] = l;
					idx++;
					lIdx++;
				}
				else
				{
					aux[idx] = r;
					idx++;
					rIdx++;
					inversions += mid - lIdx;
				}
			}
			while (lIdx < mid)
			{
				uli l = vec[lIdx];
				aux[idx] = l;
				idx++;
				lIdx++;
			}
			while (rIdx < hi)
			{
				uli r = vec[rIdx];
				aux[idx] = r;
				idx++;
				rIdx++;
			}
			copy(aux.begin(), aux.begin() + idx, vec.begin() + lo);
		}
	}
	return inversions;
}