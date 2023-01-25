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
    int getVectorOrderListSize();
};


#endif // ORDERS_H
