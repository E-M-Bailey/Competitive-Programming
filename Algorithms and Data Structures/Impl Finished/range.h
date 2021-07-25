#ifndef EMBAILEY_RANGE
#define EMBAILEY_RANGE

struct range
{
	size_t first, last;

	inline constexpr range() noexcept :
		first(0),
		last(0)
	{}

	explicit inline constexpr range(size_t last) noexcept :
		first(0),
		last(last)
	{}

	inline constexpr range(size_t first, size_t last) noexcept :
		first(first),
		last(last)
	{}
};

#endif
