#include <iostream>
#include <string>
#include <fstream>
#include "BiletNormalny.h"


BiletNormalny::BiletNormalny(int idPolaczenie, int rzad, int kolumna, std::shared_ptr<Polaczenie> polaczenia) : Bilet(idPolaczenie, rzad, kolumna, polaczenia) {
    ;
}

std::string BiletNormalny::getNazwa(){
    return "Bilet Normalny";
}

void BiletNormalny::zapiszDoPliku(const std::string& nazwaPliku, int pidBilet, int idPolaczenie, int rzad, int kolumna) {
    std::ofstream plik;
    try {
        plik.open(nazwaPliku, std::ios::out | std::ios::app);
        if (plik.fail()) {
            throw nazwaPliku;
        }
        plik << pidBilet << " " << idPolaczenie << " " << kolumna << " " << rzad << "\n";
        plik.close();
        
    }

    catch (std::string e) {
        std::cout << "Nie mo¿na poprawnie zapisaæ do pliku " <<nazwaPliku <<"!\n";
        exit(1); // UWAGA NA TO
    }
}