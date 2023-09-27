#ifndef _3B_BARCHART_H
#define _3B_BARCHART_H
#include "4b_Bar.h"
using namespace std;

class Barchart
{
private:
    vector<Bar> bars;
public:
    void sort_bars(); //sorts bars from biggest to smallest from top-down
    
    void b_chart_read(int times); // remember to pick the timestamp for all
};

#endif