#ifndef _4B_BAR_H
#define _4B_BAR_H

#include <string>
#include "5b_Tokenizer.h"

using namespace std;

/*!
 * @file 4b_Bar.h
 * @brief Defines structures and classes related to individual bars in the data file.
 */

/*!
 * @brief All types of information from each single line in the datafile.
 */
struct BarItem {
    string time_stamp; /**< The time stamp the data was captured on. */
    string label;      /**< The data label. */
    string dummy;      /**< This is any other information related to the data item that is not going to be used in the visualization. */
    float value;       /**< The value of the data item to be represented by a single bar in a chart. */
    string category;   /**< A category the data item belongs to. */
};

/*!
 * @class Bar
 * @brief Contains the information of a single bar.
 */
class Bar {
private:
    /*!
     * @brief Each Bar object only contains the information from one line, as such,
     * It only has a BarItem object named items.
     */
    BarItem items;

public:
    /*!
     * @brief Reads a SINGLE line.
     *
     * @note This function is called once for each line that contains objects from bars.
     * It's called on barchart.read()
     */
    void read_line(std::istream &stream);

    /**
     * @brief Returns the value of the bar.
     *
     * @return The items.value.
     */
    float value();

    /*!
     * @brief Returns the label of the bar.
     *
     * @return The items.label.
     */
    string label();

    /*!
     * @brief Returns the category of the bar.
     *
     * @return The items.category.
     */
    string category();

    /*!
     * @brief Returns the time stamp of the bar.
     *
     * @return The items.time_stamp.
     */
    string time_stamp();

    /*!
     * @brief Shows a SINGLE line.
     * Used for testing.
     */
    void show_line();
};

#endif
