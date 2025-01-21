#include "Pasazer.h"
#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <fstream>
#include <map>
#include <iomanip>

Pasazer::Pasazer(std::string imie, std::string nazwisko, int wiek, std::shared_ptr<Bilet> PtrBilet)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->wiek = wiek;
    this->idPasazer = pidPasazer;
    pidPasazer++;
	this->PtrBilet = PtrBilet;
}

std::string Pasazer::getImie()
{
	return this->imie;
}
std::string Pasazer::getNazwisko() 
{
	return this->nazwisko;
}
int Pasazer::getWiek() {
	return this->wiek;
}
std::shared_ptr<Bilet> Pasazer::getptrBilet()
{
	return this->PtrBilet;
}


void Pasazer::zapiszDoPliku(const std::string& nazwaPliku, std::string imie, std::string nazwisko, int wiek, int idBilet,int pidPasazer) {
    std::ofstream plik;
    try {
        plik.open(nazwaPliku, std::ios::out | std::ios::app);
        if (plik.fail()) {
            throw nazwaPliku;
        }
        plik <<imie << " " << nazwisko <<" " << wiek << " " << idBilet<<" "<<pidPasazer << "\n";
        plik.close();

    }

    catch (std::string e) {
        std::cout << "Nie mo¿na poprawnie zapisaæ do pliku " << nazwaPliku << "!\n";
        exit(1); 
    }
}

void Pasazer::wypiszZarezerwowaneBilety(const std::string& imie, const std::string& nazwisko, std::vector<std::shared_ptr<Pasazer>>& pasazerowie) const {
    bool znalezionoPasazera = false;
    int licznik = 0;

    for (const auto& pasazer : pasazerowie) {
        if (pasazer->getImie() == imie && pasazer->getNazwisko() == nazwisko) {
            const auto& bilet = pasazer->getptrBilet();
            if (licznik % 2 == 1) {
                std::cout << "\u001B[30m\u001B[46m";  
            } else {
                std::cout << "\u001B[30m\u001B[44m";  
            }
            std::cout << "Id biletu: " << std::setw(3) << bilet->getidBilet() + 1 << "   \n";
            std::cout << "\u001B[0m"; 
            std::cout << "Typ biletu: " << std::setw(4) << bilet->getNazwa() << "\n";
            std::cout << "Polaczenie: " << std::setw(3) << bilet->getPtrPolaczenie()->getSkad() << " - " << bilet->getPtrPolaczenie()->getDokad() << "\n";
            std::cout << "Samolot: " << std::setw(14) << bilet->getPtrPolaczenie()->getPtrSamolot()->getNazwa() <<"\n";
            std::cout << "Godzina: " << std::setw(8) << bilet->getPtrPolaczenie()->getGodzina()<<"\n";
            std::cout << "Data: " << std::setw(16) << bilet->getPtrPolaczenie()->getData() << "\n";


            znalezionoPasazera = true;
            licznik++;
        }
    }

    if (!znalezionoPasazera) {
        std::cout << "\u001B[30m\u001B[43mNie znaleziono pasa¿era " << imie << " " << nazwisko <<"\u001B[0m" << std::endl;
    }
}

void Pasazer::zapiszZarezerwowaneBiletyDoPliku(const std::vector<std::shared_ptr<Pasazer>>&pasazerowie, const std::string & imie, const std::string & nazwisko, const std::string & nazwaPliku){
    std::ofstream plikDoZapisu(nazwaPliku, std::ios::trunc);
    bool znalezionoPasazera = false;

    if (!plikDoZapisu) {
        std::cout << "B³¹d przy otwieraniu pliku." << std::endl;
        return;
    }

    for (const auto& pasazer : pasazerowie) {
        if (pasazer->getImie() == imie && pasazer->getNazwisko() == nazwisko) {
            const auto& bilet = pasazer->getptrBilet();
        
            plikDoZapisu << "Id biletu: " << bilet->getidBilet() + 1 << "\n";
            plikDoZapisu << "Rodzaj: " << std::setw(12) << bilet->getNazwa() << "\n";
            plikDoZapisu << "Polaczenie: " <<   bilet->getPtrPolaczenie()->getSkad() << " - " << bilet->getPtrPolaczenie()->getDokad() << "\n";
            plikDoZapisu << "Samolot: " << bilet->getPtrPolaczenie()->getPtrSamolot()->getNazwa() << "\n";
            plikDoZapisu << "Godzina: " << std::setw(8) << bilet->getPtrPolaczenie()->getGodzina() << "\n";
            plikDoZapisu << "Data: " << std::setw(16) << bilet->getPtrPolaczenie()->getData() << "\n\n";

            znalezionoPasazera = true;
          
        }
    }
    if (znalezionoPasazera) {
        std::cout << "\u001B[30m\u001B[42mWszytko przebieg³o pomyœlnie!\u001B[0m\n";

    }
    if (!znalezionoPasazera) {
        std::cout << "\u001B[30m\u001B[43mNie znaleziono pasa¿era " << imie << " " << nazwisko << "\u001B[0m" << std::endl;
    }
}

