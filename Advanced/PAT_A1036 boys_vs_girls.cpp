/*
1036. Boys vs Girls (25)
时间限制：400ms  内存限制：64MB  代码长度限制：16KB

Description:
This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

Output Specification:
For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference grade~F~-grade~M~. If one such kind of student is missing, output "Absent" in the corresponding line, and output "NA" in the third line instead.

Sample Input 1:
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95

Sample Output 1:
Mary EE990830
Joe Math990112
6

Sample Input 2:
1
Jean M AA980920 60

Sample Output 2:
Absent
Jean AA980920
NA
 */



#include <cstdio>

struct student {
	char name[15]; // 姓名 
	char gender; // 性别，M or F 
	char ID[15]; // 学号 
	int grade; // 成绩 
};

int main()
{
	student temp, lowest, highest; // 临时，最低成绩学生，最高成绩学生 
	// 初始化最低成绩学生成绩为101，性别为X，最高成绩学生成绩为-1，性别为X 
	lowest.grade = 101;
	highest.grade = -1;
	lowest.gender = highest.gender = 'X';
	
	int N;
	scanf("%d", &N);
	while (N--) {
		// 输入学生姓名、性别、学号、成绩 
		scanf("%s %c %s %d", temp.name, &temp.gender, temp.ID, &temp.grade);
		// 比较得出男生中的最低分 
		if (temp.gender == 'M' && temp.grade < lowest.grade) lowest = temp;
		// 比较得出女生中的最高分 
		if (temp.gender == 'F' && temp.grade > highest.grade) highest = temp;
	}
	
	// 女生不存在 
	if (highest.gender == 'X') printf("Absent\n");
	else printf("%s %s\n", highest.name, highest.ID);
	// 男生不存在 
	if (lowest.gender == 'X') printf("Absent\n");
	else printf("%s %s\n", lowest.name, lowest.ID);
	// 男生不存在或者女生不存在 
	if (lowest.gender == 'X' || highest.gender == 'X') printf("NA\n");
	else printf("%d\n", highest.grade - lowest.grade); // 成绩之差 
	return 0;
}
