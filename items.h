#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <iostream>

#include "Gpu.h"
#include "Cpu.h"
#include "HardDrive.h"
#include "Ram.h"

#include "TableData.h"

class Items : public TableData
{
    std::vector<Gpu> gpus;
    std::vector<Cpu> cpus;
    std::vector<HardDrive> hardDrives;
    std::vector<Ram> rams;
public:
    Items();
    Items(const Items& i);
    void add_item();
    int search_item(int idItem);
    void delete_item();
    void view_all();
    Gpu getSpecificGPU(int i);
    Cpu getSpecificCPU(int i);
    HardDrive getSpecificHardDrive(int i);
    Ram getSpecificRAM(int i);
    void increaseDateAll();
    void decreaseDateAll();
    void increasePriceAll();
    void decreasePriceAll();
    Gpu& getLastGPU();
    Cpu& getLastCPU();
    HardDrive& getLastHardDrive();
    Ram& getLastRAM();
    Gpu& getFirstGPU();
    Cpu& getFirstCPU();
    HardDrive& getFirstHardDrive();
    Ram& getFirstRAM();


};

#endif // ITEMS_H
