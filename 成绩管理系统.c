#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define max 100/*�����ṹ����������ֵ*/
int size = 0;//ȫ�ֱ���




/*��ʾѧ�����Ե���Ϣ*/
typedef struct studentInformation
{
 char student_name[20];/*ѧ��������*/ 
 char student_class[20];
 int student_number;/*ѧ����ѧ��*/ 
 float student_eng;
 float student_math;
 float student_C;
}information;

int main(void)//������
{
	//��������
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
	printf("�������û�����\n");
	scanf("%s", &user2);
	printf("���������룺\n");
	scanf("%s", &key2);
	if (strcmp(user, user2) != 0 || strcmp(key, key2) != 0)
	{
		printf("�û������������\n");
		return;
	}
	else
	{
		while (value != 0)//��"0"�˳����� 
		{
			menu();
			printf("��ѡ����Ҫִ�еĲ�����\n");
			scanf("%d", &value);
			switch (value)//����value��ֵ��ִ����Ӧ�Ĳ��� 
			{
			case 1://1---ѧ������
				printf("��������Ҫ¼��ѧ����Ϣ�ĸ�����");
				scanf("%d", &geshu);
				add_student(student, geshu);
				break;
			case 2://2---ѧ������
				printf("���������ѧ����λ�ã�\n");
				scanf("%d", &index);
				st_insert(student, index);
				break;
			case 3://3---ѧ����ѯ
				printf("������Ҫ��ѯ��ѧ����ѧ�ţ�");
				scanf("%d", &student_id);
				check_oneStudent(student, student_id);
				break;
			case 4://4---ѧ��ɾ��
				printf("������Ҫɾ����ѧ����ѧ�ţ�");
				scanf("%d", &student_id);
				del_studentinfor(student, student_id);
				break;
			case 5://5---ѧ�����
				check_student(student);
				break;
			case 6://6---����ÿ��ѧ����ƽ���ֲ����
				aveGrade(student);
				break;
			case 7://7---����ÿ�Ƶ�ƽ���ֲ���� 
				ev_grade(student);
				break;
			case 8://8---��ѧ����ƽ��������
				ave_sort(student);
				break;
			case 9://9---ͳ��ÿ�ſγ̵ļ����ʲ����
				evsub_ave(student);
				break;
			case 10://10---������ƵĲ�������������ѧ�š��������ɼ���
				rebuild(student);
				break;
			case 11://11---��ѧ����ѧ������ 
				num_sort(student);
				break;
			case 0://0---�˳�
				printf("�˳��ɹ���");
				break;
			default:
				printf("������Ϣ���󣡣�");
			} /*end of switch*/
		}/*end of while*/
	}
	return 0;
}

void menu()
{
 printf("\n");
 printf("**********************�ú�ѧϰ*************************\n"); 
 printf("            �人��ýѧԺѧ���ɼ�����ϵͳ\n"); 
 printf("**********************��������*************************\n"); 
 printf("�����ߣ���ý����ѧԺ���B1802-���� ������ ��˼�� �����\n");
 printf("*******************************************************\n");
 printf("  1---ѧ������  \n");
 printf("  2---ѧ������  \n");
 printf("  3---ѧ����ѯ  \n");
 printf("��4---ѧ��ɾ��  \n");
 printf("  5---ѧ�����  \n");
 printf("  6---����ÿ��ѧ����ƽ���ֲ����  \n");
 printf("  7---����ÿ�Ƶ�ƽ���ֲ����  \n");
 printf("  8---��ѧ����ƽ��������  \n");
 printf("  9---ͳ��ÿ�ſγ̵ļ����ʲ����  \n");
 printf("  10---������ƵĲ�������������ѧ�š��������ɼ���  \n");
 printf("  11---��ѧ����ѧ������  \n"); 
 printf("  0---�˳�  \n");
 printf("*******************************************************\n");
}

//1---ѧ������
void add_student(information im[], int geshu)
{
 int i;
 int count = size + geshu;
 
 for(i = size; i < count; i++)
 {
 printf("��¼��ѧ�������֣�\n"); 
 scanf("%s",im[i].student_name);

 printf("��¼��ѧ����ѧ�ţ�\n");
 scanf("%d",&im[i].student_number);
 
 printf("��¼��ѧ���İ༶��\n"); 
 scanf("%s",im[i].student_class);
 
 printf("��¼��ѧ����Ӣ��ɼ���\n"); 
 scanf("%f",&im[i].student_eng);
 
 printf("��¼��ѧ������ѧ�ɼ���\n"); 
 scanf("%f",&im[i].student_math);
 
 printf("��¼��ѧ����C���Գɼ���\n"); 
 scanf("%f",&im[i].student_C);
 
 size++;
 }/*end of for*/ 
}

//ѧ������(��λ�ò���)
void st_insert(information im[],int index)
{ 
 int i;
 if(index < 1 || index > size + 1){
 printf("����!\n");
 return;
 }
 for(i = size; i > index-1 ; i--)
 {
 im[i] = im[i - 1];
 }
 printf("��¼�����ѧ�������֣�\n"); 
 scanf("%s",im[i].student_name);

 printf("��¼�����ѧ����ѧ�ţ�\n");
 scanf("%d",&im[i].student_number);
 
 printf("��¼�����ѧ���İ༶��\n"); 
 scanf("%s",im[i].student_class);
 
 printf("��¼�����ѧ����Ӣ��ɼ���\n"); 
 scanf("%f",&im[i].student_eng);
 
 printf("��¼�����ѧ������ѧ�ɼ���\n"); 
 scanf("%f",&im[i].student_math);
 
 printf("��¼�����ѧ����C���Գɼ���\n"); 
 scanf("%f",&im[i].student_C);
 size += 1; 
 printf("����ɹ�!\n");
}

