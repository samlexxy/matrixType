#include <iostream>
#include "matrixType.h"

using namespace std;

int main()
{
    matrixType matrix1(5, 5);
    matrixType matrix2;
    matrixType matrix3;
    matrixType matrix4;
    matrixType matrix5;
    matrixType matrix6;

    cout<<"VALUE FOR MATRIX1 : "<<endl;
    cin>>matrix1;

    cout<<"VALUE FOR MATRIX2 : "<<endl;
    cin>>matrix2;

    matrix1.printRow();

    cout<<endl<<matrix1;
    cout<<endl<<matrix2;

    matrix3 = matrix2 + matrix1;
    matrix4 = matrix2 * matrix1;
    matrix5 = matrix4 - matrix1;

    matrix6 = matrix2;

    cout<<endl<<matrix3;
    cout<<endl<<matrix4;
    cout<<endl<<matrix5;
    cout<<endl<<matrix6;

    matrixType *ptr1;
    matrixType *ptr2;

    ptr1 = &matrix2;
    ptr2 = &matrix6;

    cout<<endl<<ptr1;
    cout<<endl<<ptr2;

    return 0;
}
