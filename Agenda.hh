/** @file Agenda.hh
 @brief Especificació de la classe Agenda
*/
#ifndef _AGENDA_HH
#define _AGENDA_HH
/** @class Agenda
 @brief Conté un conjunt de tasques ordenades cronológicament
 */
#include "Rellotge.hh"
#include "Tasca.hh"
#include "comanda.hh"

class Agenda {
    
private:
    /** @brief Conjunt de les tasques consultades ordenades cronológicament i amb índexos (1ª, 2ª...) */
    vector< map<Rellotge,Tasca>::iterator > menu; 
    /** @brief Rellotge que conté el temps actual de l'agenda */
    Rellotge rellotge;
    /** @brief Conjunt de tasques ordenades cronològicament */
    map<Rellotge,Tasca> agenda;
    /** @brief Nombre de tasques del menú */
    int nElementsMenu;
    /** @brief Mida estàndar del menú */
    static const int MENU_SIZE = 20;
    
public:
    Agenda();//crea una agenda buida
    
    /** @brief Mostra el rellotge d'Agenda
     \pre cert
     \post Mostra el rellotge del p.i 
     */
    void mostar_rellotge() const;
    
        
    /** @brief Esborra directament una tasca
     \pre n és un nombre enter
     \post La tasca n-éssima del menú s'ha esborrat del p.i s'hi s'ha trobat al menú.Altrament dóna missatge d'error
     */
    void esborrar_tasca(int n);
    
    /** @brief Esborra una etiqueta d'una tasca
     \pre cert
     \post La tasca n-éssima del menú s'ha esborrat del p.i si s'ha trobat i existeig"t.Altrament d'óna missatge d'error
     */
    void esborrar_etiqueta(int n, string t);

    /** @brief Esborra les etiquetes d'una tasca
     \pre cert
     \post S'han esborrat totes les etiquetes del p.i (la tasca a que es refereix la n-éssima del Menú)
     */
    void esborrar_etiquetes(int n);

    /** @brief Llegeix una comanda que es refereix a una inserció
     \pre cert
     \post S'ha modificat el rellotge o el conjunt de tasques depenent del tipus d'inserció
     */
    void insercio(Comanda &c);
    
    /** @brief Mostra per pantalla el menú del p.i
     \pre cert
     \post S'ha mostrat pel canal estàndard de sortida el menú del p.i
     */
    void escriure_menu();
    
    /** @brief Mostra per pantalla el relotge del p.i
     \pre cert
     \post S'ha mostrat pel canal estàndard de sortida el rellotge del p.i
     */
    void consultar_rellotge();

    /** @brief Modifica el rellotge del p.i
     \pre cert
     \post S'ha modificat el rellotge del p.i en funció del contingut de la comanda
     */
    void modificar_rellotge(Comanda& c);
    
    /** @brief Mostra per pantalla el conjunt de tasques del p.i que formen part del passat
     \pre cert
     \post S'ha mostrat pel canal estàndard de sortida el conjunt de tasques del p.i que formen part del passat
     */
    void consultar_passat();
    
    /** @brief Mostra per pantalla el conjunt de tasques del p.i en l'interval de dues dates
     \pre cert
     \post S'ha mostrat pel canal estàndard de sortida el conjunt de tasques del p.i que formen part d'un interval de dues dates
     */
    void consultar_dates(Comanda& c, map<Rellotge,Tasca>::iterator& it_inici, map<Rellotge,Tasca>::iterator& it_final);
    
    /** @brief Crea un menú del p.i amb aquelles tasques que contenen una etiqueta concreta
     \pre cert
     \post S'ha creat un nou menú amb aquelles tasques que contenen l'etiqueta "etiq"
     */
    void consultar_etiq(string etiq, map<Rellotge,Tasca>::iterator it_inici, map<Rellotge,Tasca>::iterator it_final);
    
    /** @brief Crea un menú del p.i amb aquelles tasques que compleixen una expressió booleana
     \pre cert
     \post S'ha creat un nou menú amb aquelles tasques que compleixen l'espressió booleana "expressio"
     */
    void consultar_exp(string expressio, map<Rellotge,Tasca>::iterator it_inici, map<Rellotge,Tasca>::iterator it_final);
    
    /** @brief Crea i mostra per pantalal un menú del p.i depenent del tipus de comanda
     \pre cert
     \post S'ha creat un nou menú amb aquelles tasques que compleixen la comanda i s'ha mostrat pel canal estàndar de sortida
     */
    void consultar_agenda(Comanda &c);
    
    /** @brief Fa la intersecció de tres conjunts de tasques que compleixen unes certes propietats segons la comanda
     \pre cert
     \post S'ha creat un nou menú amb aquelles tasques que complien la comanda
     */
    void interseccio(const vector<map<Rellotge,Tasca>::iterator>& v1, const vector<map<Rellotge,Tasca>::iterator>& v2, const vector<map<Rellotge,Tasca>::iterator>& v3, Comanda& c);
    
    /** @brief Fa la intersecció de dos conjunts de tasques que compleixen unes certes propietats segons la comanda
     \pre cert
     \post S'ha creat un nou menú amb aquelles tasques que complien la comanda
     */
    void interseccio_aux(const vector<map<Rellotge,Tasca>::iterator>& v1, const vector<map<Rellotge,Tasca>::iterator>& v2) ;

    /** @brief Modifica una tasca del conjunt de tasques del p.i
     \pre cert
     \post S'ha modificat la tasca del p.i segons la comanda
     */
    void modificar_tasca(Comanda &c);
    
};
#endif
