#include "Ray.h"
#include "World.h"
#include "mathUtil.h"

#include <iostream>

Ray::Ray(glm::vec3 start, glm::vec3 ori) : m_Pos(start), m_Ori(ori), m_Start(start)
{
}




void Ray::march()
{
	const float step = 0.1;
	m_Pos.x += step * m_Ori.x;
	m_Pos.y += step * m_Ori.y;
	m_Pos.z += step * m_Ori.z;

}

void Ray::rayMarchPlace() {
	bool hit = false;
	Chunk* c = nullptr;

	int x, y, z;

	while (!hit) {

		march();

		// if too bar break
		if (vec3Dist(m_Pos, m_Start) >= 4) break;

		int cx = (int)std::floor(m_Pos.x / 16.f);
		int cz = (int)std::floor(m_Pos.z / 16.f);
		x = (int)std::floor(m_Pos.x - 16 * cx);
		y = (int)std::floor(m_Pos.y);
		z = (int)std::floor(m_Pos.z - 16 * cz);
		c = World::GetChunk(cx, cz);

		if(c)
			hit = c->CheckBit(x, z, y);

	}

	// we only reasign hit if chunk or c is also not null
	if (hit) {
		Direction dir = dotProdDirs(m_Ori);
		c->PlaceBlock(x, z, y, c->GetBlock(x, z, y), dir);
	}

}

void Ray::rayMarchDestroy() {
	bool hit = false;
	while (!hit) {
		march();

		// if too bar break
		if (vec3Dist(m_Pos, m_Start) >= 4 ) break;

		int cx = (int)std::floor(m_Pos.x / 16.f);
		int cz = (int)std::floor(m_Pos.z / 16.f);
		int x = (int)std::floor(m_Pos.x - 16 * cx);
		int y = (int)std::floor(m_Pos.y);
		int z = (int)std::floor(m_Pos.z - 16 * cz);
		Chunk* c = World::GetChunk(cx, cz);

		hit = c->CheckBit(x, z, y);

		if (hit)
			c->RemoveBlock(x, z, y);
		
	}

}

       