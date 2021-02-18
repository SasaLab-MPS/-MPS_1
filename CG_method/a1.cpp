#include <bits/stdc++.h>
#include "Eigen/Dense"  // Denseにたいていのモジュールが入っている
using namespace std;
using namespace Eigen;

#define N 10
#define TMAX 100
#define EPS (1.0e-6)

int main(int argc, char const *argv[])
{
    /* code */
    cout << "call l50" << endl;
    MatrixXd A(N, N);     // MatrixXd:動的配列の行列
    A << 5.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
    2.0, 5.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
    0.0,2.0, 5.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
    0.0, 0.0, 2.0, 5.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
    0.0, 0.0, 0.0, 2.0, 5.0, 2.0, 0.0, 0.0, 0.0, 0.0, 
    0.0, 0.0, 0.0, 0.0, 2.0, 5.0, 2.0, 0.0, 0.0, 0.0, 
    0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 5.0, 2.0, 0.0, 0.0, 
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 5.0, 2.0, 0.0, 
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 5.0, 2.0, 
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 5.0;

    cout << "call l62" << endl;

    //cout << M << endl;

    VectorXd b(N), x(N);  // 行ベクトル
    b << 3.0, 1.0, 4.0, 0.0, 5.0, -1.0, 6.0, -2.0, 7.0, -15.0;
    x << 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0;

    // cout << b << endl;

    /* CG_Method */
    VectorXd p(N), r(N), Ax(N), Ap(N);

    // Axを計算
    Ax = A * x;

    // pとrを計算 p = r := b - Ax
    p = b - Ax;
    r = p;

    // 反復計算
    for (int i = 0; i < TMAX; i++)
    {
        double alpha, beta, error = 0;

        // alphaを計算
        Ap = A * p;
        alpha = p.dot(r) / p.dot(Ap);

        x += alpha * p;
        r -= alpha * Ap;

        error = r.norm();

        if (error < EPS)
        {
            break;
        }
        else
        {
            // betaの計算
            beta = -r.dot(Ap) / p.dot(Ap);
        }

        p = r + beta * p;
    }

    cout << x << endl;

    return 0;
}
