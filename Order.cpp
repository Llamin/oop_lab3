#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>
#include <fstream>

#include "pcStoreLib.h"

#include "Date.h"

#include "Order.h"

extern int ID_ORDERS;

Order::Order()
    {
        d.setCurrentDate();
        idOrder = ++ID_ORDERS;
        std::cout << "\nEnter your phone number: ";
        phoneNumber = numInput();
    }

Order::Order(const Order& o)
{
    totalPrice = o.totalPrice;
    phoneNumber = o.phoneNumber;
    idOrder = o.idOrder;
    gpus = o.gpus;
    cpus = o.cpus;
    hardDrives = o.hardDrives;
    rams = o.rams;
    d = o.d;
}

int Order::add_item(Items storage)
    {
        storage.view_all();
        int option, check, status, askedID;

        do
        {
            check = 1;
            std::cout << "\nChoose kind of item you want to order\n"
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
                    std::cout << "\nEnter ID of an item you want to order: ";
                    status = 0, askedID = numInput();

                        if(storage.search_item(askedID))
                        {
                            gpus.push_back(storage.getSpecificGPU(askedID));
                            totalPrice += storage.getSpecificGPU(askedID).getPrice();
                            status = 1;
                            break;

                        }
                        if (!status)
                        {
                            std::cout << "There is no such item with this ID." << std::endl;
                        }
                }
            break;

            case 2:
                {
                    std::cout << "\nEnter ID of an item you want to order: ";
                    status = 0, askedID = numInput();

                        if(storage.search_item(askedID))
                        {
                            cpus.push_back(storage.getSpecificCPU(askedID));
                            totalPrice += storage.getSpecificCPU(askedID).getPrice();
                            status = 1;
                            break;
                        }
                        if (!status)
                        {
                            std::cout << "There is no such item with this ID." << std::endl;
                        }

                }
            break;

            case 3:
                {
                    std::cout << "\nEnter ID of an item you want to order: ";
                    status = 0, askedID = numInput();

                        if(storage.search_item(askedID))
                        {
                            hardDrives.push_back(storage.getSpecificHardDrive(askedID));
                            totalPrice += storage.getSpecificHardDrive(askedID).getPrice();
                            status = 1;
                            break;
                        }
                        if (!status)
                        {
                            std::cout << "There is no such item with this ID." << std::endl;
                        }

                }
            break;

            case 4:
                {
                    std::cout << "\nEnter ID of an item you want to order: ";
                    status = 0, askedID = numInput();

                        if(storage.search_item(askedID))
                        {
                            rams.push_back(storage.getSpecificRAM(askedID));
                            totalPrice += storage.getSpecificRAM(askedID).getPrice();
                            status = 1;
                            break;
                        }
                        if (!status)
                        {
                            std::cout << "There is no such item with this ID." << std::endl;
                        }

                }
            break;
            case 0:
                break;
            default:
                break;
        }

        return status;
    }

int Order::delete_item()
    {
        int removalID, status = 0;
        std::cout << "\nInput ID of item you want to remove: ";
        removalID = numInput();

            if(!gpus.empty())
            {
                for (int i = 0; i < (int) gpus.size(); i++)
                {
                    if(gpus[i].getID() == removalID)
                    {
                        totalPrice -= gpus[i].getPrice();
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
                        totalPrice -= cpus[i].getPrice();
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
                        totalPrice -= hardDrives[i].getPrice();
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
                        totalPrice -= rams[i].getPrice();
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

        return status;
    }

void Order::show_all()
    {
        std::cout << "\nID of order: " << idOrder << std::endl;
                  d.showDate();
        std::cout << "Your phone number: " << phoneNumber
                  << "\n\nShopping cart\nGPU" << std::endl;

        if(!gpus.empty())
            for (int i = 0; i < (int) gpus.size(); i++)
            {
                std::cout << gpus[i];
                std::cout << std::endl;
            }
        else
            std::cout << "List is empty\n" << std::endl;

        std::cout << "\nCPU" << std::endl;
        if(!cpus.empty())
            for (int i = 0; i < (int) cpus.size(); i++)
            {
                std::cout << cpus[i];
                std::cout << std::endl;
            }
        else
            std::cout << "List is empty\n" << std::endl;

        std::cout << "\nHard Drives" << std::endl;
        if(!hardDrives.empty())
            for (int i = 0; i < (int) hardDrives.size(); i++)
            {
                std::cout << hardDrives[i];
                std::cout << std::endl;
            }
        else
            std::cout << "List is empty\n" << std::endl;

        std::cout << "\nRAM" << std::endl;
        if(!rams.empty())
            for (int i = 0; i < (int) rams.size(); i++)
            {
                std::cout << rams[i];
                std::cout << std::endl;
            }
        else
            std::cout << "List is empty\n" << std::endl;

                std::cout << "\nYour total price: " << totalPrice << " USD" << std::endl;
    }

void Order::setTotalPrice (int totalPrice)
    {
        this->totalPrice = totalPrice;
    }

int Order::getTotalPrice ()
    {
        return totalPrice;
    }

void Order::setDateOfOrder()
{
    d.setCurrentDate();
}
