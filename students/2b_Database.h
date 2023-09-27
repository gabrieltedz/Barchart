#ifndef _2B_DATABASE_H
#define _2B_DATABASE_H
#include <fstream>
#include "3b_Barchart.h"
using namespace std;

class Database 
{
private:
    std::vector<Barchart> barcharts; //(a vector containing all instances of barcharts)

public:
    // n_category (increases if a new category is found)
    string main_title;
    string source;
    string label;

    void data_read(int n_bars, int fps);

};

#endif