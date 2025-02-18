#include <iostream>

const int SIZE = 10; // Размер статического массива

void separateNumbers(int arr[], int size, int*& posArr, int& posSize, int*& negArr, int& negSize, int*& zeroArr, int& zeroSize) {
    // Подсчёт количества положительных, отрицательных и нулей
    posSize = negSize = zeroSize = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) posSize++;
        else if (arr[i] < 0) negSize++;
        else zeroSize++;
    }

    // Выделение памяти для динамических массивов
    posArr = new int[posSize];
    negArr = new int[negSize];
    zeroArr = new int[zeroSize];

    // Заполнение динамических массивов
    int posIndex = 0, negIndex = 0, zeroIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) posArr[posIndex++] = arr[i];
        else if (arr[i] < 0) negArr[negIndex++] = arr[i];
        else zeroArr[zeroIndex++] = arr[i];
    }
}

void printArray(const char* msg, int* arr, int size) {
    std::cout << msg;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "");
    int arr[SIZE] = { 3, -1, 0, 4, -5, 0, 2, -8, 6, 0 }; // Исходный статический массив

    int* posArr = nullptr;
    int* negArr = nullptr;
    int* zeroArr = nullptr;
    int posSize, negSize, zeroSize;

    // Разделение элементов массива
    separateNumbers(arr, SIZE, posArr, posSize, negArr, negSize, zeroArr, zeroSize);

    // Вывод результатов
    printArray("Положительные числа: ", posArr, posSize);
    printArray("Отрицательные числа: ", negArr, negSize);
    printArray("Нули: ", zeroArr, zeroSize);

    // Освобождение памяти
    delete[] posArr;
    delete[] negArr;
    delete[] zeroArr;

    return 0;
}
