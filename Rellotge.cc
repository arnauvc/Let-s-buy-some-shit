// Classe Rellotge

#include "Rellotge.hh"
#include <string>

Rellotge::Rellotge() {

}

Rellotge::~Rellotge() {}

string Rellotge::consulta_hora() {
	return hora;
}


int Rellotge::compara_rellotges(Rellotge R2) {
	hora1 = hora;
	hora2 = R2.consulta_hora();
	if (hora1==hora2) return 0;
	else {
		int h1, h2;
		h1=(hora1[0]*10)+hora1[1];
		h2=(hora2[0]*10)+hora2[1];
		if (h1>h2) return 2;
		if (h2>h1) return 1;
		else {
			int m1, m2;
			m1=(hora1[3]*10)+hora1[4];
			m2=(hora2[3]*10)+hora2[4];
			if (m1>m2) return 2;
			if (m2>m1)return 1;
			else {
				int s1,s2;
				s1=(hora1[6]*10)+hora1[7];
				s2=(hora2[6]*10)+hora2[7];
				if (s1>s2) return 2;
				else return 1;
			}
			
		}
		
	}
}

void suma_temps(int s){
	
}

/*int Rellotge::compara_rellotges(Rellotge R2) {
	int h, d;
	h = compara_hores(hora, R2.consulta_hora());
	//d = compara_dates(data, R2.consulta_data());
	
	if (d==0) {
		if (h==0) return 0;
		else if (h==1) return 1;
		else return 2;
	} else {
		if (d==1) return 1;
		else return 2;
	}
}
*/

/*void Rellotge::modifica_hora(string h) {
	hora=h;
}



void Rellotge::modifica_data(string d) {
	data=d;
}
*/


