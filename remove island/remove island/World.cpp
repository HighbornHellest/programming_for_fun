#include "World.hpp"


World::World(int a, int b)
{
	this->width=a;
	this->height=b;
	this->size=a*b;
	//generate_new_world();
	this->m_world = { '1', '0', '0', '0', '0', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1', '0', '0', '1', '0', '0', '0', '1', '1', '1', '0','1','0','0','0','0','1','1','0', '1', '0', '1', '1', '1', '0', '1', '0', '0', '1', '0', '0', '0', '1', '1', '1','0','0','0','1','1','0','0','0','1','0','0','1','0','0','1','0','1','0','0','0','1','0','1','0','0','0','1','1','0','0','1','0','0','0','0','1','0','1','1','0','1','0','1','1','0','0','1','0','1','0','1','1','0','1','1','1','1','1','1','0','0','0','1','1','0','1','1','1','1','1','0','1','1','1','0','1'};
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

			borders.emplace(i, TRUE);
			bordercrawl(i, i);
		}
	}
	delete_islands();
}

//if out of bounds, return true, else false
bool World::outofbounds(int i)
{
	if (i == 0)
		return FALSE;

	if (i - this->width < 0 || i + width > this->m_world.size() || i + 1 > this->m_world.size() || i - 1 < 0)
		return TRUE;
	return FALSE;
}


//previous i, current i
void World::bordercrawl(int pi, int i)
{
	
	if (!is_border(i))
	{
	
		//up
		int ti = i - width;
		if (!outofbounds(ti) && ti != pi)
		{
			if (m_world[ti] == '1')
			{
				std::cout <<"i: " <<i<<" "<< m_world[i] << std::endl;
				borders.emplace(i, TRUE);
				bordercrawl(i, ti);
			}
		}
		//down
		ti = i + width;
		if (!outofbounds(ti) && ti != pi)
		{
			if (m_world[ti] == '1')
			{
				borders.emplace(i, TRUE);
				bordercrawl(i, ti);
			}
		}
		//left
		ti = i - 1;
		if (!outofbounds(ti) && ti != pi)
		{
			if (m_world[ti] == '1')
			{
				borders.emplace(i, TRUE);
				bordercrawl(i, ti);
			}
		}

		//right
	
		ti = i + 1;
		if (!outofbounds(ti) && ti != pi)
		{
			if (m_world[ti] == '1')
			{
				borders.emplace(i, TRUE);
				bordercrawl(i, ti);
			}
		}
	}
}

void World::delete_islands()
{
	
	for (int i = 0; i < size; ++i)
	{
		auto it = borders.find(i);
		

		if (it==borders.end())
		{
			this->m_world.at(i) = '0';
		}
	
	}
}