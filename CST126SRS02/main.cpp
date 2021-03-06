// CST126SRS02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std; 

int main()
{
	char name[258];

	auto num_names = 4;
	int size{};
	int capacity{};

	auto nameList = new char*[capacity];

	while (cin.good())
	{
		const auto nl = cin.peek();

		if (nl != '\n')
		{
			if (size == capacity)
			{

				int i{};
				capacity = (capacity * 2) + 1;
				auto tmp = new char*[capacity];


				while (i < size)
				{

					tmp[i] = nameList[i];
					i++;

				}
				delete[] nameList;
				nameList = tmp;
			}
			char * currentName = nullptr;
			char buffer[258];

			cin >> setw(277) >> buffer;

			currentName = new char[strlen(buffer) + 1];
			strcpy(currentName, buffer);

			nameList[size] = currentName;

			size++;
		}

		else
		{
			size--;
			while (size >= 0)
			{
				cout << nameList[size] << " ";
				delete[] nameList[size];
				size--;
			}
		}
	}
    return 0;
}

