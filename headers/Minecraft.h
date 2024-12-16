#ifndef MINECRAFT_H
#define MINECRAFT_H

#include <iostream>
#include <stdio.h>
#include <array>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Debug.h"
#include "shaderClass.h"
#include "Render.h"
#include "Texture.h"
#include "Camera.h"
#include "Block.h"
#include "Perlin.h"
#include "Chunk.h"
#include "World.h"
#include "Self.h"


class Minecraft {


private:

	
	// thought it would be better to have all the shaders contained in this class
	// we access the shaders when updating mvp, which is being handled in updatePerspective
	// it is also being used in rendering when we need to bind specific shaders for rendering
	// the mvp is updated in any shaders that require it after perspective is updated
	// the only shaders being used in base and light, base being for chunks and objects
	// light is for of course, just the light source - sun, even though the sun looks like a box for now haha

	Shader* m_Base = nullptr;
	Shader* m_Light = nullptr;

	bool initGL();

public:

	void Init();
	void Run();


	Minecraft() {}
	~Minecraft();


};






#endif 