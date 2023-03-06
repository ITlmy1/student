#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)//�ܹ�ʹ��scanf
void input();
void lookup();
int cal_hw1(double temp );//������������ָ���ɼ�
int cal_hw2(double temp );//����Ů������ָ���ɼ�
int cal_lung1(double temp );//���������λ����ɼ�
int cal_lung2(double temp );//����Ů���λ����ɼ�
int cal_performance1(double temp );//���������������ϳɼ�
int cal_performance2(double temp );//����Ů�����������ɼ�
int Student_Search(int num1);//ͨ���������������ѧ���Ƿ����
void count();//ͳ��ѧ���ɼ�
void browse();//���ѧ����Ϣ
void del();//ɾ��ѧ���ɼ�
void modify();//�޸�ѧ���ɼ�

int n=0;//������,ͳ��ѧ������
typedef struct student {
	int number;
	char name[20];
	char sex[10];
	double height;
	double weight;
	double hw;//����ָ��
	int lung;//�λ���
	int performance;//��������or��������
	double grade;//ѧ�������ɼ�
}stu;
stu student[50];


int main() {
	printf("------------------------------------\n");
	printf("|     ѧ�����ɼ�ϵͳ         |\n");
	printf("|     �˳�ϵͳ         �밴0   |\n");
	printf("|     ����ѧ���ɼ�     �밴1   |\n");
	printf("|     ����ѧ���ɼ�     �밴2   |\n");
	printf("|     �޸�ѧ���ɼ�     �밴3   |\n");
	printf("|     ɾ��ѧ���ɼ�     �밴4   |\n");
	printf("|     ���ѧ���ɼ�     �밴5   |\n");
	printf("|     ͳ��ѧ���ɼ�     �밴6   |\n");
	printf("------------------------------------\n");
	printf("ע��δ��ѧ���ɼ�ʱ����������ѧ���ɼ����������ѧ��Ŷ\n");
	int num = 0;
	while (true)
	{
		printf("\n��������Ҫʵ�ֵĹ��ܣ�");
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
int Student_Search(int num1)//ͨ��ѧ��������ѧ����Ϣ
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (num1 == student[i].number)
		{
			return i;
		}
	}
	return -1;   //δ�ҵ����� -1 
}

void input() {
	char a;//����Y or N �����Ƿ�������һ��ѧ����Ϣ
	while (true) {
		printf("������ѧ����Ϣ��ѧ�� ���� �Ա� ���(m) ����(kg) �λ��� ��������or����������\n");
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
			if (strcmp(student[n].sex, "��") == 0) {
				mask_hw = cal_hw1(student[n].hw);
				mask_lung = cal_lung1(student[n].lung);
				mask_performance = cal_performance1(student[n].performance);
			}
			else if (strcmp(student[n].sex, "Ů") == 0) {
				mask_hw = cal_hw2(student[n].hw);
				mask_lung = cal_lung2(student[n].lung);
				mask_performance = cal_performance2(student[n].performance);
			}
			student[n].grade = 0.25 * mask_hw + 0.35 * mask_lung + 0.4 * mask_performance;

		}
		else {
			printf("֮ǰ�������ѧ�ţ�����������\n");
			n--;
		}
		n++;
		getchar();
		printf("�Ƿ������y/n��\n");
		a = getchar();
		if (a == 'n')
		{
			break;
		}
		
	}
}

//��������ָ��
//��
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
//Ů
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

//����λ�������
//��
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
//Ů
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

//��������/����
//��
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
//Ů
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

