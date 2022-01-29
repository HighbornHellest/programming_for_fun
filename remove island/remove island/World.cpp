#include "World.hpp"


World::World(int a, int b)
{
	this->width=a;
	this->height=b;
	this->size=a*b;
	std::cout << "a" << width << std::endl;
	std::cout << "b" << height << std::endl;
	std::cout << "c" << size <<std::endl;
	generate_new_world();
}

void World::generate_new_world()
{
	srand(time(NULL));

	for (int i = 0; i < size; ++i)
	{
		int a = rand() % 2;
		
		if (a)
			m_world.emplace_back('1');
		else
			m_world.emplace_back('0');

	}
}

std::vector<char> World::return_word()
{
	return this->m_world;
}