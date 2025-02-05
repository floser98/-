#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void fillArray(int array[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = rand() % 100;
        }
    }
}

void printArray(int array[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

int findMax(int array[ROWS][COLS]) {
    int maxElem = array[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] > maxElem) maxElem = array[i][j];
        }
    }
    return maxElem;
}

int findMin(int array[ROWS][COLS]) {
    int minElem = array[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (array[i][j] < minElem) minElem = array[i][j];
        }
    }
    return minElem;
}

double findAverage(int array[ROWS][COLS]) {
    int sum = 0, count = ROWS * COLS;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += array[i][j];
        }
    }
    return static_cast<double>(sum) / count;
}

bool linearSearch(int array[ROWS][COLS], int target) {
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

void sumRows(int array[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        int sum = 0;
        for (int j = 0; j < COLS; j++) {
            sum += array[i][j];
        }
        cout << "Сумма строки " << i << ": " << sum << endl;
    }
}

void sumColumns(int array[ROWS][COLS]) {
    for (int j = 0; j < COLS; j++) {
        int sum = 0;
        for (int i = 0; i < ROWS; i++) {
            sum += array[i][j];
        }
        cout << "Сумма столбца " << j << ": " << sum << endl;
    }
}

int sumAll(int array[ROWS][COLS]) {
    int sum = 0;
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
        cout << "Меню:\n1. Заполнить массив\n2. Вывести массив\n3. Найти максимум\n4. Найти минимум\n5. Среднее значение\n6. Линейный поиск\n7. Сумма строк\n8. Сумма столбцов\n9. Сумма всех элементов\n10. Выход\nВыберите действие: ";
        cin >> choice;
        switch (choice) {
        case 1: fillArray(array); break;
        case 2: printArray(array); break;
        case 3: cout << "Максимальный элемент: " << findMax(array) << endl; break;
        case 4: cout << "Минимальный элемент: " << findMin(array) << endl; break;
        case 5: cout << "Среднее значение: " << findAverage(array) << endl; break;
        case 6:
            int target;
            cout << "Введите элемент для поиска: ";
            cin >> target;
            linearSearch(array, target);
            break;
        case 7: sumRows(array); break;
        case 8: sumColumns(array); break;
        case 9: cout << "Сумма всех элементов: " << sumAll(array) << endl; break;
        case 10: return;
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
