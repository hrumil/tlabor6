/** \file: main.cpp */
#include <iostream>
#include <conio.h>
using namespace std;
/** void main */
void main()
{
	int n; ///chislo uzlov v grafe
	cout<<"Enter number uzlov: "; 
	cin>>n;

	int *visit = new int[n]; /// massiv poseshaemosti reber
	int *way = new int[n]; /// massiv min vershin
	int **value = new int*[n]; /// massiv stoimostey
	for(int i=0; i<n; i++)
		value[i]=new int[n];
	int w=0;
	cout<<"Enter distance mezhdu uzlami: \n"; 
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==j)
				value[i][j]=0;
			if(i<j)
			{
				cout<<"Distance "<<i+1<<"-" <<j+1<<" = ";
				cin>>value[i][j];
				value[j][i]=value[i][j];
			}
		}
	}

	cout << "Matrix smezhnosti:"<<endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<value[i][j]<<"\t";
			if(value[i][j]==0)
				value[i][j]=INT_MAX; 
		}
		cout<<endl<<endl;
	}
	visit[0] = 1;
	for (int i=1; i<n; i++) 
		visit[i] = 0;

	/**Algorithm Prima**/
	int x,y,z=1,min;
	cout<<"Pary vershin ostovnogo dereva: ";
	while (z < n)
	{
		min=INT_MAX;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(value[i][j]<min)
				{
					if(visit[i]!=0)
					{
						min=value[i][j];
						x=i;
						y=j;
					}
				}
			}
		}
		
		if(visit[x]==0 || visit[y]==0)
		{
			way[w] = y;
			w++;
			z++;
			cout<<"\nRebro "<<x+1<<"-"<<y+1<<" = "<<min;
			visit[y]=1;
		}
		value[x][y]=value[y][x]=INT_MAX;
	}
	cout<<"\nMin ostovnoe derevo: ";
	cout<<"1 - ";
	for(int i=0; i<n-1; i++)
	{
		cout<<way[i]+1;
		if (i<n-2) 
			cout<<" - ";
	}
	_getch();
}