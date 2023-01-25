#ifndef ORDERS_H
#define ORDERS_H

#include "Order.h"

#include "TableData.h"

class Orders : public TableData
{

    std::vector<Order> orderList;
public:
    void addOrder(Order temp);
    void showOrders();
    Order & operator[] (int index);
};


#endif // ORDERS_H
