#include <iostream>
#include <Windows.h>

#define NEW_STRING cout << endl

using std::cout;
using std::endl;
using std::cin;

double cnk(int N, int K)
{
	return ((N < K) ? 0 : ((K == 0) ? 1 : ((N - K + 1) / double(K) * cnk(N, K - 1))));
}

void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

int main() {

	const int width = 200, height = 50;
	SetWindow(width, height);
	
	int N;
	for (N = 1; N < 10; N++) {
		cout << "Input size:" << N << endl;
		//cin >> N;
		if ((N < 1) || (N > 30)) {
			std::cerr << "Sorry, but very large number" << endl;
			return 0;
		}
		cout << endl;
		int n = 0, k = 0;
		for (int i = 0; i < N; i++) {
			k = 0;
			for (int j = 0; j < width; j++) {
				char symbol = ' ';
				if (((j <= width / 2 + i) && (j >= width / 2 - i))) {
					if (k <= i)  cout << ((int)cnk(i, k) % 2 == 0 ? '@' : 'O');
					k++;
				}
				else {
					cout << symbol;
				}
			}
		}
		for (int i = N - 1; i >= 0; i--) {
			k = 0;
			for (int j = 0; j < width; j++) {
				char symbol = ' ';
				if (((j <= width / 2 + i) && (j >= width / 2 - i))) {
					if (k <= i)  cout << ((int)cnk(i, k) % 2 == 0 ? '@' : 'O');
					k++;
				}
				else {
					cout << symbol;
				}
			}
		}
		NEW_STRING;
	}
	getchar();
	return 1;
}