#ifndef _3B_BARCHART_H
#define _3B_BARCHART_H
#include "4b_Bar.h"
using namespace std;

class Barchart
{
private:
    vector<Bar> bars;
public:
    int amount_of_bars;
    void sort_bars(); //sorts bars from biggest to smallest from top-down
    
    void b_chart_read(); // remember to pick the timestamp for all
};

#endif