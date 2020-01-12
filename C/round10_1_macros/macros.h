#define EQ3(a,b,c) (a==b && b==c && a==c)? 1 :0

#define MIN2(a,b) (a>b)? b:a

#define MIN3(a,b,c) MIN2(MIN2(a,b),c)
