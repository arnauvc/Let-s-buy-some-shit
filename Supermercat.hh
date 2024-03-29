/** @file Supermercat.hh
	@brief Classe Supermercat
*/
#ifndef SUPERMERCAT_HH
#define SUPERMERCAT_HH

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <set>
#include <utility>
#include "Producte.hh"
#include "Client.hh"


using namespace std;

class Supermercat{
  
  private:
    int rengles; // nombre de rengles
    int columnes; // nombre de columnes
    int caixes; // nombre de caixes
    vector<vector<set<string> > > vec_noms;// podem inicialitzar a (26,9)// (rengles, vector<set<string> >(columnes))
    map<string,Producte> mapProductes; // guardem el productes mapejat pel nom
    map<int,Client> mapClient; //Guardem els clients per identificador
    
    int valorenter(char valor){
    	return (int)valor - 'A';
	}
    
    int simula_temps_caixa(Client &);
    
    struct Permut {
    vector<string> v; // stores a partial permutation (prefix)
    vector<bool> used; // elements used in v
    int part_d;
    vector<string> best_v;
    int best_d;
};
    
  public:
  /*Constructora*/
  
  /** @brief Creadora per defecte.
   * \pre Cert
   * \post El resultat es un supermercat sense inicialitzar
  */
  Supermercat();
  
  
  /*Destructora */
  
  /** @brief Destructora per defecte
   * \pre Existeix un producte
   * \post Destrueix el producte
  */ 
  ~Supermercat();
  
  /** @brief Inicialitza els valors del supermercat del parametre implicit
   * \pre Cert
   * \post Modifica els camps del paramtre implicit
  */ 
  void inicialitza(int r,int c,int x,int n);
  
  /** @brief Afegeix clients amb els respectius productes associats
   * \pre Cert
   * \post Guarda la llista de clients amb els productes associats
  */ 
  void carrega(int L);
  
  /** @brief Simula els pagaments
   * \pre Existeix un supermercat, iniciaitzat i carregat en el parametre implicit. S'especifica el nombre de configuracions diferents
   * \post Escriu per pantalla el temps mitja de pagament segons la configuracio
  */
  void simula(int M);
  
  /** @brief Dona informacio d'un producte concret 
   * \pre Existeix el producte i esta inicialitzat
   * \post Escriu per pantalla el nom, preu, seccio i temps de cobrament del producte del parametre implicit
  */
  void informa(string producte); //retorna escriu
  
  /** @brief Escriu tots els productes d'una seccio 
   * \pre Supermercat inicialitzat i carregat
   * \post Escriu per pantalla tots els productes que pertanyen a la seccio especificada
  */
  void productes_seccio(string s); //escriu per pantalla tots els productes de la seccio
  // o bé "seccio buida" si no hi ha productes a la seccio
  
  /** @brief Busca el millor cami per recorre el supermercat
   * \pre supermercat inicialitzat i carregat
   * \post Escriu per pantalla les seccions en l'ordre que s'han de recorre
  */

  void millor_cami(int);

  
  /** @brief Calcula el valor de la seccio a un enter
   * \pre pre entra un string
   * \post post surt un enter
  */
  int calcularpunt(string S);
  
  /** @brief Calcula la distancia total de la permutació
   * \pre entra el vector de string
   * \post surt la distancia de la permutacio total
  */
  int calculardistancia(Permut& P);
  
  /** @brief Escriu la permutació correcta
   * \pre cert
   * \post surt la permutacio correcte
  */
  void PrintPermutation(const Permut& P);
  
  /** @brief 
   * \pre entra dos seccions
   * \post retorna la distancia entre dos seccions
  */
  int distance_st(string A, string B);
  
  /** @brief Construeix la permutació
   * \pre entra tamany del mapa, el vetor de string les diverses seccions i el nombre de seccions
   * \post surt la permutacio correcte
  */
  void BuildPermutation(int c, Permut& P, int i);
  

 };
 
#endif

