#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<windows.h>
#include<ctime>
#include"Thu_vien_ho_tro.h"
#include<fstream>

// Dinh nghia ten lua chon
const string luachon1 = "Nhập từ file";
const string luachon2 = "Nhập từ màn hình console";
const string luachon3 = "Tổng A+B";
const string luachon4 = "Hiệu A-B";
const string luachon5 = "Tích AxB";
const string luachon6 = "Tích BxA";
const string luachon7 = "Định thức ma trận A";
const string luachon8 = "Định thức ma trận B";
const string thoat = "Thoát";

using namespace std;
void menu(int x);
void luachon(int x);
void selectmuitenlen(char r, int x, int y, int y0);
void selectmuitenxuong(char r, int x, int y, int y0);
void input2d(int **arr, int nrow,int ncol);
void display(int **arr,int row,int col);
void tinhTong(int **a, int **b, int **c, int m, int n);
void tinhHieu(int **a, int **b, int **c, int m, int n);
void tinhTichAxB(int **a, int **b, int **c, int m, int n, int p , int q);
void tinhTichBxA(int **a, int **b, int **c, int p, int q, int m, int n);
int tinhDinhThuc(int **a, int n);
void nhapMaTranA(int **a, int m, int n);
void nhapMaTranB(int **b, int p, int q);
void hienthiMaTran(int **a, int m, int n);

void nhapMaTranA(int **a, int m, int n)
{

    for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
        for (int j = 0; j < n; j++)
		{
            cout << " A[" << i+1 << "][" << j+1 << "]: ";
            cin >> a[i][j];
		}
    }
}
void nhapMaTranB(int **b, int p, int q)
{
    for (int i = 0; i < p; i++)
	{
		b[i] = new int[q];
        for (int j = 0; j < q; j++)
		{
            cout << " B[" << i+1 << "][" << j+1 << "]: ";
            cin >> b[i][j];
        }
    }
}

// Hàm hien thi ma tran
void hienthiMaTran(int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
	{
        for (int j = 0; j < n; j++)
		{
            cout <<setw(5) << a[i][j] << "  ";
        }
        cout << endl <<endl;
    }
}

