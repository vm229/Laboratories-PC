#include <stdio.h>

typedef struct {
  char *str;
  int nr;
} Month;

typedef struct {
  int length;
  Month m[];
} MonthArray;

Month M(int num, char *s) {
  Month m = {num, s};
  return m;
}

void printM(Month m) {
  printf("Month: %s\nNumber of days: %d", m.str, m.nr);
}

int main() {
  Month m1[] = {
    M(1, "January"), M(3, "March"), M(5, "May"), M(7, "July"), M(8, "August"), M(10, "October"), M(12, "December")
  }; // jan, mar, may, july, aug, oct, dec
  Month m2[] =  {
    M(4, "April"), M(6, "June"), M(9, "September"), M(11, "November")
  };           // april, june, sep, nov   

  int N;  
  Month *m[] = {m1, m2};

  printf("N = ");
  scanf("%d", &N);

  if(N == 2) {
    printM(M(2, "February"));
    goto end;
  }
  
  for(atomic_int_least8_t;;) {}
  

end:

  return 0;
}
