#include "func.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Samolot.h"
#include "Polaczenie.h"
#include "Pasazer.h"
#include "BiletNormalny.h"
#include "BiletDwuosobowy.h"
#include <map>


std::map<int, std::shared_ptr<Samolot>> wczytajSamoloty(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Samolot>>& samoloty) {
    std::string nazwa;
    int liczbaKolumn, liczbaRzedow, idSamolotu;
    std::ifstream plik;

    try {
        plik.open(nazwaPliku);
        if (plik.fail())
            throw nazwaPliku;

        for (int i = 0; plik >> nazwa >> liczbaKolumn >> liczbaRzedow >> idSamolotu; i++) {

            std::shared_ptr<Samolot> ptr(new Samolot(nazwa, liczbaKolumn, liczbaRzedow, idSamolotu));
            //samoloty.push_back(std::move(ptr));
            samoloty.insert(std::pair<int, std::shared_ptr<Samolot>>(idSamolotu, std::move(ptr)));
        }

        plik.close();
        return samoloty;
    }
    catch (std::string e) {
        std::cout << "Plik '" << nazwaPliku << "' nie mo¿e zostaæ poprawnie otwarty!\n";
        exit(1); // UWAGA NA TO
    }
}

void wczytajZajeteMiejsca(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia) {

    std::ifstream plik(nazwaPliku);
    if (plik.is_open()) {

        std::string linia;
        while (std::getline(plik, linia)) {
            std::stringstream ss(linia);
            int kolumna, rzad, idBilet, idPolaczenie;
            if (ss >> idBilet >> idPolaczenie >> kolumna >> rzad) {
                if (polaczenia.count(idPolaczenie) > 0) {

                    std::shared_ptr<Polaczenie> polaczenie = polaczenia[idPolaczenie];
                    if (kolumna >= 0 && kolumna < polaczenie->getPtrSamolot()->getLiczbaKolumn() && rzad >= 0 && rzad < polaczenie->getPtrSamolot()->getLiczbaRzedow()) {
                        polaczenie->getPtrSamolot()->zarezerwujMiejsce(kolumna, rzad);

                    }
                }
            }
        }
        plik.close();
    }
    else {
        std::cout << "Nie mo¿na otworzyæ pliku " << nazwaPliku << std::endl;
    }
}

void wczytajDwaZajeteMiejsca(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia) {
    std::ifstream plik(nazwaPliku);
    if (plik.is_open()) {
        std::string linia;
        while (std::getline(plik, linia)) {
            std::stringstream ss(linia);
            int kolumna1, rzad1, kolumna2, rzad2, idBilet, idPolaczenie;
            if (ss >> idBilet >> idPolaczenie >> kolumna1 >> rzad1 >> kolumna2 >> rzad2) {
                if (polaczenia.count(idPolaczenie) > 0) {

                    std::shared_ptr<Polaczenie> polaczenie = polaczenia[idPolaczenie];
                    if (kolumna1 >= 0 && kolumna1 < polaczenie->getPtrSamolot()->getLiczbaKolumn() && rzad1 >= 0 && rzad1 < polaczenie->getPtrSamolot()->getLiczbaRzedow() && kolumna2 >= 0 && kolumna2 < polaczenie->getPtrSamolot()->getLiczbaKolumn() && rzad2 >= 0 && rzad2 < polaczenie->getPtrSamolot()->getLiczbaRzedow()) {
                        polaczenie->getPtrSamolot()->zarezerwujMiejsce(kolumna1, rzad1);
                        polaczenie->getPtrSamolot()->zarezerwujMiejsce(kolumna2, rzad2);

                    }
                }
            }
        }
        plik.close();
    }
    else {
        std::cout << "Nie mo¿na otworzyæ pliku " << nazwaPliku << std::endl;
    }
}

