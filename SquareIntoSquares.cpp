//
// Created by nithin muthukumar on 2019-07-17.
//
#include <vector>
#include <math.h>
#include <iostream>
#include <set>

using namespace std;
class Decomp{
    static set<long long> sqs(long long n,set<long long> squares){
        int x=sqrt(n);
        if(n==1){
            squares.insert(1);
        }
        if(n<=1){
            return squares;
        }



        for(long long i=x;i>=5;i--){
            if(i==x&&squares.empty()||find(squares.begin(), squares.end(),i ) != squares.end()){
                continue;
            }

            set<long long> b=squares;
            b.insert(i);

            set<long long> a=sqs(n-i*i,b);
            if(!a.empty()){
                return a;

            }
        }
        return set<long long>();
    }
public:

    static vector<long long> decompose(long long n){

        set<long long> a=sqs(n*n,set<long long>());
        vector<long long> ans;
        for(auto v: a){
            ans.push_back(v);
        }

        return ans;
    }
};
int main(){

    for(auto a: Decomp::decompose(5)){
        cout<<endl;
        cout<<a<<endl;
    }



    return 0;

}

