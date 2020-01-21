#include<iostream>
#include<map>
#include<string>

using namespace std;


int main(){
    int num; cin>>num;
    map<string,int> mp;
    for(int i = 0;i < num;i++){
        string plantName; getline(cin,plantName);
        map<string,int>::iterator it;
        it = mp.find(plantName);
        if(it == mp.end()) mp[plantName] = 1;
        else  (it->second)++;
    }
    map<string,int>::iterator iter;
    for(iter = mp.begin();iter != mp.end();iter++){
        double p = iter->second * 1.0 / num;
        cout<<iter->first<<" ";
        printf("%.4f\n",p);
    }
}
