#ifndef BARCHART_H
#define BARCHART_H
#include "4Bar.h"

class Barchart
{
private:
    std::vector<Bar> bars;
    
public:
    
    void sort_bars(); //sorts bars from biggest to smallest from top-down
    
    void b_chart_read(); // remember to pick the timestamp for all
};

#endif