#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include "bmp_handler.h"
#ifdef _WIN32
	#include <cwindows>
#else
	#include <unistd.h>
#endif
using namespace std;
void filter(BMP pic, int now, int cur);
void sleep(int time){
	#ifdef WIN32 
		Sleep(time);
	#else
		usleep(time);
	#endif
}
void cleanScreen(){
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
const int R = 2, G = 1, B = 0;
int main(){
#ifdef _WIN32
	system("chcp 65001");
#endif
	char filename[] = "pac.bmp";
	BMP bmp(filename);
	char filename2[] = "30pacmanClose.bmp";
	BMP close(filename2);

	cout << "successfully input your file : " << filename << endl;
	cout << "successfully input your file : " << filename2 << endl;
	int height = bmp.height(), width = bmp.width();

	cout << "height = " << height << endl;
	cout << "width = " << width << endl;
	int now = 0, cur = 0;
	while(now < 14100){ //150*94(ASCII 33~126)
		filter(bmp, now%150, cur);
		if(now % 15 == 0){
			sleep(15000);
			cleanScreen();
			filter(close, now%150, cur);
			sleep(100000);
		}
		sleep(30000);
		cleanScreen();
		now++;
		if(now % 150 == 0) cur++;
		}
	return 0;
}

void filter(BMP pic, int now, int cur){
	//cout << "now=" << now << endl;
	int list[11] = {1, 2, 1, 2, 4, 2, 1, 2, 1};
	int height = pic.height(), width = pic.width();
	int move[11][3] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1},
					   {1, -1}, {1, 0}, {1, 1}};
	float picList[height+1][width+1][4] = {0};
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			for(int k = 0; k < 9; k++){
				if(i + move[k][0] >= 0 && i + move[k][0] < height &&
				   j + move[k][1] >= 0 && j + move[k][1] < width){
					picList[i][j][0] = picList[i][j][0] + (pic.bitmap[i+move[k][0]][j+move[k][1]][0] * list[k]);
					picList[i][j][1] = picList[i][j][1] + (pic.bitmap[i+move[k][0]][j+move[k][1]][1] * list[k]);
					picList[i][j][2] = picList[i][j][2] + (pic.bitmap[i+move[k][0]][j+move[k][1]][2] * list[k]);
				}
			}
		}
	}
	for(int i = 0; i < height; i++){
		for(int z = 0; z < now; z++) cout << " ";
		for(int j = 0; j < width; j++){
			if((int)picList[i][j][R]/16 < 230 && (int)picList[i][j][G]/16 < 230 && (int)picList[i][j][B]/16 < 180){
				printf("%c", cur + 33);
			}
			else{
				printf(" ");
			}
		}
		cout << endl;
	}
}
