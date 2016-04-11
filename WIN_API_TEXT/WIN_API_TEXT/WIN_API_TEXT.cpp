#include "windows.h"
#include "math.h"

#define Xpos1  0
#define Ypos1  0
#define WindowWidth1 640
#define WindowHeigth1 480

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//initial
	HWND hwnd;
	MSG Msg;
	WNDCLASS wndclass;
	TCHAR lpszClassName[] = L"例2-1";
	TCHAR lpszTitle[] = L"Spring Festival Scroll";
	//define
	wndclass.style = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = lpszClassName;
	//register
	if (!RegisterClass(&wndclass)) {
		MessageBeep(0);
		return false;
	}
	//create
	hwnd = CreateWindow(
		lpszClassName,
		lpszTitle,
		WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL,
		Xpos1,
		Ypos1,
		WindowWidth1,
		WindowHeigth1,
		NULL,
		NULL,
		hInstance,
		NULL
		);
	//show
	ShowWindow(hwnd, nCmdShow);
	//update
	UpdateWindow(hwnd);
	//message loop
	while (GetMessage(&Msg, NULL, 0, 0)) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

LRESULT CALLBACK WndProc(
	HWND hwnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam) {

	HDC hdc;
	PAINTSTRUCT ps;
	HPEN hP = (HPEN)GetStockObject(NULL_PEN);				//定义画笔句柄
	HBRUSH  hB = (HBRUSH)GetStockObject(NULL_BRUSH);			//定义画刷句柄

	int Xchar, Ychar;
	SIZE size;
	LPCTSTR pstring[] = { L"迎春接福",L"时来万事喜临门",L"春到百花香满地" };
	RECT	rect;					//无效矩形区
	HFONT holdFont, hnewFont;

	switch (message) {
	case WM_CREATE: return 0;
	case WM_PAINT:	//通过响应WM_PAINT消息完成绘图工作
		hnewFont = CreateFont         			//创建一种新的逻辑字体
			(48, 0, 0, 0, 500, 0, 0, 0,
				GB2312_CHARSET, //该字符集支持“楷体”等
				OUT_DEFAULT_PRECIS,
				CLIP_DEFAULT_PRECIS,
				DEFAULT_QUALITY,
				DEFAULT_PITCH & FF_DONTCARE,
				L"楷体");
		hdc = BeginPaint(hwnd, &ps);		 //得到设备环境句柄
		GetClientRect(hwnd, &rect);		 //得到需要绘制的客户区
		holdFont = (HFONT)SelectObject(hdc, hnewFont);  //选择新的字体
		SetTextColor(hdc, RGB(255, 255, 0));	 	//设置文本颜色
		SetBkColor(hdc, RGB(255, 0, 0));	 	//设置背景颜色 
		GetTextExtentPoint32(hdc, pstring[0], 4, &size);

		Xchar = (rect.right - rect.left) / 2 - size.cx / 2;
		Ychar = (rect.bottom - rect.top) / 2 - size.cy / 2 - 170;
		TextOut(hdc, Xchar, Ychar, pstring[0], 4);

		for (int i = 0; i<2; i++){
			int m = pow(-1, i);
			Xchar = (rect.right - rect.left) / 2 - size.cx / 2 * m - 80 * m - i*size.cx / 4;
			for (int j = 0; j<7; j++){
				Ychar = (rect.bottom - rect.top) / 2 - size.cy / 2 - 120 + j*size.cy;
				TextOut(hdc, Xchar, Ychar,pstring[i+1]+j, 1);
			} 
		}
		SelectObject(hdc, holdFont);		 //保存原来的字体格式
		DeleteObject(hnewFont);			 //删除新的字体格式

		break;

	case WM_DESTROY:
		DeleteObject(hP);	//退出窗口时删除画笔
		DeleteObject(hB);	//退出窗口时删除画刷
		PostQuitMessage(0); break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}
	return 0;
}