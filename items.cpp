#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>
#include <fstream>
#include <iterator>

#include "pcStoreLib.h"

#include "Items.h"

Items::Items()
{

}

Items::Items(const Items& i)
{
    gpus = i.gpus;
    cpus = i.cpus;
    hardDrives = i.hardDrives;
    rams = i.rams;
}

void Items::add_item()
    {
        int option, check;
        do
        {
            check = 1;
            std::cout << "\nITEM ADDITION\n"
                      << "1 - GPU\n"
                      << "2 - CPU\n"
                      << "3 - Hard Drive\n"
                      << "4 - RAM\n"
                      << "0 - Exit\n"
                      << "Choose what kind of item you want to add: ";

            option = numInput();

            if (option < 0 || option > 4)
            {
                std::cout << "Unknown option. Try again: ";
                option = numInput();
                check = 0;
            }
        }
        while(!check);

            switch(option)
            {

            case 1:
                {
                    Gpu temp;
                    gpus.push_back(temp);
                }
            break;

            case 2:
                {
                    Cpu temp;
                    cpus.push_back(temp);
                }
            break;

            case 3:
                {
                    HardDrive temp;
                    hardDrives.push_back(temp);
                }
            break;

            case 4:
                {
                    Ram temp;
                    rams.push_back(temp);
                }
            break;

            case 0:
            break;

            default:
                std::cout << "Unspecified option." << std::endl;
            break;

            }

    }

int Items::search_item(int idItem)
{
    int status = 0;
        if (!gpus.empty())
            for (int i = 0; i < (int) gpus.size(); i++)
            {
                if(gpus[i].getID() == idItem)
                {
                    status = 1;
                    break;
                }
            }
        if(!status && !cpus.empty())
        {
            for (int i = 0; i < (int) cpus.size(); i++)
            {
                if(cpus[i].getID() == idItem)
                {
                    status = 1;
                    break;
                }
            }
        }

        if(!status && !hardDrives.empty())
        {
            for (int i = 0; i < (int) hardDrives.size(); i++)
            {
                if(hardDrives[i].getID() == idItem)
                {
                    status = 1;
                    break;
                }
            }
        }

        if(!status && !rams.empty())
        {
            for (int i = 0; i < (int) rams.size(); i++)
            {
                if(rams[i].getID() == idItem)
                {
                    status = 1;
                    break;
                }
            }
        }

    return status;
}

void Items::delete_item()
    {
        int removalID, status = 0;
        std::cout << "\nInput ID of item you want to remove: ";
        removalID = numInput();

        if (!gpus.empty())
        {
            for (int i = 0; i < (int) gpus.size(); i++)
            {
                if(gpus[i].getID() == removalID)
                {
                    gpus.erase(gpus.begin() + i);
                    status = 1;
                    break;
                }
            }
        }
        if(!status && !cpus.empty())
        {
            for (int i = 0; i < (int) cpus.size(); i++)
            {
                if(cpus[i].getID() == removalID)
                {
                    cpus.erase(cpus.begin() + i);
                    status = 1;
                    break;
                }
            }
        }

        if(!status && !hardDrives.empty())
        {
            for (int i = 0; i < (int) hardDrives.size(); i++)
            {
                if(hardDrives[i].getID() == removalID)
                {
                    hardDrives.erase(hardDrives.begin() + i);
                    status = 1;
                    break;
                }
            }
        }

        if(!status && !rams.empty())
        {
            for (int i = 0; i < (int) rams.size(); i++)
            {
                if(rams[i].getID() == removalID)
                {
                    rams.erase(rams.begin() + i);
                    status = 1;
                    break;
                }
            }
        }
        if(!status)
        {
            std::cout << "Item by this ID wasn't found." << std::endl;
        }
    }

void Items::view_all()
    {
        std::cout << "\t\nAll items available\nGPU" << std::endl;
        if (!gpus.empty())
            for (int i = 0; i < (int) gpus.size(); i++)
            {
                std::cout << gpus[i];
                std::cout << std::endl;
            }
        else
            std::cout << "The list is empty" << std::endl;

        std::cout << "\nCPU" << std::endl;
        if (!cpus.empty())
            for (int i = 0; i < (int) cpus.size(); i++)
            {
                std::cout << cpus[i];
                std::cout << std::endl;
            }
        else
            std::cout << "The list is empty" << std::endl;

        std::cout << "\nHard Drives" << std::endl;
        if (!hardDrives.empty())
            for (int i = 0; i < (int) hardDrives.size(); i++)
            {
                std::cout << hardDrives[i];
                std::cout << std::endl;
            }
        else
            std::cout << "The list is empty" << std::endl;

        std::cout << "\nRAM" << std::endl;
        if (!rams.empty())
            for (int i = 0; i < (int) rams.size(); i++)
            {
                std::cout << rams[i];
                std::cout << std::endl;
            }
        else
            std::cout << "The list is empty" << std::endl;
    }

Gpu Items::getSpecificGPU(int idNum)
    {
        for (int i = 0; i < (int) gpus.size(); i++)
            {
                if(gpus[i].getID() == idNum)
                {
                    return gpus[i];
                }
            }
        Gpu gp;
        return gp;
    }

Cpu Items::getSpecificCPU(int idNum)
    {
        for (int i = 0; i < (int) cpus.size(); i++)
            {
                if(cpus[i].getID() == idNum)
                {
                    return cpus[i];
                }
            }
        Cpu cp;
        return cp;
    }

