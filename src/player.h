#ifndef PLAYER_H
#define PLAYER_H
#include "cards.h"
#include "AI.h"
#include "aodsystem.h"
#include "display.h"
class AI;
class DISPLAY;
class PLAYER
{
	public:
		friend class AI;
		friend class USER;
		friend class DISPLAY;
		friend class AODSYS;
		PLAYER(unsigned int amount):Pamount(amount){};
		void selectcard(CARD &c);
		void operate(AI &a,DISPLAY &d);
		void damage_display(std::string attacker,std::string is_attacked,int damage);
	private:
		unsigned int Pamount;
		std::vector<std::string> Pdata;
};
#endif
