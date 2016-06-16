#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>  

#pragma warning(disable:4996)
#pragma warning(disable:4566)

#define aboutx 472
#define abouty 178
#define aboutxp 590
#define aboutyp 224

#define instrx 472
#define instry 273
#define instrxp 590
#define instryp 320

#define beginx 472
#define beginy 369
#define beginxp 590
#define beginyp 418

#define backx 38
#define backy 392
#define backxp 156
#define backyp 446

#define back2x 286
#define back2y 457
#define back2xp 366
#define back2yp 475


using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INTERSIBLE -1
#define MenuLength 15
#define PolynLength 10
#define Y 1
#define N 0
typedef int Status;
typedef struct LNode{
	float coef;
	int expn;
	struct LNode *next;
}LNode, *LinkList;//构造数据类型
LNode *MakeNode(float coef, int expn)     //构造节点
{
	LNode *p;
	p = (LinkList)malloc(sizeof(LNode));
	p->coef = coef; p->expn = expn; p->next = NULL;
	return p;
}//end MakeNode
void SetNode(LNode *p, float c, int e)     //填写节点
{
	p->coef = c; p->expn = e;
}//end SetNode
void InitPolyn(LinkList &L)//初始化空多项式L
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
}//end InitPolyn
void OrderInsert(LinkList &L, LNode *s)//有序插入新节点
{
	LinkList p = L, q;
	while (p->next != NULL&&p->next->expn > s->expn)
		p = p->next;//指针移动至s需要插入的位置
	if (p->next == NULL || p->next->expn < s->expn)
	{   //将s插入p的下一位的情况
		s->next = p->next;
		p->next = s;
	}//end if
	else if (p->next->coef + s->coef != 0) p->next->coef = p->next->coef + s->coef;//p->expn==s->expn,且系数和不为零
	else
	{   //p->expn == s->expn, 且系数和不为零，此时删掉p
		q = p->next;
		p->next = q->next;
		free(q);
	}
}//end OrderInsert
void PrintPolyn(char s[],LinkList L)//打印单链表L
{
	LNode *p; int i;
	char sp[50] = { 0 };
	for (i = 1, p = L->next; p != NULL; p = p->next, i++)
	{
		if (i == 1)
		{   //对于第一项可能出现的情况
			if (p->expn == 0)
			{   //第一项为常数项，直接输入系数
				printf("%g", p->coef);
				sprintf(sp, "%g", p->coef);
				strcat(s, sp);
				continue;
			}
			if (p->coef < 0)
			{   //第一项非常数项
				if (p->coef == -1)
				{
					printf("-x^%d", p->expn);//第一项系数为-1，x前面加一“-”
					sprintf(sp,"-x^%d", p->expn);
					strcat(s, sp);
					continue;
				}
				else
				{   //第一项系数为负，直接打印
					printf("%g*x^%d", p->coef, p->expn);
					sprintf(sp, "%g*x^%d", p->coef, p->expn);
					strcat(s, sp);
					continue;
				}
			}
			else if (p->coef == 1)
			{   //第一项指数为1,系数不显示
				printf("x^%d", p->expn);
				sprintf(sp,"x^%d", p->expn);
				strcat(s, sp);
				continue;
			}
			else
			{   //普通项，不打印“+”
				printf("%g*x^%d", p->coef, p->expn);
				sprintf(sp,"%g*x^%d", p->coef, p->expn);
				strcat(s, sp);
				continue;
			}
		}
		else
		{
			if (p->expn == 0)
			{   //常数项，带“+”，直接打印系数
				printf("+%g", p->coef);
				sprintf(sp,"+%g", p->coef);
				strcat(s, sp);
				continue;
			}
			if (p->coef < 0)
			{   //系数为负的情况
				if (p->coef == -1)
				{   //系数为-1的项的情况
					printf("-x^%d", p->expn);
					sprintf(sp,"-x^%d", p->expn);
					strcat(s, sp);
					continue;
				}
				else
				{   //系数为负，直接输入如下格式
					printf("%g*x^%d", p->coef, p->expn);
					sprintf(sp,"%g*x^%d", p->coef, p->expn);
					strcat(s, sp);
					continue;
				}
			}
			else if (p->coef == 1)
			{
				printf("+x^%d", p->expn);//对于系数为1，直接打印x^coef
				sprintf(sp,"+x^%d", p->expn);
				strcat(s, sp);
				continue;
			}
			else
			{
				printf("+%g*x^%d", p->coef, p->expn);//对于一般情况，系数为正，打印时需要再加个“+”
				sprintf(sp,"+%g*x^%d", p->coef, p->expn);
				strcat(s, sp);
				continue;
			}
		}
	}
}//end PrintPolyn
void CopyPolyn(LinkList &La, LinkList &Lb)//复制多项式L
{
	LNode *p, *q;
	for (p = La->next; p; p = p->next)
	{
		q = MakeNode(p->coef, p->expn);//复制p上的每一个节点
		OrderInsert(Lb, q);//然后插入Lb中
	}
}//end CopyPolyn
void DestroyPolyn(LinkList &L)//销毁多项式L
{
	LinkList p, q; p = L;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	L = NULL;
}//end DestroyPolyn
void Insert(LinkList &L, LNode *t) //插节点t至L的末尾
{
	LinkList p = L;
	while (p->next != NULL)
	{   //节点p移至L的最尾
		p = p->next;
	}
	p->next = t; t->next = NULL;
}//end Insert
void AddPolyn(LinkList La, LinkList Lb, LinkList &Lc)//多项式求和
{
	LinkList p = La->next, q = Lb->next, t = Lc->next, f;
	while (p&&q)
	{   //p,q皆非空，比较指数，两指数不等，构造一个由小指数的节点内容组成的节点，插入到和多项式的末尾，p,q后移，否则做系数的加法，得到的非零系数插入和多项式Lc，p,q后移，否则p,q直接后移一位
		if (p->expn < q->expn)
		{
			t = MakeNode(q->coef, q->expn);
			Insert(Lc, t);
			q = q->next;
		}
		else if (p->expn > q->expn)
		{
			t = MakeNode(p->coef, p->expn);
			Insert(Lc, t);
			p = p->next;
		}
		else
		{
			if (p->coef + q->coef != 0)
			{
				t = MakeNode(p->coef + q->coef, p->expn);
				Insert(Lc, t);
				p = p->next;
				q = q->next;
			}
			else
			{
				p = p->next;
				q = q->next;
			}
		}
	}//end while
	if (p != NULL)
	{//p非空，将剩余的La多项式直接插入Lc中
		for (; p; p = p->next)
		{
			f = MakeNode((p->coef), p->expn);
			OrderInsert(Lc, f);
		}
	}
	if (q != NULL)
	{//q非空，将剩余的Lb多项式插入Lc中
		for (; q; q = q->next)
		{
			f = MakeNode((q->coef), q->expn);
			OrderInsert(Lc, f);
		}
	}
}//end AddPolyn
void MinusPolyn(LinkList La, LinkList Lb, LinkList &Lc) //多项式求差
{
	LinkList p = La->next, q = Lb->next, t, f;
	while (p&&q)
	{   //p,q皆非空
		if (p->expn < q->expn)
		{   //p的指数小于q的指数，直接插入p至Lc中
			t = MakeNode(-(q->coef), q->expn);
			Insert(Lc, t);
			q = q->next;
		}
		else if (p->expn > q->expn)
		{   //p的指数大于q的指数，将q的系数乘以-1，再插入
			t = MakeNode(p->coef, p->expn);
			Insert(Lc, t);
			p = p->next;

		}
		else
		{
			if (p->coef - q->coef != 0)
			{   //两节点指数相等，做系数的减法，非零系数插入Lc中
				t = MakeNode(p->coef - q->coef, p->expn);
				Insert(Lc, t);
				p = p->next;
				q = q->next;
			}
			else
			{   //零系数不插入，直接让p,q后移一位
				p = p->next;
				q = q->next;
			}
		}
	}
	if (p != NULL)
	{//p非空，将剩余项插入Lc中
		for (; p; p = p->next)
		{
			f = MakeNode((p->coef), p->expn);
			OrderInsert(Lc, f);
		}
	}
	if (q != NULL)
	{   //q非空，将其各节点系数乘以-1，再插入
		for (; q; q = q->next)
		{
			f = MakeNode(-(q->coef), q->expn);
			OrderInsert(Lc, f);
		}
	}
}//end MinusPolyn
void InsituMinusPolyn(LinkList &La, LinkList Lb)//多项式的就地减法
{
	LinkList p = Lb->next, q;
	for (; p; p = p->next)
	{
		q = MakeNode(-(p->coef), p->expn);
		OrderInsert(La, q);
	}
}//end InstiuMinusPolyn
void ChangePolyn(LinkList &La, float coef, int expn, float coeft, int expnt)//修改多项式
{
	LinkList p = La, q, r;
	while (p->next->coef != coef || p->next->expn != expn)
	{   //寻找要修改的那一项
		p = p->next;
	}
	q = p->next; p->next = q->next; free(q);//删除该项
	r = MakeNode(coeft, expnt);
	OrderInsert(La, r);//将修改后的项插入多项式中
}//end ChangePolyn
double Value(LinkList &L, double x)//多项式求值
{
	LinkList p = L->next; double value = 0;
	for (; p; p = p->next)
	{
		value += (p->coef)*pow(x, p->expn);
	}
	return value;
}//end Value
int Compare(LinkList La, float coef, int expn)//查找多项式中的某一项特定节点
{
	LinkList p = La->next;
	while (p)
	{
		if (p->coef == coef&&p->expn == expn) return 1;//找到该节点，返回1
		else p = p->next;
	}
	return 0;
}//end compare
void DerivationPolyn(LinkList L, LinkList &LDe, int order)//多项式求导：对L求order次导数，将导数多项式放入LDe中
{
	LinkList p = L->next, q; int i;
	while (p->expn < order)
	{//寻找指数项大于order的项
		p = p->next;
	}
	if (!p) return;//p空，说明求order次导后导数为常数0
	for (; p; p = p->next)
	{   //对每一项求导
		q = MakeNode(p->coef, p->expn);//记录下p节点的指数系数
		for (i = 1; i <= order; i++)
		{  //每求一次导，系数乘以指数，指数减1
			q->coef *= q->expn;
			q->expn--;
		}
		Insert(LDe, q);//将求导后的新节点q插入LDe中
	}
}//end DerivationPolyn
void IntegralPolyn(LinkList &L, LinkList &LIn, int order)
{   //多项式求积分：对L求order次积分，将积分多项式放入LDe中
	LinkList p = L->next, q = LIn; int i;
	if (!p) return;//p空
	for (; p; p = p->next)
	{
		q = MakeNode(p->coef, p->expn);//记录下p的指数系数
		for (i = 1; i < order + 1; i++)
		{//每求一次积分，指数自增一次，系数除以指数加一
			q->coef /= q->expn + 1;
			q->expn++;
		}
		Insert(LIn, q);//将求积分后的新节点q插入LIn中
	}

}//end IntegralPolyn
void MutiplyPolyn(LinkList La, LinkList Lb, LinkList &Lc)
{   //多项式乘法：La乘以Lb，所得积放入Lc中
	LinkList p = La->next, q = Lb->next, t;
	for (; p; p = p->next)
	{   //对p中每一项循环
		for (; q; q = q->next)
		{   //对q中每一项循环
			t = MakeNode(p->coef*q->coef, p->expn + q->expn);
			OrderInsert(Lc, t);
		}
		q = Lb->next;
	}
}//end MutiplyPolyn
void DividePolyn(LinkList La, LinkList Lb, LinkList &Lc, LinkList &Ld)
{   //多项式除法：La除以Lb，商放入Lc中，余式放入Ld中
	LinkList p = La->next, q = Lb->next, r = NULL, Le = MakeNode(0, 0), Lf = MakeNode(0, 0);
	if (p->expn < q->expn)
	{   //被除式首项指数小于除式首项指数，商为零
		CopyPolyn(La, Ld);
		return;
	}
	else if (p->expn == q->expn)
	{   //被除式首项指数等于除式首项指数，仅做一次除法
		r = MakeNode(p->coef / q->coef, 0);
		Insert(Lc, r);
		MutiplyPolyn(Lc, Lb, Le);
		MinusPolyn(La, Le, Ld);
	}
	else
	{   //被除式首项指数等于除式首项指数，商为多项式
		r = MakeNode(p->coef / q->coef, p->expn - q->expn);//被除式与除式最高次项的除法
		Insert(Lc, r);//将所得结果插入Lc中
		MutiplyPolyn(Lb, Lc, Le);//Lb*Lc放入到Le中
		MinusPolyn(La, Le, Ld);//将La减去Le的结果放进Ld
		DestroyPolyn(Le->next);
		p = Ld->next; r = NULL;//清空Le，r，p指向Ld的next
		while (1)
		{
			if ((p->expn) < (q->expn)) break;
			r = MakeNode(p->coef / q->coef, p->expn - q->expn);//余式与除式最高次项的除法
			OrderInsert(Lc, r);//将所得结果插入Lc中
			Lf->next = MakeNode(r->coef, r->expn);//将所得结果另放入Lf中
			MutiplyPolyn(Lf, Lb, Le);//Lb*Lf放入到Le中
			InsituMinusPolyn(Ld, Le);//将Ld就地减去Le
			DestroyPolyn(Le->next);
			DestroyPolyn(Lf->next);//清空Le，Lf
			p = Ld->next; r = NULL;//清空r，p仍然指向Ld的next
		}
		return;
	}
}//end DividePolyn
void Involution(LinkList La, int order, LinkList &Lb)
{   //多项式乘方：La乘以自身order次，所得结果放入Lb中
	int i; LinkList Lc = MakeNode(0, 0), Ld = MakeNode(0, 0);
	if (order == 0) Lb->next = MakeNode(1, 0);//零次方时值为1；构造一个（1，0）节点在Lb->next
	else if (order == 1) CopyPolyn(La, Lb);//一次方时直接复制即可
	else
	{
		for (i = 1; i < order; i++)
		{
			if (i == 1)
			{//第一次运算为La*La，放入Lc中
				MutiplyPolyn(La, La, Lc);
				continue;
			}
			if (i % 2 == 0)
			{//若i偶数,则要进行第偶数次乘方，放入Ld中，此前清空Lc
				DestroyPolyn(Ld->next);
				MutiplyPolyn(La, Lc, Ld);
			}
			else
			{//若i奇数,则要进行第奇数次乘方，放入Lc中，此前清空Ld
				DestroyPolyn(Lc->next);
				MutiplyPolyn(La, Ld, Lc);
			}
		}
		if ((Lc->next->expn)>(Ld->next->expn)) //将首项系数大的放入Lb中
			CopyPolyn(Lc, Lb);
		else CopyPolyn(Ld, Lb);
	}
	return;
}

