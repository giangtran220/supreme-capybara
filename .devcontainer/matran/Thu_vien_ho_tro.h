#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;

void gotoxy(int x, int y);
void textcolor (unsigned short color);
void resizeConsole(int width, int height);
void DisableCtrButton(bool Close, bool Min, bool Max);
void DisableResizeWindow();
void ShowScrollbar(BOOL Show);
void clrscr(void);
void SetColorAndBackground(int ForgC, int BackC);
void set_color(int X);

enum colors {BLACK = 0, BLUE, GREEN,CYAN,RED, MAGENTA, BROWN, LIGHTGRAY,
             DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN,
             LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE};


void gotoxy(int x, int y)
{
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD a={x,y};
	SetConsoleCursorPosition(h,a);
}

void textcolor(int x)
{
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,x);
}

// Hàm  doc ma tran tu file
bool ma_tran_A(ifstream &matranA, int **&a, int &m, int &n)
{
    if (matranA.fail())
	{
        cerr << "Failed to open file !" << endl;
        return false;
    }
    string line;


    // Đọc số hàng và số cột của ma trận
    getline(matranA, line);
    size_t pos = line.find(":");
    if (pos != string::npos)
    {
        string sohang = line.substr(pos+1);
            m = stoi(sohang);
    }
    getline(matranA, line);
    pos = line.find(":");
    string socot = line.substr(pos+1);
            n = stoi(socot);


// Cap phát bo nho dong cho ma tran
    a = new int*[m];
    for (int i = 0; i < m; i++)
	{
        a[i] = new int[n];
    }

    getline(matranA, line);
    for (int i = 0; i < m; i++)
    {
        getline(matranA, line);
        size_t pos = 0;
        for (int j = 0; j < n; j++)
        {
            size_t newpos = line.find(" ", pos+1);
            a[i][j] = stoi(line.substr(pos, newpos - pos));
            pos = newpos;
        }
    }
    return true;
}

// Hàm  ghi ma tran vào file
bool ghi_ma_tran(ofstream &outfile, int **a, int m, int n)
{
     string str = "Ma tran co: ";
     string str0 = "x";
    if (outfile.fail())
	{
        cerr << "Failed to open file." << endl;
        return false;
    }
    outfile << str << m << str0 << n << endl;

    for (int i = 0; i < m; i++)
	{
        for (int j = 0; j < n; j++)
		{
            outfile << a[i][j] << " ";
        }
        outfile << endl;
    }
    return true;
}


// Hàm  doc ma tran tu file
bool ma_tran_B(ifstream &matranB, int **&b, int &p, int &q)
{
    if (matranB.fail())
	{
        cerr << "Failed to open file !" << endl;
        return false;
    }
    string line;


    // Đọc số hàng và số cột của ma trận
    getline(matranB, line);
    size_t pos = line.find(":");
    string sohang = line.substr(pos+1);
            p = stoi(sohang);

    getline(matranB, line);
    pos = line.find(":");
    string socot = line.substr(pos+1);
            q = stoi(socot);


    // Cap phát bo nho dong cho ma tran
    b = new int*[q];
    for (int i = 0; i < q; i++)
	{
        b[i] = new int[p];
    }

    getline(matranB, line);
    for (int i = 0; i < p; i++)
    {
        getline(matranB, line);
        size_t pos = 0;
        for (int j = 0; j < q; j++)
        {
            size_t newpos = line.find(" ", pos+1);
            b[i][j] = stoi(line.substr(pos, newpos - pos));
            pos = newpos;
        }
    }
    return true;
}

void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}

void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void clrscr(void)
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hConsoleOut;
    COORD Home = {0,0};
    DWORD dummy;

    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

    FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
    csbiInfo.dwCursorPosition.X = 0;
    csbiInfo.dwCursorPosition.Y = 0;
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}


