#include <iostream>
#include "aodsystem.h"
#include "cards.h"

int AODSYS::judge(PLAYER &p,AI &a)
{
	int player_dead=0;
	int ai_dead=0;
	for(int n=1;n<=p.Pamount;n++)
	{
		int data_p=dataChanger<int>(p.Pdata[3*n]);
		if(data_p==0)
		{
			player_dead++;
		}
	}
	if(player_dead==p.Pamount)
	{
		return 0;
	}
	for(int m=1;m<=a.Aamount;m++)
	{
		int data_a=dataChanger<int>(a.Adata[3*m]);
		if(data_a==0)
		{
			ai_dead++;
		}
	}
	if(ai_dead==a.Aamount)
	{
		return 1;
	}
}
