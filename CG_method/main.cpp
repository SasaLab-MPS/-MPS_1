/*==================================================*/
// CG法テストプログラム
/*==================================================*/

#include <bits/stdc++.h>
using namespace std;

#define N 10
#define iMAX 100
#define EPS 1e-8

typedef vector<vector<double> > matrix;     // 行列
typedef vector<double> vec;                 // ベクトル

vec p;      // 探索方向ベクトル
vec r;      // 残差ベクトル
vec Ax;     // 行列とベクトルの積，Ax
vec Ap;     // 行列とベクトルの積，Ap

// n行m列の行列を生成
void strMatrix(matrix A, int n, int m) {
    A.resize(n);
    for(int i = 0; i < m; i++) {
        A[i].resize(m);
    }
}

// ベクトルと行列の積 Ax = y
void vector_x_matrix(matrix A, vec x, vec y) {
    double ans;
    for(int i = 0; i < A.size(); i++) {
        ans = 0;
        for(int j = 0; j < A[i].size(); j++) {
            ans += A[i][j]*x[j];
        }
        y[i] = ans;
        // printf("call vxm Ax[i] : %lf \n", y[i]);
    }
} 

// 内積を計算
double dot_product(vec a, vec b) {
    double ans = 0;
    for(int i = 0; i < a.size(); i++) {
        ans += a[i]*b[i];
    }
    return ans;
}

// ベクトルノルムを計算
double vector_norm(vec a) {
    double norm = 0;
    for(int i = 0; i < a.size(); i++) {
        norm += fabs(a[i]);
    }
    return norm;
}

// 共役勾配法，CG法
void CG_method(matrix A, vec x, vec b) {
    int Sz = x.size();
    p.resize(Sz);
    r.resize(Sz);
    Ax.resize(Sz);
    Ap.resize(Sz);

    // Axの計算
    vector_x_matrix(A, x, Ax);

    for(int i = 0; i < Ax.size(); i++) {
        printf("Ax[i] : %lf \n", Ax[i]);
    }
   
    // p, rを計算 p = r = b-Ax
    for(int i = 0; i < b.size(); i++) {
        p[i] = b[i] - Ax[i];
        r[i] = p[i];
    }

    // 反復計算
    for(int i = 0; i < iMAX; i++) {
       double alpha, beta, error = 0;

       // alphaの計算
       vector_x_matrix(A, p, Ap);
        alpha = dot_product(p, r)/dot_product(p, Ap);

        // x, rの更新
        for(int i = 0; i < x.size(); i++) {
            x[i] += alpha*p[i];
            r[i] -= alpha*Ap[i];
        }

        error = vector_norm(r); // 誤差の計算
        //printf("LOOP : %d\t Error : %g\n", i, error);

        // 終了条件
        if (error < EPS)
        {
            break;
        } else
        {
            beta = -dot_product(r, Ap)/dot_product(p, Ap);
        }

        // pの更新
        for(int i = 0; i < p.size(); i++) {
            p[i] = r[i]+beta*p[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    matrix A;
    strMatrix(A, N, N);     // N行正方行列を生成
    A = {{5.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
         {2.0, 5.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
         {0.0, 2.0, 5.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
         {0.0, 0.0, 2.0, 5.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0},
         {0.0, 0.0, 0.0, 2.0, 5.0, 2.0, 0.0, 0.0, 0.0, 0.0},
         {0.0, 0.0, 0.0, 0.0, 2.0, 5.0, 2.0, 0.0, 0.0, 0.0},
         {0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 5.0, 2.0, 0.0, 0.0},
         {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 5.0, 2.0, 0.0},
         {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 5.0, 2.0},
         {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 5.0}};

    printf("size A %d \n", A.size());
    vec b = {3.0, 1.0, 4.0, 0.0, 5.0, -1.0, 6.0, -2.0, 7.0, -15.0};
    // 初期値は適当
    vec x = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};

    // CG法 Ax = bを解く
    CG_method(A, x, b);

    printf("###Calc End.###\n");
    for (int i = 0; i < x.size(); i++)
    {
        printf("x[%d] = %2g\n", i, x[i]);
    }

    return 0;
}
