#include<iostream>
using namespace std;

class String {

int duzina;
char *znakovi;
int kapacitet;

public:
    String(); // Podrazumijevani (default) konstruktor
    String(int n, char c); // Konstruktor koji pravi string od n istih karaktera c
    String(const char* znakovi); // Konstruktor iz C-stringa (const char*)
    String(const String& kopija); // Konstruktor kopije
    ~String() {cout<<"DESTRUKTOR"<<endl; delete []znakovi;} // Destruktor

    String& PushBack(const char c); // Dodaje jedan znak na kraj stringa
    int vratiDuzinu() const {return duzina;} // Vraća trenutnu dužinu stringa
    String& operator =(const String& s); // Operator dodjele
    String& operator +=(const String& s); // Operator naddodjele

    char& operator[](int indeks) {return znakovi[indeks];} // Omogućava pisanje u string
    char operator[](int indeks) const {return znakovi[indeks];} // Omogućava čitanje iz stringa kad je const objekat

    friend istream& operator>>(istream& unos, String& s); // Omogućava unos iz cin
    friend ostream& operator<<(ostream& ispis, const String& s); // Omogućava ispis

    friend const String operator+(const String& a, const String& b); // 
    friend bool operator < (const String& a, const  String& b); // 
    friend bool operator <= (const String& a, const  String& b); // 
    friend bool operator == (const String& a, const  String& b); // 
    friend bool operator != (const String& a, const  String& b); // 
};

String::String() :  kapacitet(10),duzina(0)  {
  znakovi= new char[kapacitet];
}

String:: String(int n, char c)  : duzina(n), kapacitet(2*n)   {
 znakovi = new char[kapacitet];
 for(int i=0; i<duzina; i++) znakovi[i]= c;
}


String::String(const String& kopija): duzina(kopija.duzina), kapacitet(kopija.kapacitet) {
    znakovi = new char[kapacitet];
    for(int i=0; i<duzina; i++)  znakovi[i] = kopija.znakovi[i];

}


String&  String:: operator=(const String& s) {
   if(this == &s)   return *this;
   duzina=s.duzina;
   kapacitet = s.kapacitet;
   delete[] znakovi;
   znakovi = new char[kapacitet];
   for(int i=0; i<duzina; i++)  znakovi[i] = s.znakovi[i];
   return *this;
}



String&  String::operator +=(const String & s) {
     *this = *this + s;
     return *this;
   }


String:: String(const char* znakovi) : duzina(0), kapacitet(10)  {
  this -> znakovi = new char[kapacitet];
  const char* pok = znakovi;
  while(*pok != '\0' ) {
    PushBack(*pok);
    pok++;
  }
}

String& String::PushBack(const char c) {
    if(duzina < kapacitet) 
        znakovi[duzina] = c;
        
    else{
        kapacitet *=2;
        char *kopija = new char[kapacitet];
        for(int i=0; i<duzina; i++)
            kopija[i] = znakovi[i];
        kopija[duzina]= c;
        duzina++;

        delete[] znakovi;
        znakovi = kopija;
    }
   duzina++;
   return *this;
}


ostream& operator<<(ostream& ispis, const String& s) {
   for(int i=0; i<s.duzina; i++)  ispis<<s[i];
   return ispis;

}


istream& operator>>(istream& unos, String& s) {
   delete [] s.znakovi;
   s.duzina =0; s.kapacitet= 10;
   s.znakovi= new char[s.kapacitet];
   char znak;
   while( (znak =unos.get() )!= '\n' )
      s.PushBack(znak);
   return unos;
}

const String operator+(const String& a, const  String& b) {
  String novi(a);
  for(int i=0; i<b.duzina; i++) novi.PushBack(b[i]);
  return novi;
}


bool operator < (const String& a, const String& b)  {
  int m = min(a.duzina, b.duzina);
  for(int i=0; i<m; i++) {
    if(a[i] < b[i]) return true;
    else if(a[i] > b[i] ) return false;
  }
  return a.duzina < b.duzina;
}

 bool operator == (const String& a, const String& b)  {
    if(a.duzina != b.duzina) return false;
    for(int i=0; i<a.duzina; i++) {
        if (a[i] != b[i] ) return false;
    }
   return true;
 }

 bool operator <= (const String& a, const  String& b)  {
   return a<b || a==b;
 }

 bool operator != (const String& a, const  String& b) {
   return  !(a==b);
 }



int main(){

String a(2,'b');
cout<<a<<endl;

a[1]='c';

String b(a);
cout<<"b= "<<b<<endl;
cin>>a;
cout<<a<<endl;
cout<<a+b<<endl;
a+=b;
cout<<a<<endl;
String c;
c= a;
cout<<c<<endl;

}
 

