#ifndef BAR_H
#define BARCHART_H
#include <string>
#include "5b_Tokenizer.h"
using namespace std;

struct BarItem {
    
    string time_stamp;
    string label;
    string dummy;
    int value;
    string category;

};

class Bar
{
private:
BarItem items;

public:

/**
 * ATTENTION!! Start making program by here!!!!!!!!!!
*/

/**
 * @brief Reads a SINGLE line 
 * 
 * (this function is called once for each line that contains objects from bars) 
 * (its called x times on barchart.read())
 */ 
    void read_line(); 
};

#endif