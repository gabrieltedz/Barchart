#include <cstdlib> // EXIT_SUCCESS
#include <vector>
#include <fstream>
#include "1b_BCR.h"
using namespace std;

/* OBJETIVO PRINCIPAL NO MOMENTO:
* Conseguir fazer leitura de dados (não tentar fazer output sem antes
* settar os dados anteriormente)
* Comece no 4Bar.h!!!!!!!!!!
*/
int main(int argc, char **argv) {
  BCR bcr;

  bcr.start(argc, argv);

  bcr.bcr_read_file(bcr.n_bars, bcr.fps);

  

  return EXIT_SUCCESS;
}