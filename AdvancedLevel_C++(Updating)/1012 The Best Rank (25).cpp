/*
1012 The Best Rank (25)（25 point(s)）

To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input
Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output
For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output "N/A".

Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999

Sample Output
1 C
1 M
1 E
1 A
3 A
N/A

思路：
 1、创建好学生结构体数组，将所有学生的信息（id，三门课程分数以及平均分）存储在数组里；
 2、每门课按照分数从高到低来排序，并且将排序结果存储在对应的rank数组里；
 3、创建好查询结果的结构体数组，用以存储查询结果；
 4、依次输入m个需要查询的学号，如果查询到此学号，就修改查询结果数组中的信息；
 5、只需要将查询结果数组的内容输出就可以了，如果best_r不是0，就代表找到了这个学生，是0就是没找到。

【注意】：
 1、在排名时，如果有两个学生分数一样，那么排名也要一样，然后下一个排名是他本该的排名
 举个栗子🌰：如果分数是 100 100 90 80，那么排名是 1 1 3 4。
 2、存储学生信息数组里的score数组可以按ACME顺序存储分数，最后依次遍历简化逻辑程序。
*/
#include <iostream>
#include <algorithm>
using namespace std;

/* 学生信息数组，第i个元素代表输入的第i个学生的信息
 @id：学生id
 @best_r：此学生最好一门科目的排名
 @best_c：此学生最好一门科目
 @score：四门课成绩
 @rank：对应的四门课的排名
*/
struct stu {
	int id, best_r = 5, best_c;
	int score[4], rank[4];
}s[10000];

// 课程编号
int flag;
bool cmp (stu s1, stu s2) {return s1.score[flag] > s2.score[flag];}

/* 查询结果数组，第i个元素代表第i次查询的结果
 @best_r：所查询的这个学生最好一门科目的排名。没查到就是默认值0
 @best_c：所查询的这个学生最好一门科目，没查到就是默认值-1
*/
struct check_r {
	int best_r = 0, best_c = -1;
}c[10000];

int main () {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i].id >> s[i].score[1] >> s[i].score[2] >> s[i].score[3];
		s[i].score[0] = (s[i].score[1] + s[i].score[2] + s[i].score[3]) / 3.0 + 0.5;
	}
	
	for (flag = 0; flag < 4; flag++) {
		sort(s, s + n, cmp);
		s[0].rank[flag] = 1;
		
		for (int i = 1; i < n; i++) {
			if (s[i].score[flag] == s[i - 1].score[flag]) 
				s[i].rank[flag] = s[i - 1].rank[flag];
			else 
				s[i].rank[flag] = i + 1;
		}
		
		for (int i = 0; i < n; i++) {
			if (s[i].best_r > s[i].rank[flag]) {
				s[i].best_r = s[i].rank[flag];
				s[i].best_c = flag;
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		int check_id;
		cin >> check_id;
		for (int j = 0; j < n; j++) {
			if (s[j].id == check_id) {
				c[i].best_r = s[j].best_r;
				c[i].best_c = s[j].best_c;
				break;
			}
		}
	}
	
	char clas[] = {'A', 'C', 'M', 'E'};
	
	for (int i = 0; i < m; i++) {
		if (c[i].best_r != 0) {
			cout << c[i].best_r << ' ' << clas[c[i].best_c] << endl;
		} else {
			cout << "N/A" << endl;
		}
	}
	return 0;
} 