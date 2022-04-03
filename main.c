//  Created by Afiq Hafiz on 02/04/2022.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void header(void);
int seatType(int, int);
int computeTotalPrice(float, float, float, float);

int main()
{
    char name[20], movie[20];
    int seat, totalquantity=0, quantity=0, standardqty=0, luxeqty=0, preferqty=0, childqty=0, repeat, changemovie, i;
    float totalprice=0, standardprice=0, luxeprice=0, preferprice=0, childprice=0, tax=0, discount=0, pay;
    
    do {
        header();
        
        printf("Welcome to LLM Movie Corporation!\n");
        printf("Please enter your name: ");
        fgets(name, 20, stdin);
        for(i=0; name[i]!='\0'; i++)
            {
                /*
                 * If current character is lowercase alphabet then
                 * convert it to uppercase.
                 */
                if(name[i]>='a' && name[i]<='z')
                {
                    name[i] = name[i] - 32;
                }
            }
        printf("Please enter movie title: ");
        fgets(movie, 20, stdin);
        for(i=0; movie[i]!='\0'; i++)
            {
                /*
                 * If current character is lowercase alphabet then
                 * convert it to uppercase.
                 */
                if(movie[i]>='a' && movie[i]<='z')
                {
                    movie[i] = movie[i] - 32;
                }
            }
        
        do {
            printf("Please enter seat type (Choose 1-4): ");
            scanf("%d", &seat);
            
            while (seat > 4) {
                printf("This seat type is unavailable. Please try again.\n\n");
                header();
                printf("Please enter seat type (Choose 1-4): ");
                scanf("%d", &seat);
            }
            
            printf("\nPlease enter the quantity of tickets: ");
            scanf("%d", &quantity);
            
            totalquantity = totalquantity + quantity;
            
            if (seat == 1)
            {
                printf("You have chosen Standard seat.");
                standardqty=quantity;
                standardprice=seatType(seat, quantity);
            }
            else if (seat == 2)
            {
                printf("You have chosen Preferred seat.");
                preferqty=quantity;
                preferprice=seatType(seat, quantity);
            }
            else if (seat == 3)
            {
                printf("You have chosen LUXE seat.");
                luxeqty=quantity;
                luxeprice=seatType(seat, quantity);
            }
            else if (seat == 4)
            {
                printf("You have chosen Child seat.");
                childqty=quantity;
                childprice=seatType(seat, quantity);
            }
            
            printf("Do you want to add more seat?\n");
            printf("1- YES\n");
            printf("2- NO\n");
            scanf("%d",&repeat);
            
        } while (repeat == 1);
        
        totalprice = computeTotalPrice(standardprice, preferprice, luxeprice, childprice);
        
        printf("Do you want to changemovie?\n");
        printf("1- YES\n");
        printf("2- NO\n");
        scanf("%d",&changemovie);
    } while (changemovie == 1);
    
    printf("Hello %s. You have selected the movie of %s\n",name, movie);
    printf("Movie Ticket Details:");
    printf("Quantity \t Type \t Amount, RM \t\n");
    printf("======================================================\n");
    if (standardqty > 0) {
        printf("%d \t STANDARD %f\n",standardqty,standardprice);
    }
    
    if (preferqty > 0){
        printf("%d \t PREFERED %f\n",preferqty,preferprice);
    }
    
    if (luxeqty > 0){
        printf("%d \t LUXE %f\n",luxeqty,luxeprice);
    }
    
    if (childqty > 0){
        printf("%d \t CHILD %f\n",childqty,childprice);
    }
    printf("======================================================\n");
    
    printf("The total amount is %f \n", totalprice);
    tax = totalprice * 6 / 100;
    printf("Plus Service Tax %f\n", tax);
    totalprice = totalprice + tax;
    printf("Your Grand Total is %f\n", totalprice);
    
    if (totalprice > 80) {
        discount = totalprice * 10 / 100;
        printf("You have spent more than RM80. Discount 10 RM %f \n", discount);
    }
    totalprice = totalprice - discount;
    printf("Please pay RM %f NETT \n \n", totalprice);
    
    while (totalprice > 0) {
        printf("Your payment is RM");
        scanf("%f", &pay);
        totalprice = totalprice - pay;
        if (totalprice > 0) {
            printf("Please pay RM %f NETT \n \n", totalprice);
        }
    }
    
    if (totalprice <= 0) {
        totalprice = totalprice * -1;
    }
    
    printf("Your outstanding balance is RM %f\n", totalprice);
    printf("Thank you and enjoy your movie with LLM Cinema Corporation\n");
    
    return 0;
}

int seatType(int type, int qty)
{
    float price=0;
    
    
    if (type == 1)
    {
        price = 15 * qty;
    }
    else if (type == 2)
    {
        price = 18 * qty;
    }
    else if (type == 3)
    {
        price = 20 * qty;
    }
    else if (type == 4)
    {
        price = 8 * qty;
    }
    
    return price;
}

int computeTotalPrice (float stand, float prefer, float luxe, float child){
    float grandAmount;
    
    grandAmount = stand + prefer + luxe + child;
    
    return grandAmount;
}
void header(void)
{
    printf("=================================================\n");
    printf("NO.\t||Seat Type\t||Price per unit, RM");
    printf("\t| \n");
    printf("=================================================\n");
    printf("1.\t||Standard\t||\t15\t");
    printf("\t| \n");
    printf("=================================================\n");
    printf("2.\t||Preferred\t||\t18");
    printf("\t\t| \n");
    printf("=================================================\n");
    printf("3.\t||LUXE\t\t||\t20");
    printf("\t\t| \n");
    printf("=================================================\n");
    printf("4.\t||Child\t\t||\t8");
    printf("\t\t| \n");
    printf("=================================================\n");
}

