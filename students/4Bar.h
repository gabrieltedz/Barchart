#ifndef BAR_H
#define BARCHART_H
#include <string>

struct BarItem {
    
    int time_stamp;
    std::string label;
    std::string dummy;
    int value;
    std::string category;

};

class Bar
{
private:
BarItem items;

public:

/**
 * ATTENTION!! Start making program by here!!!!!!!!!!
*/

// reads a SINGLE line (this function is called once for each line that contains objects from bars) (its called x times on barchart.read())
//this also makes the "tokens"
    void read_line(); 
};

#endif