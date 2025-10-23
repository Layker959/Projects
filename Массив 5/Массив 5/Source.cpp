#include <iostream>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

// ������� ��� ����� �������
void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// ������� ��� ������ �������
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// ������� ��� ��������� ���� ������
void multiplyMatrices(int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        cout << "Multiplication is not possible: the number of columns of the first matrix does not match the number of rows of the second matrix." << endl; //��������� ����������: ����� �������� ������ ������� �� ��������� � ������ ����� ������ �������
        return;
    }

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter the dimensions of the first matrix (rows and columns):"; //������� ������� ������ ������� (������ �������)
    cin >> rows1 >> cols1;

    cout << "Enter the dimensions of the second matrix (rows and columns):"; //������� ������� ������ ������� (������ �������)
    cin >> rows2 >> cols2;

    if (cols1 != rows2) {
        cout << "Multiplication is not possible: the number of columns of the first matrix does not match the number of rows of the second matrix." << std::endl; //��������� ����������: ����� �������� ������ ������� �� ��������� � ������ ����� ������ �������.
        return 1;
    }

    int mat1[MAX_ROWS][MAX_COLS];
    int mat2[MAX_ROWS][MAX_COLS];
    int result[MAX_ROWS][MAX_COLS];

    inputMatrix(mat1, rows1, cols1);
    inputMatrix(mat2, rows2, cols2);

    multiplyMatrices(mat1, mat2, result, rows1, cols1, rows2, cols2);

    cout << "The result of matrix multiplication:" << endl; //��������� ��������� ������
    printMatrix(result, rows1, cols2);

    return 0;
}