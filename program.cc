#include "comanda.hh"
#include "Agenda.hh" 

int main(){
	Agenda a;
    bool b;           // Falç si posem sortir
	Comanda c;
	while (c.llegir(b)){
		if (b) {
			if (c.es_rellotge()){
				if (c.es_consulta()) a.consultar_rellotge();
				else  a.modificar_rellotge(c);
			}
			else if(c.es_insercio())a.insercio(c);
			else if (c.es_consulta()) a.consultar_agenda(c);
			else if (c.es_modificacio()) a.modificar_tasca(c);
			else if(c.es_esborrat()){
				string t = c.tipus_esborrat();
				int n = c.tasca() - 1;
				if (t == "etiquetes") a.esborrar_etiquetes(n);
				else if (t == "etiqueta") a.esborrar_etiqueta(n, c.etiqueta(1));
				else a.esborrar_tasca(n);			
			}
		}
	}
}
