#ifndef _2B_DATABASE_H
#define _2B_DATABASE_H
#include <fstream>
#include "3b_Barchart.h"
#include <fstream>
using namespace std;

/**
 * The database contains all the data necessary to make the barchart animation. 
 * And also the 3 starting lines detailing title, label and source.
*/
class Database 
{
private:
    /**
     * A vector containing all instances of barcharts.
     * >>>> Each barchart contains a frame of animation from the animation.
    */
    vector<Barchart> barcharts; 

public:

    vector<string> categories; /**< Number of categories the file has*/
    string main_title; /**< Title (first line of the input file)*/
    string label; /**< Label (second line of the input file)*/
    string source; /**< Source (third line of the input file)*/
    
    std::ifstream archive;

    /**
     * Function that reads the file until the end, creating barchart instances
     * stored in the vector named barcharts
    */
    void data_read(int n_bars, int fps, std::string name_file);

    /**
     * Funtion that returns barcharts_size
    */
    int barcharts_size();

    void max_categories(Barchart b_chart);

    void animation(int n_bars, int fps);

};

#endif