#include "Client.hh"
#include "Producte.hh"
  
  Client::Client();
  
  
  Client::Client(int torn, int caixa, int producte, Rellotge R); //el rellotge és el temps de recollida del tiquet
  
  
  Client::~Client();

   
   void Client::afegir_torn(int t){
    torn = t;
   }

   void Client::afegir_caixa(int c) {
    caixa = c;
   }
  
   
   
   void Client::afegir_producte(int producte);
   
  
   
   int Client::consultar_torn(int torn) const {
    return torn;
   }
   
   int Client::consultar_caixa(int caixa) {
    return caixa;
   }
   
   int Client::consultar_num_productes(){
     return num_productes;
   }
   
   Rellotge Client::consulta_hora(Rellotge R) const {
    return R;
   }
   
   void Client::llegeix_Client() {
     Client client;
     cin >>  client.torn >> client.R >> client.producte;
   }
