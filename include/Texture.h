#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <iostream>
#include <map>

class Texture
{

public:
	Texture(std::string filename);
	void Use() const;

	unsigned int textureId;
private:
	int m_width, m_height, m_nrChannels;
};

struct fRect
{
	float x1=0;
	float y1=0;
	float x2=0;
	float y2=0;
};


class BlockTiles
{
public:
	enum Block{ dirt, grassTop, grassSide };

	static void Initialize( int width, int height);
	static fRect GetRectangle(Block block);
	static void SetBlockTile(Block block, int x, int y);

private:
	static glm::ivec2 m_nbTiles;
	static glm::vec2 m_tileSize;
	static std::map<Block, fRect> m_blockRectangles;
};