#include <iostream>
#include <cstdlib>
#include <cmath>
#include "bmp_handler.h"

using namespace std;

const int R = 2, G = 1, B = 0;
int level(int num){
	if(num > 240) return 231;
	int start = 240, next = 230, nowLev = 232;
	while(next >= 0){
		if(num > next && num <= start) return nowLev;
		start -= 10;
		next -= 10;
		nowLev++;
	}
}

int main()
{
#ifdef _WIN32
    system("chcp 65001");
#endif

    char filename[] = "gold.bmp";
    BMP bmp(filename);

    cout << "successly input image : " << filename << endl;

    int height = bmp.height(), width = bmp.width();

    cout << "height = " << height << endl;
    cout << "width = " << width << endl;

	 unsigned int gray[height][width];
	 int deep[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
			gray[i][j] = sqrt((pow(bmp.bitmap[i][j][R], 2) +
							  pow(bmp.bitmap[i][j][G], 2) + 
							  pow(bmp.bitmap[i][j][B], 2)) / 3);

			deep[i][j] = level(gray[i][j]);
			cout << "\e[48;5;" << deep[i][j] << "m ";
		}
		cout << endl;
    }

    return 0;
}
