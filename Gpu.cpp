#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>

#include "pcStoreLib.h"

#include "Date.h"

#include "Gpu.h"

extern int ID_ITEMS;

Gpu::Gpu()
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
        gpu_size = numInput();
        std::cout << "Input price: ";
        price = numInput();

        d.setCurrentDate();
        std::cout
        << "\nID of item: " << idComponent << std::endl;
        d.showDate();
        std::cout
        << "A GPU " + brand + " " + model + " " << gpu_size << " GB of memory size\n"
        << "of a price: " << price << " USD\nwas added to the store"
        << std::endl;
    }

Gpu::Gpu(int idComponent, std::string model, std::string brand, Date d, int price, int gpu_size)
{
    this->idComponent = idComponent;
    this->model = model;
    this->brand = brand;
    this->d = d;
    this->price = price;
    this->gpu_size = gpu_size;
}

Gpu::Gpu(const Gpu& c)
{
    model = c.model;
    brand = c.brand;
    price = c.price;
    d = c.d;
    idComponent = c.idComponent;
    gpu_size = c.gpu_size;
}

void Gpu::setSize(int gpu_size)
    {
        this->gpu_size = gpu_size;
    }

int Gpu::getSize()
    {
        return gpu_size;
    }

Gpu Gpu::operator+(int priceChange)
{
    int result = this->price + priceChange;
    if (result <= 0)
    {
        std::cout << "You can't make price of items less than 1!" << std::endl;
        result = this->price;
    }
    Gpu comp(this->idComponent, this->model, this->brand, this->d, result, this->gpu_size);

    return comp;
}

Gpu Gpu::operator-(int priceChange)
{
    int result = this->price - priceChange;
    if (result <= 0)
    {
        std::cout << "You can't make price of items less than 1!" << std::endl;
        result = this->price;
    }
    Gpu comp(this->idComponent, this->model, this->brand, this->d, result, this->gpu_size);

    return comp;
}

std::ostream & operator << (std::ostream &out, Gpu &gpu_temp)
{
        out
        << "ID of item: " << gpu_temp.idComponent << std::endl;
        gpu_temp.d.showDate();
        out
        << "A GPU " + gpu_temp.brand + " " + gpu_temp.model + " " << gpu_temp.gpu_size << " GB of memory size\n"
        << "of a price: " << gpu_temp.price << " USD"
        << std::endl;

    return out;
}

std::istream & operator >> (std::istream &in,  Gpu &gpu_temp)
{
    std::cout << "Input name of brand: ";
    in >> gpu_temp.brand;
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Input name of model: ";
    in >> gpu_temp.model;
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Input size: ";
    gpu_temp.gpu_size = numInput();
    std::cout << "Input price: ";
    gpu_temp.price = numInput();

    gpu_temp.d.setCurrentDate();


    std::cout
        << "\nID of item: " << gpu_temp.idComponent << std::endl
        << "A GPU " + gpu_temp.brand + " " + gpu_temp.model + " " << gpu_temp.gpu_size << " GB of memory size\n"
        << "of a price: " << gpu_temp.price << " USD\nwas edited."
        << std::endl;

    return in;
}

bool Gpu::operator < (const Gpu& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    return this->price < temp.price;
}

bool Gpu::operator > (const Gpu& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    return this->price > temp.price;
}

bool Gpu::operator == (const Gpu& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    bool result = false;
    if(this->model == temp.model)
        if(this->brand == temp.brand)
            if(this->d == temp.d)
                if (this->price == temp.price)
                    if(this->gpu_size == temp.gpu_size)
                        result = true;

    return result;
}

bool Gpu::operator != (const Gpu& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    return this->model != temp.model || this->brand != temp.brand || this->d != temp.d || this->price != temp.price || this->gpu_size != temp.gpu_size;

}

void Gpu::operator = (const Gpu& temp)
{
    std::cout << "Use of virtual function in derived class." << std::endl;
    this->idComponent = temp.idComponent;
    this->model = temp.model;
    this->brand = temp.brand;
    this->d = temp.d;
    this->price = temp.price;
    this->gpu_size = temp.gpu_size;
}
