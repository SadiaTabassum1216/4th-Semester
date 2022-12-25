#include<stdio.h>
#include<unistd.h>

int main()
{
printf("This line won't be executed");
//fork();
for(;;){}

return 0;
}
