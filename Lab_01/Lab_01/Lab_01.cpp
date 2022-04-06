#include <iostream>
#include "Auxil.h"
#include <ctime>
#include <locale>


int main()
{
    int CYCLE = 100000;
    double av1 = 0, av2 = 0;
    clock_t t1 = 0, t2 = 0;
    setlocale(LC_ALL, "RUS");
    auxil::start();
    for (int i = 0; i < 10; i++) {
        t1 = clock();

        for (int i = 0; i < CYCLE; i++)
        {
            av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
            av2 += auxil::dget(-100, 100); // сумма случайных чисел 
        }
        t2 = clock();
        std::cout << std::endl << "количество циклов:         " << CYCLE;
        std::cout << std::endl << "среднее значение (int):    " << av1 / CYCLE;
        std::cout << std::endl << "среднее значение (double): " << av2 / CYCLE;
        std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
        std::cout << std::endl << "                  (сек):   "
            << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
        std::cout << std::endl;
        CYCLE += 100000;
    }
    system("pause");
    return 0;
}
