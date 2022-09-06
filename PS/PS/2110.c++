#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> arr;
int wifi_num;
int x;
int result;
int main(){
    cin>>x>>wifi_num;
    for (int i=0; i<x; i++) {
        int a=0;
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    int l=0;
    int r=arr[x-1];
    while (l<=r) {
        int mid=(l+r)/2;
        int gujum=arr[0];
        int wifi=1;
        for (int i=1; i<arr.size(); i++) {
            if (arr[i]-gujum>=mid) {
                wifi++;
                gujum=arr[i]; 
            }
        }
        if(wifi>=wifi_num)
        {
            result=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
        
    }
    
    cout<<result<<"\n";
    
    return 0;
}
