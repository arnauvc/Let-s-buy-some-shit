#include "Supermercat.hh"

Supermercat::Supermercat() {}

Supermercat::~Supermercat() {}

void Supermercat::inicialitza(int r,int c,int x,int n){
  rengles = r;
  columnes = c;
  caixes = x;
  Producte p;
  for (int i=0; i<n; ++i){
    p.llegeix();
    string nom = p.consulta_nom();
    mapProductes.insert(make_Pair(nom,p));//mapeja el nom i el producte
    
    string seccio = p.consulta_seccio(); //consulta la seccio del producte
    int g,h;
    g = valorenter(seccio[0]); //passa la lletra a valor numeric
    h = seccio[1];
    vec_noms[g][h].insert(nom); //inserta el nom del producte al conjunt de la posicio de la matriu
    
}

void Supermercat::carrega(){
  
}

void Supermercat::simula(){
  //se va a cagar la burra fent això
}

void Supermercat::informa(){
  
}

void Supermercat::producte_seccio(string s){ //retorna la llista de tots els productes d'una seccio
    
    //aquestes 3 linies es podrien posar en alguna funció
    int g,h;
    g = valorenter(s[0]); //passa la lletra a valor numeric
    h = s[1];
    
    set<string>::iterator it = vec_noms[g][h].begin();
    while(it != vec_noms[g][h].end() ){
      cout << *it << endl;
      ++it;
    }
}

void Supermercat::millor_cami(){
  
}
  
