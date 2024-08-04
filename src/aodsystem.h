#ifndef AODSYS_H
#define AODSYS_H
#include <string>
#include "player.h"
#include "AI.h"

class AI;
class PLAYER;
class AODSYS
{
	public:
		friend class AI;
		friend class CARDS;
		friend class USER;
		friend class DISPLAY;
		AODSYS(std::string v):version(v){};
		int judge(PLAYER &p,AI &a);
	private:
		std::string version;
};
#endif
