//bank managmant.
#include<fstream.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<process.h>
void background();
void deposit_withdraw(int);
void deposit_withdraw(int);
void display_status();
void delete_account();
void modify_account();
void display_all();
void box(int,int,int,int);
void welcome();
void list();
void menu(int);
void list()
{
textbackground(BLACK);
gotoxy(32,8); cprintf("Create Account");
gotoxy(32,10); cprintf("Deposit Amount");
gotoxy(32,12); cprintf("Withdraw Amount");
gotoxy(32,14); cprintf("Know A/C Status");
gotoxy(32,16); cprintf("Close An Account");
gotoxy(32,18); cprintf("Update An Account");
gotoxy(32,20); cprintf("View All Account");
gotoxy(32,22); cprintf("Exit");
//box(10,4,70,30);
}

void menu(int a){

	  box(33,2,45,4);
	  gotoxy(34,3);
	  textcolor(BLUE);
	 cprintf("Main Menu");

	    gotoxy(5,6);
	    textcolor(10);
	    cprintf("");

	     gotoxy(5,24);
	     textcolor(10);
	    cprintf("");
	    textcolor(WHITE);
if (a==1)
       {
	   list();
	gotoxy(32,8);
	textcolor(10);
	textbackground(16);
	cprintf("  Create Account");
	textbackground(BLACK);
	}

   if(a==2)
   {
   list();
   gotoxy(32,10);
   textbackground(16);
   textcolor(10);
   cprintf("  Deposit Amount");
   textbackground(BLACK);
   }
    if(a==3)
   {
   list();
   gotoxy(32,12);
   textbackground(16);
   textcolor(10);
   cprintf("  Withdraw Amount");
   textbackground(BLACK);
   }
     if(a==4)
   {
   list();
   gotoxy(32,14);
   textbackground(16);
   textcolor(10);
   cprintf("  Know A/C Status");
   textbackground(BLACK);
   }
     if(a==5)
   {
   list();
   gotoxy(32,16);
   textbackground(16);
   textcolor(10);
   cprintf("  Close An Account");
   textbackground(BLACK);
   }
     if(a==6)
   {
  list();
   gotoxy(32,18);
   textbackground(16);
   textcolor(10);
   cprintf("  Update An Account");
   textbackground(BLACK);
   }
     if(a==7)
   {
   list();
   gotoxy(32,20);
   textbackground(16);
   textcolor(10);
   cprintf("  View All Accounts");
   textbackground(BLACK);
   }
     if(a==8)
   {
   list();
   gotoxy(32,22);
   textbackground(16);
   textcolor(10);
   cprintf("  Exit");
   textbackground(BLACK);
   }

}
void box(int x1, int y1, int x2, int y2) {
    int i;
    textcolor(WHITE);
    textbackground(BLACK);
    gotoxy(x1,y1); cprintf("%c",201);
     gotoxy(x2,y1); cprintf("%c",187);
      gotoxy(x1,y2); cprintf("%c",200);
       gotoxy(x2,y2); cprintf("%c",188);
	for(i=y1+1;i<y2;i++)
	{

	gotoxy(x1,i);cprintf("%c",186);
	gotoxy(x2,i);cprintf("%c",186);
	  }
	  for(i=x1+1;i<x2;i++)
	  {
		gotoxy(i,y1);cprintf("%c",205);
	gotoxy(i,y2);cprintf("%c",205);
	}
}


