#pragma once
#include <iostream>;
#include "Samolot.h";

/// <summary>
/// Klasa opisuj¹ca po³¹czenia samolotów
/// </summary>
class Polaczenie
{
private:
	int idPolaczenie;
	std::string skad, dokad, godzina, data;
	int idSamolotPolaczenie; //wskazuje który samolot jest przypisany do danego lotu
	std::shared_ptr<Samolot> PtrSamolot;

public:
	/// <summary>
	/// Konstruktor po³¹czenia
	/// </summary>
	/// <param name="idPolaczenie">Identyfikator po³¹czenia</param>
	/// <param name="skad">Informacja sk¹d wylatuje samolot</param>
	/// <param name="dokad">Informacja dok¹d leci samolot</param>
	/// <param name="godzina">Informacja o której godzinie jest wylot samolotu</param>
	/// <param name="data">Informacja o dacie wylotu samolotu</param>
	/// <param name="mapaSamoloty">Ineligentny wskaŸnik do przypisanego samolotu</param>
	Polaczenie(int idPolaczenie,std::string skad, std::string dokad, std::string godzina, std::string data, std::shared_ptr<Samolot> mapaSamoloty);
	int getIDPolaczenie();
	std::string getSkad();
	std::string getDokad();
	std::string getGodzina();
	std::string getData();
	std::shared_ptr<Samolot> getPtrSamolot();
	
	
	/// <summary>
	/// Zapisuje po³¹czenia do pliku
	/// </summary>
	/// <param name="nazwaPliku">Wskazuje nazwê, do jakiego pliku maj¹ byæ zapisane po³¹czenia</param>
	/// <param name="polaczenia">Mapa po³¹czeñ</param>
	void zapiszPolaczeniaDoPliku(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia);

};