//3---ѧ����ѯ
void check_oneStudent(information im[], int student_number)
{
 int i,j;
 
 /*��ʵ��ѧ����Ϣ�Ĳ�ѯ*/
 for(i = 0; i < size; i++)
 {
 if(im[i].student_number == student_number)
 {
 printf("���� = %s\tѧ�� = %d\t�༶ = %s\tӢ��ɼ� = %0.2f\t��ѧ�ɼ� = %0.2f\tC���Գɼ� = %0.2f\n\n",
 im[i].student_name,im[i].student_number,im[i].student_class,im[i].student_eng,im[i].student_math,im[i].student_C);
 return ;
 }/*end of if*/
 }/*end of for*/ 
 
 printf("û�и�ѧ������Ϣ��\n");

}

//4---ѧ��ɾ��
void del_studentinfor(information im[],int student_number)
{
 int i,j;
 
 /*�ҵ������ı�ţ���ɾ����Ӧ��ŵ���Ϣ*/
 for(i = 0; i < size; i++)
 {
 /*ͨ���Ƚ��ҵ���Ӧ��ţ�Ȼ��ɾ��*/ 
 if(im[i].student_number == student_number)
 {
 /*ͨ���ƶ�����Ԫ����ɾ����Ϣ*/ 
 for(j = i; j < size - 1; j++)
 {
 im[j] = im[j+1];
 } /*end of for*/ 
 size--;
 printf("ɾ���ɹ�!\n");
 return ;
 }/*end of if*/ 
 }/*end of for*/ 
 
 printf("û�и�ѧ��\n");
}

//5---ѧ�����
void check_student(information im[])
{
 int i;
 if(size == 0){
 printf("û��ѧ����Ϣ��");
 }
 for(i = 0; i < size; i++)
 {
 printf("���� = %s\tѧ�� = %d\t�༶ = %s\t\nӢ��ɼ� = %0.2f\t��ѧ�ɼ� = %0.2f\tC���Գɼ� = %0.2f\n\n",
 im[i].student_name,im[i].student_number,im[i].student_class,im[i].student_eng,im[i].student_math,im[i].student_C);
 }/*end of for*/ 
}

// ����ÿ��ѧ����ƽ���ֲ����
void aveGrade(information im[])
{
 int i;
 float ave = 0;
 
 for(i = 0;i < size;i++)
 {
 ave = (im[i].student_eng + im[i].student_math + im[i].student_C)/3;
 printf("ѧ��%d����%s��ƽ���ɼ� = %0.2f\n",im[i].student_number,im[i].student_name,ave);
 }
}

//ÿ�Ƶ�ƽ���ֲ����
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
 printf("Ӣ��ƽ���ɼ�: %0.2f\n",sum1 / j);
 printf("��ѧƽ���ɼ�: %0.2f\n",sum2 / j);
 printf("C����ƽ���ɼ�: %0.2f\n",sum3 / j); 
}

//ͳ��ÿ�ſγ̵ļ����ʲ����
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
 printf("Ӣ�Ｐ����Ϊ��%0.2f\n",count1 * 100.0 / j);
 printf("��ѧ������Ϊ��%0.2f\n",count2 * 100.0 / j);
 printf("C���Լ�����Ϊ��%0.2f\n",count3 * 100.0 / j);
}

//������ƵĲ�������
void rebuild(information im[])
{
 int i,flag = 1;
 
 printf("Ӣ�ﲹ��������\n");
 for(i = 0;i < size;i++)
 {
 if(im[i].student_eng < 60)
 {
 printf("������%s\t",im[i].student_name);
 printf("ѧ�ţ�%d\t",im[i].student_number);
 printf("Ӣ��ɼ���%0.2f\n",im[i].student_eng);
 flag = 0;
 }
 }
 if(flag == 1){
 printf("û�в����ģ�\n");
 }else{
 flag = 1;
 }
 printf("��ѧ����������\n");
 for(i = 0;i < size;i++)
 {
 if(im[i].student_math < 60)
 {
 printf("������%s\t",im[i].student_name);
 printf("ѧ�ţ�%d\t",im[i].student_number);
 printf("��ѧ�ɼ���%0.2f\n",im[i].student_math);
 flag = 0;
 }
 }
 if(flag == 1){
 printf("û�в����ģ�\n");
 }else{
 flag = 1;
 }
 printf("C���Բ���������\n");
 for(i = 0;i < size;i++)
 {
 if(im[i].student_C < 60)
 {
 printf("������%s\t",im[i].student_name);
 printf("ѧ�ţ�%d\t",im[i].student_number);
 printf("C���Գɼ���%0.2f\n",im[i].student_C);
 flag = 0;
 } 
 }
 if(flag == 1){
 printf("û�в����ģ�\n");
 }
}

//��ѧ����ѧ������(��С����)
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
 printf("�����Ľ����\n");
 for(i = 0;i < size;i++)
 {
 printf("%d\t",im[i].student_number);
 }
}

//��ѧ����ƽ��������(�ɴ�С)
void ave_sort(information im[])
{
 int i,j;
 float ave_temp;
 float *ave = (float*)malloc(size * sizeof(float));//����ط��ĳ����ö�̬�ڴ濪��
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
 printf("�����Ľ����\n");
 for(i = 0;i < size;i++)
 {
 printf("%0.2f\t",ave[i]);
 }
}



