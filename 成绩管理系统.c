#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define max 100/*给定结构体数组的最大值*/
int size = 0;//全局变量




/*显示学生属性的信息*/
typedef struct studentInformation
{
 char student_name[20];/*学生的名字*/ 
 char student_class[20];
 int student_number;/*学生的学号*/ 
 float student_eng;
 float student_math;
 float student_C;
}information;

int main(void)//主函数
{
	//函数声明
	void add_student(information im[], int geshu);
	void ave_sort(information im[]);
	void aveGrade(information im[]);
	void check_oneStudent(information im[], int student_number);
	void check_student(information im[]);
	void del_studentinfor(information im[], int student_number);
	void ev_grade(information im[]);
	void evsub_ave(information im[]);
	void menu();
	void num_sort(information im[]);
	void rebuild(information im[]);
	void st_insert(information im[], int index);


	information student[max];
	int geshu;
	int value = -1;
	int student_id, index;
	char user[] = "admin\0";
	char key[] = "key\0";
	char user2[10], key2[10];
	printf("请输入用户名：\n");
	scanf("%s", &user2);
	printf("请输入密码：\n");
	scanf("%s", &key2);
	if (strcmp(user, user2) != 0 || strcmp(key, key2) != 0)
	{
		printf("用户名或密码错误！\n");
		return;
	}
	else
	{
		while (value != 0)//按"0"退出操作 
		{
			menu();
			printf("请选择所要执行的操作：\n");
			scanf("%d", &value);
			switch (value)//根据value的值来执行相应的操作 
			{
			case 1://1---学生输入
				printf("请输入你要录入学生信息的个数：");
				scanf("%d", &geshu);
				add_student(student, geshu);
				break;
			case 2://2---学生插入
				printf("请输入插入学生的位置：\n");
				scanf("%d", &index);
				st_insert(student, index);
				break;
			case 3://3---学生查询
				printf("请输入要查询的学生的学号：");
				scanf("%d", &student_id);
				check_oneStudent(student, student_id);
				break;
			case 4://4---学生删除
				printf("请输入要删除的学生的学号：");
				scanf("%d", &student_id);
				del_studentinfor(student, student_id);
				break;
			case 5://5---学生输出
				check_student(student);
				break;
			case 6://6---计算每名学生的平均分并输出
				aveGrade(student);
				break;
			case 7://7---计算每科的平均分并输出 
				ev_grade(student);
				break;
			case 8://8---对学生的平均分排序
				ave_sort(student);
				break;
			case 9://9---统计每门课程的及格率并输出
				evsub_ave(student);
				break;
			case 10://10---输出各科的补考名单（包括学号、姓名、成绩）
				rebuild(student);
				break;
			case 11://11---对学生按学号排序 
				num_sort(student);
				break;
			case 0://0---退出
				printf("退出成功！");
				break;
			default:
				printf("输入信息错误！！");
			} /*end of switch*/
		}/*end of while*/
	}
	return 0;
}

void menu()
{
 printf("\n");
 printf("**********************好好学习*************************\n"); 
 printf("            武汉传媒学院学生成绩管理系统\n"); 
 printf("**********************天天向上*************************\n"); 
 printf("制作者：传媒技术学院软件B1802-胡涛 王龙圳 阮思文 乔梦婕\n");
 printf("*******************************************************\n");
 printf("  1---学生输入  \n");
 printf("  2---学生插入  \n");
 printf("  3---学生查询  \n");
 printf("　4---学生删除  \n");
 printf("  5---学生输出  \n");
 printf("  6---计算每名学生的平均分并输出  \n");
 printf("  7---计算每科的平均分并输出  \n");
 printf("  8---对学生的平均分排序  \n");
 printf("  9---统计每门课程的及格率并输出  \n");
 printf("  10---输出各科的补考名单（包括学号、姓名、成绩）  \n");
 printf("  11---对学生按学号排序  \n"); 
 printf("  0---退出  \n");
 printf("*******************************************************\n");
}

