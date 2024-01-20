#include <iostream>
#include "Tests.h"
#include "Factory.h"

int main() {
    setlocale(LC_ALL, "Russian");
    
    if (testT1() && testT2()) {
        std::cout << "Юнит-тесты пройдены успешно!" << std::endl;
    }
    else {
        std::cerr << "Юнит-тесты не пройдены!" << std::endl;
    }

    BaseClass* obj = nullptr;
    int choice;

    do {
        std::cout << "\n1. Создать и выполнить операции для T1" << std::endl;
        std::cout << "2. Создать и выполнить операции для T2" << std::endl;
        std::cout << "0. Выход \n" << std::endl;

        std::cout << "Введите команду: \n";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string id, value;
            std::cout << "Введите ID для T1: ";
            std::cin >> id;
            std::cout << "Введите Значение для T1: ";
            std::cin >> value;
            obj = Factory::CreateT1(id, value);
            break;
        }
        case 2: {
            std::string id;
            int value;
            std::cout << "Введите ID для T2: ";
            std::cin >> id;
            while (true) {
                std::cout << "Введите Значение для T2: ";
                if (std::cin >> value) {
                    break;
                }
                else {
                    std::cerr << "Ошибка ввода! Введите целочисленное значение." << std::endl;
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            obj = Factory::CreateT2(id, value);
            break;
        }
        case 0:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неизвестная команда." << std::endl;
        }

        if (obj != nullptr) {
            obj->ShowId();
            obj->ShowValue();
            obj->ShowBin();
            obj->ShowOct();
            obj->ShowHex();
            Factory::DeleteObject(obj);
            obj = nullptr;
        }

    } while (choice != 0);

    return 0;
}