#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include "AI.h"

void AI::damage_display(std::string attacker,std::string is_attacked,int damage)
{
	std::cout<<std::endl;
	std::cout<<attacker<<"给"<<is_attacked<<"造成了"<<damage<<"点伤害"<<std::endl;
	Sleep(1500);
}

AI::AI(unsigned int amount,CARD &c)
{
	std::string nulldata("0");
	this->Adata.push_back(nulldata);
	this->Aamount=amount;
	for(int n=1;n<=amount;n++)
	{
		this->Adata.push_back(c.Cdata[3*n-2]);
		this->Adata.push_back(c.Cdata[3*n-1]);
		this->Adata.push_back(c.Cdata[3*n]);
	}
	std::cout<<"AI has been loaded."<<std::endl;
}

void AI::godAI()
{
	for(int n=1;n<=this->Aamount;n++)
	{
		std::string goddata("32768");
		this->Adata[3*n-1]=goddata;
		this->Adata[3*n]=goddata;
	}
}

void AI::attack(PLAYER &p,DISPLAY &d)
{
	int result1=0;
	int result2=0;
	while(1)
	{
		static std::default_random_engine e1(3640);
	    static std::uniform_int_distribution<unsigned int> u1(1,this->Aamount);
	    result1=u1(e1);
	    int target1=dataChanger<int>(this->Adata[3*result1]);
	    if(target1==0)
	    {
	    	continue;
		}
		else
		{
			break;
		}
	}
	
	while(1)
	{
		static std::default_random_engine e2(2193);
		static std::uniform_int_distribution<unsigned int> u2(1,p.Pamount);
        result2=u2(e2);
		int target2=dataChanger<int>(p.Pdata[3*result2]);
		if(target2==0)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	
	int damage=dataChanger<int>(this->Adata[3*result1-1]);
	std::string attacker=this->Adata[3*result1-2];
	std::string is_attacked=p.Pdata[3*result2-2];
	int hp=dataChanger<int>(p.Pdata[3*result2]);
	
	if(hp<damage)
	{
		std::string new_hp1("0");
		p.Pdata[3*result2]=new_hp1;
		std::cout<<attacker<<"击败了"<<is_attacked<<std::endl; 
		Sleep(1000);
	}
	
	else if(hp>=damage)
	{
		int hp_temp=hp-damage;
		std::string new_hp2=std::to_string(hp_temp);
		p.Pdata[3*result2]=new_hp2;
		this->damage_display(attacker,is_attacked,damage);
    }
}

void AI::defend(PLAYER &p,DISPLAY &d)
{
	;
}

void AI::decide(PLAYER &p,DISPLAY &d)
{
	std::vector<int> AIhp;
	for(int n=1;n<=this->Aamount;n++)
	{
		int hpvalue=dataChanger<int>(this->Adata[3*n]);
		AIhp.push_back(hpvalue);
	}
	std::sort(AIhp.begin(),AIhp.end());
	if(AIhp[0]<=1000&&AIhp[0]>=0)
	{
		this->attack(p,d);
	}
	else if(AIhp[0]>=1000)
	{
	    this->attack(p,d);	
	}
	else if(AIhp[0])
	{
	    this->attack(p,d);	
	}
}
