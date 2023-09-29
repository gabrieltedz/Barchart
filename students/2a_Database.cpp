#include "2b_Database.h"
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
using namespace std;

/**
 * Function that reads the file until the end, creating barchart instances
 * stored in the vector named barcharts
*/
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
        max_categories(b_chart);
        barcharts.push_back(b_chart);
        b_chart.reset();

		std::chrono::milliseconds  duration{ 1000 / fps};
		std::this_thread::sleep_for( duration );
    }

    cout << "Categorias presentes no file: ";
    for (int i = 0; i < categories.size(); i++){
        cout << categories[i] << "/";
    }
    cout << endl << endl;
}

int Database::barcharts_size(){
    return barcharts.size();
}

void Database::max_categories(Barchart b_chart){
    if (categories.size() < b_chart.n_categories.size()){
        categories = b_chart.n_categories;
    }
}