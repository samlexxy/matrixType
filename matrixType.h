//
// Created by samlexxy on 30/03/2020.
//

#ifndef PROJECT7_MATRIXTYPE_H
#define PROJECT7_MATRIXTYPE_H

#include <iostream>

using namespace std;

class matrixType {
    friend ostream& operator<<(ostream&, const matrixType&);
    friend istream& operator>>(istream&, matrixType&);

public:
    void getRow(int) const;
    void printRow() const;
    void getColumn(int) const;
    matrixType();
    matrixType(int r, int c);
    ~matrixType();
    matrixType(const matrixType&);

    matrixType operator+(const matrixType&) const;
    matrixType operator-(const matrixType&) const;
    matrixType operator*(const matrixType&) const;

    const matrixType& operator=(const matrixType&);

private:
    int rowMatrix;
    int columnMatrix;
    int rowLength;
    int columnLength;
    int **list;
};


#endif //PROJECT7_MATRIXTYPE_H
