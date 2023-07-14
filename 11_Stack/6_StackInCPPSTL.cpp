#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
int main(){
    stack <ll> s;
    
    s.push(10);
    s.push(20);
    s.push(30);

    cout<<s.size()<<endl;

    cout<<s.top()<<endl;

    s.pop();

    cout<<s.top()<<endl;

    cout<<"STACK"<<endl;

    while(s.empty()==false)
    {
        cout<<s.top()<<endl;
        s.pop();
    }

    /**
     * @brief The above class has time complexity of O(1) for all stack operations.
     * 
     * Internal working : stack can be implemented on any underlying container that provided following ops : back(),size(),empty(),push_back(),pop_back().
     * 
     * Three containers : list,vector and deque all provide the above functionalities. (all have O(1) time complexity)
     * 
     * By default it is implemented using deque container.
     * 
     * Since stack is implemented using these 3 containers and works as an interface it is also called "container adapter".
     * 
     * So queue, priority queue all these are container adapter coz they are build on top of other containers.
     * 
     */

    return 0;
}