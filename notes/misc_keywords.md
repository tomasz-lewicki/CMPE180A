# static
- a static member of a class is one that is shared among all its instances


You access a static member by qualifying the class name using the :: (scope resolution) operator. In the following example, you can refer to the static member f() of class type X as X::f() even if no object of type X is ever declared:
struct X {
  static int f();
};

int main() {
  X::f();
}

source: https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/cplr036.htm