/** @file Agenda.cc
 @brief Codi de la classe Agenda
*/
#include <iostream>
#include "Agenda.hh"
#include "comanda.hh"
using namespace std;

Agenda::Agenda() {
	menu = vector<map<Rellotge,Tasca>::iterator> (MENU_SIZE);
	nElementsMenu = 0;
}

void Agenda::mostar_rellotge() const{
    rellotge.mostrar_rellotge();
}

void Agenda::esborrar_tasca(int n) {
	if (n < nElementsMenu and menu[n] != agenda.end()) {
		Rellotge r = menu[n]->first;
		if (r < rellotge) cout << "No s'ha realitzat" << endl;
		else {
			agenda.erase(menu[n]);
			menu[n] = agenda.end();
		}
	}
	else cout << "No s'ha realitzat" << endl;
}

void Agenda::esborrar_etiqueta(int n, string t){
	if (n < nElementsMenu and menu[n] != agenda.end()) {
		Rellotge r = menu[n]->first;
		if (r < rellotge) cout << "No s'ha realitzat" << endl;
		else menu[n]->second.esborrar_etiqueta(t);
	}
	else cout << "No s'ha realitzat" << endl;
}
void Agenda::esborrar_etiquetes(int n){
	if (n < nElementsMenu and menu[n] != agenda.end()) {
		Rellotge r = menu[n]->first;
		if (r < rellotge) cout << "No s'ha realitzat" << endl;
		else menu[n]->second.esborrar_etiquetes();
	}
	else cout << "No s'ha realitzat" << endl;
}

void Agenda::insercio(Comanda &c){
	Rellotge r = rellotge;
	r.modificar_hora(c.hora());
	if (c.nombre_dates() == 1) r.modificar_data(c.data(1));
	map<Rellotge, Tasca >::iterator it = agenda.find(r);
	if (it == agenda.end() and (not (r < rellotge))) {
		Tasca nova;
		nova.modificar_titol(c.titol());
		agenda[r] = nova;
		int i = 0;
		while (i < c.nombre_etiquetes()){
			agenda[r].afegir_etiqueta(c.etiqueta(i + 1));
			++i;
		}
	}
	else cout << "No s'ha realitzat" << endl;
}	

void Agenda::escriure_menu() {
	int i = 0;
	while (i < nElementsMenu) {
		cout << i+1 << " ";
		menu[i]->second.consultar_titol();
		cout << " ";
		menu[i]->first.mostrar_rellotge();
		menu[i]->second.escriure_etiquetes();
		cout << endl;
		//if (menu[i]->first < rellotge) menu[i] = agenda.end();
		++i;
	}
}

void Agenda::consultar_rellotge(){
	rellotge.mostrar_rellotge();
	cout << endl;
}

void Agenda::modificar_rellotge(Comanda& c){
	Rellotge r = rellotge;
	if (c.te_hora() and c.nombre_dates() == 1) r.modificar_rellotge(c.hora(), c.data(1));
	else if (c.te_hora()) r.modificar_hora(c.hora());
	else r.modificar_data(c.data(1));
	
	if (not (r < rellotge)) rellotge = r;
	else cout << "No s'ha realitzat" << endl;
}

void Agenda::consultar_passat() {
	map<Rellotge, Tasca>::iterator it_final = agenda.lower_bound(rellotge);//it sempre inici
	map<Rellotge, Tasca>::iterator it_inici = agenda.begin();                    //it2 sempre final
	int cont = 0;
	while (it_inici != it_final) {
		if (nElementsMenu < MENU_SIZE) menu[nElementsMenu] = it_inici;
		else menu.push_back(it_inici);
		++nElementsMenu;
		++it_inici;
	}
}

void Agenda::consultar_dates(Comanda& c, map<Rellotge,Tasca>::iterator& it_inici, map<Rellotge,Tasca>::iterator& it_final) {
	it_inici = it_final = agenda.end();	
	Rellotge r1;
	if (rellotge.dates_iguals(c.data(1))) r1 = rellotge;
	else r1.modificar_rellotge("00:00", c.data(1));
	if (c.nombre_dates() == 1 and not (r1 < rellotge)) {
		it_inici = agenda.lower_bound(r1);
		r1.modificar_hora("23:59");
		it_final = agenda.upper_bound(r1);
	}
	else if (c.nombre_dates() == 2) {
		Rellotge r2;
		r2.modificar_rellotge("23:59", c.data(2));
		if (not (r2 < r1)) {
			if (r1 < rellotge) 
				it_inici = agenda.lower_bound(rellotge);
			else
				it_inici = agenda.lower_bound(r1);
			if (r2 < rellotge) 
				it_final = it_inici;
			else  
				it_final = agenda.upper_bound(r2);			  			
		}
	}
}

void Agenda::consultar_etiq(string etiq, map<Rellotge,Tasca>::iterator it_inici, map<Rellotge,Tasca>::iterator it_final) {
	while (it_inici != it_final) {
		if (it_inici->second.conte_etiqueta(etiq)) {
			if (nElementsMenu < MENU_SIZE) menu[nElementsMenu] = it_inici;
			else menu.push_back(it_inici);
			++nElementsMenu;
		}
		++it_inici;
	}
}

