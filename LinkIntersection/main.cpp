#include <iostream>
#include <vector>
using namespace std;

int s1[10005];
int s2[10005];
vector<int> outputList;

void input(int s[]){
    int i = 0;
    while(true){
        int c; cin>>c;
        s[i++] = c;
        if(c == -1) break;
    }
}
int main() {
    input(s1),input(s2);
    int i = 0,j = 0;
    while(true){
        int a = s1[i],b = s2[j];
        if(a == -1 || b == -1) break;
        if(a < b) i++;
        else if(a > b) j++;
        else outputList.push_back(a),i++,j++;
    }
    if(outputList.empty()) cout<<"NULL"<<endl;
    else {
        int size = outputList.size();
        for(int c = 0;c < size - 1;c++)
            cout<<outputList.at(c)<<" ";
        cout<<outputList.back()<<endl;
    }
    return 0;
}
