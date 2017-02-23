#include<iostream>
#include<string>

#include"Vector.h"

using namespace std;

void sortN(int theArr[], int nrOfElements);

void sortS(string theArr[], int nrOfElements);

template<typename T>
void sort(T theArr[], int nrOfElements);

template<typename T>
int binarySearch(T theArr, int nrOfElements, T search);

int main()
{

	//Lektion kanske 12? eller 10? Sortering:

	//string strs[5] = { "hus", "bil","cyckel","buss","lampa" };
	//sortS(strs, 5);
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << strs[i] << " ";
	//}




	int nrs[7] = { 8,6,3,5,9,2,4 };
	sortN(nrs, 7);
	for (int i = 0; i < 7; i++)
	{
		cout << nrs[i] << " ";
	}
	cout << endl;


	Vector<string>v(15, 5);
	v.addFirst("Cyckel");
	v.addFirst("Bil");
	v.addLast("Hus");
	v.addAt(1, "Båt");
	try 
	{
	v.addAt(71, "Blomma");
	}
	catch(char* e)
	{
		cout << e << endl;
	}

	getchar();
	return 0;
}

//Sortering "SelectionSort" "https://en.wikipedia.org/wiki/Selection_sort"
// 0	1	2	3	4	5	6	
// 8	6	3	5	9	2	4 //Utgår från att den första är minst sen håller den koll på vilken som är minst och bytar när den läst hela arrayen
// 2	6	3	5	9	8	4 //Utgår från att den andra är minst sen...
// 2	3	6	5	9	8	4
// 2	3	4	5	9	8	6
// 2	3	4	5	9	8	6
// 2	3	4	5	6	8	9
// 2	3	4	5	6	8	9//Slutar här, behöver ej kolla den sista
void sortN(int theArr[], int nrOfElements)
{
	int tempNr = -1;
	for (int i = 0; i < nrOfElements - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < nrOfElements; j++)
		{
			tempNr = theArr[i];
			if (theArr[j] < theArr[minIndex])
			{
				minIndex = j;
			}

		}
		tempNr = theArr[i];
		theArr[i] = theArr[minIndex];
		theArr[minIndex] = tempNr;
	}
}

void sortS(string theArr[], int nrOfElements)
{
	string tempS = "";
	for (int i = 0; i < nrOfElements - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < nrOfElements; j++)
		{
			tempS = theArr[i];
			if (theArr[j] < theArr[minIndex])
			{
				minIndex = j;
			}

		}
		tempS = theArr[i];
		theArr[i] = theArr[minIndex];
		theArr[minIndex] = tempS;
	}
}

//Funktionsmall eller Function template
//Innan Funktionsprototypen måste det skrivas "template<typename T>" alltså både i deklaration och definition

template<typename T>
void sort(T theArr[], int nrOfElements)
{
	T tempS; //kan inte initiera för man vet inte vad det är för nått
	for (int i = 0; i < nrOfElements - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < nrOfElements; j++)
		{
			tempS = theArr[i];
			if (theArr[j] < theArr[minIndex])
			{
				minIndex = j;
			}

		}
		tempS = theArr[i];
		theArr[i] = theArr[minIndex];
		theArr[minIndex] = tempS;
	}
}

//Sökning
//Linjärsökning
//Binärsökning "https://en.wikipedia.org/wiki/Binary_search_algorithm", 
//elementen måste vara sorterade. går in och kollar på mittersta elementet, jämför och går till mitten på nästa halva osv.
template<typename T>
int binarySearch(T theArr, int nrOfElements, T search)
{
	int start = 0;
	int end = nrOfElements;
	int middle = nrOfElements / 2;

	while (search != theArr[middle] && end >= start)
	{
		if (search < theArr[middle])
		{
			end = middle - 1;
		}
		else
		{
			start = middle + 1;
		}
		middle = (end + start) / 2;
		if (end < start)
		{
			middle = -1;
		}
	}
	return middle;
}


//Klassmall
//Class template	ex.	Vector<Timber>v1;	 Vector<string>v2;	 Vector<int>v3;		Vector<int>v4(50);//med storlek 50		Vector<int>(10,5); // med plats 10, expandar med 5