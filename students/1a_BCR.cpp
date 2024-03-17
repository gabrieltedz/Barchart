#include "1b_BCR.h"

/*!
 * @file 1b_BCR.h
 * @brief Header file for the BCR class, which runs a program for handling and displaying bars.
 */

/*!
 * @brief Basic function to read arguments from the command line.
 * 
 * This function reads command line arguments, including options for the number of bars (`-b`),
 * the frames per second (`-f`), and the input file name. Default values are provided.
 *
 * @param argc Number of command line arguments.
 * @param argv Array of command line arguments.
 */
void BCR::start(int argc, char **argv) {
    int intermed;

    if (argc == 1) {
        // Show usage, exit.
        usage();
        return exit(1);
    } 
    else if (argc > 1) {
        std::string arg;
        for (int i = 1; i < argc; i++) {
            arg = argv[i];

            /**
             * It's an argument, so read it
            */
            if (arg[0] == '-') {
                if (arg[1] == 'b') {
                    arg = argv[i + 1];
                    try {
                        intermed = std::stoi(arg);
                        if (intermed >= 1 && intermed <= 15) {
                            n_bars = intermed;
                        }
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Conversion failed: " << e.what() << std::endl;
                    }
                    i++;
                } 
                else if (arg[1] == 'f') {
                    arg = argv[i + 1];
                    try {
                        intermed = std::stoi(arg);
                        if (intermed >= 1 && intermed <= 24) {
                            fps = intermed;
                        }  
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Conversion failed: " << e.what() << std::endl;
                    }
                    i++;
                }
                else if(arg[1] == 'h'){
                    usage();
                    return exit(1);
                }
                else{
                    std::string line;
                    std::cerr << "Unknow option: " << argv[i] << "\n";
                    usage();
                    std::cerr << "Default options will be assumed. \n\n";
                    std::cout << ">>> Press enter to continue.\n";
                    std::getline(std::cin, line);
                    n_bars = 5;
                    fps = 12;
                }
            } 
            else {
                name_file = argv[i];
            }
        }
    }
}

/*!
 * @brief Displays a welcome message containing information about the program.
 */
void BCR::welcome() {
    std::cout << "====================================================" << std::endl;
    std::cout << "  Welcome to the incredible Bar Chart Race! (v1.0)" << std::endl;
    std::cout << "  Copyright (C) 2023, Authors:" << std::endl;
    std::cout << "  Gabriel Victor da Silva" << std::endl;
    std::cout << "  Thiago de Medeiros Raquel" << std::endl;
    std::cout << "====================================================" << std::endl << std::endl;

    std::cout << ">>> Preparing to read the input file..." << std::endl << std::endl;
    std::cout << ">>> Processing data, please wait." << std::endl;
}

/*!
 * @brief Displays information about the operation and some key data of the chart.
 */
void BCR::show_info() {
    std::cout << ">>> Input file successfully read." << std::endl << std::endl;
    std::cout << ">>> We have " << database.barcharts_size() << " charts." << std::endl;
    std::cout << ">>> Animation speed is: " << fps << "." << std::endl;
    std::cout << ">>> Bars being displayed: " << n_bars << "." << std::endl;
    std::cout << ">>> Title: " << database.main_title << std::endl;
    std::cout << ">>> Value is: " << database.label << std::endl;
    std::cout << ">>> " << database.source << std::endl;
    std::cout << ">>> # of categories found: " << database.categories.size()  << std::endl;
    for (int i = 0; i < database.categories.size(); i++) {
        if (i % 3 == 0) {
            std::cout << std::endl;
        }
        std::cout << "[" << database.categories[i] << "] "; 
    }
    std::cout << std::endl << std::endl;
    std::cout << ">>> Press enter to begin the animation." << std::endl;
    
    std::cin.ignore();
}

/*!
 * @brief Initiates the animation with specified parameters.
 * 
 * @param n_bars Number of bars to be displayed.
 * @param fps Chart playback rate.
 */
void BCR::animation(int n_bars, int fps) {
    database.animation(n_bars, fps);
}

/*!
 * @brief Function to call data read.
 * 
 * Initiates the process of reading data from the input file using the Database class.
 * 
 * @param n_bars Number of bars to be displayed.
 * @param fps Chart playback rate.
 */
void BCR::bcr_read_file(int n_bars, int fps) {
    database.data_read(n_bars, fps, name_file);
}

/*!
 * @brief Print the instructions for use.
*/
void BCR::usage(){
    std::cerr << "Usage: bcr [<options>] <input_data_file>\n";
    std::cerr << "Bar Chart Race options:\n";
    std::cerr << "      -b  <num> Max # of bars in a single char.\n";
    std::cerr << "                Valid range is [1,15]. Default values is 5.\n";
    std::cerr << "      -f  <num> Animation speed in fps (frames per second).\n";
    std::cerr << "                Valid range is [1,24]. Default value is 12.\n";

}