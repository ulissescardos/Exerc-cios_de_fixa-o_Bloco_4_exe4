#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../TestDriver/TestDriver.hpp"
#include "../TestDriver/Region.hpp"

#include <iostream>

class Controller{
    public:
        Controller();
        ~Controller();

        void test();

    private:
        int generate_random_value();

};



#endif // CONTROLLER_H
