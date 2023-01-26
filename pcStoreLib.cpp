#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>

#include "pcStoreLib.h"

#include "Gpu.h"
#include "Cpu.h"
#include "HardDrive.h"
#include "Ram.h"

#include "Order.h"

#include "Items.h"
#include "Orders.h"


int numInput()
{
    std::string input;
    int check;
    do
    {
        check = 1;
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        for (int i = 0; i < (int) input.length(); i++)
            if (isdigit(input[i]) == false)
            {
                check = 0;
                std::cout << "Your input is incorrect. You should enter only integer numbers (equal to 0 and more).\nTry again:" << std::endl;
                break;
            }

    }
    while(check == 0);

    return stoi(input);
}

