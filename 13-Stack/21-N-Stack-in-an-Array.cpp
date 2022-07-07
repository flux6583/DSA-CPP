/*

N Stacks In An Array(CodeStudio)

Problem Statement

Design a data structure to implement ‘N’ stacks using a single array of size ‘S’. It should support the following operations:
push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.

pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.
Two types of queries denote these operations :
Type 1: for push(X, M) operation.
Type 2: for pop(M) operation.

Input Format :
The first line of input contains three space-separated integers ‘N’, ‘S’ and ‘Q’ denoting the number of stacks, the size of the array and number of queries, respectively. 
The next ‘Q’ lines specify the type of operation/query to be performed on the data structure.
Each query contains an integer ‘P’ denoting the type of query.
For query of type 1, the integer ‘P’ is equal to 1 and it is followed by two space-separated integers ‘X’ and ‘M’ denoting the element and stack on which operation is to be performed, respectively.
For query of type 2, the integer ‘P’ is equal to 2 and it is followed by a single integer ‘M’ denoting the stack on which operation is to be performed.

Output Format :
For each query, print the output returned after performing the corresponding operation on the data structure. 
Note :
You do not need to print anything, it has already been taken care of. Just implement the given functions.

Sample Input 1 :
3 6 5
1 10 1
1 20 1
1 30 2
2 1
2 2

Sample Output 1 :
True 
True
True
20
30

Explanation 1 :
For the given input, we have the number of stacks, N = 3, size of the array, S = 6 and number of queries, Q = 5.
Operations performed on the stack are as follows:
push(10, 1): Push element ‘10’ into the 1st stack. This returns true.
push(20, 1): Push element ‘20’ into the 1st stack. This returns true.
push(30, 2): Push element ‘30’ into the 2nd stack. This returns true.
pop(1): Pop the top element from the 1st stack. This returns 20.
pop(2): Pop the top element from the 2nd stack. This returns 30.

The following image shows the snapshots of the stack after each operation:

*/

class NStack
{
public:
    int *arr;
    int *top;
    int *next;
    
    int n,s;
    int freeSpot;
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        // top initialise
        for(int i=0; i<n; i++)
        {
            top[i] = -1;
        }
        
        // next initialize
        for(int i = 0; i<s; i++)
        {
            next[i] = i+1;
        }
        
        // update last index value to -1
        next[s-1] = -1;
        
        // initialize freeSpot
        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if(freeSpot == -1){
            return false;
        }
        
        // find index
        int index = freeSpot;
        
        // update freeSpot
        freeSpot = next[index];
        
        // insert element into array
        arr[index] = x;
        
        // update next
        next[index] = top[m-1];
        
        // update top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(top[m-1] == -1)
        {
            return -1;
        }
        int index = top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freeSpot;
        
        freeSpot = index;
        
        return arr[index];
    }
};