//1---学生输入
void add_student(information im[], int geshu)
{
 int i;
 int count = size + geshu;
 
 for(i = size; i < count; i++)
 {
 printf("请录入学生的名字：\n"); 
 scanf("%s",im[i].student_name);

 printf("请录入学生的学号：\n");
 scanf("%d",&im[i].student_number);
 
 printf("请录入学生的班级：\n"); 
 scanf("%s",im[i].student_class);
 
 printf("请录入学生的英语成绩：\n"); 
 scanf("%f",&im[i].student_eng);
 
 printf("请录入学生的数学成绩：\n"); 
 scanf("%f",&im[i].student_math);
 
 printf("请录入学生的C语言成绩：\n"); 
 scanf("%f",&im[i].student_C);
 
 size++;
 }/*end of for*/ 
}

//学生插入(按位置插入)
void st_insert(information im[],int index)
{ 
 int i;
 if(index < 1 || index > size + 1){
 printf("错误!\n");
 return;
 }
 for(i = size; i > index-1 ; i--)
 {
 im[i] = im[i - 1];
 }
 printf("请录入插入学生的名字：\n"); 
 scanf("%s",im[i].student_name);

 printf("请录入插入学生的学号：\n");
 scanf("%d",&im[i].student_number);
 
 printf("请录入插入学生的班级：\n"); 
 scanf("%s",im[i].student_class);
 
 printf("请录入插入学生的英语成绩：\n"); 
 scanf("%f",&im[i].student_eng);
 
 printf("请录入插入学生的数学成绩：\n"); 
 scanf("%f",&im[i].student_math);
 
 printf("请录入插入学生的C语言成绩：\n"); 
 scanf("%f",&im[i].student_C);
 size += 1; 
 printf("插入成功!\n");
}

//3---学生查询
void check_oneStudent(information im[], int student_number)
{
 int i,j;
 
 /*是实现学生信息的查询*/
 for(i = 0; i < size; i++)
 {
 if(im[i].student_number == student_number)
 {
 printf("名字 = %s\t学号 = %d\t班级 = %s\t英语成绩 = %0.2f\t数学成绩 = %0.2f\tC语言成绩 = %0.2f\n\n",
 im[i].student_name,im[i].student_number,im[i].student_class,im[i].student_eng,im[i].student_math,im[i].student_C);
 return ;
 }/*end of if*/
 }/*end of for*/ 
 
 printf("没有该学生的信息！\n");

}

//4---学生删除
void del_studentinfor(information im[],int student_number)
{
 int i,j;
 
 /*找到给定的编号，并删除对应编号的信息*/
 for(i = 0; i < size; i++)
 {
 /*通过比较找到对应编号，然后删除*/ 
 if(im[i].student_number == student_number)
 {
 /*通过移动数组元素来删除信息*/ 
 for(j = i; j < size - 1; j++)
 {
 im[j] = im[j+1];
 } /*end of for*/ 
 size--;
 printf("删除成功!\n");
 return ;
 }/*end of if*/ 
 }/*end of for*/ 
 
 printf("没有该学生\n");
}

//5---学生输出
void check_student(information im[])
{
 int i;
 if(size == 0){
 printf("没有学生信息！");
 }
 for(i = 0; i < size; i++)
 {
 printf("名字 = %s\t学号 = %d\t班级 = %s\t\n英语成绩 = %0.2f\t数学成绩 = %0.2f\tC语言成绩 = %0.2f\n\n",
 im[i].student_name,im[i].student_number,im[i].student_class,im[i].student_eng,im[i].student_math,im[i].student_C);
 }/*end of for*/ 
}

// 计算每名学生的平均分并输出
void aveGrade(information im[])
{
 int i;
 float ave = 0;
 
 for(i = 0;i < size;i++)
 {
 ave = (im[i].student_eng + im[i].student_math + im[i].student_C)/3;
 printf("学号%d姓名%s的平均成绩 = %0.2f\n",im[i].student_number,im[i].student_name,ave);
 }
}

