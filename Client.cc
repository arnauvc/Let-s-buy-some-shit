#include "Client.hh"
#include "Producte.hh"
  
Client::Client() {
    assignat = false;
}

Client::~Client() {
}

void Client::afegir_caixa(int c) {
    caixa = c;
  }

bool Client::te_caixa() {
  return assignat;
}
   
int Client::consultar_torn() const {
    return torn;
   }
   
int Client::consultar_caixa() const {
    return caixa;
   }
   
int Client::consultar_num_productes() const {
     return num_productes;
   }
   
string Client::consultar_hora() const {
    return R.consulta_hora();
   }

string Client::consultar_hora_despres_caixer(){
  return R.consulta_temps_fi_caixer();
}

void Client::sumar_segons(int s){
  R.suma_temps(s);
}

void Client::llegeix_Client() {
     cin >>  torn;
     R.llegir_hora();
     cin >> num_productes;
     for(int i=0; i<num_productes; ++i) {
         string producte;
         int quantitat;
         cin >> producte >> quantitat;
         producte_client[producte] = quantitat;
     }
   }
