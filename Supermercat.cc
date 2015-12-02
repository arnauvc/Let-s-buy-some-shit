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

void Supermercat::simula(int M){}
/*
{
  //se va a cagar la burra fent aixo

  for (int i=0; i<M; ++i){ //nombres de configuracions diferents de la simulacio
    int x;//caixes normals
    int y;//caixes rapides
    cin >> x >> y ;

    for (map<int,Client>::const_iterator i = mapClient.begin(); i != mapClient.end(); ++i){
        int numero = (i->second).consultar_quantitat(); //nombre d'unitats de producte, si mes de 10 no pot ser caixa rapida
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
*/

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
  
