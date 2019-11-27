#include <stdio.h>
#include <stdlib.h>
int global_time = 0;
int result = 0;
typedef struct Task {
  int arrive_time;
  int continue_time;
  int remain_time;
} Task;
void swap(Task *T, int i, int j) {
  Task temp;
  temp = T[i];
  T[i] = T[j];
  T[j] = temp;
}
int Partition(Task *T, int p, int r) {
  int x, i, j;
  i = p;
  x = T[r].arrive_time;
  for (j = p; j < r; j++) {
    if (T[j].arrive_time <= x) {
      swap(T, i, j);
      i = i + 1;
    }
  }
  swap(T, i, r);
  return i;
}
int RandomPartition(Task *T, int p, int r) {
  int n = r - p + 1;
  int rdm = rand() % n;
  swap(T, p + rdm, r);
  return Partition(T, p, r);
}
void QuickSort(Task *T, int p, int r) {
  int q = 0;
  if (p < r) {
    q = RandomPartition(T, p, r);
    QuickSort(T, p, q - 1);
    QuickSort(T, q + 1, r);
  }
}
void RunTask(Task *T, int index, int N) // it may be a recursive function, exec
                                        // a task until it need switch
{
  if (T[index].remain_time == 0)
    return;
  int next_task = index + 1;
  while (T[index].remain_time > 0) {
    if (next_task >= N || //no more tasks to arrive
        global_time + T[index].remain_time <= T[next_task].arrive_time) {// task can be exec directly
      global_time += T[index].remain_time;
      T[index].remain_time = 0;
      break;
    } else if(global_time>T[next_task].arrive_time)
    {//just do nothing(this case is when come back from recursion)
    } else{// have tasks to arrive
      T[index].remain_time -= T[next_task].arrive_time - global_time;
      global_time = T[next_task].arrive_time;
      }
      if (T[next_task].remain_time < T[index].remain_time) {
        RunTask(T, next_task, N);
        next_task++;
      } else {
        next_task++;
      }
    }
  result += global_time - T[index].arrive_time;
}
int main() {
  int N;
  scanf("%d", &N);
  Task *T = (Task *)malloc(sizeof(Task) * N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &(T[i].arrive_time), &(T[i].continue_time));
    T[i].remain_time = T[i].continue_time;
  }
  QuickSort(T, 0, N - 1); // sorted by the arrived time
  for (int i = 0; i < N; i++) {
    global_time = (global_time>T[i].arrive_time)?global_time:T[i].arrive_time;
    RunTask(T, i, N);
  }
  printf("%d", result);
  free(T);
  system("pause");
  return 0;
}