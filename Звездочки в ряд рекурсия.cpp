#include <iostream>

using namespace std;


void printStars(int n) {
    if (n <= 0) return;
    cout << "*";        
    printStars(n - 1);  
}

int main() {
    setlocale(LC_ALL, "");
    int n;
    cout << "Введите количество звездочек: ";
    cin >> n;

    printStars(n); 
    cout << endl;  

    return 0;
}

