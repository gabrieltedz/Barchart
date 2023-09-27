#include "2b_Database.h"
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
using namespace std;

void Database::data_read(int n_bars, int fps){
    
    getline(cin, main_title);
    getline(cin, source);
    getline(cin, label);
    string aux;
    int times;
    int i{0};
    Barchart b_chart;


    while(getline(cin >> ws, aux)){
        
        cout << endl;
        times = stoi(aux);
        b_chart.b_chart_read(times);
        barcharts.push_back(b_chart);

		std::chrono::milliseconds  duration{ 1000 / fps};
		std::this_thread::sleep_for( duration );
		//std::cout << "This sentence will be printed on the standard output approximately " << fps << " times per second.\n";

    }
}