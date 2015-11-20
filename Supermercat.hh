/** @file Supermercat.hh
	@brief Classe Supermercat
*/
#include <iostream>
#include <string>
#include "Producte.hh"
#include "Client.hh"

using namespace std;

class Supermercat{
  
  private:
    int rengles; // nombre de rengles
    int columnes; // nombre de columnes
    int caixes; // nombre de caixes
    vector< vector<set<Producte>>> vec_productes(rengles, vector<set>(columnes));// podem inicialitzar a (26,9)
    
    
  public:
  /*Constructora*/
  
  /** @brief Creadora per defecte.
   * \pre Cert
   * \post El resultat es un supermercat sense inicialitzar
  */
  Supermercat();
  
  
  /*Destructora */
  
  /** @brief Destructora per defecte
   * \pre Existeix un producte
   * \post Destrueix el producte
  */ 
  ~Supermercat();
  
  /** @brief Inicialitza els valors del supermercat del parametre implicit
   * \pre Cert
   * \post Modifica els camps del paramtre implicit
  */ 
  void inicialitza(r,c,x,n);
  
  /** @brief Afegeix clients amb els respectius productes associats
   * \pre Cert
   * \post Guarda la llista de clients amb els productes associats
  */ 
  void carrega();
  
  /** @brief Simula els pagaments
   * \pre Existeix un supermercat, iniciaitzat i carregat en el parametre implicit. S'especifica el nombre de configuracions diferents
   * \post Escriu per pantalla el temps mitja de pagament segons la configuracio
  */
  void simula();
  
  /** @brief Dona informacio d'un producte concret 
   * \pre Existeix el producte i esta inicialitzat
   * \post Escriu per pantalla el nom, preu, seccio i temps de cobrament del producte del parametre implicit
  */
  void informa(); //retorna escriu
  
  /** @brief Escriu tots els productes d'una seccio 
   * \pre Supermercat inicialitzat i carregat
   * \post Escriu per pantalla tots els productes que pertanyen a la seccio especificada
  */
  void producte_seccio(s); //escriu per pantalla tots els productes de la seccio
  // o bé "seccio buida" si no hi ha productes a la seccio
  
  /** @brief Busca el millor cami per recorre el supermercat
   * \pre supermercat inicialitzat i carregat
   * \post Escriu per pantalla les seccions en l'ordre que s'han de recorre
  */
  void millor_cami();
  

 };
 
#endif

