#undef UNICODE
#undef _UNICODE
#include<iostream>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
using namespace std;
//消除方块
void xiaochu(int	a[][10]);
/*
   a   二维数组
	type   方块类型  如长条形  L形状或方形等等
	x1 
*/
void fangkuai(int a[][10], int type, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
//方块缩略图  当前图形
void suoluetu(int);
//方块缩略图  下个图形
void suoluetu1(int);
//分数
int fenshu = 0;
//是否已经结束    0未结束  1已经结束 
int jc = 0;
int main()
{
	//i表示行 j 表示列 key表示  方块类型  如长条形  L形状或方形等等  k2 下一个出现的方块类型  如长条形  L形状或方形等等
	int	i = 0, j = 0, key = 0, k2;
	int	a[15][10];
	for (i = 0; i<15; i++)
		for (j = 0; j<10; j++)
		{
			a[i][j] = 0;
		}

	initgraph(520, 640);// 初始化900x900的绘图屏幕
	setaspectratio(0.8, 0.8);
	for (;;)
	{
		for (i = 0; i<15; i++)
			for (j = 0; j<10; j++)
			{
				a[i][j] = 0;
			}
		fenshu = 0;
		setbkcolor(WHITE);//设置背景色为白色
		cleardevice();//用背景色清屏
		setlinecolor(BLACK);//设置线条颜色
		setlinestyle(PS_SOLID, 3);//设置线条样式
		line(23, 25, 23, 775);//左边框
		line(527, 25, 527, 775);//右边框
		line(23, 23, 527, 23);//上边框
		line(23, 777, 527, 777);//下边框
		settextcolor(BLACK);
		char s[] = "当前分数:";
		settextstyle(25, 0, _T("宋体"));
		outtextxy(529, 25, s);
		char s1[5];
		sprintf(s1, "%d", fenshu);
		settextstyle(50, 0, _T("宋体"));
		outtextxy(560, 60, s1);
		settextcolor(BLACK);
		char s3[] = "当前图形:";
		settextstyle(25, 0, _T("宋体"));
		outtextxy(529, 120, s3);
		char s4[] = "下个图形:";
		settextstyle(25, 0, _T("宋体"));
		outtextxy(529, 250, s4);
		srand(time(0));


		for (i = 3, j = 1;;)
		{
			if (key == 0) //I型方块
			{
				i = 3;
				j = 1;
				suoluetu(key);
				srand(time(0));
				k2 = rand() % 7;
				suoluetu1(k2);
				fangkuai(a, key, i, j, i + 1, j, i + 2, j, i + 3, j);
				if (jc == 1)
					break;

				key = k2;

			}
			else if (key == 1)  //O型方块
			{
				i = 4;
				j = 0;
				suoluetu(key);
				srand(time(0));
				k2 = rand() % 7;
				suoluetu1(k2);
				fangkuai(a, key, i, j, i + 1, j, i, j + 1, i + 1, j + 1);
				if (jc == 1)
					break;
				key = k2;
			}
			else if (key == 2)  //T型方块
			{
				i = 4;
				j = 0;
				suoluetu(key);
				srand(time(0));
				k2 = rand() % 7;
				suoluetu1(k2);
				fangkuai(a, key, i, j, i - 1, j + 1, i, j + 1, i + 1, j + 1);
				if (jc == 1)
					break;

				key = k2;

			}
			else if (key == 3) //J型方块
			{
				i = 4;
				j = 0;
				suoluetu(key);
				srand(time(0));
				k2 = rand() % 7;
				suoluetu1(k2);
				fangkuai(a, key, i, j, i, j + 1, i + 1, j + 1, i + 2, j + 1);
				if (jc == 1)
					break;

				key = k2;
			}
			else if (key == 4)//Z型方块
			{
				i = 4;
				j = 0;
				suoluetu(key);
				srand(time(0));
				k2 = rand() % 7;
				suoluetu1(k2);
				fangkuai(a, key, i, j, i + 1, j, i + 1, j + 1, i + 2, j + 1);
				if (jc == 1)
					break;

				key = k2;

			}
			else if (key == 5)//S型方块
			{
				i = 4;
				j = 0;
				suoluetu(key);
				srand(time(0));
				k2 = rand() % 7;
				suoluetu1(k2);
				fangkuai(a, key, i, j, i + 1, j, i - 1, j + 1, i, j + 1);
				if (jc == 1)
					break;
				key = k2;

			}
			else if (key == 6)//L型方块
			{
				i = 4;
				j = 0;
				suoluetu(key);
				srand(time(0));
				k2 = rand() % 7;
				suoluetu1(k2);
				fangkuai(a, key, i, j, i - 2, j + 1, i - 1, j + 1, i, j + 1);
				if (jc == 1)
					break;
				key = k2;
			}
		}
		jc = 0;
	}
	cout << "失败" << endl;
	closegraph();
	return 0;
}


//当有行被填满时消除   每个方块落定后执行
void xiaochu(int	a[][10])
{
	int k, n, r;
	for (k = 14; k>0;)
	{
		if (a[k][0] == 1 && a[k][1] == 1 && a[k][2] == 1 && a[k][3] == 1 && a[k][4] == 1 && a[k][5] == 1 && a[k][6] == 1 && a[k][7] == 1 && a[k][8] == 1 && a[k][9] == 1)  //当一排的方块都被填充时，进行消除
		{
			Sleep(80);
			for (r = 0; r<10; r++)
			{
				setfillcolor(GREEN);
				solidrectangle(26 + 50 * r, 26 + k * 50, 74 + 50 * r, 74 + k * 50);

			}
			Sleep(350);
			for (r = 0; r<10; r++)
			{
				a[k][r] = 0;
				setfillcolor(WHITE);
				solidrectangle(26 + 50 * r, 26 + k * 50, 74 + 50 * r, 74 + k * 50);
				fenshu++;
			}
			for (n = k - 1; n>0; n--)
			{
				for (r = 0; r<10; r++)
				{
					if (a[n][r] == 1)
					{
						a[n][r] = 0;
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * r, 26 + n * 50, 74 + 50 * r, 74 + n * 50);

						a[n + 1][r] = 1;
						setfillcolor(YELLOW);
						solidrectangle(26 + 50 * r, 26 + (n + 1) * 50, 74 + 50 * r, 74 + (n + 1) * 50);

					}
				}
			}
		}
		else
			k--;

	}
	char s1[5];
	sprintf(s1, "%d", fenshu);
	settextstyle(50, 0, _T("宋体"));
	outtextxy(560, 60, s1);
	settextcolor(BLACK);

}
void fangkuai(int a[][10], int type, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	int c, d;
	int ci = 0, tx, ty;
	DWORD start, stop;
	int jiange = 0;
	if (a[y1][x1] == 0 && a[y2][x2] == 0 && a[y3][x3] == 0 && a[y4][x4] == 0)
	{
		a[y1][x1] = 2;
		a[y2][x2] = 2;
		a[y3][x3] = 2;
		a[y4][x4] = 2;
		setfillcolor(BLUE);
		solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
		solidrectangle(26 + 50 * x2, 27 + y2 * 50, 73 + 50 * x2, 74 + y2 * 50);
		solidrectangle(26 + 50 * x3, 27 + y3 * 50, 73 + 50 * x3, 74 + y3 * 50);
		solidrectangle(26 + 50 * x4, 27 + y4 * 50, 73 + 50 * x4, 74 + y4 * 50);

	}
	else
	{
		setfillcolor(BLUE);
		solidrectangle(26 + 50 * x1, 27 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
		solidrectangle(26 + 50 * x2, 27 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
		solidrectangle(26 + 50 * x3, 27 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
		solidrectangle(26 + 50 * x4, 27 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
		Sleep(1000);
		setbkcolor(WHITE);//设置背景色为白色
		cleardevice();//用背景色清屏
		
	
			char s[] = "最终分数:";
			settextstyle(50, 0, _T("宋体"));
			outtextxy(175, 375, s);
			char s1[5];
			sprintf(s1, "%d", fenshu);
			settextstyle(50, 0, _T("宋体"));
			outtextxy(400, 375, s1);
			Sleep(2000);
		//以下代码为文字事件  （当然表白什么的被我删惹）
		/*
		if (fenshu == 0)
		{
			setbkcolor(WHITE);//设置背景色为白色
			cleardevice();//用背景色清屏
			char s3[] = "智商为零";
			settextstyle(50, 0, _T("宋体"));
			outtextxy(210, 375, s3);
		}
		else	if (fenshu<100)
		{
			setbkcolor(WHITE);//设置背景色为白色
			cleardevice();//用背景色清屏
			char s3[] = "智商捉急←_←";
			settextstyle(50, 0, _T("宋体"));
			outtextxy(180, 375, s3);
		}
		else if (fenshu >= 100 && fenshu<250)
		{
			setbkcolor(WHITE);//设置背景色为白色
			cleardevice();//用背景色清屏
			char s3[] = "智商不如250 不过还可以哦≧﹏≦";
			settextstyle(30, 0, _T("宋体"));
			outtextxy(100, 375, s3);
		}
		else if (fenshu == 250)
		{
			setbkcolor(WHITE);//设置背景色为白色
			cleardevice();//用背景色清屏
			char s3[] = "智商高达250→_→";
			settextstyle(50, 0, _T("宋体"));
			outtextxy(130, 375, s3);
		}
		else if (fenshu>250 && fenshu<500)
		{
			setbkcolor(WHITE);//设置背景色为白色
			cleardevice();//用背景色清屏
			char s3[] = "诶呦不错哦~\(≧▽≦)/~";
			settextstyle(40, 0, _T("宋体"));
			outtextxy(130, 375, s3);
		}
		else if (fenshu == 500)
		{
			setbkcolor(WHITE);//设置背景色为白色
			cleardevice();//用背景色清屏
			char s3[] = "智商等于两个250=￣ω￣=";
			settextstyle(40, 0, _T("宋体"));
			outtextxy(95, 375, s3);
		}
		*/
		Sleep(3000);
		jc++;
	}
	start = GetTickCount();
	for (;;)
	{
		stop = GetTickCount();
		if (kbhit() == 1)  //判断用户是否按键
		{
			c = getch();
			if (kbhit() == 1)
			{
				d = getch();
				if (c == 224 && d == 72)   // 当用户点击键盘 上键（翻转方块）
				{
					if (type == 0 && a[y1 - 1][x1 + 1] != 1 && a[y3 + 1][x3 - 1] != 1 && a[y4 + 2][x4 - 2] != 1 && y1 - 1 >= 0 && y4 + 2 <= 14 && ci == 0)
					{
						a[y1][x1] = 0;
						a[y3][x3] = 0;
						a[y4][x4] = 0;
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * (x1 + 1), 26 + (y1 - 1) * 50, 74 + 50 * (x1 + 1), 74 + (y1 - 1) * 50);
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * (x3 - 1), 26 + (y3 + 1) * 50, 74 + 50 * (x3 - 1), 74 + (y3 + 1) * 50);
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * (x4 - 2), 26 + (y4 + 2) * 50, 74 + 50 * (x4 - 2), 74 + (y4 + 2) * 50);
						y1--;
						x1++;
						y3++;
						x3--;
						y4 += 2;
						x4 -= 2;
						ci++;
					}
					else	if (type == 0 && a[y1 + 1][x1 - 1] != 1 && a[y3 - 1][x3 + 1] != 1 && a[y4 - 2][x4 + 2] != 1 && x1 - 1 >= 0 && x3 + 2 <= 9 && ci == 1)
					{
						a[y1][x1] = 0;
						a[y3][x3] = 0;
						a[y4][x4] = 0;
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * (x1 - 1), 26 + (y1 + 1) * 50, 74 + 50 * (x1 - 1), 74 + (y1 + 1) * 50);
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * (x3 + 1), 26 + (y3 - 1) * 50, 74 + 50 * (x3 + 1), 74 + (y3 - 1) * 50);
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * (x4 + 2), 26 + (y4 - 2) * 50, 74 + 50 * (x4 + 2), 74 + (y4 - 2) * 50);
						y1++;
						x1--;
						y3--;
						x3++;
						y4 -= 2;
						x4 += 2;
						a[y1][x1] = 2;
						a[y3][x3] = 2;
						a[y4][x4] = 2;
						ci--;
					}
					else	if (type == 2)
					{
						if (a[y3 - 1][x3 - 1] != 1 && y3 - 1 >= 0 && ci == 2)
						{
							a[y3][x3] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x3 - 1), 26 + (y3 - 1) * 50, 74 + 50 * (x3 - 1), 74 + (y3 - 1) * 50);
							y3--;
							x3--;
							a[y3][x3] = 2;
							tx = x1;
							ty = y1;
							x1 = x3;
							y1 = y3;
							x3 = x2;
							y3 = y2;
							x2 = tx;
							y2 = ty;
							ci++;
						}
						else if (type == 2 && a[y4 - 1][x4 + 1] != 1 && x4 + 1 <= 9 && ci == 3)
						{
							a[y4][x4] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x4 + 1), 26 + (y4 - 1) * 50, 74 + 50 * (x4 + 1), 74 + (y4 - 1) * 50);
							y4--;
							x4++;
							a[y4][x4] = 2;
							ci = 0;
						}
						else	if (a[y2 + 1][x2 + 1] != 1 && y2 + 1 <= 14 && ci == 0)
						{
							a[y2][x2] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x2 + 1), 26 + (y2 + 1) * 50, 74 + 50 * (x2 + 1), 74 + (y2 + 1) * 50);
							x2++;
							y2++;
							a[y2][x2] = 2;
							tx = x4;
							ty = y4;
							x4 = x2;
							y4 = y2;
							x2 = x3;
							y2 = y3;
							x3 = tx;
							y3 = ty;
							ci++;
						}
						else	if (a[y1 + 1][x1 - 1] != 1 && x1 - 1 >= 0 && ci == 1)
						{
							a[y1][x1] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x1 - 1), 26 + (y1 + 1) * 50, 74 + 50 * (x1 - 1), 74 + (y1 + 1) * 50);
							x1--;
							y1++;
							a[y1][x1] = 2;
							ci++;
						}
					}
					else	if (type == 3)
					{
						if (a[y1 - 1][x1 + 1] != 1 && a[y3 + 1][x3 - 2] != 1 && a[y4][x4 - 1] != 1 && y1 - 1 >= 0 && ci == 2)
						{
							a[y1][x1] = 0;
							a[y3][x3] = 0;
							a[y4][x4] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x1 + 1), 26 + (y1 - 1) * 50, 74 + 50 * (x1 + 1), 74 + (y1 - 1) * 50);
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x3 - 2), 26 + (y3 + 1) * 50, 74 + 50 * (x3 - 2), 74 + (y3 + 1) * 50);
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x4 - 1), 26 + y4 * 50, 74 + 50 * (x4 - 1), 74 + y4 * 50);
							y1--;
							x1++;
							y3++;
							x3 -= 2;
							x4--;
							a[y1][x1] = 2;
							a[y3][x3] = 2;
							a[y4][x4] = 2;
							ci++;
						}
						else	if (a[y1][x1 - 1] != 1 && a[y2][x2 - 1] != 1 && a[y3 - 1][x3 + 1] != 1 && a[y4 - 1][x4 + 1] != 1 && x4 + 1 <= 9 && ci == 3)//消除法
						{
							a[y1][x1] = 0;
							a[y2][x2] = 0;
							a[y3][x3] = 0;
							a[y4][x4] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x1 - 1), 26 + y1 * 50, 74 + 50 * (x1 - 1), 74 + y1 * 50);
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x2 - 1), 26 + y2 * 50, 74 + 50 * (x2 - 1), 74 + y2 * 50);
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x3 + 1), 26 + (y3 - 1) * 50, 74 + 50 * (x3 + 1), 74 + (y3 - 1) * 50);
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x4 + 1), 26 + (y4 - 1) * 50, 74 + 50 * (x4 + 1), 74 + (y4 - 1) * 50);
							x1--;
							x2--;
							y3--;
							x3++;
							y4--;
							x4++;
							a[y1][x1] = 2;
							a[y2][x2] = 2;
							a[y3][x3] = 2;
							a[y4][x4] = 2;
							ci = 0;
						}
						else	if (a[y1][x1 + 1] != 1 && a[y2 - 1][x2 + 2] != 1 && a[y3][x3] != 1 && a[y4 + 1][x4 - 1] != 1 && y4 + 1 <= 14 && ci == 0)//消除法
						{
							a[y1][x1] = 0;
							a[y2][x2] = 0;
							a[y4][x4] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x1 + 1), 26 + y1 * 50, 74 + 50 * (x1 + 1), 74 + y1 * 50);
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x2 + 2), 26 + (y2 - 1) * 50, 74 + 50 * (x2 + 2), 74 + (y2 - 1) * 50);
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x4 - 1), 26 + (y4 + 1) * 50, 74 + 50 * (x4 - 1), 74 + (y4 + 1) * 50);
							x1++;
							y2--;
							x2 += 2;
							y4++;
							x4--;
							a[y1][x1] = 2;
							a[y2][x2] = 2;
							a[y4][x4] = 2;
							ci++;
						}
						else	if (a[y1 + 1][x1 - 1] != 1 && a[y2 + 1][x2 - 1] != 1 && a[y3][x3 + 1] != 1 && a[y4][x4 + 1] != 1 && x4 - 1 >= 0 && ci == 1)//消除法
						{
							a[y1][x1] = 0;
							a[y2][x2] = 0;
							a[y3][x3] = 0;
							a[y4][x4] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
							solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
							solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
							solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x1 - 1), 26 + (y1 + 1) * 50, 74 + 50 * (x1 - 1), 74 + (y1 + 1) * 50);
							solidrectangle(26 + 50 * (x2 - 1), 26 + (y2 + 1) * 50, 74 + 50 * (x2 - 1), 74 + (y2 + 1) * 50);
							solidrectangle(26 + 50 * (x3 + 1), 26 + y3 * 50, 74 + 50 * (x3 + 1), 74 + y3 * 50);
							solidrectangle(26 + 50 * (x4 + 1), 26 + y4 * 50, 74 + 50 * (x4 + 1), 74 + y4 * 50);
							y1++;
							x1--;
							y2++;
							x2--;
							x3++;
							x4++;
							a[y1][x1] = 2;
							a[y2][x2] = 2;
							a[y3][x3] = 2;
							a[y4][x4] = 2;
							ci++;
						}
					}
					else	if (type == 4)
					{
						if (a[y1][x1 + 2] != 1 && a[y2 + 1][x2] != 1 && a[y3][x3 + 1] != 1 && a[y4 + 1][x4 - 1] != 1 && y4 + 1 <= 14 && ci == 0)//消除法
						{
							a[y1][x1] = 0;
							a[y2][x2] = 0;
							a[y3][x3] = 0;
							a[y4][x4] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
							solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
							solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
							solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x1 + 2), 26 + y1 * 50, 74 + 50 * (x1 + 2), 74 + y1 * 50);
							solidrectangle(26 + 50 * x2, 26 + (y2 + 1) * 50, 74 + 50 * x2, 74 + (y2 + 1) * 50);
							solidrectangle(26 + 50 * (x3 + 1), 26 + y3 * 50, 74 + 50 * (x3 + 1), 74 + y3 * 50);
							solidrectangle(26 + 50 * (x4 - 1), 26 + (y4 + 1) * 50, 74 + 50 * (x4 - 1), 74 + (y4 + 1) * 50);
							x1 += 2;
							y2++;
							x3++;
							y4++;
							x4--;
							a[y1][x1] = 2;
							a[y2][x2] = 2;
							a[y3][x3] = 2;
							a[y4][x4] = 2;
							ci++;
						}
						else	if (a[y1][x1 - 2] != 1 && a[y2 - 1][x2] != 1 && a[y3][x3 - 1] != 1 && a[y4 - 1][x4 + 1] != 1 && x1 - 2 >= 0 && ci == 1)//消除法
						{
							a[y1][x1] = 0;
							a[y2][x2] = 0;
							a[y3][x3] = 0;
							a[y4][x4] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
							solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
							solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
							solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x1 - 2), 26 + y1 * 50, 74 + 50 * (x1 - 2), 74 + y1 * 50);
							solidrectangle(26 + 50 * x2, 26 + (y2 - 1) * 50, 74 + 50 * x2, 74 + (y2 - 1) * 50);
							solidrectangle(26 + 50 * (x3 - 1), 26 + y3 * 50, 74 + 50 * (x3 - 1), 74 + y3 * 50);
							solidrectangle(26 + 50 * (x4 + 1), 26 + (y4 - 1) * 50, 74 + 50 * (x4 + 1), 74 + (y4 - 1) * 50);
							x1 -= 2;
							y2--;
							x3--;
							y4--;
							x4++;
							a[y1][x1] = 2;
							a[y2][x2] = 2;
							a[y3][x3] = 2;
							a[y4][x4] = 2;
							ci = 0;
						}
					}
					else	if (type == 5)
					{
						if (a[y2 + 1][x2 - 1] != 1 && a[y3][x3 + 2] != 1 && a[y4 + 1][x4 + 1] != 1 && y2 + 2 <= 14 && ci == 0)//消除法
						{
							a[y2][x2] = 0;
							a[y3][x3] = 0;
							a[y4][x4] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
							solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
							solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x2 - 1), 26 + (y2 + 1) * 50, 74 + 50 * (x2 - 1), 74 + (y2 + 1) * 50);
							solidrectangle(26 + 50 * (x3 + 2), 26 + y3 * 50, 74 + 50 * (x3 + 2), 74 + y3 * 50);
							solidrectangle(26 + 50 * (x4 + 1), 26 + (y4 + 1) * 50, 74 + 50 * (x4 + 1), 74 + (y4 + 1) * 50);
							y2++;
							x2--;
							x3 += 2;
							y4++;
							x4++;
							a[y1][x1] = 2;
							a[y2][x2] = 2;
							a[y3][x3] = 2;
							a[y4][x4] = 2;
							ci++;
						}
						else	if (a[y2 - 1][x2 + 1] != 1 && a[y3][x3 - 2] != 1 && a[y4 - 1][x4 - 1] != 1 && y3 + 1 <= 14 && x4 - 2 >= 0 && ci == 1)//消除法
						{
							a[y2][x2] = 0;
							a[y3][x3] = 0;
							a[y4][x4] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
							solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
							solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x2 + 1), 26 + (y2 - 1) * 50, 74 + 50 * (x2 + 1), 74 + (y2 - 1) * 50);
							solidrectangle(26 + 50 * (x3 - 2), 26 + y3 * 50, 74 + 50 * (x3 - 2), 74 + y3 * 50);
							solidrectangle(26 + 50 * (x4 - 1), 26 + (y4 - 1) * 50, 74 + 50 * (x4 - 1), 74 + (y4 - 1) * 50);
							y2--;
							x2++;
							x3 -= 2;
							y4--;
							x4--;
							a[y1][x1] = 2;
							a[y2][x2] = 2;
							a[y3][x3] = 2;
							a[y4][x4] = 2;
							ci = 0;
						}
					}
					else if (type == 6)
					{
						if (a[y1][x1 - 1] != 1 && a[y2][x2 + 1] != 1 && a[y3 + 1][x3] != 1 && a[y4 + 1][x4] != 1 && y4 + 1 <= 14 && ci == 0)//消除法
						{
							a[y1][x1] = 0;
							a[y2][x2] = 0;
							a[y3][x3] = 0;
							a[y4][x4] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
							solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
							solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
							solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x1 - 1), 26 + y1 * 50, 74 + 50 * (x1 - 1), 74 + y1 * 50);
							solidrectangle(26 + 50 * (x2 + 1), 26 + y2 * 50, 74 + 50 * (x2 + 1), 74 + y2 * 50);
							solidrectangle(26 + 50 * x3, 26 + (y3 + 1) * 50, 74 + 50 * x3, 74 + (y3 + 1) * 50);
							solidrectangle(26 + 50 * x4, 26 + (y4 + 1) * 50, 74 + 50 * x4, 74 + (y4 + 1) * 50);
							x1--;
							x2++;
							y3++;
							y4++;
							a[y1][x1] = 2;
							a[y2][x2] = 2;
							a[y3][x3] = 2;
							a[y4][x4] = 2;
							ci++;
						}
						else	if (a[y1 + 1][x1 - 1] != 1 && a[y3 - 1][x3 + 1] != 1 && a[y4][x4 - 2] != 1 && x3 - 1 >= 0 && ci == 1)//消除法
						{
							a[y1][x1] = 0;
							a[y2][x2] = 0;
							a[y3][x3] = 0;
							a[y4][x4] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
							solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
							solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x1 - 1), 26 + (y1 + 1) * 50, 74 + 50 * (x1 - 1), 74 + (y1 + 1) * 50);
							solidrectangle(26 + 50 * (x3 + 1), 26 + (y3 - 1) * 50, 74 + 50 * (x3 + 1), 74 + (y3 - 1) * 50);
							solidrectangle(26 + 50 * (x4 - 2), 26 + y4 * 50, 74 + 50 * (x4 - 2), 74 + y4 * 50);
							y1++;
							x1--;
							y3--;
							x3++;
							x4 -= 2;
							a[y1][x1] = 2;
							a[y2][x2] = 2;
							a[y3][x3] = 2;
							a[y4][x4] = 2;
							ci++;
						}
						else	if (a[y1 - 1][x1] != 1 && a[y2 - 1][x2] != 1 && a[y3][x3 - 1] != 1 && a[y4][x4 + 1] != 1 && y1 - 1 >= 0 && ci == 2)//消除法
						{
							a[y1][x1] = 0;
							a[y2][x2] = 0;
							a[y3][x3] = 0;
							a[y4][x4] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
							solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
							solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
							solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * x1, 26 + (y1 - 1) * 50, 74 + 50 * x1, 74 + (y1 - 1) * 50);
							solidrectangle(26 + 50 * x2, 26 + (y2 - 1) * 50, 74 + 50 * x2, 74 + (y2 - 1) * 50);
							solidrectangle(26 + 50 * (x3 - 1), 26 + y3 * 50, 74 + 50 * (x3 - 1), 74 + y3 * 50);
							solidrectangle(26 + 50 * (x4 + 1), 26 + y4 * 50, 74 + 50 * (x4 + 1), 74 + y4 * 50);
							y1--;
							y2--;
							x3--;
							x4++;
							a[y1][x1] = 2;
							a[y2][x2] = 2;
							a[y3][x3] = 2;
							a[y4][x4] = 2;
							ci++;
						}
						else	if (a[y1][x1 + 2] != 1 && a[y2 + 1][x2 - 1] != 1 && a[y4 - 1][x4 + 1] != 1 && x2 + 1 <= 9 && ci == 3)//消除法
						{
							a[y1][x1] = 0;
							a[y2][x2] = 0;
							a[y3][x3] = 0;
							a[y4][x4] = 0;
							setfillcolor(WHITE);
							solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
							solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
							solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
							setfillcolor(BLUE);
							solidrectangle(26 + 50 * (x1 + 2), 26 + y1 * 50, 74 + 50 * (x1 + 2), 74 + y1 * 50);
							solidrectangle(26 + 50 * (x2 - 1), 26 + (y2 + 1) * 50, 74 + 50 * (x2 - 1), 74 + (y2 + 1) * 50);
							solidrectangle(26 + 50 * (x4 + 1), 26 + (y4 - 1) * 50, 74 + 50 * (x4 + 1), 74 + (y4 - 1) * 50);
							x1 += 2;
							y2++;
							x2--;
							y4--;
							x4++;
							a[y1][x1] = 2;
							a[y2][x2] = 2;
							a[y3][x3] = 2;
							a[y4][x4] = 2;
							ci = 0;
						}

					}

				}
				else	if (c == 224 && d == 80)// 当用户输入键盘下键  （下移）
				{

					if (y4<14 && a[y1 + 1][x1] != 1 && a[y2 + 1][x2] != 1 && a[y3 + 1][x3] != 1 && a[y4 + 1][x4] != 1)
					{
						a[y1][x1] = 0;
						a[y2][x2] = 0;
						a[y3][x3] = 0;
						a[y4][x4] = 0;
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * x4, 26 + (y4 + 1) * 50, 74 + 50 * x4, 74 + (y4 + 1) * 50);
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * x3, 26 + (y3 + 1) * 50, 74 + 50 * x3, 74 + (y3 + 1) * 50);
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * x2, 26 + (y2 + 1) * 50, 74 + 50 * x2, 74 + (y2 + 1) * 50);
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * x1, 26 + (y1 + 1) * 50, 74 + 50 * x1, 74 + (y1 + 1) * 50);
						y1++;
						y2++;
						y3++;
						y4++;
						a[y1][x1] = 2;
						a[y2][x2] = 2;
						a[y3][x3] = 2;
						a[y4][x4] = 2;
						Sleep(20);
					}
					else
					{
						a[y1][x1] = 1;
						a[y2][x2] = 1;
						a[y3][x3] = 1;
						a[y4][x4] = 1;
						setfillcolor(YELLOW);
						solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
						solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
						solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
						solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
						ci = 0;
						xiaochu(a);
						break;
					}
				}
				else	if (c == 224 && d == 75)// 当用户输入键盘左键（左移）
				{
					if (x1>0 && x2>0 && x3>0 && x4>0 && a[y1][x1 - 1] != 1 && a[y2][x2 - 1] != 1 && a[y3][x3 - 1] != 1 && a[y4][x4 - 1] != 1)
					{
						a[y1][x1] = 0;
						a[y2][x2] = 0;
						a[y3][x3] = 0;
						a[y4][x4] = 0;
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * (x1 - 1), 26 + y1 * 50, 74 + 50 * (x1 - 1), 74 + y1 * 50);
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * (x2 - 1), 26 + y2 * 50, 74 + 50 * (x2 - 1), 74 + y2 * 50);
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * (x3 - 1), 26 + y3 * 50, 74 + 50 * (x3 - 1), 74 + y3 * 50);
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * (x4 - 1), 26 + y4 * 50, 74 + 50 * (x4 - 1), 74 + y4 * 50);
						x1--;
						x2--;
						x3--;
						x4--;
						a[y1][x1] = 2;
						a[y2][x2] = 2;
						a[y3][x3] = 2;
						a[y4][x4] = 2;
						Sleep(20);
					}
				}
				else	if (c == 224 && d == 77)// 当用户输入键盘右键（右移）
				{
					if (x1<9 && x2<9 && x3<9 && x4<9 && a[y1][x1 + 1] != 1 && a[y2][x2 + 1] != 1 && a[y3][x3 + 1] != 1 && a[y4][x4 + 1] != 1)
					{
						a[y1][x1] = 0;
						a[y2][x2] = 0;
						a[y3][x3] = 0;
						a[y4][x4] = 0;
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * (x4 + 1), 26 + y4 * 50, 74 + 50 * (x4 + 1), 74 + y4 * 50);
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * (x3 + 1), 26 + y3 * 50, 74 + 50 * (x3 + 1), 74 + y3 * 50);
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * (x2 + 1), 26 + y2 * 50, 74 + 50 * (x2 + 1), 74 + y2 * 50);
						setfillcolor(WHITE);
						solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
						setfillcolor(BLUE);
						solidrectangle(26 + 50 * (x1 + 1), 26 + y1 * 50, 74 + 50 * (x1 + 1), 74 + y1 * 50);
						x1++;
						x2++;
						x3++;
						x4++;
						a[y1][x1] = 2;
						a[y2][x2] = 2;
						a[y3][x3] = 2;
						a[y4][x4] = 2;
						Sleep(20);
					}
				}
			}
		}
		stop = GetTickCount();
		jiange = stop - start;
		Sleep(2);
		//上次方块下落间隔大于620毫秒  就把在运行的方块自动下降一格
		if (jiange>620 )
		{
			start = stop;
			if (y4<14 && a[y1 + 1][x1] != 1 && a[y2 + 1][x2] != 1 && a[y3 + 1][x3] != 1 && a[y4 + 1][x4] != 1)
			{
				a[y1][x1] = 0;
				a[y2][x2] = 0;
				a[y3][x3] = 0;
				a[y4][x4] = 0;
				setfillcolor(WHITE);
				solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
				setfillcolor(BLUE);
				solidrectangle(26 + 50 * x4, 26 + (y4 + 1) * 50, 74 + 50 * x4, 74 + (y4 + 1) * 50);
				setfillcolor(WHITE);
				solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
				setfillcolor(BLUE);
				solidrectangle(26 + 50 * x3, 26 + (y3 + 1) * 50, 74 + 50 * x3, 74 + (y3 + 1) * 50);
				setfillcolor(WHITE);
				solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
				setfillcolor(BLUE);
				solidrectangle(26 + 50 * x2, 26 + (y2 + 1) * 50, 74 + 50 * x2, 74 + (y2 + 1) * 50);
				setfillcolor(WHITE);
				solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
				setfillcolor(BLUE);
				solidrectangle(26 + 50 * x1, 26 + (y1 + 1) * 50, 74 + 50 * x1, 74 + (y1 + 1) * 50);
				y1++;
				y2++;
				y3++;
				y4++;
				a[y1][x1] = 2;
				a[y2][x2] = 2;
				a[y3][x3] = 2;
				a[y4][x4] = 2;
			}
			else
			{
				a[y1][x1] = 1;
				a[y2][x2] = 1;
				a[y3][x3] = 1;
				a[y4][x4] = 1;
				setfillcolor(YELLOW);
				solidrectangle(26 + 50 * x1, 26 + y1 * 50, 74 + 50 * x1, 74 + y1 * 50);
				solidrectangle(26 + 50 * x2, 26 + y2 * 50, 74 + 50 * x2, 74 + y2 * 50);
				solidrectangle(26 + 50 * x3, 26 + y3 * 50, 74 + 50 * x3, 74 + y3 * 50);
				solidrectangle(26 + 50 * x4, 26 + y4 * 50, 74 + 50 * x4, 74 + y4 * 50);
				xiaochu(a);
				break;
			}
		}

	}
}

