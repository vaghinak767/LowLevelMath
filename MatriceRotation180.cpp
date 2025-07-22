#include <iostream>
void rotate_180(int **arr, int row, int column)
{
    for (int i = 0; i <= row / 2; ++i)
    {
        int l = ((row % 2) && (i == row / 2)) ? column / 2 : column;
        for (int j = 0; j < l; ++j)
        {
            int tmp = arr[i][j];
            arr[i][j] = arr[row - 1 - i][column - 1 - j];
            arr[row - 1 - i][column - 1 - j] = tmp;
        }
    }
}

int main()
{
    int row = 0, column = 0;
    std::cin >> row >> column;
    int **arr = new int *[row];
    for (int i = 0; i < row; ++i)
    {
        arr[i] = new int[column];
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            std::cin >> arr[i][j];
        }
    }
    rotate_180(arr, row, column);
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < row; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
