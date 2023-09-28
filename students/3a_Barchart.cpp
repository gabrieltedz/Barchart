#include "3b_Barchart.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


void Barchart::sort_bars() {
    int n = bars.size();
    // Bubble sort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            // Compare the value field of adjacent Bar objects
            if (bars[j].value() < bars[j + 1].value()) {
                // Swap the Bar objects if they are out of order
                Bar temp = bars[j];
                bars[j] = bars[j + 1];
                bars[j + 1] = temp;
            }
        }
    }


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
    for (int i = 0; i < bars.size(); i++){
        bars[i].show_line();
    } 
}

void Barchart::reset(){
    bars.clear();
}