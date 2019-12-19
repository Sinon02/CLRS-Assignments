#include <iostream>
#include <string>
#include <vector>
int* COMPUTE_PREFIX(std::string& P)
{
    int m = P.length();
    int* PI = new int[m + 1];
    PI[1] = 0;
    int k = 0;
    for (int q = 2; q <= m; q++)
    {
        while (k > 0 && P[k] != P[q - 1])
        {
            k = PI[k];
        }
        if (P[k] == P[q - 1])
        {
            k++;
        }
        PI[q] = k;
    }
    return PI;
}
int KMP_MATCHER(std::string& S, std::string& P)
{
    int number = 0;
    int n = S.length();
    int m = P.length();
    int* PI = COMPUTE_PREFIX(P);
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        while (q > 0 && P[q] != S[i])
        {
            q = PI[q];
        }
        if (P[q] == S[i])
        {
            q++;
        }
        if (q == m)
        {
            number++;
            q = PI[q];
        }
    }
    return number;
}
int main()
{
    int T;
    std::cin >> T;
    getchar();
    std::string S;
    std::string P;
    for (int i = 0; i < 2 * T; i++)
    {
        if (i % 2 == 0)
        {
            std::getline(std::cin, P);
        }
        else
        {
            std::getline(std::cin, S);
            std::cout << KMP_MATCHER(S, P) << std::endl;
            S.clear();
            P.clear();
        }
    }
    return 0;
}