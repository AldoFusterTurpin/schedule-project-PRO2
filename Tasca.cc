/** @file Tasca.cc
 @brief Codi de la classe Tasca
 */
#include "Tasca.hh"
Tasca::Tasca(){}
   
Tasca::Tasca (string tit){
    titol = tit;
}
    

void Tasca::modificar_titol(string t){
	titol = t;
}    
    

void Tasca::afegir_etiqueta (string etiqueta){
	if (etiquetes.find(etiqueta) == etiquetes.end())
		etiquetes[etiqueta] = etiqueta;
	//else cout << "No s'ha realitzat" << endl;
}

void Tasca::esborrar_etiquetes()	{
	etiquetes.clear();
} 

void Tasca::esborrar_etiqueta(string etiqueta){
	map<string, string>::iterator it = etiquetes.find(etiqueta);
	if (it != etiquetes.end()) etiquetes.erase(it);
	else cout << "No s'ha realitzat" << endl;
}

void Tasca::escriure_etiquetes(){
	map<string, string>::iterator it = etiquetes.begin();
	while (it != etiquetes.end()){
		cout << " " << it->first;//(*it).first
		++it;
	}
} 

void Tasca::consultar_titol(){
	cout << titol;
}
    
bool Tasca::conte_etiqueta(string etiqueta){
	map<string, string>::iterator it = etiquetes.find(etiqueta);
	return (it != etiquetes.end());
}


bool Tasca::comprovacio(string expressio){
	int i = 0;
	return comprovacio_ie(i, expressio);
}

bool Tasca::comprovacio_ie(int& i, string s) {
	bool b = false;
	if (s[i] == '#') {
		int j = i + 1;
		while (s[j] != '.' and s[j] != ',' and s[j] != ')') ++j;
		string etiq = s.substr(i, j - i);
		i = j;
		b = conte_etiqueta(etiq);
	}
	else if (s[i] == '('){
		++i;
		bool b1 = comprovacio_ie(i, s);
		char c = s[i];
		++i;
		bool b2 = comprovacio_ie(i, s);
		++i;
		if (c == '.') b = b1 and b2;
		else b = b1 or b2;
	}
	return b;
}
