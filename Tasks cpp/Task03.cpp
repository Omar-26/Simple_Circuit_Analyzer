#include <iostream>
using namespace std;
double totalRes(string des, char connection);

int main()
{
  // Getting Circuit Description From User
  string des;
  cout << " Circuit Description : ";
  getline(cin, des);

  // Getting Voltage Applied From User
  float V;
  cout << " Voltage Applied = ";
  cin >> V;

  // Validating User Input
  bool notValidInput = false;
  for (int i = 0; i < des.length(); i++)
  {
    switch (des[i])
    {
    case 'S': case 'P': case 'e': case 'E':
    case '.': case ' ': case '0' ... '9':
    break;
    default: notValidInput = true;
    }
  }
  if (notValidInput == true)
    cout << "Wrong Circuit Description" << endl;

  // Returning Output to The User
  if (notValidInput == false)
  {
    double Req = totalRes(des, des[0]);
    cout << " Req = " << Req << " ohm" << endl;
    cout << " I = " << V / Req << " Amp" << endl;
  }
}

double totalRes(string des, char connection)
{
  double Req = 0, R;
  int childConnection = 0, digit = 0, indexFirstCon;
  // Main for Loop
  for (int i = 2; i < des.length(); i++)
  {
    // Checking for internal connections
    if (des[i] == 'S' || des[i] == 'P')
    {
      childConnection = 1;
      indexFirstCon = i;
    }

    // No internal Connection ==== > like Task 2
    if (childConnection == 0)
    {
      if (des[i] == ' ')
      {
        R = stof(des.substr(i - digit, digit));
        switch (des[0])
        {
        case 'S':
          Req += R;
          break;
        case 'P':
          Req += 1 / R;
          break;
        }
        digit = -1;
      }
      digit++;
    }

    // There is Internal Connection ==== > Task 3
    if (childConnection == 1)
    {
      if (des[i] == 'e')
      {
        string branch = des.substr(indexFirstCon, i - indexFirstCon + 1);
        R = totalRes(branch, branch[0]);
        switch (connection)
        {
        case 'S':
          Req += R;
          break;
        case 'P':
          Req += 1 / R;
          break;
        }
        childConnection = 0;
        i++;
      }
    }
  }
  // Giving The Results to the user
  switch (connection)
  {
  case 'S':
  case 's':
    return Req;
  case 'P':
  case 'p':
    return 1 / Req;
  }
  return 0;
}