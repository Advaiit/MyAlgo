#include <iostream>
#include <string.h>

using namespace std;

bool isNum(char c){
    return c >= 48 && c <= 57;
}

int parseAndAdd(string s) {
    if(!s.size()) return 0;

    int startIndex = -1, endLen = 0;
    int temp = 0;

    for(int i = 0; i < s.size(); i++) {
        if(isNum(s[i])) {
            if(startIndex == -1) {
                startIndex = i;
                endLen = 1;
            }
            else { endLen++;}
        }
        else {
            if(startIndex != -1) {
                temp += stoi(s.substr(startIndex, endLen));
                cout<<startIndex<<"\n"<<endLen<<"\n--------\n";
                startIndex = -1;
                endLen = 0;
            }
        }
    }

    if(startIndex != -1)
        temp += stoi(s.substr(startIndex, endLen));

    return temp;
}

int main(){

    //string s = "100klh564abc365bg";
    cout<<parseAndAdd(string("100klh564abc365bg"));

    return 0;
}