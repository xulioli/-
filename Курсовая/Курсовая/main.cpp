
#include <iostream>
#include <fstream>
#include <locale>
#include "Function.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
     
    
    int choseOfAdmin = 0;
    int choseOfMarks;
    int ChoseAdminOrUser;
    int choseOfUser;
    int i = 0;

    std::cout << "Добрый день!" << std::endl;
    do {
        std::cout << "главное меню:" << endl;
        std::cout << "1) войти как пользователь" << std::endl;
        std::cout << "2) войти как администратор" << std::endl;
        std::cout << "3) выход" << std::endl;
        std::cin >> ChoseAdminOrUser;

        switch (ChoseAdminOrUser) {
        case 1:
            std::cout << "Вы желаете войти или выйти?" << std::endl;
            do {
                std::cout << "1) войти\n2)выйти в главное меню" << std::endl;
                std::cin >> choseOfUser;
                switch (choseOfUser) {
                case 1:
                    while (i!=3) {
                        if (VerifyUserCredentials()) {
                            break;

                        }
                        else {
                            break;
                        }
                    }                                                            
                    break;
                case 2:
                    return 0;
                }
            } while (choseOfUser != 2);
            break;
        case 2:
            std::cout << "Введите пароль для администратора!" << std::endl;
            DataEntryAdmin(); // Добавить повтор при неверном вводе
            
                std::cout << "Выберите один из вариантов!" << std::endl;
                std::cout << "1) посмотреть список клиентов" << std::endl;
                std::cout << "2) посмотреть список тренеров" << std::endl;
                std::cout << "3) ввести информацию о тренерах" << endl;
                std::cin >> choseOfAdmin;
                switch (choseOfAdmin) {
                case 1:
                    PrintUsers();
                    break;
                case 2:
                    PrintTrainers();
                    // Добавьте обработку списка тренеров
                    break;    
                case 3:
                    DataTrainers();
                    break;
                case 4:
                    AdminAndUsers();
                    break;
                }
            break;
        case 3:
            return 0;
            break;
        }
    } while (ChoseAdminOrUser != 3);

    return 0;
}