//当前方块缩略图
void suoluetu(int k)
{
	setfillcolor(WHITE);
	solidrectangle(535, 150, 640, 250);
	Sleep(30);
	if (k == 0)
	{

		setfillcolor(BLACK);
		solidrectangle(545, 190, 625, 210);
	}
	else if (k == 1)
	{
		setfillcolor(BLACK);
		solidrectangle(565, 175, 605, 215);
	}
	else if (k == 2)
	{
		setfillcolor(BLACK);
		solidrectangle(575, 180, 595, 200);
		solidrectangle(555, 200, 615, 220);
	}
	else if (k == 3)
	{
		setfillcolor(BLACK);
		solidrectangle(555, 190, 615, 210);
		solidrectangle(555, 170, 575, 190);
	}
	else if (k == 4)
	{
		setfillcolor(BLACK);
		solidrectangle(555, 180, 595, 200);
		solidrectangle(575, 200, 615, 220);
	}
	else if (k == 5)
	{
		setfillcolor(BLACK);
		solidrectangle(575, 180, 615, 200);
		solidrectangle(555, 200, 595, 220);
	}
	else if (k == 6)
	{
		setfillcolor(BLACK);
		solidrectangle(555, 190, 615, 210);
		solidrectangle(595, 170, 615, 190);
	}
}

