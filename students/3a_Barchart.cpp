#include "3b_Barchart.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void Barchart::b_chart_read(int times){
    Bar bar;
    for (int i = 0; i < times; i++){
        bar.read_line();
        bars.push_back(bar);
    }
    
}