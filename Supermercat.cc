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
  mapClient.clear();
  for (int i=0; i<L; ++i) {
      Client client;
      client.llegeix_Client(); 
      int id;
      id = client.consultar_torn();
      mapClient[id] = client; //mapeja el client segons el id 
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

int Supermercat::calcularpunt(string s) {
    int n = s.size();
	int i= 1;
    int suma = 0;
    while (i < n) {
    	suma += (s[i] -'0')*pow(10,(n-i-1));
    	++i;
	}
    return s[0] - 'A' +suma;
}

int Supermercat::calculardistancia(Permut& P) {
    int dis = 0;
	for (int i=0; i<P.v.size()-1; ++i) {
    	dis+= abs(calcularpunt(P.v[i+1])-calcularpunt(P.v[i]));
	}
    return dis;
}

void Supermercat::PrintPermutation(const Permut& P) {
    int last = P.best_v.size();
    string s = "aa";
    for (int i = 0; i < last; ++i) {
	if(s != P.best_v[i]){
    		cout << P.best_v[i] << " ";
    	}	
    	s = P.best_v[i];
    }
    string s1 = "A0";
    s1[0] = 'A';
    s1[1] = (last-1) + '0';
    if(s != s1 ) cout << s1 << endl;
    cout << endl;
}

int Supermercat::distance_st(string A, string B)
{
    int x1 = A[1]-'0';
    int y1 = A[0]-'A';
    int x2 = B[1]-'0';
    int y2 = B[0]-'A';

    //cout << "D: " << A << " [" << x1 << "," << y1 << "] <-> " << B << " [" << x2 << "," << y2 << "]" << endl;
    int res = abs(x2-x1)+abs(y2-y1);
    //cout << "D: " << res << endl;
    return res;
}

void Supermercat::BuildPermutation(int n, Permut& P, int i) { // n = numero de seccion
	if (i == n)
    {
        //cout << "last" << endl;
        
        string s = "A0";
        s[0] = 'A';
        s[1] = n + '0';
        int ldp = distance_st(P.v.at(n-1),s);
        if (P.part_d + ldp < P.best_d)
        {
    		//cout << "===========" << endl;
            P.best_d = P.part_d+ldp;
            P.best_v = P.v;
    		//cout << calculardistancia(P) << endl;
            cout << "===========" << endl;
        }
    }
    else
    {
        //cout << "\t i: " << i << endl;
        int dp = std::numeric_limits<int>::max(); //distance_st(P.v[i-1], P.v[i]); //Calculamos la distancia del punto anterior al siguiente actual
        for (int k = i; k < P.v.size()-1; ++k) {
            string A = P.v.at(i-1);
            string B = P.v.at(k);
            int alt = distance_st(A,B);
            if (alt < dp) //Si la distancia a este punto es menor que la de dp, escogemos esta
            {
                swap(P.v[i],P.v[k]);
                P.part_d += alt;
                BuildPermutation(n,P,i+1);
                swap(P.v[i],P.v[k]);
                P.part_d -= alt;
            }
        }
    }
}


void Supermercat::millor_cami(int id){ //c es la ultima columna del supermercat
     // columnes de la matriu de string;
    
    cout << "millor cami " << id << " :" << endl;
    Client client_del_vector;
    map<int,Client>::const_iterator k = mapClient.find(id);
    if (k == mapClient.end()) cout << "error" <<endl;
    else {
        client_del_vector = k->second;
        
    }
    
    int n = client_del_vector.consultar_num_productes();
    
    Permut P;
    P.v = vector<string>(n);
    P.part_d = 0;
    P.best_v = P.v;
    P.best_d = std::numeric_limits<int>::max();
    
    
    for(int j = 0; j < client_del_vector.consultar_num_productes(); ++j){
        string nomdelproducte = client_del_vector.consultar_productes(j);
        Producte prod = mapProductes[nomdelproducte];
        P.v[j] = prod.consulta_seccio();
    }
    
    //for(int g = 0; g < P.v.size(); g++)cout << P.v[g]; Per comprovar si emplena be el vector
    int c = columnes;
    
    
    string s = "A0";
    s[0] = 'A';
    s[1] = c + '0';
    P.v.push_back(s);
    sort(P.v.begin(),P.v.end()-1);
    BuildPermutation(n,P,1);
    cout << P.best_d << endl; //millor recorregut temps
    PrintPermutation(P);
}
  
