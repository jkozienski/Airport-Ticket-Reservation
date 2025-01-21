#include "Samolot.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>      // std::setw

Samolot::Samolot(std::string nazwa, int liczbaRzedow, int liczbaKolumn,int idSamolot) {
	this->nazwa = nazwa;
	this->liczbaRzedow = liczbaRzedow;
	this->liczbaKolumn = liczbaKolumn;
	this->liczbaMiejsc = (liczbaKolumn) * (liczbaRzedow);
	this->idSamolot = idSamolot;
	
	for (size_t k = 0; k <= liczbaKolumn; k++)
	{
		std::vector<bool>pomocniczy;
		for (size_t r = 0; r <= liczbaRzedow; r++)
		{
			pomocniczy.push_back(false);
		}
		miejsca.push_back(pomocniczy);
	}
	//this->miejsca=miejsca;
}
int Samolot::getLiczbaWolnychMiejsc() {
	return this->liczbaMiejsc;
}
std::string Samolot::getNazwa() 
{
	return this->nazwa;
}
int Samolot::getLiczbaRzedow() 
{
	return this->liczbaRzedow;
}
int Samolot::getLiczbaKolumn() 
{
	return this->liczbaKolumn;
}
int Samolot::getIdSamolot() 
{
	return this->idSamolot;
}

bool Samolot::sprawdzCzyZajete(int rzad, int kolumna) 
{
	if (rzad >= 0 && rzad < liczbaRzedow && kolumna >= 0 && kolumna < liczbaKolumn && !miejsca[kolumna][rzad]) {
		return true; //wolne
	}
	return false; //zajete
}

bool Samolot::czyMiejsceWSamolocieIstnieje(int rzad, int kolumna) {
	if (rzad >= 0 && rzad < liczbaRzedow && kolumna >= 0 && kolumna < liczbaKolumn) {
		return true; // Miejsce istnieje w samolocie
	}
	else {
		return false;
	}
}

void Samolot::getMiejsca() {
	std::cout << "\u001B[42m   \u001B[0m";
	for (int kolumna = 0; kolumna < liczbaKolumn; kolumna++) {
		std::cout << "\u001B[43m" << "\u001B[30m" << std::setw(1) << kolumna << " " << "\u001B[0m";
	}
	std::cout << "\n\u001B[0m";

	for (int rzad = 0; rzad < liczbaRzedow; rzad++) {
		std::cout << "\u001B[42m" << "\u001B[30m" << std::setw(2) << rzad << " \u001B[0m";

		for (int kolumna = 0; kolumna < liczbaKolumn; kolumna++) {
			if (miejsca[kolumna][rzad]) {
				std::cout << std::setw(2) << "X "; //  zajête
			}
			else {
				std::cout << std::setw(2) << "O "; //  wolne
			}
		}
		std::cout << "\n";
	}
}


void Samolot::zarezerwujMiejsce(int rzad, int kolumna) {
	if (rzad >= 0 && rzad < liczbaRzedow && kolumna >= 0 && kolumna < liczbaKolumn) {
			miejsca[kolumna][rzad] = true;
			this->liczbaMiejsc--;
	}
}

void Samolot::wczytajZajeteMiejsca(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Samolot>>& samoloty) {
	std::ifstream plik(nazwaPliku, std::ios::in);

	if (plik.is_open()) {
		int idBilet;
		int idPolaczenie;
		int rzad, kolumna;
		std::string linia;

		while (std::getline(plik, linia)) {
			std::stringstream ss(linia);
			ss >> idBilet >> idPolaczenie >> kolumna >> rzad;

			if (samoloty.count(idPolaczenie) > 0) {
				std::shared_ptr<Samolot> samolot = samoloty[idPolaczenie];
				
				if (rzad >= 0 && rzad < samolot->getLiczbaRzedow() && kolumna >= 0 && kolumna < samolot->getLiczbaKolumn()) {
					samolot->miejsca[kolumna][rzad] = true;
					this->liczbaMiejsc--;
				}
				
			}
		}

		plik.close();
	}
	else {
		std::cout << "Nie mo¿na otworzyæ pliku " << nazwaPliku << std::endl;
	}
}

void Samolot::ustawMiejsceNaWolne(int rzad, int kolumna) {
		//std::cout << "Wybra³eœ miejsce (" << rzad << ", " << kolumna << ")" << std::endl;
		miejsca[kolumna][rzad] = false;
		this->liczbaMiejsc++;
}

