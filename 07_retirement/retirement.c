#include <stdlib.h>
#include <stdio.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double calculate_balance(double original_balance, retire_info info){
  double new_balance = original_balance*(1+info.rate_of_return) + info.contribution;
  return new_balance;
}

void print_balance(int age_in_month, double balance){
   int age_month = age_in_month % 12;                                                      
   int age_year = (age_in_month-age_month)/12;                                           
   printf("Age %3d month %2d you have $%.2lf\n", age_year, age_month, balance);
}

void retirement (int startAge,   //in months                    
                 double initial, //initial savings in dollars   
                 retire_info working, //info about working      
                 retire_info retired) //info about being retired
{double balance = initial;
 for(int i = startAge; i < startAge + working.months; i++){
   print_balance(i, balance);
   balance = calculate_balance(balance, working);
 }
 for(int i = startAge+working.months; i<startAge+working.months+retired.months; i++){
   print_balance(i, balance);
   balance = calculate_balance(balance, retired);
 }
}

int main(void){
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;
  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;
  retirement(327, 21345, working, retired);
  return EXIT_SUCCESS;
}
