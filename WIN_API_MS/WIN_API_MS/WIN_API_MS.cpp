#include "windows.h"
#include "tchar.h"
#define UNICODE


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
	TCHAR lpszClassName[] = L"例";
	TCHAR lpszTitle[] = L"Windows_API";
	//define
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
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

void InvertBlock(HWND hwnd, POINT ptBeg, POINT ptEnd){//此处未用到
	HDC hdc;
	hdc = CreateDC(_T("DISPLAY"), NULL, NULL, NULL);
	ClientToScreen(hwnd, &ptBeg);//转换指定窗口的客户区内的点的坐标
	ClientToScreen(hwnd, &ptEnd);
	PatBlt(hdc, ptBeg.x, ptBeg.y, ptEnd.x - ptBeg.x, ptEnd.y - ptBeg.y, DSTINVERT);
	//这个函数在矩形区内用当前的画笔重画背景和前景, DSTINVERT：将目标矩形反向。 
	DeleteDC(hdc);
}

LRESULT CALLBACK  WndProc(HWND hwnd, UINT message,WPARAM wParam, LPARAM lParam){
	static BOOL  operate = FALSE, ready = TRUE;//operate为按下左键标识，ready为绘制初始图形标识
	static BOOL  origin = TRUE;
	static POINT BeginP, EndP;
	static RECT rect = { 0,0,0,0 };
	HDC          hdc;
	PAINTSTRUCT  PtStr;
	HBRUSH       hBrush;

	switch (message){
	case WM_LBUTTONDOWN:
		if ((!operate) && ready){
			operate = TRUE;		//左键击活俘获
			ready = FALSE;
			SetCapture(hwnd);//把所有的鼠标信息输入到被左键击活的窗口.
			SetCursor(LoadCursor(NULL, IDC_CROSS));	 //载入光标
			BeginP.x = LOWORD(lParam);
			BeginP.y = HIWORD(lParam);
		}
		return 0;
	case WM_MOUSEMOVE:
		if (operate){
			EndP.x = LOWORD(lParam);
			EndP.y = HIWORD(lParam);
			rect.left = BeginP.x<EndP.x ? BeginP.x : EndP.x;
			rect.right = BeginP.x>EndP.x ? BeginP.x : EndP.x;
			rect.top = BeginP.y<EndP.y ? BeginP.y : EndP.y;
			rect.bottom = BeginP.y>EndP.y ? BeginP.y : EndP.y;
			SetCursor(LoadCursor(NULL, IDC_WAIT));	//载入沙漏光标
			InvalidateRect(hwnd, NULL, TRUE);
		}
		return 0;
	case WM_LBUTTONUP:
		if (operate){
			operate = FALSE;
			SetCursor(LoadCursor(NULL, IDC_ARROW));
			ReleaseCapture();	//把鼠标从当前窗口中释放出来
		}
		return 0;
	case WM_PAINT:
		if (ready == FALSE){//非初始状态,曾经按下了左键
			hdc = BeginPaint(hwnd, &PtStr);
			hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
			SelectObject(hdc, hBrush);
			Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
			DeleteObject(hBrush);
			EndPaint(hwnd, &PtStr);
		}
		else { 
			hdc = BeginPaint(hwnd, &PtStr);
			GetClientRect(hwnd, &rect);
			if (origin == true);//初始状态
			else {	//拉伸状态
				hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
				SelectObject(hdc, hBrush);
			}
			Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
			EndPaint(hwnd, &PtStr);
			SetCursor(LoadCursor(NULL, IDC_ARROW));
		}
		return 0;
	case WM_LBUTTONDBLCLK:
		if (ready == FALSE){
			ready = TRUE;
			origin = FALSE;
			InvalidateRect(hwnd, NULL, TRUE);
		}
		return 0;
	case WM_RBUTTONDOWN:
		if (origin == FALSE) {
			origin = TRUE;
			InvalidateRect(hwnd, NULL, TRUE);
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

