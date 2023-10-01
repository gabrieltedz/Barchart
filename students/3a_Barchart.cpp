#include "3b_Barchart.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

/**
 * Mergesort sorting
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


/**
 * Function that calls the reading to form a barchart
 * Times is the number of lines (or bars) this barchart has
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

    //residual code in testing
    /*if (bars.size() < 15){
        for (int i = 0; i < bars.size(); i++){
            bars[i].show_line(); 
        } cout << endl;
    } else {
        for (int i = 0; i < 15; i++){
            bars[i].show_line(); 
        } cout << endl;
    }*/
     
}

/**
 * Resets the bars vector
*/
void Barchart::reset(){
    bars.clear();   
}

/**
 * Check if there's a new category, if there is, add it.
 * Since the n_categories are not reset between barcharts, this only adds a category
 * If it is a new one.
 * (So, all barcharts have all the categories that the data file provided until that point,
 * Even if the number of categories read in the barchart is lower than the total, this is very useful
 * Later on.)
*/
void Barchart::check_categories(){
    
    for (int i = 0; i < bars.size(); i++){
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
/**
 * Function to output the bars
*/
void Barchart::show_bars(int n_bars){
    /**
     * If the number of bars the barchart has is lower than the desired amout being displayed, do this:
     * the only difference is we will jump some lines at the end
    */
    if (bars.size() < n_bars){
        
        for (int i = 0; i < bars.size(); i++){
            
            // For the first (biggest) draw 120 colored spaces
            if (i == 0){
                for (int j = 0; j < 120; j++){
                    std::cout << Color::tcolor("█", Color::RED, Color::BOLD);
                } 
                std::cout << " " << bars[i].label() << " [" << std::fixed << std::setprecision(2) << bars[i].value() << "]";
                std::cout << std::endl << std::endl;
                
            } else { // Note that calculate_bar_lenght only goes if the bar is not the first one (biggest bar)
                for (int j = 0; j < calculate_bar_lenght(i); j++){
                    std::cout << Color::tcolor("█", Color::GREEN, Color::REGULAR);
                }
                std::cout << " " << bars[i].label() << " [" << std::fixed << std::setprecision(2) << bars[i].value() << "]";
                std::cout << std::endl << std::endl;
            } 
        }

        // Jump the missing lines here 
        for (int i = 0; i < n_bars - bars.size(); i++){
            std::cout << std::endl << std::endl;
        } 
    } else {
        for (int i = 0; i < n_bars; i++){
            if (i == 0){
                // For the first (biggest) draw 120 colored spaces
                for (int j = 0; j < 120; j++){
                    std::cout << Color::tcolor("█", Color::RED, Color::BOLD);
                } 
                std::cout << " " << bars[i].label() << " [" << std::fixed << std::setprecision(2) << bars[i].value() << "]";
                std::cout << std::endl << std::endl;
                
            }
            else { // Note that calculate_bar_lenght only goes if the bar is not the first one (biggest bar)
                for (int j = 0; j < calculate_bar_lenght(i); j++){
                    std::cout << Color::tcolor("█", Color::GREEN, Color::BOLD);
                }
                std::cout << " " << bars[i].label() << " [" << std::fixed << std::setprecision(2) << bars[i].value() << "]";
                std::cout << std::endl << std::endl;
            }
        } 
    }
}

/**
 * To calculate the bar lenght is quite simple, just a "regra de 3", "rule of three"
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

/**
 * Function to output the x axis below the chart
*/
void Barchart::x_axis(){
    
}