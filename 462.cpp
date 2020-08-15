#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char words[10000]={' '};
	cin>>words;
	int times;
	cin>>times;
	
	char cmd[20]={' '};
	int cLR;
	for(cLR=0;words[cLR] !='\0';cLR++);
	char out[10000]={' '};
	int cmdTimes;
	for(int i=0;i<times;i++)
	{
		
		cin>>cmd>>cmdTimes;
		int modeLR =cmdTimes%cLR;
		int modeUD =cmdTimes%26;
		if(strcmp(cmd,"up")==0)
		{
			for(int i=0;words[i] !='\0';i++)
			{
				out[i]=(char)((words[i]-'a'+modeUD)%26+'a');
			}
			strcpy(words,out);
			cout<<out;
		}
		else if(strcmp(cmd,"down")==0)
		{
			for(int i=0;words[i] !='\0';i++)
			{
				out[i]=((char)(words[i]-'a'+26-modeUD)%26+'a');
			}
			strcpy(words,out);
			cout<<out;	
		}
		else if(strcmp(cmd,"left")==0)
		{
			for(int i=0;words[i] !='\0';i++)
			{
				if(i<modeLR)
				{
					out[i+cLR-modeLR]=words[i];
				}
				else
				{
					out[i-modeLR]=words[i];
				}
				
			}
			strcpy(words,out);
			cout<<out;
		}
		else if(strcmp(cmd,"right")==0)
		{
			for(int i=0;words[i] !='\0';i++)
			{
				if(i+modeLR>cLR-1)
				{
					out[i-cLR+modeLR]=words[i];
				}
				else
				{
					out[i+modeLR]=words[i];
				}
			}
			strcpy(words,out);
			cout<<out;
		}
		cout<<endl;
	}
	return 0;
}

