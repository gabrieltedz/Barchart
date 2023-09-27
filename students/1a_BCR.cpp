#include "1b_BCR.h"
/**
 * Basic function to read arguments from command line
*/
void BCR::start(int argc, char **argv){
    int intermed;
    if (argc == 1) {
        //do nothing (deafult)
    } 
    
    else if (argc > 1) {
        string arg;
        for (int i = 1; i < argc; i++){
            
            arg = argv[i];

            /**
             * It's an argument, so read it
            */
            if (arg[0] == '-'){

                if (arg[1] == 'b'){
                    arg = argv[i + 1];
                    try {
                        intermed = stoi(arg);
                        if (intermed >= 1 && intermed <= 15){
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
                        intermed = stoi(arg);
                        if (intermed >= 1 && intermed <= 24) {
                            fps = intermed;
                        }  
                    } catch (const std::invalid_argument& e) {
                        cerr << "Conversion failed: " << e.what() << std::endl;
                    }
                    i++;
               
                }

            } 
            
            /**
             * It's not an argument, ignore
            */
            else {

            }
        }
    }
}

void BCR::bcr_read_file(){
    //database.data_read();
}