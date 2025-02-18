#include <iostream>

// Функция сравнения двух строк
int mystrcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i]) return 1;
        if (str1[i] < str2[i]) return -1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') return 0;
    return (str1[i] == '\0') ? -1 : 1;
}

// Функция преобразования строки в число
int StringToNumber(char* str) {
    int result = 0, i = 0, sign = 1;

    if (str[i] == '-') { // Проверяем знак числа
        sign = -1;
        i++;
    }

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') break; // Проверка на цифры
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}

// Функция преобразования числа в строку
char* NumberToString(int number) {
    static char buffer[12]; // Буфер для строки (11 символов + '\0' на крайний случай)
    int i = 0, isNegative = 0;

    if (number == 0) {
        buffer[i++] = '0';
    }
    else {
        if (number < 0) {
            isNegative = 1;
            number = -number;
        }
        while (number > 0) {
            buffer[i++] = (number % 10) + '0';
            number /= 10;
        }
        if (isNegative) {
            buffer[i++] = '-';
        }
    }

    buffer[i] = '\0';
    return mystrrev(buffer); // Используем функцию реверса
}

// Функция преобразования строки в верхний регистр
char* Uppercase(char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32; // Преобразование в верхний регистр
        }
    }
    return str;
}

// Функция преобразования строки в нижний регистр
char* Lowercase(char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32; // Преобразование в нижний регистр
        }
    }
    return str;
}

// Функция реверса строки
char* mystrrev(char* str) {
    int length = 0;
    while (str[length] != '\0') length++; // Определяем длину строки

    for (int i = 0; i < length / 2; ++i) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    return str;
}

// Тестирование функций
int main() {
    setlocale(LC_ALL, "");
    char str1[100], str2[100], str3[100];
    int num;

    std::cout << "Введите первую строку: ";
    std::cin.getline(str1, 100);
    std::cout << "Введите вторую строку: ";
    std::cin.getline(str2, 100);

    std::cout << "Сравнение строк: " << mystrcmp(str1, str2) << std::endl;

    std::cout << "Введите строку для преобразования в число: ";
    std::cin.getline(str3, 100);
    std::cout << "Число: " << StringToNumber(str3) << std::endl;

    std::cout << "Введите число для преобразования в строку: ";
    std::cin >> num;
    std::cout << "Строка: " << NumberToString(num) << std::endl;
    std::cin.ignore(); // Очистка буфера после ввода числа

    std::cout << "Введите строку для преобразования в верхний регистр: ";
    std::cin.getline(str3, 100);
    std::cout << "Результат: " << Uppercase(str3) << std::endl;

    std::cout << "Введите строку для преобразования в нижний регистр: ";
    std::cin.getline(str3, 100);
    std::cout << "Результат: " << Lowercase(str3) << std::endl;

    std::cout << "Введите строку для реверса: ";
    std::cin.getline(str3, 100);
    std::cout << "Реверс: " << mystrrev(str3) << std::endl;

    return 0;
}

