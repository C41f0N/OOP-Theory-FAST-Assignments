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
            vector<int> thisRow;
            for (int j = 0; j < cols; j++)
            {
                thisRow.push_back(0);
            }
            data.push_back(thisRow);
        }
    }

    void displayMatrix()
    {
        cout << "Displaying Int Matrix" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << ", ";
            }
            cout << "\b\b\n";
        }
    }

    IntMatrix operator+(IntMatrix &mat)
    {
        int newRow, newCol;
        newRow = min(rows, mat.rows);
        newCol = min(cols, mat.cols);

        IntMatrix temp(newRow, newCol);

        for (int i = 0; i < newRow; i++)
        {
            for (int j = 0; j < newCol; j++)
            {
                temp.data[i][j] = data[i][j] + mat.getElement(i, j);
            }
        }

        return temp;
    }

    IntMatrix operator-(IntMatrix &mat)
    {
        int newRow, newCol;
        newRow = min(rows, mat.rows);
        newCol = min(cols, mat.cols);

        IntMatrix temp(newRow, newCol);

        for (int i = 0; i < newRow; i++)
        {
            for (int j = 0; j < newCol; j++)
            {
                temp.data[i][j] = data[i][j] - mat.getElement(i, j);
            }
        }

        return temp;
    }

    IntMatrix operator*(int x)
    {

        IntMatrix temp(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp.data[i][j] = data[i][j] * x;
            }
        }

        return temp;
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
            vector<double> thisRow;
            for (int j = 0; j < cols; j++)
            {
                thisRow.push_back(0.0);
            }
            data.push_back(thisRow);
        }
    }

    void displayMatrix()
    {
        cout << "Displaying Double Matrix" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << ", ";
            }
            cout << "\b\b\n";
        }
    }

    DoubleMatrix operator+(DoubleMatrix &mat)
    {
        int newRow, newCol;
        newRow = min(rows, mat.rows);
        newCol = min(cols, mat.cols);

        DoubleMatrix temp(newRow, newCol);

        for (int i = 0; i < newRow; i++)
        {
            for (int j = 0; j < newCol; j++)
            {
                temp.data[i][j] = data[i][j] + mat.getElement(i, j);
            }
        }

        return temp;
    }

    DoubleMatrix operator-(DoubleMatrix &mat)
    {
        int newRow, newCol;
        newRow = min(rows, mat.rows);
        newCol = min(cols, mat.cols);

        DoubleMatrix temp(newRow, newCol);

        for (int i = 0; i < newRow; i++)
        {
            for (int j = 0; j < newCol; j++)
            {
                temp.data[i][j] = data[i][j] - mat.getElement(i, j);
            }
        }

        return temp;
    }

    DoubleMatrix operator*(int x)
    {

        DoubleMatrix temp(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp.data[i][j] = data[i][j] * x;
            }
        }

        return temp;
    }
};

int main()
{
    // Header
    cout << "Name: Sarim Ahmed\nRoll Number: 23K0703\n\n";

    IntMatrix mat1(2, 3);
    IntMatrix mat2(2, 2);

    mat1.setElement(0, 1, 50);
    mat1.setElement(1, 1, 25);

    mat2.setElement(0, 1, 50);
    mat2.setElement(1, 1, 4);

    IntMatrix mat3 = mat1 + mat2;

    mat3.displayMatrix();

    DoubleMatrix mat4(6, 6);
    DoubleMatrix mat5(6, 6);

    mat4.setElement(0, 5, 23);
    mat4.setElement(2, 1, 25);

    mat5.setElement(0, 5, 2);
    mat5.setElement(2, 1, 2);

    DoubleMatrix mat6 = mat5 + mat4;

    mat6.displayMatrix();

    mat6 = mat6 * 5;

    mat6.displayMatrix();

    return 0;
}