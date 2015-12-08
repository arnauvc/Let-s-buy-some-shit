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
   
Rellotge Client::consultar_hora() const {
    return R;
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


int Client::get_temps_desplacament() { return temps_desplacament; }
int Client::get_temps_caixer() { return temps_caixer; }
int Client::get_temps_cua() { return temps_cua; }
void Client::set_temps_desplacament(int temps_desplacament) { this->temps_desplacament = temps_desplacament; }
void Client::set_temps_caixer(int temps_caixer) { this->temps_caixer = temps_caixer; }
void Client::set_temps_cua(int temps_cua) { this->temps_cua = temps_cua; }
