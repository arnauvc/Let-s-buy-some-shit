/** @file Producte_client.hh
    @brief Classe Producte_client
*/

#ifndef PRODUCTE_CLIENT_HH
#define PRODUCTE_CLIENT_HH

#include <iostream>
#include <string>

using namespace std;

class Producte_client{

  private:
    map<string,int> mapProdClient;//nom del producte i la quantitat de cada producte

  public:
    /* Constructora */

    /** @brief Creadora per defecte.
     * \pre Cert
     * \post El resultat es un Client amb el torn, la caixa, numero
     * de productes i lhora de la compra
    */
    Producte_client();

    /*Destructora */

    /** @brief Destructora per defecte
     * \pre Existeix un Client
     * \post Destrueix el Client
    */
    ~Producte_client();
    
    /** @brief Consultora per defecte
     * \pre cert
     * \post retorna la quantitat de productes
    */
    int consulta_quantitat(string n);

};
#endif
