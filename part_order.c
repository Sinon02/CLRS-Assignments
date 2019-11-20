#include <stdio.h>
#include <stdlib.h>
// find the longest increase path for series a1,a2,a3,...,an
// optimal substructure
// suppose n is the last element of the longest path
// L[n] = 1 + max(L[i]) i<n && a[i]<=a[n]
// for example : 1 0 2 1 3 2 5 3
// L[0]=1 L[1]=1 L[2]=2 L[3]=2 L[4]=3 L[5]=3
int main() {
  int n, i, j;
  int y1, y2, x;
  int num = 0;
  scanf("%d", &n);
  int *Y = (int *)malloc(sizeof(int) * n);
  int *L = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &x, Y + i);
  }
  L[0] = 1;
  int max_L;
  int max_result = 0;
  for (i = 1; i < n; i++) {
    max_L = 0;
    for (j = i - 1; j >= 0; j--) {
      if (Y[j] <= Y[i]) {
        int cur_L = L[j] + 1;
        if (cur_L > max_L) {
          max_L = cur_L;
        }
      }
    }
    L[i] = (max_L == 0) ? 1 : max_L;
    if (max_L > max_result) {
      max_result = max_L;
    }
  }
  printf("%d", max_result);
  return 0;
}