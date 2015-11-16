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
  Producte();
  /** @brief Creadora per defecte.
   * \pre Cert
   * \post El resultat es un producte sense inicialitzar*/
  Producte(string nom, string seccio, double preu, int temps_cobrament);
  /* Pre:                               */
  /* Post: el resultat es el producte amb el nom, seccio, preu, temps cobrament */
  
  /*Destructora */
  
  ~Producte();
  /** @brief Destructora per defecte
   * \pre Existeix un producte
   * \post Destrueix el producte
  */ 
  
  
  /*Consultores*/
  
  string consulta_nom(string nom);
  
  string consulta_seccio(string seccio);
  
  double consulta_preu(double preu);
  
  int consulta_temps(int temps_cobrament);
  /** @brief Consulta
   * 
  */
  
  /** @brief Escriu dades del producte
   * \pre Existeix un producte i esta inicialitzat
   * \post Escriu per pantalla el nom, la seccio,
   * el preu i el temps de cobrament del producte del parametre implicit
  */
  void llegir();
  
  void escriu_producte() const;
}
