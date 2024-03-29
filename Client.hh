/** @file Client.hh
	@brief Classe Client
*/
#ifndef CLIENT_HH
#define CLIENT_HH

#include <iostream>
#include "Rellotge.hh"
#include "Producte.hh"
#include <map>
#include <string>
#include <vector>

using namespace std;

class Client{
   
  private:
   int torn;//numero de torn
   int caixa; //numero de caixa
   static const int LAST_CAIXA = 20; // numero maxim de caixes
   int num_productes; //nombre de productes diferents. 
   int quantitat; //nombre d'unitats de producte
  vector< pair< string,int> > producte_quantitat;
   bool assignat;
   Rellotge R;//HH:MM:SS del tiquet
   int temps_desplacament, temps_caixer, temps_cua; // segons
    
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



    /** @brief
    * \pre cert
    * \post retorna numero de productes del client del parametre implicit
   */
   int consultar_num_productes() const;

string consultar_productes(int i) const;
			   
   int consultar_productes_quantitat(int i) const;

   int consultar_quantitat() const;
   
   /** @brief
    * \pre cert
    * \post el resultat es la hora del ticket del parametre implicit
   */
   Rellotge consultar_hora() const;
   
   /** @brief
    * \pre cert
    * \post el resultat es la hora del ticket despres de caixa del parametre implicit
   */
   string consultar_hora_despres_caixer() ;
   
   /** @brief
    * \pre cert
    * \post el resultat es la suma de segons dels productes
   */
   void sumar_segons(int s);
   
   /** @brief
    * \pre cert
    * \post introdueix els parametres del client
   */
   void llegeix_Client();

   int get_temps_desplacament();
   int get_temps_caixer();
   int get_temps_cua();
   void set_temps_desplacament(int);
   void set_temps_caixer(int);
   void set_temps_cua(int);
};
#endif
