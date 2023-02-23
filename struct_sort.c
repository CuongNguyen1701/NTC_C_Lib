#include <stdio.h>
int structcmp(const void *v1,const void *v2)
{
  const structName *s1 = (structName*)v1;
  const structName *s2 = (structName*)v2;
  if(s1->prop < s2->prop) return +1;//change the sign for ascending sort
  if(s1->prop > s2->prop) return -1;//change this also
  return 0;
}
void main(){
    //...//
    
    //sort descending
    qsort(list,     Num_of_element,           sizeof(list[0]),       structcmp);
                    //number of el in arr     //size of 1 element    //compare func
                    
    //...//
}



