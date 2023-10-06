#include "3b_Barchart.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;


/*!
 * @file 3a_Barchart.cpp
 * @brief Defines a class representing a Barchart and related functions.
 */

/*!
 * @brief Sorts a range of bars using the Merge Sort algorithm.
 * This function implements the Merge Sort algorithm to sort a range of bars
 * within the 'bars' vector in ascending order based on their values.
 * 
 * @param start The starting index of the range to be sorted.
 * @param end The ending index of the range to be sorted.
 * 
 * @note This function modifies the 'bars' vector in place and
 * doesn't order them in alfabetical order.
 */
void Barchart::sort_bars(size_t start, size_t end) {

    if (start < end) {
        size_t middle = start + (end - start) / 2;
        // Recursively sort the left and right halves
        sort_bars(start, middle);
        sort_bars(middle + 1, end);

        // Merge the two sorted halves
        std::vector<Bar> merged;
        std::size_t leftIndex = start;
        std::size_t rightIndex = middle + 1;

        while (leftIndex <= middle && rightIndex <= end) {
            if (bars[leftIndex].value() > bars[rightIndex].value()) {
                merged.push_back(bars[leftIndex]);
                leftIndex++;
            } else {
                merged.push_back(bars[rightIndex]);
                rightIndex++;
            }
        }
            // Append any remaining elements
        while (leftIndex <= middle) {
            merged.push_back(bars[leftIndex]);
            leftIndex++;
        }

        while (rightIndex <= end) {
            merged.push_back(bars[rightIndex]);
            rightIndex++;
        }

        // Copy the merged elements back into the original vector
        for (size_t i = start; i <= end; i++) {
            bars[i] = merged[i - start];
        }
    
    }

}


/*!
 * @brief Function that calls the reading to form a barchart.
 * 
 * @param times is the number of bars this barchart has and should expect to read.
 * @param stream file to read from.
*/
void Barchart::b_chart_read(int times, std::istream& stream){
    Bar bar;

    // Read "times" times since bar.read_line, only reads a line at a time
    for (int i = 0; i < times; i++){
        bar.read_line(stream);
        bars.push_back(bar);
    }
    // Sort the bars from biggest to smallest
    sort_bars(0, bars.size() - 1);
    // Check if there are any new categories
    check_categories();
    // Define the timestamp of this barchart
    timestamp = bars[0].time_stamp();
     
}

/*!
 * @brief Resets the bars vector
*/
void Barchart::reset(){
    bars.clear();   
}

/*!
 * @brief Check if there's a new category, if so, adds it.
 * 
 * @note Since the n_categories are not reset between barcharts, this only adds a category
 * if it's a new one.
 * (So, all barcharts have all the categories that the datafile provided until that point,
 * even if the number of categories read in that specific barchart is lower than the total)
*/
void Barchart::check_categories(){
    
    for (int i = 0; i < bars.size(); i++){
        // Check if the element is in the list.
        auto it = find(n_categories.begin(), n_categories.end(), bars[i].category());
        if (it != n_categories.end()) {
            // Element found
            // Do nothing
        } else {
            // Element not found
            // Add it to the list
            n_categories.push_back(bars[i].category());
        }
    }
}

/*!
 * @brief Function to output the bars with their colours.

 * @param n_bars max number of bars that can be displayed.
 * @param categories Total categories the database has.
 * 
 * @note categories is from database, not from barchart, this is because categories in the database
 * contains all the categories in the file. 
*/
void Barchart::show_bars(int n_bars, vector<string> categories){

    // If the number of bars the barchart has is lower than the desired amout being displayed.
    //then n_bars will be equal to bars.size(). Else, n_bars is the maximum amount of bars.

    if (bars.size() < n_bars){
        n_bars = bars.size();
    }   
    for (int i = 0; i < n_bars; i++){
        
        if (i == 0){ // For the first (biggest) draw 120 colored spaces
            
            bar_color(bars[i].category(), categories, 120);                
            name_color(bars[i].category(), categories, bars[i].label());
            std::cout << " [" << std::fixed << std::setprecision(2) << bars[i].value() << "]";
            std::cout << std::endl << std::endl;
            
        } else { // Note that calculate_bar_lenght only goes if the bar is not the first one (biggest bar)
            
            bar_color(bars[i].category(), categories, calculate_bar_lenght(i));
            name_color(bars[i].category(), categories, bars[i].label());
            std::cout << " [" << std::fixed << std::setprecision(2) << bars[i].value() << "]";
            std::cout << std::endl << std::endl;
        } 
    }
}


