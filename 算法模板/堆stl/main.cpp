/*
stl ��make�����ǻ��������
������Ļ����Ͻ��в���

ʹ��ע�⣺
1 ���� less<int>()  ��С�� greater<int>()
2 pop_heap ���ǽ�vector��Ԫ��ɾ�� ֻ�Ƿ�������� ʣ�µ�Ԫ���ٴ��γɶ�
3 ɾ��vector ���һ��Ԫ�� pop_back ���� numsv.erase(numsv.end()-1);
4 sort_heap ������һ�����Ͻ��в��� ���ǶѵĻ� ʹ�û����

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
    cout<<"===============Ĭ������==============="<<endl;
    make_heap(numsv.begin(),numsv.end());
    disp(numsv);

    cout<<"===============����==============="<<endl;
    make_heap(numsv.begin(),numsv.end(),less<int>());
    disp(numsv);

    cout<<"===============��С��==============="<<endl;
    make_heap(numsv.begin(),numsv.end(),greater<int>());
    disp(numsv);

    cout<<"==============ɾ���Ѷ�Ԫ��============"<<endl;
    numsv.erase(numsv.begin());
    make_heap(numsv.begin(),numsv.end(),greater<int>());
    disp(numsv);

    cout<<"===========ɾ��vectorĩβԪ��1=========="<<endl;
    numsv.erase(numsv.end()-1);
    disp(numsv);

    cout<<"===========ɾ��vectorĩβԪ��2=========="<<endl;
    numsv.pop_back();
    disp(numsv);

    cout<<"===============��������==============="<<endl;
    make_heap(numsv.begin(),numsv.end());
    disp(numsv);
    sort_heap(numsv.begin(),numsv.end());
    disp(numsv);

    return 0;
}
