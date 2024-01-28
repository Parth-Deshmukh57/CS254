#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

void print(vector<vector<int>> matrix,
           int start_row, int start_column, int end_row,
           int end_column) {
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_column; j <= end_column; j++) {
            cout << setw(10) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void add_matrix(vector<vector<int>> matrix_A,
                vector<vector<int>> matrix_B,
                vector<vector<int>>& matrix_C,
                int split_index) {
    for (auto i = 0; i < split_index; i++)
        for (auto j = 0; j < split_index; j++)
            matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
}

vector<vector<int>> multiply_matrix(vector<vector<int>> matrix_A,
                                    vector<vector<int>> matrix_B) {
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    int row_2 = matrix_B.size();
    if (col_1 != row_2) {
        cout << "\nError: The number of columns in Matrix "
             << "A must be equal to the number of rows in "
             << "Matrix B\n";
        return {};
    }

    vector<int> result_matrix_row(col_2, 0);
    vector<vector<int>> result_matrix(row_1, result_matrix_row);

    if (col_1 == 1) {
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    } else {
        int split_index = col_1 / 2;
        vector<vector<int>> result_matrix_00(split_index, vector<int>(split_index, 0));
        vector<vector<int>> result_matrix_01(split_index, vector<int>(split_index, 0));
        vector<vector<int>> result_matrix_10(split_index, vector<int>(split_index, 0));
        vector<vector<int>> result_matrix_11(split_index, vector<int>(split_index, 0));

        vector<vector<int>> a00(split_index, vector<int>(split_index, 0));
        vector<vector<int>> a01(split_index, vector<int>(split_index, 0));
        vector<vector<int>> a10(split_index, vector<int>(split_index, 0));
        vector<vector<int>> a11(split_index, vector<int>(split_index, 0));

        vector<vector<int>> b00(split_index, vector<int>(split_index, 0));
        vector<vector<int>> b01(split_index, vector<int>(split_index, 0));
        vector<vector<int>> b10(split_index, vector<int>(split_index, 0));
        vector<vector<int>> b11(split_index, vector<int>(split_index, 0));

        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++) {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + split_index];
                a10[i][j] = matrix_A[split_index + i][j];
                a11[i][j] = matrix_A[i + split_index][j + split_index];

                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + split_index];
                b10[i][j] = matrix_B[split_index + i][j];
                b11[i][j] = matrix_B[i + split_index][j + split_index];
            }

        add_matrix(multiply_matrix(a00, b00),
                   multiply_matrix(a01, b10),
                   result_matrix_00, split_index);

        add_matrix(multiply_matrix(a00, b01),
                   multiply_matrix(a01, b11),
                   result_matrix_01, split_index);

        add_matrix(multiply_matrix(a10, b00),
                   multiply_matrix(a11, b10),
                   result_matrix_10, split_index);

        add_matrix(multiply_matrix(a10, b01),
                   multiply_matrix(a11, b11),
                   result_matrix_11, split_index);

        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++) {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + split_index] = result_matrix_01[i][j];
                result_matrix[split_index + i][j] = result_matrix_10[i][j];
                result_matrix[i + split_index][j + split_index] = result_matrix_11[i][j];
            }
    }

    return result_matrix;
}

void sca(vector<vector<int>>& matrix_A, int ROW_1, int COL_1) {
    for (int i = 0; i < ROW_1; i++) {
        vector<int> p;
        for (int j = 0; j < COL_1; j++) {
            int a;
            cin>>a;
            p.push_back(a);
        }
        matrix_A.push_back(p);
    }
}

int main() {
     freopen("input1.in","r",stdin);
    freopen("output1.out","w",stdout);
    int t;
    cin>>t;

    while(t--){
    int ROW_1, COL_1, ROW_2, COL_2;
    cin >> ROW_1 >> COL_1 >> ROW_2 >> COL_2;

    vector<vector<int>> matrix_A;
    vector<vector<int>> matrix_B;

    sca(matrix_A, ROW_1, COL_1);
    print( matrix_A, 0, 0, ROW_1 - 1, COL_1 - 1);

    sca(matrix_B, ROW_2, COL_2);
    print(matrix_B, 0, 0, ROW_2 - 1, COL_2 - 1);

    vector<vector<int>> result_matrix(multiply_matrix(matrix_A, matrix_B));
    print(result_matrix, 0, 0, ROW_1 - 1, COL_2 - 1);
    }

    return 0;
}
