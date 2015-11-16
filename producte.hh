#include <iostream>
#include <string>

using namespace std;

class producte{
  
  private:
    string nom;
    string seccio;
    double preu;
    int temps_cobrament;
    
  public:
  
  /* Constructora */
  /** @brief Creadora per defecte.
   * \pre Cert
   * \post El resultat es un producte sense inicialitzar
  */
  
  /*Destructora */
  /** @brief Destructora per defecte
   * \pre Existeix un producte
   * \post Destrueix el producte
  */ 
  
  
  /*Consultores*/
  /** @brief Consulta
   * 
  */
  
  /** @brief Escriu dades del producte
   * \pre Existeix un producte i esta inicialitzat
   * \post Escriu per pantalla el nom, la seccio,
   * el preu i el temps de cobrament del producte del parametre implicit
  */
  void escriu_producte();
}
