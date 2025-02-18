#include <iostream>

// Функция для вставки символа в строку в указанную позицию
void insertChar(char* str, char ch, int pos) {
    // Определяем длину строки вручную
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // Проверяем корректность позиции
    if (pos < 0 || pos > length) {
        std::cout << "Ошибка: позиция вне диапазона!" << std::endl;
        return;
    }

    // Сдвигаем символы вправо, начиная с конца
    for (int i = length; i >= pos; --i) {
        str[i + 1] = str[i];
    }

    // Вставляем символ
    str[pos] = ch;
}

int main() {
    setlocale(LC_ALL, "");
    char str[100]; // Буфер для строки
    char ch;
    int pos;

    std::cout << "Введите строку: ";
    std::cin.getline(str, 100); // Ввод строки

    std::cout << "Введите символ для вставки: ";
    std::cin >> ch;

    std::cout << "Введите позицию для вставки: ";
    std::cin >> pos;

    insertChar(str, ch, pos);

    std::cout << "Строка после вставки: " << str << std::endl;

    return 0;
}
