//
// Tomás Oliveira e Silva, AED, November 2021
//
// matched-parenthesis verification
//

#include <iostream>
#include "aStack.h"
#include <cstring>

using std::cout;
using std::cerr;
using std::endl;

int check_parenthesis(const char *s)
{
  // put your code here (20 lines of code should be enough)
  aStack<int> pilha(10 + (int)strlen(s));

  for(int i=0; i<(int)strlen(s); i++){
    if( s[i] == '('){
      pilha.push(i);
    }
    else if (s[i] == ')'){
      if(pilha.is_empty()) return -1;
      cout << "     ( at position "<<pilha.pop()<<" and ) at position "<<i<<endl;
    }
  }
  return !pilha.is_empty();
}

int main(int argc,char **argv)
{
  if(argc == 1)
  {
    cerr << "usage: " << argv[0] << " [arguments...]" << endl;
    cerr << "example: " << argv[0] << " 'abc(def)ghi' 'x)(y'" << endl;
    return 1;
  }
  for(int i = 1;i < argc;i++)
  {
    cout << argv[i] << endl;
    if(check_parenthesis(argv[i]) == 0)
      cout << "  good" << endl;
    else
      cout << "  bad" << endl;
  }
  return 0;
}
