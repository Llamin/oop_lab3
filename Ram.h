#ifndef RAM_H
#define RAM_H

#include "Components.h"

class Ram : public Components
{
    int ram_size;
    int frequency;
public:
    Ram();
    Ram(int idComponent, std::string model, std::string brand, Date d, int price, int ram_size, int frequency);
    Ram(const Ram& c);
    void setFrequency(int frequency);
    int getFrequency();
    void setSize(int ram_size);
    int getSize();
    Ram operator+(int priceChange);
    Ram operator-(int priceChange);

    friend std::ostream & operator << (std::ostream &out, Ram &ram_temp);
    friend std::istream & operator >> (std::istream &in, Ram &ram_temp);

    bool operator < (const Ram& temp);
    bool operator > (const Ram& temp);

    bool operator == (const Ram& temp);
    bool operator != (const Ram& temp);

    void operator = (const Ram& temp);


};

#endif // RAM_H
