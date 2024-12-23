#include "World.h"
#include "Debug.h"


std::vector<Chunk*> World::m_Chunks;
std::unordered_map <std::pair<int, int>, Chunk*, pair_hash> World::m_ChunkMap;

// default constructor
World::World() : m_WorldLight(), m_RenderDistance(5), m_ChunkAllocateTime(0), pool(4) {

}

World::World(int renderDist) : m_WorldLight(), m_RenderDistance(renderDist), m_ChunkAllocateTime(0), m_AtlasID(0),

	// i have 10 cores so i could have 10 threads without having context switching
	// For my specs, running with 1 thread in the pool works even thought a pool with one thread makes little sense
	// but if your pc specs are lacking, I would recommend seeing how many cores you have and allocating that many threads for the pool
	pool(4)
{

	m_AtlasID = Texture::GetTexture(0)->getTextureID();
}


World::~World()
{
	for (auto& it : m_Chunks)
		it->DestroyChunkEnd();

	Object::DestroyObjects();
	Shader::DeleteShaders();
}

void World::HandleChunks(glm::vec3& playerPos)
{	

	for (auto& chunk : m_Chunks)
	{
		if (chunk->Loaded()) 
			chunk->UpdateRenderStatus(playerPos, m_RenderDistance);
		
		else
			chunk->ChunkFirstLoad();
	}

}


void World::RenderChunks() {
	GlCall(glBindTexture(GL_TEXTURE_2D, m_AtlasID));
	for (auto& chunk : m_Chunks)
	{
		if (chunk->Loaded()) {
			chunk->RenderChunk();
		}
	}
	GlCall(glBindTexture(GL_TEXTURE_2D, 0));

}

void World::UpdateWorld(glm::vec3& playerPos)
{
	UpdateRender(playerPos);
	HandleChunks(playerPos);
}

void World::RenderLight()
{
	m_WorldLight.Render();
}



Chunk* World::GetChunk(int x, int z)
{

	std::pair<int, int> coord{ x,z };

	if (  m_ChunkMap.find(coord) != m_ChunkMap.end())
		return 	m_ChunkMap[coord];

	return nullptr;

}




void World::UpdateRender(glm::vec3& playerPos)
{

	int chunkX = (int)playerPos.x / CHUNK_SIZE;
	int chunkZ = (int)playerPos.z / CHUNK_SIZE;

	for (int x = chunkX - m_RenderDistance; x <= chunkX + m_RenderDistance ; x++)
	{
		for (int z = chunkZ - m_RenderDistance; z <= chunkZ + m_RenderDistance; z++)
		{
			std::pair<int, int> coord{ x,z };

			double curTime = glfwGetTime();

			// slowing down how many allocations we do can help with stuttering
			if (m_ChunkMap.find(coord) == m_ChunkMap.end() && curTime - m_ChunkAllocateTime > 0.05 )
			{
				
				m_ChunkAllocateTime = glfwGetTime();
				
				Chunk* newChunk = new Chunk(x * CHUNK_SIZE, z * CHUNK_SIZE);

				// creating a task with a lambda 
				// the lambda is able to use the newChunk pointer and runs initchunk
				Task t = { [newChunk]() {
							newChunk->InitChunk();
							},
				};

				pool.enqueueTask(t);

				// pushing the pointer into the chunks vector
				// we are not able to manipulate and chunk the chunk until intilization is done
				// there is an atomic boolean that lets us see if its done
				m_Chunks.push_back(newChunk);

	
				m_ChunkMap[coord] = newChunk;
			}

		}
	}
}

