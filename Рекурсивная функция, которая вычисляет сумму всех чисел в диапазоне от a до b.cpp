#include <iostream>

using namespace std;

int sumRange(int a, int b) {
    if (a > b) 
        return 0;
    return a + sumRange(a + 1, b);  
}

int main() {
    setlocale(LC_ALL, "");
    int a, b;
    cout << "Введите два числа (a и b): " << endl;
    cin >> a >> b;

    if (a > b) {
        cout << "Ошибка: a должно быть меньше или равно b.";
    }
    else {
        int result = sumRange(a, b);
        cout << "Сумма чисел от " << a << " до " << b << " равна " << result << endl;
    }

    return 0;
}