class account
{
int acno, deposit, withdraw;
char name[50];
char type;
public:
void create_account();
void show_account()
{
box(25,2,50,3);
gotoxy(32,2);
textcolor(BLUE);
cprintf("Account Status");
gotoxy(20,9);
textcolor(YELLOW);
cprintf("A\C Number:");
gotoxy(38,9);
textbackground(BLUE);
cprintf("     %d        ",acno);
textbackground(BLACK);
//
gotoxy(20,12);
textcolor(YELLOW);
cprintf("A\C Holder Name:");
gotoxy(38,12);
textbackground(BLUE);
cprintf("     %s        ",name);
textbackground(BLACK);
//

gotoxy(20,15);
textcolor(YELLOW);
cprintf("Balance Amount:");
gotoxy(38,15);
textbackground(BLUE);
cprintf("     %d        ",deposit);
textbackground(BLACK);
gotoxy(12,23);
textcolor(YELLOW+BLINK);
cprintf("*-Press nay key to continoue-*");

}
void modify_account()
{
	box(25,2,50,3);
			gotoxy(32,2);
			textcolor(BLUE);
			cprintf("Update Account");
			gotoxy(25,6);
			textcolor(YELLOW);
			cprintf("Your a/c No :");
			gotoxy(41,6);
			textbackground(BLUE);
			cprintf("  %d  ",acno);
			textbackground(BLACK);
			gotoxy(4,9);
			textcolor(YELLOW);
			textbackground(BLACK);
			cprintf("-------------*------------Enter New Details------------*--------------");
			gotoxy(22,12);
			textcolor(YELLOW);

			 cprintf("Modify Account Holder Name : ");
		       gotoxy(50,12);
		       textbackground(BLUE);

			 cprintf("      ");
			  gotoxy(50,12);
			  textbackground(BLACK);
			  textcolor(WHITE);
			   gets(name);

			   gotoxy(22,15);
			   textcolor(YELLOW);
			 cprintf("Modify Balance amount      : ");
		    gotoxy(50,15);
				  textbackground(BLUE);
			  cprintf("      ");
		   gotoxy(50,15);
			textcolor(WHITE);
			textbackground(BLACK);
			   cin>>deposit;

}


void dep(int x)
{
deposit+=x;
}
void draw(int x)
{
 deposit-=x;
}

int retacno()
{
return acno;
}
float retdeposit()
{
return deposit;
}
void report()
{
gotoxy(8,13); cout<<acno<<"\t\t"<<name<<"\t\t"    <<deposit<<endl;
}

};       //class end.


// 	global declaration for stream object, object

