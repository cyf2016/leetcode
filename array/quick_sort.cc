#include <stdlib.h>

void quick_sort_v1(int *arr, int l, int r) {
    if (l >= r) return ;
    int x = l, y = r, z = arr[l];
    // partition
    while (x < y) {
        while (x < y && arr[y] >= z) --y;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) ++x;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort_v1(arr, l, x - 1);
    quick_sort_v1(arr, x + 1, r);
    return ;
}

void quick_sort_v2(int *arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = arr[l];
        // partition
        while (x < y) {
            while (x < y && arr[y] >= z) --y;
            if (x < y) arr[x++] = arr[y];
            while (x < y && arr[x] <= z) ++x;
            if (x < y) arr[y--] = arr[x];
        }
        arr[x] = z;
        quick_sort_v2(arr, l, x - 1);
        l = x + 1;
    }
    return ;
}

#define my_swap(a, b) { \
    __typeof(a) __a = a; \
    a = b, b = __a; \
}

void quick_sort_v3(int *arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = arr[l];
        // partition
        do {
            while (arr[x] < z) ++x;
            while (arr[y] > z) --y;
            if (x <= y) {
                my_swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while(x <= y);
        quick_sort_v3(arr, l, y);
        l = x;
    }
    return ;
}

void quick_sort_v4(int *arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = arr[l + rand() % (r - l + 1)];
        // partition
        do {
            while (arr[x] < z) ++x;
            while (arr[y] > z) --y;
            if (x <= y) {
                my_swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while(x <= y);
        quick_sort_v4(arr, l, y);
        l = x;
    }
    return ;
}

int median(int *arr, int l, int r) {
    int a = arr[l], b = arr[r], c = arr[(l + r) >> 1];
    if (a > b) my_swap(a, b);
    if (a > c) my_swap(a, c);
    if (b > c) my_swap(b, c);
    return b;
}

void quick_sort_v5(int *arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = median(arr, l, r);
        // partition
        do {
            while (arr[x] < z) ++x;
            while (arr[y] > z) --y;
            if (x <= y) {
                my_swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while(x <= y);
        quick_sort_v5(arr, l, y);
        l = x;
    }
    return ;
}
