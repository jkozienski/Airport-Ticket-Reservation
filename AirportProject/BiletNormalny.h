#pragma once
#include <iostream>
#include "Polaczenie.h"
#include "Bilet.h"
/// <summary>
/// Klasa opisuj�ca bilet normalny, dziedzicz�ca po klasie bazowej Bilet
/// </summary>
class BiletNormalny : public Bilet
{
private:
	std::string nazwa = "Normalny";
public:
	std::string getNazwa() override;
	/// <summary>
	/// Konstruktor biletu normalnego
	/// </summary>
	/// <param name="idPolaczenie">Identyfikator po��cze�</param>
	/// <param name="rzad">Numer rz�du w samolocie</param>
	/// <param name="kolumna">Numer kolumny w samolocie</param>
	/// <param name="polaczenia">Inteligenty wska�nik do przypisanego po��czenia </param>
	BiletNormalny(int idPolaczenie,int rzad, int kolumna, std::shared_ptr<Polaczenie> polaczenia);
	/// <summary>
	/// Zapisuje bilety normalne do pliku
	/// </summary>
	/// <param name="nazwaPliku">Wskazuje nazw�, do jakiego pliku ma by� zapisany bilet normalny</param>
	/// <param name="pidBilet">Identyfikator biletu</param>
	/// <param name="idPolaczenie">Identyfikator po��czenia</param>
	/// <param name="rzad">Numer rz�du w samolocie</param>
	/// <param name="kolumna">Numer kolumny w samolocie</param>
	void zapiszDoPliku(const std::string& nazwaPliku, int pidBilet, int idPolaczenie, int rzad, int kolumna);

};

