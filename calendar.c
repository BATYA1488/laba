#include <stdio.h> 
#include <stdlib.h> 

int main () 
{ 
int day, month, year, a, m, y, r; 

printf("Enter the day\n"); 
scanf("%d",&day); 
printf("Enter the month\n"); 
scanf("%d", &month); 
printf("Enter the year\n"); 
scanf("%d", &year); 
a =(14 - month) / 12; 
y = year - a; 
m = month + 12 * a - 2; 
r = 7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12); 
r = r % 7; 
switch(r) 
{ 
case 1: 
printf(" __\n"); 
printf("|Mo|\n"); 
printf(" Monday\n"); 
break; 
case 2: 
printf(" __\n"); 
printf("|Tu|\n"); 
printf(" Tuesday\n"); 
break; 
case 3: 
printf(" __\n"); 
printf("|We|\n"); 
printf(" Wednesday\n"); 
break; 
case 4: 
printf(" __\n"); 
printf("|Th|\n"); 
printf(" Thursday\n"); 
break; 
case 5: 
printf(" __\n"); 
printf("|Fr|\n"); 
printf(" Friday\n"); 
break; 
case 6: 
printf(" __\n"); 
printf("|Sa|\n"); 
printf(" Saturday\n"); 
break; 
case 0: 
printf("__\n"); 
printf("Su\n"); 
printf(" Sunday\n"); 
break; 
} 

return 0; 
}
