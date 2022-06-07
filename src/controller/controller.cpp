#include "controller.hpp"
#include <exception>
#include <iostream>
#include <random>

#define MAX 11

Controller::Controller(){}
Controller::~Controller(){}

void Controller::test()
{
    TestDriver t;

    t.runAllTests();


}

int Controller::generate_random_value()
{
    std::random_device dev;
    std::mt19937 rng(dev());

    // distribution in interval [0, 100]
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 100);

    return dist(rng);

}
