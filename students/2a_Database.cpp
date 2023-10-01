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
void Database::data_read(int n_bars, int fps, std::string name_file)
{

    archive.open(name_file);

    std::getline(archive, main_title);
    std::getline(archive, label);
    std::getline(archive, source);

    string aux;
    int times;
    int i{0};
    Barchart b_chart;

    while (std::getline(archive >> std::ws, aux))
    {

        times = stoi(aux);

        b_chart.b_chart_read(times, archive);

        max_categories(b_chart);

        barcharts.push_back(b_chart);

        b_chart.reset();


        
    }

    archive.close();

    /* Residual code here*/
    /*cout << "Categorias presentes no file: ";
    for (int i = 0; i < categories.size(); i++)
    {
        cout << categories[i] << "/";
    }
    cout << endl 
         << endl;*/
}

int Database::barcharts_size()
{
    return barcharts.size();
}

void Database::max_categories(Barchart b_chart)
{
    if (categories.size() < b_chart.n_categories.size())
    {
        categories = b_chart.n_categories;
    }
}

void Database::animation(int n_bars, int fps){
    for(int i = 0; i < barcharts.size(); i++){
        //Jump(); Used to jump the lines and give the illusion of animation
        std::cout << main_title << std::endl << std::endl;

        std::cout << "Timestamp: " << barcharts[i].timestamp << std::endl << std::endl;
            
        barcharts[i].show_bars(n_bars, categories);
        barcharts[i].x_axis();

        std::cout << "axis here" << std::endl;
        std::cout << label << std::endl << std::endl; 

        std::cout << source << std::endl;

        std::chrono::milliseconds duration{1000 / fps};
        std::this_thread::sleep_for(duration);

    }
}
