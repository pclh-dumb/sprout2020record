#include <iostream>
using namespace std;
int main(){
	int n, q;
	int rate[100003] = {0};
	cin >> n >> q;
	// cin the stars
	for(int i = 0; i < n; i++){
		cin >> rate[i];
	}
	// cin the question
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		int leftL = 0, rightL = n - 1, avgL, leftR = 0, rightR = n - 1, avgR;
		int count1 = 0, countn = 0;
		while(1){
			avgL = (leftL + rightL) / 2;
				avgL = 0;
				break;
			}
			if(l > rate[n - 2]){
				avgL = n - 1;
				break;
			}
			if(rate[avgL] >= l){
				if(rate[avgL - 1] < l){
					break;
				}
				rightL = avgL;
			}
			else{
				leftL = avgL;
			}
		}
		count1 = 0;
		countn = 0;
		while(1){
			avgR = (leftR + rightR) / 2;
			if(r >= rate[n - 1]){
				if(r == rate[n - 1]){
					avgR = n - 2;
				}
				else{
					avgR = n - 1;
				}
				break;
			}
			if(rate[avgR] <= r){
				if(rate[avgR + 1] > r){
					if(rate[avgR] == r) avgR-- ;
					break;
				}
				leftR = avgR;
			}
			else{
				rightR = avgR;
			}
		}
		cout << avgR - avgL + 1 << endl;
	}
	return 0;
}
