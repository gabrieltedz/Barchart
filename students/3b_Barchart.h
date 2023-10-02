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
    /**
     * current timestamp of the barchart
    */
    string timestamp;

    /**
     * Number of categories this barchart has
    */
    vector<string> n_categories;
    /**
     * Sorts bars from biggest to smallest from top-down
    */
    void sort_bars(size_t start, size_t end); 
    
    /**
     * Function that calls the reading to form a barchart
    */
    void b_chart_read(int times, std::istream& stream); 

    /**
     * Resets the bars vector
    */
    void reset();

    /**
     * Adds a category if a new category is found
    */
    void check_categories();

    /**
     * Function to output all bars of the current chart with colors
    */
    void show_bars(int n_bars, vector<string> categories);

    /**
     * Function that calculates the lenght of the current bar in relation to
     * the biggest bar (bars[0] is the bigges since it's sorted).
    */
    int calculate_bar_lenght(int i);

    /**
     * Function to output the x axis below the chart
    */
    void x_axis(int n_bars);

    /**
     * Auxiliar function to output the bar with it's respective color
     * color based on category
    */
    void bar_color(std::string category, std::vector<std::string> categories);

    /**
     * Auxiliar function to output the name of current bar (label) with it's respective color
     * color based on category
    */
    void name_color(std::string category, std::vector<std::string> categories, string name);

    int round_up(int number, int power);
};

#endif