void Agenda::consultar_exp(string expressio, map<Rellotge,Tasca>::iterator it_inici, map<Rellotge,Tasca>::iterator it_final) {
	while (it_inici != it_final) {
		if (it_inici->second.comprovacio(expressio)) {
			if (nElementsMenu < MENU_SIZE) menu[nElementsMenu] = it_inici;
			else menu.push_back(it_inici);
			++nElementsMenu;
		}
		++it_inici;
	}
}

void Agenda::consultar_agenda(Comanda &c) {
	menu = vector<map<Rellotge,Tasca>::iterator> (MENU_SIZE);
	nElementsMenu = 0;
	if (c.es_passat()) consultar_passat();
	else if (c.te_expressio() or c.nombre_etiquetes() or (c.nombre_dates() > 0)) {
	 	map<Rellotge,Tasca>::iterator it_i = agenda.lower_bound(rellotge);
		map<Rellotge,Tasca>::iterator it_f = agenda.end();
		if (c.nombre_dates() > 0) consultar_dates(c, it_i, it_f);
		if (c.nombre_etiquetes() == 1) consultar_etiq(c.etiqueta(1), it_i, it_f);
		else if (c.te_expressio()) consultar_exp(c.expressio(), it_i, it_f);
		else {
			while (it_i != it_f) {
				if (nElementsMenu < MENU_SIZE) menu[nElementsMenu] = it_i;
				else menu.push_back(it_i);
				++nElementsMenu;
				++it_i;
			}
		}
	}
	else {
	 	map<Rellotge, Tasca>::iterator it_inici = agenda.lower_bound(rellotge);
	 	while (it_inici != agenda.end()) {
			if (nElementsMenu < MENU_SIZE) menu[nElementsMenu] = it_inici;
			else menu.push_back(it_inici);
			++nElementsMenu;
			++it_inici;
		}
	}
	escriure_menu();
}
    
void Agenda::interseccio(const vector<map<Rellotge,Tasca>::iterator>& v1, const vector<map<Rellotge,Tasca>::iterator>& v2, const vector<map<Rellotge,Tasca>::iterator>& v3, Comanda& c) {
	bool b1, b2, b3;
	b1 = c.nombre_dates() > 0;
	b2 = c.nombre_etiquetes() > 0;
	b3 = c.te_expressio();
	if (b1 and (not b2) and (not b3)) {
		menu = v1;
		nElementsMenu = v1.size();
	}
	else if ((not b1) and b2 and (not b3)) {
		menu = v2; 
		nElementsMenu = v2.size();
	}
	else if ((not b1) and (not b2) and b3) { 
		menu = v3;
		nElementsMenu = v3.size();
	}
	else if (not b2)
		interseccio_aux(v1, v3);
	else if (not b3) 
		interseccio_aux(v1, v2);
}

void Agenda::interseccio_aux(const vector<map<Rellotge,Tasca>::iterator>& v1, const vector<map<Rellotge,Tasca>::iterator>& v2) {
	nElementsMenu = 0;
	int i, j;
	i = j = 0;
	while (i < v1.size() and j < v2.size()) {
		if (v1[i] == v2[j]) {
			if (nElementsMenu < MENU_SIZE) menu[nElementsMenu] = v1[i];
			else menu.push_back(v1[i]);
			++nElementsMenu;
			++i; ++j;
		}
		else if (v1[i]->first < v2[j]->first)
			++i;
		else ++j;
	}
}

void Agenda::modificar_tasca(Comanda &c) {//modifiquem k-essima
	if (c.tasca()-1 < nElementsMenu) {
		map<Rellotge, Tasca>::iterator it = (menu[c.tasca()-1]);
		if (it != agenda.end()) {
			if (it->first < rellotge) cout << "No s'ha realitzat" << endl;
			else {
				if (c.te_titol()) {
					it->second.modificar_titol(c.titol());
				}
				int i = 0;
				while (i < c.nombre_etiquetes()){
					it->second.afegir_etiqueta(c.etiqueta(i + 1));
					++i;
				}
				if ((c.te_hora() or c.nombre_dates() == 1)) {
					Tasca t = it->second;
					Rellotge r = it->first;
					if (c.te_hora() and c.nombre_dates() == 1) r.modificar_rellotge(c.hora(), c.data(1));
					else if (c.te_hora()) r.modificar_hora(c.hora());
					else r.modificar_data(c.data(1));
					if (not (r < rellotge)) {
						if (agenda.find(r) != agenda.end()) cout << "No s'ha realitzat" << endl;
						else {
							agenda.erase(it);
							agenda[r] = t;
							menu[c.tasca()-1] = agenda.find(r);
						}
					}
					else {
						cout << "No s'ha realitzat" << endl;
						it = agenda.end();
					}
				}
			}
		}
		else cout << "No s'ha realitzat" << endl;
	}
	else cout << "No s'ha realitzat" << endl;
}
