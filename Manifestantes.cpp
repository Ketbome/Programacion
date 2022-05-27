#include<iostream>
using namespace std;
class Manifestante{
        protected:
        int Edad, Altura;
        string Razon;
        bool Grupo;
        public:
            Manifestante(int Edad, int Altura, string Razon, bool Grupo){
            this->Edad = Edad;
            this->Altura = Altura;
            this->Razon = Razon;
            this->Grupo = Grupo;
            }
        int getEdad (){
            return Edad;
        }
        int getAltura (){
            return Altura;
        }
        string getRazon (){
            return Razon;
        }
        bool getGrupo (){
            return Grupo;
        }
        void setEdad(int Edad){
            this->Edad=Edad;
        }
        void setAltura(int Altura){
            this->Altura=Altura;
        }
        void setRazon(string Razon){
            this->Razon=Razon;
        }
        void setGrupo (bool Grupo){
            this->Grupo=Grupo;
        }        
};






class Medico: public Manifestante{
    private:
    bool KitPrimerosAuxilios;
    public:
    Medico(int Edad, int Altura, string Razon, bool Grupo, bool KitPrimerosAuxilios):Manifestante( Edad, Altura,Razon,Grupo){
    this->KitPrimerosAuxilios = KitPrimerosAuxilios;
    }
    bool getKitPrimerosAuxilios (){
        return KitPrimerosAuxilios;
    }
    void setKitPrimerosAuxilios(bool KitPrimerosAuxilios){
        this->KitPrimerosAuxilios=KitPrimerosAuxilios;
    }
};




class Capucha: public Manifestante{
    private:
    int Piedras, Molotov;
    public:
    Capucha(int Edad, int Altura, string Razon, bool Grupo, int Piedras, int Molotov):Manifestante( Edad, Altura, Razon, Grupo){
    this->Piedras = Piedras;
    this->Molotov = Molotov;
    }
    int getPiedras (){
        return Piedras;
    }
    int getMolotov (){
        return Molotov;
    }
    void setPiedras (int Piedras){
        this->Piedras=Piedras;
    }
    void setMolotov (int Molotov){
        this->Molotov=Molotov;
    }
};





class PrimeraLinea: public Manifestante{
    private:
    string MaterialEscudo;
    bool MascaraAntiGas;
    public:
    PrimeraLinea(int Edad, int Altura, string Razon, bool Grupo, string MaterialEscudo, bool MascaraAntiGas):Manifestante(Edad, Altura, Razon, Grupo){
    this->MaterialEscudo = MaterialEscudo;
    this->MascaraAntiGas = MascaraAntiGas;
    }
    string getMaterialEscudo(){
        return MaterialEscudo;
    }
    bool getMascaraAntiGas(){
        return MascaraAntiGas;
    }
    void setMaterialEscudo (string MaterialEscudo){
        this->MaterialEscudo=MaterialEscudo;
    }
    void setMascaraAntiGas(bool MascaraAntiGas){
        this->MascaraAntiGas=MascaraAntiGas;
    }
};


int main(){
    Manifestante *arreglo[50];
    int opcion, cont=0;
    int edad, altura, piedras, molotov;
    float edadmedia=0;
    bool grupo, kit, mascara;
    string razon,escudo;
    for(int i=0;i<50;i++){
    	arreglo[i]=NULL;
	}
    for(int i=0;i<50;i++){
        cout<<"Ingrese el tipo de manifestante (0 para terminar): "<<endl;
        cout<<"1.Medico."<<endl<<"2.Capucha."<<endl<<"3.Primera linea."<<endl;
        cin>>opcion;
        switch(opcion){
            case 0: break;
            case 1: cout << "Ingrese Edad, Altura, la razon de manifestarse, si viene en grupo y si lleva Kit de auxilio (0 es no y 1 es si): " << endl;
                cin >> edad >> altura >> razon >> grupo >> kit;
                arreglo[i] = new Medico(edad, altura, razon, grupo, kit);
            break;
        case 2: cout << "Ingrese Edad, Altura, la razon de manifestarse, si viene en grupo, cantidad de piedras y molotov (0 es no y 1 es si): " << endl;
                cin >> edad >> altura >> razon >> grupo >> piedras >> molotov;
                arreglo[i] = new Capucha(edad, altura, razon, grupo, piedras, molotov);
            break;
        case 3: cout << "Ingrese Edad, Altura, la razon de manifestarse, si viene en grupo, material de escudo y si lleva mascara de gas (0 es no y 1 es si): " << endl;
                cin >> edad >> altura >> razon >> grupo >> escudo >> mascara;
                arreglo[i] = new PrimeraLinea(edad, altura, razon, grupo, escudo, mascara);
            break;
        default: cout << "Numero incorrecto, ingrese nuevamente." << endl;
                 i = i-1;
                 break;
        }
        if (opcion == 0){
            break;
        }
             
        }
        for(int i=0;i<50;i++){
        	if(arreglo[i]!=NULL) { edadmedia+=arreglo[i]->getEdad(); cont++;}
		}
		edadmedia/=(float)cont;
		cout<<"La edad media es "<<edadmedia<<"."<<endl;
		int pequenio=arreglo[0]->getAltura();
		for(int i=0;i<cont;i++){
			if(pequenio>arreglo[i]->getAltura()) pequenio=arreglo[i]->getAltura();
		}
		cout<<"El manifestante mas pequenio mide "<<pequenio<<" cms."<<endl;
		
		
		
		string comun;
	 int mayor=0;
	 for (int i=0,conta=0;i<cont;i++,conta=0){
	 	for (int j=0;j<cont;j++){
	 		if (arreglo[i]->getRazon() == arreglo[j]->getRazon()){
	 			conta=conta+1;
			 }
		 }
	    if (mayor<conta){
	    	mayor=conta;
	    	comun=arreglo[i]->getRazon();
		}
	 }
	 cout << "La razon mas comun es: " << comun << endl;
        return 0;
    }
    


