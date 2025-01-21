#include <iostream>
#include "Menu.h"
#include "Samolot.h"
#include "Polaczenie.h"
#include "Pasazer.h"
#include "BiletNormalny.h"
#include "BiletDwuosobowy.h"
#include "func.h"
#include <memory>
#include <map>
#include <iomanip>
#include <cctype>

int Pasazer::pidPasazer = 0;
int Bilet::pidBilet = 0;

int main() {
	setlocale(LC_CTYPE, "Polish"); //polskie znaki

	std::map<int, std::shared_ptr<Samolot>> samoloty;
	wczytajSamoloty("pliki/samoloty.txt", samoloty);

	std::map<int, std::shared_ptr<Polaczenie>> polaczenia;
	wczytajPolaczenia("pliki/polaczenia.txt", polaczenia, samoloty);

	std::map<int, std::shared_ptr<Bilet>> bilety;
	wczytajBilety("pliki/biletyNormalne.txt", bilety, polaczenia);
	wczytajBiletyDwuosobowe("pliki/biletyDwuosobowe.txt", bilety, polaczenia);

	std::vector<std::shared_ptr<Pasazer>>pasazerowie;
	wczytajPasazerowie("pliki/pasazerowie.txt", pasazerowie, bilety);
	wczytajPasazerowie("pliki/pasazerowie2.txt", pasazerowie, bilety);

	wczytajZajeteMiejsca("pliki/biletyNormalne.txt", polaczenia);
	wczytajDwaZajeteMiejsca("pliki/biletyDwuosobowe.txt", polaczenia);

	int wybor;
	while (true) {
		system("cls");
		std::cout << "\u001B[30m\u001B[43m------------ MENU -------------" << std::endl;
		std::cout << "\u001B[42m*=============================*" << std::endl;
		std::cout << "|        Wybierz opcjê        |" << std::endl;
		std::cout << "*=============================*" << std::endl;
		std::cout << "|  1. Zarezerwuj bilet        |" << std::endl;
		std::cout << "|  2. Usuñ bilet              |" << std::endl;
		std::cout << "|  3. Wyœwietl dostêpne loty  |" << std::endl;
		std::cout << "|  4. Drukuj bilety do pliku  |" << std::endl;
		std::cout << "|  5. Drukuj loty do pliku    |" << std::endl;
		std::cout << "|  6. Wyœwietl bilety         |" << std::endl;
		std::cout << "|  7. Wyjœcie                 |" << std::endl;
		std::cout << "*=============================*\u001B[0m" << std::endl;
		



		std::string imie, nazwisko;
		int idBiletuUsun;

		
		try {
			std::cout << "\u001B[0mWybierz opcjê [1 - 7]: ";
			std::cin >> wybor;
			if (std::cin.fail()) {
				throw std::runtime_error("Wprowadzono niepoprawny znak");
			}

			if (wybor < 1 || wybor > 7) {
				throw std::runtime_error("Wprowadzono wartoœæ spoza zakresu 1-7");
			}
			switch (wybor) {

			case 1:
			{
				system("cls");
				int idPolaczenie, rodzajBiletu, rzad, kolumna, rzad2, kolumna2, wiek;

				std::cout << "======================= Bookowanie biletu =========================\n\n";
				std::cout << std::setw(2) << "ID";
				std::cout << std::setw(14) << "Sk¹d";
				std::cout << std::setw(12) << "Dok¹d";
				std::cout << std::setw(11) << "Godzina";
				std::cout << std::setw(10) << "Data";
				std::cout << std::setw(18) << "Wolne miejsca\n";
				std::cout << "-------------------------------------------------------------------\n";


				for (auto polaczenie : polaczenia) {
					std::cout << std::setw(2) << polaczenie.first << ". ";
					std::cout << std::setw(12) << polaczenie.second->getSkad();
					std::cout << std::setw(12) << polaczenie.second->getDokad();
					std::cout << std::setw(10) << polaczenie.second->getGodzina();
					std::cout << std::setw(14) << polaczenie.second->getData();
					std::cout << std::setw(8) << polaczenie.second->getPtrSamolot()->getLiczbaWolnychMiejsc() << "\n";
				}
				std::cout << "-------------------------------------------------------------------\n";
				std::cout << "Wybierz lot: \n";
				try 
				{
					std::cin >> idPolaczenie;
					if (std::cin.fail()) {
						throw std::runtime_error("Wprowadzono niepoprawny znak ");
					}

					if (idPolaczenie < 1 || idPolaczenie > 10) {
						throw std::runtime_error("Wprowadzono wartoœæ spoza dozwolonego zakresu ");
					}
					
			
					if (polaczenia[idPolaczenie]->getPtrSamolot()->getLiczbaWolnychMiejsc() > 0) {
						system("cls");
						std::cout << "====Wybierz rodzaj biletu====\n";
						std::cout << "1. Bilet normalny\n";
						std::cout << "2. Bilet dwuosobowy\n";
						std::cout << "3. Powrót\n";
						try 
						{
							std::cin >> rodzajBiletu;
							if (std::cin.fail()) {
								throw std::runtime_error("Wprowadzono niepoprawny znak ");
							
							}
							if (rodzajBiletu < 1 || rodzajBiletu > 3) {
								throw std::runtime_error("Wprowadzono wartoœæ spoza dozwolonego zakresu ");
								
							}

							switch (rodzajBiletu) {

							case 1: 
							{
								system("cls");
								int petla = 1;
								while (petla) {
									polaczenia[idPolaczenie]->getPtrSamolot()->getMiejsca();
									std::cout << "\nWybierz miejsce w samolocie [NP. \u001B[30m\u001B[42m 1 \u001B[0m\u001B[30m\u001B[43m 2 \u001B[0m]:\n";
									try
									{
										std::cin >> kolumna >> rzad;
										if (std::cin.fail()) {
											throw std::runtime_error("Wprowadzono niepoprawny znak ");
											
										}
									
										bool czyMiejsceIstnieje = polaczenia[idPolaczenie]->getPtrSamolot()->czyMiejsceWSamolocieIstnieje(rzad, kolumna);
										while (czyMiejsceIstnieje) {
											bool czyWolne = polaczenia[idPolaczenie]->getPtrSamolot()->sprawdzCzyZajete(kolumna, rzad);
											if (czyWolne) {
												polaczenia[idPolaczenie]->getPtrSamolot()->zarezerwujMiejsce(kolumna, rzad);

												std::shared_ptr<BiletNormalny> nowyBilet(new BiletNormalny(idPolaczenie, rzad, kolumna, polaczenia[idPolaczenie]));
												bilety.insert(std::pair<int, std::shared_ptr<Bilet>>(Bilet::pidBilet, std::move(nowyBilet)));
												nowyBilet->zapiszDoPliku("pliki/biletyNormalne.txt", Bilet::pidBilet, idPolaczenie, rzad, kolumna);

												system("cls");
												std::cout << "Podaj swoje dane\n";
												std::cout << "Imiê: ";
												std::cin >> imie;
												std::cout << "Nazwisko: ";
												std::cin >> nazwisko;
												std::cout << "Wiek: ";
												std::cin >> wiek;

												std::shared_ptr<Pasazer> nowyPasazer(new Pasazer(imie, nazwisko, wiek, bilety[Bilet::pidBilet]));
												pasazerowie.push_back(std::move(nowyPasazer));
												nowyPasazer->zapiszDoPliku("pliki/pasazerowie.txt", imie, nazwisko, wiek, Bilet::pidBilet, Pasazer::pidPasazer);
												petla = 0;
												system("cls");
												std::cout << "\u001B[30m\u001B[42mBilet pomyœlnie zarezerwowany!\u001B[0m\n";
												system("pause");
												break;
											}
											system("cls");

											polaczenia[idPolaczenie]->getPtrSamolot()->getMiejsca();
											std::cout << "\n\u001B[41mWybierz wolne miejsce w samolocie!\u001B[0m [NP. \u001B[30m\u001B[42m 1 \u001B[0m\u001B[30m\u001B[43m 2 \u001B[0m]\n";
											std::cin >> kolumna >> rzad;
											czyMiejsceIstnieje = polaczenia[idPolaczenie]->getPtrSamolot()->czyMiejsceWSamolocieIstnieje(rzad, kolumna);
										}
									}

									catch (const std::runtime_error& e) {
										system("cls");
										std::cerr << "\u001B[30m\u001B[43mWyj¹tek: " << e.what() << "\u001B[0m \n";
										system("pause");
										std::cin.clear();
										std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
									}
									system("cls");
									if (petla) {
										system("cls");
										std::cout << "\u001B[30m\u001B[43mMiejsce nie istnieje!\u001B[0m\n\n";
									}
								}
								std::cout << "\u001B[42m\u001B[35mRezerwacja miejsca przebieg³a pomyœlnie!\u001B[35m \u001B[0m \n";
								break;
							}
							case 2: 
							{
								if (polaczenia[idPolaczenie]->getPtrSamolot()->getLiczbaWolnychMiejsc() < 2) {
									system("cls");
									std::cout << "\u001B[30m\u001B[43mBrak dwóch wolnych miejsc w samolocie!\u001B[0m\n";
									system("pause");
									break;
								}
								else {
									int petla = 1;
									while (petla) {
										polaczenia[idPolaczenie]->getPtrSamolot()->getMiejsca();
										std::cout << "\nWybierz pierwsze miejsce w samolocie [NP. \u001B[30m\u001B[42m 1 \u001B[0m\u001B[30m\u001B[43m 2 \u001B[0m]\n";
										try
										{
											std::cin >> kolumna >> rzad;
											if (std::cin.fail()) {
												throw std::runtime_error("Wprowadzono niepoprawny znak \n");
											}

											std::cout << "Wybierz drugie miejsce w samolocie [NP. \u001B[30m\u001B[42m 1 \u001B[0m\u001B[30m\u001B[43m 2 \u001B[0m]\n";
											std::cin >> kolumna2 >> rzad2;
											if (std::cin.fail()) {
												throw std::runtime_error("Wprowadzono niepoprawny znak ");
											}

											bool czyMiejsceIstnieje1 = polaczenia[idPolaczenie]->getPtrSamolot()->czyMiejsceWSamolocieIstnieje(kolumna, rzad);
											bool czyMiejsceIstnieje2 = polaczenia[idPolaczenie]->getPtrSamolot()->czyMiejsceWSamolocieIstnieje(kolumna2, rzad2);

											while (czyMiejsceIstnieje1 && czyMiejsceIstnieje2) {
												bool czyWolne1 = polaczenia[idPolaczenie]->getPtrSamolot()->sprawdzCzyZajete(kolumna, rzad);
												bool czyWolne2 = polaczenia[idPolaczenie]->getPtrSamolot()->sprawdzCzyZajete(kolumna2, rzad2);

												if (czyWolne1 && czyWolne2) {
													polaczenia[idPolaczenie]->getPtrSamolot()->zarezerwujMiejsce(kolumna, rzad);
													polaczenia[idPolaczenie]->getPtrSamolot()->zarezerwujMiejsce(kolumna2, rzad2);

													std::shared_ptr<BiletDwuosobowy> nowyBilet(new BiletDwuosobowy(idPolaczenie, rzad, kolumna, rzad, kolumna, polaczenia[idPolaczenie]));
													bilety.insert(std::pair<int, std::shared_ptr<Bilet>>(Bilet::pidBilet, std::move(nowyBilet)));
													nowyBilet->zapiszDoPliku("pliki/biletyDwuosobowe.txt", Bilet::pidBilet, idPolaczenie, rzad, kolumna, rzad2, kolumna2);

													system("cls");
													std::cout << "Podaj swoje dane\n";
													std::cout << "Imiê: ";
													std::cin >> imie;
													std::cout << "Nazwisko: ";
													std::cin >> nazwisko;
													std::cout << "Wiek: ";
													std::cin >> wiek;

													std::shared_ptr<Pasazer> nowyPasazer(new Pasazer(imie, nazwisko, wiek, bilety[Bilet::pidBilet]));
													pasazerowie.push_back(std::move(nowyPasazer));
													nowyPasazer->zapiszDoPliku("pliki/pasazerowie2.txt", imie, nazwisko, wiek, Bilet::pidBilet, Pasazer::pidPasazer);
													system("cls");
													std::cout << "\u001B[30m\u001B[42mBilet pomyœlnie zarezerwowany!\u001B[0m\n";
													system("pause");

													petla = 0;
													break;
												}
												system("cls");
												std::cout << "\u001B[41mWskazane miejce jest zajête!\u001B[0m\n\n";

												polaczenia[idPolaczenie]->getPtrSamolot()->getMiejsca();
												std::cout << "\n\u001B[41mWybierz pierwsze wolne miejsce w samolocie!\u001B[0m\n";
												std::cin >> kolumna >> rzad;
												std::cout << "\u001B[41mWybierz drugie wolne miejsce w samolocie!\u001B[0m\n";
												std::cin >> kolumna2 >> rzad2;
												bool czyMiejsceIstnieje1 = polaczenia[idPolaczenie]->getPtrSamolot()->czyMiejsceWSamolocieIstnieje(kolumna, rzad);
												bool czyMiejsceIstnieje2 = polaczenia[idPolaczenie]->getPtrSamolot()->czyMiejsceWSamolocieIstnieje(kolumna2, rzad2);

											}
											if (petla) {
												system("cls");
												std::cout << "\u001B[30m\u001B[43mMiejsce nie istnieje!\u001B[0m\n\n";
											}

										}
										catch (const std::runtime_error& ex) {
											system("cls");
											std::cerr << "\u001B[30m\u001B[43mWyj¹tek: " << ex.what() << "\u001B[0m \n";
											system("pause");
											system("cls");
											std::cin.clear();
											std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
										}
									}

								}


							}
							case 3:
							{
								break;
							}
							}
						}
						catch (const std::runtime_error& ex) {
							system("cls");
							std::cerr << "\u001B[30m\u001B[43mWyj¹tek: " << ex.what() << "\u001B[0m \n";
							system("pause");
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

						}
						
							

							
					} else {
						system("cls");
						std::cout << "\u001B[30m\u001B[43mBrak wolnych miejsc w samolocie!\u001B[0m\n";
						system("pause");
					}
				}
				catch (const std::runtime_error& ex) {
					system("cls");
					std::cerr << "\u001B[30m\u001B[43mWyj¹tek: " << ex.what() << "\u001B[0m \n";
					system("pause");
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				}
			
				break;
				}
			case 2:
			{
				try {
					if (bilety.size() < 1) {
						system("cls");
						throw ("Brak zarezerwowanych biletów w systemie!");
					}
					else {
						system("cls");
						std::cout << "====== Usuwanie rezerwacji biletu ======\n";
						std::cout << "Podaj imiê i nazwisko" << std::endl;
						std::cin >> imie >> nazwisko;
						system("cls");
						pasazerowie[0]->wypiszZarezerwowaneBilety(imie, nazwisko, pasazerowie);
						bool czyMaBilet = pasazerowie[0]->czyMaBilet(pasazerowie, imie, nazwisko);
						if (czyMaBilet) {
							bool czyNaPewno;
							std::cout << "\nCzy na pewno chcesz usun¹æ rezerwacjê biletu?[\u001B[30m\u001B[42m1 - tak\u001B[0m, \u001B[41m0 - nie\u001B[0m]\n";
							std::cin >> czyNaPewno;
							if (czyNaPewno) {
								system("cls");
								pasazerowie[0]->wypiszZarezerwowaneBilety(imie, nazwisko, pasazerowie);
								std::cout << "\nKtóry bilet chcesz usun¹æ [podaj Id]?\n";
								std::cin >> idBiletuUsun;
								pasazerowie[0]->usunBilet(idBiletuUsun, imie, nazwisko, pasazerowie, bilety, "pliki/pasazerowie.txt", "pliki/biletyNormalne.txt", "pliki/pasazerowie2.txt", "pliki/biletyDwuosobowe.txt", samoloty);
							}
							else {
								break;
							}
						}
						system("pause");
						break;
					}
				}
				catch (const char* ex) {
					std::cerr << "\u001B[30m\u001B[43mWyj¹tek: " << ex << "\u001B[0m\n";
					system("pause");
					break;
				}
			}
			case 3:
			{
				system("cls");
				std::cout << "====================== Dostêpne po³¹czenia ========================\n\n";
				std::cout << std::setw(2) << "\u001B[33mID";
				std::cout << std::setw(14) << "Sk¹d";
				std::cout << std::setw(12) << "Dok¹d";
				std::cout << std::setw(11) << "Godzina";
				std::cout << std::setw(10) << "Data";
				std::cout << std::setw(16) << "Wolne miejsca\u001B[0m\n";
				std::cout << "-------------------------------------------------------------------\n";


				for (auto polaczenie : polaczenia) {
					std::cout << std::setw(2) <<"\u001B[33m" << polaczenie.first << ".\u001B[0m";
					std::cout << std::setw(14) << polaczenie.second->getSkad();
					std::cout << std::setw(12) << polaczenie.second->getDokad();
					std::cout << std::setw(10) << polaczenie.second->getGodzina();
					std::cout << std::setw(14) << polaczenie.second->getData();
					std::cout << std::setw(8) << polaczenie.second->getPtrSamolot()->getLiczbaWolnychMiejsc() << "\n";
				}
				std::cout << "-------------------------------------------------------------------\n";
				system("pause");
				break;
			}
			case 4:
			{
				try 
				{
					if (pasazerowie.size() < 1) {
						throw std::runtime_error("Brak pasa¿erów w systemie");
					}

					std::string plikDoWypisaniaBiletow = "pliki/wydrukowaneBilety.txt";
					system("cls");
					std::cout << "====== Wydrukuj swoje bilety do pliku ======" << std::endl;
					std::cout << "Podaj imiê i nazwisko" << std::endl;
					std::cin >> imie >> nazwisko;
					
					system("cls");
					pasazerowie[0]->zapiszZarezerwowaneBiletyDoPliku(pasazerowie, imie,nazwisko, plikDoWypisaniaBiletow);
					system("pause");
					break;
				}
				catch (const std::runtime_error& ex) {
					system("cls");
					std::cerr << "\u001B[30m\u001B[43mWyj¹tek: " << ex.what() << "\u001B[0m \n";
					system("pause");
				}
			}
			break;
			case 5:
			{
				try {
					if (polaczenia.size() < 1) {
						throw std::runtime_error("Brak po³¹czeñ w systemie");
					}
					std::string plikDoWypisaniaPolaczenia = "pliki/wydrukowanePolaczenia.txt";
					system("cls");
					std::cout << "====== Wydrukuj dostêpne po³¹czenia ======\n\n";
					polaczenia[1]->zapiszPolaczeniaDoPliku(plikDoWypisaniaPolaczenia, polaczenia);
					system("cls");
					std::cout << "\u001B[30m\u001B[42mPomyœlnie wydrukowano po³¹czenia do pliku \u001B[0m\n";

					system("pause");
					break;
				}
				catch (const std::runtime_error& ex) {
					system("cls");
					std::cerr << "\u001B[30m\u001B[43mWyj¹tek: " << ex.what() << "\u001B[0m \n";
					system("pause");
				}
			}

			break;
			case 6:
			{
				try {
					if (pasazerowie.size() < 1) {
						system("cls");
						throw ("Brak zarezerwowanych biletów w systemie! ");
					}
					else {
						system("cls");
						std::cout << "====== SprawdŸ swoje loty ======" << std::endl;
						std::cout << "Podaj imiê i nazwisko" << std::endl;
						std::cin >> imie >> nazwisko;
						system("cls");
						pasazerowie[0]->wypiszZarezerwowaneBilety(imie, nazwisko, pasazerowie);
						std::cout << "\n";

						system("pause");
						break;
					}
				}
				catch (const char* ex) {
					std::cerr<<"\u001B[30m\u001B[43mWyj¹tek: " << ex << "\u001B[0m\n";
					system("pause");
					break;
				}
			}
			case 7:
				return 0;

			default: 
			{
				system("cls");
				std::cout << "Nieprawid³owy wybór. Wybierz opcjê od 1 do 7." << std::endl;
				system("pause");
			}
			}
		}
		 catch (const std::runtime_error& ex) {
			 system("cls");
			 std::cerr << "\u001B[30m\u001B[43mWyj¹tek: " << ex.what() << "\u001B[0m \n";
			 system("pause");
			 std::cin.clear();
			 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		 }
	}
return 0;

}
