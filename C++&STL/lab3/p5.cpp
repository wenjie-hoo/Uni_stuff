/*
分别创建大小为10×10、100×100和1000×1000的矩阵，并用0.5到2.0范围内的随机值填充它们。
然后通过测量执行这些操作所需的时间来计算每个矩阵的平方。
使用 high_resolution_clock 时钟的 now() 函数测量时间。
对于小矩阵，重复操作多次，然后将测量时间除以该倍数。
*/

#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;
using namespace chrono;

void fillMatrix(int n, vector<vector<double>> &matrix)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double randomValue = 0.5 + (double)rand() / RAND_MAX * 1.5;
            matrix[i][j] = randomValue;
        }
    }
}

void squareMatrix(int n, vector<vector<double>> &matrix)
{
    vector<vector<double>> result(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }
    matrix = result;
}

int main()
{
    srand(time(NULL));

    vector<vector<double>> m1(100, vector<double>(100));
    vector<vector<double>> m2(1000, vector<double>(1000));
    vector<vector<double>> m3(10000, vector<double>(10000));

    fillMatrix(100, m1);
    fillMatrix(1000, m2);
    fillMatrix(10000, m3);

    duration<double> time(0);

    for (int i = 0; i < 50; i++)
    {
        auto start = high_resolution_clock::now();
        squareMatrix(100, m1);
        auto end = high_resolution_clock::now();
        time += duration_cast<duration<double>>(end - start);
    }
    cout << "100x100 matrix: " << time.count() / 50 << " s" << endl;

    auto start = high_resolution_clock::now();
    squareMatrix(1000, m2);
    auto end = high_resolution_clock::now();
    time = duration_cast<duration<double>>(end - start);
    cout << "1000x1000 matrix: " << time.count() << " s" << endl;

    start = high_resolution_clock::now();
    squareMatrix(10000, m3);
    end = high_resolution_clock::now();
    time = duration_cast<duration<double>>(end - start);
    cout << "10000x10000 matrix: " << time.count() << " s" << endl;
    return 0;
}
