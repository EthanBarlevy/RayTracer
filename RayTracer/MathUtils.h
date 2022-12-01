#pragma once
#include <glm/glm.hpp>
#include <cstdlib>
#include <algorithm>

inline float Random01()
{
	return rand() / (float)RAND_MAX;
}

inline float Random(float min, float max)
{
	if (min > max) std::swap(min, max);

	return min + (max - min) * Random01();
}

template <typename T>
inline T Interp(T a, T b, float t)
{
	return (a * (1.0f - t)) + (b * t);
}