//下个方块缩略图
void suoluetu1(int k)
{
	setfillcolor(WHITE);
	solidrectangle(535, 280, 640, 380);
	Sleep(30);
	if (k == 0)
	{

		setfillcolor(BLACK);
		solidrectangle(545, 320, 625, 340);
	}
	else if (k == 1)
	{
		setfillcolor(BLACK);
		solidrectangle(565, 305, 605, 345);
	}
	else if (k == 2)
	{
		setfillcolor(BLACK);
		solidrectangle(575, 310, 595, 330);
		solidrectangle(555, 330, 615, 350);
	}
	else if (k == 3)
	{
		setfillcolor(BLACK);
		solidrectangle(555, 320, 615, 340);
		solidrectangle(555, 300, 575, 320);
	}
	else if (k == 4)
	{
		setfillcolor(BLACK);
		solidrectangle(555, 310, 595, 330);
		solidrectangle(575, 330, 615, 350);
	}
	else if (k == 5)
	{
		setfillcolor(BLACK);
		solidrectangle(575, 310, 615, 330);
		solidrectangle(555, 330, 595, 350);
	}
	else if (k == 6)
	{
		setfillcolor(BLACK);
		solidrectangle(555, 320, 615, 340);
		solidrectangle(595, 300, 615, 320);
	}
}