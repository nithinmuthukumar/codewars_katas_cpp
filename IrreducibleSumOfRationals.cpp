//
// Created by nithin muthukumar on 2019-07-18.
//
#include <vector>
#include<utility>
#include <iostream>

using namespace std;
class SumFractions
{
public:
    static int gcd(int a,int b){
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    static pair <int, int> sumFracts(vector<vector<int>> &l){
        vector<int> denoms;
        int denominator=l[0][1];
        int numerator=0;
        for(auto v: l){
            denominator=(denominator*v[1])/gcd(denominator,v[1]);
        }
        for(auto v:l){
            numerator+=v[0]*(denominator/v[1]);
        }
        int factor=gcd(numerator,denominator);

        pair<int,int> ans (numerator/factor,denominator/factor);
        return ans;

    }
};
int main(){
    vector<vector<int>> a1 = { {1,2}, {2,9}, {3,18}, {4,24}, {6,48} };
    cout<<SumFractions::sumFracts(a1).second;
    return 0;
}

