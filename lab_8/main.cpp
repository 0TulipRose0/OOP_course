#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <vector>

//Шаблон вычисления среднего арифметического вектора чисел
template<typename vect_type>
vect_type average_value(std::vector<vect_type> arr){
    vect_type sum{};
    for (vect_type &value: arr){
        sum = sum + value;
    }
    vect_type value = sum/arr.size();
    return value;
}

//Шаблон класса "Точка"
template<typename T1, typename T2>
class point{
public:
    T1 x;
    T2 y;
    point(T1 input1, T2 input2) : x(input1), y(input2) //инициализация по вводимым значениям
    {}
    point() : x(0), y(0) //инициализация по умолчанию
    {}
    //Перегрузка операторов "+" и "/"
    point<T1, T2> operator + (point dot){
        return point<T1, T2>(this->x + dot.x, this->y + dot.y);
    }

    point<T1, T2> operator / (int number){
        return point<T1, T2>(this->x / number, this->y / number);
    }
};


int main(int argc, char *argv[])
{
    //Проверка работоспособности шаблонов

    std::vector<int> array1{3,5,7};
    auto result1 = average_value(array1);
    std::cout << "Result for integers = " << result1 <<std::endl;

    std::vector<float> array2{3.5,5.5,7.5};
    auto result2 = average_value(array2);
    std::cout << "Result for floats = " << result2 <<std::endl;

    std::vector<point<int, int>> array3{{1, 1},{2, 2},{3, 3}};
    auto result3 = average_value(array3);
    std::cout << "Result for dots x: " << result3.x << " " << "y: " << result3.y << std::endl;


    return 0;
}
