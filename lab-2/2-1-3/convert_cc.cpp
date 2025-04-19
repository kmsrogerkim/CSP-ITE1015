#include <iostream>
#include <string>
using namespace std;

void convert_case(string& a){
    for (int i = 0; i < a.size(); i++){
        int ascii_num = int(char(a[i]));

        if (ascii_num >= 97){
            a[i] = char(ascii_num - 32);
        }
        else{
            a[i] = char(ascii_num + 32);
        }
    }
}

int main(){
    string input;

    while (true){
        cin >> input;

        if (input == "exit"){
            return 0;
        }

        for (int i = 0; i < input.size(); i++){
            char character = input[i];
            int ascii_num = int (character);
            if (ascii_num < 65 || ascii_num > 122 || (ascii_num > 90 && ascii_num < 65)) {
                cout << "Error: Wrong input!" << endl;
                return 0;
            }
        }

        convert_case(input);

        cout << input << endl;
    }

    return 0;
}
