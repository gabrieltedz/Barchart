#include "3b_Barchart.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/**
 * Function that calls the reading to form a single barchart
*/
void Barchart::b_chart_read(int times){
    Bar bar;
    for (int i = 0; i < times; i++){
        bar.read_line();
        bars.push_back(bar);
    }
}