void Pasazer::usunBilet(int idBilet, const std::string& imie, const std::string& nazwisko, std::vector<std::shared_ptr<Pasazer>>& pasazerowie, std::map<int, std::shared_ptr<Bilet>>& bilety, const std::string& nazwaPliku, const std::string& nazwaPlikuBiletyNormalne, const std::string& nazwaPlikuPasazerowie2, const std::string& nazwaPlikuBiletyDwuosobowe, std::map<int, std::shared_ptr<Samolot>>& samoloty){
    bool znalezionoPasazera = false;
    bool znalezionoBilet = false;

    // Usuniêcie linii z kontenera pasazerowie
    pasazerowie.erase(std::remove_if(pasazerowie.begin(), pasazerowie.end(), [&](const std::shared_ptr<Pasazer>& pasazer) {
        if (pasazer->getImie() == imie && pasazer->getNazwisko() == nazwisko && pasazer->getptrBilet()->getidBilet()+1 == idBilet) {
            znalezionoPasazera = true;
            znalezionoBilet = true;
            return true;
        }
    return false;
        }), pasazerowie.end());

    // Usuniêcie linii z pliku pasazerowie
    std::ifstream plik(nazwaPliku);
    std::ofstream plikDoZapisu(nazwaPliku + ".tmp", std::ios::app | std::ios::out);

    if (!plik || !plikDoZapisu) {
        std::cout << "B³¹d przy otwieraniu plików." << std::endl;
        return;
    }
    
    int tempIdBilet1, wiek1,idPasazera1;
    std::string tempImie1,tempNazwisko1;
        for (int i = 0; plik >> tempImie1 >> tempNazwisko1 >> wiek1 >> tempIdBilet1>> idPasazera1; i++) {
            if (tempIdBilet1 != idBilet || tempImie1 != imie || tempNazwisko1 != nazwisko) {

                plikDoZapisu << tempImie1 << " " << tempNazwisko1 << " " << wiek << " " << tempIdBilet1 <<" "<< idPasazera1 << "\n";
            }
            else {
                znalezionoPasazera = true;
            }
        }

    plik.close();
    plikDoZapisu.close();
    std::remove(nazwaPliku.c_str());
    std::rename((nazwaPliku + ".tmp").c_str(), nazwaPliku.c_str());


    // Usuniêcie linii z pliku pasazerowie2
    std::ifstream plikPasazerowie2 (nazwaPlikuPasazerowie2);
    std::ofstream plikDoZapisuPasazerowie2(nazwaPlikuPasazerowie2 + ".tmp", std::ios::app | std::ios::out);

    if (!plikPasazerowie2 || !plikDoZapisuPasazerowie2) {
        std::cout << "\u001B[30m\u001B[41mB³¹d przy otwieraniu plików.\u001B[0m" << std::endl;
        return;
    }
   
    int tempIdBilet2, wiek2, idPasazera2;
    std::string tempImie2, tempNazwisko2;
    for (int i = 0; plik >> tempImie2 >> tempNazwisko2 >> wiek2 >> tempIdBilet2 >> idPasazera2; i++) {
        if (tempIdBilet2 != idBilet || tempImie2 != imie || tempNazwisko2 != nazwisko) {

            plikDoZapisuPasazerowie2 << tempImie2 << " " << tempNazwisko2 << " " << wiek << " " << tempIdBilet2 << " " << idPasazera2 << "\n";
        }
        else {
            znalezionoPasazera = true;
        }
    }

    plikPasazerowie2.close();
    plikDoZapisuPasazerowie2.close();
    std::remove(nazwaPlikuPasazerowie2.c_str());
    std::rename((nazwaPlikuPasazerowie2 + ".tmp").c_str(), nazwaPlikuPasazerowie2.c_str());


    // Usuniêcie linii z pliku biletyDwuosobowe
    std::ifstream plikBiletyDwuosobowe(nazwaPlikuBiletyDwuosobowe);
    std::ofstream plikDoZapisuBiletyDwuosobowe(nazwaPlikuBiletyDwuosobowe + ".tmp", std::ios::app | std::ios::out);

    if (!plikBiletyDwuosobowe || !plikDoZapisuBiletyDwuosobowe) {
        std::cout << "B³¹d przy otwieraniu plików." << std::endl;
        return;
    }

    int tempIdBilet3,tempidPolaczenia3,tempKolumna1,tempRzad1,tempKolumna2, tempRzad2;
    
    for (int i = 0; plikBiletyDwuosobowe >> tempIdBilet3 >> tempidPolaczenia3 >> tempKolumna1 >> tempRzad1 >> tempKolumna2 >> tempRzad2; i++) {
        if (tempIdBilet3 != idBilet) {
            plikDoZapisuBiletyDwuosobowe << tempIdBilet3 << " " << tempidPolaczenia3 << " " << tempKolumna1 << " " << tempRzad1 << " " << tempKolumna2 << " " << tempRzad2<< "\n";
        }
        else {
            samoloty[bilety[tempIdBilet3]->getPtrPolaczenie()->getPtrSamolot()->getIdSamolot()]->ustawMiejsceNaWolne(tempKolumna1, tempRzad1);
            samoloty[bilety[tempIdBilet3]->getPtrPolaczenie()->getPtrSamolot()->getIdSamolot()]->ustawMiejsceNaWolne(tempKolumna2, tempRzad2);

            znalezionoBilet = true;
        }
    }
    plikBiletyDwuosobowe.close();
    plikDoZapisuBiletyDwuosobowe.close();
    std::remove(nazwaPlikuBiletyDwuosobowe.c_str());
    std::rename((nazwaPlikuBiletyDwuosobowe + ".tmp").c_str(), nazwaPlikuBiletyDwuosobowe.c_str());


    // Usuniêcie linii z kontenera bilety
    auto it = bilety.find(idBilet);
    if (it != bilety.end()) {
        bilety.erase(it);
        znalezionoBilet = true;
    }
    // Usuniêcie linii z pliku biletyNormalne
    std::ifstream plikBiletyNormalne(nazwaPlikuBiletyNormalne);
    std::ofstream plikDoZapisuBiletyNormalne(nazwaPlikuBiletyNormalne + ".tmp", std::ios::app | std::ios::out);
    
    if (!plikBiletyNormalne || !plikDoZapisuBiletyNormalne) {
        std::cout << "B³¹d przy otwieraniu plików." << std::endl;
        return;
    }
    //int tempIdBiletNormalny, tempidPolaczenia, tempKolumna,tempRzad;
    int tempIdBilet4, tempidPolaczenia4, tempKolumna3, tempRzad3;

    for (int i = 0; plikBiletyNormalne >> tempIdBilet4 >> tempidPolaczenia4 >> tempKolumna3 >> tempRzad3; i++) {
        if (tempIdBilet4 != idBilet) {
            plikDoZapisuBiletyNormalne << tempIdBilet4 <<" " << tempidPolaczenia4 <<" " << tempKolumna3<<" " << tempRzad3 << "\n";
        }
        else {
            std::cout << bilety[i]->getPtrPolaczenie()->getPtrSamolot()->getNazwa();
            samoloty[bilety[i]->getPtrPolaczenie()->getPtrSamolot()->getIdSamolot()]->ustawMiejsceNaWolne(tempKolumna3, tempRzad3);
            znalezionoBilet = true;
        }
    }
    plikBiletyNormalne.close();
    plikDoZapisuBiletyNormalne.close();
    std::remove(nazwaPlikuBiletyNormalne.c_str());
    std::rename((nazwaPlikuBiletyNormalne + ".tmp").c_str(), nazwaPlikuBiletyNormalne.c_str());
 
   if (!znalezionoBilet) {
        system("cls");
        std::cout << "\u001B[30m\u001B[43mNie znaleziono biletu o ID " << idBilet << ".\u001B[0m" << std::endl;
    } else if (znalezionoPasazera && znalezionoBilet) {
        system("cls");
        std::cout << "\u001B[30m\u001B[43mUsuniêto bilet o ID " << idBilet << ".\u001B[0m" << std::endl;
    }
    
}

bool Pasazer::czyMaBilet(const std::vector<std::shared_ptr<Pasazer>>& pasazerowie, const std::string& imie, const std::string& nazwisko) {
    for (const auto& pasazer : pasazerowie) {
        if (pasazer->getImie() == imie && pasazer->getNazwisko() == nazwisko) {
            return true;// znaleziony
        }
    }
    return false; //  nie znaleziony
}