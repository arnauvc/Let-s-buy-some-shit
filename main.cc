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
 string condicio;
 while(getline(cin,condicio)){
  if (condicio == "inicialitzar") super.inicialitza();
  else if (condicio == "carregar") super.carrega();
  else if (condicio == "simular") super.simula();
  else if (condicio == "informacio") super.informa();
  else if (condicio == "productes") super.productes_seccio();
  else if (condicio == "millor cami")super.millor_cami();
  else if (codicio == "sortir") break;
 }
}
