#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    // Getting Circuit Description From User
    string str;
    cout << " Circuit Description : ";
    getline(cin, str);
    // Getting Voltage Applied From User
    float V;
    cout << " Voltage Applied : ";
    cin >> V;

    float
        R1 = stof(str.substr(2, 1)),
        R2 = stof(str.substr(4, 1)),
        R3 = stof(str.substr(6, 1)),
        S = (R1 + R2 + R3),
        P = pow(((1 / R1) + (1 / R2) + (1 / R3)), -1),
        R = (str[0] == 'S') ? S : P,
        I = (V) / (R);
    // Giving Results to the User
    cout << " The Total Resistance is " << R << " Ohm\n"
         << "The Value of the Current is " << I << " Amp";

    return 0;
}