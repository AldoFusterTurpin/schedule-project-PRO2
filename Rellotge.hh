/** @file Rellotge.hh
@brief Especificació de la classe Rellotge
 */

#ifndef _RELLOTGE_HH
#define _RELLOTGE_HH

#include "utils.PRO2"

/** @class Rellotge
 @brief Conte una hora, un dia, un mes i un any.
    La data inicial del rellotge és 20.04.15 i l'hora les 00:00.
 */
class Rellotge {
    
private:
    /** @brief Representa l'hora del Rellotge */
    string hora;
    /** @brief Representa el dia de la data del Rellotge */
    int dia;
    /** @brief Representa el mes de la data del Rellotge */
    int mes;
    /** @brief Representa l'any de la data del Rellotge */
    int any;
    
public:
    // Constructora
    Rellotge(); /* DATA INICIAL: 20.04.15 00:00 */
    
    // Modificadores 
    
    /** @brief Modifica només l'hora del rellotge intern de l'Agenda
     \pre cert
     \post L'hora del rellotge passa a ser "h" si no és anterior a l'actual sinó dona missatge d'error
     */
//    void modificar_rellotge(string h);
    
    /** @brief Modifica només la data del Rellotge 
     \pre cert
     \post La data del parametre implicit es modifica si no és anterior a l'actual, sinó dona missatge d'error
     */
  //  void modificar_rellotge(int dd, int mm, int aa);
    
    /** @brief Modifica l'hora i la data del Rellotge 
     \pre cert
     \post l'hora i la data del rellotge passa a ser la suposadament actual si no és anterior a l'actual, sinó dona missatge d'error
     */
    //void modificar_rellotge(string h, int dd, int mm, int aa);
    
    // Consultores
    /** @brief Consulta l'hora(i data) actual del Rellotge 
     \pre: cert
     \post: retorna un objecte rellotge de la classe Rellotge
     */
    //Rellotge consultar_rellotge();
    
    /** @brief Modifica l'hora del rellotge
     \pre: cert
     \post: modifica l'hora del rellotge
     */
    void  modificar_hora(string h);
    
    /** @brief Modifica la data del rellotge
     \pre: cert
     \post: la data del rellotge passa a ser "data"
     */
    void modificar_data(string data);
    
    /** @brief Modifica l'hora i la data del rellotge
     \pre: cert
     \post: el relloge (p.i) passa a tenir hora "h" i data "data"
     */
    void modificar_rellotge(string h, string data);
    
	/** @brief Comprova si una data externa "d" i la del rellotge són iguals
     \pre: cert
     \post: retorna cert si la data del p.i és igual a la data "d". Altrament retorna fals
     */
    bool dates_iguals(string d) const;	
    
    /** @brief Compara si el p.i (rellotge) és anterior cronològicament al rellotge "r"
     \pre: cert
     \post: retorna cert si el p.i és anterior cronològicament al rellotge "r".Altrament retorna fals
     */
    bool  operator < (const Rellotge& r) const;

    
    /** @brief Compara si el p.i (rellotge) és igual cronològicament al rellotge "r"
     \pre: cert
     \post: retorna cert si el p.i és igual al rellotge "r"
     */
    bool operator == (const Rellotge& r) const;
    	
  
    /** @brief Mostra per pantalla el rellotge
     \pre: cert
     \post: mostra per pantalla el p.i (rellotge)
     */
    void  mostrar_rellotge() const;
    	
};
#endif
