#include "matrix.h"
using namespace std;
/*Constructors*/
Matrix::Matrix()
{
    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<"Enter the number of columns: ";
    cin>>column;

    matrix = new int*[row];
    for(int i=0; i<row; i++)
        matrix[i] = new int[column];
}

Matrix::Matrix(int _row,int _column)
{
    row    = _row;
    column = _column;
    matrix = new int*[_row];
    for(int i = 0; i < _row; i++)
        matrix[i] = new int[_column];

    for(int i = 0; i < row; i++)
        for(int j = 0; j < column; j++)
            matrix[i][j] = 0;

}

Matrix::Matrix(int _row, int _column,int *arr)
{
    row    = _row;
    column = _column;
    matrix = new int*[_row];
    for(int i = 0; i < _row; i++)
        matrix[i] = new int[_column];

    for(int i = 0; i < row; i++)
        for(int j = 0; j < column; j++)
            matrix[i][j] = arr[i * column + j];

}

Matrix::Matrix(const Matrix &_m)
{
    row    = _m.row;
    column = _m.column;
    matrix = new int*[row];
    for(int i = 0; i < row; i++)
        matrix[i] = new int[column];

    for(int i = 0; i < row; i++)
        for(int j = 0; j < column; j++)
            matrix[i][j] = _m.matrix[i][j];

}


/*cin operator >> and cout operator <<*/

istream&operator>>(istream &input, const Matrix& obj)
{
    cout<<"Enter elements: "<<endl;
    for(int i=0; i< obj.row; i++)
    {
        for(int j=0; j < obj.column; j++)
            input>>obj.matrix[i][j];
    }
    return input;
}

ostream&operator<<(ostream &output,const Matrix& obj)
{
    for(int i = 0; i < obj.row; i++)
    {
        for(int j = 0; j < obj.column; j++)
            output<<obj.matrix[i][j]<<" ";
        output<<endl;
    }
    return output;
}
//Deep copy
Matrix Matrix:: operator= (Matrix obj)
{
    if (this == &obj)
        return *this;


    for (int i = 0; i < row; i++)
        delete [] matrix[i];
    delete [] matrix;

    row = obj.row;
    column = obj.column;
    matrix = new int* [row];

    for (int i = 0; i < row; i++)
     matrix[i] = new int [column];

    for (int i = 0; i < row; i++)
      for (int j = 0; j < column; j++)
        matrix[i][j] = obj.matrix[i][j];

        return *this;
}


//20170260
/*addition operator*/
Matrix Matrix::operator+(const Matrix &obj)
{
    if(this->row==obj.row && this->column==obj.column)
    {

        Matrix m(row,column);
        for(int i = 0; i < m.row; i++)
        {
            for(int j = 0; j < m.column; j++)
                m.matrix[i][j] = matrix[i][j] + obj.matrix[i][j]; //summation of two matrices in one new matrix
        }
    return m;
    }
    else
        cout<<"Cannot sum due to different ROWS or COLS"<<endl;
        exit(0);
}
/*subtraction operator*/
Matrix Matrix::operator-(const Matrix &obj)
{
    if(this->row==obj.row && this->column==obj.column)
    {
    Matrix m(row,column);
    for(int i = 0; i < m.row; i++)
    {
        for(int j = 0; j < m.column; j++)
            m.matrix[i][j] = matrix[i][j] - obj.matrix[i][j];
    }
    return m;
    }
    else
        cout<<"Cannot sum due to different ROWS or COLS"<<endl;
        exit(0);
}

/*multiplication operator*/
Matrix Matrix::operator*(const Matrix &obj)
{
    if(this->column == obj.row)
    {
    Matrix m(row, obj.column);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < obj.column; j++)
        {
            m.matrix[i][j] = 0;
            for(int k = 0; k < column; k++)
            {
                m.matrix[i][j] += matrix[i][k] * obj.matrix[k][j];
            }
        }
    }
    return m;
    }
    else
        cout<<"Cannot as COL of mat1 doesn't equal ROW in mat2"<<endl;
        exit(0);
}
//Summation of Matrix with a scalar num.
Matrix Matrix::operator+(int scalar)
{
    Matrix m(row,column);
    for(int i = 0; i < m.row; i++)
    {
        for(int j = 0; j < m.column; j++)
            m.matrix[i][j] = matrix[i][j] + scalar;
    }
    return m;
}
//Difference of Matrix with a scalar num.
Matrix Matrix::operator-(int scalar)
{
    Matrix m(row,column);
    for(int i = 0; i < m.row; i++)
    {
        for(int j = 0; j < m.column; j++)
            m.matrix[i][j] = matrix[i][j] - scalar;
    }
    return m;
}
//Multiplication of Matrix with a scalar num.
Matrix Matrix::operator*(int scalar)
{
    Matrix m(row,column);
    for(int i = 0; i < m.row; i++)
    {
        for(int j = 0; j < m.column; j++)
            m.matrix[i][j] = matrix[i][j] * scalar;
    }
    return m;
}

