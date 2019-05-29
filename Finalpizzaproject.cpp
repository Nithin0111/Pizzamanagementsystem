#include<iostream.h>
#include<conio.h>    
#include<stdlib.h>
#include<stdio.h>


static int count = (1); //tracks order number;
class base_pizza    //defines basic ingridients
{
protected:      //or they are unaccessible by child class
unsigned int price;
int size;
int capscicum;
int tomatoes;
int mushrooms;
int olives;
int tikka_chicken;
int roast_chicken;
int cheese;


base_pizza()   //constructor to define base prices
    {
    price=0;
    size=60;
    capscicum=50;
    tomatoes=50;
    mushrooms=50;
    olives=50;
    tikka_chicken=70;
    roast_chicken=80;
    cheese=40;
    }


    public:

    int choose_base()   //choose base
    {
    char opt;

    cout<<"\nSelect size of the pizza(S/M/L):\t";
    cin>>opt;

    switch (opt)
        {
        case 's':
        case 'S':
                return 1;

        case 'm':
        case 'M':
                return 2;

        case 'l':
        case 'L':
                return 3;

        default:
                return 1;
        }
    }

    int admin_edit()
        {
        int edit;
        cout<<"\nEnter New value:\t";
        cin>>edit;
        return edit;
        }
};


class customize: public base_pizza //defines customization functions
{
protected:
int serv_capscicum;
int serv_tomatoes;
int serv_mushrooms;
int serv_olives;
int serv_tikka_chicken;
int serv_roast_chicken;
int serv_cheese;
int serv_size;
public:

customize()     //default serving of ingridients
    {
    serv_size=1;
    serv_capscicum=1;
    serv_tomatoes=1;
    serv_mushrooms=1;
    serv_olives=1;
    serv_tikka_chicken=0;
    serv_roast_chicken=0;
    serv_cheese=1;
    }

int choose_serv()   //function to choose serving of each object
    {
    char x;
       //   int serv;
    cin>>x;
    switch (x)
        {
        case 'n':
        case 'N':
                return 0;

        case 's':
        case 'S':
                return 1;

        case 'm':
        case 'M':
                return 2;

        case 'l':
        case 'L':
                return 3;

        default:
                return 1;
        }

     // return serv;
    }

void calc_price()   //calculates price
    {
    int pricet=0;   //0 to avoid junk value
    pricet+=(serv_size)*(size);
    pricet+=(serv_capscicum)*(capscicum);
    pricet+=(serv_tomatoes)*(tomatoes);
    pricet+=(serv_mushrooms)*(mushrooms);
    pricet+=(serv_olives)*(olives);
    pricet+=(serv_tikka_chicken)*(tikka_chicken);
    pricet+=(serv_roast_chicken)*(roast_chicken);
    pricet+=(serv_cheese)*(cheese);
    price=pricet;
    }

int ret_price()
    {
    return price;
    }
void disp_price()   //displays price
    {
    cout<<price;
    }

void edit_base()    //function to edit size of base

    {
    int x;
       //   cout<<"\nEnter the size of the Base: ";
    x=choose_base();
    serv_size=x;
    }

void edit_capscicum()   //function to edit serving of capsicum
    {
    int x;
    cout<<"\nEnter the serving of Capscicum: ";
    x=choose_serv();
    serv_capscicum=x;
    }

void edit_tomatoes()
    {
    int x;
    cout<<"\nEnter the serving of Tomatoes: ";
    x=choose_serv();
    serv_tomatoes=x;
    }

void edit_mushrooms()
    {
    int x;
    cout<<"\nEnter the serving of Mushrooms: ";
    x=choose_serv();
    serv_mushrooms=x;
    }

void edit_olives()
    {
    int x;
    cout<<"\nEnter the serving of Olives: ";
    x=choose_serv();
    serv_olives=x;
    }

void edit_tikka_chicken()
    {
    int x;
    cout<<"\nEnter the serving of Chicken tikka: ";
    x=choose_serv();
    serv_tikka_chicken=x;
    }

void edit_roast_chicken()
    {
    int x;
    cout<<"\nEnter the serving of Roasted Chicken: ";
    x=choose_serv();
    serv_roast_chicken=x;
    }

void edit_cheese()
    {
    int x;
    cout<<"\nEnter the serving of Cheese: ";
    x=choose_serv();
    serv_cheese=x;
    }

};


