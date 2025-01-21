#pragma once
#include <vector>
#include <map>
#include "Samolot.h"
#include "Pasazer.h"
#include "Polaczenie.h"
#include "BiletNormalny.h";

/// <summary>
/// Wczytuje samoloty z pliku
/// </summary>
/// <param name="nazwaPliku">Wskazuje nazw�, z jakiego pliku maj� by� wczytane samoloty</param>
/// <param name="samoloty">Mapa samoloty</param>
/// <returns>Zwraca samoloty do mapy samoloty</returns>
std::map<int, std::shared_ptr<Samolot>> wczytajSamoloty(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Samolot>>& samoloty);

/// <summary>
/// Wczytuje zaj�te miejsca z pliku
/// </summary>
/// <param name="nazwaPliku">Wskazuje nazw�, z jakiego pliku maj� by� wczytane zaj�te miejsca</param>
/// <param name="polaczenia">Mapa po��cze�</param>
void wczytajZajeteMiejsca(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia);

/// <summary>
/// Wczytuje zaj�te miejsca z pliku
/// </summary>
/// <param name="nazwaPliku">Wskazuje nazw�, z jakiego pliku maj� by� wczytane zaj�te miejsca</param>
/// <param name="polaczenia">Mapa po��cze�</param>
void wczytajDwaZajeteMiejsca(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia);

/// <summary>
/// Wczytuje po��czenia z pliku
/// </summary>
/// <param name="nazwaPliku">Wskazuje nazw�, z jakiego pliku maj� by� wczytane zaj�te miejsca</param>
/// <param name="polaczenia">Mapa po��cze�</param>
/// <param name="samoloty">Mapa samolot�w</param>
/// <returns>Zwraca po��czenia do mapy po�aczenia</returns>
std::map<int, std::shared_ptr<Polaczenie>> wczytajPolaczenia(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia, std::map<int, std::shared_ptr<Samolot>>& samoloty);


/// <summary>
/// Wczytuje pasa�er�w z pliku
/// </summary>
/// <param name="nazwaPliku">Wskazuje nazw�, z jakiego pliku maj� by� wczytani pasa�erowie</param>
/// <param name="pasazerowie">Wektor pasa�er�w</param>
/// <param name="bilety">Mapa bilet�w</param>
/// <returns>Zwraca pasa�er�w do wektora pasazerowie</returns>
std::vector<std::shared_ptr<Pasazer>> wczytajPasazerowie(const std::string& nazwaPliku, std::vector<std::shared_ptr<Pasazer>>& pasazerowie, std::map<int, std::shared_ptr<Bilet>>& bilety);

/// <summary>
/// Wczytuje bilety normalne z pliku
/// </summary>
/// <param name="nazwaPliku">Wskazuje nazw�, z jakiego pliku maj� by� wczytane bilety normalne</param>
/// <param name="bilety">Mapa bilet�w</param>
/// <param name="polaczenia">Mapa po��cze�</param>
/// <returns>Zwraca bilety normalne do mapy bilety</returns>
std::map<int, std::shared_ptr<Bilet>> wczytajBilety(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Bilet>>& bilety, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia);

/// <summary>
/// Wczytuje bilety dwuosobowe z pliku
/// </summary>
/// <param name="nazwaPliku">Wskazuje nazw�, z jakiego pliku maj� by� wczytane bilety dwuosobowe</param>
/// <param name="bilety">Mapa bilet�w</param>
/// <param name="polaczenia">Mapa po��cze�</param>
/// <returns>Zwraca bilety dwuosobowe do mapy bilety</returns>
std::map<int, std::shared_ptr<Bilet>> wczytajBiletyDwuosobowe(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Bilet>>& bilety, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia);

