#include "T2.h"
#include <bitset>
// Реализация конструктора класса T2
T2::T2(const std::string& id, int value) : BaseClass(id), value(value) {}

// Реализация методов класса T2

void T2::ShowBin() const {
    std::cout << "Двоичная строка: " << std::bitset<32>(value) << std::endl;
}

void T2::ShowOct() const {
    std::cout << "Восьмеричная строка: " << std::oct << value << std::endl;
}

void T2::ShowHex() const {
    std::cout << "Шестнадцатеричная строка: " << std::hex << value << std::endl;
}
void T2::ShowValue() const {
    std::cout << "Значение(в десятичной системе): " << std::dec << value << std::endl;
}
