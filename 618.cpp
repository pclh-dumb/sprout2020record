#include <iostream>
#include <cstring>
using namespace std;

int map_size;
char map[20][20];
bool isValid(int current[], char dir);
bool isArrived(int start[], int end[], char command[]);

//下方為我實作的部分 
bool isValid(int current[], char dir)
{
	if(dir == 'L' && current[1] > 0) 
	{
		if(map[current[0]][current[1] - 1] != 'o')
		{
			return 1;
		}
		return 0;
	}
	if(dir == 'R' && current[1] < map_size - 1) 
	{
		if(map[current[0]][current[1] + 1] != 'o')
		{
			return 1;
		}
		return 0;
	}
	if(dir == 'U' && current[0] > 0) 
	{
		if(map[current[0] - 1][current[1]] != 'o')
		{
			return 1;
		}
		return 0;
	}
	if(dir == 'D' && current[0] < map_size - 1) 
	{
		if(map[current[0] + 1][current[1]] != 'o')
		{
			return 1;
		}
		return 0;
	}
	return 0;
} 

bool isArrived(int start[], int end[], char command[])
{
	
	for(int i = 0; i < strlen(command); i++)
	{
		if(start[0] == end[0] && start[1] == end[1])
		{
			return 1;
		}
		else if(isValid(start, command[i]))
		{
			if(command[i] == 'L')
			{
				start[1] -= 1;
			}
			else if(command[i] == 'R')
			{
				start[1] += 1;
			}
			else if(command[i] == 'U')
			{
				start[0] -= 1;
			}
			else if(command[i] == 'D')
			{
				start[0] += 1;
			}
		}
		else
		{
			return 0;
		} 
	}
	if(start[0] == end[0] && start[1] == end[1])
		{
			return 1;
		}
	else
	{
		return 0;
	}	
} 
//上方為我實作的部分 

int main() {
	char command[100];
	int start[2]; // position: (start[0], start[1])
	int end[2];

	// read map size
	cin>>map_size;

	// read map
	for (int i=0; i<map_size; i++) {
		for (int j=0; j<map_size; j++) {
			cin>>map[i][j];
		}
	}

	// read start and end position
	cin>>start[0]>>start[1];
	cin>>end[0]>>end[1];

	// read command
	cin>>command;

	if (isArrived(start, end, command)) 
		cout<<"Get the mask";
	else cout<<"Cry";
}	






//226 
//#include <iostream>
//
//int range(int array[],int size);
//double average(int array[],int size);
//
//int main()
//{
//  int scores[1000];
//  int n;
//
//  std::cin >> n;
//  for(int i = 0; i < n; i++)
//    std::cin >> scores[i];
//  
//  std::cout << "Max - Min = " << range(scores, n) << "\n";
//  std::cout << "Average = " << average(scores, n) << "\n";
//  
//  return 0;
//}          
//
//int range(int array[],int size)
//{
//	int max=0,min=101;
//	for(int i=0;i<size;i++)
//	{
//		if(array[i]<min)
//		{
//			min=array[i];
//		}
//		else if(array[i] >max)
//		{
//			max = array[i];
//		}
//	}
//	return max-min;
//} 
//double average(int array[],int size){
//	int sum=0;
//	for(int i=0;i<size;i++)
//	{
//		sum +=array[i];
//	}
//	return (double)sum/size;
//}



// -O2 <--優化 

//225
//int san_n_jia_i(int n)
//{
//	if(n==1) return 1;
//	else if(n%2==0) return n/2;
//	else if(n%2 !=0) return 3*n+1;
//} 

int abs(int a)
{
	if(a>0) return a;
	else return -1*a;
}
