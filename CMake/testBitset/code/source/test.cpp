// bitset operators
#include <iostream>       // std::cout
#include <string>         // std::string
#include <bitset>         // std::bitset

/*
// Function to return the only odd occurring element 
int findOdd(uint8_t arr[], uint8_t n) { 
  uint8_t res = 0;
  for (size_t i = 0; i != n; i++) {
    //std::cout<<"i="<<i<<" before res="<<res<<" arr[i]="<<arr[i]<<std::endl;
    printf("i=%d arr[i]=%d res=%d  \n",i,arr[i],res);
    res ^= arr[i];
    //std::cout<<"i="<<i<<" after  res="<<res<<" arr[i]="<<arr[i]<<std::endl;
  }
  return res; 
} 
  
int main(void) { 
   uint8_t arr[] = {12, 12, 14, 90, 15, 15, 14}; 
   int a=sizeof(arr);
   int b=sizeof(arr[0]);
   // way to calculate the number of elements in an array
   // the ratio of the size of the entire array to the size of one element
   int n = sizeof(arr)/sizeof(arr[0]); 
   int m=sizeof(char);
   int o=sizeof(float);
   int p=sizeof(uint8_t);
   int r=sizeof(bool);
   int s=sizeof(double);
   //int t=sizeof(int);
   //int u=sizeof(size_t)
   uint16_t t=13^12^12;;
   uint16_t u=12^12^13;
   uint16_t v=12^13^12;
   std::cout<<"a="<<a<<" b="<<b<<" n="<<n<<" m="<<m<<" o="<<o<<" p="<<p<<" r="<<r<<" s="<<s<<" t="<<t<<" u="<<u<<" v="<<v<<std::endl;
   printf ("t=%d u=%d v=%d \n",t,u,v);
   printf ("The odd occurring element is %d \n", findOdd(arr, n)); 
   return 0; 
} 
/// Output: The odd occurring element is 90 
*/

/*
#include<stdio.h> 
int main() 
{ 
    unsigned char a = 5, b = 9; // a = 5(00000101), b = 9(00001001) 
    printf("a = %d, b = %d\n", a, b); 
    printf("a&b = %d\n", a&b); // The result is 00000001 
    printf("a|b = %d\n", a|b);  // The result is 00001101 
    printf("a^b = %d\n", a^b); // The result is 00001100 
    printf("~a = %d\n", a = ~a);   // The result is 11111010 
    printf("b<<1 = %d\n", b<<1);  // The result is 00010010  
    printf("b>>1 = %d\n", b>>1);  // The result is 00000100  
    return 0; 
} 
*/


/*
int main ()
{
  //std::bitset<4> foo (0010);
  //std::bitset<4> bar (std::string("0011"));
  //std::string a=foo.to_string();
  //std::cout<<"foo="<<foo<<" a="<<a<<std::endl;

  std::bitset<16> foo;
  std::bitset<16> bar (0xfa2); // Hexadecimal makes it easier to write these large binary numbers. A=10, B=11, ... , F=15 here fa2=4002
  std::bitset<16> baz (std::string("0101111001"));

  std::cout << "foo="<<foo<<" as an integer is "<<foo.to_ulong()<<std::endl;
  std::cout << "bar="<<foo<<" as an integer is "<<bar.to_ulong()<<std::endl;
  std::cout << "baz="<<foo<<" as an integer is "<<baz.to_ulong() <<" of size="<<baz.size()<<std::endl;
  // careful, bits are counted from the end, from the right
  for (size_t i=0; i!=baz.size(); i++) {
    std::cout<<"i="<<i<<" baz["<<i<<"]="<<baz[i]<<std::endl;
  }

  return 0;

  std::cout << "foo "<<foo<<std::endl;
  std::cout << "bar "<<bar<<std::endl;
  std::cout << "foo^bar "<<(foo^bar)<<std::endl; // XOR
  std::cout << "foo&bar "<<(foo&bar)<<std::endl; // AND
  std::cout << "foo|bar "<<(foo|bar)<<std::endl;
  std::cout << "~(foo|bar) "<<(~(foo|bar))<<std::endl;
  std::cout << "foo<<2 "<<(foo<<2)<<std::endl;
  std::cout << "foo>>1 "<<(foo>>1)<<std::endl;
  std::cout << "~bar "<<(~bar)<<std::endl;
  std::cout << "bar<<1 "<<(bar<<1)<<std::endl;
  std::cout << "bar>>1 "<<(bar>>1)<<std::endl;

  return 0;

  std::cout << (foo^=bar) << '\n';       // 1010 (XOR,assign)
  std::cout << (foo&=bar) << '\n';       // 0010 (AND,assign)
  std::cout << (foo|=bar) << '\n';       // 0011 (OR,assign)

  std::cout << (foo<<=2) << '\n';        // 1100 (SHL,assign)
  std::cout << (foo>>=1) << '\n';        // 0110 (SHR,assign)

  std::cout << (~bar) << '\n';           // 1100 (NOT)
  std::cout << (bar<<1) << '\n';         // 0110 (SHL)
  std::cout << (bar>>1) << '\n';         // 0001 (SHR)

  std::cout << (foo==bar) << '\n';       // false (0110==0011)
  std::cout << (foo!=bar) << '\n';       // true  (0110!=0011)

  std::cout << (foo&bar) << '\n';        // 0010
  std::cout << (foo|bar) << '\n';        // 0111
  std::cout << (foo^bar) << '\n';        // 0101

  return 0;
}
*/


