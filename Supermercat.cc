#include "Supermercat.hh"

Supermercat::Supermercat() {}

Supermercat::~Supermercat() {}

void Supermercat::inicialitza(int r,int c,int x,int n){
  rengles = r;
  columnes = c;
  caixes = x;
  Producte p;
  vec_noms = vector< vector< set<string> > >(rengles, vector< set<string> >(columnes));
  for (int i=0; i<n; ++i){
    p.llegir_producte();
    string nom = p.consulta_nom();
    mapProductes.insert(make_pair(nom,p));//mapeja el nom i el producte
    string seccio = p.consulta_seccio(); //consulta la seccio del producte
    int g,h;
    g = valorenter(seccio[0]); //passa la lletra a valor numeric
    h = seccio[1] - '0' - 1;
    vec_noms[g][h].insert(nom); //inserta el nom del producte al conjunt de la posicio de la matriu
  }
}

void Supermercat::carrega(int L){
  for (int i=0; i<L; ++i) {
      Client client;
      client.llegeix_Client(); //el teu client, e.....
      int id;
      id = client.consultar_torn();
      mapClient.insert(make_pair(id,client));//mapeja el nombre de client i la quantitat de productes diferents
  }
}

void Supermercat::simula(int M){
  //se va a cagar la burra fent aixo

  for (int i=0; i<M; ++i){ //nombres de configuracions diferents de la simulacio
    int x;//caixes normals
    int y;//caixes rapides
    cin >> x >> y ;

    for (map<int,Client>::const_iterator i = mapClient.begin(); i != mapClient.end(); ++i){
        int numero = (i->second).consultar_num_productes(); //nombre de productes, pero hauria de ser, nombre d'unitats de producte
        //si el numero es bla bla bla assignar caixa;
        int temps_acomulat = 0;

        for(map<string,int>::const_iterator j = producte_client.begin(); j != producte_client.end(); ++j){//recorre el "carro" del client
            string nom = j->first;
            Producte p = mapProductes[nom];
            temps_acomulat += (j->second) * p.consulta_temps();//afegeix el temps de cobrament d'un producte * quantitat del producte

        }//Per anar be, al sortir d'aquest bucle s'hauria d'haver sumats tots els temps dels productes

        cout << (i->second).consultar_hora() ;
        (i->second)


    }


  }
}
  

void Supermercat::informa(string nom_producte){
    map<string,Producte>::const_iterator i = mapProductes.find(nom_producte);
    if(i == mapProductes.end()) cout << "informacio " << nom_producte << ":"<<endl << "error" <<endl;
    else {
        Producte producte = mapProductes[nom_producte];
        cout << "informacio " << nom_producte << ":"<<endl;
        producte.escriu_producte();
    }
}

void Supermercat::productes_seccio(string s){ //retorna la llista de tots els productes d'una seccio
    
    //aquestes 3 linies es podrien posar en alguna funció
    int g,h;
    g = valorenter(s[0]); //passa la lletra a valor numeric
    h = s[1] - '0' - 1;
    
    set<string>::iterator it = vec_noms[g][h].begin();
    if (it == vec_noms[g][h].end()) cout << "productes " << s << ":"<<endl << "seccio buida" << endl;
    else{
      cout << "productes " << s << ":"<<endl;
      while(it != vec_noms[g][h].end() ){
        cout << *it << endl;
        ++it;
      }
    }
}

void Supermercat::millor_cami(){
  
}
  
