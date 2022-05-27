#include <iostream>
using namespace std;
int main(){
	int a=2;
	int b=5;
	cout<< "a "<< a<< " b "<< b << endl;
	a+=b;
	b=a-b;
	a=a-b;
	cout<< "a "<< a<< " b "<< b << endl;
}
