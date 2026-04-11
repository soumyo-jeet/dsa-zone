#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

void MM(int A[32][32], int B[32][32], int C[32][32],
       int iA, int jA, int iB, int jB, int iC, int jC, int s)
{
    if (s == 1){
        C[iC][jC] += A[iA][jA] * B[iB][jB];
        return;
    }

    int k = s / 2;

    // C00 = A00 * B00 + A01 * B10
    MM(A, B, C, iA, jA, iB, jB, iC, jC, k);
    MM(A, B, C, iA, jA + k, iB + k, jB, iC, jC, k);

    // C01 = A00 * B01 + A01 * B11
    MM(A, B, C, iA, jA, iB, jB + k, iC, jC + k, k);
    MM(A, B, C, iA, jA + k, iB + k, jB + k, iC, jC + k, k);

    // C10 = A10 * B00 + A11 * B10
    MM(A, B, C, iA + k, jA, iB, jB, iC + k, jC, k);
    MM(A, B, C, iA + k, jA + k, iB + k, jB, iC + k, jC, k);

    // C11 = A10 * B01 + A11 * B11
    MM(A, B, C, iA + k, jA, iB, jB + k, iC + k, jC + k, k);
    MM(A, B, C, iA + k, jA + k, iB + k, jB + k, iC + k, jC + k, k);
}


void add(int n, int A[32][32], int B[32][32], int C[32][32]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void sub(int n, int A[32][32], int B[32][32], int C[32][32]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int s, int A[32][32], int B[32][32], int C[32][32]) {
    if(s == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int A00 [32][32], A01 [32][32], A10 [32][32], A11 [32][32],
    B00 [32][32], B01 [32][32], B10 [32][32], B11 [32][32],
    C00 [32][32], C01 [32][32], C10 [32][32], C11 [32][32],

    P[32][32], Q[32][32], R[32][32], S[32][32], T[32][32], U[32][32], V[32][32],

    T1[32][32], T2[32][32];

    int k = s / 2;

    // matrices formation
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            A00[i][j] = A[i][j];
            A01[i][j] = A[i][j + k];
            A10[i][j] = A[i + k][j];
            A11[i][j] = A[i + k][j + k];

            B00[i][j] = B[i][j];
            B01[i][j] = B[i][j + k];
            B10[i][j] = B[i + k][j];
            B11[i][j] = B[i + k][j + k];
        }
    }

    // P = (A00 + A11)(B00 + B11)
    add(k, A00, A11, T1);
    add(k, B00, B11, T2);
    strassen(k, T1, T2, P);

    // Q = (A10 + A11)(B00)
    add(k, A10, A11, T1);
    strassen(k, T1, B00, Q);

    // R = (A00)(B01 - B11)
    sub(k, B01, B11, T1);
    strassen(k, A00, T1, R);

    // S = (A11)(B10 - B00)
    sub(k, B10, B00, T1);
    strassen(k, A11, T1, S);

    // T = (A00 + A01)(B11)
    add(k, A00, A01, T1);
    strassen(k, T1, B11, T);

    // U = (A10 - A00)(B00 + B01)
    sub(k, A10, A00, T1);
    add(k, B00, B01, T2);
    strassen(k, T1, T2, U);

    // V = (A01 - A11)(B10 + B11)
    sub(k, A01, A11, T1);
    add(k, B10, B11, T2);
    strassen(k, T1, T2, V);

    // C00 = P + S - T + V
    add(k, P, S, T1);
    sub(k, T1, T, T2);
    add(k, T2, V, C00);

    // C01 = R + T
    add(k, R, T, C01);

    // C10 = Q + S
    add(k, Q, S, C10);

    // C11 = P - Q + R + U
    add(k, P, R, T1);
    sub(k, T1, Q, T2);
    add(k, T2, U, C11);

    // Combine result
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            C[i][j] = C00[i][j];
            C[i][j + k] = C01[i][j];
            C[i + k][j] = C10[i][j];
            C[i + k][j + k] = C11[i][j];
        }
    }
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int A[32][32], B[32][32], C[32][32] = {0}, C_[32][32];
    cout << "Enter matrix A: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "\nEnter matrix B: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j];
        }
    }

    MM(A, B, C, 0, 0, 0, 0, 0 , 0, n);

    cout << "\nOutput matrix C: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    strassen(n, A, B, C_);
    cout << "\nOutput matrix C_: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << C_[i][j] << " ";
        }
        cout << endl;
    }
}