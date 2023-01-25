#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>

#include "pcStoreLib.h"

#include "Orders.h"

extern std::string ordersFileName;

void Orders::addOrder(Order temp)
    {
        orderList.push_back(temp);
        temp.setDateOfOrder();
    }

void Orders::showOrders()
    {
        if(!orderList.empty())
            for (int i = 0; i < (int) orderList.size(); i++)
            {
                orderList[i].show_all();
            }
        else
            std::cout << "List is empty\n" << std::endl;
    }

Order& Orders::operator[] (int index)
{
    return orderList[index];
}
