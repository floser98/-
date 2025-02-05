#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int* array = new int[1]; // Изначально массив из одного элемента
    int size = 0; // Текущий размер массива
    int input;

    cout << "Введите числа (для завершения введите отрицательное число):" << std::endl;

    while (true) {
        cin >> input;

        if (input < 0) {
            break; // Если введено отрицательное число, выходим из цикла
        }

        // Переопределяем память для нового массива
        int* temp = new int[size + 1]; // Создаем новый массив на 1 элемент больше
        for (int i = 0; i < size; i++) {
            temp[i] = array[i]; // Копируем элементы старого массива
        }
        temp[size] = input; // Добавляем новое число

        delete[] array; // Удаляем старый массив
        array = temp; // Указатель перенаправляем на новый массив
        size++; // Увеличиваем размер массива
    }

    // Выводим элементы массива
    cout << "Вы ввели следующие числа:" << std::endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << std::endl;

    delete[] array; // Освобождаем память
    return 0;
}
