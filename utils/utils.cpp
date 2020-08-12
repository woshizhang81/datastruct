#include <stdio.h>
#include <stdlib.h>
template<typename T>
void print_binary(T t){
    int num_size = sizeof(T) * 8;
    int i = num_size;
    while(num_size--)
    {
        auto r = (t & (1<<num_size));
        if (r)
            printf("1");
        else
            printf("0"); 
        if (num_size % 4 == 0)
             printf(" ");
    }
}

void bin32bdis(int data)
{
    int i=32;
    while(i--) //32---1 
    {
        if(data & (1<<i))
            printf("1");
        else
            printf("0");
        if(i % 4 == 0) {
            if(i % 8==0)
                printf(" ");
            else
                printf("-");
        }
    }
    putchar(10);
}



int main()
{
    int i = 5;
   printf("%d\n", --i++);

    print_binary<int>(-1); 
    putchar(10);

    bin32bdis(-1);
    putchar(10);
}
