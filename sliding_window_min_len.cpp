#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int arr[15] = {2, 3, 1, 2, 4, 3};
  int size = 6, maxSum = 7, p1 = 0, p2, n = size, tempSum = 0; //set the max sum as 7

  for (p2 = 0; p2 < size; p2++)
  {
    tempSum = tempSum + arr[p2];

    if (tempSum >= 7)
    {
      n = min(p2 - p1 + 1, n);
      tempSum = tempSum - arr[p1];
      p1++;
    }
  }
  cout << "min length: " << n << endl;
  return 0;
}