/*
 * Lotto_use.cpp
 *
 *  Created on: 18 gru 2018
 *      Author: Malcini
 */
#include "Lotto.h"

int main()
{
	srand(time(NULL));
	Lotto lotto;

	lotto.losowanie_gracza();
	lotto.losowanie_liczb();
	lotto.wynik_losowania();

	system("pause");
	return 0;
}



