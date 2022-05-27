//Laboratorio Javier Molina y Pablo Moraga.
#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<string> palabra;
	vector<char> letra;
	string pbra;
	cout << "Ingrese su texto(T para terminar):" << endl;
	//Texto
	while(true){
		cin >> pbra;	         
		if(pbra=="T"){
			break;
		}
		palabra.push_back(pbra);
	}
	for(int i=97; i<123 ; i++){
		letra.push_back(i);
	}
	for(int i=0; i < palabra.size() ; i++){
		for (int j=0; j < palabra[i].size() ; j++){
			for (int t=0; t < letra.size() ; t++){
				if(palabra[i].at(j) == letra.at(t)){
					letra.erase(letra.begin()+t);
					break;
				}
			}
		}
	}
	if (letra.size()==0){
		cout << "No es lipograma.";
		return 0;
	}
	cout << "Las palabras omitidas son: " << endl;
	for (int i=0; i < letra.size() ; i++){
		cout << letra[i] << " ";
	}
}
	


