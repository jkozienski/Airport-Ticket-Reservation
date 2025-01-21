#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
/// <summary>
/// Klasa opisuj¹ca samoloty
/// </summary>
class Samolot {
private:
    std::string nazwa;
    int liczbaRzedow;
    int liczbaKolumn;
    int liczbaMiejsc;
    int idSamolot;
    std::vector<std::vector<bool>> miejsca;


public:
    Samolot(std::string nazwa, int liczbaRzedow, int liczbaKolumn, int idSamolot);
    int getLiczbaWolnychMiejsc();
    std::string getNazwa();
    int getLiczbaRzedow();
    int getLiczbaKolumn();
    int getIdSamolot();

    /// <summary>
    /// Wypisuje stan zajêtoœci miejsc w samolocie
    /// </summary>
    /// <param name="rzad">Numer rzêdu w samolocie</param>
    /// <param name="kolumna">Numer kolumny w samolocie</param>
    void getMiejsca();
    
    /// <summary>
    /// Sprawdza czy podane miejsce jest zajête
    /// <param name="rzad">Numer rzêdu w samolocie</param>
    /// <param name="kolumna">Numer kolumny w samolocie</param>
    /// <returns>Zwraca 1 gdy miejsce jest w samolocie jest zajête<returns>
    /// </summary>
    bool sprawdzCzyZajete(int rzad, int kolumna);
    
    /// <summary>
    /// Sprawdza czy podane miejsce jest zajête
    /// <param name="rzad">Numer rzêdu w samolocie</param>
    /// <param name="kolumna">Numer kolumny w samolocie</param>
    /// <returns>Zwraca 1 gdy miejsce w samolocie istnieje<returns>
    /// </summary>
    bool czyMiejsceWSamolocieIstnieje(int rzad, int kolumna);
    
    /// <summary>
    /// Zmienia stan miejsca na zajête
    /// <param name="rzad">Numer rzêdu w samolocie</param>
    /// <param name="kolumna">Numer kolumny w samolocie</param>
    /// </summary>
    void zarezerwujMiejsce(int rzad, int kolumna);
    
    /// <summary>
    /// Wczytuje zajête miejsca z pliku
    /// <param name="nazwaPliku">Wskazuje nazwê, z jakiego pliku ma byæ wczytany</param>
    /// <param name="samoloty">Mapa samolotów</param>
    /// </summary>
    void wczytajZajeteMiejsca(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Samolot>>& samoloty);

    /// <summary>
    /// Ustawia stan miejsca w samolocie na wolne
    /// <param name="rzad">Numer rzêdu w samolocie</param>
    /// <param name="kolumna">Numer kolumny w samolocie</param>
    /// </summary>
    void ustawMiejsceNaWolne(int rzad, int kolumna);
};
