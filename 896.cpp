#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
void solve(int Nl[], int N, int Ml[], int M){
	int current = 0;
	for(int i = 0; i < N; i++){
		while(Nl[i] != 0){
			if(Nl[i] > Ml[current]){
				if(current >= M) break;
				current++;
			}
			else{
				Ml[current] -= Nl[i];
				Nl[i] = 0;
			}
		}
	}
	v.push_back(current+1);
}
int main(){
	int N, M, tN = 0, tM = 0;
	int Nl[11] , Ml[11];
	cin >> N >> M;
	for(int i = 0 ; i < N; i++){
		cin >> Nl[i];
		tN += Nl[i];
	}
	for(int i = 0 ; i < M; i++){
		cin >> Ml[i];
		tM += Ml[i];
	}
	if(tN > tM){
		cout << "-1" << endl;
		return 0;
	}
	sort(Ml, Ml+M);
	reverse(Ml, Ml+M);
	sort(Nl, Nl+N);
	do{
		int tmp[21], tmpB[21];
		for(int i = 0; i < N; i++){
			tmp[i] = Nl[i];
		}
		for(int i = 0; i < M; i++){
			tmpB[i] = Ml[i];
		}
		solve(tmp, N, tmpB, M-1);
	}while(next_permutation(Nl, Nl+N));
	int min = v[0];
	for(int i = 1; i < v.size(); i++){
		if((v[i]) < min) min = v[i];
	}
	cout << min << endl;
	return 0;
}
