#include "Polaczenie.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


Polaczenie::Polaczenie(int idPolaczenie,std::string skad, std::string dokad, std::string godzina, std::string data, std::shared_ptr<Samolot> mapaSamoloty ){
	this->skad = skad;
	this->dokad = dokad;
	this->godzina = godzina;
	this->data = data;
	this->PtrSamolot = mapaSamoloty;
	this->idPolaczenie = idPolaczenie;
}

int Polaczenie::getIDPolaczenie() {
	return this->idPolaczenie;
}
std::string Polaczenie::getSkad() {
	return this->skad;
}
std::string Polaczenie::getDokad() {
	return this->dokad;
}
std::string Polaczenie::getGodzina() {
	return this->godzina;
}
std::string Polaczenie::getData() {
	return this->data;
}
std::shared_ptr<Samolot> Polaczenie::getPtrSamolot() {
	return this->PtrSamolot;
}

void Polaczenie::zapiszPolaczeniaDoPliku(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia) {
	std::ofstream plik(nazwaPliku);
	if (plik.is_open()) {
		for (const auto& polaczenie : polaczenia) {
			plik << "ID: " << polaczenie.first << "\n";
			plik << "Skad: " << polaczenie.second->getSkad() << "\n";
			plik << "Dokad: " << polaczenie.second->getDokad() << "\n";
			plik << "Godzina: " << polaczenie.second->getGodzina() << "\n";
			plik << "Data: " << polaczenie.second->getData() << "\n";
			plik << "Wolne miejsca: " << polaczenie.second->getPtrSamolot()->getLiczbaWolnychMiejsc() << "\n\n";
		}
		plik.close();
		std::cout << "Polaczenia zostaly zapisane do pliku: " << nazwaPliku << std::endl;
	}
	else {
		std::cout << "Nie udalo sie otworzyc pliku do zapisu: " << nazwaPliku << std::endl;
	}
}


