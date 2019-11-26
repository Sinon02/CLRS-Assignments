#include <stdio.h>
#include <stdlib.h>
void swap(int *A, int i, int j) {
  int temp;
  temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}
int Partition(int *A, int p, int r) {
  int x, i, j;
  i = p;
  x = A[r];
  for (j = p; j < r; j++) {
    if (A[j] <= x) {
      swap(A, i, j);
      i = i + 1;
    }
  }
  swap(A, i, r);
  return i;
}
int RandomPartition(int *A, int p, int r) {
  int n = r - p + 1;
  int rdm = rand() % n;
  swap(A, p + rdm, r);
  return Partition(A, p, r);
}
void QuickSort(int *A, int p, int r) {
  int q = 0;
  if (p < r) {
    q = RandomPartition(A, p, r);
    QuickSort(A, p, q - 1);
    QuickSort(A, q + 1, r);
  }
}
int main() {
  int N, R;
  scanf("%d %d", &N, &R);
  int *Village = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    scanf("%d", Village + i);
  }
  QuickSort(Village, 0, N - 1);
  int num=0;
  for (int i = 0; i < N;) {
    int j,k;
    for (j = 0; j<N&&Village[j] - Village[i] <=R; j++)
      ;
    for (k = j; k<N&&Village[k] - Village[j - 1] <= R; k++)
      ;
    i=k;
    num++;
   }
  printf("%d", num);
  return 0;
}