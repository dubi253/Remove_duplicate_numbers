#include <iostream>
#include <string>
using namespace std;
string str;
int b[255] = {0};

char get_number(string input){
    char character;
    int i = 0;
    while (!input.empty()){
        character = input.front();//提取字符串第一个字符
        input.erase(input.begin());//删除字符串第一个字符
        b[i] = character - 48;//char转int，并赋值
        i++;
    }
    return 0;
}

char Delete_duplicate_numbers(){
    get_number(str);
    for (int k = 0; k < str.length()-1; ++k) {
        for (int j = k+1; j < str.length(); ++j) {
            if (b[j] == b[k]) {
                str.erase(str.begin() + j);
                --j;
                get_number(str);
                if (str.empty()) break;
            }
        }
    }
    return 0;
}

int main(){
    while (getline(cin, str)) {
        int a[255] = {0}, sum = 0, Number_of_duplicate_numbers = 0;
        string Repeated_numbers;
        for (char i : str){
            a[i]++;
        }
        Delete_duplicate_numbers();
        for (char i : str){
            if (a[i] >= 2){
                ++Number_of_duplicate_numbers;
                Repeated_numbers = Repeated_numbers + i + " ";
                cout << i << " repeated " << a[i] << " times " << endl;
            }
        }
        if (!Repeated_numbers.empty()){
            cout << "The number of duplicate numbers is " << Number_of_duplicate_numbers << "." << "They are " << Repeated_numbers << endl;
        }else{
            cout << "There are no duplicate numbers." << endl;
        }
        for (int i = 0; i < str.length(); ++i){
            sum+=b[i];
        }
        cout << "The sum of the redundant duplicate numbers is " << sum << endl;
    }
}