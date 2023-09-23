#include <stdio.h>

// calculates the min, max sum of consecutive array elements

int main()
{
  int n, p = 3;
  printf("enter size: ");
  scanf("%d", &n);
  int arr[n];

  printf("enter elements: \n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int p1 = 0, p2 = p, maxSum = 0, minSum = 0, tempSumMax, tempSumMin;

  for (int i = 0; i < p; i++)
  {
    maxSum = maxSum + arr[i];
    minSum = minSum + arr[i];
  }
  tempSumMax = maxSum;
  tempSumMin = minSum;

  while (p2 < n)
  {
    tempSumMax = tempSumMax - arr[p1] + arr[p2];
    tempSumMin = tempSumMin - arr[p2] + arr[p1];
    if (tempSumMax > maxSum)
    {
      maxSum = tempSumMax;
    }
    else if (tempSumMin < minSum)
    {
      minSum = tempSumMin;
    }

    p1++;
    p2++;
  }
  printf("max: %d\nmin: %d", maxSum, minSum);
}