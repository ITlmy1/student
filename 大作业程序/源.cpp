#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)//能够使用scanf
void input();
void lookup();
int cal_hw1(double temp );//计算男生体重指数成绩
int cal_hw2(double temp );//计算女生体重指数成绩
int cal_lung1(double temp );//计算男生肺活量成绩
int cal_lung2(double temp );//计算女生肺活量成绩
int cal_performance1(double temp );//计算男生引体向上成绩
int cal_performance2(double temp );//计算女生仰卧起坐成绩
int Student_Search(int num1);//通过遍历查找输入的学号是否存在
void count();//统计学生成绩
void browse();//浏览学生信息
void del();//删除学生成绩
void modify();//修改学生成绩

int n=0;//计数用,统计学生人数
typedef struct student {
	int number;
	char name[20];
	char sex[10];
	double height;
	double weight;
	double hw;//体重指数
	int lung;//肺活量
	int performance;//引体向上or仰卧起坐
	double grade;//学生体育成绩
}stu;
stu student[50];


int main() {
	printf("------------------------------------\n");
	printf("|     学生体测成绩系统         |\n");
	printf("|     退出系统         请按0   |\n");
	printf("|     输入学生成绩     请按1   |\n");
	printf("|     查找学生成绩     请按2   |\n");
	printf("|     修改学生成绩     请按3   |\n");
	printf("|     删除学生成绩     请按4   |\n");
	printf("|     浏览学生成绩     请按5   |\n");
	printf("|     统计学生成绩     请按6   |\n");
	printf("------------------------------------\n");
	printf("注：未有学生成绩时，请先输入学生成绩，别输入错学号哦\n");
	int num = 0;
	while (true)
	{
		printf("\n请输入想要实现的功能：");
		scanf("%d", &num);
		switch (num)
		{
		case 0:return 0; break;
		case 1:input(); break;
		case 2:lookup(); break;
		case 3:modify(); break;
		case 4:del(); break;
		case 5:browse(); break;
		case 6:count(); break;
		default:
			break;
		}
	}
}
int Student_Search(int num1)//通过学号来检索学生信息
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (num1 == student[i].number)
		{
			return i;
		}
	}
	return -1;   //未找到返回 -1 
}

void input() {
	char a;//输入Y or N 决定是否输入下一个学生信息
	while (true) {
		printf("请输入学生信息（学号 姓名 性别 身高(m) 体重(kg) 肺活量 引体向上or仰卧起坐）\n");
		scanf("%d", &student[n].number);
		scanf("%s", &student[n].name);
		scanf("%s", &student[n].sex);
		scanf("%lf", &student[n].height);
		scanf("%lf", &student[n].weight);
		scanf("%d", &student[n].lung);
		scanf("%d", &student[n].performance);
		
		if (Student_Search(student[n].number) == -1) {
			student[n].hw = 0;
			student[n].hw = student[n].weight / (student[n].height * student[n].height);

			int mask_hw = 0, mask_lung = 0, mask_performance = 0;
			if (strcmp(student[n].sex, "男") == 0) {
				mask_hw = cal_hw1(student[n].hw);
				mask_lung = cal_lung1(student[n].lung);
				mask_performance = cal_performance1(student[n].performance);
			}
			else if (strcmp(student[n].sex, "女") == 0) {
				mask_hw = cal_hw2(student[n].hw);
				mask_lung = cal_lung2(student[n].lung);
				mask_performance = cal_performance2(student[n].performance);
			}
			student[n].grade = 0.25 * mask_hw + 0.35 * mask_lung + 0.4 * mask_performance;

		}
		else {
			printf("之前输入过此学号，请重新输入\n");
			n--;
		}
		n++;
		getchar();
		printf("是否继续（y/n）\n");
		a = getchar();
		if (a == 'n')
		{
			break;
		}
		
	}
}

