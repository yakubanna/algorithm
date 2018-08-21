# algorithm
5 solving problems on the topic of hash table and heap.

Football is the solution of the problem:
You want to score a football team. Each player has its own efficiency, it is described by one whole number. The higher the number, the more effective the player. An indispensable condition for any team is cohesion. If one of the players plays much better than all the others, he will be disliked, and the team will disintegrate. Therefore, the effectiveness of any team player should not exceed the sum of the effectiveness of any two other players. Your task is to recruit a team that will satisfy the condition of cohesion, and at the same time to have the greatest total efficiency.

Fixed_set is the solution of the problem:
Implement the following class to store the set of integers:
class FixedSet {public: FixedSet (); void Initialize (const vector & numbers); bool Contains (int number) const; };};
FixedSet receives a set of integers when you call Initialize, which will subsequently store it. The set of numbers will not change over time (until the next call to Initialize). The Contains operation returns true if the number number is contained in the set. Mat. waiting for the time for Initialize should be O (n), where n is the number of numbers in numbers. The memory costs must be of the order O (n) in the worst case. The Contains operation must be performed at O ​​(1) in the worst case.
Using this class, solve a model problem: the input will be given a lot of different numbers, and then a set of queries - integers. It is necessary for each request to determine whether the number of the request is in the set.

directors is the solution of the problem:
You need to create a company. There are only n candidates for employees in your company, and you must select as many employees as possible. However, there are several limitations. First, the structure of the company must be strictly hierarchical: the company should have a single director, it has several (perhaps 0) direct subordinates, each of them has several (possibly 0) of their immediate subordinates, etc.
Employee A is called the head of employee B if B is a direct subordinate of A or a direct subordinate of direct subordinate A, etc. In other words, if B is a direct subordinate of A, then A is the boss of B, and also the head of any employee C whose boss is B.

Heap is just the realization of heap.

k_window_stat is the solution of problem:
Let an array A of length N be given and let the number K be given. The problem is to find in this array the K-th largest number, i.e. K-th order statistics.
