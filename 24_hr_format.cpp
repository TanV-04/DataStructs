#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
  int hour, minutes, sec;
  char c1, c2;

  cout << "enter time in hh mm ssAM/PM format: " << endl;
  cin >> hour >> minutes >> sec >> c1 >> c2;

  if ((c1 == 'P' || c1 == 'p') && hour == 12)
  {

    cout << "time in 24 hr format is: " << hour << ":" << minutes << ":" << sec << c1 << c2;
  }
  else if ((c1 == 'P' || c1 == 'p') && hour != 12)
  {
    hour = hour + 12;
    cout << "time in 24 hr format is: " << hour << ":" << minutes << ":" << sec << c1 << c2;
  }
  else if (c1 == 'A' || c1 == 'a')
  {
    if (hour == 12)
    {
      cout << "time in 24 hr format is: "
           << "00"
           << ":" << minutes << ":" << sec << c1 << c2;
    }
    else
    {
      cout << "time in 24 hr format is: " << hour << ":" << minutes << ":" << sec << c1 << c2;
    }
  }
}