//计算体重指数
//男
int cal_hw1(double temp) {
	int mask_hw = 0;
	if (temp >= 17.9 && temp <= 23.9) {
		mask_hw = 100;
	}
	else if ((temp >= 0 && temp < 17.9) || (temp > 23.9 && temp < 27.9)) {
		mask_hw = 80;
	}
	else if (temp >= 28.0) {
		mask_hw = 60;
	}
	return mask_hw;
}
//女
int cal_hw2(double temp) {
	int mask_hw = 0;
	if (temp >= 17.1 && temp <= 23.9) {
		mask_hw = 100;
	}
	else if ((temp >= 0 && temp < 17.1) || (temp > 23.9 && temp < 27.9)) {
		mask_hw = 80;
	}
	else if (temp >= 28.0) {
		mask_hw = 60;
	}
	return mask_hw;
}

//计算肺活量分数
//男
int cal_lung1(double temp) {
	int mask_lung;
	if (temp > 4800) {
		mask_lung = 100;
	}
	else if (temp >= 4181 && temp <= 4800) {
		mask_lung = 80;
	}
	else if (temp >= 3101 && temp <= 4180) {
		mask_lung = 60;
	}
	else if (temp <= 3100) {
		mask_lung = 30;
	}
	return mask_lung;
}
//女
int cal_lung2(double temp ) {
	int mask_lung;
	if (temp > 3400) {
		mask_lung = 100;
	}
	else if (temp >= 3001 && temp <= 3400) {
		mask_lung = 80;
	}
	else if (temp >= 2051 && temp <= 3000) {
		mask_lung = 60;
	}
	else if (temp <= 2050) {
		mask_lung = 30;
	}
	return mask_lung;
}

//计算引体/仰卧
//男
int cal_performance1(double temp) {
	int mask_performance;
	if (temp > 19) {
		mask_performance = 100;
	}
	else if (temp >= 16 && temp <= 19) {
		mask_performance = 80;
	}
	else if (temp >= 10 && temp <= 15) {
		mask_performance = 60;
	}
	else if (temp <= 9) {
		mask_performance = 30;
	}
	return mask_performance;
}
//女
int cal_performance2(double temp ) {
	int mask_performance;
	if (temp > 56) {
		mask_performance = 100;
	}
	else if (temp >= 53 && temp <= 56) {
		mask_performance = 80;
	}
	else if (temp >= 25 && temp <= 52) {
		mask_performance = 60;
	}
	else if (temp <= 25) {
		mask_performance = 30;
	}
	return mask_performance;
}

//查找学生成绩
void lookup() {
	int number1;
	printf("\n请输入要查找学生的学号：");
	scanf("%d", &number1);
	int i;
	for (i = 0; i < 3; i++) {
		if (number1 == student[i].number) {
			if (student[i].grade >= 95 && student[i].grade <= 100) {
				printf("该学生姓名：%s， 性别：%s， 身高：%.2lf(m)， 体重：%.0lf(kg)， 体重指数：%.2lf,  肺活量：%d， 引体向上or仰卧起坐：%d， 总成绩：%.2lf(优秀）\n",
					student[i].name, student[i].sex, student[i].height, student[i].weight, student[i].hw, student[i].lung, student[i].performance, student[i].grade);
			}else if (student[i].grade >= 80 && student[i].grade < 95) {
				printf("该学生姓名：%s， 性别：%s， 身高：%.2lf(m)， 体重：%.0lf(kg)， 体重指数：%.2lf,  肺活量：%d， 引体向上or仰卧起坐：%d， 总成绩：%.2lf(良好）\n",
					student[i].name, student[i].sex, student[i].height, student[i].weight, student[i].hw, student[i].lung, student[i].performance, student[i].grade);
			}else if (student[i].grade >= 60 && student[i].grade < 80) {
				printf("该学生姓名：%s， 性别：%s， 身高：%.2lf(m)， 体重：%.0lf(kg)， 体重指数：%.2lf,  肺活量：%d， 引体向上or仰卧起坐：%d， 总成绩：%.2lf(及格）\n",
					student[i].name, student[i].sex, student[i].height, student[i].weight, student[i].hw, student[i].lung, student[i].performance, student[i].grade);
			}else if (student[i].grade >= 0 && student[i].grade < 60) {
				printf("该学生姓名：%s， 性别：%s， 身高：%.2lf(m)， 体重：%.0lf(kg)， 体重指数：%.2lf,  肺活量：%d， 引体向上or仰卧起坐：%d， 总成绩：%.2lf(不及格）\n",
					student[i].name, student[i].sex, student[i].height, student[i].weight, student[i].hw, student[i].lung, student[i].performance, student[i].grade);
			}
		}
	}
}

