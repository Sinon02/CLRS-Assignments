#include <iostream>
#include <vector>
class Bag {
public:
  int wi;
  int vi;
  int numi;
  Bag(int w, int v, int n);
};
Bag::Bag(int w, int v, int n) {
  wi = w;
  vi = v;
  numi = n;
}
int main() {
  int n, W;
  int numi, wi, vi;
  std::cin >> n >> W;
  std::vector<Bag> B;
  for (int i = 0; i < n; i++) {
    std::cin >> wi >> vi >> numi;
    B.push_back(Bag(wi, vi, numi));
  }
  int **F = new int *[n + 1];
  for (int i = 0; i <= n; i++) {
    F[i] = new int[W + 1];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= W; j++) {
      if (i == 0 || j == 0)
        F[i][j] = 0;
      else {
        int max_ = 0;
        for (int n = 0; n <= B[i - 1].numi; n++) {
          if ((B[i - 1].wi) * n > j) {
            break;
          }
          if (F[i - 1][j - B[i - 1].wi * n] + B[i - 1].vi * n > max_)
            max_ = F[i - 1][j - B[i - 1].wi * n] + B[i - 1].vi * n;
        }
        F[i][j] = max_;
      }
    }
  }
  std::cout << F[n][W] << std::endl;
  for (int i = 0; i <= n; i++) {
    delete[] F[i];
  }
  delete[] F;
  return 0;
}
