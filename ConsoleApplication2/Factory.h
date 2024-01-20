#ifndef FACTORY_H
#define FACTORY_H

#include "BaseClass.h"

class Factory {
public:
    static BaseClass* CreateT1(const std::string& id, const std::string& value);
    static BaseClass* CreateT2(const std::string& id, int value);
    static void DeleteObject(BaseClass* obj);
};

#endif