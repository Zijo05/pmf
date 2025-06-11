#include <iostream>
#include<vector>
#include<string>
using namespace std;

///ZA VJEZBU: SLICNO KAO I U PRVOM ZADATKU, MODIFIKOVATI TAKO DA RADI I U SLUCAJU KAD PROSLIJEDIMO  v.begin() i v.end()

template<typename Tip>
void SmjestiMinIMax (Tip* pocetak, Tip* izakraja, Tip* &minPok, Tip* &maxPok) {
   Tip tmin = *pocetak;
   Tip tmax = *pocetak;

  /* for(Tip* pok = pocetak; pok < izakraja; pok++) {
      if (*pok< tmin) { tmin=*pok;  minPok = pok; }
      else if (*pok>= tmax)  {tmax=*pok; maxPok = pok;}   }*/
  
    for (int i = 0; i < (izakraja - pocetak); i++) {
      cout<<i<<" "<<*(pocetak + i)<<" "<<pocetak + i<<endl;
       if (*(pocetak + i) < tmin) {
          tmin = *(pocetak + i);
          minPok = pocetak + i;
      }
      else if (*(pocetak + i)>= tmax)  {
          tmax = *(pocetak + i);
          maxPok = pocetak + i;
      }  
  } 
}

int main (){
 
int niz[]{6,2,4,8,6,1,3};
int* PokNaMin{nullptr};
int* PokNaMax{nullptr};

/*string niz[]{"abc","k","xyz","z","klm", "a", "opr"};
string* PokNaMin{nullptr};
string* PokNaMax{nullptr};*/

SmjestiMinIMax(niz, niz+7,PokNaMin, PokNaMax); 
cout<<"Min je "<<*PokNaMin<<", a max je "<<*PokNaMax<<endl;

return 0;
} 
