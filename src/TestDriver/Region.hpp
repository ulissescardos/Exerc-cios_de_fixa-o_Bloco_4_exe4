/*
 * Region.hpp
 */

#include <iostream>
using namespace std;

#ifndef REGION_HPP_
#define REGION_HPP_

class Region
{
private:
    double area;
public:
    Region(void);
    Region(int area);
    virtual ~Region();
    
    virtual double getArea() const;
    virtual void setArea(double area);
    
    bool operator==(Region &region) const;
    bool operator!=(Region &region) const;
    bool operator>(Region &region) const;
    bool operator>=(Region &region) const;
    bool operator<(Region &region) const;
    bool operator<=(Region &region) const;
    
    friend ostream& operator<<(std::ostream &os, Region &region);
    friend istream& operator>>(std::istream &is, Region &region);
    
    friend Region operator+(Region&, Region&);
    friend Region operator-(Region&, Region&);
};

ostream& operator<<(std::ostream &, Region &);

istream& operator>>(std::istream &, Region &);


#endif
/* REGION_HPP_ */