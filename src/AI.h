#ifndef AI_H
#define AI_H
#include <vector>
#include <string>
#include "cards.h"
#include "player.h"
#include "display.h" 
#include "aodsystem.h"

class AI
{
	public:
		friend class DISPLAY;
		friend class PLAYER;
		friend class AODSYS;
	    AI(unsigned int amount,CARD &c);
	    void decide(PLAYER &p,DISPLAY &d);
        void attack(PLAYER &p,DISPLAY &d);
	    void defend(PLAYER &p,DISPLAY &d);
	    void killAI();
	    void godAI();
	    void damage_display(std::string attacker,std::string is_attacked,int damage);
	private:
		std::vector<std::string> Adata;
		unsigned int Aamount;
};
#endif
