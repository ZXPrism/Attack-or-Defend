#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "cards.h"
#include "os.h"

int CARD::showamount()
{
	return this->Camount;
}

CARD::CARD(unsigned int amount,char res_path[20])
{
	std::ifstream i;
	this->Camount=amount;
	std::string datain;
	this->Cdata.push_back(datain);
	i.open(res_path);
	while(std::getline(i,datain))
	{
		this->Cdata.push_back(datain);
	}
	std::cout<<"Data has been loaded successfully."<<std::endl;
}

void CARD::reset()
{
	std::vector<std::string> reset;
	std::string nulldata("0");
	for(int n=0;n<=this->Camount;n++)
	{
		reset.push_back(nulldata);
		reset.push_back(nulldata);
		reset.push_back(nulldata);
	}
	this->Cdata=reset;
	std::cout<<"DATARESET!!!"<<std::endl;
}

void CARD::display()
{
    Clear();
	std::cout<<"****************THE DATA OF THE CARDS****************"<<std::endl;
	for(int m=1;m<=this->Camount;m++)
	{
		std::cout<<"名称:"<<this->Cdata[3*m-2]<<std::endl;
		std::cout<<"攻击力:"<<this->Cdata[3*m-1]<<std::endl;
		std::cout<<"生命值:"<<this->Cdata[3*m]<<std::endl;
	}
}

void CARD::search()
{
	typedef std::vector<std::string>::iterator data;
	std::string name;
	while(0)
	{
		std::cout<<"Enter the card's name you want to search."<<std::endl;
		std::cin>>name;
		data result=std::find(this->Cdata.begin(),this->Cdata.end(),name);
		if(result==this->Cdata.end())
		{
			std::cout<<"No data. Try again? Enter 1 or 0"<<std::endl;
			int choice=0;
			std::cin>>choice;
			if(choice==1)
			{
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			data attack=result+1;
			data HP=result+2;
			std::cout<<"Name:"<<*result<<std::endl;
			std::cout<<"Attack:"<<*attack<<std::endl;
			std::cout<<"HP:"<<*HP<<std::endl;
			std::cout<<"Search again?Enter 1 or 0"<<std::endl;
			int choice2=0;
			std::cin>>choice2;
			if(choice2==1)
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
}

unsigned int CARD::showdata()
{
	std::vector<unsigned int> showhp;
	for(int m=1;m<=this->Camount;m++)
	{
		int data_hp=dataChanger<int>(this->Cdata[3*m]);
		showhp.push_back(data_hp);
	}
	std::sort(showhp.begin(),showhp.end());
	return showhp[0];
}

