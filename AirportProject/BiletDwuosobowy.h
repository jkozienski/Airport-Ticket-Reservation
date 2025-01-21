#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Polaczenie.h"
#include "Bilet.h"

/// <summary>
/// Klasa opisuj¹ca bilet dwuosobowy, dziedzicz¹ca po klasie bazowej Bilet
/// </summary>
class BiletDwuosobowy : public Bilet
{
private:
	std::string nazwa = "Dwuosobowy";
	std::pair<int, int> miejsce2;

public:
	/// <summary>
	/// Konstruktor biletu dwuosobowego
	/// </summary>
	/// <param name="idPolaczenie">Identyfikator po³¹czenia</param>
	/// <param name="rzad1">Numer rzêdu 1. miejsca w samolocie</param>
	/// <param name="kolumna1">Numer kolumny 1. miejsca w samolocie</param>
	/// <param name="rzad2">Numer rzêdu 2. miejsca w samolocie</param>
	/// <param name="kolumn2">Numer kolumny 2. miejsca w samolocie</param>
	/// <param name="polaczenia">Mapa po³¹czeñ</param>
	BiletDwuosobowy(int idPolaczenie, int rzad1, int kolumna1, int rzad2, int kolumn2, std::shared_ptr<Polaczenie> polaczenia);

	std::string getNazwa() override;

	void zapiszDoPliku(const std::string& nazwaPliku, int pidBiletDwuosobowy, int idPolaczenie, int rzad, int kolumna, int rzad2, int kolumna2);

};

