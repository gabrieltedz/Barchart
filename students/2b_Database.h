#ifndef _2B_DATABASE_H
#define _2B_DATABASE_H

#include <fstream>
#include "3b_Barchart.h"
#include <fstream>

/*!
 * @file 2b_Database.h
 * @brief Structure the data to be used in the chart.
 */

/**
 * @class Database
 * @brief The database contains all the data necessary to create the barchart animation.
 * It also includes the three starting lines detailing title, label, and source.
 */
class Database 
{
private:
    
    
    /*!< A vector containing all instances of barcharts. 
    Each barchart contains a frame of animation from the animation.*/
      
    std::vector<Barchart> barcharts; 

public:

    std::vector<string> categories;              /*!< Number of categories the file has */
    std::string main_title;                      /*!< Title (first line of the input file) */
    std::string label;                           /*!< Label (second line of the input file) */
    std::string source;                          /*!< Source (third line of the input file) */
    std::ifstream archive;                       /*!< Name of the archive we will open to read */

    /*!
     * @brief Function that reads the file until the end, creating barchart instances
     * stored in the vector named barcharts.
     * 
     * @param n_bars Number of bars for the animation.
     * @param fps Frames per second for the animation.
     * @param name_file Name of the file to be read.
     */
    void data_read(int n_bars, int fps, std::string name_file);

    /*!
     * @brief Function that returns the size of the barcharts vector.
     * 
     * @return The size of the barcharts vector.
     */
    int barcharts_size();

    /*!
     * @brief Checks if the current barchart has a new category.
     * If so, adds it to the database categories, which is the "global" max amount of categories.
     * 
     * @param b_chart The Barchart instance to be checked for new categories.
     */
    void max_categories(Barchart b_chart);

    /*!
     * @brief Starts the animation with the defined number of bars and frames per second.
     * 
     * @param n_bars Number of bars for the animation.
     * @param fps Frames per second for the animation.
     */
    void animation(int n_bars, int fps);

    /*!
     * @brief Legend of colors below the barchart.
     */
    void legend();

};

#endif
