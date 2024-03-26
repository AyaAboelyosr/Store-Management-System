#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
typedef struct  category  category;
typedef struct  product  product;
typedef struct  store  store;
struct product
{
    char proname[20];
    int quantity;
    int price;
};


struct category
{
    char catname[20];
    product products[20];
    int procount;
};
struct store
{
    category categories[20];
    int catcount;
};


void createCategory(store *s)
{


    char key;
    do
    {

        if (s->catcount < 20)
        {
            SetColor(17);
            printf("Enter name of category: ");
            SetColor(15);
            char name[20];
            scanf("%s", name);
            strcpy(s->categories[s->catcount].catname,name);
            s->categories[s->catcount].procount = 0;
            s->catcount++;

        }
        else
        {  SetColor(12);
            printf("No storage for more categories.\n");
        }
        SetColor(25);
        printf("Do you want to add catagory? y/n \n");
        key = getch();

    }
    while(key=='y'||key=='Y');
}
void createProdact( store*s)
{
    char pname[20];
    char cname[20];
    int price,quantity;
    int findindexcat=-1;


    char key;
    do
    {



        if(s->categories->procount<20)
        {
            SetColor(17);

            printf(" Enter name of product \n" );
            SetColor(15);
            scanf("%s",pname);
            SetColor(17);
            printf(" Enter name of catagory  \n" );
            SetColor(15);
            scanf("%s",cname);

            for(int i=0 ; i<s->catcount; i++)
            {
                if (strcmp(s->categories[i].catname,cname) == 0)
                {
                    findindexcat = i;
                    break;

                }
            }


            if (findindexcat != -1)
            {
                if(s->categories[findindexcat].procount<20)
                {
                    strcpy(s->categories[findindexcat].products[s->categories[findindexcat].procount].proname, pname);
                    SetColor(17);
                    printf("Enter Price\n");
                    SetColor(15);
                    scanf("%d",&price);
                    s->categories[findindexcat].products[s->categories[findindexcat].procount].price = price;
                    SetColor(17);
                    printf("Enter quantity ");
                    SetColor(15);
                    scanf("%d",&quantity);
                    s->categories[findindexcat].products[s->categories[findindexcat].procount].quantity = quantity;
                    s->categories[findindexcat].procount++;
                    SetColor(10);
                    printf("product added successfully!! \n");


                }



            }
            else
            {
                 SetColor(12);

                printf("Enter valid category\n");
            }


        }else{
             SetColor(12);
            printf("Out of Storage");
        }
        SetColor(25);
        printf("Do you want to add product? y/n \n");
        key = getch();


    }
    while(key=='y'||key=='Y');

}
void displayCat(store*s)
{

    int catCount=s->catcount;

    for (int i=0; i<catCount; i++)
    {
        int productCount = s->categories[i].procount;
        SetColor(13);
        printf(" The categories are %s \n ",s->categories[i].catname);
        for (int j=0; j<productCount; j++)
        {
            SetColor(17);

            printf("The products are : %s | price : %d |quantity :%d  \n",s->categories[i].products[j].proname,s->categories[i].products[j].price,s->categories[i].products[j].quantity);
        }
    }
}
void removeProduct(store*s)
{
    char pname[20];
    char cname[20];
    int price,quantity;
    int findindexcat=-1;
    int findindexpro=-1;
    char key;
    do
    {
        SetColor(17);
        printf(" Enter name of product \n" );
        SetColor(15);
        scanf("%s",pname);
        SetColor(17);
        printf(" Enter name of catagory  \n" );
        SetColor(15);
        scanf("%s",cname);
        for(int i=0; i<s->catcount; i++)
        {
            if(strcmp(s->categories[i].catname,cname) == 0)
            {
                findindexcat=i;
                break;


            }
        }
        if( findindexcat !=-1)
        {

            for(int i=0; i< s->categories[findindexcat].procount; i++)
            {
                if(strcmp(s->categories[findindexcat].products[i].proname,pname) == 0)
                {
                    findindexpro=i;
                    break;

                }else{
                    SetColor(12);
            printf("Enter valid product \n");

                }


            }


        }else{
             SetColor(12);
            printf("Enter valid category \n");
        }
        if(findindexpro!=0){

        for(int i=findindexpro; i<s->categories[findindexcat].procount; i++)
        {
            s->categories[findindexcat].products[i]= s->categories[findindexcat].products[i+1];
            s->categories[findindexcat].procount--;


        }
        }else{
             SetColor(10);
            printf("product  removed successfully!! \n");
        }
          SetColor(25);

        printf("Do you want to delete product? y/n \n");
        key = getch();


    }
    while(key=='y'||key=='Y');
}
void removeCategory(store*s){
    char cname[20];
     int findindexcat=-1;
      char key;
    do
    {

        SetColor(17);
        printf(" Enter name of catagory  \n" );
        SetColor(15);
        scanf("%s",cname);
        for(int i=0; i<s->catcount; i++)
        {
            if(strcmp(s->categories[i].catname,cname) == 0)
            {
                findindexcat=i;
                break;


            }
        }
        if( findindexcat !=-1)
        {


 for(int i=findindexcat; i<s->catcount; i++)
        {
            s->categories[i]= s->categories[i+1];
             s->catcount--;


        }



        }else{
             SetColor(12);
            printf("Enter valid category \n");
        }

          SetColor(25);

        printf("Do you want to delete product? y/n \n");
        key = getch();


    }
    while(key=='y'||key=='Y');

}
void sell(store*s)
{
    char pname[20];
    char cname[20];
    int quant;
    int price;
    int findindexcat=-1;
    int findindexpro=-1;
    char key;
    do
    {
        SetColor(17);
        printf(" Enter name of product \n" );
        SetColor(15);
        scanf("%s",pname);
        SetColor(17);
        printf(" Enter name of catagory  \n" );
        SetColor(15);

        scanf("%s",cname);
        for(int i=0; i<s->catcount; i++)
        {
            if(strcmp(s->categories[i].catname,cname) == 0)
            {
                findindexcat=i;
                break;


            }else{
                SetColor(12);
                printf("Invalid Catagory");
            }
        }
        if( findindexcat !=-1)
        {

            for(int i=0; i< s->categories[findindexcat].procount; i++)
            {
                if(strcmp(s->categories[findindexcat].products[i].proname,pname) == 0)
                {
                    findindexpro=i;
                    break;

                }else{
                     SetColor(12);
                    printf("Invalid product");
                }



            }


        }
        if(findindexpro !=-1)
        {
            SetColor(17);
            printf("Enter quantity \n");
            SetColor(15);
            scanf("%d",&quant);
            if(quant<s->categories[findindexcat].products[findindexpro].quantity){

            s->categories[findindexcat].products[findindexpro].quantity -=quant;
            SetColor(10);
            printf("selled success \n");

            }else{
                 SetColor(12);

                printf("Enter Less quantity! \n");
                 SetColor(14);
                printf("Enter quantity \n");
            SetColor(15);
            scanf("%d",&quant);
            if(quant<s->categories[findindexcat].products[findindexpro].quantity){

            s->categories[findindexcat].products[findindexpro].quantity -=quant;
            SetColor(10);
            printf("selled success \n");

            }
            }



        }
        SetColor(25);

        printf("Do you want to sell product? y/n \n");
        key = getch();



    }
    while(key=='y'||key=='Y');

}
void move(store*s){
    char cname[20];
    char pname[20];
    char sourcename[20];
    char Destname[20];
    int sourceindexcat= -1;
    int destindex=-1;
    int destindexpro=-1;
     int findindexpro=-1;
      int findindexcat=-1;
       char key;
       do{
           SetColor(17);
    printf("Move procuct from catagery  \n");
     SetColor(15);
    scanf("%s",sourcename);
     for(int i=0;i<s->catcount;i++){
        if(strcmp(s->categories[i].catname,sourcename) == 0){
                sourceindexcat=i;
                 break;
}
     }
     if(sourceindexcat!=-1){
             SetColor(17);
            printf(" Enter name of product \n" );
            SetColor(15);
            scanf("%s",pname);
            for(int i=0;i<s->categories[sourceindexcat].procount;i++){
                     if(strcmp(s->categories[sourceindexcat].products[i].proname,pname) == 0){
                            findindexpro=i;
                             break;

                    }


            }
     }else{
          SetColor(12);
         printf("Enter Valid category /n");

     }
            if( findindexpro !=-1){
                     SetColor(17);
                    printf("Move to catagery : \n");
                     SetColor(15);
                    scanf("%s",Destname);

                     for(int i=0;i<s->catcount;i++){
            if(strcmp(s->categories[i].catname,Destname) == 0){
                destindex=i;
                 break;
}
     }
            }


       if(destindex !=-1){


            s->categories[destindex].products[s->categories[destindex].procount]=
            s->categories[sourceindexcat].products[findindexpro];
       s->categories[destindex].procount++;
       }





       for(int i =sourceindexcat;i<s->catcount-1;i++){
        s->categories[sourceindexcat].products[i+1];
       }
       s->categories[sourceindexcat].procount--;
                            SetColor(25);

        printf("Do you want to move product? y/n \n");
        key = getch();








}while((key=='y'||key=='Y'));

}










