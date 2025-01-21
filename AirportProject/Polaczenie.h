#pragma once
#include <iostream>;
#include "Samolot.h";

/// <summary>
/// Klasa opisuj�ca po��czenia samolot�w
/// </summary>
class Polaczenie
{
private:
	int idPolaczenie;
	std::string skad, dokad, godzina, data;
	int idSamolotPolaczenie; //wskazuje kt�ry samolot jest przypisany do danego lotu
	std::shared_ptr<Samolot> PtrSamolot;

public:
	/// <summary>
	/// Konstruktor po��czenia
	/// </summary>
	/// <param name="idPolaczenie">Identyfikator po��czenia</param>
	/// <param name="skad">Informacja sk�d wylatuje samolot</param>
	/// <param name="dokad">Informacja dok�d leci samolot</param>
	/// <param name="godzina">Informacja o kt�rej godzinie jest wylot samolotu</param>
	/// <param name="data">Informacja o dacie wylotu samolotu</param>
	/// <param name="mapaSamoloty">Ineligentny wska�nik do przypisanego samolotu</param>
	Polaczenie(int idPolaczenie,std::string skad, std::string dokad, std::string godzina, std::string data, std::shared_ptr<Samolot> mapaSamoloty);
	int getIDPolaczenie();
	std::string getSkad();
	std::string getDokad();
	std::string getGodzina();
	std::string getData();
	std::shared_ptr<Samolot> getPtrSamolot();
	
	
	/// <summary>
	/// Zapisuje po��czenia do pliku
	/// </summary>
	/// <param name="nazwaPliku">Wskazuje nazw�, do jakiego pliku maj� by� zapisane po��czenia</param>
	/// <param name="polaczenia">Mapa po��cze�</param>
	void zapiszPolaczeniaDoPliku(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia);

};

