#ifndef _1B_BCR_H
#define _1B_BCR_H
#include "2b_Database.h"

/**
 * Class that runs the program
*/
class BCR 
{
public:
    /**
     * Numbers of bars will be displayed (deafult 5)
    */
    int n_bars = 5;
    /**
     * Frames per second (default 24)
    */
    int fps = 24;

    std::string name_file;                 /*!< File name. */


    /**
     * Basic function to read arguments from command line
    */
    void start(int argc, char **argv); 

    void welcome();

    void show_info();
    
    /**
     * Reads file (stores all data in database) (these read functions calls the read function from their lower classes)
     * EX: bcr_read calls data_read. The former calls b_cart.read() and so on and so forth...
    */
    void bcr_read_file(int n_bars, int fps);

    void animation(int n_bars, int fps);
    
private:
    /**
     * Object containg all data from file
    */
    Database database;

};

#endif
