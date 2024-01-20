#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>

class BaseClass {
public:
    BaseClass(const std::string& id) : id(id) {}

    void ShowId() const {
        std::cout << "ID: " << id << std::endl;
    }

    virtual void ShowBin() const = 0;
    virtual void ShowOct() const = 0;
    virtual void ShowHex() const = 0;
    virtual void ShowValue() const = 0;

protected:
    std::string id;
};

#endif