// Hàm tính tong hai ma tran
void tinhTong(int **a, int **b, int **c, int m, int n)
{
    for (int i = 0; i < m; i++)
	{
        for (int j = 0; j < n; j++)
		{
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Hàm tính hieu hai ma tran
void tinhHieu(int **a, int **b, int **c, int m, int n)
{
    for (int i = 0; i < m; i++)
	{
        for (int j = 0; j < n; j++)
		{
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Hàm tính tích hai ma tran
void tinhTichAxB(int **a, int **b, int **c, int m, int n, int p , int q)
{
    for (int i = 0; i < m; i++)
	{
        for (int j = 0; j < p; j++)
		{
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
			{
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void tinhTichBxA(int **a, int **b, int **c, int p, int q, int m, int n)
{
    for (int i = 0; i < p; i++)
	{
        for (int j = 0; j < n; j++)
		{
            c[i][j] = 0;
            for (int k = 0; k < q; k++)
			{
                c[i][j] += b[i][k] * a[k][j];
            }
        }
    }
}

// Ham tinh dinh thuc cua ma tran
int tinhDinhThuc(int **a, int n)
    {
       int det = 0;
       if (n == 1)
	{
       return a[0][0];
    }
    else if (n == 2)
    {
        return (a[0][0] * a[1][1] - a[1][0] * a[0][1]);
	}
	   else
	{
       for (int k = 0; k < n; k++) {
            int **c = new int*[n-1];
            for (int i = 0; i < n-1; i++)
                c[i] = new int[n-1];
            for (int i = 1; i < n; i++) {
                int p = 0;
                for (int j = 0; j < n; j++) {
                    if (j == k)
                        continue;
                    c[i-1][p++] = a[i][j];
                }
            }
            det += a[0][k] * pow(-1, k) * tinhDinhThuc(c, n-1);
            for (int i = 0; i < n-1; i++)
                delete[] c[i];
            delete[] c;
        }
    }
    return det;
}

//Tạo menu
void menu(int x)
{
	gotoxy(x,6);
	textcolor(YELLOW);
		cout<<luachon1<<endl;
	gotoxy(x,8);
	textcolor(WHITE);
		cout<<luachon2<<endl;
	gotoxy(x,10);
	textcolor(WHITE);
		cout<<luachon3<<endl;
	gotoxy(x,12);
	textcolor(WHITE);
		cout<<luachon4<<endl;
	gotoxy(x,14);
	textcolor(WHITE);
		cout<<luachon5<<endl;
    gotoxy(x,16);
	textcolor(WHITE);
		cout<<luachon6<<endl;
	gotoxy(x,18);
	textcolor(WHITE);
		cout<<luachon7<<endl;
	gotoxy(x,20);
	textcolor(WHITE);
		cout<<luachon8<<endl;
	gotoxy(x,22);
	textcolor(WHITE);
		cout<<thoat<<endl;
	gotoxy(0,0);
}
// Tạo lựa chọn
void luachon(int x)
{
    int **a,**b,**c,m,n,p,q;
	int y0 = 2;
	char r;
    int y = 6;
    gotoxy(x,y); // ve lua chon dau tien 1

    while(1)
    {
        r = getch(); // lay gia tri cua mot phim bat ky

        if(r==72) // mui ten len
        {
        	if(y>6) // chan tren
    	  	{
    			y = y - y0;
			}
		    selectmuitenlen(r,x,y,y0);
        }// end 72

        // MUI TEN XUONG
        if(r==80)// mui ten xuong
        {
            if(y<23)
            {
            	y = y + y0;
			}
			selectmuitenxuong(r,x,y,y0);

        }// end 80

        if(r==27) // ESC để thoát
        {
			break;
		}

        if(r==13)// Enter // lựa chọn tính toán
		{
			gotoxy(0,0);


			if(y==6)// Nhập ma trận từ file
			{
				clrscr();
				selectmuitenlen(r,x,y,y0);
				gotoxy(0,0);
				// Bắt đầu nhập ma trận từ file
                cout << "Vui long nhap cac thong tin cua hai ma tran !\n";
                cout << "Nhan phim bat ki de bat dau nhap du lieu\n";
                system("pause");

                char mtB[] = "Notepad.exe matranB.txt";
		        WinExec(mtB, SW_SHOWNORMAL);
                ifstream matranB("matranB.txt");
                if (matranB.fail())
	             {
                  cerr << "Failed to open file !" << endl;
	             }
     	        matranB.close();

                char mtA[] = "Notepad.exe matranA.txt";
	            WinExec(mtA, SW_SHOWNORMAL);
    	        ifstream matranA("matranA.txt");
                if (matranA.fail())
	             {
                  cerr << "Failed to open file !" << endl;
	             }
                matranA.close();
			} // Kết thúc lựa chọn 1

            if(y==8) // Lựa chọn 2 - Tính toán lựa chọn 2
            {

            	clrscr();
				selectmuitenlen(r,x,y,y0);
				gotoxy(0,0);

                cout << "Nhập vào số hàng của ma trận A: ";
                cin >> m;
                cout << "Nhập vào số cột của ma trận A: ";
                cin >> n;
                int **a=new int*[n];
            	nhapMaTranA(a, m, n);
            	cout << "Ma tran A :\n";
            	hienthiMaTran(a, m, n);


                cout << "Nhập vào số hàng của ma trận B: ";
                cin >> p;
                cout << "Nhập vào số cột của ma trận B: ";
                cin >> q;
                int **b = new int*[p];
            	nhapMaTranB(b, p, q);
            	cout << "Ma tran B :\n";
            	hienthiMaTran(b, p, q);

			}// Kết thúc lựa chọn 2

            if(y==10) // Lựa chọn 3
            {
            	clrscr();
				selectmuitenlen(r,x,y,y0);
				gotoxy(0,0);

	   	     		if(m==p&&n==q)
               		{
               			int **c = new int*[m];
    					for (int i = 0; i < m; i++)
    					{
        					c[i] = new int[p];
    					}
	             		//Tính và hien thi tong cua hai ma tran

                 		   tinhTong(a, b, c, m, n);
                 		   ofstream outfile("tong.txt");
                 		   cout << "\n+ Bạn đã ghi số liệu thành công!\n";
                 		   cout << "\n+ Kết quả đã được ghi trong file tong.txt\n";
	                       cout << "\n+ Nhấn phím bất kỳ để xem nội dung file\n\n";

	                       system("PAUSE");
                           ghi_ma_tran(outfile,c,m,n);
	                       char program[] = "Notepad.exe tong.txt";
	                       WinExec(program, SW_SHOWNORMAL);
                            outfile.close();

                 		for (int i = 0; i < m; i++)
							{
        						delete []a[i];
    						}
    						delete []a;
                		for (int i = 0; i < m; i++)
							{
								delete []b[i];
    						}
    						delete []b;
                 		for (int i = 0; i < m; i++)
    						{
        						delete []c[i];
    						}
    						delete []c;
               		}
    				else
               		{
                 		textcolor(12);  cout << "Không thể cộng hai ma trận !"<<endl;
                 		cout<<a[0][0]<<endl;
                 		cout<<b[0][0]<<endl;
                 		textcolor(11);

	           		}

			} // Kết thúc lựa chọn 3
            if(y==12) // Lựa chọn 4 // Tinh hieu A-B
            {
                clrscr();
				selectmuitenlen(r,x,y,y0);
				gotoxy(0,0);

                if(m==p&&n==q)
               		{
               			int **c = new int*[m];
    					for (int i = 0; i < m; i++)
    						{
        						c[i] = new int[p];
    						}
	             		// Tính và hien thi hieu cua hai ma tran

                 		tinhHieu(a, b, c, m, n);
                 		ofstream outfile("hieu.txt");
                 		 cout << "\n+ Ban da ghi so lieu thanh cong!\n";
                 		 cout << "\n+ Ket qua da in trong file hieu.txt\n" ;
	                     cout << "\n+ Nhan phim bat ky de xem noi dung file\n\n";
	                     system("PAUSE");

                         ghi_ma_tran(outfile,c,m,n);
	                     char program[] = "Notepad.exe hieu.txt";
	                     WinExec(program, SW_SHOWNORMAL);
                            outfile.close();
                 		for (int i = 0; i < m; i++)
							{
        						delete []a[i];
    						}
    						delete []a;
                 		for (int i = 0; i < m; i++)
							{
								delete []b[i];
    						}
    						delete []b;
                 		for (int i = 0; i < m; i++)
    						{
        						delete []c[i];
    						}
    						delete []c;
              		 }
    				else
               		{
                 		textcolor(12);  cout << "Không thể trừ hai ma trận !"<<endl;
                 		textcolor(11);
	           		}

			}// Ket thuc lua chon 4

            if(y==14) //Lua chon 5 // Tinh tich AxB
            {
                clrscr();
				selectmuitenlen(r,x,y,y0);
				gotoxy(0,0);

                            int **c = new int *[m];
            				for (int i = 0; i < m; i++)
            				{
               					c[i] = new int[q];
            				}
                        if (n!=p)
                             {
	             		       textcolor(12); cout << "Không thể nhân hai ma trận !"<<endl;
	             		       textcolor(11);
                             }
                        else
                             {
                               tinhTichAxB(a, b, c, m, n, p, q);
                               ofstream outfile("tich.txt");
            			       cout << "\n+ Ban da ghi so lieu thanh cong!\n";
            			       cout << "\n+ Ket qua da in trong file tich.txt\n " << endl;
	                           cout << "\n+ Nhan phim bat ky de xem noi dung file\n\n";
	                           system("PAUSE");
                               ghi_ma_tran(outfile,c,m,n);
	                           char program[] = "Notepad.exe tich.txt";
	                           WinExec(program, SW_SHOWNORMAL);

                               outfile.close();
                               // Xoa cac mang con va giai phong bo nho
            				for (int i = 0; i < m; i++)
            				{
            				    delete[] a[i];
            				}
            				delete[] a;

            				for (int i = 0; i < p; i++)
            				{
            				    delete[] b[i];
            				}
            				delete[] b;

            				for (int i = 0; i < m; i++)
            				{
            				    delete[] c[i];
            				}
            				delete[] c;
                             }
            }//Ket thuc lua chon 5

            if(y==16) //Lua chon 6 // Tinh tich BxA
            {
                clrscr();
				selectmuitenlen(r,x,y,y0);
				gotoxy(0,0);

              int **c = new int *[m];
            				for (int i = 0; i < m; i++)
            				{
               					c[i] = new int[q];
            				}
                        if (q!=m)
                             {
	             		       textcolor(12); cout << "Không thể nhân hai ma trận !"<<endl;
	             		       textcolor(11);
                             }
                        else
                             {
                               tinhTichBxA(a, b, c, m, n, p, q);
                               ofstream outfile("tich.txt");
            			       cout << "\n+ Ban da ghi so lieu thanh cong!\n";
            			       cout << "\n+ Ket qua da in trong file tich.txt\n " << endl;
	                           cout << "\n+ Nhan phim bat ky de xem noi dung file\n\n";
	                           system("PAUSE");
                               ghi_ma_tran(outfile,c,m,n);
	                           char program[] = "Notepad.exe tich.txt";
	                           WinExec(program, SW_SHOWNORMAL);

                               outfile.close();
                               // Xoa cac mang con va giai phong bo nho
            				for (int i = 0; i < m; i++)
            				{
            				    delete[] a[i];
            				}
            				delete[] a;

            				for (int i = 0; i < p; i++)
            				{
            				    delete[] b[i];
            				}
            				delete[] b;

            				for (int i = 0; i < m; i++)
            				{
            				    delete[] c[i];
            				}
            				delete[] c;
                             }
            }//Ket thuc lua chon 6

            if(y==18) // Lua chon 7 //Tinh dinh thuc ma tran A
            {
                clrscr();
				selectmuitenlen(r,x,y,y0);
				gotoxy(0,0);

                if(m==n)
                        { int det=tinhDinhThuc(a,n);
                             ofstream outfile("det.txt");
                             if (outfile.is_open())
                          {
                            cout << "\n+ Ban da ghi so lieu thanh cong!\n";
                 		    cout << "\n+ Ket qua da in trong file det.txt\n" ;
	                        cout << "\n+ Nhan phim bat ky de xem noi dung file\n\n";
	                        system("PAUSE");
	                        outfile << "Dinh thuc cua ma tran la: " << det << endl;
	                        char program[] = "Notepad.exe det.txt";
                            WinExec(program, SW_SHOWNORMAL);
                            outfile.close();
                          } else{cerr << "Khong the mo file det.txt de ghi ket qua" << endl;}
                        }	else {textcolor(4); cout<<"Ma tran A khong phai ma tran vuong nen khong tinh duoc dinh thuc !"<<endl;}
            }
            if(y==20) //Lua chon 8 // Tinh dinh thuc ma tran B
            {
                clrscr();
				selectmuitenlen(r,x,y,y0);
				gotoxy(0,0);

                if(p==q)
                      {
                         int det=tinhDinhThuc(b,n);
                           ofstream outfile("det.txt");
                           if (outfile.is_open())
                        {
                          cout << "\n+ Ban da ghi so lieu thanh cong!\n";
                 		  cout << "\n+ Ket qua da in trong file det.txt\n" ;
	                      cout << "\n+ Nhan phim bat ky de xem noi dung file\n\n";
	                      system("PAUSE");
	                      outfile << "Dinh thuc cua ma tran la: " << det << endl;
	                      char program[] = "Notepad.exe det.txt";
                          WinExec(program, SW_SHOWNORMAL);
                          outfile.close();
                        }else{cerr << "Khong the mo file det.txt de ghi ket qua" << endl;}
                      }
						 else {textcolor(4);  cout<<"Ma tran B khong phai ma tran vuong nen khong tinh duoc dinh thuc !"<<endl;}
            }

            if(y==22) // Thoat
            {
                clrscr();
				gotoxy(0,0);
            	break;
            }

        }// end 13
        gotoxy(x,y);

	} // end while
}

void selectmuitenxuong(char a, int x, int y, int y0)
{
	if(y==6) // Lua chon 1 (xuong)
	{
		gotoxy(x,y+y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y+2*y0);
		textcolor(15);
		cout<<luachon3<<endl;

		gotoxy(x,y+3*y0);
		textcolor(15);
		cout<<luachon4<<endl;

		gotoxy(x,y+4*y0);
		textcolor(15);
		cout<<luachon5<<endl;

		gotoxy(x,y+5*y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y+6*y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y+7*y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y+8*y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon1<<endl;

		textcolor(15);
	}
	if(y==8) // lua chon 2 (xuong)
	{

		gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y+y0);
		textcolor(15);
		cout<<luachon3<<endl;

        gotoxy(x,y+2*y0);
		textcolor(15);
		cout<<luachon4<<endl;

		gotoxy(x,y+3*y0);
		textcolor(15);
		cout<<luachon5<<endl;

		gotoxy(x,y+4*y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y+5*y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y+6*y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y+7*y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon2<<endl;

		textcolor(15);
	}
	if(y==10) // Lua chon 3  (xuong)
	{

		gotoxy(x,y-2*y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y+y0);
		textcolor(15);
		cout<<luachon4<<endl;

        gotoxy(x,y+2*y0);
		textcolor(15);
		cout<<luachon5<<endl;

        gotoxy(x,y+3*y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y+4*y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y+5*y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y+6*y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon3<<endl;

		textcolor(15);
	}
	if(y==12) // Lua chon 4  (xuong)
	{
		gotoxy(x,y-3*y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y-2*y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon3<<endl;

        gotoxy(x,y+y0);
		textcolor(15);
		cout<<luachon5<<endl;

		gotoxy(x,y+2*y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y+3*y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y+4*y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y+5*y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon4<<endl;

		textcolor(15);
	}
	if(y==14) // Lua chon 5  (xuong)
	{
		gotoxy(x,y-4*y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y-3*y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y-2*y0);
		textcolor(15);
		cout<<luachon3<<endl;

        gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon4<<endl;

		gotoxy(x,y+y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y+2*y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y+3*y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y+4*y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon5<<endl;

		textcolor(15);
	}
	if(y==16) // Lua chon 6  (xuong)
	{
		gotoxy(x,y-5*y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y-4*y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y-3*y0);
		textcolor(15);
		cout<<luachon3<<endl;

        gotoxy(x,y-2*y0);
		textcolor(15);
		cout<<luachon4<<endl;

		gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon5<<endl;

		gotoxy(x,y+y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y+2*y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y+3*y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon6<<endl;

		textcolor(15);
	}
	if(y==18) // Lua chon 7  (xuong)
	{
		gotoxy(x,y-6*y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y-5*y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y-4*y0);
		textcolor(15);
		cout<<luachon3<<endl;

        gotoxy(x,y-3*y0);
		textcolor(15);
		cout<<luachon4<<endl;

		gotoxy(x,y-2*y0);
		textcolor(15);
		cout<<luachon5<<endl;

		gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y+y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y+2*y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon7<<endl;

		textcolor(15);
	}
	if(y==20) // Lua chon 8  (xuong)
	{
		gotoxy(x,y-7*y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y-6*y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y-5*y0);
		textcolor(15);
		cout<<luachon3<<endl;

        gotoxy(x,y-4*y0);
		textcolor(15);
		cout<<luachon4<<endl;

		gotoxy(x,y-3*y0);
		textcolor(15);
		cout<<luachon5<<endl;

		gotoxy(x,y-2*y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y+y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon8<<endl;

		textcolor(15);
	}
	if(y==22) // Thoat  (xuong)
	{
		gotoxy(x,y-8*y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y-7*y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y-6*y0);
		textcolor(15);
		cout<<luachon3<<endl;

        gotoxy(x,y-5*y0);
		textcolor(15);
		cout<<luachon4<<endl;

		gotoxy(x,y-4*y0);
		textcolor(15);
		cout<<luachon5<<endl;

		gotoxy(x,y-3*y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y-2*y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<thoat<<endl;

		textcolor(15);
	}
}
void selectmuitenlen(char r, int x, int y, int y0)
{
	gotoxy(60,0);
	cout << "BẢNG ĐIỀU KHIỂN \n";
	if(y==6) // Lua chon 1 (len)
	{
		gotoxy(x,y+y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y+2*y0);
		textcolor(15);
		cout<<luachon3<<endl;

		gotoxy(x,y+3*y0);
		textcolor(15);
		cout<<luachon4<<endl;

		gotoxy(x,y+4*y0);
		textcolor(15);
		cout<<luachon5<<endl;

		gotoxy(x,y+5*y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y+6*y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y+7*y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y+8*y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon1<<endl;

		textcolor(15);
	}
	if(y==8) // lua chon 2 (len)
	{

		gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y+y0);
		textcolor(15);
		cout<<luachon3<<endl;

        gotoxy(x,y+2*y0);
		textcolor(15);
		cout<<luachon4<<endl;

		gotoxy(x,y+3*y0);
		textcolor(15);
		cout<<luachon5<<endl;

		gotoxy(x,y+4*y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y+5*y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y+6*y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y+7*y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon2<<endl;

		textcolor(15);
	}
	if(y==10) // Lua chon 3  (len)
	{

		gotoxy(x,y-2*y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y+y0);
		textcolor(15);
		cout<<luachon4<<endl;

        gotoxy(x,y+2*y0);
		textcolor(15);
		cout<<luachon5<<endl;

        gotoxy(x,y+3*y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y+4*y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y+5*y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y+6*y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon3<<endl;

		textcolor(15);
	}
	if(y==12) // Lua chon 4  (len)
	{
		gotoxy(x,y-3*y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y-2*y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon3<<endl;

        gotoxy(x,y+y0);
		textcolor(15);
		cout<<luachon5<<endl;

		gotoxy(x,y+2*y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y+3*y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y+4*y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y+5*y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon4<<endl;

		textcolor(15);
	}
	if(y==14) // Lua chon 5  (len)
	{
		gotoxy(x,y-4*y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y-3*y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y-2*y0);
		textcolor(15);
		cout<<luachon3<<endl;

        gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon4<<endl;

		gotoxy(x,y+y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y+2*y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y+3*y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y+4*y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon5<<endl;

		textcolor(15);
	}
	if(y==16) // Lua chon 6  (len)
	{
		gotoxy(x,y-5*y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y-4*y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y-3*y0);
		textcolor(15);
		cout<<luachon3<<endl;

        gotoxy(x,y-2*y0);
		textcolor(15);
		cout<<luachon4<<endl;

		gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon5<<endl;

		gotoxy(x,y+y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y+2*y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y+3*y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon6<<endl;

		textcolor(15);
	}
	if(y==18) // Lua chon 7  (len)
	{
		gotoxy(x,y-6*y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y-5*y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y-4*y0);
		textcolor(15);
		cout<<luachon3<<endl;

        gotoxy(x,y-3*y0);
		textcolor(15);
		cout<<luachon4<<endl;

		gotoxy(x,y-2*y0);
		textcolor(15);
		cout<<luachon5<<endl;

		gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y+y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y+2*y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon7<<endl;

		textcolor(15);
	}
	if(y==20) // Lua chon 8  (len)
	{
		gotoxy(x,y-7*y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y-6*y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y-5*y0);
		textcolor(15);
		cout<<luachon3<<endl;

        gotoxy(x,y-4*y0);
		textcolor(15);
		cout<<luachon4<<endl;

		gotoxy(x,y-3*y0);
		textcolor(15);
		cout<<luachon5<<endl;

		gotoxy(x,y-2*y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y+y0);
		textcolor(15);
		cout<<thoat<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<luachon8<<endl;

		textcolor(15);
	}
	if(y==22) // Thoat  (len)
	{
		gotoxy(x,y-8*y0);
		textcolor(15);
		cout<<luachon1<<endl;

		gotoxy(x,y-7*y0);
		textcolor(15);
		cout<<luachon2<<endl;

		gotoxy(x,y-6*y0);
		textcolor(15);
		cout<<luachon3<<endl;

        gotoxy(x,y-5*y0);
		textcolor(15);
		cout<<luachon4<<endl;

		gotoxy(x,y-4*y0);
		textcolor(15);
		cout<<luachon5<<endl;

		gotoxy(x,y-3*y0);
		textcolor(15);
		cout<<luachon6<<endl;

		gotoxy(x,y-2*y0);
		textcolor(15);
		cout<<luachon7<<endl;

		gotoxy(x,y-y0);
		textcolor(15);
		cout<<luachon8<<endl;

		gotoxy(x,y);
		textcolor(14);
		cout<<thoat<<endl;

		textcolor(15);
	}
}

int main()
{
  char ch;
  do
   {
     SetConsoleTitle("Ma Tran");
     resizeConsole(1000, 700);
	 DisableCtrButton(1,1,1);
	 DisableResizeWindow();
	 ShowScrollbar(0);
	 SetConsoleOutputCP(65001);
	 int x = 60; // vi tri dat lua chon
	 menu(x);
     luachon(x);

     gotoxy(48,0); cout << "--------MA TRẬN--------\n";

        textcolor(10);
        cout << "Bạn có muốn thử lại  ?  [Y/N]";
        cin >> ch;
    	system("cls");
   }


while(toupper(ch)=='Y');
	Sleep(400);
	textcolor(10);
	cout<<"-------------------------------------\n";
	cout<<"\t\tAbout programe"<<endl;
	cout<<"Name's programe: Matran\n";
	cout<<"Created by: "<<"Tran Van Giang-Vu Mai Tuan"<<"\n";
	cout<<"Line numbers: "<<__LINE__<<endl;
	cout<<"Location file "<<__FILE__<<endl;
	cout<<"Date and Time creating: "<<__DATE__<<endl;
	cout<<"Time: "<<__TIME__<<endl;
	cout<<"_____________________________________\n";

system("PAUSE");
return 0;
}

