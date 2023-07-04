#define epsint 1e-4
#define epsZero 1e-2
#include <math.h>


double abs1(double Num);  // 112-Козлов-Илья Функция Функция модуля. Подаем Num, получаем |Num|
double findzero(double (*function)(double), double Start_Segment, double End_Segment, int * err); // 112-Козлов-Илья
//Подаем функцию, зависящую от одной переменной, function, double Start_Segment - начало поиска нуля, double End_Segment - конец поиска нуля и указатель на код ошибки * err;
//Получаем значение X, в котором функция function принимает значение 0
//Алгоритм: Функция берет концевые точки строит отрезок, далее смотри пересечение отрезка и прямой OX. Далее один из концов с совпадающим знаком заменяется на это новое число
// и так до тех пор, пока значение от пересечения с OX не станет очень близко к нулю.
double integral(double (*function)(double), double Start_Segment, double End_Segment); // 112-Козлов-Илья Сначала с помощью цикла складываем все трапеции,
// потом с помощью другого цикла засчет прибавления количества разбиений пытаемся добиться точности полученных вычислений
// Подаем double (*function)(double) - функция, которую будем интегрировать
// Start_Segment, End_Segment - соответственно начало и конец отрезка
//Получаем integral(function) from Start_Segment to End_Segment возвращаемый с помощью return
double function(double x); //112-Козлов-Илья
//Подаем переменную x
//Получаем результат sqrt(x*x*x+1/x)