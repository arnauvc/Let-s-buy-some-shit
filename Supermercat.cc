#include "Supermercat.hh"

Supermercat::Supermercat() {}

Supermercat::~Supermercat() {}

void Supermercat::inicialitza(r,c,x,n){
  rengles = r;
  columnes = c;
  caixes = x;
  Producte p;
  for (int i=0; i<n; ++i){
    p.Producte();//vull que la creadora s'encarregui dels parametres
    vec_productes[i].first = p.consulta_seccio();
    vec_productes[i].second = p;
}

void Supermercat::carrega(){
  
}

void Supermercat::simula(){
  
}

void Supermercat::informa(){
  
}

void Supermercat::producte_seccio(){
  
}

void Supermercat::millor_cami(){
  
}
  
