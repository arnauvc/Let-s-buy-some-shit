#include "Producte.hh"

// CREADORES //

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

void llegir_producte() {
  cin >> nom >> seccio >> preu >> temps_cobrament;
}

void escriu_producte() const {
  cout << nom << " "<< preu <<" "<< seccio <<" "<< temps_cobrament << endl;
}
