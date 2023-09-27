#ifndef BCR_H
#define BCR_H
#include "2Database.h"

class BCR 
{
public:
    short n_bars = 5; // Numbers of bars will be displayed (deafult 5)
    short fps = 12; // Frames per second (default 12)

public:



    void start(int argc, char **argv); // initializes variables and reads CLI ONLY (-f and -b options) (does not read file yet)

    void bcr_read(); // Reads file (stores all data in database)

    
private:
    
    Database database; // Object containg all data from file

};

#endif
