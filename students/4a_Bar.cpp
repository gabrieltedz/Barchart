#include "4b_Bar.h"
using namespace std;

/**
 * Function to read a line
*/
void Bar::read_line(std::istream& stream){
    Tokenizer tk; // Tokenizer to separate the line in tokens
    string input;
    getline(stream, input); // Get the line

    tk.tokens(input, ",", false); // Make tokens

    /**
     * Atribute tokens to respective items.
    */
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

/**
 * Outputs a bar, used for testing
*/
void Bar::show_line(){
    cout << items.time_stamp << "." << items.label << "." << items.dummy << "." << items.value << "." << items.category << "." << endl;
}


/*Returns the items.value*/
float Bar::value(){
    return items.value;
}


/* Returns the items.category*/
string Bar::category(){
    return items.category;
}

/* Returns the items.label*/
string Bar::label(){
    return items.label;
}

/* Returns the items.time_stamp*/
string Bar::time_stamp(){
    return items.time_stamp;
}