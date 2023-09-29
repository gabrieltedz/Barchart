#ifndef _3B_BARCHART_H
#define _3B_BARCHART_H
#include "4b_Bar.h"
using namespace std;


/**
 * Class that contains an instance of animation from the Barchart
 * Contains only a vector of bars sorted.
*/
class Barchart
{
private:
    /**
     * Vector of bars.
    */
    vector<Bar> bars;
public:
    vector<string> n_categories;
    /**
     * Sorts bars from biggest to smallest from top-down
    */
    void sort_bars(size_t start, size_t end); 
    
    /**
     * Function that calls the reading to form a single barchart
    */
    void b_chart_read(int times, std::istream& stream); 

    void reset();

    void check_categories();
};

#endif