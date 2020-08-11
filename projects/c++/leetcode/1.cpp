#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

int cal( vector<int> arr , int k){
    int count = 0;
    int now = 0;

    while(now < arr.size() -1 )
    {

        int i = now + 1;
        if(i==arr.size()) i = 0;

        // win
        while( arr[now] > arr[i] )
        {
            count++;    i++;
            while(i==now || i==arr.size())  i= (i+1)%arr.size();
            if(count == k ) return arr[now];
        }
        count=0;
        //loose
        {
            now++;
            count++;
            if(count == k) return arr[now];;
        }

        //lose
    }

    return arr[now];

}

void run(){
    vector<int> arr = {2,1,3,5,4,6,7};
    int k = 2;

    assert(cal(arr ,k) == 5);

    arr = {3,2,1}; k=10;
    assert(cal(arr ,k) == 3);

    arr = {1,9,8,2,3,7,6,4,5}; k=7;
    assert(cal(arr ,k) == 9);

    arr = {1,11,22,33,44,55,66,77,88,99}; k=1000000000;
    assert(cal(arr ,k) == 99);

    arr = {1,25,35,42,68,70}; k=1;
    assert(cal(arr ,k) == 25);
    

}

int main(int argc, char const *argv[])
{
    run();
    return 0;
}
