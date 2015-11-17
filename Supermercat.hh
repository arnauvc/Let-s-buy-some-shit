#include <iostream>
#include <strng>
#include "Producte.hh"
#include "Client.hh"

using namespace std;

class supermercat{
  
  public:
    int rengles // nombre de rengles
    int columnes // nombre de columnes
    int caixes // nombre de caixes
    vector < pair<productes,int>> // sort i despres stable_sort
    map<> //Conte tots els productes possibles, mapejats segons seccio i ordenats alfabeticament
  
  
  private:
  /*Constructora*/
  
  /** @brief Creadora per defecte.
   * \pre Cert
   * \post El resultat es un supermercat sense inicialitzar*/
  Supermercat();
  
  
  /*Destructora */
  
  /** @brief Destructora per defecte
   * \pre Existeix un producte
   * \post Destrueix el producte
  */ 
  ~Supermercat();
  
  /** @brief 
   * \pre 
   * \post 
  */ 
  void inicialitza();
  
  /** @brief 
   * \pre 
   * \post 
  */ 
  void carrega();
  
  /** @brief 
   * \pre 
   * \post 
  */
  void simula();
  
  /** @brief 
   * \pre 
   * \post 
  */
  void informa(); //retorna escriu
  
  /** @brief 
   * \pre 
   * \post 
  */
  void producte_seccio(); //escriu per pantalla tots els productes de la seccio
  // o bé "seccio buida" si no hi ha productes a la seccio
  
  /** @brief 
   * \pre 
   * \post 
  */
  void millor cami();
  

 };
#endif

