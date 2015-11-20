#include "Supermercat.hh"

Supermercat::Supermercat() {}

Supermercat::~Supermercat() {}

void Supermercat::inicialitza(int r,int c,int x,int n){
  rengles = r;
  columnes = c;
  caixes = x;
  Producte p;
  for (int i=0; i<n; ++i){
    p.vProducte();
    string nom = p.consulta_nom();
    mapProductes.insert(make_Pair(nom,p));
    //falta posar el nom dins la matriu de sets
}

void Supermercat::carrega(){
  
}

void Supermercat::simula(){
  //se va a cagar la burra fent això
}

void Supermercat::informa(){
  
}

void Supermercat::producte_seccio(string s){ //retorna la llista de tots els productes d'una seccio
  
}

void Supermercat::millor_cami(){
  
}
  
