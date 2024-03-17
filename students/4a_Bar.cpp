#include "4b_Bar.h"
using namespace std;

/**
 * @file 4b_Bar.cpp
 * @brief Defines a class representing a single bar and related functions.
 */

/**
 * @brief Function to read a line.
 *
 * @param stream File to read from.
 */
void Bar::read_line(std::istream &stream) {
    Tokenizer tk; // Tokenizer to separate the line into tokens
    string input;
    getline(stream, input); // Get the line

    tk.tokens(input, ",", false); // Make tokens

    /**
     * Attribute tokens to respective items.
     */
    items.time_stamp = tk.get_token();
    tk.next();
    items.label = tk.get_token();
    tk.next();
    items.dummy = tk.get_token();
    tk.next();
    items.value = std::stof(tk.get_token());
    tk.next();
    items.category = tk.get_token();
}

/**
 * @brief Outputs a bar, used for testing.
 */
void Bar::show_line() {
    cout << items.time_stamp << "." << items.label << "." << items.dummy << "." << items.value << "." << items.category << "." << endl;
}

/**
 * @brief Returns the items.value.
 *
 * @return The value of the bar.
 */
float Bar::value() {
    return items.value;
}

/**
 * @brief Returns the items.category.
 *
 * @return The category of the bar.
 */
string Bar::category() {
    return items.category;
}

/**
 * @brief Returns the items.label.
 *
 * @return The label of the bar.
 */
string Bar::label() {
    return items.label;
}

/**
 * @brief Returns the items.time_stamp.
 *
 * @return The time stamp of the bar.
 */
string Bar::time_stamp() {
    return items.time_stamp;
}
