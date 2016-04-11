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
	TCHAR lpszClassName[] = L"��2-1";
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
	HPEN hP=(HPEN)GetStockObject(NULL_PEN);				//���廭�ʾ��
	HBRUSH  hB=(HBRUSH)GetStockObject(NULL_BRUSH);			//���廭ˢ���

	switch (message) {
	case WM_PAINT:	//ͨ����ӦWM_PAINT��Ϣ��ɻ�ͼ����
		hdc = BeginPaint(hwnd, &ps);
		SetMapMode(hdc, MM_ANISOTROPIC);       //����ӳ��ģʽ
		hP = (HPEN)GetStockObject(BLACK_PEN);	//��ɫ����
		hB = (HBRUSH)GetStockObject(DKGRAY_BRUSH); //��ˢ
		SelectObject(hdc, hB);   //ѡ��ˢ
		SelectObject(hdc, hP);       //ѡ�񻭱�
		RoundRect(hdc, 50, 120, 100, 200, 15, 15); //����Բ�Ǿ���
		hB = (HBRUSH)GetStockObject(LTGRAY_BRUSH);  //��������ɫ��ˢ
		SelectObject(hdc, hB);  	   //ѡ��ˢ
		Ellipse(hdc, 150, 50, 200, 150); 	   //������Բ
		hB = (HBRUSH)GetStockObject(HOLLOW_BRUSH); //�黭ˢ
		SelectObject(hdc, hB);  	  //ѡ��ˢ
		Pie(hdc, 250, 50, 300, 100, 250, 50, 300, 50);  	//���Ʊ���

		hP = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 255));
		hB = CreateHatchBrush(HS_HORIZONTAL, RGB(0, 255, 0));
		SelectObject(hdc, hP);
		SelectObject(hdc, hB);
		RoundRect(hdc, 35, 220, 115, 270, 15, 15);
		Ellipse(hdc, 125, 170, 225, 220);
		Pie(hdc, 250, 120, 300, 170, 300, 120, 300, 170);

		EndPaint(hwnd, &ps);  	//������ͼ
		break;

	case WM_DESTROY:
		DeleteObject(hP);	//�˳�����ʱɾ������
		DeleteObject(hB);	//�˳�����ʱɾ����ˢ
		PostQuitMessage(0); break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}
	return 0;
}