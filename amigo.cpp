#include<iostream>
using namespace std;

class Persona{
    protected:
        string Nombre;
        string Pasaporte;
        int Edad;
    public:
        Persona(string Nombre, string Pasaporte, int Edad){
            this->Nombre = Nombre;
            this->Pasaporte = Pasaporte;
            this->Edad = Edad;
        }
        void setNombre(string Nombre){
            this->Nombre = Nombre;
        }
        void setPasaporte(string Pasaporte){
            this->Pasaporte = Pasaporte;
        }
        void setEdad(int Edad){
            this->Edad = Edad;
        }
        string getNombre(){
            return Nombre;
        }
        string getPasaporte(){
            return Pasaporte;
        }
        int getEdad(){
            return Edad;
        }
};
class Piloto:public Persona{
    private:
        int AniosExperiencia;
        int Sueldo;
    public:
        Piloto(string Nombre, string Pasaporte, int Edad, int AniosExperiencia, int Sueldo):Persona(Nombre,Pasaporte,Edad){
            this->AniosExperiencia = AniosExperiencia;
            this->Sueldo = Sueldo;
        }
        void setAniosExperiencia(int AniosExperiencia){
            this->AniosExperiencia = AniosExperiencia;
        }
        void setSueldo(int Sueldo){
            this->Sueldo = Sueldo;
        }
        int getAniosExperiencia(){
            return AniosExperiencia;
        }
        int getSueldo(){
            return Sueldo;
        }
    };
class AuxiliarVuelo:public Persona{
    private:
        int Sueldo;
    public:
        AuxiliarVuelo(string Nombre, string Pasaporte, int Edad, int Sueldo):Persona(Nombre,Pasaporte,Edad){
            this->Sueldo = Sueldo;
        }
        void setSueldo(int Sueldo){
            this->Sueldo = Sueldo;
        }
        int getSueldo(){
            return Sueldo;
        }
    };
class Vuelo{
    private:
        Persona *Personas[250];
        Piloto *Pilotos[3];
        AuxiliarVuelo *AuxiliaresVuelo[5];
        int NumeroDeVuelo;
    public:
        Vuelo(int NumeroDeVuelo){
            this->NumeroDeVuelo = NumeroDeVuelo;
        }
        void setNumeroDeVuelo(int NumeroDeVuelo){
            this->NumeroDeVuelo = NumeroDeVuelo;
        }
        int getNumeroDeVuelo(){
            return NumeroDeVuelo;
        }
        int RegistrarPasajero(Persona *persona){
        	int conta=0;
        	for(int i=0;i<250;i++){
				if (Personas[i]==NULL){
				    Personas[i]=persona; 
				    break;
				}
			}
			for(int i=0;i<250;i++){
				if (Personas[i]!=NULL){
					conta=conta+1;
				}
			}
			return conta;
		}
	    int CantidadMenoresDeEdad(){
            int Contador=0, personas=0;
            for(int i=0;i<250;i++){
				if (Personas[i]!=NULL){
					personas=personas+1;
				}
			}
            for (int i=0 ; i < personas ; i++){
                if (Personas[i]->getEdad() < 18){
                    Contador = Contador + 1;
                }
            }     
            return Contador;
        }
        int CalcularCostoDelVuelo(){
        	int cont=0;
        	for(int i=0;i<250;i++){
				if (Personas[i]!=NULL){
					int cont=cont+1;
				}
			}
            return (cont-CantidadMenoresDeEdad())*40000+(CantidadMenoresDeEdad())*30000;
        }
        void TerminarVuelo(){
            for(int i=0 ; i<250 ; i++){
                Personas[i] = NULL;
            }
            for(int i=0 ; i<3 ; i++){
                Pilotos[i] = NULL;
            }
            for(int i=0 ; i<5 ; i++){
                AuxiliaresVuelo[i] = NULL;
            }
        }
};



int main(){
	
	return 0;
}