//每科的平均分并输出
void ev_grade(information im[])
{
 int i,j = 0;
 float sum1 = 0.0,sum2 = 0.0,sum3 = 0.0;
 
 for(i = 0;i < size;i++)
 {
 sum1 = sum1 + im[i].student_eng; 
 sum2 = sum2 + im[i].student_math; 
 sum3 = sum3 + im[i].student_C;
 j++;
 }
 printf("英语平均成绩: %0.2f\n",sum1 / j);
 printf("数学平均成绩: %0.2f\n",sum2 / j);
 printf("C语言平均成绩: %0.2f\n",sum3 / j); 
}

//统计每门课程的及格率并输出
void evsub_ave(information im[])
{
 int i,j = 0,count1 = 0,count2 = 0,count3 = 0;
 
 for(i = 0;i < size;i++)
 {
 if(im[i].student_eng >= 60)
 {
 count1++;
 }
 if(im[i].student_math >= 60)
 {
 count2++;
 }
 if(im[i].student_C >= 60)
 {
 count3++;
 }
 j++;
 }
 printf("英语及格率为：%0.2f\n",count1 * 100.0 / j);
 printf("数学及格率为：%0.2f\n",count2 * 100.0 / j);
 printf("C语言及格率为：%0.2f\n",count3 * 100.0 / j);
}

//输出各科的补考名单
void rebuild(information im[])
{
 int i,flag = 1;
 
 printf("英语补考名单：\n");
 for(i = 0;i < size;i++)
 {
 if(im[i].student_eng < 60)
 {
 printf("姓名：%s\t",im[i].student_name);
 printf("学号：%d\t",im[i].student_number);
 printf("英语成绩：%0.2f\n",im[i].student_eng);
 flag = 0;
 }
 }
 if(flag == 1){
 printf("没有补考的！\n");
 }else{
 flag = 1;
 }
 printf("数学补考名单：\n");
 for(i = 0;i < size;i++)
 {
 if(im[i].student_math < 60)
 {
 printf("姓名：%s\t",im[i].student_name);
 printf("学号：%d\t",im[i].student_number);
 printf("数学成绩：%0.2f\n",im[i].student_math);
 flag = 0;
 }
 }
 if(flag == 1){
 printf("没有补考的！\n");
 }else{
 flag = 1;
 }
 printf("C语言补考名单：\n");
 for(i = 0;i < size;i++)
 {
 if(im[i].student_C < 60)
 {
 printf("姓名：%s\t",im[i].student_name);
 printf("学号：%d\t",im[i].student_number);
 printf("C语言成绩：%0.2f\n",im[i].student_C);
 flag = 0;
 } 
 }
 if(flag == 1){
 printf("没有补考的！\n");
 }
}

//对学生按学号排序(由小到大)
void num_sort(information im[])
{
 int i,j;
 information stu_temp;
 
 for(i = 0;i < size;i++)
 {
 for(j = 0; j<size-1-i; j++)
 {
 if(im[j].student_number > im[j+1].student_number)
 {
 stu_temp = im[j];
 im[j] = im[j+1];
 im[j+1] = stu_temp;
 }
 }
 }
 printf("排序后的结果：\n");
 for(i = 0;i < size;i++)
 {
 printf("%d\t",im[i].student_number);
 }
}

//对学生的平均分排序(由大到小)
void ave_sort(information im[])
{
 int i,j;
 float ave_temp;
 float *ave = (float*)malloc(size * sizeof(float));//这个地方改成了用动态内存开辟
 information stu_temp;
 
 for(i = 0;i < size;i++)
 {
 ave[i] = (im[i].student_eng + im[i].student_math + im[i].student_C)/3;
 }
 for(i = 0;i < size-1;i++)
 {
 for(j = 0; j<size-1-i; j++)
 {
 if(ave[j] < ave[j+1])
 {
 stu_temp = im[j];
 im[j] = im[j+1];
 im[j+1] = stu_temp;
 
 ave_temp = ave[j];
 ave[j] = ave[j+1];
 ave[j+1] = ave_temp;
 }
 }
 }
 printf("排序后的结果：\n");
 for(i = 0;i < size;i++)
 {
 printf("%0.2f\t",ave[i]);
 }
}



