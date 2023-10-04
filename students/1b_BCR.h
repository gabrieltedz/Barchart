#ifndef _1B_BCR_H
#define _1B_BCR_H

#include "2b_Database.h"

 /*!
 * @file 1b_BCR.h
 * @brief Header file for the BCR class, which runs a program for handling and displaying bars.
 */

 /*!
 * @class BCR
 * @brief Class that runs the program for handling and displaying bars.
 */
class BCR 
{
public:
    int n_bars = 5;                        /*!< Number of bars to be displayed (default is 5). */
    
    int fps = 12;                          /*!< Frames per second for the chart (default is 12). */

    std::string name_file;                 /*!< File name for input. */


    /*!
     * @brief Basic function to read command line arguments.
     * 
     * @param argc Number of command line arguments.
     * @param argv Array of command line arguments.
    */
    void start(int argc, char **argv); 

    /*!
     * @brief Displays a welcome message containing information about the program.
    */
    void welcome();

    /*!
     * @brief Displays information about the operation and some key data of the chart.
    */
    void show_info();
    
    /*!
     * @brief Reads the file and stores all data in the database.
     * 
     * This function calls the read function from lower classes, such as `data_read`.
     * For example, `bcr_read` calls `data_read`. The former calls `b_cart.read()`, and so on.
    */
    void bcr_read_file(int n_bars, int fps);

    /*!
     * @brief Updates the data related to the number of bars and the FPS of the chart.
     *
     * @param n_bars Number of bars to be displayed.
     * @param fps Chart playback rate.
    */
    void animation(int n_bars, int fps);
    
private:
    Database database;                      /*!< Object containing all data from the file. */
};

#endif