//Second
//20170261

//Summation of 2 Matrices in the first matrix

Matrix Matrix :: operator+=(const Matrix&obj)
{
    if(this->row==obj.row && this->column == obj.column)
    {
        for(int i=0;i<this->row;i++)
            for(int j=0;j<this->column;j++)
                this->matrix[i][j]+=obj.matrix[i][j];
        cout<<*this<<endl;
        return *this;
    }
    else
        cout<<"Cannot sum as ROWS or COLS aren't the same"<<endl;
        exit(0);
}
//Difference of 2 Matrices in the first matrix

Matrix Matrix :: operator-=(const Matrix&obj)
{
    if(this->row==obj.row && this->column == obj.column)
    {
        for(int i=0;i<this->row;i++)
            for(int j=0;j<this->column;j++)
                this->matrix[i][j]-=obj.matrix[i][j];
        cout<<*this<<endl;
        return *this;
    }
    else
        cout<<"Cannot sum as ROWS or COLS aren't the same"<<endl;
        exit(0);
}
//Summation of scalar to matrix

Matrix Matrix :: operator+=(int scalar)
{
    for(int i=0;i<this->row;i++)
        for(int j=0;j<this->column;j++)
            this->matrix[i][j]+=scalar;
    cout<<*this<<endl;
    return *this;
}
//Difference of scalar to matrix

Matrix Matrix :: operator-=(int scalar)
{
    for(int i=0;i<this->row;i++)
        for(int j=0;j<this->column;j++)
            this->matrix[i][j]-=scalar;
    cout<<*this<<endl;
    return *this;
}

//Adding 1 to each element in Matrix
void Matrix::operator++()
{
    for(int i=0;i<this->row;i++)
        for(int j=0;j<this->column;j++)
            this->matrix[i][j]+=1;
    cout<<*this<<endl;

}
//Subtracting 1 from each element in Matrix

void Matrix::operator--()
{
    for(int i=0;i<this->row;i++)
        for(int j=0;j<this->column;j++)
            this->matrix[i][j]-=1;
    cout<<*this<<endl;

}



//Third
//20170274

//Check if matrix is square or not(Row=Col)
bool Matrix::isSquare()
{
    Matrix m(row,column);
    if(m.column == m.row)
    {
        return true;
    }
    else
        return false;
}

//Transpose Matrix (Row be Col && col be row)
Matrix Matrix :: transpose(Matrix& obj)
{
    Matrix m(column,row);
    int transpose1[(obj.row)*(obj.column)];
    int r=0;
    if(this->isSquare()){
        for(int i=0;i<m.row;i++)
        {
            for(int j=0;j<m.column;j++)
            {
                m.matrix[i][j]=obj.matrix[j][i];
            }
        }
   }
   else
   {
       for(int i = 0;i < obj.column; i++){
        for(int j = 0;j < obj.row; j++){
            m.matrix[i][j] = obj.matrix[j][i];
        }
        }
   }
return m;
}
//Identity matrix of zeros with only ones diagonal

bool Matrix :: isIdentity (Matrix& obj){
if (isSquare()){
        int sum=0;
    for(int i=0;i<obj.column;i++){
        if(obj.matrix[i][i]!=1){
            return false ;
        }
        for(int j=0;j<obj.row;j++){
            sum=sum+obj.matrix[i][j];
        }
    }
    if(sum==obj.row){
        return true;
    }
    else
        return false;
}
else
    return false;
}
//Symetric if it's square and also when transposed it'll be the same to the original one

bool Matrix::isSymetric (Matrix &obj)
{
    /*if((isSquare())&&((obj==transpose(obj))))
    {
      return true;
    }
    else
        return false;*/
}

//check the equality of two matrices

bool Matrix::operator!=(const Matrix &obj)
{
    int sum=0;
    Matrix m(row, column);
    if((m.row!=obj.row) && (m.column != obj.column))
    {
    for (int i = 0; i < m.row; i++){
        for (int j = 0; j < m.column; j++)
        {
            if (m.matrix[i][j]!=obj.matrix[i][j])
            {
                sum++;
            }
            else
                return true;
        }
    }
    if(sum==(obj.column*obj.row)){
        return true;
    }
    else
        return false;
    }
    else
        return true;
}
