#include <iostream>
#include <fstream>
#include <string>
using namespace std;

main ()
{
	int region, denuncias2015, denuncias2016;
	int suma2015=0;
	int suma2016=0;
	int mayor=0, menor=200000;
	int regiones[15],regionesss[15];
	int nroregionmayor, nroregionmenor;
	int comunadenuncia=0;
	int porcentual=0, porcentuals=0;
	int regionporcentual;
	
	
	string comuna, comunasss;
	ifstream leer("C:\\Users\\Pablo-PC\\Downloads\\datosudp.txt");
	
	for(int i= 1; i<=15 ; i++) //Hace que no tenga nros anteriores y si no esta las denuncias del 2016 por region no funciona
	{
		regiones[i]=0;
		regionesss[i]=0;
	}
	
	while (!leer.eof() ) // aqui se ve lo de las denuncias 2016 2015 y las por region del 2016
	{
		leer>>region>>comuna>>denuncias2015>>denuncias2016;
		
	    for(int i= 1; i<=15 ; i++)
	    {
		
			if(region==i)
			{
				regiones[i] = regiones[i] + denuncias2016;	 
				regionesss[i] = regionesss[i] + denuncias2015;	 
			}
		}
	
	
	if(comunadenuncia < denuncias2016) //Aqui se hace lo de cual comuna es la que tiene mas denuncias del 2016 
	{
		comunasss = comuna;
		comunadenuncia= denuncias2016;
	}
	
	 
	 	
		suma2015 = suma2015 + denuncias2015;
		suma2016 = suma2016 + denuncias2016;
		
		
		cout<<region<<" "<<comuna<<" "<<denuncias2015<<" "<<denuncias2016<<endl;
	

	
	
	
	}
	for (int k=1; k<=15; k++) // aqui se ve la mayor y menor region con denuncias del 2016
	 {
	 	if(mayor < regiones[k])
	 	{
	 		mayor = regiones[k];
	 		nroregionmayor = k; 
		 }
		 else if(menor > regiones[k])
		 {
		 	menor = regiones[k];
		 	nroregionmenor = k;
		 }
	 }
	 
	 float porcentaje;
	 
	 for(int i=1; i<=15; i++){
	 	// Primero que nada se ve si la cantidad del 2016 es mayor a la del 2015
	 if (regiones[i] > regionesss[i]){
	 	// Lo que hacemos es sacar el porcentaje total del mayo con respecto al minimo PD. el minimo siempre sera un 100% y como el otro es mayor dara mas del 100% (regla de 3)
	 	porcentaje=regiones[i]*100/regionesss[i];
	 	if (porcentual < porcentaje){
	 		//porcentual es como el mayor porcentaje entonces guardamos en porcentual el mayor porcentaje de todos los que van quedando
	 		porcentual=porcentaje;
	 		// y aca la region
	 		regionporcentual=i;
		 }
	 }
	}


for(int j=1; j<=15; j++)
{

	cout<<"Las denuncias del año 2016 en la " <<j << " region son: "<<regiones[j]<<endl;
}
   
   
   
   
   	cout<<"Los delitos del año 2015 son: "<<suma2015<<endl;
	cout<<"Los delitos del año 2016 son: "<<suma2016<<endl;
	
	cout<<"La region con mas delitos del año 2016 es la region "<<nroregionmayor<< " con "<< mayor<<" denuncias"<<endl;	
	cout<<"La region con menos delitos del año 2016 es la region "<<nroregionmenor<< " con "<<menor<<" denuncias"<<endl;
	
	cout<<"La comuna con mas delitos del año 2016 es la comuna "<<comunasss<< " con "<< comunadenuncia<<" denuncias"<<endl;	

	cout<<"La region con mayor aumento porcentual es la region "<<regionporcentual<< " con "<< porcentual-100<<" %"<<endl; // saque el porcentaje de diferencia y daria 150 le resto 100 para ver el aumento asi da los 50
	
	
	
	
	
	
	leer.close();
}
