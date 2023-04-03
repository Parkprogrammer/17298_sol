#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int top=-1;
int *okenArray, *Stacktoken, *Printoken;

int main()
{
	int Arraysize, Arrp;
	
	char *okenString, *token;
	
	cin >> Arraysize;
	Arrp = Arraysize-1;
	okenArray = (int*)malloc(sizeof(int)*Arraysize);
	okenString = (char*)malloc(sizeof(char)*Arraysize*8);
	Stacktoken = (int*)malloc(sizeof(int)*Arraysize);
	Printoken = (int*)malloc(sizeof(int)*Arraysize);
	//fill_n(Answoken,Arraysize,-1);
	
	cin.ignore();
	cin.getline(okenString,Arraysize*8);
	
	for(token = strtok(okenString," ");token;token=strtok(NULL," "),Arrp--)
		if(sscanf(token,"%d",&okenArray[Arrp])<1)
			break;
	
	for(int i=0;i<Arraysize;i++)
	{
		if(top==-1)
		{
			Printoken[i] = -1;
			Stacktoken[++top] = okenArray[i];
			continue;
		}
		
		if(okenArray[i]>=Stacktoken[top])
		{
			while(okenArray[i]>=Stacktoken[top] && top!=-1)
			{	
				if(top==0)
				{
					if(okenArray[i]>=Stacktoken[top])
					{
						Stacktoken[top]=okenArray[i];
						Printoken[i]=-1;
					}
					else
					{
						Printoken[i]=Stacktoken[top];
						Stacktoken[++top]=okenArray[i];
					}
					break;
				}
				top--;
			}
			
		}
		
		if(okenArray[i]<Stacktoken[top])
		{
			Printoken[i]=Stacktoken[top];
			Stacktoken[++top]=okenArray[i];
		}
		
		
	}
	
	for(int k=Arraysize-1;k>=0;k--)
	{
		if(k==0)
		{
			cout << Printoken[k];
			break;
		}
		cout << Printoken[k] << ' ';
	}
	
}
