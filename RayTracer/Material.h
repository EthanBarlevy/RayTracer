#pragma once
#include "Color.h"
#include "Ray.h"

class Material 
{
public:
	virtual bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const = 0;
};