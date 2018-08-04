/*
1016 Phone Bills (25)（25 point(s)）
A long-distance telephone company charges its customers by the following rules:
Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.
The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.
The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".
For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

Output Specification:
For each test case, you must print a phone bill for each customer.
Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line

Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80

题目大意：
说啊，有这么一个长途电话公司。他们的收费策略是不同的时间段不同的价钱，现在给你一批客户的通话记录，其中包含他们打电话的时间，挂电话的时间，但是其中有些无效信息，需要自己筛选。要你把他们这个月的电话账单打出来。

分析：
这其实是一道排序题，因为不管是题目要求的姓名按字典序排序，还是通话记录按时间排序，还是筛选无效信息，只要排个序都可以解决的。

PS. (我很生气，相当生气！！！) 这题有个错误！
题目交代了：It is guaranteed that at least one call is well paired in the input. 
可是case2和case3里面有客户没有有效的通话记录，这样要求不输出这些客户的姓名，总花费，什么都不输出。
因为这个问题我耽误了一个下午找bug！
气）（╯‵□′）╯︵┴─┴
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int toll[25];

// 通话记录结构体
struct record {
    string name;
    int month, day, hour, minute, time;
    string status;
};

// 客户结构体
struct customer {
    string name;
    vector<record> records;
};

// 将姓名按字典序排列
bool cmp_name (customer a, customer b) {return a.name < b.name;}
// 将通话记录按时间顺序排列
bool cmp_time (record a, record b) {return a.time < b.time;}

// 如果从01:00:00:00打电话到此记录的时间，那么花多少钱
float billFromZero(record a) {
    /*
     分为三部分计费
     1、01:00:00:00 - 01:dd:00:00 天数
     2、01:dd:00:00 - 01:dd:hh:00 小时数
     3、01:dd:hh:00 - 01:dd:hh:mm 分钟数
     */
    float total = 0;

    // 考虑天数，经过这么多天要花多少钱
    total += toll[24] * a.day;
    
    // 考虑小时数，这一天内这么多小时要多少钱
    for (int i = 0; i < a.hour; i++)
        total += toll[i] * 60;
    
    // 考虑分钟数，这些分钟数要花多少钱
    total += toll[a.hour] * a.minute;
    
    return total / 100.0;
}

// 求一个电话花了多少钱，用作差法
float get_amount (record a, record b) {return billFromZero(b) - billFromZero(a);}

int main () {
    
    // 记录个数
    int n;
    // 客户集合类
    vector<customer> customers;
    
    // 输入每小时的话费(cent/min)，toll[24]表示如果打一天电话花多少钱
    for (int i = 0; i < 24; i++) {
        scanf("%d", &toll[i]);
        toll[24] += toll[i] * 60;
    }
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        record r;
        cin >> r.name;
        scanf("%d:%d:%d:%d", &r.month, &r.day, &r.hour, &r.minute);
        r.time = r.day * 24 * 60 + r.hour * 60 + r.minute;
        cin >> r.status;
        
        // 如果此用户已经被记录过了，那么就直接在他后面添加此通话记录
        int j;
        for (j = 0; j < customers.size(); j++) {
            if (customers[j].name.compare(r.name) == 0) {
                customers[j].records.push_back(r);
                break;
            }
        }
        
        // 如果此用户还没有被记录过，那么添加此用户，并在他后面加通话记录
        if (j == customers.size()) {
            customer c;
            c.name = r.name;
            c.records.push_back(r);
            customers.push_back(c);
        }
    }
    
    // 将客户按姓名字典序排序
    sort(customers.begin(), customers.end(), cmp_name);
    for (int i = 0; i < customers.size(); i++) {
        // 将每个客户的通话记录按时间排序
        sort(customers[i].records.begin(), customers[i].records.end(), cmp_time);
    } 

    // 这里的flag判别去掉就是题目本意应该的答案，可是为了通过case2和case3，我加上了flag判别，此代码可以全部AC
    // 遍历每个客户
    for (int i = 0; i < customers.size(); i++) {
        int flag = 0;
        float total_amount = 0;
        // 遍历他的通话记录
        for (int j = 0; j < customers[i].records.size() - 1; j++) {
            // 如果这条通话记录状态是"on-line"，而下一条通话记录的状态是"off-line"，那么就认为这是一对有效的通话记录
            if (customers[i].records[j].status == "on-line" &&
                customers[i].records[j + 1].status == "off-line") {
                if (flag == 0) {
                    cout << customers[i].name;
                    printf(" %02d\n", customers[i].records[0].month);
                    flag = 1;
                }
                // 算出他的此次通话的消费
                float this_amount = get_amount(customers[i].records[j], customers[i].records[j + 1]);
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                       customers[i].records[j].day,
                       customers[i].records[j].hour,
                       customers[i].records[j].minute,
                       customers[i].records[j + 1].day,
                       customers[i].records[j + 1].hour,
                       customers[i].records[j + 1].minute,
                       customers[i].records[j + 1].time - customers[i].records[j].time,
                       this_amount);
                // 加入到总费用中
                total_amount += this_amount;
            }
        }
        if (flag == 1)
            printf("Total amount: $%.2f\n", total_amount);
    }
    return 0;
}

