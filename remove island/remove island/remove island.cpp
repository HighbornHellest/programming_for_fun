// remove island.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"



int main()
{
	World world(  10,10 );

	world.out();
	std::cout << std::endl << std::endl << std::endl << std::endl;

	world.get_mainland();

}
