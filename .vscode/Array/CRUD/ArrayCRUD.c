#include <stdio.h>
#define MAX_SIZE 100 // 定义数组大小

// 查找元素 参数 arr 数组 n 当前数组长度 key 查找目标数据
int findElement(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i; // 返回元素的索引
    }
    return -1; // 如果未找到元素，返回-1
}

// 中间插入元素 arr 数组 n 取数组大小size的地址 element 添加的元素 position 添加的位置
void insertAtMiddle(int arr[], int *n, int element, int position) {
    if (*n >= MAX_SIZE) {
        printf("数组已满，无法插入元素\n");
        return;
    }
    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*n)++;
}

// 在数组尾部插入元素
void insertAtEnd(int arr[], int *n, int element) {
    if (*n >= MAX_SIZE) {
        printf("数组已满，无法插入元素\n");
        return;
    }
    arr[*n] = element;
    (*n)++;
}

// 改变指定位置的值 arr 数组 n 数组大小 position 要改变值的位置 newValue 新值
void updateElementAtPosition(int arr[], int n, int position, int newValue) {
    if (position < 0 || position >= n) {
        printf("位置无效\n");
        return;
    }
    arr[position] = newValue;
}

void deleteAtMiddle(int arr[],int *n,int position){
    if(position<0||position>=*n){
        printf("位置无效\n");
        return;
    }
    for(int i=position;i<*n-1;i++){
        arr[i]=arr[i+1];
    }
    (*n)--;
}
void deleteAtEnd(int arr[],int *n){
    if(*n<=0){
        printf("数组为空，无法删除元素\n");
        return;
    }
    (*n)--;
}

int main() {
    int arr[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int key = 5; // 查找目标数
    int index = findElement(arr, size, key);
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }

    int elementToInsert = 90;
    int position = 5; // 插入位置
    printf("在数组中间插入元素 %d 后的数组: ", elementToInsert);
    insertAtMiddle(arr, &size, elementToInsert, position);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int elementToEnd = 99;
    insertAtEnd(arr, &size, elementToEnd);
    printf("在尾部插入元素 %d 后的数组: ", elementToEnd);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 改变指定位置的值
    int newValue = 77;
    position = 3; // 要改变值的位置
    updateElementAtPosition(arr, size, position, newValue);
    printf("改变位置 %d 的值为 %d 后的数组: ", position, newValue);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    position = 4; // 要删除元素的位置
    deleteAtMiddle(arr, &size, position);
    printf("删除位置 %d 的元素后的数组: ", position);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    deleteAtEnd(arr,&size);
    printf("删除尾部元素后的数组: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}