#include <cstdio>
#include "equiv.h"

int main( )
{

Equiv e(7);
printf("\n");

combine(e,3,6);
combine(e,4,5);
combine(e,3,5);
combine(e,3,1);
combine(e,3,5);

printBoss(e);

return  0;
}
