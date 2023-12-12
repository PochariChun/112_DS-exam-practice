#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m1, n1, m2, n2;

    // ?入第一?矩?的行?和列?
    cin >> m1 >> n1;

    // ?入第一?矩?的元素
    vector<vector<int> > matrix1(m1, vector<int>(n1));
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            cin >> matrix1[i][j];
        }
    }

    // ?入第二?矩?的行?和列?
    cin >> m2 >> n2;

    // ?入第二?矩?的元素
    vector<vector<int> > matrix2(m2, vector<int>(n2));
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            cin >> matrix2[i][j];
        }
    }

    // ?查矩?是否可以相乘
    if (n1 != m2) {
        cout << "矩??法相乘" << endl;
        return 0;
    }

    // ?算矩?相乘的?果
    vector<vector<int> > result(m1, vector<int>(n2, 0));
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            for (int k = 0; k < n1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // ?出矩?相乘的?果
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}