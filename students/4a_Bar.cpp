#include "4b_Bar.h"
using namespace std;

/**
 * Function to read a line ang get it's corresponding bar
*/
void Bar::read_line(std::istream& stream){
    Tokenizer tk;
    string input;
    getline(stream, input);

    tk.tokens(input, ",", false);

    items.time_stamp = tk.get_token();
    tk.next();
    items.label = tk.get_token();
    tk.next();
    items.dummy = tk.get_token();
    tk.next();
    items.value = std::stof(tk.get_token());
    tk.next();
    items.category = tk.get_token();
    

}

void Bar::show_line(){
    cout << items.time_stamp << "." << items.label << "." << items.dummy << "." << items.value << "." << items.category << "." << endl;
}

/**
 * Mudei de int para float, dps ver se não dá problema
*/
float Bar::value(){
    return items.value;
}



string Bar::category(){
    return items.category;
}

string Bar::label(){
    return items.label;
}

string Bar::time_stamp(){
    return items.time_stamp;
}