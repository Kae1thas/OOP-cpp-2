/* #include <iostream>
#include <bitset>
#include <cassert>
#include <sstream>
//абстрактный класс
class BaseClass {
public:

        BaseClass(const std::string& id) : id(id) {}

        void ShowId() const {
            std::cout << "ID: " << id << std::endl;
        }
        //чисто виртуальная функция
        //абстрактные методы
        virtual void ShowBin() const = 0;
        virtual void ShowOct() const = 0;
        virtual void ShowHex() const = 0;
        virtual void ShowValue() const = 0;
        
        protected:
        std::string id;
 };
   


class T1 : public BaseClass {
public:

    T1(const std::string& id, const std::string& value) : BaseClass(id), value(value) {}

    void ShowBin() const override {
        std::cout << "Двоичная строка: " << "Не реализовано" << std::endl;
    }

    void ShowOct() const override {
        std::cout << "Восьмеричная строка: " << "Не реализовано" << std::endl;
    }

    void ShowHex() const override {
        std::cout << "Шестнадцатеричная строка: " << "Не реализовано" << std::endl;
    }

    void ShowValue() const override {
        std::cout << "Значение: " << value << std::endl;
    }
    
    private:
    std::string value;
};

class T2 : public BaseClass {
    public:
    T2(const std::string& id, int value) : BaseClass(id), value(value) {}

    void ShowBin() const override {
        std::cout << "Двоичная строка: " << std::bitset<32>(value) << std::endl;
    }

    void ShowOct() const override {
        std::cout << "Восьмеричная строка: " << std::oct << value << std::endl;
    }

    void ShowHex() const override {
        std::cout << "Шестнадцатеричная строка: " << std::hex << value << std::endl;
    }

    void ShowValue() const override {
        std::cout << "Значение: " << value << std::endl;
    }
        
    private:
    int value;
};

class Factory {
public:
    static BaseClass* CreateT1(const std::string& id, const std::string& value) {
        return new T1(id, value);
    }

    static BaseClass* CreateT2(const std::string& id, int value) {
        return new T2(id, value);
    }

    static void DeleteObject(BaseClass* obj) {
        delete obj;
    }
};

void testT1() {
    // Создаем объект T1
    BaseClass* obj = Factory::CreateT1("ID_T1", "Value_T1");

    // Захватываем стандартный вывод
    std::stringstream output;
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    // Вызываем методы для вывода
    obj->ShowId();
    obj->ShowValue();
    obj->ShowBin();
    obj->ShowOct();
    obj->ShowHex();

    // Сравниваем полученный вывод с ожидаемым результатом
    assert(output.str() == "ID: ID_T1\nЗначение: Value_T1\nДвоичная строка: Не реализовано\nВосьмеричная строка: Не реализовано\nШестнадцатеричная строка: Не реализовано\n");

    // Освобождаем ресурсы
    std::cout.rdbuf(coutBuffer);
    Factory::DeleteObject(obj);
}


void testT2() {
    // Создаем объект T2
    BaseClass* obj = Factory::CreateT2("ID_T2", 42);

    // Захватываем стандартный вывод
    std::stringstream output;
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    // Вызываем методы для вывода
    obj->ShowId();
    obj->ShowValue();
    obj->ShowBin();
    obj->ShowOct();
    obj->ShowHex();

    // Сравниваем полученный вывод с ожидаемым результатом
    assert(output.str() == "ID: ID_T2\nЗначение: 42\nДвоичная строка: 00000000000000000000000000101010\nВосьмеричная строка: 52\nШестнадцатеричная строка: 2a\n");

    // Освобождаем ресурсы
    std::cout.rdbuf(coutBuffer);
    Factory::DeleteObject(obj);
}



int main() {
    setlocale(LC_ALL, "Russian");
    // Вызываем тесты
    testT1();
    testT2();

    std::cout << "Все тесты пройдены успешно!" << std::endl;


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
            std::cout << "Введите Значение для T2: ";
            std::cin >> value;
            obj = Factory::CreateT2(id, value);
            break;
        }
        case 0:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неизвестная команда." << std::endl;
        }

        // Проверяем, что obj не равен nullptr, перед выполнением операций
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
*/