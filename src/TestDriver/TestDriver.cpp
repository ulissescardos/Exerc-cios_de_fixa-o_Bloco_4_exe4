#include "TestDriver.hpp"
#include <exception>

TestDriver::TestDriver()
{
    sPointerRegion1.reset(new Region(200));
    sPointerRegion2.reset(new Region(100));
}

string TestDriver::boolToString(bool expr) const
{
    return (expr ? "true" : "false");
}

void TestDriver::showCurrentStatus(void) const
{
    cout << "Current Status" << endl;
    cout << "Region 1: " << *sPointerRegion1 << endl;
    cout << "Region 2: " << *sPointerRegion2 << endl;
    cout << endl;
}

void TestDriver::equalityTest(void) const
{
    cout << "equality test: " << boolToString(*sPointerRegion1 == *sPointerRegion2);
}

void TestDriver::inequalityTest(void) const
{
    cout << "inequality test: " <<boolToString(*sPointerRegion1 != *sPointerRegion2) << endl;
}

void TestDriver::relationsTest(void) const
{
    cout << "< test" << boolToString(*sPointerRegion1 < *sPointerRegion2) << endl;
    cout << "> test" << boolToString(*sPointerRegion1 > *sPointerRegion2) << endl;
    cout << "<= test" << boolToString(*sPointerRegion1 <= *sPointerRegion2) << endl;
    cout << ">= test" << boolToString(*sPointerRegion1 >= *sPointerRegion2) << endl;
}

void TestDriver::additionTest(void) const
{
    Region result(*sPointerRegion1 + *sPointerRegion2);

    cout << "addition test" << *sPointerRegion1 << " + " << *sPointerRegion2 << " = " << result << endl;
}

void TestDriver::subtractionTest(void) const
{
    Region result(*sPointerRegion1 - *sPointerRegion2);

    cout << "addition test" << *sPointerRegion1 << " - " << *sPointerRegion2 << " = " << result << endl;

}
void TestDriver::exceptionTest(void) const
{
    sPointerRegion2->setArea(400);

    try{
        Region result(*sPointerRegion1 - *sPointerRegion2);
        cout << "addition test" << *sPointerRegion1 << " - " << *sPointerRegion2 << " = " << result << endl;
    }
    catch(exception &e){
        cerr << e.what() << endl;
    }
}

void TestDriver::runAllTests()
{
    showCurrentStatus();
    equalityTest();
    inequalityTest();
    relationsTest();
    additionTest();
    showCurrentStatus();
    subtractionTest();
    showCurrentStatus();
    exceptionTest();
    showCurrentStatus();
}