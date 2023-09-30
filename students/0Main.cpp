#include <cstdlib> // EXIT_SUCCESS
#include <vector>
#include <fstream>
#include "1b_BCR.h"
using namespace std;

/* 
*/
int main(int argc, char **argv) {
  BCR bcr;

  bcr.start(argc, argv);

  bcr.welcome();

  bcr.bcr_read_file(bcr.n_bars, bcr.fps);

  bcr.show_info(); // Will wait for enter from user

  bcr.animation(bcr.n_bars, bcr.fps);

  

  

  return EXIT_SUCCESS;
} 