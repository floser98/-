#include <iostream>

// Функция для удаления всех вхождений заданного символа из строки
void removeAllChars(char* str, char ch) {
    int newIndex = 0; // Индекс для новой строки

    // Проходим по всей строке
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != ch) {
            str[newIndex++] = str[i]; // Копируем только нужные символы
        }
    }

    str[newIndex] = '\0'; // Завершаем строку
}

int main() {
    setlocale(LC_ALL, "");
    char str[100]; // Буфер для строки
    char ch;

    std::cout << "Введите строку: ";
    std::cin.getline(str, 100); // Ввод строки с пробелами

    std::cout << "Введите символ для удаления: ";
    std::cin >> ch;

    removeAllChars(str, ch);

    std::cout << "Строка после удаления символа '" << ch << "': " << str << std::endl;

    return 0;
}

