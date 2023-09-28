#include "4b_Bar.h"
using namespace std;

/**
 * Function to read a line ang get it's corresponding bar
*/
void Bar::read_line(){
    Tokenizer tk;
    string input;
    getline(cin, input);

    tk.tokens(input, ",", false);

    items.time_stamp = tk.get_token();
    tk.next();
    items.label = tk.get_token();
    tk.next();
    items.dummy = tk.get_token();
    tk.next();
    items.value = stoi(tk.get_token());
    tk.next();
    items.category = tk.get_token();

}

void Bar::show_line(){
    cout << items.time_stamp << "." << items.label << "." << items.dummy << "." << items.value << "." << items.category << "." << endl;
}

int Bar::value(){
    return items.value;
}