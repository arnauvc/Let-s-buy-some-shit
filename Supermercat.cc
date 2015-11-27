#include "Supermercat.hh"

Supermercat::Supermercat() {}

Supermercat::~Supermercat() {}

void Supermercat::inicialitza(int r,int c,int x,int n){
  rengles = r;
  columnes = c;
  caixes = x;
  Producte p;
  for (int i=0; i<n; ++i){
    p.llegir_producte();
    string nom = p.consulta_nom();
    mapProductes.insert(make_pair(nom,p));//mapeja el nom i el producte
    
    string seccio = p.consulta_seccio(); //consulta la seccio del producte
    int g,h;
    g = valorenter(seccio[0]); //passa la lletra a valor numeric
    h = seccio[1];
    vec_noms[g][h].insert(nom); //inserta el nom del producte al conjunt de la posicio de la matriu
    
}

void Supermercat::carrega(int L){
  cin >> L;
  for (int i; i<L; ++i) {
    cin >> i(identificador del client) >> hora >> nombre de producte de diferents comprats; //Aquesta linia s'ha de canviar tota
  }
}

void Supermercat::simula()
  //se va a cagar la burra fent aixo
  
  

void Supermercat::informa(){
  for (map<nom, producte>::const_iterator i = d.begin(); i != d.end(); ++i) {
    cout << i->first << " " << i->second.preu << " " << i-> second.seccio << " " << i-> temps_de_cobrament << endl;
  }
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
  
