#include "util.h"
#include <iostream>

const verts BaseBlock[24] =
{
	// front
	{ {0.0f, 0.0f, 1.0f}, {0, 0} ,0},// bottom left       
	{ {1.0f, 0.0f, 1.0f}, {0, 0} ,0},  // bottom right
	{ {0.0f, 1.0f, 1.0f}, {0, 0} ,0},  // top left
	{ {1.0f, 1.0f, 1.0f}, {0, 0} ,0},  // top right

	// left side
	{ {0.0f, 0.0f, 0.0f}, {0, 0} ,1},  // bottom left       
	{ {0.0f, 0.0f, 1.0f}, {0, 0} ,1},  // bottom right
	{ {0.0f, 1.0f, 0.0f}, {0, 0} ,1},   // top left
	{ {0.0f, 1.0f, 1.0f}, {0, 0} ,1},   // top right

	// back side
	{ {1.0f, 0.0f, 0.0f}, {0, 0} ,2},// bottom left       
	{ {0.0f, 0.0f, 0.0f}, {0, 0} ,2},  // bottom right
	{ {1.0f, 1.0f, 0.0f}, {0, 0} ,2},  // top left
	{ {0.0f, 1.0f, 0.0f}, {0, 0} ,2},  // top right

	// right side
	{ {1.0f, 0.0f, 1.0f}, {0, 0} ,3},  // bottom left       
	{ {1.0f, 0.0f, 0.0f}, {0, 0} ,3},   // bottom right
	{ {1.0f, 1.0f, 1.0f}, {0, 0} ,3},  // top left
	{ {1.0f, 1.0f, 0.0f}, {0, 0} ,3}, // top right

	// bottom
	{ {0.0f, 0.0f, 1.0f}, {0, 0} ,4},  // bottom left
	{ {1.0f, 0.0f, 1.0f}, {0, 0} ,4},  // bottom right
	{ {0.0f, 0.0f, 0.0f}, {0, 0} ,4},  // top left
	{ {1.0f, 0.0f, 0.0f}, {0, 0} ,4},  // top right

	// top
	{ {0.0f, 1.0f, 1.0f}, {0, 0} ,5},   // bottom left
	{ {1.0f, 1.0f, 1.0f}, {0, 0} ,5},   // bottom right
	{ {0.0f, 1.0f, 0.0f}, {0, 0} ,5},  // top left
	{ {1.0f, 1.0f, 0.0f}, {0, 0} ,5}, // top right

};

