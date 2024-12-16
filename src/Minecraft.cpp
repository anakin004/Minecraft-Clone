
#include "Minecraft.h"



GLFWwindow* window = nullptr;
const int WIDTH = 1280;
const int HEIGHT = 720;




Minecraft::~Minecraft() {

	// Delete window before ending the program
	glfwDestroyWindow(window);

	// Terminate GLFW before ending the program
	glfwTerminate();
}



void Minecraft::Run() {



	if (!initGL()) {
		std::cout << "failed to init";
		return;
	}

	Texture::InitTextures();
	Shader::InitShaders();

	{

		World w(2);
		//Gui gui(window);


		glm::mat4 identityMatrix(1.0f);


		Self player({ 0,7,0 });
		player.m_PlayerModel.Init();

		Renderer renderer;

		Shader* base = Shader::getShader("base.shader");
		Shader* light = Shader::getShader("light.shader");
		Shader* model = Shader::getShader("model.shader");

		while (!glfwWindowShouldClose(window))
		{

			renderer.Clear();

			//gui.HandleGui(cam.GetPos());
			player.updatePerspective(base, light, model);

			w.UpdateWorld(player.getPos());

			light->Bind();
			w.RenderLight();
			model->Bind();
			player.Render(model);
			base->Bind();
			w.RenderChunks();
			// Swap the back buffer with the front buffer
			glfwSwapBuffers(window);
			// Take care of all GLFW events
			glfwPollEvents();

		}


		// notice theres an extra scope because we have ~ cleanups in our classes that call gl frees after we terminate
		// which we have no active context
	}

}



bool Minecraft::initGL()
{

	bool success = true;


	// Initialize GLFW
	glfwInit();


	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "Minecraft", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		success = false;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();

	std::cout << glGetString(GL_VERSION) << std::endl;

	// Specify the viewport of OpenGL in the Window
	glViewport(0, 0, WIDTH, HEIGHT);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glCullFace(GL_BACK);


	return success;
}