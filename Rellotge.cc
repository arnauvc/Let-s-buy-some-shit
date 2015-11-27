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
	int temps1,hora1,minuts1,segons1;
	hora1 = (hora[0]*10)+hora[1])*3600; //hores a segons
	minuts1 = (hora[3]*10)+hora[4])*60;
	segons1 = (hora[6]*10)+hora[7]);
	temps1 = hora1+minuts1+segons1; // la hora del rellotge en segons
	temps1 += s; //sumem els segons desitjats
	//Ara fem el proces invers
	minuts1 = temps1/60;
	hores1 = minuts1/60;
	hora = to_string(int(hores1))+":"+ to_string(int(minuts1%60))+":"+ to_string(int(segons1%60));
	//Concatena la nova hora en forma de: hores, minuts i segons amb els " : " necessaris.
}

void llegeix_hora(){
	cin >> hora;
}


