#ifndef T2_H
#define T2_H

#include "BaseClass.h"

class T2 : public BaseClass {
public:
    T2(const std::string& id, int value);

    void ShowBin() const override;
    void ShowOct() const override;
    void ShowHex() const override;
    void ShowValue() const override;

private:
    int value;
};

#endif // T2_H