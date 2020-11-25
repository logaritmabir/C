//Data_Structs_Project_3 'till 27.11.2020
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
void add_stick1(int number);
void add_stick2(int number);
void add_stick3(int number);
void printstick1();
void printstick2();
void printstick3();
void printallsticks();
void moveto1(struct stack *topa);
void moveto2(struct stack *topa);
void moveto3(struct stack *topa);
void changetopstick1();
void changetopstick2();
void changetopstick3();


struct stack *topstick1 = NULL;     //1.çubuğun tanımlanması
struct stack *topstick2 = NULL;     //2.çubuğun tanımlanması
struct stack *topstick3 = NULL;     //3.çubuğun tanımlanması
int main(void)
{
    add_stick1(3);      //1.çubuk yığınının oluşturulması
    add_stick1(2);
    add_stick1(1);
    printstick1();      //1.çubuğun kontrolü

    moveto3(topstick1);         //Çubuk1 den Çubuk3'e 
    changetopstick1();

    moveto3(topstick1);         //Çubuk1 den Çubuk3'e 
    changetopstick1();

    moveto2(topstick3);         //Çubuk3 den Çubuk2'ye 
    changetopstick3();

    moveto3(topstick1);         //Çubuk1 den Çubuk3'e 
    changetopstick1();

    moveto1(topstick2);         //Çubuk2 den Çubuk1'e 
    changetopstick2();

    moveto3(topstick2);         //Çubuk2 den Çubuk3'e 
    changetopstick2();

    moveto3(topstick1);         //Çubuk1 den Çubuk3'e 
    changetopstick1();

    printstick3();

}
void add_stick1(int number)     //1.çubuğa elemanlarını yığıt şeklinde ekleyen fonksiyon
{
    struct stack *temp =(struct stack *)malloc(sizeof(struct stack));
    temp->data = number;
    temp->next = NULL;
    if(topstick1 != NULL)
    {
        temp->next = topstick1;
    }
    topstick1 = temp;
}
void add_stick2(int number)     //2.çubuğa elemanlarını yığıt şeklinde ekleyen fonksiyon
{
    struct stack *temp =(struct stack *)malloc(sizeof(struct stack));
    temp->data = number;
    temp->next = NULL;
    if(topstick2 != NULL)
    {
        temp->next = topstick2;
    }
    topstick2 = temp;
}
void add_stick3(int number)     //3.çubuğa elemanlarını yığıt şeklinde ekleyen fonksiyon
{
    struct stack *temp =(struct stack *)malloc(sizeof(struct stack));
    temp->data = number;
    temp->next = NULL;
    if(topstick3 != NULL)
    {
        temp->next = topstick3;
    }
    topstick3 = temp;
}
void printstick1()      //1.çubuğun elemanlarını yazdıran fonksiyon
{
    struct stack *temptopstick = NULL;
    temptopstick = topstick1;
    while(temptopstick->next != NULL)
    {
        printf("%d\t",temptopstick->data);
        temptopstick = temptopstick->next;
    }
    printf("%d\t\n",temptopstick->data);
}
void printstick2()      //2.çubuğun elemanlarını yazdıran fonksiyon
{
    struct stack *temptopstick = NULL;
    temptopstick = topstick2;
    while(temptopstick->next != NULL)
    {
        printf("%d\t",temptopstick->data);
        temptopstick = temptopstick->next;
    }
    printf("%d\t\n",temptopstick->data);
}
void printstick3()      //3.çubuğun elemanlarını yazdıran fonksiyon
{
    struct stack *temptopstick = NULL;
    temptopstick = topstick3;
    while(temptopstick->next != NULL)
    {
        printf("%d\t",temptopstick->data);
        temptopstick = temptopstick->next;
    }
    printf("%d\t\n",temptopstick->data);
}
void moveto1(struct stack *topa)        //Herhangi bir çubuğun ilk elemanını 1.çubuğa eklemek isteyeceğimiz zaman kullanılacak fonksiyon
{
    return add_stick1(topa->data);
}
void moveto2(struct stack *topa)        //Herhangi bir çubuğun ilk elemanını 2.çubuğa eklemek isteyeceğimiz zaman kullanılacak fonksiyon
{
    return add_stick2(topa->data);
}
void moveto3(struct stack *topa)        //Herhangi bir çubuğun ilk elemanını 3.çubuğa eklemek isteyeceğimiz zaman kullanılacak fonksiyon
{
    return add_stick3(topa->data);
}
void changetopstick1()                  //1.çubuğun baş elemanını bir sonraki eleman yapar ve eski baş elemanın adresini boşaltır.
{
    struct stack *temp = NULL;
    temp = topstick1;
    topstick1 = topstick1->next;
    free(temp);
}
void changetopstick2()                  //2.çubuğun baş elemanını bir sonraki eleman yapar ve eski baş elemanın adresini boşaltır.
{
    struct stack *temp = NULL;
    temp = topstick2;
    topstick2 = topstick2->next;
    free(temp);
}
void changetopstick3()                  //3.çubuğun baş elemanını bir sonraki eleman yapar ve eski baş elemanın adresini boşaltır.
{
    struct stack *temp = NULL;
    temp = topstick3;
    topstick3 = topstick3->next;
    free(temp);
}