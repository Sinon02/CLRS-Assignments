#include <stdio.h>
#include <stdlib.h>
/*typedef struct Coord {
  int x;
  int y;
} Coord;
int Judge(Coord a, Coord b) {
  if (a.x <= b.x && a.y <= b.y)
    return 1;
  else
    return 0;
}
int Part_Order(Coord a, Coord b) {
  if (Judge(a, b) || Judge(b, a)) {
    return 0;
  } else {
    return 1;
  }
}
int main() {
  int i, n;
  int max, max_num, num = 0;
  Coord a, b;
  scanf("%d", &n);
  scanf("%d %d", &a.x, &a.y);
  b = a;
  for (i = 1; i < n; i++) {
    scanf("%d %d", &a.x, &a.y);
    if (Judge(b, a)) {
      num++;
      max = a.y;
      max_num = num;
    } else {
      num = 0;
    }
  }
}*/

int main() {
  int n, i, j;
  int y1, y2, x;
  int num = 0;
  int *Y = (int *)malloc(sizeof(int) * n);
  int *Mark = (int *)malloc(sizeof(int) * n);
  scanf("%d", &n);
  scanf("%d %d", &x, &y2);
  y1 = y2;
  Y[0] = y2;
  for (i = 1; i < n; i++) {
    scanf("%d %d", &x, &y2);
    if (y1 <= y2) {
      num++;
    }
    y1 = y2;
    Mark[i] = 1;
    Y[i] = y2;
  }
  int max_num = num;
  int max_min = Y[0];
  for (i = 1; i < n; i++) {
    y1 = Y[i];
    num = 0;
    for (j = i; j < n; j++) {
      if (Mark[j] != 1) {
        y2 = Y[j];
        if (y1 <= y2) {
          num++;
        }
        Mark[j] = 1;
        y1 = y2;
      }
    }
  }
}