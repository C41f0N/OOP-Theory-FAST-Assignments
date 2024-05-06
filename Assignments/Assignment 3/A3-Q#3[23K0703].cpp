#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Matrix
{
protected:
    int rows, cols;
    vector<vector<T>> data;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols)
    {
    }

    void setElement(int row, int col, T value)
    {
        data[row][col] = value;
    }

    T getElement(int row, int col)
    {
        return data[row][col];
    }

    Matrix<T> operator+(Matrix &mat)
    {
        int newRow, newCol;
        newRow = min(rows, mat.rows);
        newCol = min(cols, mat.cols);

        Matrix temp(newRow, newCol);

        for (int i = 0; i < newRow; i++)
        {
            for (int j = 0; j < newCol; j++)
            {
                temp.data[i][j] = data[i][j] + mat.getElement(i, j);
            }
        }

        return temp;
    }

    Matrix<T> operator-(Matrix &mat)
    {
        int newRow, newCol;
        newRow = min(rows, mat.rows);
        newCol = min(cols, mat.cols);

        Matrix temp(newRow, newCol);

        for (int i = 0; i < newRow; i++)
        {
            for (int j = 0; j < newCol; j++)
            {
                temp.data[i][j] = data[i][j] - mat.getElement(i, j);
            }
        }

        return temp;
    }

    Matrix<T> operator*(T x)
    {

        Matrix temp(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp.data[i][j] = data[i][j] * x;
            }
        }

        return temp;
    }

    void virtual displayMatrix() = 0;
};

class IntMatrix : public Matrix<int>
{
public:
    IntMatrix(
        int rows,
        int cols)
        : Matrix(
              rows,
              cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
    }

    void displayMatrix()
    {
        cout << "Displaying Int Matrix" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; i < cols; j++)
            {
                cout << data[i][j] << ", ";
            }
            cout << "\b\b\n";
        }
    }
};

class DoubleMatrix : public Matrix<double>
{
public:
    DoubleMatrix(
        int rows,
        int cols)
        : Matrix(
              rows,
              cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0.0;
            }
        }
    }

    void displayMatrix()
    {
        cout << "Displaying Double Matrix" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; i < cols; j++)
            {
                cout << data[i][j] << ", ";
            }
            cout << "\b\b\n";
        }
    }
};

int main()
{
    // Header
    cout << "Name: Sarim Ahmed\nRoll Number: 23K0703\n\n";

    IntMatrix mat1(2, 3);
    DoubleMatrix mat2(2, 2);

    mat1.displayMatrix();

    return 0;
}