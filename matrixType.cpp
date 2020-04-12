//
// Created by samlexxy on 30/03/2020.
//

#include <iostream>
#include "matrixType.h"

using namespace std;

void matrixType::getRow(int r) const
{
    int column;

    for (column = 0; column < columnLength; column++)
    {
        cout<<list[r][column]<<" ";
    }
}

void matrixType::printRow() const
{
    cout<<"Number of Row is : "<<rowMatrix;
}

void matrixType::getColumn(int c) const
{
    int row;

    for (row = 0; row < rowLength; row++)
    {
        cout<<list[row][c]<<" ";
    }
}

matrixType::matrixType()
{
    rowMatrix = 5;
    columnMatrix = 5;
    rowLength = 0;
    columnLength = 0;

    list = new int* [rowMatrix];

    for (int row = 0; row < rowMatrix; row++)
    {
        list[row] = new int [columnMatrix];
    }

    for (int row = 0; row < rowMatrix; row++)
    {
        for (int col = 0; col < columnMatrix; col++)
        {
            list[row][col] = 0;
        }
    }
}

matrixType::matrixType(int r, int c)
{
    rowMatrix = r;
    columnMatrix = c;
    rowLength = 0;
    columnLength = 0;

    list = new int* [rowMatrix];

    for (int row = 0; row < rowMatrix; row++)
    {
        list[row] = new int [columnMatrix];
    }

    for (int row = 0; row < rowMatrix; row++)
    {
        for (int col = 0; col < columnMatrix; col++)
        {
            list[row][col] = 0;
        }
    }
}

matrixType::~matrixType()
{
    delete [] list;
}

matrixType::matrixType(const matrixType& otherMatrix)
{
    rowMatrix = otherMatrix.rowMatrix;
    columnMatrix = otherMatrix.columnMatrix;
    rowLength = otherMatrix.rowLength;
    columnLength = otherMatrix.columnLength;

    for (int row = 0; row < rowMatrix; row++)
    {
        for (int col = 0; col < columnMatrix; col++)
        {
            list[row][col] = otherMatrix.list[row][col];
        }
    }
}

matrixType matrixType::operator+(const matrixType& otherMatrix) const
{
    matrixType temp(rowMatrix, columnMatrix);

    for (int row = 0; row < rowMatrix; row++)
    {
        for (int col = 0; col < columnMatrix; col++)
        {
            temp.list[row][col] = list[row][col] + otherMatrix.list[row][col];
        }
    }

    return temp;
}

matrixType matrixType::operator-(const matrixType& otherMatrix) const
{
    matrixType temp(rowMatrix, columnMatrix);

    for (int row = 0; row < rowMatrix; row++)
    {
        for (int col = 0; col < columnMatrix; col++)
        {
            temp.list[row][col] = list[row][col] - otherMatrix.list[row][col];
        }
    }

    return temp;
}

matrixType matrixType::operator*(const matrixType& otherMatrix) const
{
    matrixType temp(rowMatrix, columnMatrix);

    for (int row = 0; row < rowMatrix; row++)
    {
        for (int col = 0; col < columnMatrix; col++)
        {
            temp.list[row][col] = list[row][col] * otherMatrix.list[row][col];
        }
    }

    return temp;
}

const matrixType& matrixType::operator=(const matrixType& otherMatrix)
{
    if (this != &otherMatrix)
    {
        rowMatrix = otherMatrix.rowMatrix;
        columnMatrix = otherMatrix.columnMatrix;
        rowLength = otherMatrix.rowLength;
        columnLength = otherMatrix.columnLength;

        delete [] list;

        list = new int* [rowMatrix];

        for (int row = 0; row < rowMatrix; row++)
        {
            list[row] = new int [columnMatrix];
        }

        for (int row = 0; row < rowMatrix; row++)
        {
            for (int col = 0; col < columnMatrix; col++)
            {
                list[row][col] = otherMatrix.list[row][col];
            }
        }
    }

    return *this;

}

ostream& operator<<(ostream& outp, const matrixType& otherMatrix)
{
    for (int row = 0; row < otherMatrix.rowMatrix; row++)
    {
        for (int col = 0; col < otherMatrix.columnMatrix; col++)
        {
            outp<<otherMatrix.list[row][col]<<" ";
        }
        outp<<endl;
    }

    return outp;
}

istream& operator>>(istream& inp, matrixType& otherMatrix)
{
    for (int row = 0; row < otherMatrix.rowMatrix; row++)
    {
        cout<<"Entering value for "<<row + 1<< " Row : ";
        for (int col = 0; col < otherMatrix.columnMatrix; col++)
        {
            inp>>otherMatrix.list[row][col];
            otherMatrix.columnLength++;
        }
        otherMatrix.rowLength++;
    }

    return inp;
}
