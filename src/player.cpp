#include <iostream>
#include <vector>
#include <Windows.h>
#include "player.h"

void PLAYER::damage_display(std::string attacker,std::string is_attacked,int damage)
{
	std::cout<<std::endl;
	std::cout<<attacker<<"��"<<is_attacked<<"�����"<<damage<<"���˺�"<<std::endl;
	Sleep(1500);
}

void PLAYER::selectcard(CARD &c)
{
	std::system("cls");
	std::string nulldata("0");
	this->Pdata.push_back(nulldata);
	std::vector<int> selected;
	selected.push_back(0);
	unsigned int num=0;
	unsigned int times=0;
	unsigned int need=0;
	for(int n=1;n<=c.Camount;n++)
	{
		std::cout<<"["<<n<<"]"<<c.Cdata[3*n-2]<<std::endl;
	}
	std::cout<<"����������Ҫ�Ŀ�Ƭ����."<<std::endl;
	std::cin>>need;
	std::cout<<"����������ѡ��Ŀ�Ƭ�����(��ͬ���֮���ÿո�ָ���������Ϻ󰴻س�)"<<std::endl; 
	while(std::cin>>num)
	{
		times++;
		selected.push_back(num);
		this->Pamount++;
		if(times==need)
		{
			break;
		}
	}
	
	for(int m=1;m<=times;m++)
	{
		int index=selected[m];
		this->Pdata.push_back(c.Cdata[3*index-2]);
		this->Pdata.push_back(c.Cdata[3*index-1]);
		this->Pdata.push_back(c.Cdata[3*index]);
	}
	std::cout<<"[From Console] ����װ�����!"<<std::endl;
}

void PLAYER::operate(AI &a,DISPLAY &d)
{
	std::cout<<"��������Ҫ���𹥻����ҷ���Ƭ���."<<std::endl; 
	int index_p=0;
	int index_e=0;
	while(1)
	{
		std::cin>>index_p;
		int targethp_p=dataChanger<int>(this->Pdata[3*index_p]);
		if(targethp_p==0)
		{
			d.draw(a,*this);
			std::cout<<"�˿�Ƭ��ʧȥս������. ����������:"<<std::endl; 
		}
		else
		{
			break;
		}
	}
	std::cout<<"�����뱻�����ĵз���Ƭ���"<<std::endl;
	while(1)
	{
		std::cin>>index_e;
		int targethp_e=dataChanger<int>(a.Adata[3*index_e]);
		if(targethp_e==0)
		{
		    d.draw(a,*this);
			std::cout<<"��Ŀ�꿨Ƭ��ʧȥս������. ���������룺"<<std::endl; 
		}
		else
		{
			break;
		}
	} 
	std::string damage_temp=this->Pdata[(index_p*3)-1];
	std::string hp_temp=a.Adata[index_e*3];
	int damage=dataChanger<int>(damage_temp);
	int hp=dataChanger<int>(hp_temp);
	std::string attacker=this->Pdata[index_p*3-2];
	std::string is_attacked=a.Adata[index_e*3-2];
	if(hp<damage)
	{
		std::string new_hp1("0");
		a.Adata[index_e*3]=new_hp1;
		std::cout<<attacker<<"������"<<is_attacked<<std::endl; 
		Sleep(1000);
	}
	else if(hp>=damage)
	{
		int hp_tempx=hp-damage;
		std::string new_hp2=std::to_string(hp_tempx);
		a.Adata[3*index_e]=new_hp2;
		this->damage_display(attacker,is_attacked,damage);
	}
}