//修改学生成绩
void modify() {
	char a;
	while (true) {
		int id = 0;
		printf("\n请你输入要修改学号：");
		scanf("%d", &id);
		
		int temp = Student_Search(id);
		if (Student_Search(id) == -1) {
			printf("找不到该学号");
		}
		else {
			printf("请输入你要修改的学生信息（姓名 性别 身高(m) 体重(kg) 肺活量 引体向上or仰卧起坐）:\n");
			scanf("%s", &student[temp].name);
			scanf("%s", &student[temp].sex);
			scanf("%lf", &student[temp].height);
			scanf("%lf", &student[temp].weight);
			scanf("%d", &student[temp].lung);
			scanf("%d", &student[temp].performance);
			student[temp].hw = student[temp].weight / (student[temp].height * student[temp].height);

			int mask_hw = 0, mask_lung = 0, mask_performance = 0;
			if (strcmp(student[temp].sex, "男") == 0) {
				mask_hw = cal_hw1(student[temp].hw);
				mask_lung = cal_lung1(student[temp].lung);
				mask_performance = cal_performance1(student[temp].performance);
			}
			else if (strcmp(student[temp].sex, "女") == 0) {
				mask_hw = cal_hw2(student[temp].hw);
				mask_lung = cal_lung2(student[temp].lung);
				mask_performance = cal_performance2(student[temp].performance);
			}
			student[temp].grade = 0.25 * mask_hw + 0.35 * mask_lung + 0.4 * mask_performance;

		}
		getchar();
		printf("是否继续（y/n）\n");
		a = getchar();
		if (a == 'n')
		{
			break;
		}
	}
}

//删除学生成绩
void del() {
	int i = 0;
	int number = 0;
	printf("请输入要删除学生的学号：");
	scanf("%d", &number);
	int j = Student_Search(number);
	if (j == -1) {
		printf("未搜索到该学生学号");
	}
	else {
		for (i = j; i < n - 1; i++) {
			student[i] = student[i + 1];
		}
		n--;
		printf("删除成功");
	}
	

}

//统计学生成绩
void count() {
	double avg = 0;//平均分
	double sum = 0;//总分
	int max = 0;//最大值
	int min = 0;//最小值
	int i = 0;
	for (i = 0; i < n; i++) {
		sum += student[i].grade;
		if (max < student[i].grade) {
			max = i;
		}
		if (min > student[i].grade) {
			min = i;
		}
	}
	avg = sum / n;
	
	printf("最高成绩为：%lf，该学号为：%d，姓名为：%s\n", student[max].grade, student[max].number, student[max].name);
	printf("最低成绩为：%lf，该学号为：%d，姓名为：%s\n", student[min].grade, student[min].number, student[min].name);
	printf("平均分为：%lf", avg);
}
//浏览学生成绩
void browse() {
	int i = 0;
	printf("学号     姓名   性别 身高（m） 体重（kg） 肺活量  引体向上or仰卧起坐  成绩\n");
	for (i = 0; i < n; i++) {
		printf("%8d %6s %2s   %3.2lf     %3.0lf      %4d    %3d    %lf\n", student[i].number, student[i].name, student[i].sex, student[i].height, student[i].weight, student[i].lung, student[i].performance, student[i].grade);
	}
}