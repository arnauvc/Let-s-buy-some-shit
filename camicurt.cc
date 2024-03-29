#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;

struct Permut {
    vector<string> v; // stores a partial permutation (prefix)
    vector<bool> used; // elements used in v
    int part_d;
    vector<string> best_v;
    int best_d;
};

int calcularpunt(string S) {
    int n = S.size();
	int i= 1;
    int suma = 0;
    while (i < n) {
    	suma += (S[i] -'0')*pow(10,(n-i-1));
    	++i;
	}
    return S[0] - 'A' +suma;
}

int calculardistancia(Permut& P) {
    int dis = 0;
	for (int i=0; i<P.v.size()-1; ++i) {
    	dis+= abs(calcularpunt(P.v[i+1])-calcularpunt(P.v[i]));
	}
    return dis;
}

void PrintPermutation(const Permut& P) {
    int last = P.best_v.size();
    string s = "aa";
    for (int i = 0; i < last; ++i) {
	if(s != P.best_v[i]){
    		cout << P.best_v[i] << " ";
    	}	
    	s = P.best_v[i];
    }
    string s1;
    s1[0] = 'A';
    s1[1] = (last-1) + '0';
    if(s != s1 ) cout << s1 << endl;
    cout << endl;
}

int distance_st(string A, string B)
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

void BuildPermutation(int n, Permut& P, int i) {
	if (i == n)
    {
        //cout << "last" << endl;
        string s;
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


int main() {
    int n;
    cin >> n;
    Permut P;
    P.v = vector<string>(n);
    P.part_d = 0;
    P.best_v = P.v;
    P.best_d = std::numeric_limits<int>::max();
    for (int i=0; i<n; ++i) {
        cin >> P.v[i];
    }
    string s;
    s[0] = 'A';
    s[1] = n + '0';
    P.v.push_back(s);
    sort(P.v.begin(),P.v.end()-1);
    BuildPermutation(n,P,1);
    cout << "Mejor distancia: " << P.best_d << endl;
    PrintPermutation(P);
}
