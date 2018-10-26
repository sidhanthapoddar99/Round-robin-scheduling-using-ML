// operatiing system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void alpha(int arr[])//arr[], low, high)
{
	//int arr[]
	int low = 0;
	int high = 4;

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
int zindex(int arr[], int zz = 0)
{
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

}

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
int main()
{

	cout << "enter new array\n";
	int arr[5];
	for(int i=0;i<5;i++)
	cin >> arr[i];
	cout << "\n\narray before sort\n";
	display(arr);
	alpha(arr);
	cout << "\n\narray after sort\n";
	display(arr);
    cout<<"         -----------------------------------------------------------------------------\n\n";
	int i = 0;
	int totalw=0;
	do
	{
		//cout << "wait" << endl;
		wait();
		writeBT(arr);
		signal();
		wait();
		i = readTQ();
		cout<<"time quantum selected = "<<i<<endl;
		int wt = wating_time(arr, i);
			totalw += wt;
		cout << "wating time = " << wt << "\n\n";

		display(arr);

		if (zindex(arr, 1) <= 1)
			break;


    cout<<"         -----------------------------------------------------------------------------\n\n";
		getch();



	} while (i != -1);

	cout << "\n\ntotal wating = " << totalw;
	cout<<"average wating time= " << totalw/5;
	getch();
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
