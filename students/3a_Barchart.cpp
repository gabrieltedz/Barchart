#include "3b_Barchart.h"
#include "4b_Bar.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void Barchart::b_chart_read(){
    string read_x_times; // Auxiliar string used to read the first number indicating how many bars the current barchart has
    getline(cin, read_x_times);
    int amount_of_bars = stoi(read_x_times); // amount of times a bar will be read

    for (int i = 0; i < amount_of_bars; i++){
        bars[i].read_line();
    }
    
}