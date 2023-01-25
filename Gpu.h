#ifndef GPU_H
#define GPU_H

#include "Components.h"



class Gpu : public Components
{
    int gpu_size;
public:
    Gpu();
    Gpu(int idComponent, std::string model, std::string brand, Date d, int price, int gpu_size);
    Gpu(const Gpu& c);
    void setSize(int gpu_size);
    int getSize();
    Gpu operator+(int priceChange);
    Gpu operator-(int priceChange);
    friend std::ostream & operator << (std::ostream &out, Gpu &gpu_temp);
    friend std::istream & operator >> (std::istream &in, Gpu &gpu_temp);
    bool operator < (const Gpu& temp);
    bool operator > (const Gpu& temp);
    bool operator == (const Gpu& temp);
    bool operator != (const Gpu& temp);
    void operator = (const Gpu& temp);

};

#endif // GPU_H