class veg_extra: public customize
{
void veg_extra1()   //default servs for predefined pizza
    {
    serv_size=1;
    serv_capscicum=2;
    serv_tomatoes=1;
    serv_mushrooms=2;
    serv_olives=2;
    serv_tikka_chicken=0;
    serv_roast_chicken=0;
    serv_cheese=1;
    }
public:
void call() //function to call the private function for servs
    {
    veg_extra1();
    }

};

class nveg_extra: public customize
{
void nveg_extra1()
    {
    serv_size=1;
    serv_capscicum=1;
    serv_tomatoes=1;
    serv_mushrooms=2;
    serv_olives=1;
    serv_tikka_chicken=2;
    serv_roast_chicken=1;
    serv_cheese=1;
    }
public:
void call()
    {
    nveg_extra1();
    }

};

char offers[8][50];
static int ctr=0;   //keeps count of number of offers
int pin=0;
static long int sales=0;//total sales
char adr[80]={"Shop-5,Ground Floor, Unity One Mall, Janakpuri, New Delhi,                 110019"};
char phn[11]={"9818114547"};
char mail[30]={"contact@palacefoods.com"};

class admin: public base_pizza
{

int user[3];
int pass[3];

public:
admin()     //accepted admin logins
    {
    user[0]=123;
    pass[0]=321;
    user[1]=456;
    pass[1]=654;
    user[2]=789;
    pass[2]=987;
    }

int retuser(int i)
    {
    return user[i];
    }
int retpass(int i)
    {
    return pass[i];
    }

void admin_panel()
    {
    int r;

    clrscr();
    cout<<"\t\t\tADMIN PANEL\n";
    cout<<"\nPlease choose an option:";
    cout<<"\n\n\n\t1.Check Total Sales";
    cout<<"\n\n\n\t2.Add Offers";
    cout<<"\n\n\n\t3.Edit Offers";
    cout<<"\n\n\n\t4.Edit Contact options";
    cout<<"\n\n\n\t5.Exit Admin Panel";
    cout<<"\n\n\n\t6.LOGOUT\n";
    cout<<"\n-->> ";
    cin>>r;

    switch(r)
        {
        case 1:
            clrscr();
            cout<<"\n\n\n";
            cout<<"Total sales for the day have been Rs. ";
            cout<<sales;
            getch();
            break;

        case 2:
            clrscr();
            cout<<"Enter the new offer below:\n";
            gets(offers[ctr]);
            cout<<"\n\n\n";
            cout<<"Offer Posted in 'Offers' section.\n";
            ctr++;
            getch();
            break;

        case 3:
            int n;
            clrscr();
            cout<<"Enter the Offer Number to be edited: ";
            cin>>n;
            cout<<endl<<endl;
            n=n-1;
            if(n>=ctr)
                {
                cout<<"\n*No offer found*\n";
                }
            else
                {
                cout<<"\nENTER NEW OFFER BELOW:\n";
                gets(offers[n]);
                cout<<"\n\n***Offers updated***\n";
                }
            getch();
            break;

        case 4:
            int opt,key=1;
            while(key==1)
            {
            clrscr();
            cout<<"Choose an option:\n";
            cout<<"\n1.Edit Phone Number\n";
            cout<<"\n2.Edit Email Adress\n";
            cout<<"\n-->>";
            cin>>opt;

            switch(opt)
                {
                case 1:
                    clrscr();
                    cout<<"\n\n";
                    cout<<"Enter new phone number: ";
                    gets(phn);
                    cout<<"\n\n";
                    cout<<"Phone Number updated";
                    getch();
                    key=0;
                    break;
                case 2:
                    clrscr();
                    cout<<"\n\n";
                    cout<<"Enter new Email: ";
                    gets(mail);
                    cout<<"\n\n";
                    cout<<"Email Adress updated";
                    getch();
                    key=0;
                    break;

                default:
                    key=1;

                }
            }
            break;

        case 5:
            break;

        case 6:
            pin=0;
            break;
        default:
            break;
        }


    }

};

