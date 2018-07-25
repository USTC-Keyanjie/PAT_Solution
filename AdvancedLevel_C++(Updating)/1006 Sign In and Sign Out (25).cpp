/*
1006 Sign In and Sign Out (25)（25 point(s)

At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:
Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:
ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.

Output Specification:
For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40

Sample Output:
SC3021234 CS301133

思路：
1、我建立了一个员工的结构体，并且将员工信息存储在vector<staff>里面；
2、员工的Sign_in_time与Sign_out_time我存储为一个数字，其十位与个位代表秒，千位与百位代表分，十万位与万位代表时。虽然时间是60进制，我这里是100进制，但是数值比较不会出现问题的；
3、比较各个员工的Sign_in_time与Sign_out_time，排序出结果。

Thought:
1. I created an employee structure and stored employee information in vector<staff>;
2. The employee's Sign_in_time and Sign_out_time are stored as a number, with ten and one digits representing seconds, thousands and hundred digits representing minutes, and 100,000 digits and 10,000 digits representing hours.
3. Compare the Sign_in_time and Sign_out_time of each employee and sort the results.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
@id: the id of staff 员工ID
@sit: Sign_in_time 员工进入时间
@sot: Sign_out_time 员工退出时间
*/
typedef struct staff{
    string id;
    int sit;
    int sot;
} staff;

bool cmp1(staff s1, staff s2) {return s1.sit < s2.sit;}
bool cmp2(staff s1, staff s2) {return s1.sot > s2.sot;}

int main() {
    int n;
    cin >> n;
    vector<staff> v(n);
    for (int i = 0; i < n; i++) {
        staff s;
        string str_sit;
        string str_sot;
        cin >> s.id >> str_sit >> str_sot;
        
        /*
        将输入的时间字符串去除冒号，转为相应的整形值
        Remove the colon from the input time string and convert it to the corresponding integer value.
        */
        str_sit.erase(2, 1);
        str_sit.erase(4, 1);
        str_sot.erase(2, 1);
        str_sot.erase(4, 1);
        s.sit = stoi(str_sit);
        s.sot = stoi(str_sot);
        v[i] = s;
    }
    
    sort(v.begin(), v.end(), cmp1);
    cout << v[0].id;
    
    sort(v.begin(), v.end(), cmp2);
    cout << ' ' << v[0].id << endl;
    
    return 0;
}
