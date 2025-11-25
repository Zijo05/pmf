#include <iostream>
#include <vector>
using namespace std;

//k=0 - prvi el. k=1 - drugi el.

int selekcija(vector<int> &v, int k){
    if(v.size()==1){
        return v[0];
    }

    auto srednji = v.size()/2;
    vector<int> lijevi;
    vector<int> desni;

    auto pivot = v[srednji];
    for(auto &x : v){
        if(x<pivot){
            lijevi.push_back(x);
        }
        else if(x>pivot){
            desni.push_back(x);
        }
    }

    if (lijevi.size() > k) {
    return selekcija(lijevi, k);
    }
    else if (k == lijevi.size()) {
        return pivot;
    }
    else {
    return selekcija(desni, k - lijevi.size() - 1);
    }

}

int selekcija1(vector<int> &v, int k){
    if(k>=v.size()){
        throw invalid_argument("Nisi ti to skontao bolan.");
    }
    return selekcija(v,k);
}

int main(){
    vector<int> v{10,30,50,20,40,60};
    for(int i=0;i<v.size();i++){
        cout<<i+1<<". najmanji element je: "<<selekcija1(v,i)<<endl;
    }
    return 0;
}