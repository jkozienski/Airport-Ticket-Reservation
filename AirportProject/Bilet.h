#pragma once
#include "Polaczenie.h"
/// <summary>
/// Klasa bazowa opisuj�ca bilet
/// </summary>
/// 

class Bilet
{
protected:
	int idBilet;
	int idPolaczenie;
	std::shared_ptr<Polaczenie> PtrPolaczenie;
	std::pair<int, int> miejsce;

public:

	static int pidBilet;
	virtual std::string getNazwa();
	
	/// <summary>
	/// Konstruktor biletu
	/// </summary>
	/// <param name="idPolaczenie">Identyfikator po��czenia</param>
	/// <param name="rzad">Numer rz�du w samolocie</param>
	/// <param name="kolumna">Numer kolumny w samolocie</param>
	/// <param name="polaczenia">Wektor po��cze�</param>
	Bilet(int idPolaczenie, int rzad, int kolumna, std::shared_ptr<Polaczenie> polaczenia);
	int getidBilet();
	int getidPolaczenie();
	std::shared_ptr<Polaczenie> getPtrPolaczenie();

};


