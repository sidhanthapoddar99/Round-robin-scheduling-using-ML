#include<iostream>
#include<fstream>
using namespace std;

const int maxx = 7;
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
	/*int arr[] = { 215,299,159,55,211 };
	cout << rec(arr, 1);
	alpha(arr);
	cout << rec(arr,1);
	int arr1[] = { 178,198,29,129,10 };
	cout << rec(arr1, 1);
	alpha(arr1);
	cout << rec(arr1, 1);
	int arr2[] = { 105,9,13,24,16 };
	cout << rec(arr2, 1);
	alpha(arr2);*/
	setmax1(maxx);
	setmax2(maxx);
	wrt = 0;
	int arr3[maxx];
	cout << "enter the array to be generated/added :: ";
	for (int i = 0; i < maxx; i++)
		cin >> arr3[i];
	cout << "generate csv?(1/0)";
	cin >> wrt;
	alpha(arr3);

	int k1 = maxi(arr3) + 1;
	int *arr5=new int[k1];
	for (int i = 0; i < k1; i++)
		arr5[i] = -1;
	

	//cout << rec2(arr3,arr5, 0);
	cout << rec(arr3, 0);


	//for (int i = 0; i < k1; i++)
		//cout << arr5[i] << " ";

	//cout << rec(arr3, 0);




	/*for (int i = 7; i <= 12; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[j] > 0) {
				arr[j]-=1;
				cout << rec(arr, 0) / 5;

			}
			

		}
	}*/
	/*for(int j=0;j<maxx;j++)
	cout<<arr[j]<<"  ";
	cout<<endl;
	cout<<"wating time:"<<wating_time(arr,3);
	cout<<endl;
	for(int j=0;j<maxx;j++)
	cout<<arr[j]<<"  ";
	cout<<endl;*/
	//cout<<mini(arr);
	cin.get();
	int zzzx;
	cin >> zzzx;
	return 0;

}

