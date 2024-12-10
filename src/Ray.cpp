#include "Ray.h"
#include <iostream>

Ray::Ray(glm::vec3 start, glm::vec3 ori) : m_Pos(start), m_Ori(ori)
{
}

glm::vec3& Ray::march()
{
	const float step = 0.1;
	m_Pos.x += step * m_Ori.x;
	m_Pos.y += step * m_Ori.y;
	std::cout << m_Pos.y << std::endl;
	m_Pos.z += step * m_Ori.z;
	return m_Pos;
}
       