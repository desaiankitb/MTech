#include <iostream>
using namespace std;
class A
{
	private:
		int i;
	public:
		void getData(void);
		void printData(void);
};
void A::getData(void)
{
	cout << "\nEnter value of i";
	cin >> i;
}
void A::printData(void)
{
	cout << "\nvalue of i =" << i;
}

int main()
{
	A ob;
	ob.getData();
	ob.printData();
	return 0;
}
