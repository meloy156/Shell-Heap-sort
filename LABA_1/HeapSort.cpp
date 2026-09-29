#include "HeapSort.h"


static void siftDown(std::vector<int>& arr, int root, int heapSize) {
    while (true) {
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;

        if (left < heapSize && arr[left] > arr[largest]) largest = left;
        if (right < heapSize && arr[right] > arr[largest]) largest = right;


        if (largest == root) break;

        std::swap(arr[root], arr[largest]);
        root = largest;
    }

}



void HeapSort (std::vector<int>& arr) {
    int n = (int)arr.size();
    if (n < 2) return;


    // строим дерево и кидаем вверх max
    for (int i = n/2 - 1; i >= 0; --i) {
        siftDown(arr, i, n);
    }

    // берем верх дерева и ставим в конец массива
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        siftDown(arr, 0, i);
    }

}