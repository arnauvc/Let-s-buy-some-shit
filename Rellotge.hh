/** @file Rellotge.hh
	@brief Classe Rellotge
*/

#ifndef RELLOTGE_HH
#define RELLOTGE_HH

#include <string>
#include <iostream>
using namespace std;


/** @class Rellotge
    @brief Representa un rellotge, té una <em>hora</em> i <em>data</em> en format string que poden ser consultades
    i modificades.
    */
class Rellotge{

private:	
    int hora, minuts, segons; // hora a la que entra
    int delta_segons; // segons que s'esta comprant

public:
	
 	/* Constructores */
	/** @brief Creadora per defecte.
		\pre cert
		\post El resultat és un rellotge nou, buit.
	*/ 
	Rellotge();

	
	/* Destructores */
	/** @brief Destructora per defecte.
		\pre Existeix rellotge.
		\post Destrueix el rellotge.
	*/
	~Rellotge();


	/* Consultores */
	/** @brief Consulta l’hora actual d’un rellotge.
		\pre Cert
		\post Retorna l’hora del paràmetre implícit en format string (HH:MM:SS).
	*/
	string consulta_hora();
	
	
	
	
	/** @brief Compara dos rellotges.
		\pre El paràmetre implícit i l'explícit son dos rellotges.
		\post Retorna 0 si són iguals, 1 si el paràmetre implícit és anterior a 
		<em>R2</em>, 2 altrament.
	*/
	//No se si ens fara falta o no :$ pero almenys ja esta implementada
	/* int compara_rellotges(Rellotge R2); */


	/* Modificadores */

	/** @brief 
		\pre 
		\post 
		
	*/
	void suma_temps(int s); //suma segons al parametre implicit
	
	
	/** @brief 
		\pre 
		\post 
		
	*/	
	void llegir_hora(); //llegeix un string amb l'hora de la forma HH:MM:SS

        string consulta_temps_fi_caixer();
};

#endif
