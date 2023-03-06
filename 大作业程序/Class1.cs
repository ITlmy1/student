# include <stdio.h>
# include <string>

typedef struct student
{
	int number;
	char name[20];
	char sex;
	double height;
	double weight;
	int lung;
	int performance;//引体向上or仰卧起坐
}
stu;
int main()
{
	stu student[3];
	for (int i = 0; i < 3; i++)
	{
		printf("请输入第%d个学生信息（学号 姓名 性别 身高 体重 肺活量 引体向上or仰卧起坐）", i + 1);
		scanf("%d%s%c%lf%lf%d%d", &student[i].number, &student[i].name, &student[i].sex, &student[i].height,
			&student[i].weight, &student[i].lung, &student[i].performance);

	}



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
	printf("请输入想要实现的功能：");
	int n = 0;
	scanf_s("%d", &n);
	switch (n)
	{
		case 0: return 0; break;
		case 1:
		default:
			break;
	}

}
