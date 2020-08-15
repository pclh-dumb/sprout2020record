#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int length,j=0;
	int count[27]={0};
	cin>>length;
	char words[100000]={' '};
	char out[length+1]={};
	cin>>words;
	for(int i=0;i<length;i++)
	{
		if(words[i] >='a' && words[i]<='z')
		{
			out[j]=words[i];
			count[out[j]-'a'] +=1;
			j++;
		}
		else if(words[i] >='A' && words[i]<='Z')
		{
			out[j]=words[i]^' '; 
			count[out[j]-'a'] +=1;
			j++;
		}
	}
	cout<<out<<endl;
	for(int i=0;i<25;i++)
	{
		cout<<count[i]<<' ';
	}
	cout<<count[25]<<endl;
	return 0;
}
