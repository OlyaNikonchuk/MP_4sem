// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <ctime> 
#include <locale>
#include <iomanip> 
#include "Combi.h"
#include"Boat.h"
#include "Auxil.h"
#include <iomanip> 
#include <string>
#include <conio.h>
#define N 10
#define INF   0x7fffffff 
#define H (sizeof(AA)/2)
#define M 3
#define NN (sizeof(v)/sizeof(int))
#define MM 5
#define COUNT 25
int main()
{
	setlocale(LC_ALL, "rus");
	char AA[][2] = { "A", "B", "C", "D"/*,"E","F","G"*/};
	std::cout << "----Генератор множества всех подмножеств----\nИсходное множество: \n{";
	for (int i = 0; i < sizeof(AA) / 2; i++)
	{
		std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? "," : " ");
	}
	std::cout << "}\n";
	std::cout << "Генерация всех подмножеств \n";
	combi::subset* s1 = new combi::subset(sizeof(AA) / 2);
	int n = s1->getfirst();
	while (n >= 0)
	{
		std::cout << "{ ";
		for (int i = 0; i < n; i++) std::cout << AA[s1->ntx(i)] << ((i < n - 1) ? ", " : " ");
		std::cout << "}\n";
		n = s1->getnext();
	}
	std::cout << "Всего : " << s1->count() << std::endl;
	//------------------------------------------------------------------------
	std::cout << std::endl << " --- Генератор сочетаний ---";
	std::cout << std::endl << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++) std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация сочетаний ";
	combi::xcombination xc(sizeof(AA) / 2, 3);
	std::cout << "из " << xc.n << " по " << xc.m;
	int  n2 = xc.getfirst();
	while (n2 >= 0)
	{
		std::cout << std::endl << xc.nc << ": { ";
		for (int i = 0; i < n2; i++) std::cout << AA[xc.ntx(i)] << ((i < n2 - 1) ? ", " : " ");
		std::cout << "}";
		n2 = xc.getnext();
	};
	std::cout << std::endl << "всего: " << xc.count() << std::endl;
	//-----------------------------------------------------------------------
	std::cout << std::endl << " --- Генератор перестановок ---";
	std::cout << std::endl << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++) std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация перестановок ";
	combi::permutation p(sizeof(AA) / 2);
	__int64  n3 = p.getfirst();
	while (n3 >= 0)
	{
		std::cout << std::endl << std::setw(4) << p.np << ": { ";
		for (int i = 0; i < p.n; i++) std::cout << AA[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");
		std::cout << "}";
		n3 = p.getnext();
	};
	std::cout << std::endl << "всего: " << p.count() << std::endl;
	//-----------------------------------------------------------------------
	std::cout << std::endl << " --- Генератор размещений ---";
	std::cout << std::endl << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < H; i++) std::cout << AA[i] << ((i < H - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация размещений  из  " << H << " по " << M;
	combi::accomodation s(H, M);
	int  n4 = s.getfirst();
	while (n4 >= 0)
	{
		std::cout << std::endl << std::setw(2) << s.na << ": { ";
		for (int i = 0; i < 3; i++) std::cout << AA[s.ntx(i)] << ((i < n4 - 1) ? ", " : " ");
		std::cout << "}";
		n4 = s.getnext();
	};
	std::cout << std::endl << "всего: " << s.count() << std::endl;
	//-------------------------------------------------------------------------------
	int v[COUNT]; //Вес клнтейнеров
	int c[COUNT]; //Доход от перевзки каждого
	auxil::start();
	for (int i = 0; i < COUNT; i++)
	{
		v[i] = auxil::iget(100, 900);
		c[i] = auxil::iget(10, 150);
	}

	int V = 1500;
	short  r[MM];
	clock_t t1 = clock();
	int cc = boat(
		V,   // [in]  максимальный вес груза
		MM,  // [in]  количество мест для контейнеров     
		NN,  // [in]  всего контейнеров  
		v,   // [in]  вес каждого контейнера  
		c,   // [in]  доход от перевозки каждого контейнера     
		r    // [out] результат: индексы выбранных контейнеров  
	);
	clock_t t2 = clock();

	std::cout << std::endl << "Задача о размещении контейнеров на судне \n --------------------------------";
	std::cout << std::endl << "Общее количество контейнеров : " << NN;
	std::cout << std::endl << "количество мест для контейнеров : " << MM;
	std::cout << std::endl << "ограничение по суммарному весу  : " << V;
	std::cout << std::endl << "вес контейнеров : ";
	for (int i = 0; i < NN; i++) std::cout << std::setw(3) << v[i] << " ";
	std::cout << std::endl << "доход от перевозки : ";
	for (int i = 0; i < NN; i++) std::cout << std::setw(3) << c[i] << " ";
	std::cout << std::endl << "выбраны контейнеры (0,1,...,m-1): ";
	for (int i = 0; i < MM; i++) std::cout << r[i] << " ";
	std::cout << std::endl << "доход от перевозки : " << cc;
	std::cout << std::endl << "общий вес выбранных контейнеров : ";
	int k = 0; for (int i = 0; i < MM; i++) k += v[r[i]]; std::cout << k;
	std::cout << std::endl << std::endl;
	std::cout << "Время: " << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC) << std::endl;
	system("pause");

	std::cout << std::endl << "Задача об оптимальной загрузке судна \n ----------------------------------- ";
	std::cout << std::endl << "ограничение по весу : " << V;
	std::cout << std::endl << "количество мест : " << MM;
	std::cout << std::endl << "количество контейнеров / продолжительность вычисления";
	for (int i = 25; i <= NN; i++)
	{
		t1 = clock();
		int maxcc = boat(V, MM, i, v, c, r);
		t2 = clock();
		std::cout << std::endl << "          " << std::setw(2) << i
			<< "                     " << std::setw(5) << (t2 - t1);
	}
	std::cout << std::endl << std::endl;
	system("pause");
}