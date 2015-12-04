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


    Producte_client();

    /*Destructora */

    /** @brief Destructora per defecte
     * \pre Existeix un Client
     * \post Destrueix el Client
    */
    ~Producte_client();

    int consulta_quantitat(string n);

};
#endif
