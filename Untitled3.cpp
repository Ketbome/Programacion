#include <iostream>
using namespace std;
float terreno(int x[100][100]){
	int mayor, desnivel, suma=0;
	mayor= x[0][0];
	for (int i=0; i<100; i++){
		for (int j=0; j<100; j++){
			if(mayor < x[i][j]){
				mayor= x[i][j];
			}
		} 
	}
	for (int i=0; i<100; i++){
		for (int j=0; j<100; j++){
			suma = suma + (mayor - x[i][j])
		}
	} return suma; 
}
main(){
	int terren[100][100], total;
	total= terreno(terren);
	cout 
}
