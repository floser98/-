#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

// Шаблонная функция для заполнения массива случайными значениями
template <typename T>
void fillArray(T array[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = static_cast<T>(rand() % 100);
        }
    }
}

// Шаблонная функция для вывода массива
template <typename T>
void printArray(T array[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

// Шаблонная функция для поиска максимального элемента
template <typename T>
T findMax(T array[ROWS][COLS]) {
    T maxElem = array[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] > maxElem) maxElem = array[i][j];
        }
    }
    return maxElem;
}

// Шаблонная функция для поиска минимального элемента
template <typename T>
T findMin(T array[ROWS][COLS]) {
    T minElem = array[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] < minElem) minElem = array[i][j];
        }
    }
    return minElem;
}

// Шаблонная функция для линейного поиска
template <typename T>
bool linearSearch(T array[ROWS][COLS], T target) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] == target) {
                cout << "Элемент " << target << " найден на позиции (" << i << ", " << j << ")" << endl;
                return true;
            }
        }
    }
    cout << "Элемент " << target << " не найден." << endl;
    return false;
}

// Шаблонная функция для вычисления суммы всех элементов
template <typename T>
T sumAll(T array[ROWS][COLS]) {
    T sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += array[i][j];
        }
    }
    return sum;
}

void mainMenu() {
    int array[ROWS][COLS];
    int choice;
    do {
        cout << "Меню:\n1. Заполнить массив\n2. Вывести массив\n3. Найти максимум\n4. Найти минимум\n5. Линейный поиск\n6. Сумма всех элементов\n7. Выход\nВыберите действие: ";
        cin >> choice;
        switch (choice) {
        case 1: fillArray(array); break;
        case 2: printArray(array); break;
        case 3: cout << "Максимальный элемент: " << findMax(array) << endl; break;
        case 4: cout << "Минимальный элемент: " << findMin(array) << endl; break;
        case 5:
            int target;
            cout << "Введите элемент для поиска: ";
            cin >> target;
            linearSearch(array, target);
            break;
        case 6: cout << "Сумма всех элементов: " << sumAll(array) << endl; break;
        case 7: return;
        default: cout << "Некорректный ввод! Попробуйте снова." << endl;
        }
    } while (true);
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(nullptr));
    mainMenu();
    return 0;
}
