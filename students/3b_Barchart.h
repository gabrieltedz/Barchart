#ifndef _3B_BARCHART_H
#define _3B_BARCHART_H
#include "4b_Bar.h"
using namespace std;


/**
 * @brief Class that contains an instance of animation from the Barchart
 * @note Contains a vector of bars
*/
class Barchart
{
private:
    /**
     * @brief Vector of bars.
    */
    vector<Bar> bars;
public:
    /**
     * @brief Current timestamp of the barchart.
    */
    string timestamp;

    /**
     * @brief Number of categories this barchart has.
    */
    vector<string> n_categories;
    /**
     * @brief Sorts bars from biggest to smallest from top-down
    */
    void sort_bars(size_t start, size_t end); 
    
    /**
     * @brief Function that calls the reading to form a barchart
    */
    void b_chart_read(int times, std::istream& stream); 

    /**
     * @brief Resets the bars vector
    */
    void reset();

    /**
     * @brief Adds a category if a new category is found
    */
    void check_categories();

    /**
     * @brief Function to output all bars of the current chart with colors
    */
    void show_bars(int n_bars, vector<string> categories);

    /**
     * @brief Function that calculates the lenght of the current bar in relation to
     * the biggest bar (bars[0] is the biggest since it's sorted).
    */
    int calculate_bar_lenght(int i);

    /**
     * @brief Function to output the x axis below the chart
    */
    void x_axis(int n_bars);

    /**
     * Auxiliar function to output the bar with it's respective color
     * color based on category
    */
    void bar_color(std::string category, std::vector<std::string> categories, int bar_length);

    /**
     * Auxiliar function to output the name of current bar (label) with it's respective color
     * color based on category
    */
    void name_color(std::string category, std::vector<std::string> categories, string name);

    /**
     * @brief Returns a number rounded up to the power of 10 choosen
    */
    int round_up(int number, int power);
};

#endif