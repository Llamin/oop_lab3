#ifndef CPU_H
#define CPU_H

#include <iostream>

#include "Components.h"


class Cpu : public Components
{
protected:
    int frequency;
public:
    Cpu();
    Cpu(int idComponent, std::string model, std::string brand, Date d, int price, int frequency);
    Cpu(const Cpu& c);
    int getFrequency();
    void setFrequency(int frequency);
    Cpu operator+(int priceChange);
    Cpu operator-(int priceChange);
    friend std::ostream & operator << (std::ostream &out, Cpu &cpu_temp);
    friend std::istream & operator >> (std::istream &in, Cpu &cpu_temp);
    bool operator < (const Cpu& temp);
    bool operator > (const Cpu& temp);
    bool operator == (const Cpu& temp);
    bool operator != (const Cpu& temp);
    void operator = (const Cpu& temp);
};

#endif // CPU_H
