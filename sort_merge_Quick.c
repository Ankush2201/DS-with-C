#include <stdio.h>

void merge(int arr[], int beg, int mid, int end) {
    int i = beg, j = mid + 1, index = beg, temp[end + 1], k;

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[index] = arr[i];
            i++;
        } else {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }

    if (i > mid) {
        while (j <= end) {
            temp[index] = arr[j];
            j++;
            index++;
        }
    } else {
        while (i <= mid) {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }

    for (k = beg; k < index; k++) {
        arr[k] = temp[k];
    }
}

void merge_sort(int arr[], int beg, int end) {
    int mid;
    if (beg < end) {
        mid = (beg + end) / 2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}
void swap(int arr[], int *i, int *j) {
    int temp = arr[*i];
    arr[*i] = arr[*j];
    arr[*j] = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (arr[i] <= pivot) {
            i++;
        }
        while ( arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr, &i, &j);
        }
    }

    swap(arr, &low, &j);
    return j;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);

        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = 7;

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

   // merge_sort(arr, 0, size - 1);
   quick_sort( arr , 0 , high-1);

    printf("\nSorted array: ");
    for (int i = 0; i < size+1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