// hit is the block that is hit from a ray cast
std::array<verts,24> makeNewBlock(const glm::vec3& dirNorm, const verts* base, const blockCoordGroup block) {

	float x = dirNorm.x;
	float y = dirNorm.y;
	float z = dirNorm.z;



	return {
		// front
		verts{ {base[0].vec.x + x, base[0].vec.y + y, base[0].vec.z + z}, block.side.botLeft , 0}, // bottom left       
		verts{ {base[1].vec.x + x, base[1].vec.y + y, base[1].vec.z + z}, block.side.botRight , 0 },  // bottom right
		verts{ {base[2].vec.x + x, base[2].vec.y + y, base[2].vec.z + z}, block.side.topLeft , 0 },  // top left
		verts{ {base[3].vec.x + x, base[3].vec.y + y, base[3].vec.z + z}, block.side.topRight , 0 },  // top right

		// left side
		verts{ {base[4].vec.x + x, base[4].vec.y + y, base[4].vec.z + z}, block.side.botLeft , 1 },  // bottom left       
		verts{ {base[5].vec.x + x, base[5].vec.y + y, base[5].vec.z + z}, block.side.botRight , 1 },  // bottom right
		verts{ {base[6].vec.x + x, base[6].vec.y + y, base[6].vec.z + z}, block.side.topLeft , 1 },   // top left
		verts{ {base[7].vec.x + x, base[7].vec.y + y, base[7].vec.z + z}, block.side.topRight , 1 },   // top right

		// back side
		verts{ {base[8].vec.x + x, base[8].vec.y + y, base[8].vec.z + z}, block.side.botLeft , 2 }, // bottom left       
		verts{ {base[9].vec.x + x, base[9].vec.y + y, base[9].vec.z + z}, block.side.botRight , 2 },  // bottom right
		verts{ {base[10].vec.x + x, base[10].vec.y + y, base[10].vec.z + z}, block.side.topLeft , 2 },  // top left
		verts{ {base[11].vec.x + x, base[11].vec.y + y, base[11].vec.z + z}, block.side.topRight , 2 },  // top right

		// right side
		verts{ {base[12].vec.x + x, base[12].vec.y + y, base[12].vec.z + z}, block.side.botLeft , 3 },  // bottom left       
		verts{ {base[13].vec.x + x, base[13].vec.y + y, base[13].vec.z + z}, block.side.botRight , 3 },   // bottom right
		verts{ {base[14].vec.x + x, base[14].vec.y + y, base[14].vec.z + z}, block.side.topLeft , 3 },  // top left
		verts{ {base[15].vec.x + x, base[15].vec.y + y, base[15].vec.z + z}, block.side.topRight , 3 }, // top right

		// bottom
		verts{ {base[16].vec.x + x, base[16].vec.y + y, base[16].vec.z + z}, block.bottom.botLeft , 4 },  // bottom left
		verts{ {base[17].vec.x + x, base[17].vec.y + y, base[17].vec.z + z}, block.bottom.botRight , 4 },  // bottom right
		verts{ {base[18].vec.x + x, base[18].vec.y + y, base[18].vec.z + z}, block.bottom.topLeft , 4 },  // top left
		verts{ {base[19].vec.x + x, base[19].vec.y + y, base[19].vec.z + z}, block.bottom.topRight , 4 },  // top right

		// top
		verts{ {base[20].vec.x + x, base[20].vec.y + y, base[20].vec.z + z}, block.top.botLeft , 5 },   // bottom left
		verts{ {base[21].vec.x + x, base[21].vec.y + y, base[21].vec.z + z}, block.top.botRight , 5 },   // bottom right
		verts{ {base[22].vec.x + x, base[22].vec.y + y, base[22].vec.z + z}, block.top.topLeft , 5 },  // top left
		verts{ {base[23].vec.x + x, base[23].vec.y + y, base[23].vec.z + z}, block.top.topRight , 5 }, // top right


	};



}

const glm::vec3 FaceNormals[6] = {
	{0.0f, 0.0f, 1.0f},   // front
	{-1.0f, 0.0f, 0.0f},  // left
	{0.0f, 0.0f, -1.0f},  // back
	{1.0f, 0.0f, 0.0f},   // right
	{0.0f, -1.0f, 0.0f},  // bottom
	{0.0f, 1.0f, 0.0f}    // top
};


// Indices for vertices order
const indexCoords BaseBlockIndices[12] =
{
	{0, 1, 2},  // f. left tri
	{1, 2, 3},  // f. right tri
	{4, 5, 6},  // ls. left tri
	{5, 6, 7},  // ls. right tri
	{8, 9, 10},  // ba. left tri
	{9, 10, 11},  // ba. right tri
	{12, 13, 14},  // rs. left tri
	{13, 14, 15},  // rs. right tri
	{16, 17, 18},  // bottom. left tri
	{17, 18, 19},  // bottom. right tri
	{20, 21, 22},  // top. left tri
	{21, 22, 23},  // top. right tri
};


const float LightVertices[24] =
{ //     COORDINATES     //
	-0.1f, -0.1f,  0.1f,
	-0.1f, -0.1f, -0.1f,
	0.1f, -0.1f, -0.1f,
	0.1f, -0.1f,  0.1f,
	-0.1f,  0.1f,  0.1f,
	-0.1f,  0.1f, -0.1f,
	0.1f,  0.1f, -0.1f,
	0.1f,  0.1f,  0.1f
};

const GLuint LightIndices[36] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};



Direction dotProdDirs(glm::vec3& ori) {

	glm::vec3 normalizeOri = glm::normalize(ori);
	float min = 1;
	Direction dir = NORTH;
	for (int i = 0; i < sizeof(FaceNormals)/sizeof(FaceNormals[0]); i++) {
		float dotprod = glm::dot(normalizeOri, FaceNormals[i]);

		if (dotprod < min) {
			min = dotprod;
			dir = static_cast<Direction>(i);
		}

	}


	return dir;
}

