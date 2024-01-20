#include "Tests.h"
#include "Factory.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>

bool testT1() {

    BaseClass* obj = Factory::CreateT1("1", "oleg");

    std::stringstream output;
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    obj->ShowId();
    obj->ShowValue();
    obj->ShowBin();
    obj->ShowOct();
    obj->ShowHex();

    assert(output.str() == "ID: 1\nЗначение: oleg\nДвоичная строка: Не реализовано\nВосьмеричная строка: Не реализовано\nШестнадцатеричная строка: Не реализовано\n");

    std::cout.rdbuf(coutBuffer);
    Factory::DeleteObject(obj);
    return true;
}

bool testT2() {
    BaseClass* obj = Factory::CreateT2("2", 42);
    std::stringstream output;
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    obj->ShowId();
    obj->ShowValue();
    obj->ShowBin();
    obj->ShowOct();
    obj->ShowHex();

    assert(output.str() == "ID: 2\nЗначение(в десятичной системе): 42\nДвоичная строка: 00000000000000000000000000101010\nВосьмеричная строка: 52\nШестнадцатеричная строка: 2a\n"); //для демонстрации теста сделать ошибку здесь 

    std::cout.rdbuf(coutBuffer);
    Factory::DeleteObject(obj);
    return true;
}