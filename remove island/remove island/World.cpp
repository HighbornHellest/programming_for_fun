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

std::vector<char> World::return_word()
{
	return this->m_world;
}

void World::search_island()
{
	for (int i = 0; i < size; ++i)
	{
		//edges
		if (i <= this->width || i%width==0 || i%width==width-1 || i>=size-width)
		{
			continue;
		}
		if (m_world.at(i) == 0)
		{
			continue;
		}
		else
		{

		}
		
	}
}



//if it turns out to be an island, return false
//if there's a path to mainland, return true
bool World::remove_if_island(int a, int previous)
{

	/*mainland*/
	//if upper edge and it's a word
	if (a <= this->width && m_world.at(a) ==1)
	{
		return TRUE;
	}
	//left side 
	if (a%width == 0 && m_world.at(a)==1)
	{
		return TRUE;
	}
	//right side
	if (a%width == width - 1 && m_world.at(a) == 1)
	{
		return TRUE;
	}
	//bottom side
	if (a > m_world.size() - width && m_world.at(a) == 1)
	{
		return TRUE;
	}
	/*end of mainland*/

	//up, down, left, right
	if ( remove_if_island(a-width,a) || remove_if_island(a+width,a)||remove_if_island(a-1,a) || remove_if_island(a+1,a))
	{
		
	}

}