   #include <stdio.h>
   union temp
   {
       char a;
       char b;
       int c;
       int d;
   }x;
   int main()
   {
       printf("%d", sizeof(x));
       return 0;
   }
