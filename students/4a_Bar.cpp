#include "4b_Bar.h"
using namespace std;

void Bar::read_line(){
    Tokenizer tk;
    string input = "1500,Beijing,China,672,East Asia";
    vector<string> list;
    // getline(cin, input);
    tk.tokens(input, ",", false);

    list = tk.get_tokens_list();

    for (int i = 0; i < list.size(); i++){
        cout << list[i] << ".";
    } cout << endl;

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