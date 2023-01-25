#ifndef HARDDRIVE_H
#define HARDDRIVE_H

#include "Components.h"

class HardDrive : public Components
{
    int hd_size;
public:
    HardDrive();
    HardDrive(int idComponent, std::string model, std::string brand, Date d, int price, int hd_size);
    HardDrive(const HardDrive& c);
    int getSize();
    void setSize(int hd_size);
    HardDrive operator+(int priceChange);
    HardDrive operator-(int priceChange);
    friend std::ostream & operator << (std::ostream &out, HardDrive &hd_temp);
    friend std::istream & operator >> (std::istream &in, HardDrive &hd_temp);
    bool operator < (const HardDrive& temp);
    bool operator > (const HardDrive& temp);
    bool operator == (const HardDrive& temp);
    bool operator != (const HardDrive& temp);
    void operator = (const HardDrive& temp);

};

#endif // HARDDRIVE_H
