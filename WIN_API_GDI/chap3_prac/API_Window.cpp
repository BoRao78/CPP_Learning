#include "windows.h"

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
	TCHAR lpszTitle[] = L"My_drawing";
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
		WS_OVERLAPPEDWINDOW|WS_HSCROLL|WS_VSCROLL,
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
	HPEN hP=(HPEN)GetStockObject(NULL_PEN);				//定义画笔句柄
	HBRUSH  hB=(HBRUSH)GetStockObject(NULL_BRUSH);			//定义画刷句柄

	switch (message) {
	case WM_PAINT:	//通过响应WM_PAINT消息完成绘图工作
		hdc = BeginPaint(hwnd, &ps);
		SetMapMode(hdc, MM_ANISOTROPIC);       //设置映像模式
		hP = (HPEN)GetStockObject(BLACK_PEN);	//黑色画笔
		hB = (HBRUSH)GetStockObject(DKGRAY_BRUSH); //画刷
		SelectObject(hdc, hB);   //选择画刷
		SelectObject(hdc, hP);       //选择画笔
		RoundRect(hdc, 50, 120, 100, 200, 15, 15); //绘制圆角矩形
		hB = (HBRUSH)GetStockObject(LTGRAY_BRUSH);  //采用亮灰色画刷
		SelectObject(hdc, hB);  	   //选择画刷
		Ellipse(hdc, 150, 50, 200, 150); 	   //绘制椭圆
		hB = (HBRUSH)GetStockObject(HOLLOW_BRUSH); //虚画刷
		SelectObject(hdc, hB);  	  //选择画刷
		Pie(hdc, 250, 50, 300, 100, 250, 50, 300, 50);  	//绘制饼形

		hP = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 255));
		hB = CreateHatchBrush(HS_HORIZONTAL, RGB(0, 255, 0));
		SelectObject(hdc, hP);
		SelectObject(hdc, hB);
		RoundRect(hdc, 35, 220, 115, 270, 15, 15);
		Ellipse(hdc, 125, 170, 225, 220);
		Pie(hdc, 250, 120, 300, 170, 300, 120, 300, 170);

		EndPaint(hwnd, &ps);  	//结束绘图
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