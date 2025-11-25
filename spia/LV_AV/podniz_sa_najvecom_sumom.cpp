#include <iostream>
#include <vector>

using namespace std;

int prelazSum(vector<int> &v, int p, int mid, int k){
    int lS = -9999999;
    int suma=0;
    
    for (int i = mid; i >= p; i--)
    {
        suma+= v[i];
        lS = max(lS, suma);
        cout<<"Suma u " << i << " iteraciji: " << suma<<endl;
        
    }

    int dS = -999999;
    suma=0;
    for (int i = mid+1; i <= k; i++)
    {
        suma+= v[i];
        dS = max(dS, suma);
    }
    
    return lS+dS;
}

int maxSumR(vector<int> &v, int p, int k){
    if(p==k) return v[p];

    auto mid = (k+p)/2;

    auto maxSumL = maxSumR(v, p, mid);
    auto maxSumD = maxSumR(v, mid+1, k);
    auto prelaz = prelazSum(v, p, mid, k);
    return max(max(maxSumL,maxSumD), prelaz);
}

int maxSum(vector<int> &v){
    if(v.empty()) throw domain_error("Mrs napolje");
    return maxSumR(v, 0, v.size()-1);
}

int main(){
    vector<int> v{-2,1,-3,4,-1,2,1,-5,4};
    auto rez = maxSum(v);
    cout<< rez;
    return 0;
}