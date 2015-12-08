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
      client.llegeix_Client(); 
      int id;
      id = client.consultar_torn();
      mapClient.insert(make_pair(id,client));//mapeja el client segons el id 
  }
}

void Supermercat::simula(int M){

  //se va a cagar la burra fent aixo
  
  for (int i=0; i<M; ++i){ //nombres de configuracions diferents de la simulacio
    int num_caixes_normals;
    int num_caixes_rapides;
    cin >> num_caixes_normals >> num_caixes_rapides ;
    cout << "simular pagament:" <<endl;

    vector< vector<Client*> > vector_caixes(caixes, vector<Client*>(0));
    for (map<int,Client>::iterator it = mapClient.begin(); it != mapClient.end(); ++it){
        Client *C = &it->second;
        int caixa_assignada;
        unsigned int min_clients = -1;
        int min_caixes;

        if (C->consultar_quantitat() < 10) min_caixes = caixes - num_caixes_rapides - num_caixes_normals;
        else min_caixes = caixes - num_caixes_normals;

        for (int j = caixes - 1; j > min_caixes - 1; j--) {
            if (vector_caixes[j].size() < min_clients) {
                min_clients = vector_caixes[j].size();
                caixa_assignada = j;
            }
        }
        vector_caixes[caixa_assignada].push_back(C);
        C->afegir_caixa(caixa_assignada + 1);
    }

    /* for (map<int,Client>::const_iterator i = mapClient.begin(); i != mapClient.end(); ++i){ */
    /*     cout << i->first << " " << i->second.consultar_caixa() << endl; */
    /* } */

    map<int, int> temps_cua; // id, temps
    for (unsigned int j = 0; j < vector_caixes.size(); j++) {
        int temps_caixa = 0;
        Rellotge r;
        bool primer = true;
        for (unsigned int k = 0; k < vector_caixes[j].size(); k++) {
            Client *c = vector_caixes[j][k];
            if (primer) {
                primer = false;
                r = c->consultar_hora();
            }
            temps_cua[c->consultar_torn()] = temps_caixa;
            c->set_temps_caixer(simula_temps_caixa(*c));
            r.suma_temps(c->get_temps_caixer() + caixes - c->consultar_caixa());
            temps_caixa = temps_caixa + c->get_temps_caixer();
        }
    }

    /* cout << "MAP" << endl; */
    /* for (map<int,int>::const_iterator it = temps_cua.begin(); it != temps_cua.end(); ++it){ */
    /*     cout << it->first << " " << it->second << endl; */
    /* } */

    for (map<int, int>::iterator it = temps_cua.begin(); it != temps_cua.end(); ++it){
        /* Client &C = mapClient[it->first]; */
        /* cout <<C.consultar_torn()<< " " <<C.consultar_caixa()<< " " <<C.consultar_hora() <<" " << C.consultar_hora_despres_caixer() << endl; */
    }

    /* for (map<int,Client>::iterator i = mapClient.begin(); i != mapClient.end(); ++i){ */
    /*     Client &C = i->second; */
    /*     cout <<C.consultar_torn()<< " " <<C.consultar_caixa()<< " " <<C.consultar_hora() <<" " << C.consultar_hora_despres_caixer() << endl; */
    /* } */

  }
}

int Supermercat::simula_temps_caixa(Client &C) {
    int temps_acomulat = 0;

    for(int j=0; j< C.consultar_num_productes() ; ++j){
        string nom = C.consultar_productes(j);
        int quantitat = C.consultar_productes_quantitat(j);
        Producte p = mapProductes[nom];
        temps_acomulat += quantitat * p.consulta_temps();
    }

    return temps_acomulat;
}

void Supermercat::informa(string nom_producte){
    cout << "informacio " << nom_producte << ":"<< endl;
    map<string,Producte>::const_iterator i = mapProductes.find(nom_producte);
    if(i == mapProductes.end()) cout << "error" <<endl;
    else {
        Producte producte = mapProductes[nom_producte];
        producte.escriu_producte();
    }
  cout << endl;
}

void Supermercat::productes_seccio(string s){ //retorna la llista de tots els productes d'una seccio
    
    //aquestes 3 linies es podrien posar en alguna funciÃ³
    int g,h;
    g = valorenter(s[0]); //passa la lletra a valor numeric
    h = s[1] - '0' - 1;
    
    cout << "productes " << s << ":"<<endl;
    set<string>::iterator it = vec_noms[g][h].begin();
    if (it == vec_noms[g][h].end()) cout << "seccio buida" << endl;
    else{
      while(it != vec_noms[g][h].end() ){
        cout << *it << endl;
        ++it;
      }
    }
  cout << endl;
}

void Supermercat::millor_cami(string nom){
/*1. pedirle los producto al client.
  2. encontrar las secciones de cada producto. (guardarla en un vector)
  3. mantener el inicio y el final.
  4. con el resto de puntos hacer permutaciones
  5. calcular la distancia de cada permutacion, 
  6. compararla con una distancia minima mientras calcula la distancia total
  7. en el caso del a6 lo tengo que poner como ultimo elemento de la permutacion */
struct permut {
    vector<string> v;
    v[0]="A2";
    v[1]="B1";
    map <string,bool> used;
    int distanciaminimacamino;
};

int distanciacamino = 0;
void permutacion(Punto A1(intentar hacer break de la permutacion), permut& p, int i) {
    if (i == P.v.size()-1) {
        if (distancia a1(va cambiando) a A6 < distancia minima and distanciacamino+distancia entre a1 y v[k] < distanciaminimacamino) {
            distanciacamino += distancia entre a1 a6;
            distanciaminimacamino = distanciacamino;
           distancia minima = distancia a1 a a6;
            Printpermutation(P);
        }
    }
    else {
    // Define one more location for the prefix
    // preserving the lexicographical order of
    // the unused elements
        for (int k = 0; k < P.used.size(); ++k) {
            if (not P.used[k]) { //used por un map map<string,bool>
            //comprobar la distancia de a1 el punto v[k];
                if (distancia a1 a v[k] < distancia minima and distanciacamino+distancia entre a1 y v[k] < distanciaminimacamino) {
                    P.v[i] = k; // k+1
                    P.used[k] = true;
                    distanciacamino += distancia entre a1 v[k];
                    distanciaminimacamino = distanciacamino;
                    distancia minima = distancia a1 a v[k];
                    permutacion(k,p, i + 1);
                    P.used[k] = false;
                }
            }
        }
    } 
  }
}
  
