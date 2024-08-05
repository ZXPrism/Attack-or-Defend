#include <iostream>
#include <cstdlib>
#include "os.h"
#include "cards.h"
#include "AI.h"
#include "player.h"
#include "display.h"
#include "aodsystem.h"

void battle(CARD &c,DISPLAY &d,AODSYS &a)
{
	int camount=c.showamount();
	PLAYER player_module(0);
	AI ai_module(camount,c);
	player_module.selectcard(c);
	d.draw(ai_module,player_module);
	while(1)
	{
		player_module.operate(ai_module,d);
		d.draw(ai_module,player_module);
		int j1=a.judge(player_module,ai_module);
		if(j1==1)
		{
			std::cout<<"The winner is you!!!Congratuation to you!!!"<<std::flush;
			Sleep(2000);
            Clear();
			break;
		}
		ai_module.decide(player_module,d);
	    d.draw(ai_module,player_module);
		int j2=a.judge(player_module,ai_module);
		if(j2==0)
		{
			std::cout<<"You lose! Try to be the winner next time!"<<std::flush;
			Sleep(2000);
            Clear();
			break;
		}
	}
}

int main()
{
    std::string ver("v1.0 Release");
    DISPLAY display_module(ver);
    display_module.logo();
    AODSYS aodsys_module(ver);
    CARD card_module(5,"cards.db");
    //card_module.display();
    Change_code_to_utf8();
    while(1)
    { 
        battle(card_module,display_module,aodsys_module);
        std::cout<<"重玩?输入1重新开始游戏，输入0结束游戏"<<std::endl;
        int choice=0;
		std::cin>>choice; 
		if(choice==1)
		{
			continue;
		}
		else if(choice==0)
		{
			break;
		}
		else if(choice==2)
		{
			std::cout<<"乱输是不对的哦!"<<std::endl;
			Sleep(1000);
			break;
		}
		else if(choice==666)
		{
			std::cout<<"谢谢夸奖."<<std::endl;
			Sleep(1000);
			break;
		}
		else
		{
			break;
		}
    }
    return 0;
}

