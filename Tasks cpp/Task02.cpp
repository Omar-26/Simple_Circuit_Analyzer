#include <iostream>
using namespace std;
int main()
{
    // Getting Circuit Description From User
    float R, P = 0, S = 0;

    string D;
    cout << " Circuit Description : ";
    getline(cin, D);

    // Getting Voltage Applied From User
    float V;
    cout << " Voltage Applied = ";
    cin >> V;

    int digit = 0;
    for (int i = 2; D[i] != 'E' && D[i] != 'e' ; i++)
    {
        if (D[i] == ' ')
        {
            R = stof(D.substr(i - digit, digit));
            S += R;
            P += 1 / (R);
            digit = -1;
        }
        digit++;
    }
    // Giving The Results to the user
    switch (D[0])
    {
    case 'S':
    case 's':
        cout << " Req = " << S << " ohm" << endl
             << " I = " << V / S << " Amp";
        break;
    case 'P':
    case 'p':
        cout << " Req = " << 1 / P << " ohm" << endl
             << " I = " << V * P << " Amp";
        break;
    default:
        cout << "Wrong Circuit Description";
    }
}