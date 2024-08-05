#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <string>
#include "player.h"
class AI;
class PLAYER;
class DISPLAY
{
	public:
	    DISPLAY(std::string v):version(v){};
	    void logo();
	    void draw(AI &a,PLAYER &p);
	private:
		std::string version;
};
#endif
