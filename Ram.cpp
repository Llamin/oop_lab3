#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>

#include "pcStoreLib.h"

#include "Date.h"

#include "Ram.h"

extern int ID_ITEMS;

Ram::Ram()
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
        std::cout << "Input size: ";
        ram_size = numInput();
        std::cout << "Input price: ";
        price = numInput();

        d.setCurrentDate();
        std::cout
        << "\nID of item: " << idComponent << std::endl;
        d.showDate();
        std::cout
        << "A RAM " + brand + " " + model + " " << frequency << " MHz of frequency and " << ram_size << " GB of memory size\n"
        << "of a price: " << price << " USD\nwas added to the store"
        << std::endl;
    }

Ram::Ram(int idComponent, std::string model, std::string brand, Date d, int price, int ram_size, int frequency)
{
    this->idComponent = idComponent;
    this->model = model;
    this->brand = brand;
    this->d = d;
    this->price = price;
    this->ram_size = ram_size;
    this->frequency = frequency;
}

Ram::Ram(const Ram& c)
{
    model = c.model;
    brand = c.brand;
    price = c.price;
    d = c.d;
    idComponent = c.idComponent;
    ram_size = c.ram_size;
    frequency = c.frequency;
}

void Ram::setFrequency(int frequency)
    {
        this->frequency = frequency;
    }

int Ram::getFrequency()
    {
        return frequency;
    }

void Ram::setSize(int ram_size)
    {
        this->ram_size = ram_size;
    }

int Ram::getSize()
    {
        return ram_size;
    }

Ram Ram::operator+(int priceChange)
{
    int result = this->price + priceChange;
    if (result <= 0)
    {
        std::cout << "You can't make price of items less than 1!" << std::endl;
        result = this->price;
    }
    Ram comp(this->idComponent, this->model, this->brand, this->d, result, this->ram_size, this->frequency);

    return comp;
}

Ram Ram::operator-(int priceChange)
{
    int result = this->price - priceChange;
    if (result <= 0)
    {
        std::cout << "You can't make price of items less than 1!" << std::endl;
        result = this->price;
    }
    Ram comp(this->idComponent, this->model, this->brand, this->d, result, this->ram_size, this->frequency);

    return comp;
}

std::ostream & operator << (std::ostream &out, Ram &ram_temp)
{
        out
        << "ID of item: " << ram_temp.idComponent << std::endl;
        ram_temp.d.showDate();
        out
        << "A RAM " + ram_temp.brand + " " + ram_temp.model + " " << ram_temp.frequency << " MHz of frequency and " << ram_temp.ram_size << " GB of memory size\n"
        << "of a price: " << ram_temp.price << " USD"
        << std::endl;

    return out;
}

std::istream & operator >> (std::istream &in, Ram &ram_temp)
{
    std::cout << "Input name of brand: ";
    in >> ram_temp.brand;
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Input name of model: ";
    in >> ram_temp.model;
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Input frequency: ";
    ram_temp.frequency = numInput();
    std::cout << "Input size: ";
    ram_temp.ram_size = numInput();
    std::cout << "Input price: ";
    ram_temp.price = numInput();

    ram_temp.d.setCurrentDate();

    std::cout
        << "\nID of item: " << ram_temp.idComponent << std::endl
        << "A RAM " + ram_temp.brand + " " + ram_temp.model + " " << ram_temp.frequency << " MHz of frequency and " << ram_temp.ram_size << " GB of memory size\n"
        << "of a price: " << ram_temp.price << " USD\nwas edited."
        << std::endl;

    return in;
}

bool Ram::operator < (const Ram& temp)
{
    return this->price < temp.price;
}

bool Ram::operator > (const Ram& temp)
{
    return this->price > temp.price;
}

bool Ram::operator == (const Ram& temp)
{
    bool result = false;
    if(this->model == temp.model)
        if(this->brand == temp.brand)
            if(this->d == temp.d)
                if (this->price == temp.price)
                    if(this->ram_size == temp.ram_size)
                        if(this->frequency == temp.frequency)
                            result = true;

    return result;
}

bool Ram::operator != (const Ram& temp)
{
    return this->model != temp.model || this->brand != temp.brand || this->d != temp.d || this->price != temp.price || this->ram_size != temp.ram_size || this->frequency != temp.frequency;

}

void Ram::operator = (const Ram& temp)
{
    this->idComponent = temp.idComponent;
    this->model = temp.model;
    this->brand = temp.brand;
    this->d = temp.d;
    this->price = temp.price;
    this->ram_size = temp.ram_size;
    this->frequency = temp.frequency;
}
