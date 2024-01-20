#include "Factory.h"
#include "T1.h"
#include "T2.h"

BaseClass* Factory::CreateT1(const std::string& id, const std::string& value) {
    return new T1(id, value);
}

BaseClass* Factory::CreateT2(const std::string& id, int value) {
    return new T2(id, value);
}

void Factory::DeleteObject(BaseClass* obj) {
    delete obj;
}