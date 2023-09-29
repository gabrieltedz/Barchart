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

  //bcr.welcome();

  //bcr.show_info();


  
  bcr.bcr_read_file(bcr.n_bars, bcr.fps);


  
  bcr.show_info();

  

  

  return EXIT_SUCCESS;
} 