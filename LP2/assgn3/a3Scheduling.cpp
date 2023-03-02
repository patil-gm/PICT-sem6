#include <iostream>
#include <iomanip>

using namespace std;

class Cpu_sched
{
private:
    int n, bt[20], at[20], wt[20], tat[20];
    float all_avg_wait[4], all_avg_turn[4];
    string algo[4] = {"FCFS", "SJF", "PRIO", "RDRB"};
    float awt, atat;

public:
    void get()
    {
        cout << "Enter number of processes\n";
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cout << "Enter arrival time for P" << i + 1 << endl;
            cin >> at[i];

            cout << "Enter burst time for P" << i + 1 << endl;
            cin >> bt[i];
        }
    }

    void fcfs()
    {
        int total_wait = 0;
        int total_turnaround = 0;
        awt = 0.0;
        atat = 0.0;

        wt[0] = 0;
        int total_burst = bt[0];
        for (int i = 1; i < n; ++i)
        {
            wt[i] = total_burst - at[i];
            total_burst += bt[i];
        }
        // cout << total_wait << endl;
        for (int i = 0; i < n; i++)
        {
            // cout << i << " " << wt[i] << endl;
            total_wait += wt[i];
        }
        cout << "total wait " << total_wait << " " << n << endl;
        awt = 0.0, atat = 0.0;
        awt = (float)total_wait / n;

        cout << "Average waiting time is (FCFS) : " << awt << endl;

     
        for (int i = 0; i < n; i++)
        {
            tat[i] = (wt[i] + bt[i]) - at[i];
        }
        for (int i = 0; i < n; i++)
        {
            total_turnaround += tat[i];
        }
        atat = (float)total_turnaround / n;
        cout << "Average turn around time is (FCFS) : " << atat << endl;
        all_avg_wait[0] = awt;
        all_avg_turn[0] = atat;
        
    }

    
    
    
    
    void sjf()
    {
        int complete = 0, curr_time = 0, min_time = 9999, shortest = 0, finish_time = 0;
        bool check = false;

        float total_wait = 0;
        float total_turnaround = 0;

        int rembt[n];

        for (int i = 0; i < n; i++)
        {
            rembt[i] = bt[i];
        }

        while (complete != n)
        {
            
            for (int i = 0; i < n; i++)
            {   //finding shortest job at perticular time
                if ((at[i] <= curr_time) && (rembt[i] < min_time) && rembt[i] > 0)
                {
                    min_time = rembt[i];
                    shortest = i;
                    // check = true;
                }
            }

            // if (check == false){ curr_time++; continue;}

            rembt[shortest]--;
            min_time = rembt[shortest];

            if (min_time == 0) min_time = 9999;


            if (rembt[shortest] == 0)
            {
                complete++;
                // check = false;

                finish_time = curr_time + 1;
                wt[shortest] = finish_time - bt[shortest] - at[shortest];

                if (wt[shortest] < 0)
                {
                    wt[shortest] = 0;
                }
            }
            
            curr_time++;
        }

while(0){
        awt = 0, atat = 0;
        for (int i = 0; i < n; i++)
        {
            total_wait = total_wait + wt[i];
        }
        awt = total_wait / n;
        cout << "Average Waiting Time:" << awt << endl;

        for (int i = 0; i < n; i++)
        {
            tat[i] = wt[i] + bt[i];
            total_turnaround += tat[i];
        }
        atat = total_turnaround / n;
        cout << "Average Turn Around Time:" << atat << endl;

        all_avg_wait[1] = awt;
        all_avg_turn[1] = atat;
}
       
    }

    void priority()
    {
        int pr[n], total_wait = 0, total_turnaround = 0;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter priority for process " << (i + 1) << ":";
            cin >> pr[i];
        }

        // sorting the priority list by bubble sort in descending order
        for (int i = 0; i < n; i++)
        {
            bool swapped = false;
            for (int j = 0; j < n - i ; j++)
            {
                if (pr[j] < pr[j + 1])
                {
                    swapped = true;
                    swap(pr[j],pr[j+1]);
                    swap(bt[j],bt[j+1]);
                    swap(at[j],at[j+1]);
                }
            }
            if (!swapped)break;
        }


        wt[0] = 0;
        int total_burst = bt[0];
        int ct = wt[0] + at[0] + bt[0];

        for (int i = 1; i < n; ++i)
        {
            wt[i] = ct - at[i];
            if(wt[i]<0)wt[i]=0;
            ct = at[i] + bt[i] + wt[i];
            total_burst += bt[i];
            total_wait += wt[i];
        }

        int o=1;
        while(o--){
        awt = 0, atat = 0;
        awt = (float)total_wait / n;
        cout << "Average Waiting Time is:" << awt << endl;

        for (int j = 0; j < n; j++)
        {
            tat[j] = wt[j] + bt[j];
            total_turnaround += tat[j];
        }
        atat = (float)total_turnaround / n;
        cout << "Average Turn Around Time is:" << atat << endl;

        all_avg_wait[2] = awt;
        all_avg_turn[2] = atat;
        }
       
    }

    void round_robin()
    {
        int time_quantum;
        cout << "Enter Time Quantum for round robin:";
        cin >> time_quantum;
        int rem_bt[n];
        for (int i = 0; i < n; i++)
        {
            rem_bt[i] = bt[i];
        }

        int time = 0;

        bool done = false;
        while (!done)
        {
            done = true;
            for (int i = 0; i < n; i++)
            {
                if (rem_bt[i] > 0)
                {
                    done = false;

                    if (rem_bt[i] > time_quantum)
                    {
                        time += time_quantum;
                        rem_bt[i] -= time_quantum;
                    }
                    else
                    {
                        time = time + rem_bt[i];
                        wt[i] = time - bt[i];
                        rem_bt[i] = 0;
                    }
                }
            }
        }
        float total_wait = 0;
        for (int j = 0; j < n; j++)
        {
            total_wait = total_wait + wt[j];
        }

        float total_turnaround = 0;
        awt = 0;
        atat = 0;
        for (int j = 0; j < n; j++)
        {
            tat[j] = wt[j] + bt[j];
            total_turnaround += tat[j];
        }

        awt = total_wait / n;
        cout << "Average Waiting Time is:" << awt << endl;
        atat = total_turnaround / n;
        cout << "Average Turn Around Time is:" << atat << endl;

        all_avg_wait[3] = awt;
        all_avg_turn[3] = atat;
    }

    void display_avg()
    {
        cout << "Algo"
             << "\t"
             << "Avg_Wait"
             << "\t"
             << "Avg_Turn\n";
        cout << "-----------------------------------------\n";
        for (int i = 0; i < 4; i++)
        {
            cout << algo[i] << "\t" << setprecision(2) << all_avg_wait[i] << "\t\t" << all_avg_turn[i] << endl;
        }
    }

    void display()
    {
        cout << "Process\t\t"
             << "AT\t"
             << "BT\t"
             << "WT\t"
             << "TT\t" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << (i + 1) << "      \t\t" << at[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
        }
    }
};

int main()
{
    Cpu_sched obj;

    obj.get();

    obj.fcfs();
    obj.display();
    cout << endl;

    obj.sjf();
    obj.display();
    cout << endl;

    obj.priority();
    obj.display();
    cout << endl;

    obj.round_robin();
    obj.display();
    cout << endl;

    obj.display_avg();

    return 0;
}