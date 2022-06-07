#include "Region.hpp"
#include <stdexcept>

Region::Region(void){}

Region::Region(int area)
{
    this->area = area;
}

Region::~Region(){}

bool Region::operator==(Region &region) const 
{
    return (this->area == region.area);
}

bool Region::operator!=(Region &region) const
{
    return (this->area != region.area);
}

bool Region::operator<(Region &region) const 
{
    return (this->area < region.area);
}

bool Region::operator>(Region &region) const 
{
    return (this->area > region.area);
}

bool Region::operator>=(Region &region) const
{
    return (this->area >= region.area);
}

ostream& operator<<(std::ostream &os, Region &region)
{
    os << region.area;

    return os;
}

istream& operator>>(std::istream &is, Region &region)
{
    is >> region.area;

    return is;
}

Region operator+(Region &r1, Region &r2)
{
    Region result(r1.area + r2.area);
    return result;
}

Region operator-(Region &r1, Region &r2)
{
    Region result(r1.area - r2.area);

    if(result.area < 0){
        throw range_error("out_of_range");
    }
    else{
        return result;
    }

}

