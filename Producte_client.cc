#include "Producte_client.hh"

Producte_client::Producte_client() {

}

Producte_client::~Producte_client() {
}

int consulta_quantitat(string n){
    map<string,int>::const_iterator i = mapProdClient.find(n);
    if(i == mapProductes.end()) return -1;
    else {
        return *i;

}
