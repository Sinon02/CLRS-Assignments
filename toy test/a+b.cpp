#include<iostream>
#include<string>
#include<sstream>

int main()
{
	std::string str;
	int x, y;
	while(std::getline(std::cin,str))
	{
		std::istringstream is(str);
		is>>x>>y;
		std::cout<<x+y<<std::endl;
	}
	
	return 0;
}
