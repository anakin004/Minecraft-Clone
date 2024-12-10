#include "mathUtil.h"

double vec3Dist(const glm::vec3& v1, const glm::vec3& v2)
{	
	double a = sqrt(1);
	return glm::length(v2 - v1);
}