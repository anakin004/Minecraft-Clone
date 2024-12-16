#ifndef WORLD_H
#define WORLD_H

#include "Light.h"
#include "shaderClass.h"
#include "Thread.h"
#include <unordered_map>
#include <utility>  
#include "Chunk.h"
#include "Texture.h"

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator()(const std::pair<T1, T2>& pair) const {
		return std::hash<T1>()(pair.first) ^ (std::hash<T2>()(pair.second) << 1);
	}
};


class World {



public:
	//default constructor
	World();

	World(int renderDist);
	~World();

	void AddChunk();
	void RenderChunks();
	void UpdateRender(glm::vec3& playerPos);
	void HandleChunks(glm::vec3& playerPos);

	// wrapper for handle chunks and update render
	void UpdateWorld(glm::vec3& playerPos);

	void RenderLight();

	//@param divide x and z by 16 before you getchunk, we arent using world coords for mapping
	static Chunk* GetChunk(int x, int z);
	

private:

	static std::vector<Chunk*> m_Chunks;
	static std::unordered_map <std::pair<int, int>, Chunk*, pair_hash> m_ChunkMap;
	
	ThreadPool pool;

	Light m_WorldLight;

	double m_ChunkAllocateTime;

	int m_RenderDistance;

	GLint m_AtlasID;

};


#endif 