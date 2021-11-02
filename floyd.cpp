#define INF 99999
#include <iostream>
using namespace std;

int ex[5][5] = {
    {0, 1, INF, 1, 5},
    {9, 0, 3, 2, INF},
    {INF, INF, 0, 4, INF},
    {INF, INF, 2, 0, 3},
    {3, INF, INF, INF, 0}};

int **D;
int **P;

void floyd2(int n, int W[][5])
{
    D = new int *[n];
    for (int i = 0; i < n; i++)
    {
        *(D + i) = new int[n];
        for (int j = 0; j < n; j++)
        {
            D[i][j] = W[i][j];
        }
    }

    P = new int *[n];
    for (int i = 0; i < n; i++)
    {
        *(P + i) = new int[n];
        for (int j = 0; j < n; j++)
        {
            P[i][j] = 0;
        }
    }

    int i, j, k;

    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (D[i - 1][j - 1] > D[i - 1][k - 1] + D[k - 1][j - 1])
                {
                    P[i - 1][j - 1] = k;
                    D[i - 1][j - 1] = D[i - 1][k - 1] + D[k - 1][j - 1];
                }
            }
        }
    }
}
void printMat(int **M)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{

    floyd2(5, ex);
    cout << "print D" << endl;
    printMat(D);
    cout << endl;
    cout << "print P" << endl;
    printMat(P);
}