/*!
 * @brief calculate the bar lenght is quite simple, just a "rule of three".
 * 
 * @param i Index of the current bar.
*/
int Barchart::calculate_bar_lenght(int i){
    int length_bar{0};

    // Using the floor function ensures the bars are always smaller than the biggest one
    // facilitating the calculation.
    // 120 is the hight bar length, we multiply it by current bar value and divide the result
    // by bars[0] value. 
    length_bar = std::floor((120 * bars[i].value()) / bars[0].value());

    return length_bar;
}

/*!
 * @brief Function to output the x axis below the chart.
 * 
 * @param n_bars amount of bars this barchart has.
*/
void Barchart::x_axis(int n_bars){
    
    
    // Variables initiation.
    
    int length_min_bar{0};  /// Length of the smallest bar 
    int aux1{0}, aux2{0}, aux3{0}, aux4{0}, aux5{0};
    int rounded1{0};
    int temp{0}, temp2{0};
    std::string str1, str2, str3, str4, str5, str6;

    // If n_bars is bigger than bars.size(), than the amount of bars that will be displayed is bars.size()
    if (bars.size() < n_bars){
        n_bars = bars.size() - 1; // - 1 because the count starts at zero
    } 
    // If n_bars is smaller or equal to bars.size(), than the amount of bars that will be displayed is n_bars
    else if (bars.size() >= n_bars){
        n_bars -= 1; // - 1 because the count starts at zero
    }

    // If the smallest bar value == 0
    if (bars[n_bars].value() == 0){
        length_min_bar = 1;
    }

    // Else if the smallest bar is not zero
    else {
        // Calculate the length of the smallest bar
        length_min_bar = std::floor((120 * bars[n_bars].value()) / bars[0].value());
        
        // If the smallest bar value == 0
        if (length_min_bar == 0){
            length_min_bar = 1;
        }
    }

    // Cout the "+-------------------" part up until the length of the smallest bar.
    std::cout << "+";
    for (int i = 0; i < length_min_bar - 1 ; i++){
        std::cout << "-";
    }     

        
    // Special cases.

    if (length_min_bar == 120){
        std::cout << "+" << std::endl;
    } else if (length_min_bar == 119){
        std::cout << "++" << std::endl;
    } else if (length_min_bar == 118){
        std::cout << "+++" << std::endl;
    } else if (length_min_bar == 117){
        std::cout << "++++" << std::endl;
    } else if (length_min_bar == 116){
        std::cout << "+++++" << std::endl;
    } else {
        
        // Cout "+", this is exactly 1 character ahead of the smallest bar length
        cout << "+";

        // Calculate and output the divison of the (max bar - min bar) / 5
        aux1 = floor((115 - length_min_bar) / 5);
        for (int i = 0; i < aux1; i++){
            std::cout << "-";
        } std::cout << "+";
    
        aux2 = floor(((115 - length_min_bar) * 2) / 5) - aux1;
        for (int i = 0; i < aux2; i++){
            std::cout << "-";
        } std::cout << "+";
    
        aux3 = floor(((115 - length_min_bar) * 3)/ 5) - floor(((115 - length_min_bar) * 2) / 5);
        for (int i = 0; i < aux3; i++){
            std::cout << "-";
        } std::cout << "+";

        aux4 = floor(((115 - length_min_bar) * 4)/ 5) - floor(((115 - length_min_bar) * 3) / 5);
        for (int i = 0; i < aux4; i++){
            std::cout << "-";
        } std::cout << "+";
    
        aux5 = floor((115 - length_min_bar)) - floor(((115 - length_min_bar) * 4) / 5);
        for (int i = 0; i < aux5; i++){
            std::cout << "-";
        }
        // This "+" is exactly one charachter ahead of the biggest bar.
        std::cout << "+" << std::endl;
    }

    temp = static_cast<int>(bars[n_bars].value());
    
    // There's only one line, or the max and min bar lenght are the same.
    if (length_min_bar == 120){
        std::cout << "0";
        rounded1 = round_up(temp, 0);
        std::cout << setw(119 + std::to_string(rounded1).size()) << rounded1 << std::endl;
    }

    else {
        if (temp < 10){
        temp++;
        
        str1 = std::to_string(temp);
        
        rounded1 = round_up(temp, (str1.size() - 1));
        
    } else if (temp < 100){
        str1 = std::to_string(temp);
        rounded1 = round_up(temp, (str1.size() - 1));
        
    } else {
        str1 = std::to_string(temp);
        rounded1 = round_up(temp, (str1.size() - 2));
        
    }
    str1 = std::to_string(rounded1);

    /**
     * These calculate the numbers below the barchart rounding them up
     * If the number is above 100, round up to the second biggest house
    */
    if ((temp2 = std::stoi(str1)) > 100){
        str2 = std::to_string(round_up(temp + (bars[0].value() - bars[n_bars].value()) / 5, 
        std::to_string(static_cast<int>(bars[n_bars].value() + (bars[0].value() - bars[n_bars].value()) / 5)).size() - 2));

        str3 = std::to_string(round_up(temp + (bars[0].value() - bars[n_bars].value()) * 2 / 5, 
        std::to_string(static_cast<int>(bars[n_bars].value() + (bars[0].value() - bars[n_bars].value()) * 2 / 5)).size() - 2));

        str4 = std::to_string(round_up(temp + (bars[0].value() - bars[n_bars].value()) * 3 / 5, 
        std::to_string(static_cast<int>(bars[n_bars].value() + (bars[0].value() - bars[n_bars].value()) * 3 / 5)).size() - 2));

        str5 = std::to_string(round_up(temp + (bars[0].value() - bars[n_bars].value()) * 4 / 5, 
        std::to_string(static_cast<int>(bars[n_bars].value() + (bars[0].value() - bars[n_bars].value()) * 4 / 5)).size() - 2));

        str6 = std::to_string(round_up(static_cast<int>(bars[0].value()) + 1, std::to_string(static_cast<int>(bars[0].value())).size() - 2));
    } 
    
    // Else, if the number is equal or below 100, dont round up the number
    else {
        str2 = std::to_string(round_up(temp + (bars[0].value() - bars[n_bars].value()) / 5, 0));
        str3 = std::to_string(round_up(temp + (bars[0].value() - bars[n_bars].value()) * 2 / 5, 0));
        str4 = std::to_string(round_up(temp + (bars[0].value() - bars[n_bars].value()) * 3 / 5, 0));
        str5 = std::to_string(round_up(temp + (bars[0].value() - bars[n_bars].value()) * 4 / 5, 0));
        str6 = std::to_string(round_up(static_cast<int>(bars[0].value()) + 1, 0));
    }

    /**
     * Output of the numbers below the barchart at the exact position the "+" are in the line below.
    */
    std::cout << "0" << std::setw(length_min_bar + str1.size() - 1) << str1;                        
    std::cout << std::setw(aux1 - str1.size() + str2.size() + 1) << str2;
    std::cout << std::setw((aux2 - str2.size() + str3.size() + 1)) << str3;
    std::cout << std::setw((aux3 - str3.size() + str4.size() + 1)) << str4;
    std::cout << std::setw((aux4 - str4.size() + str5.size() + 1)) << str5;
    std::cout << std::setw((aux5 - str5.size() + str6.size() + 1)) << str6 << std::endl;
    }
}
        
    

