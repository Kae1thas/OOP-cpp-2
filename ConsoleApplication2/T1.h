#ifndef T1_H
#define T1_H

#include "BaseClass.h"

class T1 : public BaseClass {
public:
    T1(const std::string& id, const std::string& value);

    void ShowBin() const override;
    void ShowOct() const override;
    void ShowHex() const override;
    void ShowValue() const override;

private:
    std::string value;
};

#endif // T1_H