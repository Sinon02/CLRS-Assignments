#include <stdio.h>
#include <stdlib.h>
int main() {
  int n;
  int INF = 0;
  scanf("%d", &n);
  int *A = (int *)malloc(sizeof(int) * n);
  int *P = (int *)malloc(sizeof(int) * n);
  int *M = (int *)malloc(sizeof(int) * n * n);
  int i, j, l, k;
  for (i = 0; i < n; i++) {
    scanf("%d", A + i);
    INF += A[i];
    P[i] = INF;
  }
  for (i = 0; i < n; i++) {
    *(M + n * i + i) = 0;
  }
  for (l = 2; l <= n; l++) {
    for (i = 0; i < n - l + 1; i++) {
      int j = i + l - 1;
      *(M + i * n + j) = INF+1000;
      for (k = i; k < j; k++) {
        int q =*(M + i * n + k) + *(M + (k + 1) * n + j)+(P[k]-P[i-1])+(P[j]-P[k]);
        if (q < *(M + i * n + j)) {
          *(M + i * n + j) = q;
        }
      }
    }
  }
  printf("%d",*(M+n-1));

  return 0;
}
