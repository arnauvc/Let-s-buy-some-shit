#include <iostream>
#include "Rellotge.hh"

using namespace std;

class Client{
   
  private:
    int torn //numero de torn
    int caixa //numero de caixa
    static const int LAST_CAIXA = 20; // numero maxim de caixes
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
  
  ~Client();
  /** @brief Destructora per defecte
   * \pre Existeix un Client
   * \post Destrueix el Client
  */ 

   /*Modificadors*/
   
   void afegir_caixa(int caixa);
   /* Pre: el parametre implicit no te #caixa */
   /* Post: el resultat es el #caixa*/
   
   void modificar_caixa(int caixa);
   /* Pre: el parametre implicit ja te caixa pero es massa lent*/
   /* Post: el resultat es una caixa mes rapida*/
   
   void afegir_producte(int producte);
   /* Pre: el parametre implicit no te productes */
   /* Post: afegeix productes al parametre implicit */
   
   /*Consultors*/
   int consultar_torn(int torn) const;
   /* Pre: cert */
   /* Pro: el resultat es el torn del client del parametre implicit*/
   
   int consultar_caixa(int caixa);
   /* Pre: cert */
   /* Pro: el resultat la caixa que pertoca al client del parametre implicit*/
   
   Rellotge consulta_hora(Rellotge R) const;
   /* Pre: cert */
   /* Pro: el resultat es la hora del ticker del parametre implicit*/
}
