/*
1017 Queueing at Bank (25)（25 point(s)）

Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.

Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=10000) - the total number of customers, and K (<=100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.

Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.

Output Specification:
For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.

Sample Input:
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10

Sample Output:
8.2

题目大意：
有家银行，有k个服务窗口，每个窗口只能坐1个人，其他人要在黄线外等候。今天一共来了n个人，给出他们每个人的到达时间以及所需服务时间。银行早上8点开门，晚上17点关门，如果是8点前到的，要在这里等候开门，如果是17点之后到的（17:00:00到可以，17:00:01到或者再晚到就不可以了）就不被受理了。而且每个人最多只被服务60分钟，求所有客户的平均等待时间。

分析：
1、和PAT甲级1014题一样，我们用一个now变量来记录此时此刻的时间，所做的就是不断的将这个时间向前推进；
2、时间向前推进中会发生几种情况：
 (1) 有人服务时间到了，还有人在黄线外等候。那么就要把此人移除，换下一个人进来。这种情况要找出在服务窗口的所有客户，哪个还剩的所需服务时间最短，谁就先服务好；
 (2) 在服务过程中，有人抵达了银行，那么要维护他的等待时间；
 (3) 有窗口已空闲，但是下一个客户还没有抵达银行，这种情况下，我们可以确定这个窗口一定会被最近到达的客户占用，尽管他还没到。那么我们可以模拟此时客户已经抵达，把此时此刻到他抵达银行的时间算在他的所需服务时间里。因为有窗口空闲，他一来就接受服务，是不用等待的。只需要让他结束服务时间与现实保持一致就可以了。
3、客户是先来后到服务的，所以我们可以按客户的到达时间，给客户排个序，这样就可以依次服务了；
4、如果超过60分钟就不再对其进行服务，那么我们可以那些所需服务时间超过60分钟客户的服务时间改为60分。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 @arrive：抵达时间
 @process：需要服务时间
 @wait：已等待时间
 */
struct customer {
    int arrive;
    int process;
    int wait;
};

// 按先来后到顺序排列函数
bool cmp (customer a, customer b) {
    return a.arrive < b.arrive;
}

int main () {
    freopen("input.txt", "r", stdin);
    
    /*
     @n：客户人数
     @k：窗口数
     @now：现在时间
     @p：目前处于黄线外，但下一个就要被服务的人
     */
    int n, k, now = 8 * 60 * 60, p = 0;
    float ave = 0;
    cin >> n >> k;
    vector<customer> customers;
    vector<customer *> windows(k);
    
    for (int i = 0; i < n; i++) {
        int hour, minute, second, arrive_time, processing_time;
        scanf("%d:%d:%d %d", &hour, &minute, &second, &processing_time);
        arrive_time = hour * 60 * 60 + minute * 60 + second;
        // 抵达时间超过17:00就不服务
        if (arrive_time > 17 * 60 * 60) continue;
        customer c;
        c.arrive = arrive_time;
        c.process = (processing_time > 60) ? 60 * 60 : processing_time * 60;
        c.wait = 0;
        customers.push_back(c);
    }
    
    // 按先来后到顺序排列
    sort(customers.begin(), customers.end(), cmp);
    
    // 如果有客户8:00前就到了，那么算上他们等到8:00的等待时间
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].arrive < 8 * 60 * 60)
            customers[i].wait = 8 * 60 * 60 - customers[i].arrive;
    }
    
    // 8:00开门，每个窗口送上一个客户
    for (int i = 0; i < k && p < customers.size(); i++) {
        windows[i] = &customers[p];
        // 这边如果此客户到达时间晚于当前时刻，而此窗口目前空闲，那么也把此客户送上窗口，让他的所需服务时间再加上等到他到达的时间
        if (customers[p].arrive > now)
            customers[p].process += customers[p].arrive - now;
        p++;
    }
    
    /*
    @min_time：所有窗口中，剩余所需服务时间中最短的
    @min_window：所有窗口中，剩余所需服务时间中最短的窗口号
    @forward：本次循环中，可以向前推进而不发生任何状态改变的时间
    */
    int min_time, min_window, forward;
    
    while (p < customers.size()) {
        min_time = windows[0]->process;
        min_window = 0;
        forward = 0;
        // 选出需求服务时间最短的客户
        for (int i = 1; i < k; i++) {
            if (windows[i]->process < min_time) {
                min_time = windows[i]->process;
                min_window = i;
            }
        }
        
        // 时间前进
        forward = min_time;
        now += forward;
        
        // 所有窗口的客户所需服务时间缩短
        for (int i = 0; i < k; i++) {
            windows[i]->process -= forward;
        }
        
        // 所有黄线外客户，如果他们到了等待时间加长
        for (int i = p; i < customers.size() && customers[i].arrive < now; i++) {
            /*
              如果此客户在本次循环前就已经到达，那么他的等待时间只需要加上forward就可以了
              如果此客户在本次循环中到达，那么他的等待时间是现在时间减去他的到达时间
            */
            customers[i].wait += (customers[i].arrive < (now - forward)) ? forward : now - customers[i].arrive;
        }
        
        // 将服务好的客户换下，上新客户
        windows[min_window] = &customers[p];
        // 同样，如果下一个客户到达时间比现在时间还晚，那么将他的到达时间与现在时间之差也算在他的需求服务时间之内
        if (customers[p].arrive > now)
            customers[p].process += customers[p].arrive - now;
        p++;
    }
    
    float sum = 0;
    for (int i = 0; i < customers.size(); i++) {
        sum += customers[i].wait;
    }
    
    ave = (customers.size() > 0) ? (sum / customers.size()) / 60.0 : 0.0;
    printf("%.1f\n", ave);
    return 0;
}
