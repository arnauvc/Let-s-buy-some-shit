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
   
  /* Pre:                               */
  /* Post: el resultat es el producte amb el nom, seccio, preu, temps cobrament */
  Producte(string nom, string seccio, double preu, int temps_cobrament);
  
  
  
  /*Destructora */
  
  /** @brief Destructora per defecte
   * \pre Existeix un producte
   * \post Destrueix el producte
  */ 
  ~Producte();
  
  
  /*Consultores*/
  
  
  // Falta posar a cada funcio, un nom codificat amb doxygen, aka  @brief bla bla bla !!
  
  
  
  /* Pre: cert */
  /* Post: el resultat es el nom del parametre implicit */
  string consulta_nom(string nom);
  
  /* Pre: cert */
  /* Post: el resultat es la seccio del parametre implicit */
  string consulta_seccio(string seccio);
  
  /* Pre: el parametre implicit te preu */
  /* Post: el resultat es el preu del parametre implicit */
  double consulta_preu(double preu);
  
  /* Pre: El parametre implicit te el temps de cobrament inicialitzat */
  /* Pro: el resultat es el temps de cobrament del parametre implicit */
  int consulta_temps(int temps_cobrament);
  
  
  
  /** @brief Escriu dades del producte
   * \pre Existeix un producte i esta inicialitzat
   * \post Escriu per pantalla el nom, la seccio,
   * el preu i el temps de cobrament del producte del parametre implicit
  */
  
  
  /* Pre: hi ha preparats al canal estandar d'entrada */
  /* Post: el parametre implicit passa a tenir els atributs llegits del canal estandard d'entrada */
  void llegir_producte();
  
  
  /* Pre: cert */
  /* Post: s'han escrit els atributs del parametre implicit al canal estandard de sortida */
  void escriu_producte() const;
  
  

};
#endif

