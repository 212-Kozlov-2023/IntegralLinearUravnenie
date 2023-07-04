#include <stdio.h>
#include "function.h"

double a;//Параметр в уравнении

double functionWithIntegral(double x);//112-Козлов-Илья Функция нашего уравнения
//Подаем x
//Получаем функцию зависящую от x: integral(sqrt(x^3+1/x)) from 0 to x = a^2 + sqrt(x)
int main(void) //112-Козлов-Илья Задача: Решить уравнение с параметром а: integral(sqrt(x^3+1/x)) from 0 to x = a^2 + sqrt(x).
{
    int err = 0; // код ошибки
    double Result;
    printf("Данная программа находит решения уравнения integral(sqrt(x^3+1/x)) from 0 to x = a^2 + sqrt(x)\n Введите значение параметра a:\n");
    if(scanf("%lf", &a) != 1){
        printf("Неверно введен параметр!");
        return -1;
    }

    Result = findzero(functionWithIntegral, 0, 1e5, &err);
    printf("Корень уравнения - %lf\n", Result);
    if(err == 1){
        printf(" Не удалось найти корень");
        return 1;
    }
    return 0;
}

double functionWithIntegral(double x)//112-Козлов-Илья Функция нашего уравнения
//Подаем x
//Получаем функцию зависящую от x: integral(sqrt(x^3+1/x)) from 0 to x = a^2 + sqrt(x)
{
    double add;
    if(x<1e-9){
        x = 1e-9;
    }
    add = sqrt(1e-9)*2; // приближая асимптотикой первообразная равна этому значению.
    return integral(function, 1e-9, x) - a*a - sqrt(x) + add;
}

