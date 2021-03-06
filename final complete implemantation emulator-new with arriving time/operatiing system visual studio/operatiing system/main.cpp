// operatiing system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<iostream>
#include<conio.h>


using namespace std;

int wating_time2(int arr[5], int QT, int &tt, int &p, int at[], int bt[]);

int gtq(int arr[5]);

int zindex(int arr[], int zz = 0);

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void alpha(int arr[],int high = 4)//arr[], low, high)
{
	//int arr[] 
	int low = 0;
	//int high = 4

	// pivot (Element to be placed at right position)
	int pivot = arr[high];

	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	//for (int j = low; j <= high; j++)
		//cout << arr[j] << " ";
	//cin.get();
	//return 0;
}

/*{
	int maxx = 5;
	//cout<<"check z enter"<<endl;
	int c = 0;
	int j = 0;
	for (int i = 0; i < maxx; i++)
		if (arr[i] != 0)
		{
			j = i;
			c++;
		}
	//cout<<"check z exit"<<endl;
	if (zz == 1)
		return c;
	if (c <= 1)
		return j;
	return -1;

}*/

int wating_time(int arr[], int QT)
{
	int r_no = zindex(arr, 1);
	int c = 0;
	int maxx = 5;
	int wt = 0;
	for (int i = 0; i < maxx; i++)
	{
		if (arr[i] != 0) {
			if (arr[i] <= QT)
			{
				wt += arr[i] * (r_no - c - 1);
				arr[i] = 0;
				c++;
			}
			else
			{
				wt += QT * (r_no - c - 1);
				arr[i] -= QT;
				
			}
		}

	}
	
	return(wt);
}

void display(int arr[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

/*
void wait() {
	char p = 'p';
	while (p != 'c') {
		ifstream f("sema.txt", ios::in);
			f >> p;
			f.close();
	}
}
 
void signal()
{
	ofstream f("sema.txt", ios::out);
	f << "p";
	f.close();
}

void writeBT(int arr[5])
 {
	 ofstream f("s.txt", ios::out);
	 for (int i = 0; i < 4; i++)
		 f << arr[i] << ",";
	 f << arr[4];
	 f.close();
 }

int readTQ()
 {
	 ifstream f("s.txt", ios::in);
	 int a;
	 f>> a;
	 f.close();
	 return a;
 }
 */

int avg(int arr[])
{
	int avg = 0;
	for (int i = 0; i < 5; i++)
	{
		avg = avg + arr[i];
	}
	return (avg);
}

int main()
{
	
	cout << "enter burst time";
	int bt[5];
	for(int i=0;i<5;i++)
	cin >> bt[i];
	cout << "enter arrival time";
	int at[5];
	for (int i = 0; i < 5; i++)
		cin >> at[i];
	//int iii = 0;
	int p = 0;
	int arr[] = { 0,0,0,0,0 };

	while (at[p] == 0)
	{
		arr[p] = bt[p];
		p++;
	}

	cout << "array before sort\n";
	display(arr);
	alpha(arr,p-1);
	cout << "array after sort\n";
	display(arr);
	
	int i = 0;
	int totalw=0;
	int tt = 0;
	int idle = 0;
	do
	{
		alpha(arr, p - 1);
		if (zindex(arr, 1) == 1)
			i = arr[zindex(arr, 0)];
		else	
			i = gtq(arr);

		
		
		cout << "-------------------------------------------start-------------------------------------------\n\n\n";
		cout << "\n\nPROCESS BEFORE CYCLE\n";
		display(arr);
		cout << endl;
		cout << "Time Quantum Predicted : " << i << "\n\n";
		int wt = wating_time2(arr, i, tt,p,at,bt);
			totalw += wt;
		
		
		cout << "\n\n\nwating time: "<<wt<<"\n\narray after cycle:";
		display(arr);

		cout << "--------------------------------------------end--------------------------------------------\n\n";
		//debug
		//cout << "\np: " << p << "\ntq: " << i << "\n\n\n";
		if (zindex(arr, 1) <= 0)
			if (p < 5)
			{
				//debug
				//cout << "debug idle" << "\nnxt arrival" << at[p] << "\ntt" << tt << endl;
				//debug
				int idle1 = at[p] - tt;
				idle += idle1;
				arr[p] = bt[p];
				tt = at[p];
				p++;
				
				cout << "PROCESSOR IDEL FOR :" << idle1 << "\n\nPROCESS " << arr[p - 1] << "  entered at " << at[p - 1] << "\n\n\n";
			}
			else
				break;
		
		char k;
		cin >> k;
		


	} while (i != -1);
	cout << "Total Wating Time =" << totalw/5;
	cout << "\nTotal IDLE Time   =" << idle;
	cout << "\nTotal Turn-around Time   =" << (totalw+avg(bt)+idle)/5;

	char k;
	cin >> k;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
