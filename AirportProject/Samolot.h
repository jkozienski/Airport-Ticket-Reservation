#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
/// <summary>
/// Klasa opisuj�ca samoloty
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
    /// Wypisuje stan zaj�to�ci miejsc w samolocie
    /// </summary>
    /// <param name="rzad">Numer rz�du w samolocie</param>
    /// <param name="kolumna">Numer kolumny w samolocie</param>
    void getMiejsca();
    
    /// <summary>
    /// Sprawdza czy podane miejsce jest zaj�te
    /// <param name="rzad">Numer rz�du w samolocie</param>
    /// <param name="kolumna">Numer kolumny w samolocie</param>
    /// <returns>Zwraca 1 gdy miejsce jest w samolocie jest zaj�te<returns>
    /// </summary>
    bool sprawdzCzyZajete(int rzad, int kolumna);
    
    /// <summary>
    /// Sprawdza czy podane miejsce jest zaj�te
    /// <param name="rzad">Numer rz�du w samolocie</param>
    /// <param name="kolumna">Numer kolumny w samolocie</param>
    /// <returns>Zwraca 1 gdy miejsce w samolocie istnieje<returns>
    /// </summary>
    bool czyMiejsceWSamolocieIstnieje(int rzad, int kolumna);
    
    /// <summary>
    /// Zmienia stan miejsca na zaj�te
    /// <param name="rzad">Numer rz�du w samolocie</param>
    /// <param name="kolumna">Numer kolumny w samolocie</param>
    /// </summary>
    void zarezerwujMiejsce(int rzad, int kolumna);
    
    /// <summary>
    /// Wczytuje zaj�te miejsca z pliku
    /// <param name="nazwaPliku">Wskazuje nazw�, z jakiego pliku ma by� wczytany</param>
    /// <param name="samoloty">Mapa samolot�w</param>
    /// </summary>
    void wczytajZajeteMiejsca(const std::string& nazwaPliku, std::map<int, std::shared_ptr<Samolot>>& samoloty);

    /// <summary>
    /// Ustawia stan miejsca w samolocie na wolne
    /// <param name="rzad">Numer rz�du w samolocie</param>
    /// <param name="kolumna">Numer kolumny w samolocie</param>
    /// </summary>
    void ustawMiejsceNaWolne(int rzad, int kolumna);
};