void start(){
	initgraph(640, 480);
	cleardevice();
	setbkcolor(WHITE);
	loop: IMAGE image;//主界面图像载入
	loadimage(&image,_T( "start.gif"), 640, 480, 1);
	putimage(0, 0, &image);
	MOUSEMSG mousemsg;
	while (true){
		if (MouseHit){
			mousemsg = GetMouseMsg();//获取鼠标信息
			if (mousemsg.x >= aboutx && mousemsg.x <= aboutxp && mousemsg.y >= abouty && mousemsg.y <= aboutyp){//关于我们
				if (mousemsg.mkLButton){
					loadimage(&image, _T("member.gif"), 640, 480, 1);
					putimage(0, 0, &image);
					while (true){
						if (MouseHit){
							mousemsg = GetMouseMsg();//获取鼠标信息
							if (mousemsg.x >= backx && mousemsg.x <= backxp && mousemsg.y >= backy && mousemsg.y <= backyp){//判断鼠标位置
								if (mousemsg.mkLButton){
									goto loop;
								}
							}
						}
					}
				}
			}
			else if (mousemsg.x >= instrx && mousemsg.x <= instrxp && mousemsg.y >= instry && mousemsg.y <= instryp){//介绍
				if (mousemsg.mkLButton){
					loadimage(&image, _T("help.gif"), 640, 480, 1);
					putimage(0, 0, &image);
					while (true){
						if (MouseHit){
							mousemsg = GetMouseMsg();//获取鼠标信息
							if (mousemsg.x >= back2x && mousemsg.x <= back2xp && mousemsg.y >= back2y && mousemsg.y <= back2yp){//判断鼠标位置
								if (mousemsg.mkLButton){
									goto loop;
								}
							}
						}
					}
				}
			}
			else if (mousemsg.x >= beginx && mousemsg.x <= beginxp && mousemsg.y >= beginy && mousemsg.y <= beginyp){//开始
				if (mousemsg.mkLButton){
					break;
				}
			}
		}
	}
	closegraph();
}

