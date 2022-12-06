#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>
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

inline glm::vec3 randomInUnitSphere()

{
    glm::vec3 point;
    do
    {
        point = glm::vec3{ Random(-1, 1), Random(-1, 1), Random(-1, 1) };
    } while (glm::length2(point) >= 1);

    return point;
}

template <typename T>
inline T Lerp(T a, T b, float t)
{
	return (a * (1.0f - t)) + (b * t);
}