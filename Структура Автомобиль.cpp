#include <iostream>
struct Car {
    double l;
    double h;
    double v;
    int w;
    std::string color;
    int d;
    std::string a;
    std::string name;



};

Car file(double l1, double h1, double v1, int w1, std::string color, int d1, std::string a1, std::string name1) {
    Car car;
    car.l = l1;
    car.h = h1;
    car.v = v1;
    car.w = w1;
    car.color = color;
    car.d = d1;
    car.a = a1;
    car.name = name1;
    return car;
}
void print(Car f) {
    std::cout << "Марка " << f.name << std::endl;
    std::cout << "Длинна                " << f.l << std::endl;
    std::cout << "Клиренс               " << f.h << std::endl;
    std::cout << "Объем двигателя       " << f.v << std::endl;
    std::cout << "Мощьность             " << f.w << std::endl;
    std::cout << "Диаметр дисков        " << f.d << std::endl;
    std::cout << "Трансмиссия           " << f.a << std::endl;
}


int main()
{
    setlocale(LC_ALL, "");
    Car c = file(3.4, 0.23, 1.6, 109, "red", 15, "auto", "Lada"); 
    Car b = file(4.2, 0.19, 1.6, 128, "blue", 16, "auto" , "Skoda");

    print(c);
    print(b);




}
