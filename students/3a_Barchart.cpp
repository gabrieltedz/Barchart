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
void Barchart::show_bars(int n_bars, vector<string> categories){
    /**
     * If the number of bars the barchart has is lower than the desired amout being displayed, do this:
     * the only difference is we will jump some lines at the end
    */
    if (bars.size() < n_bars){
        
        for (int i = 0; i < bars.size(); i++){
            
            // For the first (biggest) draw 120 colored spaces
            if (i == 0){
                for (int j = 0; j < 120; j++){
                    
                    bar_color(bars[i].category(), categories);
                } 
                name_color(bars[i].category(), categories, bars[i].label());
                std::cout << " [" << std::fixed << std::setprecision(2) << bars[i].value() << "]";
                std::cout << std::endl << std::endl;
                
            } else { // Note that calculate_bar_lenght only goes if the bar is not the first one (biggest bar)
                for (int j = 0; j < calculate_bar_lenght(i); j++){
                    
                    bar_color(bars[i].category(), categories);
                }
                name_color(bars[i].category(), categories, bars[i].label());
                std::cout << " [" << std::fixed << std::setprecision(2) << bars[i].value() << "]";
                std::cout << std::endl << std::endl;
            } 
        }

        // Jump the missing lines here 
        /*for (int i = 0; i < n_bars - bars.size(); i++){
            std::cout << std::endl << std::endl;
        }*/ 
    } else {
        for (int i = 0; i < n_bars; i++){
            if (i == 0){
                // For the first (biggest) draw 120 colored spaces
                for (int j = 0; j < 120; j++){
                    bar_color(bars[i].category(), categories);
                } 
                name_color(bars[i].category(), categories, bars[i].label());
                std::cout << " [" << std::fixed << std::setprecision(2) << bars[i].value() << "]";
                std::cout << std::endl << std::endl;
                
            }
            else { // Note that calculate_bar_lenght only goes if the bar is not the first one (biggest bar)
                for (int j = 0; j < calculate_bar_lenght(i); j++){
                    
                    bar_color(bars[i].category(), categories);
                }
                name_color(bars[i].category(), categories, bars[i].label());
                std::cout << " [" << std::fixed << std::setprecision(2) << bars[i].value() << "]";
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
void Barchart::x_axis(int n_bars){
    int length_min_bar{0};
    int aux1{0}, aux2{0}, aux3{0}, aux4{0}, aux5{0};
    int rounded1{0}, rounded2{0};
    int temp;
    std::string str1, str2, str3, str4, str5;
    if (bars.size() < n_bars){
        int m = bars.size() - 1;

        if (bars[m].value() == 0 || bars[0].value() == 0){
            length_min_bar = 120;
        } else {
            length_min_bar = std::floor((120 * bars[m].value()) / bars[0].value());
            if (length_min_bar == 0){
                length_min_bar = 120;
            }
        }
        std::cout << "+";
        
        for (int i = 0; i < length_min_bar - 1 ; i++){
            std::cout << "-";
        }     

        

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
            
            cout << "+";

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
        
            aux5 = floor(((115 - length_min_bar) * 5)/ 5) - floor(((115 - length_min_bar) * 4) / 5);
            for (int i = 0; i < aux5; i++){
                std::cout << "-";
            }
            std::cout << "+" << std::endl;
        }

        temp = static_cast<int>(bars[m].value());

        
        if (temp < 1){
            temp += 1;
            str1 = std::to_string(temp);
            rounded1 = round_up(temp, (str1.size() - 1));
            str1 = std::to_string(rounded1);
            std::cout << "0" << std::setw(length_min_bar + str1.size() - 1) << str1 << std::endl;
        } else if (temp < 100){
            str1 = std::to_string(temp);
            rounded1 = round_up(temp, (str1.size() - 1));
            str1 = std::to_string(rounded1);
            std::cout << "0" << std::setw(length_min_bar + str1.size() - 1) << str1 << std::endl;
        } else {
            str1 = std::to_string(temp);
            rounded1 = round_up(temp, (str1.size() - 2));
            str1 = std::to_string(rounded1);
            std::cout << "0" << std::setw(length_min_bar + str1.size() - 1) << str1;
            std::cout << std::setw(((length_min_bar) / 5)) << bars[0].value() <<std::endl;
        }
    
    } else if (bars.size() >= n_bars) {
        if (bars[n_bars - 1].value() == 0 || bars[0].value() == 0){
            length_min_bar = 120;
        } else {
            length_min_bar = std::floor((120 * bars[n_bars - 1].value()) / bars[0].value());
            if (length_min_bar == 0){
                length_min_bar = 120;
            }
        }

        //std::cout << length_min_bar << std::endl;
        //std::cout << "+";
        std::cout << "+";
        for (int i = 0; i < length_min_bar - 1 ; i++){
            std::cout << "-";
        }
        
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
            
            std::cout << "+";

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
        
            aux5 = floor(((115 - length_min_bar) * 5)/ 5) - floor(((115 - length_min_bar) * 4) / 5);
            for (int i = 0; i < aux5; i++){
                std::cout << "-";
            }
            std::cout << "+" << std::endl;
            
        }
        
        int temp = static_cast<int>(bars[n_bars - 1].value());

        if (temp < 1){
            temp += 1;
            str1 = std::to_string(temp);
            rounded1 = round_up(temp, (str1.size() - 1));
            str1 = std::to_string(rounded1);
            std::cout << "0" << std::setw(length_min_bar + str1.size() - 1) << str1 << std::endl;
        } else if (temp < 100){
            str1 = std::to_string(temp);
            rounded1 = round_up(temp, (str1.size() - 1));
            str1 = std::to_string(rounded1);
            std::cout << "0" << std::setw(length_min_bar + str1.size() - 1) << str1 << std::endl;
        } else {
            str1 = std::to_string(temp);
            rounded1 = round_up(temp, (str1.size() - 2));
            str1 = std::to_string(rounded1);
            str2 = std::to_string(static_cast<int>(bars[0].value()));
            std::cout << "0" << std::setw(length_min_bar + str1.size() - 1) << str1;
            std::cout << std::setw(((120 - length_min_bar) / 5) - str1.size() + str2.size()) << str2 << std::endl;
        }
        
        
    }
        
    
}

/**
 * To output current bar with its respective color
*/
void Barchart::bar_color(std::string category, std::vector<std::string> categories){
    if (categories.size() >= 15){
    // white
        std::cout << Color::tcolor("█", Color::getColorByIndex(14), Color::REGULAR);
    } else {
        if (category == categories[0]){
            // red
            std::cout << Color::tcolor("█", Color::getColorByIndex(0), Color::REGULAR);
        } else if (category == categories[1]){
            // green
            std::cout << Color::tcolor("█", Color::getColorByIndex(1), Color::REGULAR);
        } else if (category == categories[2]){  
            // yellow
            std::cout << Color::tcolor("█", Color::getColorByIndex(2), Color::REGULAR);
        } else if (category == categories[3]){
            // blue
            std::cout << Color::tcolor("█", Color::getColorByIndex(3), Color::REGULAR);
        } else if (category == categories[4]){
            // magenta
            std::cout << Color::tcolor("█", Color::getColorByIndex(4), Color::REGULAR);
        } else if (category == categories[5]){
            // cyan
            std::cout << Color::tcolor("█", Color::getColorByIndex(5), Color::REGULAR);
        } else if (category == categories[6]){
            // black
            std::cout << Color::tcolor("█", Color::getColorByIndex(6), Color::REGULAR);
        } else if (category == categories[7]){
            //bright red
            std::cout << Color::tcolor("█", Color::getColorByIndex(7), Color::REGULAR);
        } else if (category == categories[8]){
            // bright green
            std::cout << Color::tcolor("█", Color::getColorByIndex(8), Color::REGULAR);
        } else if (category == categories[9]){
            // bright yellow
            std::cout << Color::tcolor("█", Color::getColorByIndex(9), Color::REGULAR);
        } else if (category == categories[10]){
            // bright blue
            std::cout << Color::tcolor("█", Color::getColorByIndex(10), Color::REGULAR);
        } else if (category == categories[11]){
            // bright magenta
            std::cout << Color::tcolor("█", Color::getColorByIndex(11), Color::REGULAR);
        } else if (category == categories[12]){
            // bright cyan
            std::cout << Color::tcolor("█", Color::getColorByIndex(12), Color::REGULAR);
        } else if (category == categories[13]){
            // bright black
            std::cout << Color::tcolor("█", Color::getColorByIndex(13), Color::REGULAR);
        }
    }
    
}

/**
 * To output current bar name (label) with its respective color
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
    
int Barchart::round_up(int number, int power) {
    int divisor = std::pow(10, power);
    return ((number + divisor - 1) / divisor) * divisor;
}    
