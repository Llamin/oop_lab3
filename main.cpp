#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>
#include <fstream>

#include "Gpu.h"
#include "Cpu.h"
#include "HardDrive.h"
#include "Ram.h"

#include "Order.h"

#include "Items.h"
#include "Orders.h"

#include "pcStoreLib.h"

int ID_ORDERS = 0;
int ID_ITEMS = 0;

std::string itemsFileName = "Items.txt";
std::string ordersFileName = "Orders.txt";


int main()
{
    int opt;
    Orders ord;
    Items all;

    std::fstream itemsFileStream;
    std::fstream ordersFileStream;

    itemsFileStream.open(itemsFileName);
    ordersFileStream.open(ordersFileName);

    std::cout << "Welcome!" << std::endl;
    do
    {

        std::cout << "\t\t\nMenu\n"
                  << "1. Add item to the storage\n"
                  << "2. Remove item from the storage\n"
                  << "3. View all items\n"
                  << "4. Place an order\n"
                  << "5. View all orders\n"
                  << "6. Increase day on all items in storage\n"
                  << "7. Decrease day on all items in storage\n"
                  << "8. Increase price on all items in storage by set value\n"
                  << "9. Decrease price on all items in storage by set value\n"
                  << "10. Output order by choice\n"
                  << "11. Edit last item from storage\n"
                  << "12. Compare prices of first and last item from storage\n"
                  << "13. Compare first and last item from storage\n"
                  << "14. Copy first item to last item from storage\n"
                  << "0. Exit\n"
                  << "Your option: ";

        opt = numInput();

        switch(opt)
        {
        case 1:
            {
                all.view_all();
                all.add_item();

            }
        break;

        case 2:
            {
                all.view_all();
                all.delete_item();
            }
        break;

        case 3:
            {
                all.view_all();
            }
        break;


        case 4:
            {
                int option, check, status = 0;
                Order temp;
                do
                {
                    do
                    {
                        temp.show_all();

                        check = 1;
                        std::cout << "\nChoose your action\n"
                                  << "1 - Add item\n"
                                  << "2 - Remove item\n"
                                  << "3 - View all items\n"
                                  << "0 - Exit\n"
                                  << "Choose your option: ";

                        option = numInput();

                        if (option < 0 || option > 3)
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
                        status += temp.add_item(all);

                        break;
                    }
                    case 2:
                    {
                        status -= temp.delete_item();
                        break;
                    }
                    case 3:
                    {
                        temp.show_all();
                        break;
                    }
                    case 0:
                    {
                        if(status)
                        {
                            temp.setDateOfOrder();
                            ord.addOrder(temp);
                        }
                        break;
                    }
                    default:
                        std::cout << "Unknown option.\n" << std::endl;
                        break;
                    }
                }
                while(option);

            }
        break;

        case 5:
            {
                ord.showOrders();
            }
        break;

        case 6:
            {
                all.increaseDateAll();
            }
        break;

        case 7:
            {
                all.decreaseDateAll();
            }
        break;

        case 8:
            {
                all.increasePriceAll();
            }
        break;

        case 9:
            {
                all.decreasePriceAll();
            }
        break;

        case 10:
            {
                std::cout << "Input ID of order you want to see: ";
                int index = numInput() - 1;
                ord[index].show_all();
            }
        break;

        case 11:
            {
                int option, check;
                do
                {

                    do
                    {
                        check = 1;
                        std::cout << "\nChoose category\n"
                                  << "1 - GPU\n"
                                  << "2 - CPU\n"
                                  << "3 - Hard Drive\n"
                                  << "4 - RAM\n"
                                  << "0 - Exit\n"
                                  << "Choose your option: ";

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
                        std::cin >> all.getLastGPU();
                        break;
                    }
                    case 2:
                    {
                        std::cin >> all.getLastCPU();
                        break;
                    }
                    case 3:
                    {
                        std::cin >> all.getLastHardDrive();
                        break;
                    }
                    case 4:
                    {
                        std::cin >> all.getLastRAM();
                        break;
                    }
                    case 0:
                    {
                        break;
                    }
                    default:
                        std::cout << "Unknown option.\n" << std::endl;
                        break;
                    }
                }
                while(option);
            }
        break;

        case 12:
            {
                int option, check;
                do
                {

                    do
                    {
                        check = 1;
                        std::cout << "\nChoose category\n"
                                  << "1 - GPU\n"
                                  << "2 - CPU\n"
                                  << "3 - Hard Drive\n"
                                  << "4 - RAM\n"
                                  << "0 - Exit\n"
                                  << "Choose your option: ";

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
                        if(all.getFirstGPU() > all.getLastGPU())
                        {
                            std::cout << "The price of first GPU (" << all.getFirstGPU().getPrice() << " USD) is bigger than the price of the last one (" << all.getLastGPU().getPrice() << " USD)." << std::endl;
                        }
                        else if(all.getFirstGPU() < all.getLastGPU())
                        {
                            std::cout << "The price of first GPU (" << all.getFirstGPU().getPrice() << " USD) is lesser than the price of the last one (" << all.getLastGPU().getPrice() << " USD)." << std::endl;
                        }
                        else
                        {
                            std::cout << "The price of first GPU (" << all.getFirstGPU().getPrice() << " USD) is equal to the price of the last one (" << all.getLastGPU().getPrice() << " USD)." << std::endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        if(all.getFirstCPU() > all.getLastCPU())
                        {
                            std::cout << "The price of first CPU (" << all.getFirstCPU().getPrice() << " USD) is bigger than the price of the last one (" + all.getLastCPU().getPrice() << " USD)." << std::endl;
                        }
                        else if(all.getFirstCPU() < all.getLastCPU())
                        {
                            std::cout << "The price of first CPU (" << all.getFirstCPU().getPrice() << " USD) is lesser than the price of the last one (" + all.getLastCPU().getPrice() << " USD)." << std::endl;
                        }
                        else
                        {
                            std::cout << "The price of first CPU (" << all.getFirstCPU().getPrice() << " USD) is equal to the price of the last one (" + all.getLastCPU().getPrice() << " USD)." << std::endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        if(all.getFirstHardDrive() > all.getLastHardDrive())
                        {
                            std::cout << "The price of first Hard Drive (" << all.getFirstHardDrive().getPrice() << " USD) is bigger than the price of the last one (" << all.getLastHardDrive().getPrice() << " USD)." << std::endl;
                        }
                        else if(all.getFirstHardDrive() < all.getLastHardDrive())
                        {
                            std::cout << "The price of first Hard Drive (" << all.getFirstHardDrive().getPrice() << " USD) is lesser than the price of the last one (" << all.getLastHardDrive().getPrice() << " USD)." << std::endl;
                        }
                        else
                        {
                            std::cout << "The price of first Hard Drive (" << all.getFirstHardDrive().getPrice() << " USD) is equal to the price of the last one (" << all.getLastHardDrive().getPrice() << " USD)." << std::endl;
                        }
                        break;
                    }
                    case 4:
                    {
                        if(all.getFirstRAM() > all.getLastRAM())
                        {
                            std::cout << "The price of first RAM (" << all.getFirstRAM().getPrice() << " USD) is bigger than the price of the last one (" << all.getLastRAM().getPrice() << " USD)." << std::endl;
                        }
                        else if(all.getFirstRAM() < all.getLastRAM())
                        {
                            std::cout << "The price of first RAM (" << all.getFirstRAM().getPrice() << " USD) is lesser than the price of the last one (" << all.getLastRAM().getPrice() << " USD)." << std::endl;
                        }
                        else
                        {
                            std::cout << "The price of first RAM (" << all.getFirstRAM().getPrice() << " USD) is equal to the price of the last one (" << all.getLastRAM().getPrice() << " USD)." << std::endl;
                        }
                        break;
                    }
                    case 0:
                    {
                        break;
                    }
                    default:
                        std::cout << "Unknown option.\n" << std::endl;
                        break;
                    }
                }
                while(option);
            }
        break;

        case 13:
            {
                int option, check;
                do
                {

                    do
                    {
                        check = 1;
                        std::cout << "\nChoose category\n"
                                  << "1 - GPU\n"
                                  << "2 - CPU\n"
                                  << "3 - Hard Drive\n"
                                  << "4 - RAM\n"
                                  << "0 - Exit\n"
                                  << "Choose your option: ";

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
                        if(all.getFirstGPU() == all.getLastGPU())
                        {
                            std::cout << "The first GPU and last GPU are equal." << std::endl;
                        }
                        else if(all.getFirstGPU() != all.getLastGPU())
                        {
                            std::cout << "The first GPU and last GPU are NOT equal." << std::endl;
                        }
                        else
                        {
                            std::cout << "You are not supposed to see it." << std::endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        if(all.getFirstCPU() == all.getLastCPU())
                        {
                            std::cout << "The first CPU and last CPU are equal." << std::endl;
                        }
                        else if(all.getFirstGPU() != all.getLastGPU())
                        {
                            std::cout << "The first CPU and last CPU are NOT equal." << std::endl;
                        }
                        else
                        {
                            std::cout << "You are not supposed to see it." << std::endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        if(all.getFirstHardDrive() == all.getLastHardDrive())
                        {
                            std::cout << "The first Hard Drive and last Hard Drive are equal." << std::endl;
                        }
                        else if(all.getFirstGPU() != all.getLastGPU())
                        {
                            std::cout << "The first Hard Drive and last Hard Drive are NOT equal." << std::endl;
                        }
                        else
                        {
                            std::cout << "You are not supposed to see it." << std::endl;
                        }
                        break;
                    }
                    case 4:
                    {
                        if(all.getFirstRAM() == all.getLastRAM())
                        {
                            std::cout << "The first RAM and last RAM are equal." << std::endl;
                        }
                        else if(all.getFirstGPU() != all.getLastGPU())
                        {
                            std::cout << "The first RAM and last RAM are NOT equal." << std::endl;
                        }
                        else
                        {
                            std::cout << "You are not supposed to see it." << std::endl;
                        }
                        break;
                    }
                    case 0:
                    {
                        break;
                    }
                    default:
                        std::cout << "Unknown option.\n" << std::endl;
                        break;
                    }
                }
                while(option);
            }
        break;

        case 14:
            {
                int option, check;
                do
                {

                    do
                    {
                        check = 1;
                        std::cout << "\nChoose category\n"
                                  << "1 - GPU\n"
                                  << "2 - CPU\n"
                                  << "3 - Hard Drive\n"
                                  << "4 - RAM\n"
                                  << "0 - Exit\n"
                                  << "Choose your option: ";

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
                        all.getLastGPU() = all.getFirstGPU();
                        break;
                    }
                    case 2:
                    {
                        all.getLastCPU() = all.getFirstCPU();
                        break;
                    }
                    case 3:
                    {
                        all.getLastHardDrive() = all.getFirstHardDrive();
                        break;
                    }
                    case 4:
                    {
                        all.getLastRAM() = all.getFirstRAM();
                        break;
                    }
                    case 0:
                    {
                        break;
                    }
                    default:
                        std::cout << "Unknown option.\n" << std::endl;
                        break;
                    }
                }
                while(option);
            }
        break;



        case 0:

        break;

        default:
            std::cout << "Unknown option. Please, try again." << std::endl;
        break;

        }
    }
    while(opt);

    itemsFileStream.close();
    ordersFileStream.close();

    return 0;
}

