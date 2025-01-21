#include "BiletDwuosobowy.h"
BiletDwuosobowy::BiletDwuosobowy(int idPolaczenie, int rzad1, int kolumna1, int rzad2, int kolumna2, std::shared_ptr<Polaczenie> polaczenia) : Bilet(idPolaczenie, rzad1, kolumna1, polaczenia) {
    this->miejsce.first = rzad1;
    this->miejsce.second = kolumna1;
    this->miejsce2.first = rzad2;
    this->miejsce2.second = kolumna2;

}

std::string BiletDwuosobowy::getNazwa() {
    return "Bilet Dwuosobowy";
}

void BiletDwuosobowy::zapiszDoPliku(const std::string& nazwaPliku, int pidBiletDwuosobowy, int idPolaczenie, int rzad, int kolumna,int rzad2,int kolumna2) {
    std::ofstream plik;
    try {
        plik.open(nazwaPliku, std::ios::out | std::ios::app);
        if (plik.fail()) {
            throw nazwaPliku;
        }
        plik << pidBiletDwuosobowy << " " << idPolaczenie << " " << kolumna << " " << rzad << " " << kolumna2 << " " << rzad2<< "\n";
        plik.close();

    }

    catch (std::string e) {
        std::cout << "Nie mo¿na poprawnie zapisaæ do pliku " << nazwaPliku << "!\n";
        exit(1);
    }
}