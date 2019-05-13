/*
 * lotto.h
 *
 *  Created on: 18 gru 2018
 *      Author: Malcini
 */

#ifndef LOTTO_H_
#define LOTTO_H_
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <algorithm>
#include <string>
const short SIZE_ = 6;

class Lotto
{
public:
	Lotto() {}
	bool check_wylosowane(int n, int ilosc); // This function checks reapeating of player numbers
	int check_gracza(int t[], int rozmiar); // This function checks reapeating of randomized lottery numbers
	void losowanie_gracza(); // This function allows you to enter your lottery numbers
	void losowanie_liczb(); // This function randomizes numbers
	void wynik_losowania(); // This function shows final results of lottery
	virtual ~Lotto() {}
private:
	int tab[SIZE_];
	std::vector<int> liczby_losowane;
	std::vector<int> liczby_gracza;
	int lg[SIZE_];
	int zliczanie = 0;
	int los, licznik = 0;
	int wynik;
};







#endif /* LOTTO_H_ */
