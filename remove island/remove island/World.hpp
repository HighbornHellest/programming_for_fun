#pragma once
#include "Header.h"

class World
{
private:
	unsigned long int width, height, size;
	std::vector<char> m_world;

public:
	World() = delete;
	World(int a, int b);
	void generate_new_world();
	std::vector<char> return_word();
	
	void out()
	{
		for (int i=0; i< size; ++i)
		{
			if (i%width == 0)
				std::cout << std::endl;
			std::cout<< m_world.at(i);
			
		}
	}

	void search_island();
	bool remove_if_island(int , int);
};