/*!
* @brief To output current bar with its respective color.
*
* @param category Category of the current bar.
* @param categories Total categories in the database.
* @param bar_length Length of the bar.
*/
void Barchart::bar_color(std::string category, std::vector<std::string> categories, int bar_lenght){
    
    int index;
    if (categories.size() >= 15){
    // white
        index = 14;
    } else {
        if (category == categories[0]){
            index = 0;
            // red
        } else if (category == categories[1]){
            // green
            index = 1;
        } else if (category == categories[2]){  
            // yellow
            index = 2;
        } else if (category == categories[3]){
            // blue
            index = 3;
        } else if (category == categories[4]){
            // magenta
            index = 4;
        } else if (category == categories[5]){
            // cyan
            index = 5;
        } else if (category == categories[6]){
            // black
            index = 6;
        } else if (category == categories[7]){
            //bright red
            index = 7;
        } else if (category == categories[8]){
            // bright green
            index = 8;
        } else if (category == categories[9]){
            // bright yellow
            index = 9;
        } else if (category == categories[10]){
            // bright blue
            index = 10;
        } else if (category == categories[11]){
            // bright magenta
            index = 11;
        } else if (category == categories[12]){
            // bright cyan
            index = 12;
        } else if (category == categories[13]){
            // bright black
            index = 13;
        }
        
    }
    for (int i = 0; i < bar_lenght; i++){
        std::cout << Color::tcolor("█", Color::getColorByIndex(index), Color::REGULAR);
    }
}


