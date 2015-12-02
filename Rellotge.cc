// Classe Rellotge

#include "Rellotge.hh"
#include <string>

Rellotge::Rellotge() {

}

Rellotge::~Rellotge() {}

string Rellotge::consulta_hora() const{
	return to_string(hora) + ":" + to_string(minuts) + ":" + to_string(segons);
}


/*
int Rellotge::compara_rellotges(Rellotge R2) {
	string hora1 = hora;
	string hora2 = R2.consulta_hora();
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
*/

void Rellotge::suma_temps(int s){
    delta_segons += s;
}

void Rellotge::llegir_hora(){
    char dospunts;
    cin >> hora >> dospunts >> minuts >> dospunts >> segons;
}


string Rellotge::consulta_temps_fi_caixer() {
    int temps_inicial = hora*3600 + minuts*60 + segons;
    int temps_final = temps_inicial + delta_segons;
    int hora_final = temps_final/3600;
    temps_final -= hora_final*3600;
    int minuts_final = temps_final/60;
    temps_final -= minuts_final*60;
    int segons_final = temps_final;
    return to_string(hora_final)+":"+ to_string(minuts_final)+":"+ to_string(segons_final);
    //Concatena la nova hora en forma de: hores, minuts i segons amb els " : " necessaris.
}

