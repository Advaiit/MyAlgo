//Calculate power in O(log n) time
#include <iostream>
using namespace std;


float pow(float x, int y)
{
    if(!y)
        return 1;
    if(y % 2 == 0)
    {
        return pow(x, y/2) * pow(x, y/2);
    }
    else
    {
        if(y > 0)
        {
            return x * pow(x, y/2) * pow(x, y/2);
        }
        else
        {
            return (pow(x, y/2) * pow(x, y/2))/x;
        }
    }
}

int main()
{
    cout<<"5.0 ^ 5: \n";
    cout<<pow(5.0, 5)<<"\n";

    return 0;
}