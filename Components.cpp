#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>

#include "Components.h"

extern int ID_ITEMS;

std::string Components::getBrand()
    {
        return brand;
    }

void Components::setBrand(std::string brand)
    {
        this->brand = brand;
    }

std::string Components::getModel()
    {
        return model;
    }

void Components::setModel(std::string model)
    {
        this->model = model;
    }

int Components::getPrice()
    {
        return price;
    }

void Components::setPrice(int price)
    {
        this->price = price;
    }

int Components::getID()
    {
        return idComponent;
    }

void Components::setID(int idCompontent)
    {
        this->idComponent = idCompontent;
    }


void Components::increaseDay()
{
    ++d;
}

void Components::decreaseDay()
{
    d--;
}

Components Components::operator+(int priceChange)
{
    Components comp;
    comp.brand = this->brand;
    comp.model = this->model;
    comp.d = this->d;
    comp.price = price + priceChange;
    return comp;
}

Components Components::operator-(int priceChange)
{
    Components comp;
    comp.brand = this->brand;
    comp.model = this->model;
    comp.d = this->d;
    if (priceChange >= price)
    {
        std::cout << "You can't make price of items less than 1!" << std::endl;
        comp.price = this->price;
    }
    else
        comp.price = price - priceChange;

    return comp;
}

bool Components::operator < (const Components& temp)
{
    std::cout << "Use of virtual function in base class." << std::endl;
    return this->price < temp.price;
}

bool Components::operator > (const Components& temp)
{
    std::cout << "Use of virtual function in base class." << std::endl;
    return this->price > temp.price;
}

bool Components::operator == (const Components& temp)
{
    std::cout << "Use of virtual function in base class." << std::endl;
    bool result = false;
    if(this->model == temp.model)
        if(this->brand == temp.brand)
            if(this->d == temp.d)
                if (this->price == temp.price)
                    result = true;

    return result;
}

bool Components::operator != (const Components& temp)
{
    std::cout << "Use of virtual function in base class." << std::endl;
    return this->model != temp.model || this->brand != temp.brand || this->d != temp.d || this->price != temp.price;

}

void Components::operator = (const Components& temp)
{
    std::cout << "Use of virtual function in base class." << std::endl;
    this->idComponent = temp.idComponent;
    this->model = temp.model;
    this->brand = temp.brand;
    this->d = temp.d;
    this->price = temp.price;
}

