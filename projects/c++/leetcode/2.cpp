#include<iostream>
#include<vector>
#include<assert.h>


using namespace std;

int cal(vector<int>& nums1, vector<int>& nums2 ){
    long sum=0;
    vector<pair<int,int>> tmp;

    int i=0,j=0;
    while(true)
    {
        if( nums1[i] < nums2[j] ) { i++; }
        
        else if( nums1[i] > nums2[j]) {j++; }

        else   tmp.push_back( make_pair(i,j) );

        if( i == nums1.size() || j==nums2.size()) break;
    }

    if(tmp.size()==0)
    {
        long t1=0,t2=0;
        for(int a=0; a<nums1.size();a++)
            t1+=nums1[a];
        for(int a=0; a<nums2.size();a++)
            t2+=nums1[a];
        
        return max(t1 ,t2);
    }
    else if(tmp.size()==1)
    {
        long t1=0,t2=0;
        for(int a=0; a<tmp[0].first;a++)
            t1+=nums1[a];

        for(int a=0; a<tmp[0].second;a++)
            t2+=nums1[a];

        long sum = max(t1,t2);
        t1=0; t2=0;
        for(int a=tmp[0].first+1 ; a<nums1.size();a++)
            t1+=nums1[a];

        for(int a=tmp[0].second; a<nums2.size();a++)
            t2+=nums1[a];
        sum+=max(t1,t2);

    }
    else
    {}

}


void run(){
    vector<int> nums1 = {2,4,5,8,10}, nums2 = {4,6,8,9};
    assert(cal(nums1,nums2) == 30);

    nums1 = {1,3,5,7,9}, nums2 = {3,5,100};
    assert(cal(nums1,nums2) == 109);

    nums1 = {1,2,3,4,5}, nums2 = {6,7,8,9,10};
    assert(cal(nums1,nums2) == 40);

};

int main(int argc, char const *argv[])
{
    run();
    return 0;
}
