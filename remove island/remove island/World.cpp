#include "World.hpp"


World::World(int a, int b)
{
	this->width=a;
	this->height=b;
	this->size=a*b;
	generate_new_world();
}

void World::generate_new_world()
{
	srand(time(NULL));

	for (int i = 0; i < size; ++i)
	{
		int a = rand() % 2;
		// 1 is land 0 is sea
		if (a)
			m_world.emplace_back('1');
		else
			m_world.emplace_back('0');

	}
}


bool World::is_border(int i)
{
	if (i == 0)
		return true;

	int s = m_world.size();

	//left		//right				//top		/bottom
	if (s%i == 0 || s % i == s - 1 || i < s - 1 || i >= s - width)
	{
		return true;
	}
	return false;
}

void World::get_mainland()
{
	for (int i = 0; i < this->m_world.size(); ++i)
	{

		if (this->m_world[i] == '1' && is_border(i))
		{
			borders.emplace(std::make_tuple(i, i), TRUE);
		}
	}
}

void World::bordercrawl()
{

}