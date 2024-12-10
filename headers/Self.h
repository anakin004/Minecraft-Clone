#ifndef SELF_H
#define SELF_H

#include "Camera.h"
#include "PlayerObj.h"

class Self : public PlayerObj {


public:
	// pass in shader to set mvp intially
	Self( glm::vec3 pos );

	// updating camera, changes orientation and position, need to update mvp for
	// both shaders
	void updatePerspective(Shader* base, Shader* light);
	glm::vec3& getPos() { return m_Camera.GetPos(); }



private:

	Camera m_Camera;




};

extern GLFWwindow* window;
extern const int WIDTH;
extern const int HEIGHT;


#endif