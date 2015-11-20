#include "Producte.hh"

private:
  int valorenter(char valor){
    	return (valor - 'A');
  }

// CREADORES //
public:

Producte::~Producte() {}

void Producte::vProducte() {
  cin >> nom >> seccio >> preu >> temps_cobrament;
}

string Producte::consulta_nom() {
  return nom;
}

double Producte::consulta_preu() {
  return preu;
}

string Producte::consulta_seccio() {
  return seccio;
}



void llegir_producte();


