#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 12356630 // Sum(26^i) i=1,2,3,4,5
int Table[MAX];      // Use to count the apperance of the same string

int main() {
  int n, k, i, j, sum, count, left, right, prefix;
  char str[6];
  scanf("%d %d", &n, &k);
  int *INPUT = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    scanf("%s", str);
    INPUT[i] = 0;
    for (j = strlen(str) - 1; j >= 0; j--) {
      INPUT[i] = INPUT[i] * 26 + (str[j] - 'a'); // 26 Decimal
    }
  }
  count = 0;  // use to give answer
  left = 0;   // the left of window
  right = 0;  // the right of window
  sum = 0;    // count different value in window
  prefix = 0; // the number of elements front of window and has the same value
              // in the window
  for (i = 0; i < n; i++) {
    Table[INPUT[i]] = 0;
  }
  for (right = 0; right < n; right++) {
    Table[INPUT[right]]++;
    if (Table[INPUT[right]] == 1) {
      sum++; // different values
    }
    for (; sum > k || Table[INPUT[left]] > 1; Table[INPUT[left]]--, left++) {
      if (sum > k) {
        prefix =
            0; // if sum>k means the prefix now can't be the result 's prefix
        sum--;
      } else if (Table[INPUT[left]] > 1) {
        prefix++;
      }
    }
    if (sum == k) {
      count += prefix + 1; // sum==k means a window match, and the same time
                           // [prefix,window] also match
    }
  }

  printf("%d", count);
  return 0;
}
