#include <iostream>
#include <vector>

using namespace std;


void llegir(vector<string> S) {
	int n = S.size();
	for (int i=0; i<n; ++i) {
		cin >> S[i];
	}
}

void escriure(vector<string> S) {
	int n = S.size();
	for (int i=0; i<n; ++i) {
		cout << S[i] << " ";
	}
	cout << endl;
}

int main() {
	int n, j, z, cont;
	cin >> n;
	string seccio;
	j = z = 0;
	vector<string> voriginal(n);
	vector<string> vaux(n);
	vector<string> vsimplificat(n);
	for (int i=0; i<n; ++i) {
		cin >> voriginal[i];
	}
	for (int i=0;i<n;i++) { 
		cont = 0;
		seccio = voriginal[i];
		vaux[j] = seccio;
		++j;
		for (int k=0; k<n; ++k) {
			if (vaux[k] == seccio) {
				++cont;
			}
		}
		if (cont == 1) {
			vsimplificat[z] = seccio;
			++z;
		}
	}
	for (int h=0; h<z; ++h) {
			cout << vsimplificat[h] << " ";
		}
	cout << endl;
}
