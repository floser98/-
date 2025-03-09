#include <iostream>
using namespace std;


struct Decimal {
    int num;
    int tail;

    void print() {
        cout << "Num: " << num << ", tail: " << tail << endl;
    }
    void sum(int e_num, int e_tail) {
        num += e_num;
        tail += e_tail;

    }




};

int main() {
    Decimal d;

    d.num = 14;
    d.tail = 345;
    d.print();
    d.sum(100, 120);
    d.print();


}
