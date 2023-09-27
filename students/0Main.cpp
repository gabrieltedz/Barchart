#include <cstdlib> // EXIT_SUCCESS
#include <vector>
#include "1b_BCR.h"
using namespace std;

/* OBJETIVO PRINCIPAL NO MOMENTO:
* Conseguir fazer leitura de dados (não tentar fazer output sem antes
* settar os dados anteriormente)
* Comece no 4Bar.h!!!!!!!!!!
*/
int main(int argc, char **argv) {
  BCR bcr;
  Bar bar;

  bcr.start(argc, argv);
  bar.read_line();
  cout << bcr.n_bars << endl;
  cout << bcr.fps << endl;
  // Read file
  //bcr.bcr_read();

  

  return EXIT_SUCCESS;
}