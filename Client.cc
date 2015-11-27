#include "Client.hh"
#include "Producte.hh"
  
  Client::Client();
  
  
  //Client::Client(int torn, int caixa, int producte, Rellotge R); //el rellotge és el temps de recollida del tiquet
  
  
  Client::~Client();


   void Client::afegir_caixa(int c) {
    caixa = c;
   }
   
   int Client::consultar_torn() const {
    return torn;
   }
   
   int Client::consultar_caixa() {
    return caixa;
   }
   
   int Client::consultar_num_productes(){
     return num_productes;
   }
   
   Rellotge Client::consultar_hora() const {
    return R;
   }
   
   void Client::llegeix_Client() {
     cin >>  torn >> R >> numproductes;
     for(int i=0; i<numproductes; ++i) {
       
       //cin >> llegir_producte();
     }
   }
