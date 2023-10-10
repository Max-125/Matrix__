#include <vector>
#include <iostream>
#include <string>
using namespace std;

/*
* //how to find matrix (1)
double determinant(const std::vector<std::vector<double>>& matrix) {
    int num = matrix.size();

    if (num == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else if (num == 3) {
        return (matrix[0][0] * matrix[1][1] * matrix[2][2]) +
            (matrix[0][1] * matrix[1][2] * matrix[2][0]) +
            (matrix[0][2] * matrix[1][0] * matrix[2][1]) -
            (matrix[0][2] * matrix[1][1] * matrix[2][0]) -
            (matrix[0][1] * matrix[1][0] * matrix[2][2]) -
            (matrix[0][0] * matrix[1][2] * matrix[2][1]);
    }
    else {
        return 0;
    }
}

int main() {
    std::vector<std::vector<double>> matrix = {{114, 92, 13}, {4, 955, 6}, {307, 808, 94} };
    double result = determinant(matrix);
    std::cout << "Determinant of the matrix is: " << result << std::endl;
    return 0;
}
*/


/*
//how to find matrix (2)
int main() {
    int matrix[3][3];
    for (int i = 0; i < 3; i++) {
        cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];
    }
    for (int a = 0; a < 3; a++) {
        cout << '|' << matrix[a][0] << " " << matrix[a][1] << " " << matrix[a][2] << '|' << endl;
    }
    int det1, determinant = 0;
    for (int ij = 0; ij < 3; ij++) {
        det1= 1;

        // matrix[ij % 3][0] - create barries ( move 1 to the right or , when we get an extreme num we move to the first num of line
        // for exemple we have : 4 * 2 * 10 -> move each element 1 to the right and we have -> 5 * 3 * 7
        // *
        // matrix[(ij + 1) % 3][1] * matrix[(ij + 2) - multiple 5 * 1 * 10
        // -
        // matrix[(ij + 1) % 3][2] * matrix[(ij + 2) % 3][1] - multiple 5 * 3 * 7

        det1 = matrix[ij % 3][0] * (matrix[(ij + 1) % 3][1] * matrix[(ij + 2) % 3][2] - matrix[(ij + 1) % 3][2] * matrix[(ij + 2) % 3][1]) ;
        determinant += det1;
    }
    cout << determinant;
    return 0;
}

*/

/*
* // Transposing matrix 
void transpose(int* src, int* dest, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            dest[i + j * rows] = src[j + i * cols];
}

void print(int* a, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i * cols + j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[2][4] = {
        {1 , 2 , 3 , 4 },
        {5 , 6 , 7 , 8 } };
    int res[4][2];
    transpose(a[0], res[0], 2, 4);
    print(res[0], 4, 2);
    return 0;
}
*/

/*
//sum of matrix
int main() {
    int a[3][4] = {
        {1 , 2 , 3 , 4},
        {5 , 6 , 7 , 8},
        {9 , 10 , 11 , 12} };
    int b[3][4] = {
        {1 , 2 , 3 , 4},
        {5 , 6 , 7 , 8},
        {9 , 10 , 11 , 12}
    };
    int res[3][4];

    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 4; k++) {
            res[i][k] = a[i][k] + b[i][k];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 4; k++) {
            cout << res[i][k] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/


// multiplication matrix 

void mult(int* a, int* b, int* res, int size, int rows, int cols) {
    for (int k = 0; k < rows; k++) {
        for (int j = 0; j < cols; j++) {
            int ret = 0;
            for (int x = 0; x < size; x++) {
                ret += a[x + k * size] * b[j + x * cols];
            }
            res[j + k * cols] = ret;
        }
    }
}

void print(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i * cols + j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[3][2] = {
    {1, 2},
    {0, 1},
    {1, 0} };

    int b[2][1] = {
        {1},
        {0} };

    int res[3][1];

    mult(a[0], b[0], res[0], 2, 3, 1);

    print(res[0], 3, 1);

    return 0;
}