fstream fp;
account ac;
void start()
{
char ch;
int a=1,x,y;
do
{
clrscr();
menu(a);
while(1)
 {
ch=getch();
if(ch==0)
{
   ch=getch();
 if(ch==72)
 {
    if(a>1)
    {
      a--;
      clrscr();
      menu(a);
 }   }

 else if(ch==80)
   {
      if(a<8)
      {
       a++;clrscr();menu(a);
       }
   }
 }

  if(ch==13)
       break;
 }
  switch(a)
   {
   case 1: ac.create_account(); break;
   case 2: deposit_withdraw(1); break;
   case 3: deposit_withdraw(2); break;
   case 4: display_status(); break;
   case 5: delete_account(); break;
   case 6: modify_account(); break;
   case 7: display_all(); break;
   case 8: clrscr();gotoxy(25,9);textcolor(YELLOW); cprintf("thanks for use!");
	gotoxy(30,12);
	cout<<"LOADING....";
	int u=0;
	for(int i=1;i<=10;i++)
	{
		gotoxy(30+u,13);
		delay(300);
		cout<<"лл";
		u=u+2;
		gotoxy(52,13);
		cout<<i<<"0%";
	}
	gotoxy(35,14);
	cout<<"COMPLETE ";
	delay(200);
	cout<<"!";
	delay(200);
	cout<<"!";
	delay(300);
	gotoxy(50,22);
	cout<<"Press Any Key To Exit";

    getch(); exit(0); break;
   default : cout<<"invalid";getch();

 }
   clrscr();
   }
   while(1);
}
void account::create_account()
{
account ac2;
fstream fp2;
int temp;
clrscr();
box(25,2,50,3);
gotoxy(32,2);
textcolor(BLUE);
cprintf("New Account");
gotoxy(20,9);
textcolor(YELLOW);
cprintf("Enter A\C Number:");
gotoxy(45,9);
textbackground(BLUE);
cprintf("         ");
gotoxy(45,9);
textcolor(WHITE);
cin>>acno;
fp2.open("account.dat",ios::in);
fp.open("account.dat",ios::out|ios::app);
while(!fp2.eof())
{
 fp2.read((char*)&ac2,sizeof(ac2));
 if(ac2.retacno()==acno)
 {

gotoxy(12,11);
textcolor(YELLOW);
textbackground(BLACK);
cprintf("A\C Number Already created:");
gotoxy(45,15);
textbackground(RED);
textcolor(WHITE);
cprintf(" Try Again ");
gotoxy(49,15);
textbackground(BLACK);
temp=getch();
  if(temp==13){clrscr();start();break;}
  else{ exit(0);}

 }

}    //end of while loop.
textcolor(YELLOW);
gotoxy(20,11);
textbackground(BLACK);
cprintf("Enter A/c Holder Name : ");
gotoxy(45,11);
textbackground(BLUE);
cprintf("       ");
gotoxy(45,11);
textcolor(WHITE);
gets(name);

textcolor(YELLOW);
gotoxy(20,13);
textbackground(BLACK);
cprintf("Enter Intial Amount $500: ");
gotoxy(45,13);
textbackground(BLUE);
cprintf("       ");
gotoxy(45,13);
textcolor(WHITE);
cin>>deposit;

fp.write((char*)&ac,sizeof(ac));

gotoxy(23,16);textcolor(YELLOW); textbackground(BLACK);
cprintf("Account Created Successfully ..");
gotoxy(39,25);textcolor(YELLOW+BLINK); textbackground(BLACK);
cprintf("-* Press Any Key To Continoue*-");

getch();

fp.close();
}//end of fun.

//function for introduction
void welcome()
{
char pass[15],password[15]="aditya";
int i2 =-1;
clrscr();
int i,gd=DETECT,gm;
char t;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
setcolor(GREEN);
 settextstyle(10,0,4);
outtextxy(110,60,"Password Login");

settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy (177,190,"Password :");
gotoxy(43,13);cout<<" ";
//gets(pass);
do{
i2+=1;
pass[i2]=getch();
textcolor(GREEN);
settextstyle(5,0,2);
outtextxy(340+i2*14,185,"*");
}
while(pass[i2]!=13);
pass[i2] =NULL;
if(strcmp(pass,password)==0)
{
cleardevice();
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
setcolor(WHITE);
for(i=190;i<400;i++)
{
line (i,200,i,215);
}
for(i=190;i<400;i++)
{
setcolor(GREEN);
line(i,200,i,215);
delay (10);
setcolor(WHITE);
settextstyle(DEFAULT_FONT,0,1);
outtextxy(190,220,"Loging");
delay(10);
setcolor(rand()%16);
settextstyle(SMALL_FONT,0,7);
outtextxy(245,212,"...");
delay(10);
}
setcolor(GREEN);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy (177,260,"Password Match!");
outtextxy(200,360,"Press any key to continoue:");
getch();

	cleardevice();

	while(!kbhit())
	{
	setcolor(YELLOW);
	settextstyle(GOTHIC_FONT,0,5);
	outtextxy(95,20,"Bank Managmant System");
	   setcolor(GREEN);
	   settextstyle(GOTHIC_FONT,0,4);
	outtextxy(95,170,"Developed By   :");
	outtextxy(380,170,"Aditya Kumar");
	 outtextxy(95,300,"Special Thanks  :");
	  outtextxy(380,300,"Ankit Sir");
	  setcolor(YELLOW+BLINK);
	   settextstyle(GOTHIC_FONT,0,2);
	 outtextxy(160,420,"*-Press Any Key To Continue-*");
      putpixel(rand()%630,rand()%540,rand()%16);
	}
	cleardevice();
	closegraph();
	getch();
}

else
{
settextstyle(8,0,1);
outtextxy(180,250,"Wrong password");
again:
settextstyle(4,0,1);
outtextxy(180,380,"Press(1) to try again.press(2) for exit.");

t=getch();
if(t=='1')
{
cleardevice();
welcome();
}
else if(t=='2')
{
cleardevice();
exit(0);
}
else
{
cleardevice();
settextstyle(4,0,3);
outtextxy(180,320,"Invalid Choice!");
outtextxy(160,390,"Press Any Key To Continoue.");
getch();
cleardevice();
goto again;
}
}
}

