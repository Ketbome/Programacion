#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ifstream covid("covid.csv");
	string line;
	char letra;
	getline(covid, line ,',');
	cout << line << endl;
	covid.get(letra);
	cout << letra << endl;
	getline(covid, line ,',');
	cout << line << endl;
	covid.get(letra);
	cout << letra << endl;
	covid.putback();
	getline(covid, line ,',');
	cout << line << endl;
	
}

