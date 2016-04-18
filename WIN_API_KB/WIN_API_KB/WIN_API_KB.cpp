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

long WINAPI WndProc(HWND hWnd, UINT iMessage, UINT wParam, LONG lParam)
{
	HDC hDC;				//�����豸�������.
	PAINTSTRUCT ps;			//���������ͼ��Ϣ�Ľṹ�����
	HPEN hPen;				//���廭�ʾ����
	HBRUSH hBrush;			//���廭ˢ��� 

	//���¶���������ַ�����
	static TCHAR cUp[] = _T("You had hitted the UP key");
	static TCHAR cCtrl[] = _T("You had hitted the Ctrl key");
	static TCHAR cShift[] = _T("You had hitted the SHIFT key");
	static TCHAR cCtrl_A[] = _T("You had hitted the CTRL A key");
	static TCHAR cShift_B[] = _T("You had hitted the SHIFT B key");

	//���涨�岢��ʼ��������־������
	static BOOL	nUpKeyDown = FALSE,
						nShiftKeyDown = FALSE,
						nCtrlKeyDown = FALSE,
						nCtrlAKeyDown = FALSE,
						nShiftBKeyDown = FALSE,
						nOtherKeyDown = FALSE;


	switch (iMessage){
	case WM_KEYDOWN:{ 
		switch (wParam){
			case VK_UP:		//�����ϼ�ͷ��ʱ��������Ϊ�档
				nUpKeyDown = TRUE;	 break;
			case VK_SHIFT:			//����shift��ʱ��������Ϊ�档
				nShiftKeyDown = TRUE; break;
			case VK_CONTROL:			//����control��ʱ��������Ϊ��
				nCtrlKeyDown = TRUE;	 break;
			default: 
				nOtherKeyDown = TRUE;  break;
		}
	}
	break;
	case WM_KEYUP:
		InvalidateRect(hWnd, NULL, FALSE);	//����WM_PAINT��Ϣ
		break;

	case WM_CHAR:
		if (wParam == (65 & VK_CONTROL)){	               //������Ctrl+a��ʱ(A���)
			if (nCtrlKeyDown == TRUE){
				nOtherKeyDown = FALSE;
				nCtrlAKeyDown = TRUE;	
				nCtrlKeyDown = FALSE;
			}
		}
		else if (wParam == 98 || wParam == 66){	//������b��ʱ
			if (nShiftKeyDown == TRUE){		//���shift���Ƿ��ڰ���״̬��
				nOtherKeyDown = FALSE;
				nShiftBKeyDown = TRUE;	//��SHIFT������ʱ��������Ϊ��
				nShiftKeyDown = FALSE;
			}
		}
		break;
	
	case WM_PAINT:						//�����ͼ��Ϣ.
		hDC = BeginPaint(hWnd, &ps);
		hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);	//���� �׻�ˢ��
		hPen = (HPEN)GetStockObject(WHITE_PEN);		//�����׻��ʡ�
		SelectObject(hDC, hPen);				//ѡ��׻�ˢ
		SelectObject(hDC, hBrush);			//ѡ��׻���
		SetTextColor(hDC, RGB(255, 0, 0));		//����������ɫΪ��ɫ��

												//�����Ϣ��
		if (nUpKeyDown == TRUE){
			Rectangle(hDC, 0, 0, 300, 200);                         //�����ַ���
			TextOut(hDC, 0, 0, cUp, _tcslen(cUp));
			nUpKeyDown = FALSE;
		}
		else if (nCtrlAKeyDown == TRUE){
			Rectangle(hDC, 0, 0, 300, 200);
			TextOut(hDC, 0, 100, cCtrl_A, _tcslen(cCtrl_A));
			nCtrlAKeyDown = FALSE;
			nCtrlKeyDown = FALSE;
		}
		//else if(nCtrlAKeyDown == TRUE) 
		else if (nCtrlKeyDown == TRUE&&nCtrlAKeyDown == FALSE){
			Rectangle(hDC, 0, 0, 300, 200);
			TextOut(hDC, 0, 60, cCtrl, _tcslen(cCtrl));
			nCtrlKeyDown = FALSE;
		}
		else if (nShiftBKeyDown == TRUE){
			Rectangle(hDC, 0, 0, 300, 200);
			TextOut(hDC, 0, 0, cShift_B, _tcslen(cShift_B));
			nShiftBKeyDown = FALSE;
			nShiftKeyDown = FALSE;
		}
		else if (nShiftBKeyDown == FALSE&&nShiftKeyDown == TRUE){
			Rectangle(hDC, 0, 0, 300, 200);
			TextOut(hDC, 0, 0, cShift, _tcslen(cShift));
			nShiftKeyDown = FALSE;
		}
		else if (nOtherKeyDown == TRUE) {
			Rectangle(hDC, 0, 0, 300, 200);
			nOtherKeyDown = FALSE;
		}
		else;
		//ɾ�����ʺͻ�ˢ
		DeleteObject(hPen);
		DeleteObject(hBrush);
		EndPaint(hWnd, &ps);
		break;
		
	case WM_DESTROY:
		PostQuitMessage(0);	return 0;
		default:	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
	}
	return 0;
}
