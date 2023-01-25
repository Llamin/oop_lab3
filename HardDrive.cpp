#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>

#include "pcStoreLib.h"

#include "Date.h"

#include "HardDrive.h"

extern int ID_ITEMS;

HardDrive::HardDrive()
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
        std::cout << "Input size: ";
        hd_size = numInput();
        std::cout << "Input price: ";
        price = numInput();

        d.setCurrentDate();
        std::cout
        << "\nID of item: " << idComponent << std::endl;
        d.showDate();
        std::cout
        << "A Hard Drive " + brand + " " << hd_size << " GB of memory size\n"
        << "of a price: " << price << " USD\nwas added to the store"
        << std::endl;
    }

HardDrive::HardDrive(int idComponent, std::string model, std::string brand, Date d, int price, int hd_size)
{
    this->idComponent = idComponent;
    this->model = model;
    this->brand = brand;
    this->d = d;
    this->price = price;
    this->hd_size = hd_size;
}

HardDrive::HardDrive(const HardDrive& c)
{
    model = c.model;
    brand = c.brand;
    price = c.price;
    d = c.d;
    idComponent = c.idComponent;
    hd_size = c.hd_size;
}

int HardDrive::getSize()
    {
        return hd_size;
    }

void HardDrive::setSize(int hd_size)
    {
        this->hd_size = hd_size;
    }

HardDrive HardDrive::operator+(int priceChange)
{
    int result = this->price + priceChange;
    if (result <= 0)
    {
        std::cout << "You can't make price of items less than 1!" << std::endl;
        result = this->price;
    }
    HardDrive comp(this->idComponent, this->model, this->brand, this->d, result, this->hd_size);

    return comp;
}

HardDrive HardDrive::operator-(int priceChange)
{
    int result = this->price - priceChange;
    if (result <= 0)
    {
        std::cout << "You can't make price of items less than 1!" << std::endl;
        result = this->price;
    }
    HardDrive comp(this->idComponent, this->model, this->brand, this->d, result, this->hd_size);

    return comp;
}

std::ostream & operator << (std::ostream &out, HardDrive &hd_temp)
{
        out
        << "ID of item: " << hd_temp.idComponent << std::endl;
        hd_temp.d.showDate();
        out
        << "A Hard Drive " + hd_temp.brand + " " + hd_temp.model + " " << hd_temp.hd_size << " GB of memory size\n"
        << "of a price: " << hd_temp.price << " USD"
        << std::endl;

    return out;
}

std::istream & operator >> (std::istream &in,  HardDrive &hd_temp)
{
    std::cout << "Input name of brand: ";
    in >> hd_temp.brand;
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Input name of model: ";
    in >> hd_temp.model;
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Input size: ";
    hd_temp.hd_size = numInput();
    std::cout << "Input price: ";
    hd_temp.price = numInput();

    hd_temp.d.setCurrentDate();

        std::cout
        << "\nID of item: " << hd_temp.idComponent << std::endl
        << "A Hard Drive " + hd_temp.brand + " " << hd_temp.hd_size << " GB of memory size\n"
        << "of a price: " << hd_temp.price << " USD\nwas edited."
        << std::endl;

    return in;
}

bool HardDrive::operator < (const HardDrive& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    return this->price < temp.price;
}

bool HardDrive::operator > (const HardDrive& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    return this->price > temp.price;
}

bool HardDrive::operator == (const HardDrive& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    bool result = false;
    if(this->model == temp.model)
        if(this->brand == temp.brand)
            if (this->price == temp.price)
                if(this->hd_size == temp.hd_size)
                    result = true;

    return result;
}

bool HardDrive::operator != (const HardDrive& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    return this->model != temp.model || this->brand != temp.brand || this->price != temp.price || this->hd_size != temp.hd_size;

}

void HardDrive::operator = (const HardDrive& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    this->idComponent = temp.idComponent;
    this->model = temp.model;
    this->brand = temp.brand;
    this->d = temp.d;
    this->price = temp.price;
    this->hd_size = temp.hd_size;
}
