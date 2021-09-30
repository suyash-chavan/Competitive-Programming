#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vr = {34, 56, 21, 89, 47};
   
    cout<<"\n Our original vector is:";
    for(int i=0; i<5; i++)
        cout<<vr[i]<<" ";

    
    //to sort vector
    sort(vr.begin(), vr.end()); //O(NlogN)
    cout<<"\n Vector after sorting is:";
     for(int i=0; i<5; i++)
        cout<<vr[i]<<" ";

   
    //to sort vector in descending oreder
    sort(vr.begin(), vr.end(), greater<int>());
    cout << "\n Sorted Vector in descending order:";
    for (int i = 0; i < vr.size(); i++)
        cout << vr[i] << " ";
    cout << endl;
    
    //binary search operation 
    bool present = binary_search(vr.begin(), vr.end(), 56); //O(logN)  output will be true
   /* if(present)
       cout<<"\n"<<1; */

    //to add elements to the vector
    vr.push_back(100);
    cout<<"\n after adding elements vector is:";
    for(int i=0; i<vr.size(); i++)
        cout<<vr[i]<<" ";

    sort(vr.begin(), vr.end());
    //iterators 
    auto ite = lower_bound(vr.begin(), vr.end(), 89); // >= (output will be 56 cause 56>=56)
    auto ite2 = lower_bound(vr.begin(), vr.end(), 89); // > (output will be 89 cause 89>56)
    cout<<"\n"<<*ite<<" "<<*ite2; 
    

    return 0;
}