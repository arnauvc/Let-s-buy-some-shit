/** @file Client.hh
	@brief Classe Client
*/
#ifndef CLIENT_HH
#define CLIENT_HH

#include <iostream>
#include "Rellotge.hh"
#include "Producte.hh"
#include <map>

using namespace std;

class Client{
   
  private:
   int torn;//numero de torn
   int caixa; //numero de caixa
   static const int LAST_CAIXA = 20; // numero maxim de caixes
   int num_productes; //nombre de unitats de productes. 
   map<string,int> producte_client;//nom del producte i la quantitat de cada producte
   bool assignat;
   Rellotge R;//HH:MM:SS del tiquet
    
  public:
  
  /* Constructora */
  
  /** @brief Creadora per defecte.
   * \pre Cert
   * \post El resultat es un Client amb el torn, la caixa, numero
   * de productes i lhora de la compra
  */
  Client();
  
  /*Destructora */
  
  /** @brief Destructora per defecte
   * \pre Existeix un Client
   * \post Destrueix el Client
  */
  ~Client();

   /*Modificadors*/
   
   /** @brief Afegeix numero de caixa
    * \pre el parametre implicit no te #caixa 
    * \post el resultat es el #caixa 
   */
   void afegir_caixa(int caixa);
   
   
    /** @brief Creadora amb parametres.
   * \pre comproba que el client tingui caixa o no.
   * \post Si te caixa sera cert, sino no té serà fals 
   */
   bool te_caixa();

   
   /*Consultores*/
   
   /** @brief Consulta el torn del client
    * \pre cert
    * \post el resultat es el torn del client del parametre implicit
   */
   int consultar_torn() const;
   
   /** @brief
    * \pre cert
    * \post el resultat la caixa que pertoca al client del parametre implicit
   */
   int consultar_caixa() const;
   
   //Doxygen documentacio
   int consultar_num_productes() const; //retorna numero de productes del client del parametre implicit
   
   /** @brief
    * \pre cert
    * \post el resultat es la hora del ticket del parametre implicit
   */
   string consultar_hora() const;
   
   string consultar_hora_despres_caixer() ;
   
   
   void sumar_segons(int s);
   
   
  
  
   /** @brief
    * \pre cert
    * \post introdueix els parametres del client
   */
   void llegeix_Client();
};
#endif
