#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
string read(string data){
	ifstream covid("covid.csv");
	string line,line2;
	char letra;
	int i=0;
	int j=0;
	vector<string> datos[33];
	while( getline(covid, line,',')!=NULL ){
		datos[j].push_back(line);
		j++;
	    covid.get(letra);
		if(letra == '"'){
			getline(covid ,line, '"');
			covid.get(letra);
			if(letra=='"'){
		    	line+='"';
			}
			if(letra!=','){
				while(letra != ','){
					covid.putback(letra);
		    	    getline(covid ,line2, '"');
		    	    line+=line2;
		    	    covid.get(letra);
		    	    if(letra=='"'){
		    	    	line+='"';
					}
				}
			}
		    datos[j].push_back(line);
		    j++;
		}else{
			covid.putback(letra);
		}
	    if(j==33){
	    	for(int x=0; x <11 ; x++){
	    		getline(covid, line,',');
	    	}
		    j=0;
			i++;
		    }
	}
}

int main(){
	ifstream covid("covid.csv");
	string line,line2;
	char letra;
	int i=0;
	int j=0;
	vector<string> datos[33];
	while( getline(covid, line,',')!=NULL ){
		datos[j].push_back(line);
		j++;
	    covid.get(letra);
		if(letra == '"'){
			getline(covid ,line, '"');
			covid.get(letra);
			if(letra=='"'){
		    	line+='"';
			}
			if(letra!=','){
				while(letra != ','){
					covid.putback(letra);
		    	    getline(covid ,line2, '"');
		    	    line+=line2;
		    	    covid.get(letra);
		    	    if(letra=='"'){
		    	    	line+='"';
					}
				}
			}
		    datos[j].push_back(line);
		    j++;
		}else{
			covid.putback(letra);
		}
	    if(j==33){
	    	for(int x=0; x <11 ; x++){
	    		getline(covid, line,',');
	    	}
		    j=0;
			i++;
		    }
	}
	for(int y=0; y < 13480 ; y++){
		for(int x=0; x < 33 ; x++){
			cout << datos[x][y] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;	
}
