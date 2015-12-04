#include "Producte.hh"

// CREADORES //

Producte::Producte() {}

Producte::~Producte() {}


string Producte::consulta_nom() {
  return nom;
}

double Producte::consulta_preu() {
  return preu;
}

string Producte::consulta_seccio() {
  return seccio;
}

int Producte::consulta_temps(){
  return temps_cobrament;
}

void Producte::llegir_producte() {
  //cin >> nom >> seccio >> preu >> temps_cobrament;
  cin >>nom >> preu >>seccio>>temps_cobrament;
}

void Producte::escriu_producte() const {
  cout << nom << " "<< preu <<" "<< seccio <<" "<< temps_cobrament << endl;
}
