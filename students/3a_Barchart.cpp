#include "3b_Barchart.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

bool Barchart::compareByValueDescending(const BarItem& a, const BarItem& b) {
    return a.value > b.value;
}

void Barchart::sort_bars(){
    sort(bars.begin(), bars.end(), compareByValueDescending);
}

/**
 * Function that calls the reading to form a single barchart
*/
void Barchart::b_chart_read(int times){
    Bar bar;
    for (int i = 0; i < times; i++){
        bar.read_line();
        bars.push_back(bar);
    }
    sort_bars();
}