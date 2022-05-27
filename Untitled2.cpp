#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<char> noletra;
	string texto;
	cout<<"Ingrese el texto por verificar: "<<endl;
	getline(cin, texto);
	for(int i=97;i<123;i++){
		noletra.push_back(i);
	}
	for(int i=0;i<texto.length();i++){
		for(int j=0;j<noletra.size();j++){
			if(noletra.at(j)==texto[i]){ noletra.erase(noletra.begin()+j); break; }
		}
	}
	
	if(noletra.size()==0){ cout<<"No es lipograma."<<endl; return 0;
	}
	cout<<"Las letras que estan siendo omitidas son las siguientes: "<<endl;
	for(int i=0;i<noletra.size();i++){
		cout<<noletra.at(i)<<" ";
	}
	
	
	
	return 0;
}
