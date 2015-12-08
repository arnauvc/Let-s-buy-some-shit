#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct Permut {
    vector<string> v; // stores a partial permutation (prefix)
    vector<bool> used; // elements used in v
};

int calcularpunt(string S) { // Calcula en valor int la seccio
    int n = S.size();
	int i= 1;
    int suma = 0;
    while (i < n) {
    	suma += (S[i] -'0')*pow(10,(n-i-1));
    	++i;
	}
    return S[0] - 'A' +suma;
}

int calculardistancia(Permut& P) { // Calcula de tot el recorregut
    int dis = 0;
	for (int i=0; i<P.v.size()-1; ++i) {
    	dis+= abs(calcularpunt(P.v[i+1])-calcularpunt(P.v[i]));
	}
    return dis;
}

void PrintPermutation(const Permut& P) { // Escriu la permutacio
    int last = P.v.size()-1;
    for (int i = 0; i < last; ++i) cout << P.v[i] << " ";
    cout << P.v[last] << endl;
}

void BuildPermutation(int n, Permut& P, int i) { // Construccio de la permutacio
	if (i == n) {
		PrintPermutation(P);
		cout << calculardistancia(P) <<endl;
    } 
    else {
        for (int k = i; k < P.v.size(); ++k) {
			swap(P.v[i],P.v[k]);
            BuildPermutation(n,P,i+1);
            swap(P.v[i],P.v[k]);
        }
    }
}
