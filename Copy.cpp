#include<iostream>
#include<vector>

class test
{
public:test();
	   test(const test&T);
	   ~test();
};
test::test()
{
	std::cout << "constructor" << std::endl;
}
test::~test()
{
	std::cout << "deconstructor" << std::endl;
}
test::test(const test &T)
{
	std::cout << "copy constructor" << std::endl;
}
int main()
{
	test a = test();
	test b = test();
	test c = test();
	std::vector<test>vec = { a,b,c };
	std::cout << "Hello World" << std::endl;
}