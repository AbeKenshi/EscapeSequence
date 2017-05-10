#include <windows.h>
#include <cstdio>
using namespace std;

int Locate(HANDLE, int, int);

int main()
{
	HANDLE hStdout;
	char str[32];

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int x = 0;
	int y = 0;
	bool flag = true;
	while (true)
	{
		if (flag) {
			if (GetAsyncKeyState(VK_DOWN) && y < 10) {
				y += 1;
				Locate(hStdout, x, y);
				flag = false;
			}
			else if (GetAsyncKeyState(VK_RIGHT) && x < 10) {
				x += 1;
				Locate(hStdout, x, y);
				flag = false;
			}
			else if (GetAsyncKeyState(VK_UP) && y > 0) {
				y -= 1;
				Locate(hStdout, x, y);
				flag = false;
			}
			else if (GetAsyncKeyState(VK_LEFT) && x > 0) {
				x -= 1;
				Locate(hStdout, x, y);
				flag = false;
			}
		}
		else {
			if (GetAsyncKeyState(VK_DOWN) && y < 10) {
			}
			else if (GetAsyncKeyState(VK_RIGHT) && x < 10) {
			}
			else if (GetAsyncKeyState(VK_UP) && y > 0) {
			}
			else if (GetAsyncKeyState(VK_LEFT) && x > 0) {
			}
			else {
				flag = true;
			}
		}
		Sleep(50);
	}
	return 0;
}

int Locate(HANDLE hOut, int x, int y)
{
	// カーソル位置を指定
	COORD dwPos;
	dwPos.X = (SHORT)x;
	dwPos.Y = (SHORT)y;
	system("cls");
	if (SetConsoleCursorPosition(hOut, dwPos) == 0) {
		return -1;
	}
	else {
		printf("*");
		return 0;
	}
}
