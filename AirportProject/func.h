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
/// <param name="nazwaPliku">Wskazuje nazwê, z jakiego pliku maj¹ byæ wczytane samoloty</param>
/// <param name="samoloty">Mapa samoloty</param>
/// <returns>Zwraca samoloty do mapy samoloty</returns>
std::map<int, std::shared_ptr<Samolot>> wczytajSamoloty(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Samolot>>& samoloty);

/// <summary>
/// Wczytuje zajête miejsca z pliku
/// </summary>
/// <param name="nazwaPliku">Wskazuje nazwê, z jakiego pliku maj¹ byæ wczytane zajête miejsca</param>
/// <param name="polaczenia">Mapa po³¹czeñ</param>
void wczytajZajeteMiejsca(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia);

/// <summary>
/// Wczytuje zajête miejsca z pliku
/// </summary>
/// <param name="nazwaPliku">Wskazuje nazwê, z jakiego pliku maj¹ byæ wczytane zajête miejsca</param>
/// <param name="polaczenia">Mapa po³¹czeñ</param>
void wczytajDwaZajeteMiejsca(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia);

/// <summary>
/// Wczytuje po³¹czenia z pliku
/// </summary>
/// <param name="nazwaPliku">Wskazuje nazwê, z jakiego pliku maj¹ byæ wczytane zajête miejsca</param>
/// <param name="polaczenia">Mapa po³¹czeñ</param>
/// <param name="samoloty">Mapa samolotów</param>
/// <returns>Zwraca po³¹czenia do mapy po³aczenia</returns>
std::map<int, std::shared_ptr<Polaczenie>> wczytajPolaczenia(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia, std::map<int, std::shared_ptr<Samolot>>& samoloty);


/// <summary>
/// Wczytuje pasa¿erów z pliku
/// </summary>
/// <param name="nazwaPliku">Wskazuje nazwê, z jakiego pliku maj¹ byæ wczytani pasa¿erowie</param>
/// <param name="pasazerowie">Wektor pasa¿erów</param>
/// <param name="bilety">Mapa biletów</param>
/// <returns>Zwraca pasa¿erów do wektora pasazerowie</returns>
std::vector<std::shared_ptr<Pasazer>> wczytajPasazerowie(const std::string& nazwaPliku, std::vector<std::shared_ptr<Pasazer>>& pasazerowie, std::map<int, std::shared_ptr<Bilet>>& bilety);

/// <summary>
/// Wczytuje bilety normalne z pliku
/// </summary>
/// <param name="nazwaPliku">Wskazuje nazwê, z jakiego pliku maj¹ byæ wczytane bilety normalne</param>
/// <param name="bilety">Mapa biletów</param>
/// <param name="polaczenia">Mapa po³¹czeñ</param>
/// <returns>Zwraca bilety normalne do mapy bilety</returns>
std::map<int, std::shared_ptr<Bilet>> wczytajBilety(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Bilet>>& bilety, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia);

/// <summary>
/// Wczytuje bilety dwuosobowe z pliku
/// </summary>
/// <param name="nazwaPliku">Wskazuje nazwê, z jakiego pliku maj¹ byæ wczytane bilety dwuosobowe</param>
/// <param name="bilety">Mapa biletów</param>
/// <param name="polaczenia">Mapa po³¹czeñ</param>
/// <returns>Zwraca bilety dwuosobowe do mapy bilety</returns>
std::map<int, std::shared_ptr<Bilet>> wczytajBiletyDwuosobowe(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Bilet>>& bilety, std::map<int, std::shared_ptr<Polaczenie>>& polaczenia);

