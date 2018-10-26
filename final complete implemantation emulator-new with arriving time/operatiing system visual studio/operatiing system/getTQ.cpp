
#include "pch.h"
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

void wait() 
{
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
	f >> a;
	f.close();
	return a;
}
int gtq(int arr[5])
{
	cout << "wait" << endl;
	wait();
	writeBT(arr);
	signal();
	wait();
	return(readTQ());
}