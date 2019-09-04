#include<iostream>
#include<fstream>
using namespace std;

int maxx1;

void setmax1(int x)
{
	maxx1 = x;
}

int zindex(int arr[], int zz = 0)
{
	//cout<<"check z enter"<<endl;
	int c = 0;
	int j = 0;
	for (int i = 0; i < maxx1; i++)
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


void writetofile(int arr[], int a)
{
	ofstream ofile;
	ofile.open("a.csv", ios::out | ios::app);
	for (int i = 0; i < maxx1; i++)
		ofile << arr[i] << ",";
	ofile << a << endl;
	ofile.close();


}


int mini(int arr[])
{
	int min = 0;
	for (int i = 0; i < maxx1; i++)
		if (min == 0 || (arr[i] < min && arr[i] != 0))
			min = arr[i];
	return min;
}


int maxi(int arr[])
{
	int max = 0;
	for (int i = 0; i < maxx1; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}


int wating_time(int arr[], int QT)
{
	int r_no = zindex(arr, 1);
	int c = 0;

	int wt = 0;
	for (int i = 0; i < maxx1; i++)
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
				/*if (arr[i] <= QT/12)//new algo
				{
					wt += arr[i] * (r_no - c - 1);
					arr[i] = 0;
					c++;
				}*/
			}
		}

	}
	/*for(int j=0;j<maxx1;j++)
	cout<<arr[j]<<"  ";
	cout<<"  QT- "<<QT<<"  wt "<<wt<<endl;*/
	return(wt);
}