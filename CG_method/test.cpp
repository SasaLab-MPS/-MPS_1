#include <bits/stdc++.h>
#include "Eigen/Dense"
using namespace Eigen;
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    Matrix3f A;
    Vector3f b;
    A << 1,2,3, 4,5,6, 7,8,9;
    b << 1,3,5;

    cout << "Here is the matrix A:\n" << A << endl;
    cout << "Here is the vector b:\n"<< b << endl;
    
    return 0;
}