int main ()
{
  std::bitset<5> foo (std::string("01011"));
  std::bitset<5> bar (std::string("11010"));

  std::cout << "foo contains:\n";
  std::cout << std::boolalpha;
  //for (std::size_t i=0; i<foo.size(); ++i)
  //  std::cout << foo.test(i) << '\n';

  //returns false, but does not complain, if the element is not present as in total only 5 bits and we ask for 7
  std::cout << foo[7] << '\n';
  
  // test method checks and if 5 and we ask 7 it will through an exception
  std::cout << foo.test(2) << std::endl;

  // resets to zero a bit at a given position and through an exception if we try to set the bit that is not defined
  foo.reset(1);

  // reset all the bits to zero
  foo.reset();

  // set one particular bit at index 2 as read from the right to the value of 1
  foo.set(2);

  // set one particular bit at index 2 as read from the right to the value of 0
  foo.set(2,0);

  // set one particular bit at index 2 as read from the right to the value of 1
  foo.set(2,1);

  // reset all values to zero
  foo.reset();

  // set all values to one
  foo.set();

  // flip all the values (0->1, 1->0)
  foo.flip();
  
  // flip the value of ony a certain position
  foo.flip(2);

  std::cout << foo << " has ";
  std::cout << foo.count() << " ones and ";
  std::cout << (foo.size()-foo.count()) << " zeros.\n";
  std::cout << "any 1 in foo="<<foo.any()<<std::endl;
  std::cout << "none 1 in foo="<<foo.none()<<std::endl;
  std::cout << "all 1 in foo="<<foo.all()<<std::endl;

  std::cout<< "foo="<<foo<<std::endl;

  unsigned char x{ 0b11111110u };

  std::cout << (foo^bar) << '\n';        // 0101
  std::cout << (bar^bar) << '\n';        // 0101
  std::cout << (foo^bar^bar) << '\n';    // 0101
  std::cout << (bar^foo^bar) << '\n';    // 0101
  std::cout << (bar^bar^foo) << '\n';    // 0101
  std::cout <<" to_string="<<foo.to_string()<<std::endl;
  // when converting to string, represent 0 as r and 1 as s
  std::cout <<" to_string="<<foo.to_string('r','s')<<std::endl;

  std::cout<<sizeof(char)<<std::endl;
  std::cout<<sizeof(unsigned char)<<std::endl;
  std::cout<<sizeof(short)<<std::endl;
  std::cout<<sizeof(unsigned short)<<std::endl;
  std::cout<<sizeof(long)<<std::endl;
  std::cout<<sizeof(unsigned long)<<std::endl;
  std::cout<<sizeof(long long)<<std::endl;
  std::cout<<sizeof(unsigned long long)<<std::endl;

  unsigned short c=0;
  std::bitset<sizeof(unsigned char)*8>bs_c(c);
  bs_c.set();
  std::cout<<"c="<<c<<" bs_c="<<bs_c<<" back to number "<<bs_c.to_ulong()<<std::endl;

  unsigned short ui8=0;
  std::bitset<sizeof(unsigned char)*8>bs_ui8(ui8);
  bs_ui8.set();
  std::cout<<"ui8="<<ui8<<" bs_ui8="<<bs_ui8<<" back to number "<<bs_ui8.to_ulong()<<std::endl;

  unsigned short s=0;
  std::bitset<sizeof(unsigned short)*8>bs_s(s);
  bs_s.set();
  std::cout<<"s="<<s<<" bs_s="<<bs_s<<" back to number "<<bs_s.to_ulong()<<std::endl;

  unsigned int i=0;
  std::bitset<sizeof(unsigned int)*8>bs_i(i);
  bs_i.set();
  std::cout<<"i="<<i<<" bs_i="<<bs_i<<" back to number "<<bs_i.to_ulong()<<std::endl;

  unsigned long l=0;
  std::bitset<sizeof(unsigned long)*8>bs_l(l);
  bs_l.set();
  std::cout<<"l="<<l<<" bs_l="<<bs_l<<" back to number "<<bs_l.to_ulong()<<std::endl;

  unsigned long long ll=0;
  std::bitset<sizeof(unsigned long long)*8>bs_ll(ll);
  bs_ll.set();
  std::cout<<"ll="<<ll<<" bs_ll="<<bs_ll<<" back to number "<<bs_ll.to_ulong()<<std::endl;
  

  return 0;
}
