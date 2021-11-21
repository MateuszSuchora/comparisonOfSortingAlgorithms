#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

void RadixSort(int z1[], int z2[], int m)
{
  int L[2],i;

  L[0] = L[1] = 0;
  for(i = 1; i <= N; i++) L[(z1[i] & m) > 0]++;
  L[1] += L[0];
  for(i = N; i >= 1; i--) z2[L[(z1[i] & m) > 0]--] = z1[i];
}
int main()
{

  return 0;
}
