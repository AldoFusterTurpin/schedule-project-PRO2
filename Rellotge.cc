/** @file Rellotge.cc
@brief Codi de la classe Rellotge
 */
#include "Rellotge.hh"    
		//Comprovar al main: esrellotge--consulta/modificacio--si es modificacio--assegurarse que lhora que entra es bona;	

Rellotge::Rellotge(){ /* DATA INICIAL: 20.04.15 00:00 */
	hora = "00:00";
	dia = 20;
	mes = 04;
	any = 15;
}

void Rellotge::modificar_hora(string h){
  	hora = h;
}

void Rellotge::modificar_data(string data){
    dia = (data[0]-'0')*10+data[1]-'0';
    mes = (data[3]-'0')*10+data[4]-'0';
    any = (data[6]-'0')*10+data[7]-'0';
}
       
void Rellotge::modificar_rellotge(string h, string data){
    hora = h;
    dia = (data[0]-'0')*10+data[1]-'0';
    mes = (data[3]-'0')*10+data[4]-'0';
    any = (data[6]-'0')*10+data[7]-'0';
}

bool Rellotge::dates_iguals(string data) const {
    int dia1 = (data[0]-'0')*10+data[1]-'0';
    int mes1 = (data[3]-'0')*10+data[4]-'0';
    int any1 = (data[6]-'0')*10+data[7]-'0';
    return dia == dia1 and mes == mes1 and any == any1;
}
	
bool Rellotge:: operator < (const Rellotge& r) const {
	bool petit = true;
	if (any > r.any) petit = false;
	else if (any == r.any) {
		if (mes > r.mes) petit = false;
		else if(mes == r.mes){
			if (dia > r.dia) petit = false;
			else if (dia == r.dia)
				petit = hora < r.hora;    			
		}
	}
	return petit;
}

bool Rellotge:: operator == (const Rellotge& r) const{
    return (any == r.any and mes == r.mes and dia == r.dia and hora == r.hora);
}

void Rellotge:: mostrar_rellotge() const{
    if (dia < 10) cout << "0";
    cout << dia << ".";
    if (mes < 10) cout << "0";
    cout << mes << ".";
    if (any < 10) cout << "0";
    cout << any << " " << hora;
}
