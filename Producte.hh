/** @file Producte.hh
	@brief Classe Producte
*/

#include <iostream>
#include <string>

using namespace std;

class Producte{
  
  private:
    string nom;
    string seccio;
    double preu;
    int temps_cobrament;
    
  public:
  
  /* Constructora */
 
  /** @brief Creadora per defecte.
   * \pre Cert
   * \post El resultat es un producte sense inicialitzar*/
    Producte();
   
  /** @brief 
   * \pre Cert                             
   * \post el resultat es el producte amb el nom, seccio, preu, temps cobrament */
  Producte(string nom, string seccio, double preu, int temps_cobrament);
  
  /*Destructora */
  
  /** @brief Destructora per defecte
   * \pre Existeix un producte
   * \post Destrueix el producte
  */ 
  ~Producte();
  
  
  /*Consultores*/

  /** @brief Consultora de nom
   * \pre cert
   * \post el resultat es el nom del parametre implicit 
  */
  string consulta_nom(string nom);
  
  /** @brief Consultora de seccio
   *  \pre cert
   *  \post el resultat es la seccio del parametre implicit 
  */
  string consulta_seccio(string seccio);
  
  /** @brief Consultora del preu
   * \pre el parametre implicit te preu 
   * \post el resultat es el preu del parametre implicit 
  */
  double consulta_preu(double preu);
  
  /** @brief Consultora de temps
   *  \pre El parametre implicit te el temps de cobrament inicialitzat
   *  \post El resultat es el temps de cobrament del parametre implicit 
  */
  int consulta_temps(int temps_cobrament);
  
  
  
  
  
  
  /** @brief Llegeix dades del producte.
   * \pre Hi ha preparats al canal estandar d'entrada
   * \post El parametre implicit passa a tenir els atributs llegits del canal estandard d'entrada 
  */
  void llegir_producte();
  
  /** @brief Escriu dades del producte.
   * \pre Existeix un producte i esta inicialitzat
   * \post Escriu per pantalla el nom, la seccio,
   * el preu i el temps de cobrament del producte del parametre implicit
  */
  void escriu_producte() const;
  
  

};
#endif

