#ifndef _2B_DATABASE_H
#define _2B_DATABASE_H
#include <fstream>
#include "3b_Barchart.h"
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
std::vector<Barchart> barcharts; 

public:
    // n_category (increases if a new category is found) TODO
    string main_title;
    string label;
    string source;

    /**
     * Function that reads the file until the end, creating barchart instances
     * stored in the vector named barcharts
    */
    void data_read(int n_bars, int fps);

    int barcharts_size();

};

#endif