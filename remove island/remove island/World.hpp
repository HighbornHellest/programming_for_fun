#pragma once
#include "Header.h"

class World
{
private:
	unsigned long int width, height, size;
	std::vector<char> m_world;
	std::map< std::tuple<int, int>, int> borders;

bool is_border(int i);

public:

	World() = delete;
	World(int a, int b);
	void generate_new_world();

	
	void out()
	{
		for (int i=0; i< size; ++i)
		{
			if (i%width == 0)
				std::cout << std::endl;
			std::cout<< m_world.at(i);
			
		}
	}

	void get_mainland();
	void bordercrawl();
};

