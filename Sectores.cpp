#include <iostream>
using namespace std;

int main(){
	int sectores, suma=0, mayor, menor, secmay=0, secmen=0;
	cout << "Cuantos sectores tiene la cuenca ";
	cin >> sectores;
	int aridos[sectores];
	for (int i=0; i<sectores ; i++){
		cout << "Ingrese la cantidad de aridos en el sector " << i+1 << " ";
		cin >> aridos[i];
		suma=suma+aridos[i];
	}
	mayor=aridos[0];
	secmay=1;
	menor=aridos[0];
	secmen=1;
	for (int i = 0 ; i < sectores ; i++){
		if(mayor < aridos[i]){
			mayor = aridos[i];
			secmay = i+1;
		}
		if(menor > aridos[i]){
			menor = aridos[i];
			secmen = i+1;
		}
	}
	cout << "El sector con mayor cantidad de aridos es "<< secmay << "." << endl;
	cout << "El sector con menor cantidad de aridos es "<< secmen << "." << endl;
	cout << "Los aridos en total de la cuenca son " << suma << "." << endl;
	
}
