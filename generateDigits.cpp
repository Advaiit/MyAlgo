#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Digits
{
    inline char numToChar(int num) {
        return (char) num + 48;
    }

    void generateDigitsUtil(string &currentString, int n, vector<string> &result);

public:
    vector<string> generateDigits(int n);
};

vector<string> Digits::generateDigits(int n) {
    vector<string> result;

    if(!n) return result;

    string currentString;

    generateDigitsUtil(currentString, n, result);

    cout<<"Size: "<<result.size()<<" Result: \n";
    for(int i = 0; i < result.size(); i++) {
        cout<<result[i]<<endl;
    }

    return result;
}

void Digits::generateDigitsUtil(string &currentString, int n, vector<string> &result)
{
    if(currentString.size() == n) {
        result.push_back(currentString);
        return;
    }

    for(int i = n; i >= 1; i--) {
        currentString += numToChar(i);
        generateDigitsUtil(currentString, n, result);
        currentString.pop_back();
    }
}

int main()
{
    Digits d;
    d.generateDigits(3);
    return 0;
}