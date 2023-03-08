#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    map <int,int> values;
    vector <int> nums,ans;
    int target = 9;
    nums.push_back(2);
    nums.push_back(15);
    nums.push_back(7);
    nums.push_back(11);

    vector<int>::iterator it_vec;


    for(int i=0;i<nums.size();i++){
        int val1 = nums[i];
        auto x = values.find(target - val1);
        if(x != values.end()  && x->second != i ){
            ans.push_back(x->second);
            ans.push_back(i);
            break;
        }
        else{
            values.insert(pair <int,int> (nums[i],i));
        }
    }
    
    for(int i=0; i<ans.size();i++){
        cout << ans[i]<<'\t';
    }
    cout << endl;
}