int main()
{
	int menu, input, i, j, address, expn = 0, add1, add2, sum, answer, expnt, order, newaddress, muti1, muti2, product, div1, div2, divi, residue;
	float coef = 1, coeft; double value, x;
	LinkList L[PolynLength] = { NULL }, p;
	char ployout[100] = { 0 };

	start();//开始界面

	while (1)
	{
		char *Menu[MenuLength] = { "退出", "创建多项式", "显示多项式", "复制多项式", "求和", "求差", "求值", "销毁多项式", "清空多项式", "修改多项式", "求导", "求积分", "求积", "求商", "乘方" };//菜单选项
		printf("\t\t*****多项式运算器*****\n");
		for (i = 0; i < MenuLength; i++)
			printf("\t\t%d.%s;\n", i, Menu[i]);
		printf("请选择：");
	
		input = scanf("%d", &menu);
		if (input == EOF || input != 1 || menu < 0)
		{   //防止输入时有错误：
			printf("error!\n");
			break;
		}
		else if (menu > 15) printf("菜单不存在，请重新选择：");//输入数超出菜单选项范围
		else switch (menu)
		{
		case 0:
			return 0; break;
		case 1:
			printf("请输入您创建的多项式地址（0-9）：");
			input = scanf("%d", &address);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				return 0;
			}
			if (address > 9 || address < 0)
			{
				printf("地址不存在，请重新输入！\n");
				break;
			}
			InitPolyn(L[address]);//初始化L[address]
			L[address] = MakeNode(0, 0);//构造头节点（0，0）
			i = 1;
			while (1)
			{
				printf("请输入多项式第%d项的系数和指数：", i);
				input = scanf("%f,%d", &coef, &expn);
				if (input == EOF || input != 2)
				{
					printf("error!\n");
					break;
				}
				if (coef == 0 && expn == 0) break;//创建多项式结束标志
				if (coef == 0 || expn<0)
				{//不接受指数小于零的项
					printf("请重新输入！");
					continue;
				}
				p = MakeNode(coef, expn);
				OrderInsert(L[address], p);
				i++;
			}
			printf("创建成功！"); break;
		case 2:
			for (i = 0; i < PolynLength; i++)
			{
				printf("%d:", i);
				sprintf(ployout,"%d:", i);
				p = L[i];
				if (p != NULL)
				{
					if (p->next == NULL) printf("0\n");//p已初始化，却仅有一个头节点（0，0）
					else
					{
						PrintPolyn(ployout,p);
						printf("\n");
						//strcat(ployout, "\n");
						//HWND wnd = GetHWnd();
						//MessageBox(wnd, ployout, "信息", MB_OK | MB_ICONWARNING);
						//printf("%s", ployout);
					}

				}
				else printf("\n");
			}
			break;
		case 3:
			printf("请输入要复制的多项式地址和新多项式的地址（0-9）:\n");
			input = scanf("%d,%d", &i, &j);
			if (input == EOF || input != 2)
			{
				printf("error!\n");
				break;
			}
			InitPolyn(L[j]);//初始化L[j]
			CopyPolyn(L[i], L[j]);//复制L[i]至L[j]中
			printf("复制成功！");
			break;
		case 4:
			printf("请输入要求和的两多项式地址（0-9）:\n");
			input = scanf("%d,%d", &add1, &add2);
			if (input == EOF || input != 2)
			{
				printf("error!\n");
				break;
			}
			while ((!L[add1]) && (!L[add2]))
			{
				printf("输入地址不存在多项式，请重新输入！");
				input = scanf("&d,%d", &add1, &add2);
				if (input == EOF || input != 1)
				{
					printf("error!\n");
					break;
				}
			}
			printf("请输入和多项式需要放入的地址（0-9）:\n");
			input = scanf("%d", &sum);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			if (!L[sum])
			{   //L[sum]为空
				InitPolyn(L[sum]);
				L[sum] = MakeNode(0, 0);
				AddPolyn(L[add1], L[add2], L[sum]);
			}
			else
			{   //L[sum]非空
				printf("该处存在多项式，是否覆盖？1/0\n");
				input = scanf("%d", &answer);
				if (input == EOF || input != 1)
				{
					printf("error!\n");
					break;
				}
				if (answer == 1)
				{
					DestroyPolyn(L[sum]->next);//清空L[sum]
					AddPolyn(L[add1], L[add2], L[sum]);
				}
				else break;
			}
			printf("求和成功");
			break;
		case 5:
			printf("请输入要求差的两多项式地址（0-9）:\n");
			input = scanf("%d,%d", &add1, &add2);
			if (input == EOF || input != 2)
			{
				printf("error!\n");
				break;
			}
			while ((!L[add1]) && (!L[add2]))
			{
				printf("输入地址不存在多项式，请重新输入！");
				input = scanf("&d,%d", &add1, &add2);
				if (input == EOF || input != 1)
				{
					printf("error!\n");
					break;
				}
			}
			printf("请输入差多项式需要放入的地址（0-9）:\n");
			input = scanf("%d", &sum);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			if (!L[sum])
			{
				InitPolyn(L[sum]);
				L[sum] = MakeNode(0, 0);
				MinusPolyn(L[add1], L[add2], L[sum]);
			}
			else
			{
				printf("该处存在多项式，是否覆盖？Y/N\n");
				input = scanf("%d", &answer);
				if (answer == 1)
				{
					DestroyPolyn(L[sum]->next);//清空L[sum]
					MinusPolyn(L[add1], L[add2], L[sum]);
				}
				else break;
			}
			printf("求差成功！");
			break;
		case 6:
			printf("请问要求值多项式的地址（0-9）；");
			scanf("%d", &address);
			if (L[address] == NULL) printf("该地址多项式不存在，请重新输入！");
			else
			{
				printf("x=?");
				scanf("%lf", &x);
				value = Value(L[address], x);
				printf("原式=%g", value);
			}
			break;
		case 7:
			printf("请输入您要销毁的多项式地址（0-9）：");
			input = scanf("%d", &i);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			if (L[i] == NULL) printf("该组多项式不存在！");
			else
			{
				DestroyPolyn(L[i]);
				printf("销毁成功！");
			}
			break;
		case 8:
			printf("请输入您要销毁的多项式地址（0-9）：");
			input = scanf("%d", &i);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			if (L[i] == NULL) printf("该组多项式不存在！");
			else
			{
				DestroyPolyn(L[i]->next);
				printf("清空成功！");
			}
			break;
		case 9:
			printf("请输入您要修改的多项式地址（0-9）：");
			input = scanf("%d", &i);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			if (L[i] == NULL) printf("该组多项式不存在！");
			else
			{
				printf("对该多项式进行整体替换还是修改单项？1/0:");
				scanf("%d", &answer);
				if (answer == 1)
				{
					DestroyPolyn(L[i]);
					InitPolyn(L[i]);
					L[i] = MakeNode(0, 0);	j = 1;
					while (1)
					{   //整体替换时重复case1中操作
						printf("请输入新多项式第%d项的系数和指数：", j);
						input = scanf("%f,%d", &coef, &expn);
						if (input == EOF || input != 2)
						{
							printf("error!\n");
							break;
						}
						if (coef == 0 && expn == 0) break;
						p = MakeNode(coef, expn);
						OrderInsert(L[i], p);
						j++;
					}
				}
				else if (answer == 0)
				{   //修改单项
					printf("请输入修改单项的系数和指数：");
					input = scanf("%f,%d", &coef, &expn);
					if (input == EOF || input != 2)
					{
						printf("error!\n");
						break;
					}
					if (Compare(L[i], coef, expn) == 0)
					{   //遍历整个多项式寻找需要修改的项
						printf("该项不存在，是否插入？1/0:");
						scanf("%d", &answer);
						if (answer == 1)
						{
							p = MakeNode(coef, expn);
							OrderInsert(L[address], p);
						}
						else break;
					}
					else
					{
						printf("请输入改后的系数与指数：");
						scanf("%f,%d", &coeft, &expnt);
						ChangePolyn(L[i], coef, expn, coeft, expnt);
					}
				}
				else
				{   //使用者胡乱输入的情况
					printf("error!");
				}
			}
			break;
		case 10:
			printf("请问求导的多项式在几号地址？");
			input = scanf("%d", &address);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			printf("请问求几阶导？");
			input = scanf("%d", &order);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			printf("请问倒数多项式放在几号地址？");
			input = scanf("%d", &newaddress);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			if (!L[newaddress])
			{   //L[address]非空
				InitPolyn(L[newaddress]);
				L[newaddress] = MakeNode(0, 0);
				DerivationPolyn(L[address], L[newaddress], order);
				printf("求导成功！");
			}
			else
			{
				printf("该处已有多项式，是否覆盖？Y/N");
				scanf("%d", &answer);
				if (answer == 1)
				{
					InitPolyn(L[newaddress]);
					L[newaddress] = MakeNode(0, 0);
					DerivationPolyn(L[address], L[newaddress], order);
					printf("求导成功！");
				}
				else break;//不覆盖时直接跳出
			}
			break;
		case 11:
			printf("请问求积分的多项式在几号地址？");
			input = scanf("%d", &address);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			printf("请问求几次积分？");
			input = scanf("%d", &order);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			printf("请问积分后的多项式放在几号地址？");
			input = scanf("%d", &newaddress);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			if (!L[newaddress])
			{
				InitPolyn(L[newaddress]);
				L[newaddress] = MakeNode(0, 0);
				IntegralPolyn(L[address], L[newaddress], order);
				printf("积分成功！");
			}
			else
			{
				printf("该处已有多项式，是否覆盖？Y/N");
				input = scanf("%d", &answer);
				if (input == EOF || input != 1)
				{
					printf("error!\n");
					break;
				}
				if (answer == 1)
				{
					InitPolyn(L[newaddress]);
					L[newaddress] = MakeNode(0, 0);
					IntegralPolyn(L[address], L[newaddress], order);
					printf("积分成功！");
				}
				else break;
			}
			break;
		case 12:
			printf("请输入两个乘数多项式地址（0-9）：");
			input = scanf("%d,%d", &muti1, &muti2);
			if (input == EOF || input != 2)
			{
				printf("error!\n");
				break;
			}
			while ((!L[muti1]) || (!L[muti2]))
			{   //两乘数存在NULL
				printf("输入地址不存在多项式，请重新输入！");
				input = scanf("%d,%d", &muti1, &muti2);
				if (input == EOF || input != 2)
				{
					printf("error!\n");
					return 0;
				}
			}
			printf("请输入积多项式地址（0-9）：");
			input = scanf("%d", &product);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			if (!L[product])
			{   //积的地址空
				InitPolyn(L[product]);
				L[product] = MakeNode(0, 0);
				MutiplyPolyn(L[muti1], L[muti2], L[product]);
			}
			else
			{
				printf("该处存在多项式，是否覆盖？Y/N\n");
				input = scanf("%d", &answer);
				if (input == EOF || input != 1)
				{
					printf("error!\n");
					break;
				}
				if (answer == 1)
				{
					DestroyPolyn(L[product]->next);
					MutiplyPolyn(L[muti1], L[muti2], L[product]);
				}
				else break;
			}
			break;
		case 13:
			printf("请输入被除数与除数多项式地址（0-9）：");
			input = scanf("%d,%d", &div1, &div2);
			if (input == EOF || input != 2)
			{
				printf("error!\n");
				break;
			}
			while ((!L[div1]) || (!L[div2]))
			{   //被除数与除数存在NULL
				printf("输入地址不存在多项式，请重新输入！");
				input = scanf("%d,%d", &div1, &div2);
				if (input == EOF || input != 2)
				{
					printf("error!\n");
					return 0;
				}
			}
			printf("请输入商多项式和余式地址（0-9）：");
			input = scanf("%d,%d", &divi, &residue);
			if (input == EOF || input != 2)
			{
				printf("error!\n");
				break;
			}
			if ((!L[divi]) && (!L[residue]))
			{
				InitPolyn(L[divi]);
				L[divi] = MakeNode(0, 0);
				InitPolyn(L[residue]);
				L[residue] = MakeNode(0, 0);
				DividePolyn(L[div1], L[div2], L[divi], L[residue]);
			}
			else
			{
				printf("这两个地址中存在多项式，是否覆盖？Y/N\n");
				input = scanf("%d", &answer);
				if (input == EOF || input != 1)
				{
					printf("error!\n");
					break;
				}
				if (answer == 1)
				{
					if (!L[divi]) DestroyPolyn(L[divi]->next);//清空L[divi]
					if (!L[residue]) DestroyPolyn(L[residue]->next);//清空L[residue]
					DividePolyn(L[div1], L[div2], L[divi], L[residue]);
				}
				else break;
			}
			break;
		case 14:
			printf("请输入需要乘方的多项式地址：（0-9）");
			input = scanf("%d", &muti1);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			printf("请输入需要乘方的次数：");
			input = scanf("%d", &order);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			printf("请输入乘方后多项式地址：（0-9）");
			input = scanf("%d", &product);
			if (input == EOF || input != 1)
			{
				printf("error!\n");
				break;
			}
			if (!(L[product]))
			{
				InitPolyn(L[product]);
				Involution(L[muti1], order, L[product]);
			}
			else
			{
				printf("该处存在多项式，是否覆盖？Y/N\n");
				input = scanf("%d", &answer);
				if (input == EOF || input != 1)
				{
					printf("error!\n");
					break;
				}
				if (answer == 1)
				{
					DestroyPolyn(L[product]->next);
					Involution(L[muti1], order, L[product]);
				}
				else break;
			}
			break;
		}
	}
}
