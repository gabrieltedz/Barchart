#include "2b_Database.h"
#include <fstream>
#include <iostream>
#include <string>
#include <thread>

/**
 * @file 2b_Database.cpp
 * @brief Implementation of the Database class for structuring data used in the chart.
 */

/**
 * @brief Reads the file until the end, creating barchart instances stored in the vector named barcharts.
 * 
 * @param n_bars Number of bars for the animation.
 * @param fps Frames per second for the animation.
 * @param name_file Name of the file to be read.
 */
void Database::data_read(int n_bars, int fps, std::string name_file)
{
    // get file path (or name)
    archive.open(name_file);

    // Read first 3 lines (title, label, and source)
    std::getline(archive, main_title);
    std::getline(archive, label);
    std::getline(archive, source);

    string aux;
    int times;
    int i{0};
    Barchart b_chart;

    // While there are lines to read, read barcharts
    while (std::getline(archive >> std::ws, aux))
    {
        // Aux was what the getline read from the archive, it's a number indicating how many bars
        // the current barchart has. So, use string to integer to give it to times
        times = stoi(aux);

        // Temporary barchart reads the current
        b_chart.b_chart_read(times, archive);

        // Check for new categories
        max_categories(b_chart);

        // Add the barchart to the barchart vector (barcharts)
        barcharts.push_back(b_chart);

        // Temporary barchart gets RESET!!!
        b_chart.reset();
    }

    archive.close();
}

/**
 * @brief Returns the size of the barcharts vector.
 * 
 * @return The size of the barcharts vector.
 */
int Database::barcharts_size()
{
    return barcharts.size();
}

/**
 * @brief Checks if the current barchart has more categories than the categories stored in the database.
 * If it has, it's because it has a new element, so, update database categories with the new element.
 * 
 * @param b_chart The Barchart instance to be checked for new categories.
 */
void Database::max_categories(Barchart b_chart)
{
    if (categories.size() < b_chart.n_categories.size())
    {
        categories = b_chart.n_categories;
    }
}

/**
 * @brief Initiates the animation with the defined number of bars and frames per second.
 * 
 * @param n_bars Number of bars for the animation.
 * @param fps Frames per second for the animation.
 */
void Database::animation(int n_bars, int fps)
{
    /// Do for each barchart:
    for (int i = 0; i < barcharts.size(); i++)
    {
        /// Jump out lines to give the impression of animation:
        for (int j = 0; j < 40 - (n_bars * 2); j++)
        {
            std::cout << std::endl;
        }

        /// Main title
        std::cout << main_title << std::endl
                  << std::endl;

        /// Timestamp
        std::cout << "Timestamp: " << barcharts[i].timestamp << std::endl
                  << std::endl;

        /// Bars with colors
        barcharts[i].show_bars(n_bars, categories);

        /// X axis
        barcharts[i].x_axis(n_bars);

        /// Label
        std::cout << label << std::endl
                  << std::endl;

        /// Source
        std::cout << source << std::endl;

        /// Legend of colors
        legend();

        // Pause for a bit (fps)
        std::chrono::milliseconds duration{1000 / fps};
        std::this_thread::sleep_for(duration);
    }
}

/**
 * @brief Legend of colors below the barchart.
 */
void Database::legend()
{
    for (int i = 0; i < categories.size(); i++)
    {
        if (categories.size() >= 15)
        {
            std::cout << Color::tcolor("█", Color::getColorByIndex(15), Color::REGULAR);
            std::cout << ": " << Color::tcolor(categories[i], Color::getColorByIndex(15), Color::REGULAR) << " ";
        }
        else
        {
            std::cout << Color::tcolor("█", Color::getColorByIndex(i), Color::REGULAR);
            std::cout << ": " << Color::tcolor(categories[i], Color::getColorByIndex(i), Color::REGULAR) << " ";
        }
    }
    std::cout << std::endl;
}
