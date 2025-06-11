#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Tacka {

double x,y;

public:
Tacka(double x, double y):x(x),y(y) {}
void Translatiraj(double dx, double dy) {
    x += dx;
    y += dy;
  }
double Udaljenost(Tacka a) {
        return sqrt(pow(x - a.x,2) + pow(y - a.y,2));
    }
friend double Orijentacija(Tacka A, Tacka B, Tacka C) {
   if(A.x*(B.y-C.y) + B.x*(C.y-A.y) + C.x*(A.y-B.y) > 0)
    return 1;
   else if(A.x*(B.y-C.y) + B.x*(C.y-A.y) + C.x*(A.y-B.y) < 0)
    return -1;
   else return 0;}
friend Tacka operator+(Tacka A, Tacka B) {  return Tacka(A.x + B.x, A.y + B.y);}
friend Tacka operator/(Tacka A, double skalar) { return Tacka(A.x/skalar,A.y/skalar);}
friend ostream& operator<<(ostream& ispis, Tacka T) { ispis<<"("<<T.x<<","<<T.y<<")";  return ispis;}
};



class Lik {
  public:
  virtual Tacka getTeziste() = 0;
  virtual void Translatiraj(double dx, double dy) = 0;
  virtual bool daLiPripada(Tacka A) = 0;
  virtual void Ispisi() = 0;
};

class Krug: public Lik {
  Tacka centar;
  double r;
  public:
  Krug(Tacka c, double r):centar(c),r(r) {}
  Krug(Tacka c, Tacka tacka_sa_kruznice): centar(c) {
     r = c.Udaljenost(tacka_sa_kruznice);

    }
  Tacka getTeziste() { return centar; }
  void Translatiraj(double dx, double dy) {
    centar.Translatiraj(dx,dy);
  };
  bool daLiPripada(Tacka A) {
    return centar.Udaljenost(A) < r;
  }
  void Ispisi() {
    cout<<"Centar kruga je "<<centar<<", a poluprecnik je "<<r;
  }
};


class Trougao: public Lik {
  Tacka A,B,C;
  public:
  Trougao(Tacka A, Tacka B, Tacka C):A(A),B(B),C(C){}
  Tacka getTeziste() { return Tacka((A+B+C)/3);}
  void Translatiraj(double dx, double dy) {
    A.Translatiraj(dx,dy);
    B.Translatiraj(dx,dy);
    C.Translatiraj(dx,dy);
  }

  bool daLiPripada(Tacka T) {
      return (Orijentacija(A,B,T) == 1 &&  Orijentacija(B, C, T) == 1 && Orijentacija(C,A,T) ==1)
      || (Orijentacija(A,B,T) == -1 &&  Orijentacija(B, C, T) == -1 &&Orijentacija(C,A,T) == -1) ;};


  void Ispisi() {
    cout<<"Vrhovi trougla su "<<A<<","<<B<<","<<C;
  };
};

int main() {
  Lik *krug1 = new Krug(Tacka(1,2),3);
  Lik *T = new Trougao(Tacka(1,1),Tacka(1,4),Tacka(5,1));
  Lik *krug2 = new Krug(Tacka(0,0),Tacka(5,6));
  vector<Lik*> likovi;
  likovi.push_back(krug1);
  likovi.push_back(T);
  likovi.push_back(krug2);
  for(int i=0;i<likovi.size();i++)
    likovi[i]->Translatiraj(1,2);
  for(int i=0;i<likovi.size();i++) {
    likovi[i]->Ispisi();
    cout<<endl;
  }

  for(int i=0;i<likovi.size();i++)
    cout<<likovi[i]->getTeziste()<<endl;
}
