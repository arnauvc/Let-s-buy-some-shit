/**
 * @mainpage Pràctica PRO2 - Gestio d'un supermercat
 
/** @file main.cc
 *  @brief Programa principal de <em>Pràctica PRO2 - Gestor d'un supermercat'</em>.
*/

#include "client.hh"
#include "Producte.hh"
#include "supermercat.hh"
#include "Rellotge.hh"

/** @brief Programa principal.
*/
int main() {
 Supermercat super;
 string condicio,seccio, nom;
 
 while(getline(cin,condicio)){ //revisar el getline perque donara problemes
  if (condicio == "inicialitzar"){
   int r,c,x,n,l;
   cin >> r >> c >> x >> n;
   super.inicialitza(r,c,x,n);
  } 
  else if (condicio == "carregar") {
   cin >> l;
   super.carrega(int l);
  }
  else if (condicio == "simular") super.simula();
  else if (condicio == "informacio") {
   cin >> nom;
   super.informa(nom);
  }
  else if (condicio == "productes") {
   cin >> seccio;
   super.productes_seccio(seccio);
  }
  else if (condicio == "millor cami")super.millor_cami();
  else if (codicio == "sortir") break;
 }
}
