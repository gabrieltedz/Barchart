#ifndef _3B_BARCHART_H
#define _3B_BARCHART_H

#include "4b_Bar.h"

/*!
 * @file 3b_Barchart.h
 * @brief Defines a class representing a Barchart and related functions.
 */

/*!
 * @class Barchart.h
 
 * @brief Class that contains an instance of animation from the Barchart.
 * 
 * @note Contains a vector of bars.
 */
class Barchart {
private:

    vector<Bar> bars;                   /*!< Vector of bars. */

public:

    string timestamp;                   /*!< Current timestamp of the barchart. */

    vector<string> n_categories;        /*!< Number of categories this barchart has. */

    /*!
     * @brief Sorts bars from biggest to smallest from top-down.
     *
     * @param start The starting index of the range to be sorted.
     * @param end The ending index of the range to be sorted.
     */
    void sort_bars(size_t start, size_t end);

    /*!
     * @brief Function that calls the reading to form a barchart.
     *
     * @param times The number of bars this barchart has and should expect to read.
     * @param stream File to read from.
     */
    void b_chart_read(int times, std::istream &stream);

    /*!
     * @brief Resets the bars vector.
     */
    void reset();

    /*!
     * @brief Adds a category if a new category is found.
     */
    void check_categories();

    /*!
     * @brief Function to output all bars of the current chart with colors.
     *
     * @param n_bars Max number of bars that can be displayed.
     * @param categories Total categories the database has.
     */
    void show_bars(int n_bars, vector<string> categories);

    /*!
     * @brief Function that calculates the length of the current bar in relation to
     * the biggest bar (bars[0] is the biggest since it's sorted).
     *
     * @param i Index of the current bar.
     * @return The length of the bar.
     */
    int calculate_bar_lenght(int i);

    /*!
     * @brief Function to output the x-axis below the chart.
     *
     * @param n_bars Amount of bars this barchart has.
     */
    void x_axis(int n_bars);

    /*!
     * @brief Auxiliar function to output the bar with its respective color
     * color based on category.
     *
     * @param category Category of the current bar.
     * @param categories Total categories in the database.
     * @param bar_length Length of the bar.
     */
    void bar_color(std::string category, std::vector<std::string> categories, int bar_length);

    /*!
     * @brief Auxiliar function to output the name of the current bar (label) with its respective color
     * color based on category.
     *
     * @param category Category of the current bar.
     * @param categories Total categories in the database.
     * @param name Name (label) of the current bar.
     */
    void name_color(std::string category, std::vector<std::string> categories, string name);

    /*!
     * @brief Returns a number rounded up to the power of 10 chosen.
     *
     * @param number Number to be rounded up.
     * @param power Power that will be rounded up (right to left).
     * @return The rounded-up number.
     */
    int round_up(int number, int power);
};

#endif
