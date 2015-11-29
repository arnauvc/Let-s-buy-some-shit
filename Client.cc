#include "Client.hh"
#include "Producte.hh"
  
Client::Client() {
}

  
  
  //Client::Client(int torn, int caixa, int producte, Rellotge R); //el rellotge és el temps de recollida del tiquet
  
  
Client::~Client() {
}



   void Client::afegir_caixa(int c) {
    caixa = c;
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
   
   string Client::consultar_hora() {
    return R.consulta_hora();
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
