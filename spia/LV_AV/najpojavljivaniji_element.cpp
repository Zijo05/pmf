#include <iostream>
#include <vector>

using namespace std;

//Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

int brojPojava(vector<int> &v, int el){
    int broj{};
    for(auto x : v){
        if(x==el){
            broj++;
        }
    }
    return broj;
}

int majorityRek(vector<int> &v, int p, int k){
    //bazni slučaj
    if(p==k){
        return v[p];
    }

    //rekurzija
    int sredina=(p+k)/2;
    int lijevi=majorityRek(v, p, sredina);
    int desni=majorityRek(v, sredina+1, k);

    if(lijevi==desni){
        return lijevi;
    }
    int lijeviBroj = brojPojava(v, lijevi);
    int desniBroj = brojPojava(v, desni);

    if(lijeviBroj>desniBroj){
        return lijevi;
    }
    else return desni;
}

int majority(vector<int> &v){
    if(v.size()==0){
        throw invalid_argument("Nisi ti to skontao bolan.");
    }
    return majorityRek(v, 0, v.size()-1);
}

int main(){
    vector<int> v{1,2,3,3,3,5,6,7,3,2,1,3,7,5,8,9,3,3,2,1,3};
    cout<<"Element sa najvise pojavljivanja je: "<<majority(v);
    return 0;
}