std::map<int, std::shared_ptr<Polaczenie>> wczytajPolaczenia(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia, std::map<int, std::shared_ptr<Samolot>>& samoloty) {
    int idSamolotPolaczenie;
    int idPolaczenie;
    std::string skad, dokad, godzina, data;
    std::ifstream plik;
    try {
        plik.open(nazwaPliku);
        if (plik.fail())
            throw nazwaPliku;
        for (int i = 0; plik >> idPolaczenie >> skad >> dokad >> godzina >> data >> idSamolotPolaczenie; i++) {

            for (const auto& pair : samoloty) {
                int idSamolot = pair.first;
                if (idSamolot == idSamolotPolaczenie) {
                    //std::cout << "znaleziono wspolny klucz "<<idSamolot <<" oraz "<< idPolaczenie << "\n";
                    //std::cout << skad << " " << dokad << " " << godzina << " " << data<<"\n\n";

                    std::shared_ptr<Polaczenie> ptr(new Polaczenie(idPolaczenie, skad, dokad, godzina, data, samoloty.find(idSamolotPolaczenie)->second));
                    polaczenia.insert(std::pair<int, std::shared_ptr<Polaczenie>>(idPolaczenie, std::move(ptr)));
                }
            }
        }

        plik.close();
        return polaczenia;
    }
    catch (std::string e) {
        std::cout << "Plik '" << nazwaPliku << "' nie mo¿e zostaæ poprawnie otwarty!\n";
        exit(1); // UWAGA NA TO
    }
};

std::map<int, std::shared_ptr<Bilet>> wczytajBilety(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Bilet>>& bilety, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia) {
    int idBilet;
    int idPolaczenie;
    int rzad;
    int kolumna;
    std::ifstream plik;
    try {
        plik.open(nazwaPliku);
        if (plik.fail())
            throw nazwaPliku;
        for (int i = 0; plik >> idBilet >> idPolaczenie >> rzad >> kolumna; i++) {
            std::shared_ptr<BiletNormalny> ptr(new BiletNormalny(idPolaczenie, rzad, kolumna, polaczenia.find(idPolaczenie)->second));
            bilety.insert(std::pair<int, std::shared_ptr<BiletNormalny>>(idBilet, std::move(ptr)));

        }

        plik.close();
        return bilety;
    }
    catch (std::string e) {
        std::cout << "Plik '" << nazwaPliku << "' nie mo¿e zostaæ poprawnie otwarty!\n";
        exit(1);
    }
}

std::map<int, std::shared_ptr<Bilet>> wczytajBiletyDwuosobowe(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Bilet>>& bilety, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia) {
    int idBilet, idPolaczenie, rzad1, kolumna1, rzad2, kolumna2;

    std::ifstream plik;
    try {
        plik.open(nazwaPliku);
        if (plik.fail())
            throw nazwaPliku;
        for (int i = 0; plik >> idBilet >> idPolaczenie >> rzad1 >> kolumna1 >> rzad2 >> kolumna2; i++) {
            std::shared_ptr<BiletDwuosobowy> ptr(new BiletDwuosobowy(idPolaczenie, rzad1, kolumna1, rzad2, kolumna2, polaczenia.find(idPolaczenie)->second));
            bilety.insert(std::pair<int, std::shared_ptr<BiletDwuosobowy>>(idBilet, std::move(ptr)));

        }

        plik.close();
        return bilety;
    }
    catch (std::string e) {
        std::cout << "Plik '" << nazwaPliku << "' nie mo¿e zostaæ poprawnie otwarty!\n";
        exit(1);
    }
}


std::vector<std::shared_ptr<Pasazer>> wczytajPasazerowie(const std::string& nazwaPliku, std::vector<std::shared_ptr<Pasazer>>& pasazerowie, std::map<int, std::shared_ptr<Bilet>>& bilety) {
    int idPasazera;
    std::string imie, nazwisko;
    int wiek;
    int idBiletuPasazera;
    std::ifstream plik;

    try {
        plik.open(nazwaPliku);
        if (plik.fail())
            throw nazwaPliku;

        while (plik >> imie >> nazwisko >> wiek >> idBiletuPasazera >> idPasazera) {
            std::shared_ptr<Pasazer> ptr(new Pasazer(imie, nazwisko, wiek, bilety.find(idBiletuPasazera)->second));
            pasazerowie.push_back(std::move(ptr));
        }

        plik.close();
        return pasazerowie;
    }
    catch (std::string e) {
        std::cout << "Plik '" << nazwaPliku << "' nie mo¿e zostaæ poprawnie otwarty!\n";
        exit(1);
    }
}
