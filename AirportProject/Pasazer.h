#pragma once
#include <iostream>
#include "BiletNormalny.h"
/// <summary>
/// Klasa opisuj�ca pasa�era
/// </summary>
class Pasazer
{
private:
	std::string imie;
	std::string nazwisko;
	int wiek;
	int nrTelefonu;
	std::shared_ptr<Bilet> PtrBilet;
	int idPasazer;


public:
	static int pidPasazer;
	Pasazer(std::string imie, std::string nazwisko, int wiek, std::shared_ptr<Bilet> PtrBiletNormalny);
	std::string getImie();
	std::string getNazwisko();
	int getWiek();
	std::shared_ptr<Bilet> getptrBilet();
	
	/// <summary>
	/// Zapisuje pasa�era do pliku
	/// </summary>
	/// <param name="nazwaPliku">Wskazuje nazw�, do jakiego pliku ma by� zapisany pasa�er</param>
	/// <param name="imie">Imi� pasa�era</param>
	/// <param name="nazwisko">Nazwisko pasa�era</param>
	/// <param name="wiek">Wiek pasa�era</param>
	/// <param name="idBilet">Identyfikator biletu</param>
	/// <param name="pidPasazer">Identyfikator pasa�era</param>
	void zapiszDoPliku(const std::string& nazwaPliku,std::string imie, std::string nazwisko, int wiek, int idBilet, int pidPasazer);
	
	/// <summary>
	/// Wypisuje do konsoli zarezerwowane bilety przez wskazanego pasa�era
	/// </summary>
	/// <param name="imie">Imie pasa�aera</param>
	/// <param name="nazwisko">Nazwisko pasa�era</param>
	/// <param name="pasazerowie">Wektor pasa�er�w</param>
	void wypiszZarezerwowaneBilety(const std::string& imie, const std::string& nazwisko, std::vector<std::shared_ptr<Pasazer>>& pasazerowie) const;

	/// <summary>
	/// Zapisuje zarezerwowane bilety do pliku
	/// </summary>
	/// <param name="pasazerowie">Wektor po��cze�</param>
	/// <param name="imie">Imi� pasa�era</param>
	/// <param name="nazwisko">Nazwisko pasa�era</param>
	/// <param name="nazwaPliku">Wskazuje nazw�, do jakiego pliku maj� by� zapisane bilety</param>
	void zapiszZarezerwowaneBiletyDoPliku(const std::vector<std::shared_ptr<Pasazer>>& pasazerowie, const std::string& imie, const std::string& nazwisko, const std::string& nazwaPliku);

	/// <summary>
	/// Usuwa zarezerwowany bilet
	/// </summary>
	/// <param name="idBilet">Identyfikator biletu</param>
	/// <param name="imie">Imi� pasa�era</param>
	/// <param name="nazwisko">Nazwisko pasa�era</param>
	/// <param name="pasazerowie">Wektor pasa�er�w</param>
	/// <param name="bilety">mapa bilet�w</param>
	/// <param name="nazwaPliku">Wskazuje nazw�, z jakiego pliku pasa�er�w ma by� usuni�ty bilet normalny</param>
	/// <param name="nazwaPlikuBiletyNormalne">Wskazuje nazw�, z jakiego pliku bilet�w ma by� usuni�ty bilet normalny</param>
	/// <param name="nazwaPlikuPasazerowie2">Wskazuje nazw�, z jakiego pliku pasa�er�w ma by� usuni�ty bilet dwuosobowy</param>
	/// <param name="nazwaPlikuBiletyDwuosobowe">Wskazuje nazw�, z jakiego pliku bilet�w ma by� usuni�ty bilet dwuosobowy</param>
	/// <param name="samoloty">Mapa samolot�w</param>
	void usunBilet(int idBilet, const std::string& imie, const std::string& nazwisko, std::vector<std::shared_ptr<Pasazer>>& pasazerowie, std::map<int, std::shared_ptr<Bilet>>& bilety, const std::string& nazwaPliku, const std::string& nazwaPlikuBiletyNormalne, const std::string& nazwaPlikuPasazerowie2, const std::string& nazwaPlikuBiletyDwuosobowe, std::map<int, std::shared_ptr<Samolot>>& samoloty);


	/// <summary>
	/// Sprawdz czy pasa�er posiada zarezerwowany bilet
	/// </summary>
	/// <param name="pasazerowie">Wektor pasa�er�w</param>
	/// <param name="imie">Imi� pasa�era</param>
	/// <param name="nazwisko">Nazwisko pasa�era</param>
	/// <returns>Zwraca true je�eli pasa�er ma zarezerwowany przynajmniej jeden bilet</returns>
	bool czyMaBilet(const std::vector<std::shared_ptr<Pasazer>>& pasazerowie, const std::string& imie, const std::string& nazwisko);

};

