/** @file Tasca.hh
 @brief Especificació de la classe Tasca
 */

#ifndef _TASCA_HH
#define _TASCA_HH

#include <map>
#include "utils.PRO2"

/** @class  Tasca
 @brief Representa una tasca de l'agenda
 
 Cada tasca conté obligatoriament un títol i una data. A més a més,
 pot contenir etiquetes
 */

class Tasca
{
private:
    /**@brief Representa el títol d'una tasca */
    string titol;
    /**@brief Representa el conjunt d'etiquetes d'una tasca */
    map<string,string> etiquetes;
    
    /** @invariant Invariant de la representació:
     Totes les tasques contenen títol i data.
     No es pot diferenciar entre dates de segles diferents i suposarem que els dos darrers dígits de la
     data (x, y en la data **.**.xy) corresponen a un any de quatre xifres que comença per 20 (20xy).
     Les tasques futures són aquelles amb data posterior o igual a la del rellotge intern.
     Altrament es consideren passades
     */
    
    
public:
    /* Constructores */
    
    /** @brief Constructora sense paràmetres
     \pre cert
     \post Crea una tasca buida
     */
    Tasca();
    
    /** @brief Constructora amb titol concret
     \pre cert
     \post Crea una tasca amb títol "t"
     */
    Tasca(string t);
    
    
    /** @brief Creadora de tasca amb títol i data concrets.
     
     Crea una tasca amb títol i data (hora inclosa) definides per l'usuari
     \pre Un títol, una data i un conjunt d'etiquetes (pot ser buit)
     \post El resultat es una tasca amb títol "tit", dia "dd", mes "mm", any "aa", hora "h" i
           conjunt d'etiquetes "eti" (pot ser buit)
     */
    //Tasca (string tit, int dd, int mm, int aa, string h, list <string> eti);
    
    
    /* Modificadores de les tasques */
    
    /** @brief Modifica el títol d'una tasca 
     \pre cert
     \post La tasca passa a tenir el titol "t" si no pertany al passat. Altrament dóna missatge d' error
     */
    void modificar_titol(string t);    
    
    /** @brief Modifica la data d'una tasca futura
     \pre cert
     \post la data del p.i s'ha modificat
     */
    void modificar_data(int dd, int mm, int aa);
    
    /** @brief Modifica l' hora d'una tasca futura
     \pre cert
     \post l'hora del p.i passa a ser "h"
     */
    void modificar_hora(string h);

    /** @brief Afegeix una etiqueta a la tasca
     \pre cert
     \post s'ha afegit "etiqueta" al conjunt d'etiquetes del p.i
     */
    void afegir_etiqueta (string etiqueta);

     /** @brief Esborra totes les etiquetes de la tasca
     \pre cert
     \post Totes les etiquetes del p.i s'han esborrat
     */
    void esborrar_etiquetes();
    
    /** @brief Esborrar una etiqueta de la tasca
     \pre cert
     \post l'etiqueta "eti" s'ha borrat del p.i
     */
    void esborrar_etiqueta(string eti);

    /** @brief Mostra per pantalla les etiquetes d'una tasca
     \pre cert
     \post s'ha mostrat pel canal estàndard de sortida el conjunt d'etiquetes del p.i
     */
    void escriure_etiquetes();
    
    /** @brief Consulta el títol d'una tasca
     \pre cert
     \post s'ha mostrat pel canal estàndard de sortida el títol del p.i
     */
    void consultar_titol();
    
    /** @brief Retorna si la tasca conté o no una etiqueta concreta
     \pre cert
     \post Retorna cert si el p.i conté l'etiqueta "etiqueta".Altrament retorna fals
     */
    bool conte_etiqueta(string etiqueta);
    
     /** @brief Comprovació d'expressió booleana
     \pre cert
     \post Retorna cert si el p.i compleix una expressió booleana d'etiquetes "s"
     */
    bool comprovacio(string s);

    /** @brief Comprovació d'immersió d'expressió booleana
     \pre cert
     \post Retorna cert si una tasca compleix una expressió booleana d'etiquetes
     */
    bool comprovacio_ie(int& i, string s);
    
   
   
};

#endif
