#include "3b_Barchart.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

/**
 * Mergesort function
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
        for (std::size_t i = start; i <= end; i++) {
            bars[i] = merged[i - start];
        }
        
        
    
    }

}


/**
 * Function that calls the reading to form a single barchart
*/
void Barchart::b_chart_read(int times){
    Bar bar;
    for (int i = 0; i < times; i++){
        bar.read_line();
        bars.push_back(bar);
    }
    sort_bars(0, bars.size() - 1);
    for (int i = 0; i < bars.size(); i++){
        bars[i].show_line();
    } 
}

void Barchart::reset(){
    bars.clear();
}