#include "Menu.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>

std::string DUMMY;

void Menu::Uruchom() {
    while (true) {
        ShowMenu();
        int choice;
        std::cin >> choice;
       // std::cin.ignore();  // Ignorowanie znaku nowej linii

        switch (choice) {
        case 1:
            system("cls");
            AddConnection();
            break;
        case 2:
            system("cls");
            TicketReservation();
            break;
        case 3:
            system("cls");
            DeleteReservation();
            break;
        case 4:
            system("cls");
            PrintConnections();
            break;
        case 5:
            system("cls");
            PrintBoughtTicket();
            break;
        case 6:
            system("cls");
            return;  // Wyjœcie z programu
        default:
            system("cls");
            std::cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
            break;
        }
    }
}

void Menu::ShowMenu() {
    std::cout << "---- MENU ----\n";
    std::cout << "1. Dodaj polaczenie\n";
    std::cout << "2. Zarezerwuj bilet\n";
    std::cout << "3. Usun rezerwacje\n";
    std::cout << "4. Wydrukuj zajetosc polaczen\n";
    std::cout << "5. Wydrukuj zakupione bilety\n";
    std::cout << "6. Wyjscie\n";
    std::cout << "Wybierz opcje: ";
    std::cout << "\n\n";
}

void Menu::AddConnection() {
    // Logika dodawania nowego po³¹czenia
    std::cout << "Dodawanie polaczenia...\n";

    std::getline(std::cin, DUMMY);
}

void Menu::TicketReservation() {
    // Logika rezerwacji biletu
   

    std::cout << "---- Rezerwacja biletu ----\n";
    std::cout << "Wyjscie\n";
    std::cout << "Wybierz opcje: \n";
    std::getline(std::cin, DUMMY);
}

void Menu::DeleteReservation() {
    // Logika usuwania rezerwacji
    std::cout << "Usuwanie rezerwacji...\n";
    std::getline(std::cin, DUMMY);
}

void Menu::PrintConnections() {
    // Logika wydruku zajêtoœci po³¹czeñ
    std::cout << "Wydrukuj zajetosc polaczen...\n";
    std::getline(std::cin, DUMMY);
}

void Menu::PrintBoughtTicket() {
    // Logika wydruku zakupionych biletów
    std::cout << "Wydrukuj zakupione bilety...\n";
    std::getline(std::cin, DUMMY);

}

