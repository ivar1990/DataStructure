#include "stdafx.h"
#include <iostream>
#include <string>

#include "Abstractor.h"

using namespace std;

Abstractor::Abstractor()
{

}

void Abstractor::Begin()
{
//	Input();
	OutputFrequencyTable();

	Output();
}

void Abstractor::Input(int ascChar)
{
		dataset.push_back(ascChar);
}

void Abstractor::GetFeedback()
{
	cout << "FeedBack Table: " << endl;
	map<int, int>::iterator it;
	int i = 0;
	for (it = frequency_table.begin(); it != frequency_table.end(); it++)
	{
		cout << endl;
		cout << "Solution No. " << i << endl;
		i++;
		cout << static_cast<char>(it->first) << " => " << it->second << '\n';
		SeparateByFrequency(it->first);
	}
}

void Abstractor::GenerateRandomDataSet(int max_size)
{
	if (max_size < 1)
	{
		max_size = (rand() % 50) + 1;
	}


	srand(time(NULL));
	int rand_num = 0;

	cout << "Amount of nodes generated: " << max_size << endl;
	for (int i = 0; i < max_size; i++) {
		/* generate random number between 1 and 255: */
		rand_num = (rand() % 255) + 1;

		dataset.push_back(rand_num);
		//cout << rand_num << endl;
	}

	for (std::list<int>::iterator it = dataset.begin(); it != dataset.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';
}

void Abstractor::GenerateFrequencyTable()
{
	list<int>::iterator dataset_it;
	map<int, int>::iterator frequencytable_it;

	if (frequency_table.empty())
	{
		frequency_table.insert(pair<int, int>(0, 0));
	}

	for (dataset_it = dataset.begin(); dataset_it != dataset.end(); ++dataset_it)
	{
		//std::cout << "dataset number: " << *dataset_it << endl;

		for (frequencytable_it = frequency_table.begin(); frequencytable_it != frequency_table.end(); ++frequencytable_it)
		{
				if (*dataset_it == frequencytable_it->first)
				{
					frequencytable_it->second++;
				}
				else
				{
					frequency_table.insert(pair<int, int>(*dataset_it, 0));
				}

			//cout << frequencytable_it->first << " => " << frequencytable_it->second << '\n';
		}
	}
}

void Abstractor::OutputFrequencyTable()
{
	GenerateFrequencyTable();
	// show content:
	cout << "Frequency Table: " << endl;
	map<int, int>::iterator it;

	for (it = frequency_table.begin(); it != frequency_table.end(); it++)
		cout << it->first << " => " << it->second << '\n';
}

void Abstractor::SeparateByFrequency(int frequency_num)
{
	list<int>::iterator it;

	for (it = dataset.begin(); it != dataset.end(); it++)
	{
		if (frequency_num != *it)
		{
			cout << static_cast<char>(*it);
		}
		else
		{
			cout << "\n";
			cout << static_cast<char>(frequency_num) << "\n";
		}
	}
}

void Abstractor::Output()
{
	cout << "Response Table: " << endl;
	map<int, int>::iterator it;
	int i = 0;
	for (it = frequency_table.begin(); it != frequency_table.end(); it++)
	{
		cout << endl;
		cout << "Solution No. " << i << endl;
		i++;
		cout << static_cast<char>(it->first) << " => " << it->second << '\n';
		SeparateByFrequency(it->first);
	}
}