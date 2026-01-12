#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void iter(T *array, size_t const length, F func)
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif
