#include "Client.hh"
#include "Producte.hh"
  
Client::Client() {
    assignat = false;
    quantitat = 0;
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
 
int Client::consultar_num_productes() const{
  return num_productes;
}  

string Client::consultar_productes(int i) const {
			    return producte_quantitat[i].first;
		}
			
		int Client::consultar_productes_quantitat(int i) const {
			    return producte_quantitat[i].second;
			    }

int Client::consultar_quantitat() const {
    return quantitat;
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
      producte_quantitat = vector < pair< string,int> > (num_productes);
     for(int i=0; i<num_productes; ++i) {
         string producte;
         int quantitat_temp;
         cin >> producte >> quantitat_temp;
          quantitat += quantitat_temp;
         producte_quantitat[i] = make_pair(producte,quantitat_temp); 
     }
   }
