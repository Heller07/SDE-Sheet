//tc == O(N2)
//sc = O(n)
#include <bits/stdc++.h>

void sort(stack<int> &stack,int num) 

{

    if(stack.empty()||num>stack.top())

    {

        stack.push(num);

        return;

    }

    int rec=stack.top();

    stack.pop();

    sort(stack,num);

    stack.push(rec);

 

}

void sortStack(stack<int> &stack)

{

    // Write your code here

    if(stack.empty())

        return;

    int store=stack.top();

    stack.pop();

    sortStack(stack);

    sort(stack,store);

}