/*!
* @brief To output current bar name (label) with its respective color.
*
* @param category Category of the current bar.
* @param categories Total categories in the database.
* @param name Name (label) of the current bar.
*/
void Barchart::name_color(std::string category, std::vector<std::string> categories, string name){
    if (categories.size() >= 15){
    // white
        std::cout << " " << Color::tcolor(name, Color::getColorByIndex(14), Color::REGULAR);
    } else {
        if (category == categories[0]){
            // red
            std::cout << " " << Color::tcolor(name, Color::getColorByIndex(0), Color::REGULAR);
        } else if (category == categories[1]){
            // green
            std::cout << " " << Color::tcolor(name, Color::getColorByIndex(1), Color::REGULAR);
        } else if (category == categories[2]){  
            // yellow
            std::cout << " " << Color::tcolor(name, Color::getColorByIndex(2), Color::REGULAR);
        } else if (category == categories[3]){
            // blue
            std::cout << " " << Color::tcolor(name, Color::getColorByIndex(3), Color::REGULAR);
        } else if (category == categories[4]){
            // magenta
            std::cout << " " << Color::tcolor(name, Color::getColorByIndex(4), Color::REGULAR);
        } else if (category == categories[5]){
            // cyan
            std::cout << " " << Color::tcolor(name, Color::getColorByIndex(5), Color::REGULAR);
        } else if (category == categories[6]){
            // black
            std::cout << " " << Color::tcolor(name, Color::getColorByIndex(6), Color::REGULAR);
        } else if (category == categories[7]){
            //bright red
            std::cout << " " << Color::tcolor(name, Color::getColorByIndex(7), Color::REGULAR);
        } else if (category == categories[8]){
            // bright green
            std::cout << " " << Color::tcolor(name, Color::getColorByIndex(8), Color::REGULAR);
        } else if (category == categories[9]){
            // bright yellow
            std::cout << " " << Color::tcolor(name, Color::getColorByIndex(9), Color::REGULAR);
        } else if (category == categories[10]){
            // bright blue
            std::cout << " " << Color::tcolor(name, Color::getColorByIndex(10), Color::REGULAR);
        } else if (category == categories[11]){
            // bright magenta
            std::cout << " " << Color::tcolor(name, Color::getColorByIndex(11), Color::REGULAR);
        } else if (category == categories[12]){
            // bright cyan
            std::cout << " " << Color::tcolor(name, Color::getColorByIndex(12), Color::REGULAR);
        } else if (category == categories[13]){
            // bright black
            std::cout << " " << Color::tcolor(name, Color::getColorByIndex(13), Color::REGULAR);
        }
    }
    
}

/**
 * @brief Returns a number rounded up to the power of 10 choosen
 * @param number number to be rounded up
 * @param power house that will be rounded up (right to left)
 * @note The rounding up "eats" the house from right to left given by power and rounds up by ten the next bigger house than the one eaten.
 * 
 * @note Example: number = 1457, power = 2, result = 1500
 * @note Example: number = 368, power = 2, result = 400
 * @note Example: number = 45678, power = 1, result = 45680
 * @note Example: number = 345, power = 0, result = 345
 * @note Example: number = 1457, power = 3, result = 2000
 * @note Example: number = 1457, power = 4, result = 10000
 * @note Example: number = 1457, power = 5, result = 100000
*/ 
int Barchart::round_up(int number, int power) {
    // power of 10 we will use to round up the number
    int divisor = std::pow(10, power);
    
    // This first calculation may give a decimal number, for example (power == 2)
    // (1457 + 100 - 1) / 100 = 15,56
    // rounding 15,56 down it's 15
    int result = ((number + divisor - 1) / divisor) 

    // multiplying 15 by 100 we get 1500
    * divisor;

    // Does not accept numbers lower than one
    return (result < 1) ? 1 : result;
}    
