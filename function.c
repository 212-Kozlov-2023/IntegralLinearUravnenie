#include "function.h"

double abs1(double Num)  // 112-Козлов-Илья Функция Функция модуля. Подаем Num, получаем |Num|
{
    if (Num >= 0)
        return Num;
    else
        return -Num;
}

double findzero(double (*function)(double), double Start_Segment, double End_Segment, int * err) // 112-Козлов-Илья
//Подаем функцию, зависящую от одной переменной, function, double Start_Segment - начало поиска нуля, double End_Segment - конец поиска нуля и указатель на код ошибки * err;
//Получаем значение X, в котором функция function принимает значение 0
//Алгоритм: Функция берет концевые точки строит отрезок, далее смотри пересечение отрезка и прямой OX. Далее один из концов с совпадающим знаком заменяется на это новое число
// и так до тех пор, пока значение от пересечения с OX не станет очень близко к нулю.
{
    double ZeroCords = Start_Segment;
    if(abs1(function(Start_Segment)) < epsZero)
        *err = 5;
    if(abs1(function(End_Segment)) < epsZero)
        *err = 4;
    if(*err != 0)
        return 0;
    if(function(Start_Segment) * function(End_Segment) < 0)
    {
        while(abs1(function(ZeroCords)) > epsZero)
        {
            ZeroCords = End_Segment - (function(End_Segment) * (Start_Segment-End_Segment) / (function(Start_Segment) - function(End_Segment)));
            if(function(Start_Segment)*function(ZeroCords) > 0)
                Start_Segment = ZeroCords;
            else
                End_Segment = ZeroCords;
        }
    }
    else
    {
        *err = 1;
        return 8888888888;
    }
    return ZeroCords;
}

double integral(double (*function)(double), double Start_Segment, double End_Segment) // 112-Козлов-Илья Сначала с помощью цикла складываем все трапеции,
// потом с помощью другого цикла засчет прибавления количества разбиений пытаемся добиться точности полученных вычислений
// Подаем double (*function)(double) - функция, которую будем интегрировать
// Start_Segment, End_Segment - соответственно начало и конец отрезка
//Получаем integral(function) from Start_Segment to End_Segment возвращаемый с помощью return
{
    double result = 0; // значение интегр суммы
    double temp_res; // ячейка для хранения предыдущуего результата интегральной суммы
    int numOfSplit = 1000; // переменная с количеством разбиений

    // Первый прогон подсчета интг суммы

    double dx = (abs1(Start_Segment - End_Segment) / numOfSplit); // длина отрезочка над которым считаем площадь
    for( int i = 0; i < numOfSplit; i++)
    {
        result = dx * ((function(Start_Segment+i*dx)+function(Start_Segment+(i+1)*dx))/2) + result;
    }
    temp_res = result + 1; // создаю разницу для запуска цикла
    numOfSplit = numOfSplit + 1000;

    //

    while(abs1(result-temp_res)>epsint)
    {
        dx = (abs1(Start_Segment - End_Segment) / numOfSplit);
        temp_res = result;
        result = 0;
        for( int i = 0; i < numOfSplit; i++)
        {
            result = dx * ((function(Start_Segment+i*dx)+function(Start_Segment+(i+1)*dx))/2) + result;
        }
        numOfSplit += 1000;
    }
    return result;
}


double function(double x)//112-Козлов-Илья
//Подаем переменную x
//Получаем результат sqrt(x*x*x+1/x)
{
    return sqrt(x*x*x+1/x);
}



