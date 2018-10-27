#include "pch.h"
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
void display1(int arr[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
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
//int wt_for_1_process

int wating_time2(int arr[], int TQ ,int &tt,int &p,int at[],int bt[])
{
	int r_no = zindex(arr, 1);
	int c = 0;
	int maxx = 5;
	int wt = 0;
	int QT = TQ;
	int flag = 1;
	for (int i = 0; i < p && flag==1; i++)
	{
		int rev_flag = 0;
		
	reval:
		if ((r_no==5 || arr[i]==0 )&&(rev_flag == 1) )
			return wt;
		//denug
		//cout << "IB:" << i << endl << endl;
		if (arr[i] != 0) {
			if (p < 5) {
				if ((QT + tt) > at[p] && (arr[i]+tt)>at[p])
				{
					//debug
					//cout << "---------------------->" << (at[p] - tt) << "\n\n";
					
					
					if (bt[p] < (0.5*QT)) {
						int ttq = at[p] - tt;
						wt += ttq * (r_no - c);
						tt += ttq;
						arr[i] -= ttq;
						//add_to_front
						for (int k = p; k > 0; k--)
						{
							arr[k] = arr[k - 1];
						}
						arr[0] = bt[p];						
						p++;
						cout << "BREAK CYCLE-----process entered with bt: " << bt[p - 1] << endl;
						cout << "Waiting time for all process: " << ttq * (r_no - c)<<endl;
						display1(arr);


						return(wt);
						
					}
					else
					{
						
						arr[p]=bt[p];
						int www = (at[p] - tt)* (r_no - c - 1);
						wt += www;
						arr[i] -= (at[p] - tt);
						tt += (at[p] - tt);
						
						p++;
						r_no++;
						
						//debug
						//cout << "****************\nwt " << wt << "\ntt " << tt << "\np " << p << "\narr[i]" << arr[i] << "\nc " << c << endl;
						cout << "CONTINUE CYCLE-----process entered with bt: " << "process entered with bt: " << bt[p - 1] << endl;
						cout << "Waiting time for all process: " << www <<endl;
						//debug
						//cout<<"at---->"<<

						display1(arr);
						/*
						debug - dry run
						display1(bt);
						cout<< "\n\n***************************\n\n";
						*/
						rev_flag = 1;
						goto reval;

					}
				}
			
			}
			if (flag == 1) {
				int www;
				if (arr[i] <= QT)
				{
					wt += arr[i] * (r_no - c - 1);
					www = arr[i] * (r_no - c - 1);
					tt += arr[i];
					arr[i] = 0;
					c++;
				}
				else
				{
					wt += QT * (r_no - c - 1);
					www = QT * (r_no - c - 1);
					tt += QT ;
					arr[i] -= QT;

				}
				cout << "CONTINUE CYCLE P"<<i<< "   processed " << endl;
				cout << "Waiting time for all process: " << www << endl;
				display1(arr);

			}
		}

	}

	return(wt);
}
