#include <iostream>
#include <cstring> // Для работы с C-строками

// Функция для удаления символа из строки по заданному индексу
void removeChar(char* str, int index) {
    int length = std::strlen(str);

    if (index < 0 || index >= length) {
        std::cout << "Ошибка: индекс вне диапазона!" << std::endl;
        return;
    }

    for (int i = index; i < length - 1; ++i) {
        str[i] = str[i + 1]; // Сдвигаем символы влево
    }
    str[length - 1] = '\0'; // Завершаем строку
}

int main() {
    setlocale(LC_ALL, "");
    char str[100]; // Статический массив для строки
    int index;

    std::cout << "Введите строку: ";
    std::cin.getline(str, 100);

    std::cout << "Введите индекс символа для удаления: ";
    std::cin >> index;

    removeChar(str, index);

    std::cout << "Строка после удаления: " << str << std::endl;

    return 0;
}