void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void displayMenu(int selected)
{
    for(int i=1; i<8; i++)
    {

        if (i == selected)
        {

            SetColor(17);

        }
        else
        {
            SetColor(15);
        }


        switch(i)
        {
        case 1:
            printf("1-Add Catagory \n");
            break;
        case 2:
            printf("2-Add Product \n");
            break;
        case 3:
            printf("3-Display \n");
            break;
        case 4:
            printf("4-Remove Product \n");
            break;
        case 5:
            printf("5-sell Product \n");
            break;
        case 6:
            printf("6-Move product \n");
            break;
        case 7:
            printf("7-Remove Category");
            break;

        }
    }

}


int main()
{
    store s1;
    s1.catcount=0;



    int selected=1;


    while(1)
    {
        system("cls");
        displayMenu(selected);
        char key = getch();

        switch(key)
        {

        case 72:
            if(selected>1)
            {
                selected--;
            }

            break;
        case 80:
            if(selected<7)
            {
                selected++;
            }
            else if(selected=7)
            {
                selected=1;

            }
            break;

        case 13:
            if(selected==1)
            {


                system("cls");

                createCategory(&s1);

                //key = getch();
                break;
            }
            else if(selected==2)
            {
                system("cls");
                createProdact(&s1);


                break;

            }
            else if(selected==3)
            {

                system("cls");
                displayCat(&s1);
                key = getch();
                break;


            }
            else if(selected==4)
            {
                system("cls");
                removeProduct(&s1);
                //exit(0);
                break;
            }
            else if(selected==5)
            {
                system("cls");
                sell(&s1);


            }else if(selected==6){
                system("cls");
                move(&s1);


            }else{
                  system("cls");
                  removeCategory(&s1);


            }


        }







    }


    return 0;
}
