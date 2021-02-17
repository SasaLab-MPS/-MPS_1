#include <bits/stdc++.h>
#include "Eigen/Dense"  // Denseにたいていのモジュールが入っている
using namespace std;
using namespace Eigen;

#define N 10
#define TMAX 100
#define EPS (1.0e-6)

void CG_method(MatrixXd A, VectorXd b, VectorXd x) {
    VectorXd p, r, Ax, Ap;

    // Axを計算
    Ax = A*x;

    // pとrを計算 p = r := b - Ax
    p = b - Ax;
    r = p;

    // 反復計算
    for(int i = 0; i < TMAX; i++) {
        double alpha, beta, error = 0;

        // alphaを計算
        Ap = A*p;
        alpha = p.dot(r)/p.dot(Ap);

        x += alpha*p;
        r -= alpha*Ap;

        error = r.norm();

        if (error < EPS)
        {
            break;
        }
        else
        {
            // betaの計算
            beta = - r.dot(Ap)/p.dot(Ap);
        }

        p = r + beta*p;        
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    MatrixXd M;     // MatrixXd:動的配列の行列
    M << 5.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
         2.0, 5.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
         0.0, 2.0, 5.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 2.0, 5.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 0.0, 2.0, 5.0, 2.0, 0.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 0.0, 0.0, 2.0, 5.0, 2.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 5.0, 2.0, 0.0, 0.0,
         0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 5.0, 2.0, 0.0,
         0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 5.0, 2.0,
         0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 5.0;

    VectorXd b, x;  // 行ベクトル
    b << 3.0, 1.0, 4.0, 0.0, 5.0, -1.0, 6.0, -2.0, 7.0, -15.0;
    x << 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0;

    CG_method(M, b, x);

    cout << x << endl;

    return 0;
}
