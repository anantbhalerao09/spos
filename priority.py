# Function to find the waiting time for all processes
def findWaitingTime(processes, n, wt):
    wt[0] = 0
 
    # calculating waiting time
    for i in range(1, n):
        wt[i] = processes[i - 1][1] + wt[i - 1]
 
# Function to calculate turnaround time
def findTurnAroundTime(processes, n, wt, tat):
     
    # Calculating turnaround time by adding bt[i] + wt[i]
    for i in range(n):
        tat[i] = processes[i][1] + wt[i]
 
# Function to calculate average waiting and turn-around times.
def findavgTime(processes, n):
    wt = [0] * n
    tat = [0] * n
 
    # Function to find waiting time of all processes
    findWaitingTime(processes, n, wt)
 
    # Function to find turnaround time for all processes
    findTurnAroundTime(processes, n, wt, tat)
 
    # Display processes along with all details
    print("\nProcesses    Burst Time    Waiting",
          "Time    Turn-Around Time")
    total_wt = 0
    total_tat = 0
    for i in range(n):
 
        total_wt = total_wt + wt[i]
        total_tat = total_tat + tat[i]
        print(" ", processes[i][0], "\t\t",
                   processes[i][1], "\t\t",
                   wt[i], "\t\t", tat[i])
 
    print("\nAverage waiting time = %.5f "%(total_wt /n))
    print("Average turn around time = ", total_tat / n)
 
def priorityScheduling(proc, n):
     
    # Sort processes by priority
    proc = sorted(proc, key = lambda proc:proc[2],
                                  reverse = True)
 
    print("Order in which processes gets executed")
    for i in proc:
        print(i[0], end = " ")
    findavgTime(proc, n)
     
# Driver code
if __name__ =="__main__":
     
    # Process id's
    proc = [[1, 10, 1],
            [2, 5, 0],
            [3, 8, 1]]
    n = 3
    priorityScheduling(proc, n)



# PS D:\shubham\spos> python priority.py
# Order in which processes gets executed
# 1 3 2 
# Processes    Burst Time    Waiting Time    Turn-Around Time
#   1              10              0               10
#   3              8               10              18
#   2              5               18              23

# Average waiting time = 9.33333 
# Average turn around time =  17.0