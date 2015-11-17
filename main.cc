/**
 * @mainpage Pràctica PRO2 - Gestio d'un supermercat

#include "client.hh"
#include "Producte.hh"
#include "supermercat.hh"
#include "Rellotge.hh"
//#include "espec_generic.hh" aquest fitxer no és una classe !!!

int main() {
 Supermercat super;
 string condicio;
 while(getline(cin,condicio)){
  if (condicio == "inicialitzar") super.inicialitza();
  else if (condicio == "carregar")
  else if (condicio == "simular")
  else if (condicio == "informacio")
  else if (condicio == "productes")
  else if (condicio == "seccio")
  else if (condicio == "millor cami")
  else if (codicio = "sortir") break;
 }
}
