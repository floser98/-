#include <iostream>

// Функция для проверки, является ли число простым
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Функция для удаления простых чисел из массива
int* removePrimes(int* arr, int size, int& newSize) {
    // Считаем количество непростых чисел
    newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (!isPrime(arr[i])) {
            newSize++;
        }
    }

    // Выделяем новую память под массив без простых чисел
    int* newArr = new int[newSize];
    int index = 0;

    // Заполняем новый массив
    for (int i = 0; i < size; ++i) {
        if (!isPrime(arr[i])) {
            newArr[index++] = arr[i];
        }
    }

    return newArr;
}

int main() {
    setlocale(LC_ALL, "");
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size];
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int newSize;
    int* newArr = removePrimes(arr, size, newSize);

    std::cout << "Массив после удаления простых чисел: ";
    for (int i = 0; i < newSize; ++i) {
        std::cout << newArr[i] << " ";
    }
    std::cout << std::endl;

    // Освобождаем память
    delete[] arr;
    delete[] newArr;

    return 0;
}
