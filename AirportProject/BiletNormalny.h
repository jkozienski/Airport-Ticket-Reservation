#pragma once
#include <iostream>
#include "Polaczenie.h"
#include "Bilet.h"
/// <summary>
/// Klasa opisuj¹ca bilet normalny, dziedzicz¹ca po klasie bazowej Bilet
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
	/// <param name="idPolaczenie">Identyfikator po³¹czeñ</param>
	/// <param name="rzad">Numer rzêdu w samolocie</param>
	/// <param name="kolumna">Numer kolumny w samolocie</param>
	/// <param name="polaczenia">Inteligenty wskaŸnik do przypisanego po³¹czenia </param>
	BiletNormalny(int idPolaczenie,int rzad, int kolumna, std::shared_ptr<Polaczenie> polaczenia);
	/// <summary>
	/// Zapisuje bilety normalne do pliku
	/// </summary>
	/// <param name="nazwaPliku">Wskazuje nazwê, do jakiego pliku ma byæ zapisany bilet normalny</param>
	/// <param name="pidBilet">Identyfikator biletu</param>
	/// <param name="idPolaczenie">Identyfikator po³¹czenia</param>
	/// <param name="rzad">Numer rzêdu w samolocie</param>
	/// <param name="kolumna">Numer kolumny w samolocie</param>
	void zapiszDoPliku(const std::string& nazwaPliku, int pidBilet, int idPolaczenie, int rzad, int kolumna);

};

