#include <iostream>
using namespace std;

// 折半查找函数
int BinarySearch(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        // 计算中间位置
        int mid = left + (right - left) / 2;

        // 检查key是否在中间位置
        if (arr[mid] == key)
        {
            return mid;
        }

        // 如果key大于中间值，忽略左半部分
        if (arr[mid] < key)
        {
            left = mid + 1;
        }
        // 如果key小于中间值，忽略右半部分
        else
        {
            right = mid - 1;
        }
    }

    // 如果没有找到key，返回-1
    return -1;
}

int main()
{
    // 定义并初始化已排序的数组和目标元素key
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]); // 计算数组长度
    int key = 7;

    // 调用折半查找函数进行查找
    int result = BinarySearch(arr, 0, n - 1, key);

    // 根据返回值判断是否找到目标元素并输出结果
    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
