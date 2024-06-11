#include <iostream>
using namespace std;

// 哨兵查找函数
int SentinelSearch(int arr[], int n, int key)
{
    // 将数组最后一个元素保存到变量last中
    int last = arr[n - 1];

    // 将目标元素key放置在数组的最后一个位置，作为哨兵
    arr[n - 1] = key;

    int i = 0;

    // 从头开始遍历数组，直到找到目标元素key
    while (arr[i] != key)
    {
        i++;
    }

    // 恢复数组最后一个元素
    arr[n - 1] = last;

    // 检查找到的位置是否在数组范围内，如果是则返回该位置，否则返回-1表示未找到
    if (i < n - 1 || arr[n - 1] == key)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int main()
{
    // 定义并初始化数组和目标元素key
    int arr[] = {4, 2, 3, 7, 8, 5, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    // 调用哨兵查找函数进行查找
    int index = SentinelSearch(arr, n, key);

    // 根据返回值判断是否找到目标元素并输出结果
    if (index != -1)
    {
        cout << "Element found at index: " << index << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