void display_status()
{
clrscr();

int n;

 box(25,2,50,3);
gotoxy(32,2);
textcolor(BLUE);
cprintf("Account Status");

textcolor(YELLOW);
gotoxy(22,9);
cprintf("Enter A\C Number:");
gotoxy(38,9);
textbackground(BLUE);
cprintf("       ");
gotoxy(38,9);
	cin>>n;
	int flag=0;
	fp.open("account.dat",ios::in);
	while(fp.read((char*)&ac,sizeof(account)))
	{
		if(ac.retacno()==n)
		{

			ac.show_account();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	{
		gotoxy(12,13);
		textcolor(YELLOW);
			textbackground(BLACK);
		cprintf("Account Number does not exist\n");

		 gotoxy(23,19);
		   textcolor(YELLOW+BLINK);
		 cprintf("*-Press Any Key To Continue-*");

	}
	getch();
}

// 	function to modify record of file
void modify_account()
{
	clrscr();

	int no,found=0;

       box(25,2,50,3);
	gotoxy(32,2);
	textcolor(BLUE);
	cprintf("Update Account");
	gotoxy(20,9);
       textcolor(YELLOW);
	     textbackground(BLACK);
	   cprintf("Enter A\C Number:");
       gotoxy(45,9);
       textbackground(BLUE);
	   cprintf("         ");
       gotoxy(45,9);
       textcolor(WHITE);
	cin>>no;
	textbackground(BLACK);
	fp.open("account.dat",ios::in|ios::out);
	while(fp.read((char*)&ac,sizeof(account)) && found==0)
	{
		if(ac.retacno()==no)
		{
		       clrscr();
			  textbackground(BLUE);
			ac.show_account();
			getch();
			clrscr();
			ac.modify_account();
			int pos=-1*sizeof(ac);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&ac,sizeof(account));
			gotoxy(12,25);textcolor(YELLOW);cprintf("\t Record Updated\n");
			found=1;
		}
	}
	fp.close();
	if(found==0)
	{
		gotoxy(12,18);
		textcolor(YELLOW+BLINK);
		cprintf(" Record Not Found \n");
		gotoxy(12,23);
textcolor(YELLOW);
textbackground(RED);
cprintf("Try Again");
textbackground(BLACK);

	}
	getch();
}

// 	function to delete record of file


void delete_account()
{     	clrscr();
	int no;
	  box(25,2,50,3);
	gotoxy(32,2);
	textcolor(BLUE);
	 cprintf("Close Account");
	gotoxy(20,9);
       textcolor(YELLOW);
	     textbackground(BLACK);
	   cprintf("Enter A\C Number:");
       gotoxy(45,9);
       textbackground(BLUE);
	   cprintf("         ");
       gotoxy(45,9);
       textcolor(WHITE);
	cin>>no;
	textbackground(BLACK);
	fp.open("account.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&ac,sizeof(account)))
	{
		if(ac.retacno()!=no)
		{
			fp2.write((char*)&ac,sizeof(account));
		}
	}
	fp2.close();
	fp.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	gotoxy(12,10);textcolor(YELLOW);cprintf("Record Deleted!\n");
	gotoxy(20,45);textcolor(YELLOW);cprintf("-* Press Any Key To Continoue-*");
	getch();
}


// 	function to deposit and withdraw amounts
void deposit_withdraw(int option)
{
clrscr();
int no,found=0,amt,conf;

  box(25,2,50,3);
	gotoxy(32,2);
	textcolor(BLUE);
	cprintf("Deposit Amount");
	gotoxy(20,9);
       textcolor(YELLOW);
	     textbackground(BLACK);
	   cprintf("Enter A\C Number:");
       gotoxy(45,9);
       textbackground(BLUE);
	   cprintf("        ");
       gotoxy(45,9);
       textcolor(WHITE);
	cin>>no;
	textbackground(BLACK);
fp.open("account.dat",ios::in|ios::out);
while(fp.read((char*)&ac,sizeof(account)) && found==0)
{
if(ac.retacno()==no)
{
ac.show_account();
if(option==1)
{
gotoxy(14,18);
textcolor(YELLOW);
cprintf("Enter Amount To DEPOSIT : ");
 gotoxy(41,18);
 textbackground(BLUE);
 cprintf("     ");
 textcolor(WHITE);
 textbackground(BLACK);
 gotoxy(41,18);
cin>>amt;
gotoxy(14,20);
textcolor(YELLOW);
cprintf("1.Conform");
gotoxy(26,21);
textbackground(BLUE);
cprintf("  ");
textbackground(BLACK);
gotoxy(14,22);
textcolor(YELLOW);
cprintf("2.Deny");
gotoxy(26,21);
textcolor(WHITE);
cin>>conf;
if(conf==1)
{
ac.dep(amt);
gotoxy(16,25);
textcolor(YELLOW);
cprintf("Deposit Succesfully:");
}
else
{
clrscr();
start();
}
}
if(option==2)
{

gotoxy(14,18);
textcolor(YELLOW);
cprintf("Enter Amount To Withdraw: ");
 gotoxy(41,18);
 textbackground(BLUE);
 cprintf("     ");
 textcolor(WHITE);
 textbackground(BLACK);
 gotoxy(41,18);
cin>>amt;
int bal=ac.retdeposit()-amt;
if(bal<500 || amt>bal) {
textcolor(YELLOW);
cprintf("\n!!!Insufficient balance!!!");      }
else {
ac.draw(amt);
gotoxy(15,35);
textcolor(YELLOW);
cprintf("Withdraw Succesfully."); }
}
int pos=-1*sizeof(ac);
fp.seekp(pos,ios::cur);
 fp.write((char*)&ac,sizeof(account));
 found=1;
 }
  }
  fp.close();
 if(found==0)
 {
 gotoxy(12,10); textcolor(YELLOW);
    cprintf(" Record Not Found \n");
  }
  getch();
}

void display_all()
{
clrscr();
fp.open("account.dat",ios::in,ios::binary);
if(!fp)
{
 gotoxy(12,5);textcolor(RED+BLINK);cprintf("ERROR!! File can't open");
 getch();
}
else
{
	box(25,2,58,3);
	gotoxy(32,2);textcolor(BLUE);
	cprintf("Account Holders List");

	gotoxy(8,7);textcolor(BLUE);cprintf("");
	gotoxy(8,9);textcolor(10);cprintf("A/c no");
	gotoxy(23,9);textcolor(10);cprintf("Name");
       gotoxy(38,9);textcolor(10);cprintf("Balance");
	gotoxy(8,11);textcolor(BLUE);textbackground(BLACK);cprintf("\n");
fp.read((char*)&ac,sizeof(account));
while(!fp.eof())
{
ac.report();
gotoxy(25,17);
textcolor(YELLOW);
cprintf("press enter to next record.");
getch();
fp.read((char*)&ac,sizeof(account));
}
fp.close();
gotoxy(12,23);
textcolor(YELLOW+BLINK);
cprintf("*-Press nay key to continoue-*");
getch();
}
}

//     MAIN FUNCTION OF PROGRAM

void main()
{

 welcome();
 start();
}
