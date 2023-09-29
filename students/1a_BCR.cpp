#include "1b_BCR.h"
using namespace std;
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
            
            else {
                name_file = argv[i];
            }
        }
    }
}

void BCR::welcome(){

    cout << "====================================================" << endl;
    cout << "  Welcome to the incredible Bar Chart Race! (v1.0)" << endl;
    cout << "  Copyright (C) 2023, Authors:" << endl;
    cout << "  Gabriel" << endl;
    cout << "  Thiago de Medeiros Raquel" << endl;
    cout << "====================================================" << endl << endl;

    cout << ">>> Preparing to read input file..." << endl << endl;

    cout << ">>> Processing data, please, wait." << endl;
}

void BCR::show_info(){
    cout << ">>> Input file successfully read." << endl << endl;

    cout << ">>> We have " << database.barcharts_size() << " charts." << endl;
    cout << ">>> Animation speed is: " << fps << "." << endl;
    cout << ">>> Bars being displayed : " << n_bars << "." << endl;
    cout << ">>> Title: " << database.main_title << endl;
    cout << ">>> Value is: " << database.label << endl;
    cout << ">>> " << database.source << endl;
    // cout << ">>> # of categories found: "  << endl;
    cout << ">>> Press enter to begin the animation." << endl << endl;

    // cout << categories

}

/**
 * Function to call data read
*/
void BCR::bcr_read_file(int n_bars, int fps){
    database.data_read(n_bars, fps, name_file);
}