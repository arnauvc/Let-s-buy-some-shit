/**
 * @mainpage Pràctica PRO2 - Gestio d'un supermercat
 
/** @file main.cc
 *  @brief Programa principal de <em>Pràctica PRO2 - Gestor d'un supermercat'</em>.
*/

#include "Client.hh"
#include "Producte.hh"
#include "Supermercat.hh"
#include "Rellotge.hh"

/** @brief Programa principal.
*/
int main() {
 Supermercat super;
 string condicio,seccio, nom;
 
 while(cin>>condicio){ //revisar el getline perque donara problemes
  if (condicio == "inicialitzar"){
   int r,c,x,n,l;
   cin >> r >> c >> x >> n;
   super.inicialitza(r,c,x,n);
  } 
  else if (condicio == "carregar") {
   int l;
   cin >> l;
   super.carrega(l);
  }
  else if (condicio == "simular") {
   string varia;
   cin >> varia; // llegiras cami)
   if (varia == "pagament") super.simula();
  }
  
  else if (condicio == "informacio") {
   cin >> nom;
   super.informa(nom);
  }
  else if (condicio == "productes") {
   cin >> seccio;
   super.productes_seccio(seccio);
  }
  else if (condicio == "millor") {
      string varia;
      cin >> varia; // llegiras cami)
      if (varia == "cami") super.millor_cami();
  }
  else if (condicio == "sortir") break;
 }
}
