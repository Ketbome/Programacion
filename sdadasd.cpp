#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Juego{
	private:
		int numero;
		string nombrejuego;
	public:
		Juego(int numeros, string nombrejuego){
			this->numero = numero;
			this->nombrejuego = nombrejuego;
		}
	    int get_numero(){
	    	return numero;
		}
		string get_nombre(){
			return nombrejuego;
		}
};

main ()
{
	map <int, string, vector<int> > juegos;
	string nombre;
	srand(time(NULL));
	int valor, num, opcion;
	while (true)
	{
		cout << "Ingrese nombre del juego o # para salir" << endl;
		cin >> fecha;
		if (nombre == "#")
		{
			break;
		}
		cout << "Ingrese cantidad de numero del juego" << endl;
		cin >> valor;
		if (juegos.find(nombre) == juegos.end()) //significa que no esta
		{
			vector <int> numeros;
			for(int i=0; i<valor; i++)
			{
				
			 	cout << "Ingrese numero " << i+1 << endl;
			 	cin >> num;
			 	numeros.push_back(num);
			 	
			}
			juegos[nombre] = numeros;
		}	
	}
	while (true)
	{
		cout << "1.- Consultar por numeros ganadores de un juego" << endl;
		cout << "2.- Imprimir los resultado de todos los juegos" << endl;
		cout << "3.- Consultar en que juegos de azar salio sorteado un numero especifico" << endl;
		cout << "4.- Salir" << endl;
		cin >> opcion;
		
		if (opcion == 1)
		{
			map<string, vector<int> > ::iterator b = juegos.begin();
			cout << "Ingrese juego" << endl;
			cin >> nombre;
			cout << "El numero ganador es: " << b->second[rand()%valor] << endl;
		}
		if (opcion == 2)
		{
			map<string, vector<int> > ::iterator b = juegos.begin(); // para recorrer el map
			while (b!=juegos.end())
			{
				cout << "Juego: "<<b->first << endl;
				for (int i=0; i<b->second.size(); i++) // porque el contenido es un vector
				{
					cout << b->second[i] << " ";
				}
				cout << endl;
				b++;
			}
		cout << endl;	
		}
		if (opcion == 3)
		{
			cout << "Ingrese numero que quiere consultar" << endl;
			cin >> num;
			
			map<string, vector<int> > ::iterator b = juegos.begin(); 
			while (b!=juegos.end())
			{
				for (int i=0; i<b->second.size(); i++) 
				{
					if (num == b->second[i])
					{
						cout << "El numero se encuentra en el juego: " << b->first << endl;
					}
				}
				b++;
			}
		}
	}
}
