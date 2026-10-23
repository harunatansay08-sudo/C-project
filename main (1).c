
#include <stdio.h>

int main()
{
    int accessresult;

    int age;
    printf("tell me your age\n");
    scanf("%d", &age);

    int vip;
    printf("do you have a VIP pass? 1 = yes / 0 = no\n");
    scanf("%d", &vip);

    int ticket;
    printf("do you have a ticket? 1 for yes 0 for no\n");
    scanf("%d", &ticket);

    int banned;
    printf("are you banned? 1 for yes 0 for no\n");
    scanf("%d", &banned);

    int student;
    printf("are you a student? 1 for yes 0 for no\n");
    scanf("%d", &student);

    int money;
    printf("how much money do you have\n");
    scanf("%d", &money);


    /* PART 2 - ACCESS CONTROL */

    if (banned == 1) {
        printf("get out of here.\n");
        accessresult = 0;
    }

    else if (ticket == 0 && vip == 0) {
        printf("You need a ticket or VIP pass.\n");
        accessresult = 0;
    }

    else if (age < 13) {
        printf("too young\n");
        accessresult = 0;
    }

    else {
        accessresult = 1;

        if (age >= 65) {
            printf("SENIOR ACCESS\n");
        }

        else if (age >= 18) {
            printf("ADULT ACCESS\n");
        }

        else {
            printf("TEEN ACCESS\n");
        }
    }


    /* PART 4 - PRICE */

    int price = 100;

    if (age >= 65) {
        price -= 30;
    }

    if (vip == 1) {
        price -= 25;
    }

    if (student == 1) {
        price -= 20;
    }


    /* PART 5 - DAY DISCOUNT */

    int day;

    printf("in a numerical way. Whats the number of the day?\n");
    scanf("%d", &day);

    if (day % 2 == 0) {
        price -= 5;
        printf("hey! its a lucky day! 5 dollar discount!!\n");
    }


    /* PART 6 - PAYMENT */

    int paymentresult;

    if (money > price) {
        printf("Making the purchase\n");

        paymentresult = 1;

        money -= price;

        printf("remaining money left is %d\n", money);
    }

    else if (money == price) {
        printf("making the purchase\n");

        paymentresult = 1;

        money -= price;

        printf("remaining money is none\n");
    }

    else {
        int shortage = price - money;

        paymentresult = 0;

        printf("Couldnt make the purchase. Sorry, but you need %d more dollars\n",
               shortage);
    }


    /* PART 7 - FINAL SUMMARY */

    printf("\n");
    printf("SUMMARY OF ALL INFORMATION\n");
    printf("--------------------------\n");

    printf("AGE: %d\n", age);
    printf("VIP AVAILABILITY: %d\n", vip);
    printf("STUDENT AVAILABILITY: %d\n", student);
    printf("TICKET AVAILABILITY: %d\n", ticket);
    printf("FINAL PRICE: %d\n", price);
    printf("ACCESS RESULT: %d\n", accessresult);
    printf("PAYMENT RESULT: %d\n", paymentresult);

    if (paymentresult == 1) {
        printf("PAYMENT SUCCESS\n");
        printf("EXCESS MONEY: %d\n", money);
    }

    else {
        printf("PAYMENT DENIED\n");
    }
    return 0;
}