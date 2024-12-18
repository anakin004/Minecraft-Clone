Voxel/Minecraft Game with Multiplayer Using SDLnet and OpenGL

A 3D Minecraft-like game built in **C++** using **OpenGL**. Explore procedurally generated terrains, interact with dynamic blocks, and enjoy seamless multiplayer functionality.

## Features

- **Procedural Terrain Generation**  
  - Utilizes **Perlin Noise** for realistic terrain creation  
  - Multithreaded chunk generation with thread pooling for smooth gameplay without stutterting
  - Chunking and distance rendering for terrain offloading and generation

- **Graphics and Lighting**  
  - lighting implemented with **GLSL** shaders  
  - **Phong Shading** for enhanced visual effects (optional - uncomment from shader and shaderclass src file)
  - Primarily using ambient lighting to look more Minecraft like

- **Multiplayer Functionality**  
  - Supports server-client connections using **TCP** and **UDP** protocols
  - currently on last stretching for implimenting the code, utilizing boiler plate code from a previousl and working multiplayer project, 8-Bit Fighter (check it out too its awesome!)
  - Optimized for performance in a Linux environment

- **Dynamic Gameplay**  
  - Break and place blocks with physics-based interactions
  - You can enable/disable flying in camera, might add a function to switch that on an off with imgui
  - Infinite world exploration without interruptions

## Technologies Used

- **C++**
- **OpenGL**
- **GLSL**
- **Multithreading**
- **TCP/UDP Networking**
- **Linux Virtual Machine** for development and deployment.
- ** Assimp ** model loader
- ** SDLnet ** for the networking
- ** imgui ** for debugging, testing, visualizations, etc

![image](https://github.com/user-attachments/assets/5a84dd50-dbf8-44e9-9f9d-cf1f5b70e858)






