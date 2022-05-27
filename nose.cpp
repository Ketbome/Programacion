#include <iostream>
#include <vector>
using namespace std;

class Participante{
	private:
		string Nombre, Pais, Pasaporte;
	public:
		Participante(string Nombre, string Pasaporte, string Pais){
			this->Nombre = Nombre;
			this->Pais = Pais;
			this->Pasaporte = Pasaporte;
		}
		void set_Nombre(string Nombre){
			this->Nombre = Nombre;
		}
		void set_Pasaporte(string Pasaporte){
			this->Pasaporte = Pasaporte;
		}
		string get_Nombre(){
			return Nombre;
		}
		string get_Pasaporte(){
			return Pasaporte;
		}
		string get_Pais(){
			return Pais;
		}
		
};

class Campeonato{
	private:
		vector<Participante *> nuevo;
		vector<string> pais;
	public:
		bool llegaParticipanteNuevo(Participante *p){
			for(int i =0 ; i < pais.size(); i++){
				if (pais[i]==p->get_Pais()){
					return 0;
				}
			}
			pais.push_back(p->get_Pais());
			nuevo.push_back(p);
		}
		bool saleParticipantePais(string Pais){
			for (int i=0; i < nuevo.size(); i++){
				if (Pais== nuevo[i]->get_Pais()){
					nuevo.erase(nuevo.begin()+i);
				}
			}
		}
		bool cambioParticipantePais(string pais, Participante *p){
			for(int i=0; i < nuevo.size(); i++){
				if (pais == nuevo[i]->get_Pais()){
					nuevo[i] = p;
				}
			}
		}
		void imprimeTodosLosParticipantes(){
			for (int i=0; i < nuevo.size() ; i++){
				cout << nuevo[i]->get_Pais() << " = " << nuevo[i]->get_Nombre() << endl;
			}
		}
};


int main(){
Campeonato camp2019;
camp2019.llegaParticipanteNuevo(new Participante("Jose", "P038639-5", "Eslovenia"));
camp2019.llegaParticipanteNuevo(new Participante("Maria", "X03ddf8-R", "Islandia"));
camp2019.llegaParticipanteNuevo(new Participante("Luis", "9863490", "Turquia"));
camp2019.llegaParticipanteNuevo(new Participante("Pedro", "936777-4", "Chile"));
camp2019.llegaParticipanteNuevo(new Participante("Norma", "198000-K", "Islandia"));
camp2019.saleParticipantePais("Turquia");
camp2019.cambioParticipantePais("Chile", new Participante("Juan", "123342-M", "Chile"));
camp2019.imprimeTodosLosParticipantes();
return 0;
}

