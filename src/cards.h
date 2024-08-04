#ifndef CARDS_H
#define CARDS_H
#include <vector>
#include <string>
#include <sstream>
class CARD
{
	public:
		friend class AI;
		friend class PLAYER;
		CARD(unsigned int amount,char res_path[20]);
		void search();
		void display();
		void reset();
		unsigned int showdata();
		int showamount();
	private:
	std::vector<std::string> Cdata;
	unsigned  int Camount;
};

template <typename T>T dataChanger(const std::string &str)
{
	std::istringstream i(str);  
    T target;  
    i >> target;  
    return target;
}
#endif
