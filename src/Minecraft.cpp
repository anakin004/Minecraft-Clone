
#include "Minecraft.h"
#include "Self.h"



GLFWwindow* window = nullptr;
const int WIDTH = 1280;
const int HEIGHT = 720;



Minecraft::~Minecraft() {

	// Delete window before ending the program
	glfwDestroyWindow(window);

	// Terminate GLFW before ending the program
	glfwTerminate();
}



void Minecraft::Init()
{
	glm::vec3 pos = { 0,7,0 };
	m_Player.emplace(pos);

	m_Base = Shader::getShader("base.shader");
	m_Light = Shader::getShader("light.shader");
}


void Minecraft::Run() {



	if (!initGL()) {
		std::cout << "failed to init"; 
		return;
	}

	Shader::InitShaders();
	Texture::InitTextures();

	// now we init Player
	// the since player is contained the world
	// the world is initialized, allows for better encapsulization
	Init();


	{

		// removing gui as needed
		// throughout development
		//Gui gui(window);

		Renderer renderer;

		while (!glfwWindowShouldClose(window))
		{
			renderer.Clear();

			//gui.HandleGui(cam.GetPos());
			
			m_Player->updatePerspective(m_Base, m_Light);
			Update(); 
			Render();

			// Swap the back buffer with the front buffer
			glfwSwapBuffers(window);
			// Take care of all GLFW events
			glfwPollEvents();

		}


		// notice theres an extra scope because we have ~ cleanups in our classes that call gl frees after we terminate
		// which we have no active context
	}

}


void Minecraft::Update() {
	m_Player->UpdateWorld(m_Player->getPos());
}

void Minecraft::Render()
{
	m_Base->Bind();
	m_Player->RenderChunks();

	m_Light->Bind();
	m_Player->RenderLight();
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

