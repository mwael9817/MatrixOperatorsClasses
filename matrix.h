#ifndef MATRIX_H
#define MATRIX_H


#include <iostream>
using namespace std ;

class Matrix
{
private:
	/*Attributes*/
    int row,column;
	int **matrix;
	//int **data;
public:

	/*Constructors*/
    Matrix();
    Matrix(int _row, int _column);
	Matrix(int _row, int _column, int *arr);
    Matrix(const Matrix &_m);
    Matrix operator= (Matrix mat);

	/*cin operator >> and cout operator <<*/
    friend istream&operator>>(istream &input , const Matrix& obj);      //input stream
    friend ostream&operator<<(ostream &output ,const Matrix& obj);      //output stream


	/*addition operator, subtraction operator, multiplication operator, and equal operator*/
    //20170260

    Matrix operator+(const Matrix &obj);    //Summation of two matrices in new matrix
    Matrix operator-(const Matrix &obj);    //difference of two matrices in new matrix
    Matrix operator*(const Matrix &obj);    //multiplication of two matrices in new matrix
    Matrix operator+(int scalar);           //Summation of matrix and scalar in new matrix
    Matrix operator-(int scalar);           //diff of matrix and scalar in new matrix
    Matrix operator*(int scalar);           //multiplication of matrix and scalar in new matrix

    //20170261

    Matrix operator+=(const Matrix&obj);    // mat1 changes & return new matrix with the sum
    Matrix operator-=(const Matrix&obj);    // mat1 changes & return new matrix with difference
    Matrix operator+=(int scalar);          // change mat & return new
    Matrix operator-=(int scalar);          // change mat & return new
    void operator++ ();                     // Add 1 to each element ++mat
    void operator-- ();                     //subtract 1 to each element --mat



    //20170274
    bool   operator== (const Matrix &obj);	// True if identical
    bool   operator!= (const Matrix &obj); 	// True if not same
    bool   isSymetric (Matrix&obj);  // True if square and symmetric
    bool isIdentity (Matrix& obj); // True if square and identity
    bool  isSquare ();              // True if square matrix
    Matrix transpose(Matrix& obj);

	/*Access operator*/
    double*operator[](const int& index);
	/*Destructor*/
    //~Matrix();
 };

#endif // MATRIX_H
