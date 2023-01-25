#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>

#include "pcStoreLib.h"

#include "Date.h"

#include "Cpu.h"

extern int ID_ITEMS;

Cpu::Cpu()
    {
        idComponent = ++ID_ITEMS;

        std::cout << "Input name of brand: ";
        std::cin >> brand;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Input name of model: ";
        std::cin >> model;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Input frequency: ";
        frequency = numInput();
        std::cout << "Input price: ";
        price = numInput();

        d.setCurrentDate();
        std::cout
        << "\nID of item: " << idComponent << std::endl;
        d.showDate();
        std::cout
        << "A processor " + brand + " " + model + " " << frequency << " MHz of frequency\n"
        << "of a price: " << price << " USD\nwas added to the store"
        << std::endl;
    }

Cpu::Cpu(int idComponent, std::string model, std::string brand, Date d, int price, int frequency)
{
    this->idComponent = idComponent;
    this->model = model;
    this->brand = brand;
    this->d = d;
    this->price = price;
    this->frequency = frequency;
}

Cpu::Cpu(const Cpu& c)
{
    model = c.model;
    brand = c.brand;
    price = c.price;
    d = c.d;
    idComponent = c.idComponent;
    frequency = c.frequency;
}

int Cpu::getFrequency()
    {
        return frequency;
    }

void Cpu::setFrequency(int frequency)
    {
        this->frequency = frequency;
    }

Cpu Cpu::operator+(int priceChange)
{
    int result = this->price + priceChange;
    if (result <= 0)
    {
        std::cout << "You can't make price of items less than 1!" << std::endl;
        result = this->price;
    }
    Cpu comp(this->idComponent, this->model, this->brand, this->d, result, this->frequency);

    return comp;
}

Cpu Cpu::operator-(int priceChange)
{
    int result = this->price - priceChange;
    if (result <= 0)
    {
        std::cout << "You can't make price of items less than 1!" << std::endl;
        result = this->price;
    }
    Cpu comp(this->idComponent, this->model, this->brand, this->d, result, this->frequency);

    return comp;
}

std::ostream & operator << (std::ostream &out, Cpu &cpu_temp)
{
    out << "ID of item: " << cpu_temp.idComponent << std::endl;
    cpu_temp.d.showDate();
    out << "A CPU " + cpu_temp.brand + " " + cpu_temp.model + " " << cpu_temp.frequency << " MHz of frequency\n" << "of a price: " << cpu_temp.price << " USD" << std::endl;

    return out;
}

std::istream & operator >> (std::istream &in,  Cpu &cpu_temp)
{
    std::cout << "Input name of brand: ";
    in >> cpu_temp.brand;
    std::cin.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Input name of model: ";
    in >> cpu_temp.model;
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Input frequency: ";
    cpu_temp.frequency = numInput();
    std::cout << "Input price: ";
    cpu_temp.price = numInput();

    cpu_temp.d.setCurrentDate();

    std::cout
        << "ID of item: " << cpu_temp.idComponent << std::endl
        << "A processor " + cpu_temp.brand + " " + cpu_temp.model + " " << cpu_temp.frequency << " MHz of frequency\n"
        << "of a price: " << cpu_temp.price << " USD\nwas edited."
        << std::endl;

    return in;
}

bool Cpu::operator < (const Cpu& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    return this->price < temp.price;
}

bool Cpu::operator > (const Cpu& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    return this->price > temp.price;
}

bool Cpu::operator == (const Cpu& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    bool result = false;
    if(this->model == temp.model)
        if(this->brand == temp.brand)
            if(this->d == temp.d)
                if (this->price == temp.price)
                    if(this->frequency == temp.frequency)
                        result = true;

    return result;
}

bool Cpu::operator != (const Cpu& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    return this->model != temp.model || this->brand != temp.brand || this->d != temp.d || this->price != temp.price || this->frequency != temp.frequency;

}

void Cpu::operator = (const Cpu& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    this->idComponent = temp.idComponent;
    this->model = temp.model;
    this->brand = temp.brand;
    this->d = temp.d;
    this->price = temp.price;
    this->frequency = temp.frequency;
}
