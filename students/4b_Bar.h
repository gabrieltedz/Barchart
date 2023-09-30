#ifndef _4B_BAR_H
#define _4B_BAR_H
#include <string>
#include "5b_Tokenizer.h"
using namespace std;

/**
 * All types of information from each single line in the datafile.
*/
struct BarItem {
    
    string time_stamp; 
    string label;
    string dummy;
    float value;
    string category;

};

/**
 * @brief contains the information of a single bar.
*/
class Bar
{
private:
/**
 * @brief Each Bar object only contains the information from one line, as such,
 * It only has a BarItem object named items
*/
BarItem items;

public:

/**
 * @brief Reads a SINGLE line 
 * 
 * (this function is called once for each line that contains objects from bars) 
 * (its called x times on barchart.read())
 */ 
void read_line(std::istream& stream); 

float value();
string label();
string category();
string time_stamp();

void show_line();


};

#endif