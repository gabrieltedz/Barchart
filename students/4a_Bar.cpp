#include "4b_Bar.h"
using namespace std;

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

    cout << items.time_stamp << "." << items.label << "." << items.dummy << "." << items.value << "." << items.category << "." << endl;
}