#include <iostream>

using namespace std;

class Matrix {
public:
    int mat[10][10], rows, cols;

    void input() {
        cout << "Enter rows and columns: ";
        cin >> rows >> cols;
        cout << "Enter elements:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix add(Matrix m) {
        Matrix res;
        if (rows != m.rows || cols != m.cols) {
            cout << "Addition not possible!\n";
            return res;
        }
        res.rows = rows;
        res.cols = cols;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return res;
    }

    Matrix multiply(Matrix m) {
        Matrix res;
        if (cols != m.rows) {
            cout << "Multiplication not possible!\n";
            return res;
        }
        res.rows = rows;
        res.cols = m.cols;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                res.mat[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    res.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return res;
    }

    Matrix transpose() {
        Matrix res;
        res.rows = cols;
        res.cols = rows;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.mat[j][i] = mat[i][j];
            }
        }
        return res;
    }
};

int main() {
    Matrix A, B, result;

    cout << "Enter first matrix:\n";
    A.input();

    cout << "Enter second matrix:\n";
    B.input();

    result = A.add(B);
    cout << "Sum of matrices:\n";
    result.display();

    result = A.multiply(B);
    cout << "Product of matrices:\n";
    result.display();

    result = A.transpose();
    cout << "Transpose of first matrix:\n";
    result.display();

    return 0;
}