#include <iostream>
#include <string>
#include <vector>
using namespace std;
string rangeToString(vector<int> rng){

    if(rng.size()>2){
        return to_string(rng[0])+"-"+to_string(rng[rng.size()-1])+",";

    }else if(rng.size()==2){
        return to_string(rng[0])+","+to_string(rng[1])+",";
    }else{
        return to_string(rng[0])+",";
    }
}


string range_extraction(vector<int> args) {
    vector<int> difArray;
    difArray.push_back(0);
    for(int i=0;i<args.size()-1;i++){
        difArray.push_back(args[i+1]-args[i]);
    }
    difArray.push_back(0);
    vector<int> group;
    string s="";
    for(int i=0;i<difArray.size()-1;i++){
        group.push_back(args[i]);



        if(difArray[i+1]>1) {
            s+=rangeToString(group);


            vector<int> c;
            group=c;
            continue;
        }
    }
    if(group.size()>0){
        s+=rangeToString(group);
    }
    s.pop_back();

    return s;
}
void printGroup(vector<int> group){
    if(group.size()>2){
        cout<<group[0]<<"-"<<group[group.size()-1]<<",";
    }else if(group.size()==2){
        cout<<group[0]<<","<<group[1];
    }else{
        cout<<group[0]<<",";
    }

}

int main() {
    cout<<range_extraction({-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20});

    return 0;
}