//����ѧ���ɼ�
void lookup() {
	int number1;
	printf("\n������Ҫ����ѧ����ѧ�ţ�");
	scanf("%d", &number1);
	int i;
	for (i = 0; i < 3; i++) {
		if (number1 == student[i].number) {
			if (student[i].grade >= 95 && student[i].grade <= 100) {
				printf("��ѧ��������%s�� �Ա�%s�� ��ߣ�%.2lf(m)�� ���أ�%.0lf(kg)�� ����ָ����%.2lf,  �λ�����%d�� ��������or����������%d�� �ܳɼ���%.2lf(���㣩\n",
					student[i].name, student[i].sex, student[i].height, student[i].weight, student[i].hw, student[i].lung, student[i].performance, student[i].grade);
			}else if (student[i].grade >= 80 && student[i].grade < 95) {
				printf("��ѧ��������%s�� �Ա�%s�� ��ߣ�%.2lf(m)�� ���أ�%.0lf(kg)�� ����ָ����%.2lf,  �λ�����%d�� ��������or����������%d�� �ܳɼ���%.2lf(���ã�\n",
					student[i].name, student[i].sex, student[i].height, student[i].weight, student[i].hw, student[i].lung, student[i].performance, student[i].grade);
			}else if (student[i].grade >= 60 && student[i].grade < 80) {
				printf("��ѧ��������%s�� �Ա�%s�� ��ߣ�%.2lf(m)�� ���أ�%.0lf(kg)�� ����ָ����%.2lf,  �λ�����%d�� ��������or����������%d�� �ܳɼ���%.2lf(����\n",
					student[i].name, student[i].sex, student[i].height, student[i].weight, student[i].hw, student[i].lung, student[i].performance, student[i].grade);
			}else if (student[i].grade >= 0 && student[i].grade < 60) {
				printf("��ѧ��������%s�� �Ա�%s�� ��ߣ�%.2lf(m)�� ���أ�%.0lf(kg)�� ����ָ����%.2lf,  �λ�����%d�� ��������or����������%d�� �ܳɼ���%.2lf(������\n",
					student[i].name, student[i].sex, student[i].height, student[i].weight, student[i].hw, student[i].lung, student[i].performance, student[i].grade);
			}
		}
	}
}

//�޸�ѧ���ɼ�
void modify() {
	char a;
	while (true) {
		int id = 0;
		printf("\n��������Ҫ�޸�ѧ�ţ�");
		scanf("%d", &id);
		
		int temp = Student_Search(id);
		if (Student_Search(id) == -1) {
			printf("�Ҳ�����ѧ��");
		}
		else {
			printf("��������Ҫ�޸ĵ�ѧ����Ϣ������ �Ա� ���(m) ����(kg) �λ��� ��������or����������:\n");
			scanf("%s", &student[temp].name);
			scanf("%s", &student[temp].sex);
			scanf("%lf", &student[temp].height);
			scanf("%lf", &student[temp].weight);
			scanf("%d", &student[temp].lung);
			scanf("%d", &student[temp].performance);
			student[temp].hw = student[temp].weight / (student[temp].height * student[temp].height);

			int mask_hw = 0, mask_lung = 0, mask_performance = 0;
			if (strcmp(student[temp].sex, "��") == 0) {
				mask_hw = cal_hw1(student[temp].hw);
				mask_lung = cal_lung1(student[temp].lung);
				mask_performance = cal_performance1(student[temp].performance);
			}
			else if (strcmp(student[temp].sex, "Ů") == 0) {
				mask_hw = cal_hw2(student[temp].hw);
				mask_lung = cal_lung2(student[temp].lung);
				mask_performance = cal_performance2(student[temp].performance);
			}
			student[temp].grade = 0.25 * mask_hw + 0.35 * mask_lung + 0.4 * mask_performance;

		}
		getchar();
		printf("�Ƿ������y/n��\n");
		a = getchar();
		if (a == 'n')
		{
			break;
		}
	}
}

//ɾ��ѧ���ɼ�
void del() {
	int i = 0;
	int number = 0;
	printf("������Ҫɾ��ѧ����ѧ�ţ�");
	scanf("%d", &number);
	int j = Student_Search(number);
	if (j == -1) {
		printf("δ��������ѧ��ѧ��");
	}
	else {
		for (i = j; i < n - 1; i++) {
			student[i] = student[i + 1];
		}
		n--;
		printf("ɾ���ɹ�");
	}
	

}

//ͳ��ѧ���ɼ�
void count() {
	double avg = 0;//ƽ����
	double sum = 0;//�ܷ�
	int max = 0;//���ֵ
	int min = 0;//��Сֵ
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
	
	printf("��߳ɼ�Ϊ��%lf����ѧ��Ϊ��%d������Ϊ��%s\n", student[max].grade, student[max].number, student[max].name);
	printf("��ͳɼ�Ϊ��%lf����ѧ��Ϊ��%d������Ϊ��%s\n", student[min].grade, student[min].number, student[min].name);
	printf("ƽ����Ϊ��%lf", avg);
}
//���ѧ���ɼ�
void browse() {
	int i = 0;
	printf("ѧ��     ����   �Ա� ��ߣ�m�� ���أ�kg�� �λ���  ��������or��������  �ɼ�\n");
	for (i = 0; i < n; i++) {
		printf("%8d %6s %2s   %3.2lf     %3.0lf      %4d    %3d    %lf\n", student[i].number, student[i].name, student[i].sex, student[i].height, student[i].weight, student[i].lung, student[i].performance, student[i].grade);
	}
}