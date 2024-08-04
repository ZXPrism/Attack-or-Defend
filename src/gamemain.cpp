#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "cards.h"
#include "AI.h"
#include "user.h"
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
			std::system("cls");
			break;
		}
		ai_module.decide(player_module,d);
	    d.draw(ai_module,player_module);
		int j2=a.judge(player_module,ai_module);
		if(j2==0)
		{
			std::cout<<"You lose! Try to be the winner next time!"<<std::flush;
			Sleep(2000);
			std::system("cls");
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
    CARD card_module(5,"D:\\cards.txt");
    //card_module.display();
    while(1)
    { 
        battle(card_module,display_module,aodsys_module);
        std::cout<<"����?����1���¿�ʼ��Ϸ������0������Ϸ"<<std::endl;
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
			std::cout<<"�����ǲ��Ե�Ŷ!"<<std::endl;
			Sleep(1000);
			break;
		}
		else if(choice==666)
		{
			std::cout<<"лл�佱."<<std::endl;
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

