#include "Bilet.h"
Bilet::Bilet(int idPolaczenie, int rzad, int kolumna, std::shared_ptr<Polaczenie> polaczenia) {
	this->idPolaczenie = idPolaczenie;
	this->miejsce.first = rzad;
	this->miejsce.second = kolumna;
	this->PtrPolaczenie = polaczenia;
	this->idBilet = pidBilet;
	pidBilet++;

}
int Bilet::getidBilet() {
	return this->idBilet;
}
 std::string Bilet::getNazwa() {
	return "Bilet";
}

int Bilet::getidPolaczenie() {
	return this->idPolaczenie;
}

std::shared_ptr<Polaczenie> Bilet::getPtrPolaczenie() {
	return this->PtrPolaczenie;
}