HardDrive Items::getSpecificHardDrive(int idNum)
    {
        for (int i = 0; i < (int) hardDrives.size(); i++)
            {
                if(hardDrives[i].getID() == idNum)
                {
                    return hardDrives[i];
                }
            }
        HardDrive hd;
        return hd;
    }

Ram Items::getSpecificRAM(int idNum)
    {
        for (int i = 0; i < (int) rams.size(); i++)
            {
                if(rams[i].getID() == idNum)
                {
                    return rams[i];
                }
            }
        Ram ra;
        return ra;
    }

void Items::increaseDateAll()
{
        if (!gpus.empty())
            for (int i = 0; i < (int) gpus.size(); i++)
            {
                gpus[i].increaseDay();
            }
        else
            std::cout << "List of GPUs is empty!" << std::endl;


        if (!cpus.empty())
            for (int i = 0; i < (int) cpus.size(); i++)
            {
                cpus[i].increaseDay();
            }
        else
            std::cout << "List of CPUs is empty!" << std::endl;

        if (!hardDrives.empty())
            for (int i = 0; i < (int) hardDrives.size(); i++)
            {
                hardDrives[i].increaseDay();
            }
        else
            std::cout << "List of Hard Drives is empty!" << std::endl;

        if (!rams.empty())
            for (int i = 0; i < (int) rams.size(); i++)
            {
                rams[i].increaseDay();
            }
        else
            std::cout << "List of RAMs is empty!" << std::endl;
}

void Items::decreaseDateAll()
{
        if (!gpus.empty())
            for (int i = 0; i < (int) gpus.size(); i++)
            {
                gpus[i].decreaseDay();
            }
        else
            std::cout << "List of GPUs is empty!" << std::endl;

        if (!cpus.empty())
            for (int i = 0; i < (int) cpus.size(); i++)
            {
                cpus[i].decreaseDay();
            }
        else
            std::cout << "List of CPUs is empty!" << std::endl;


        if (!hardDrives.empty())
            for (int i = 0; i < (int) hardDrives.size(); i++)
            {
                hardDrives[i].decreaseDay();
            }
        else
            std::cout << "List of Hard Drives is empty!" << std::endl;


        if (!rams.empty())
            for (int i = 0; i < (int) rams.size(); i++)
            {
                rams[i].decreaseDay();
            }
        else
            std::cout << "List of RAMs is empty!" << std::endl;

}

void Items::increasePriceAll()
{
    std::cout << "Input the value you want to increase price of all items with: ";
    int priceChange = numInput();
        if (!gpus.empty())
            for (int i = 0; i < (int) gpus.size(); i++)
            {
                gpus[i] = gpus[i] + priceChange;
            }
        else
            std::cout << "List of GPUs is empty!" << std::endl;


        if (!cpus.empty())
            for (int i = 0; i < (int) cpus.size(); i++)
            {
                cpus[i] = cpus[i] + priceChange;
            }
        else
            std::cout << "List of CPUs is empty!" << std::endl;

        if (!hardDrives.empty())
            for (int i = 0; i < (int) hardDrives.size(); i++)
            {
                hardDrives[i] = hardDrives[i] + priceChange;
            }
        else
            std::cout << "List of Hard Drives is empty!" << std::endl;

        if (!rams.empty())
            for (int i = 0; i < (int) rams.size(); i++)
            {
                rams[i] = rams[i] + priceChange;
            }
        else
            std::cout << "List of RAMs is empty!" << std::endl;
}

void Items::decreasePriceAll()
{
    std::cout << "Input the value you want to increase price of all items with: ";
    int priceChange = numInput();
        if (!gpus.empty())
            for (int i = 0; i < (int) gpus.size(); i++)
            {
                gpus[i] = gpus[i] - priceChange;
            }
        else
            std::cout << "List of GPUs is empty!" << std::endl;


        if (!cpus.empty())
            for (int i = 0; i < (int) cpus.size(); i++)
            {
                cpus[i] = cpus[i] - priceChange;
            }
        else
            std::cout << "List of CPUs is empty!" << std::endl;

        if (!hardDrives.empty())
            for (int i = 0; i < (int) hardDrives.size(); i++)
            {
                hardDrives[i] = hardDrives[i] - priceChange;
            }
        else
            std::cout << "List of Hard Drives is empty!" << std::endl;

        if (!rams.empty())
            for (int i = 0; i < (int) rams.size(); i++)
            {
                rams[i] = rams[i] - priceChange;
            }
        else
            std::cout << "List of RAMs is empty!" << std::endl;
}

Gpu& Items::getLastGPU()
{
    return gpus.back();
}

Cpu& Items::getLastCPU()
{
    return cpus.back();
}

HardDrive& Items::getLastHardDrive()
{
    return hardDrives.back();

}
Ram& Items::getLastRAM()
{
    return rams.back();
}

Gpu& Items::getFirstGPU()
{
    return gpus.front();
}

Cpu& Items::getFirstCPU()
{
    return cpus.front();
}

HardDrive& Items::getFirstHardDrive()
{
    return hardDrives.front();

}
Ram& Items::getFirstRAM()
{
    return rams.front();
}

int Items::getVectorSizeGPU()
{
    return gpus.size();
}

int Items::getVectorSizeCPU()
{
    return cpus.size();
}

int Items::getVectorSizeHardDrive()
{
    return hardDrives.size();
}

int Items::getVectorSizeRAM()
{
    return rams.size();
}
