#include <cstdlib> // EXIT_SUCCESS
#include <vector>
#include "1BCR.h"

// OBJETIVO PRINCIPAL NO MOMENTO:
// Conseguir fazer leitura de dados (não tentar fazer output sem antes
// settar os dados anteriormente)
// Start on 4Bar.h!!!!!!!!!

int main(int argc, char **argv) {
  BCR bcr;
  Bar bar;

  bar.read_line();

  // Parse CLI options
  //bcr.start(argc, argv);

  // Read file
  //bcr.bcr_read();

  

  return EXIT_SUCCESS;
}