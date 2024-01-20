#include "T1.h"

// Реализация конструктора класса T1
T1::T1(const std::string& id, const std::string& value) : BaseClass(id), value(value) {}

// Реализация методов класса T1
void T1::ShowBin() const {
    std::cout << "Двоичная строка: Не реализовано" << std::endl;
}

void T1::ShowOct() const {
    std::cout << "Восьмеричная строка: Не реализовано" << std::endl;
}

void T1::ShowHex() const {
    std::cout << "Шестнадцатеричная строка: Не реализовано" << std::endl;
}

void T1::ShowValue() const {
    std::cout << "Значение: " << value << std::endl;
}