char phno[20][11],addr[20][40];
void get_details()
{
clrscr();
cout<<"Please enter the following details:";
cout<<"\n\n";
cout<<"Your Address : ";
gets(addr[count]);
cout<<"\n\n";
cout<<"Your Phone Number : ";
gets(phno[count]);
cout<<"\n\n";
cout<<"Details successfully entered\n";
getch();
}

void main()
{
int ch,x,y,s,k;

menu:
clrscr();
cout<<"\t\t\t\t------------\n";
cout<<"\t\t\t       *Pizza Palace*";
cout<<"\n\t\t\t\t------------\n";

cout<<"\n\t\t\t  Welcome to Pizza Palace!\n";
cout<<"Order No. : "<<count;
cout<<"\n*Please choose an option from the list:\n";
cout<<"\n\n\t1.Order Now!";
cout<<"\n\n\t2.Offers";
cout<<"\n\n\t3.Contact Us";
cout<<"\n\n\t4.About Us";
cout<<"\n\n\t5.Admin Login";
cout<<"\n\n\t6.EXIT";
cout<<"\n\n--->> ";

cin>>ch;

switch(ch)
    {
    case 1:
        clrscr();
        int ch1;
        cout<<"\nSelect an option to proceed\n";
        cout<<"\n1.Choose from our range of exciting Pizzas!";
        cout<<"\n\n2.Make your own Pizza!";

        choosech1:
        cout<<"\n\n--->> ";
        cin>>ch1;

        switch(ch1)
        {
        case 1:
            int k;
            clrscr();
            cout<<"Which pizza would you like "
            <<"your tastebuds to delight in?\n";
            cout<<"\n1.Veg Extraveganza";
            cout<<"\n2.Non Veg Extraveganza\n";
            cin>>k;

            switch(k)
            {
            case 1:

                veg_extra ob1;
                ob1.call();
                clrscr();
                cout<<"\nYou selected Veg "
                <<"Extraveganza\n";
                cout<<endl;
                ob1.edit_base();
                ob1.calc_price();
                cout<<"\nAmount Due: Rs.";
                ob1.disp_price();
                getch();
                get_details();
                cout<<"\n\t\t\tThank you for"
                <<" ordering\n";
                cout<<"\t\t\tPlease keep Rs. ";
                ob1.disp_price();
                cout<<" ready.";
                cout<<"\n*Your order will arrive"
                <<" in under 45 mins, or its free!";
                cout<<endl;
                count++;
                sales+=ob1.ret_price();
                getch();
                clrscr();
                goto menu;
                 // break;
            case 2:
                nveg_extra ob2;
                ob2.call();
                clrscr();
                cout<<"\nYou selected Non Veg "
                <<"Extraveganza\n";
                cout<<endl;
                ob2.edit_base();
                ob2.calc_price();
                cout<<"\nAmount Due: Rs.";
                ob2.disp_price();
                getch();
                get_details();
                cout<<"\n\t\t\tThank you for"
                <<" ordering\n";
                cout<<"\t\t\tPlease keep Rs. ";
                ob2.disp_price();
                cout<<" ready.";
                cout<<"\n*Your order will arrive"
                <<" in under 45 mins, or its free!";
                cout<<endl;
                count++;
                sales+=ob2.ret_price();
                getch();
                clrscr();
                goto menu;


            default:
                break;
            }



        case 2:
            int r;
            customize ob3;
            editor:
            clrscr();
            cout<<"\t\t\tMake you own pizza!\n";
            cout<<"How to go about it:\n";
            cout<<"\t*Once presented with an"
            <<" ingredient, choose a serving:\n"
            <<"\t\tS - Small\n\t\tM - Medium\n"
            <<"\t\tL - Large\n\t\tN - Skip (remove)\n"
            <<"Once you complete, the final price will"
            <<" be displayed, if you are satisfied "
            <<"you\ncan continue, or you can remake "
            <<"the pizza\n";

            ob3.edit_base();
            ob3.edit_capscicum();
            ob3.edit_tomatoes();
            ob3.edit_mushrooms();
            ob3.edit_olives();
            ob3.edit_tikka_chicken();
            ob3.edit_roast_chicken();
            ob3.edit_cheese();

            ob3.calc_price();

            cout<<"\n\nYour Order sums up at Rs. ";
            ob3.disp_price();

            cout<<"\n\nDo you want to continue, or"
            <<" edit your order?\n"
            <<"\t1.Continue\n"
            <<"\t2.Edit Order\n";

            cin>>r;

            if(r==1)
                {

                }
            else
                {
                goto editor;
                }

            cout<<"\n\n\nYour order sums up to Rs. ";
            ob3.disp_price();
            getch();
            get_details();
            cout<<"\nThank you for ordering\n";
            cout<<"\nPlease keep Rs. ";
            ob3.disp_price();
            cout<<" ready with you.";
            cout<<"\nYour order will arrive under"
            <<" 45 mins, or its free!";
            count++;
            sales+=ob3.ret_price();
            getch();
            clrscr();
            goto menu;

               //   break;
        default:
            goto choosech1;
        }


          //    break;
    case 2:
        clrscr();
        cout<<"\t\t\t\tOFFERS\n";
        for(int i=0; i<ctr; ++i)
            {
            cout<<i+1<<".";
            puts(offers[i]);
            cout<<endl;
            }
        getch();
        break;
    case 3:
        clrscr();
        cout<<"\t\t\t\tCONTACT US";
        cout<<"\n\n\n";
        cout<<"ADDRESS: ";
        puts(adr);
        cout<<endl<<endl<<endl;
        cout<<"Place order on phone:-\n";
        cout<<"\tPhone Number : ";
        cout<<phn;
        cout<<"\n\n";
        cout<<endl<<endl;
        cout<<"Email : ";
        cout<<mail;

        getch();
        break;
    case 4:
        clrscr();
        cout<<"\t\t\t\tAbout\n\n";
        cout<<"This program has been made by Jyotinder "
        <<"Singh and Rachit Jain, of class XII-A as their "
        <<"Computer Science Project for the year 2016-2017.";
        cout<<"\n\n";
        cout<<"Salient features of the program:\n";
        cout<<"\n\t1.User friendly interface."
        <<"\n\n\t2.Dynamic Pricing system - No prefixed prices!"
        <<"\n\n\t3.Prices calculated based on servings you choose for each object."
        <<"\n\n\t4.Each ingridient defined as separate member of the class."
        <<"\n\n\t5.Admin Panel."
        <<"\n\n\t6.Admin can add and edit offers."
        <<"\n\n\t7.Track of total number of orders for that day."
        <<"\n\n\t8.Track of total sales for the day";

        getch();
        break;
    case 5:
        admin log;
        if(pin!=0)
            {
            clrscr();
            cout<<"\nYou are already logged in\n";
            getch();
            log.admin_panel();
            }
        else if(pin==0)
            {
            int id,cred;
            clrscr();
            cout<<"\t\t\tADMIN LOGIN";
            cout<<"\n\n\n";
            cout<<"\t\t\t";
               cout<<"USER ID: ";
            cin>>id;
            for(int i=0;i<3;++i)
                {
                if(id==log.retuser(i))
                    {

                    cout<<"\n\t\t\t";
                    cout<<"PASSWORD: ";
                    cin>>cred;

                    if(cred==log.retpass(i))
                        {
                        pin=1;
                        log.admin_panel();
                        }
                    else
                        {
                        cout<<"\n\t\t\t";
                        cout<<"Password "
                        <<"doesn't match\n";
                        getch();
                        goto menu;
                         // break;
                        }

                    }
                else
                    {
                    continue;
                    }
                }


            }
        goto menu;
         // break;
    case 6:
        exit(0);

    default:
        break;
    }


goto menu;
   //   getch();
}
