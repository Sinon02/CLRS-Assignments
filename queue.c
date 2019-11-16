#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 12356630
int Table[MAX];

int main() {
  int n, k, i, j, sum, count, left,right;
  char str[6];
  scanf("%d %d", &n, &k);
  int *INPUT = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    scanf("%s", str);
    INPUT[i] = 0;
    for (j = strlen(str) - 1; j >= 0; j--) {
      INPUT[i] = INPUT[i] * 26 + (str[j] - 'a');
    }
  }
  count = 0;
  left = 0;
  right = 0;
  for (right = 0; right < n; right++) {
      sum = 0;
      for (j = 0; j < i; j++) {
        if (Table[INPUT[j]] == 0) {
          sum++;
        }
        Table[INPUT[j]]++;
      }
      if (sum == k) {
        count++;
      }
      for (j = i; j < n; j++) // n=4 k=2 j=[0,1] [1,2] [2,3]
      {
        if (Table[INPUT[j - i]] <= 1) {
          sum--;
        }
        Table[INPUT[j - i]]--;
        if (Table[INPUT[j]] < 1) {
          sum++;
        }
        Table[INPUT[j]]++;
        if (sum == k) {
          count++;
        }
      }
      for (j=n-1; j >= n - i;j--)
      {
        Table[INPUT[j]] = 0;
      }
    }


  printf("%d", count);
  return 0;
}