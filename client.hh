#include <iostream>
#include "Rellotge.hh"

using namespace std;

class Client{
   
  private:
    int torn //numero de torn
    int caixa //numero de caixa
    static const int LAST_CAIXA = 20;
    int productes //nombre de unitats de productes. 
    //Sactualitza cada cop que s'afegeix un producte
    Rellotge R //HH:MM:SS del tiquet
    
  public:
  
  /* Constructora */
  
  Client();
  
  Client(int torn, int caixa, int producte, Rellotge R);
  /** @brief Creadora per defecte.
   * \pre Cert
   * \post El resultat es un Client amb el torn, la caixa, numero
   * de productes i lhora de la compra
  */
  
  /*Destructora */
  /** @brief Destructora per defecte
   * \pre Existeix un Client
   * \post Destrueix el Client
  */ 
   ~Client();
   
   //Modificadors
   
   void afegir_caixa(int caixa);
   /* Pre: el parametre implicit no te #caixa */
   /* Post: el resultat es la
   
   void modificar_caixa(int caixa);
   
   void afegir_producte(int producte);
   
   //Consultors
   int consultar_torn(int torn) const;
   
   Rellotge consulta_hora(Rellotge R) const;
  
  
  
  
}
