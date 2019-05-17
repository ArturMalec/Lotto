#include "Lotto.h"

void Lotto::losowanie_gracza()
{
	int INT_LOS = 6;
	std::cout << "Podaj swoje liczby do skreslenia od 1 do 49: \n";

		do
		{
		for (int i = 0; i < INT_LOS; i++)
		{
			std::cout << ">> ";
			while (!(std::cin >> lg[i]))
			{
				std::cerr << "Musisz podac cyfry!" << std::endl;
				std::cin.clear();
				std::cin.sync();
			}
			if (lg[i] > 49 || lg[i] < 1)
			{
				std::cerr << "Liczba musi byc w przedziale od 1 do 49!!\n";
				INT_LOS++;
				continue;
			}
			else
			{
				liczby_gracza.push_back(lg[i]);
			}
		}

			wynik = Lotto::check_gracza(lg, INT_LOS);

			if (wynik < INT_LOS)
			{
				std::cerr << "Liczby nie moga sie powtarzac!!! Sproboj ponownie..." << std::endl;
				for (int i = 0; i < INT_LOS; i++)
					liczby_gracza.pop_back();
				continue;
			}
		}
		while (wynik < INT_LOS);

		sort(liczby_gracza.begin(), liczby_gracza.end());

		for (int x : liczby_gracza)
		{
			std::cout << x << ' ';
		}
		std::cout << std::endl;
}

void Lotto::losowanie_liczb()
{
	std::cout << "Losowanie liczb nastapi za 3 sekundy: " << std::endl;
		Sleep(3000);

			while (licznik < 6)
			{
				los = rand() % 49 + 1;
				if (!(Lotto::check_wylosowane(los, licznik)))
				{
					tab[licznik] = los;
					licznik++;
					liczby_losowane.push_back(los);
				}
			}
			std::cout << "Wylosowane liczby w loterii: " << std::endl;
			sort(liczby_losowane.begin(), liczby_losowane.end());

			for (int x : liczby_losowane)
			{
				std::cout << x << std::endl;
				Sleep(500);
			}
			std::cout << std::endl;
}

void Lotto::wynik_losowania()
{
	const int ITER = 6;
	for (int x : liczby_losowane)
		{
			for (int y : liczby_gracza)
			{
				if (y == x)
					{
						zliczanie++;
					}
			}
		}
			std::vector<std::string> nazwy {"jedynke","dwojke","trojke",
				"czworke","piatke","szostke"};
			if (zliczanie == 0)
				std::cout << "Nie trafiles nic!" << std::endl;

			for (int i = 1; i < ITER; i++)
			{
				if (zliczanie == i)
					std::cout << "Trafiles " << nazwy[i-1] << std::endl;
			}
}


bool Lotto::check_wylosowane(int n, int ilosc)
{
	for (int i = 0; i < ilosc; i++)
		{
			if (tab[i] == n)
				return true;
		}
		return false;
}

int Lotto::check_gracza(int t[], int rozmiar)
{
	int l = 0;
		int p = 0;

		while ( l < rozmiar)
			{
				int z = 0;
				for (int k = l+1; k < rozmiar; k++)
					{
						if (t[l] == t[k])
							z++;
					}
				l=l+z+1;
				if (z != 0)
					p=p+z+1;
			}
		return rozmiar-p;
}


