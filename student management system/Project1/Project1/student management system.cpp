#define  _CRT_SECURE_NO_WARNINGS  //解决scanf
#define _CRT_SECURE_NO_WARNINGS//禁用安全函数警告
#pragma warning(disable:6031)//禁用 6031 的安全警告

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
typedef struct student ST;
typedef struct activity SA;

void welcome();
void input();
void display();
void search_student(char _id[]);
void modify(char _xid[]);
void modify_test();

struct student //学生
{
	char name[20];
	char id[30];
	char sex[20];
	char spty[20];
	char clas[20];
	char date[50];
};

struct activity // 活动
{
	char acname[60];
};

int main()
{
	char u[20], p[20];
	system("color 4");
	printf("*******************************************************\n");
	printf("*            <欢迎来到学生信息管理系统>               *\n");
	printf("*******************************************************\n");
	printf("请输入用户名和密码(以空格分开)$>");
	scanf("%s %s", u, p);
	
	if ((strcmp(u, "admin") == 0) && strcmp(p, "admin") == 0) //用户密码判断
	{
		while (1)
		{
			welcome();
			char x = _getch();
			switch (x)
{
case '1':
{
	input(); break;	
}
case '2':
{
	printf("请输入学号$>");
	char _xid[25];
	scanf("%s", _xid);
	search_student(_xid); 
	break;
}
case '3':
{
	char pass[30];
	printf("请输入管理员密码$>");
	cin >> pass;
	
	if (strcmp(pass, "root33846") == 0)
	{
		printf("请输入学生id:\n");
		char _xid[50];
		scanf("%s", _xid);
		modify(_xid);
		break;
	}
	else {
		printf("管理员密码错误 修改失败!\n");
		system("pause");
	}break;
	
	
}
case '4':
{
	display(); break;
}
case '5':
{
	printf("系统已退出 欢迎下次使用(请按任意键退出)\n");
	exit(0);
} break;
	
	default: printf("输入错误 系统自动退出!\n"); exit(0); break;
	
}
		}
	}
	else {
		cout << "用户名或密码错误 系统登录失败!" << endl;
	}
	return 0;
}

void welcome() //欢迎页
{
	system("color e3");
	system("cls");
	printf("*****************************************************\n");
	printf("*              欢迎来到学生信息管理系统             *\n");
	printf("*                     1.信息录入                    *\n");
	printf("*                     2.信息查找                    *\n");
	printf("*                     3.信息修改                    *\n");
	printf("*                     4.信息显示                    *\n");
	printf("*                     5.退出系统                    *\n");
	printf("*****************************************************\n");
	printf("请输入序号执行$>\n");
}

void input() //信息录入
{
	ST st;
	SA sa;
	
	FILE* fp = fopen("student.txt", "a"); //打开文件
	
	printf("请输入姓名:\n");
	scanf("%s", st.name);
	printf("请输入学号:\n");
	scanf("%s", st.id);
	printf("请输入性别:\n");
	scanf("%s", st.sex);
	printf("请输入专业:\n");
	scanf("%s", st.spty);
	printf("请输入出生年月:\n");
	scanf("%s", st.date);
	printf("请输入班级:\n");
	scanf("%s", st.clas);
	printf("请输入活动名称\n");
	scanf("%s", sa.acname);
	
	if (fp == NULL)
	{
		printf("文件打开失败 信息未录入!\n");
		return;
	}
	else {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			st.name,st.id,st.sex,st.spty,st.date,st.clas,sa.acname);
		
		fclose(fp);
		printf("学生信息录入完成!\n");
		system("pause");
		system("cls");
	}
}

void search_student(char _id[]) //学生信息查找
{
	ST st;
	SA sa;
	FILE* fp = fopen("student.txt", "r");
	
	if (fp == NULL)
	{
		printf("文件打开失败 信息查找失败!\n");
		return;
	}
	else
	{
		while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",
			st.name, st.id, st.sex, st.spty, st.date, st.clas, sa.acname) != EOF)
		{
			if (strcmp(st.id, _id) == 0)
			{
				printf("姓名:%s  学号:%s  性别:%s  专业:%s  出生年月:%s  班级:%s  活动名称:%s\n",
					st.name, st.id, st.sex, st.spty, st.date, st.clas, sa.acname);
				fclose(fp);
				system("pause");
			}
			
		}
		
	}
}

void modify(char _xid[]) //修改
{
	int mod = 0;
	ST st;
	SA sa;
	FILE* xp = fopen("student.txt", "r");
	if (xp == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	
	FILE* tem = fopen("tem.txt", "w");
	if (tem == NULL)
	{
		printf("文件打开失败\n");
		fclose(xp);
		return;
	}
	
	while (fscanf(xp, "%s %s %s %s %s %s %s\n",
		st.name, st.id, st.sex, st.spty, st.date, st.clas, sa.acname) != EOF)
	{
		if (strcmp(st.id, _xid) == 0)
		{ 
			modify_test();
			printf("请输入对应序号更改：");
			char x = _getch();
			switch (x)
{
case '1':
	printf("请输入新的姓名: ");
	scanf("%s", st.name);  break;
	
case '2':
	printf("请输入新的学号: ");
	scanf("%s", st.id); break;
case '3':
	printf("请输入新的学号: ");
	scanf("%s", st.id); break;
case '4':
	printf("请输入新的性别: ");
	scanf("%s", st.sex); break;
case '5':
	printf("请输入新的专业: ");
	scanf("%s", st.spty); break;
case '6':
	printf("请输入新的出生年月: ");
	scanf("%s", st.date); break;
case '7':
	printf("请输入新的班级: ");
	scanf("%s", st.clas); break;
case '8':
	printf("请输入新的活动信息: ");
	scanf("%s", sa.acname); break;
}
			mod = 1;
		}
		fprintf(tem, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			st.name, st.id, st.sex, st.spty, st.date, st.clas, sa.acname);
	}
	fclose(xp);
	fclose(tem);
	if (mod)
	{
		remove("student.txt");
		rename("tem.txt", "student.txt");
		printf("完成修改!\n");
		system("pause");
	}
	else
	{
		remove("tem.txt");
		printf("没找到学生!\n");
	}
	
	
}

void display() //信息显示
{
	char str[700];
	FILE* fp;
	fp = fopen("student.txt", "r");
	
	if (fp == nullptr) {
		printf("学生信息显示失败!\n");
	}
	while (fgets(str, 700, fp) != NULL)
	{
		printf("%s\n", str);
	};
	
	system("pause");
	fclose(fp);
}

void modify_test()
{
	printf("1.姓名  2.学号  3.性别\n");
	printf("4.专业  5.出生年月\n");
	printf("6.班级  7.信息\n");
}


