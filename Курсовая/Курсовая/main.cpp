
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

    std::cout << "������ ����!" << std::endl;
    do {
        std::cout << "������� ����:" << endl;
        std::cout << "1) ����� ��� ������������" << std::endl;
        std::cout << "2) ����� ��� �������������" << std::endl;
        std::cout << "3) �����" << std::endl;
        std::cin >> ChoseAdminOrUser;

        switch (ChoseAdminOrUser) {
        case 1:
            std::cout << "�� ������� ����� ��� �����?" << std::endl;
            do {
                std::cout << "1) �����\n2)����� � ������� ����" << std::endl;
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
            std::cout << "������� ������ ��� ��������������!" << std::endl;
            DataEntryAdmin(); // �������� ������ ��� �������� �����
            
                std::cout << "�������� ���� �� ���������!" << std::endl;
                std::cout << "1) ���������� ������ ��������" << std::endl;
                std::cout << "2) ���������� ������ ��������" << std::endl;
                std::cout << "3) ������ ���������� � ��������" << endl;
                std::cin >> choseOfAdmin;
                switch (choseOfAdmin) {
                case 1:
                    PrintUsers();
                    break;
                case 2:
                    PrintTrainers();
                    // �������� ��������� ������ ��������
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
