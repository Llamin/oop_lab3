#ifndef ORDER_H
#define ORDER_H

#include "Gpu.h"
#include "Cpu.h"
#include "HardDrive.h"
#include "Ram.h"

#include "Date.h"

#include "items.h"

class Order
{
    Date d{0, 0, 0};
    int totalPrice = 0, phoneNumber, idOrder;
    std::vector<Gpu> gpus;
    std::vector<Cpu> cpus;
    std::vector<HardDrive> hardDrives;
    std::vector<Ram> rams;

public:
    Order();
    Order(const Order& o);
    int add_item(Items storage);
    int delete_item();
    void show_all();
    void setTotalPrice (int totalPrice);
    int getTotalPrice ();
    void setDateOfOrder ();

};

#endif // ORDER_H
