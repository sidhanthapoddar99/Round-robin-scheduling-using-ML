#include<iostream>
#include<fstream>
using namespace std;

const int maxx = 5;
int wrt = 1;

void setmax2(int x);
void setmax1(int x);
void alpha(int arr[]);
int zindex(int arr[], int zz = 0);
void writetofile(int arr[], int a);
int mini(int arr[]);
int maxi(int arr[]);
int wating_time(int arr[], int QT);






//rec without dynamic programming
int rec(int arr[],int al=0)
{
	int z = zindex(arr);

	if (z != -1) {
		// cout<<"check final"<<endl;
		return(0);
	}

	//cout<<"check initial"<<endl;
	int twtf = 0;
	int flag;
	int c = 0;
	int k = mini(arr);
	//for (int i = k; i <= maxi(arr); i++)
	for (int i = k; i <= maxi(arr); i++)
	{

		int arr2[maxx];
		for (int j = 0; j<maxx; j++)
			arr2[j] = arr[j]; 
		int TWT = 0;
		int WT = wating_time(arr2, i);
		TWT = WT + rec(arr2);
		if (c == 0 || twtf>TWT)
		{

			//cout<<c<<"twt-"<<TWT<<"   twtf "<<twtf<<endl;
			flag = i;
			twtf = TWT;
			c = 1;
		}
	}
	//if (flag != k) {
	for (int j = 0; j<maxx; j++)
			cout << arr[j] << "  ";
		cout << " TQ :" << flag << "   wating time :" << twtf << endl << endl;
	//}
	if(wrt==1)
	writetofile(arr, flag);

	if (al == 0)
		return(twtf);
	else
		return flag;

}

// rec with dynamic programming
int rec2(int arr[], int *arr3, int al = 0)
{
	int z = zindex(arr);

	if (z != -1) {
		// cout<<"check final"<<endl;
		return(0);
	}
	int k1 = maxi(arr);
	if (arr3[k1] != -1)
	{
		return(arr3[k1]);
	}
	//cout<<"check initial"<<endl;
	int twtf = -1;
	int flag;
	int c = 0;
	int k = mini(arr);
	//for (int i = k; i <= maxi(arr); i++)
	for (int i = k; i <= k1; i++)
	{

		//creating a temporary variable
		int arr2[maxx];
		for (int j = 0; j < maxx; j++)
			arr2[j] = arr[j];


		int TWT = 0;
		int WT = wating_time(arr2, i);
		TWT = WT + rec2(arr2,arr3);
		
		if (twtf==-1 || twtf > TWT)
		{	
			//cout<<c<<"twt-"<<TWT<<"   twtf "<<twtf<<endl;
			flag = i;
			twtf = TWT;
		}
	}
	
	for (int j = 0; j < maxx; j++)
		cout << arr[j] << "  ";
	cout << " TQ :" << flag << "   wating time :" << twtf << endl << endl;
	
	arr3[k1] = twtf;

	if (wrt == 1)
		writetofile(arr, flag);

	if (al == 0)
		return(twtf);
	else
		return flag;

}


int main()
{
	//int arr[] = { 152,95,1,232,12 };
	//int arr[] = { 105,85,55,43,35 };
	//int arr[] = { 105,61,120,48,75 };
	//int arr[] = { 75,48,61,105,120 };
	//int arr[] = { 35 ,85, 55, 43, 105 };
	//int arr[] = { 43,35,105,85,55 };
	//int arr[] = { 35,2,37,58,3,43,1,38,137,19 };
	//int arr[]={0,0,2,6,8,0,0,5,0,0};
	//int arr[]={0,0,0,0,0,0,0,5,0,0};
	//int arr[] = { 215,299,159,55,211 };

	setmax1(maxx);
	setmax2(maxx);
	wrt = 0;
	int arr3[maxx];
	

	cout << "enter the array to be generated/added :: ";
	for (int i = 0; i < maxx; i++)
		cin >> arr3[i];
	cout << "generate csv?(1/0)";
	cin >> wrt;
	
	//wrt = 1;

	alpha(arr3);

	//this part is for dynamic programming maxi is the max value of the array set entrered 
	//thus the maximum itterartion value or all the possible stats of the program for which the time quantum can be calculated
	
	int k1 = maxi(arr3) + 1;
	int *arr5=new int[k1];
	for (int i = 0; i < k1; i++)
		arr5[i] = -1;

	cout << rec2(arr,arr5, wrt);
	
	/*
	alpha(arr3);
	for (int i = 0; i < k1; i++)
		arr5[i] = -1;

	cout << rec2(arr3, arr5, 1);
	*/
	//cin.get();
	int zzzx;
	cin >> zzzx;
	return 0;

}

