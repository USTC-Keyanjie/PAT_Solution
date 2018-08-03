/*
1014 Waiting in Line (30)（30 point(s)）

Suppose a bank has N windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. The rules for the customers to wait in line are:

The space inside the yellow line in front of each window is enough to contain a line with M customers. Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.
Each customer will choose the shortest line to wait in when crossing the yellow line. If there are two or more lines with the same length, the customer will always choose the window with the smallest number.
Customer[i] will take T[i] minutes to have his/her transaction processed.
The first N customers are assumed to be served at 8:00am.
Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.

For example, suppose that a bank has 2 windows and each window may have 2 customers waiting inside the yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, customer~1~ is served at window~1~ while customer~2~ is served at window~2~. Customer~3~ will wait in front of window~1~ and customer~4~ will wait in front of window~2~. Customer~5~ will wait behind the yellow line.

At 08:01, customer~1~ is done and customer~5~ enters the line in front of window~1~ since that line seems shorter now. Customer~2~ will leave at 08:02, customer~4~ at 08:06, customer~3~ at 08:07, and finally customer~5~ at 08:10.

Input
Each input file contains one test case. Each case starts with a line containing 4 positive integers: N (<=20, number of windows), M (<=10, the maximum capacity of each line inside the yellow line), K (<=1000, number of customers), and Q (<=1000, number of customer queries).

The next line contains K positive integers, which are the processing time of the K customers.

The last line contains Q positive integers, which represent the customers who are asking about the time they can have their transactions done. The customers are numbered from 1 to K.

Output
For each of the Q customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output "Sorry" instead.

Sample Input
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7

Sample Output
08:07
08:06
08:10
17:00
Sorry

题目大意：
一个银行有n个服务窗口，每个窗口前只允许排m个人，那这样总共可以排n*m个人，其他的人就在一边等候。一共有k个客户，客户都是有编号的，按顺序进队伍。客户永远选择人数最少的队伍，如果有两个队伍人数一样多，那么选择窗口号较小的队伍。银行8:00开门，17:00关门。如果在17:00前还没有还是服务，那么就不服务了。我们是知道每个客户需要服务多久的，现在有q个客户需要查询何时能结束自己的服务，输出他们结束服务的时间，如果不能被服务，就输出"Sorry"。

分析：
推动整个事件向前发展的一个变量——时间。我可以使用时间来作为整个程序推动器。随着时间推移，正在窗口接受服务的客户肯定有服务完成的，那么他就出去，将在一个客户加入此队伍中。如果此客户的开始时间在17:00之前，而结束时间已经到了或者超过17:00了，那么此窗口只服务此客户，直至他服务完成，排在他后面的客户就Sorry了。

数据结构：
银行排队肯定是使用队列这种数据结构比较好，我设立了20条队伍，模拟n(<=20)个窗口前的队伍，队列里装的是客户编号。还需要一个time数组来存储每个客户【还需】的服务时间，数组里第i个元素就代表了i号客户所需的服务时间。另外，我还设立的result数组，用以存储客户的结束服务时间。第i个元素代表第i个客户的结束服务时间，如果不能被服务，就存储-1；

思路：
1、先把客户依次按照规则装进队伍里，如果客户数k>n*m，那么剩下的客户就在外面等待；
2、now_time是现在时间，由于要保证必须在17:00前才可以提供服务，所以now_time<540才会进入循环。只要现在时间没到17:00就可以服务客户。找出所有窗口中要服务的客户时间最短的那个，对其进行服务，并且此客户服务完后，其余正在服务的客户所需时间应该相应减少，维护time数组。如果此客户服务完后已经17:00了或者超过17:00了，那么循环立即结束；
3、现在在每个队列首部的人都是17：00点结束的或者是17:00之后结束的客户，但是保证了他们都是17：00前开始接受服务的，所以要将现在时间加上他们还需服务时间，存储到result数组里面。队伍里的其余人员以及队伍外的等候人员全部保存-1，表示只能Say Sorry。

*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main () {
    /* 
     @n：窗口数
     @m：队伍长度
     @k：客户数
     @q：需要查询人数
     @p：p指向下一个需要进队伍的人，一开始指向第一位客户
     @now_time：现在时间（从8:00开始后的分钟数）
    */
    int n, m, k, q, p = 1, now_time = 0;
    cin >> n >> m >> k >> q;
    queue<int> windows[20];
    //@time数组：第i个元素表示i号客户【还需】服务时间
    vector<int> time(k + 1), result(k + 1);
    
    for (int i = 1; i <= k; i++) {
        scanf("%d", &time[i]);
    }
    
    /*
      此时银行刚刚开门，p用来往队伍中装人。
      p指向下一个需要进队伍的人。
    */
    for (int i = 0; p <= k && p <= n * m; i = (i + 1) % n, p++) {
        windows[i].push(p);
    }
    
    /*
      @min：所有将要被服务的客户中，所需服务时间的最短时间
      @temp_window：所需服务时间最短的客户所载窗口号
      @consumer_next：此客户的编号
    */
    int min, temp_window = 0, consumer_next = 0;
    // 如果现在时间还没到17:00就可以开始服务
    while (now_time < 540) {
        // 找一个最短可以服务掉的客户
        min = 99999;
        for (int i = 0; i < n; i++) {
            if (windows[i].empty())
                continue;
            
            if (time[windows[i].front()] < min) {
                consumer_next = windows[i].front();
                min = time[consumer_next];
                temp_window = i;
            }
        }
        
        //如果所有队伍都是空的，打破循环
        if (min == 99999) break;
        
        //服务好这个客户之后的时间
        now_time += min;
        
        //所有正在窗口接受服务的客户，所需时间相应的减少
        for (int i = 0; i < n; i++) {
            if (!windows[i].empty())
                time[windows[i].front()] -= min;
        }
        
        //如果现在时刻还没到17:00，那么就保存好这个客户的服务结束时间，并且将队伍外的客户加进这个队伍中
        if (now_time < 540) {
            result[consumer_next] = now_time;
            windows[temp_window].pop();
            if (p <= k) {
                windows[temp_window].push(p);
                p++;
            }
        }
    }
    
    // 如果现在到达或者超过17:00了，那么将窗口正在接受服务的客户服务号，并保存他们的结束时间
    for (int i = 0; i < n; i++) {
        if (!windows[i].empty()) {
            result[windows[i].front()] = now_time + time[windows[i].front()];
            windows[i].pop();
        }
    }
    
    // 还在队伍里的客户保存-1
    for (int i = 0; i < n; i++) {
        while (!windows[i].empty()) {
            result[windows[i].front()] = -1;
            windows[i].pop();
        }
    }
    
    // 队伍外的客户保存-1
    for (int i = p; i <= k; i++) {
        result[i] = -1;
    }
    
    // 输出结果
    for (int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        int time = result[temp];
        if (time != -1) {
            int hour = time / 60 + 8;
            int minute = time % 60;
            printf("%02d:%02d\n", hour, minute);
        } else {
            printf("Sorry\n");
        }
    }
    
    return 0;
}
