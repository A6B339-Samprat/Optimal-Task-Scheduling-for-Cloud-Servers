# Optimal-Task-Scheduling-for-Cloud-Servers
In cloud platforms (like AWS, Azure, or Google Cloud), multiple jobs with different deadlines and profits need to be executed on limited virtual machines (VMs).So to maximize profit and reduce idle time for the servers and to work more efficiently.

The goal is to allocate multiple computational tasks to heterogeneous cloud servers efficiently, minimizing the **makespan** (overall completion time) and improving **load balancing**.

 Objective
To design and implement a **Greedy-based scheduling algorithm** that:
- Assigns each task to the most suitable server.
- Minimizes the total completion time (makespan).
- Optimizes resource utilization and load distribution.

- In cloud environments, multiple servers (resources) execute independent tasks of varying lengths.  
The Greedy Method (Min–Min heuristic) schedules tasks by always making the **locally optimal choice** — selecting the task–server pair that finishes earliest at every step.

Greedy Choice Property:
At each iteration, pick the task that can be completed *earliest* and assign it to the corresponding server.

Optimal Substructure:
After one optimal assignment, the remaining problem (with remaining tasks) retains the same structure — allowing recursive optimal construction.
