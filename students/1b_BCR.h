#ifndef _1B_BCR_H
#define _1B_BCR_H
#include "2b_Database.h"

class BCR 
{
public:
    short n_bars = 5; // Numbers of bars will be displayed (deafult 5)
    short fps = 24; // Frames per second (default 24)

public:

    void start(int argc, char **argv); /**< initializes variables and reads CLI ONLY (-f and -b options) (does not read file yet) */

    // Reads file (stores all data in database) (these read functions calls the read function from their lower classes)
    // EX: bcr_read calls data_read. The former calls b_cart.read() and so on and so forth...
    void bcr_read_file(int n_bars, int fps); 
    
private:
    
    Database database; // Object containg all data from file

};

#endif
