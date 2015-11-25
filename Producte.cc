#include "Producte.hh"

private:
  

// CREADORES //
public:

Producte::~Producte() {}

//no cal el vProducte. La funcio es la e Llegir, que tenim a baix
/*
void Producte::vProducte() {
  cin >> nom >> seccio >> preu >> temps_cobrament;
}
*/

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
  cin >> nom >> seccio >> preu >> temps_cobrament;
  
void escriu_producte() const;


