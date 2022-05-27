#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
using namespace std;
class LibroAleer{
	protected:
		string nombre;
		string autor;
		string genero;
		
		public:
			LibroAleer(string nombre,string autor,string genero){
				this->nombre=nombre;
				this-> autor=autor;
				this->genero=genero;
			}
			void set_nombre(string nombre){
					this-> nombre=nombre;
				}
			void set_autor(string autor){
					this-> autor=autor;
				}
			void set_genero(string genero){
					this-> genero=genero;
				}
			string get_autor(){
					return autor;
				}
			string get_nombre(){
					return nombre;
				}
			string get_genero(){
					return genero;
				}
	
	
};
class LibroAvender {
	protected:
		string nombrevender;
		int precio;
		int anio;
		public:
			LibroAvender(string nombrevender, int precio, int anio){
				this->nombrevender=nombrevender;
				this-> precio=precio;
				this->anio=anio;
			}
			void set_nombrevender(string nombrevender){
					this-> nombrevender=nombrevender;
				}
			void set_precio(int precio){
					this->precio=precio;
				}
			void setAno(int anio){
					this-> anio=anio;
				}
				string get_nombrevender(){
					return nombrevender;
				}
				float get_precio(){
					return precio;
				}
				float get_anio(){
					return anio;
				}
			
	
};
int main (){
	int opcion,pre,ano, actual, nuevopre;
	stack <LibroAvender *> vender;
	string nom, aut, gen;
	queue <LibroAleer *> leer;
	vector <string> generos;
    
	
	while (opcion!=5){
		cout<<"1.- Agregar libro."<<endl;
		cout<<"2.- Leer libro."<<endl;
		cout<<"3.- Agregar libro a la venta."<<endl;
		cout<<"4.- Vender libro."<<endl;
		cout<<"5.- Salir"<<endl;
		cin>> opcion;
		switch (opcion){
			case 1:
				cout << "Ingrese Nombre del libro, autor y genero:"<< endl;
				cin >> nom >> aut >> gen;
				leer.push(new LibroAleer(nom,aut,gen));			
			    break;
			case 2:
			    cout << "Nombre: "<< leer.front()->get_nombre() <<endl<< "Autor: " << leer.front()->get_autor() << endl << "Genero: "<< leer.front()->get_genero() << endl;
				for (int i=0; i < generos.size() ; i++){
					if (generos[i] == leer.front()->get_genero()){
						cout << "Ya has leido un libro del mismo genero." << endl;
					}
				}
				generos.push_back(leer.front()->get_genero());
				leer.pop();				
				break;
			case 3:
			    cout << "Ingrese Nombre del libro, precio y anio comprado:"<< endl;
				cin >> nom >> pre >> ano;
				vender.push(new LibroAvender(nom,pre,ano));
				break;
			case 4:
				cout << "Ingrese el anio actual:"<< endl;
				cin >> actual;
				nuevopre = (vender.top()->get_precio())-(actual-(vender.top()->get_anio()))*1000;
				if(nuevopre<0) nuevopre=0;
				cout << "Nombre: "<< vender.top()->get_nombrevender() <<endl<< "Precio: " << nuevopre << endl;
				vender.pop();
				break;
			case 5:break;
				
				
	
				
		}
		
	}
	
	return 0;
}
