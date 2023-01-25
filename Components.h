#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "Date.h"

class Components
{
protected:
    int idComponent;
    std::string model;
    std::string brand;
    Date d{0, 0, 0};
    int price;
public:
    std::string getBrand();
    void setBrand(std::string brand);
    std::string getModel();
    void setModel(std::string model);
    int getPrice();
    void setPrice(int price);
    int getID();
    void setID(int idCompontent);
    void increaseDay();
    void decreaseDay();
    Components operator+(int priceChange);
    Components operator-(int priceChange);
    virtual bool operator < (const Components& temp);
    virtual bool operator > (const Components& temp);
    virtual bool operator == (const Components& temp);
    virtual bool operator != (const Components& temp);
    virtual void operator = (const Components& temp);

};

#endif // COMPONENTS_H
