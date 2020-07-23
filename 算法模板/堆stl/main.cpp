/*
stl 的make数组是基于数组的
在数组的基础上进行操作

使用注意：
1 最大堆 less<int>()  最小堆 greater<int>()
2 pop_heap 不是将vector的元素删除 只是放在了最后， 剩下的元素再次形成堆
3 删除vector 最后一个元素 pop_back 或者 numsv.erase(numsv.end()-1);
4 sort_heap 必须在一个堆上进行操作 不是堆的话 使用会出错

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void disp(vector<int> numsv){

    for(auto i: numsv){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    int nums[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    vector<int> numsv(nums,nums+15);

    //disp(numsv);
    cout<<"===============默认最大堆==============="<<endl;
    make_heap(numsv.begin(),numsv.end());
    disp(numsv);

    cout<<"===============最大堆==============="<<endl;
    make_heap(numsv.begin(),numsv.end(),less<int>());
    disp(numsv);

    cout<<"===============最小堆==============="<<endl;
    make_heap(numsv.begin(),numsv.end(),greater<int>());
    disp(numsv);

    cout<<"==============删除堆顶元素============"<<endl;
    numsv.erase(numsv.begin());
    make_heap(numsv.begin(),numsv.end(),greater<int>());
    disp(numsv);

    cout<<"===========删除vector末尾元素1=========="<<endl;
    numsv.erase(numsv.end()-1);
    disp(numsv);

    cout<<"===========删除vector末尾元素2=========="<<endl;
    numsv.pop_back();
    disp(numsv);

    cout<<"===============将堆排序==============="<<endl;
    make_heap(numsv.begin(),numsv.end());
    disp(numsv);
    sort_heap(numsv.begin(),numsv.end());
    disp(numsv);

    return 0;
}
