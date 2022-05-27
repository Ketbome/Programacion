#include <iostream>
#include <queue>
#include <stack>
#include <string>
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
			void setNombre (string nombre){
					this-> nombre=nombre;
				}
			void setAutor (string autor){
					this-> autor=autor;
				}
			void setGenero (string genero){
					this-> genero=genero;
				}
				string getAutor (){
					return autor;
				}
				string getNombre (){
					return nombre;
				}
				string getGenero (){
					return genero;
				}
	
	
};
class LibroAvender {
	protected:
		string nombredos;
		float precio;
		float ano;
		public:
			LibroAvender(string nombredos, float precio, float ano){
				this->nombredos=nombredos;
				this-> precio=precio;
				this->ano=ano;
			}
			void setNombredos (string nombredos){
					this-> nombredos=nombredos;
				}
			void setPrecio (float precio){
					this->precio=precio;
				}
			void setAno (float ano){
					this-> ano=ano;
				}
				string getNombredos (){
					return nombredos;
				}
				float getPrecio (){
					return precio;
				}
				float getAno (){
					return ano;
				}
			
	
};
int main (){
	int op;
	queue <LibroAleer *> a;
	stack <LibroAvender *> b;
	vector <string>genero2;
	string genero,autor,nombre,nombre2;
	float ano,precio,year,nuevovalor;
	
	while (op!=5){
		cout<<"1) OPCION 1"<<endl;
		cout<<"2) OPCION 2"<<endl;
		cout<<"3) OPCION 3"<<endl;
		cout<<"4) OPCION 4"<<endl;
		cout<<"5) Salir"<<endl;
		cout<<"Digite una opcion ..."<<endl;
		cin>> op;
		switch (op){
			case 1:
	
		cout << "Ingrese nombre,autor y genero del libro"<< endl;
		cin >> nombre >> autor >> genero;
		a.push(new LibroAleer(autor,genero,nombre));
			break;
			case 2:
				cout << "Nombre: "<< a.front()->getNombre() <<endl<< "Autor: " << a.front()->getAutor() << endl << "Genero: "<< a.front()->getGenero() << endl;
				for (int i=0; i < genero2.size() ; i++){
					if (genero2[i] == a.front()->getGenero()){
						cout << "ya has leido el mismo genero" << endl;
					}
				}
				genero2.push_back(a.front()->getGenero());
				a.pop();		
				break;
			
				
				
				
				break;
			case 3:
				cout << "Ingrese el nombre del libro,precio del libro,ano en que fue comprado"<< endl;
		cin >> nombre2 >> precio >> ano;
		b.push(new LibroAvender(nombre2,precio,ano ));
				break;
			case 4:
				cout << "ingrese ano actual:"<< endl;
				cin >> year;
				nuevovalor = (b.top()->getPrecio())-(year-(b.top()->getAno()))*1000;
				cout << "Nombre: "<< b.top()->getNombredos() <<endl<< "Precio: " << nuevovalor << endl;
				b.pop();
				
				break;
				default:
				if (op<1||op>5){
					
					cout <<"numero no valido"<<endl;
					
				}
				break;
				
				
				
				
		}
		
	}
	
	return 0;
}
