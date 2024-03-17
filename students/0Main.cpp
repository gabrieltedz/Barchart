#include <cstdlib> // EXIT_SUCCESS
#include <vector>
#include <fstream> //std::ifstream

#include "1b_BCR.h"

 /*!
 * @file main.cpp
 * @brief The main entry point for the Bar Chart Race program.
 */

 /*!
 * @brief The main function initializes and runs the Bar Chart Race program.
 * 
 * @param argc Number of command line arguments.
 * @param argv Array of command line arguments.
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(int argc, char **argv) {
  /// Create BCR object  
  BCR bcr;

  /// Read command line arguments
  bcr.start(argc, argv);

  /// Display welcome message
  bcr.welcome();

  /// Read data from the input file
  bcr.bcr_read_file(bcr.n_bars, bcr.fps);

  /// Display information about the data and wait for user input
  bcr.show_info(); // Will wait for enter from the user

  /// Initiate the animation
  bcr.animation(bcr.n_bars, bcr.fps);

  return EXIT_SUCCESS;
}
