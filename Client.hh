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
  
  /** @brief Creadora per defecte.
   * \Pre: Cert
   * \Post: El resultat es un Client amb el torn, la caixa, numero
   * de productes i lhora de la compra
  */
  Client();
  
  
  /** @brief Creadora amb parametres.
   * \Pre: Cert
   * \Post: El resultat es un Client amb el torn, la caixa, numero
   * de productes i lhora de la compra
  */
  Client(int torn, int caixa, int producte, Rellotge R);
  
  /*Destructora */
  
  /** @brief Destructora per defecte
   * \Pre: Existeix un Client
   * \Post: Destrueix el Client
  */
  ~Client();

   /*Modificadors*/
   
   /** @brief Afegeix numero de caixa
    * \Pre: el parametre implicit no te #caixa 
    * \Post: el resultat es el #caixa 
   */
   void afegir_caixa(int caixa);
   
   /** @brief
    * \Pre: el parametre implicit ja te caixa pero es massa lent 
    * \Post: el resultat es un canvi de caixa 
   */
   void modificar_caixa(int caixa);
   
   /** @brief
    * \Pre: el parametre implicit no te productes 
    * \Post: afegeix productes al parametre implicit
   */
   void afegir_producte(int producte);
   
   /*Consultores*/
   
   /** @brief Consulta el torn del client
    * \Pre: cert
    * \Post: el resultat es el torn del client del parametre implicit
   */
   int consultar_torn(int torn) const;
   
   /** @brief
    * \Pre: cert
    * \Post: el resultat la caixa que pertoca al client del parametre implicit
   */
   int consultar_caixa(int caixa);
   
   /** @brief
    * \Pre: cert
    * \Post: el resultat es la hora del ticker del parametre implicit
   */
    
   Rellotge consulta_hora(Rellotge R) const;
}
