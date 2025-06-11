istream& operator>>(istream& unos, String& s) {
   delete [] s.znakovi;
   s.duzina =0; s.kapacitet= 10;
   s.znakovi= new char[s.kapacitet];
   char znak;
   while( (znak =unos.get() )!= '\n' )
      s.PushBack(znak);
   return unos;
}