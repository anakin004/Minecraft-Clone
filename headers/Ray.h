#ifndef RAY_H
#define RAY_H

#include<glm/glm.hpp>

class Ray{

public:
	
	Ray(glm::vec3 start, glm::vec3 ori);
	void rayMarchDestroy();
	void rayMarchPlace();

private:

	void march();

	glm::vec3 m_Pos;
	glm::vec3 m_Ori;
	glm::vec3 m_Start;


};






#endif
