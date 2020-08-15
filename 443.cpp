#include <iostream>

int ladder(int n);

int ladder(int n){
	if(n == 1 ) return 1;
	else if(n == 2) return 2;
	else if(n == 3) return 4;
	else return ladder(n - 1) + ladder(n - 2) + ladder(n - 3); 
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << ladder(n) << '\n';
	return 0;
}
