#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<windows.h>
#include<mmsystem.h>
using namespace std;
//void sound()
//{
//	PlaySound(TEXT("skdf.wAV"),NULL,SND_SYNC);
//}
// ---------------------- General Function Definations ---------------
int clicked(int i,char click);
void keybord();
void yourpregrassion();
void button(int x1,int y1,int x2,int y2);
void mainfram();
// -------------------- Char Function Definations ----------------
void charbox();
void ch1setdis(int CharNumber);
void ch2setdis(int CharNumber);
void ch3setdis(int CharNumber);
void ch4setdis(int CharNumber);
void ch5setdis(int CharNumber);
void ch6setdis(int CharNumber);
// -------------------- Word Function Definations ----------------
void w1setword(int ind);
void w2setword(int ind);
void w3setword(int ind);
void w4setword(int ind);
void w5setword(int ind);
void w6setword(int ind);
void printchar(char click,int c,int r);
// ----------------------- Global Variables -------------
int Correct_words=0,Wrong_words=0,ind=0,progress=0;
// -------------------- Result Function Definations ----------------
int time1,time2;
int gettime();
void resulttable();
void Result(int x);
// ------------------ Paragraph Function Definations ----------------
int ab=0,col=0;
void writesentence();
void drawinput(char click,int c,int r);
void we();
void is();
void to();
void of();
void it();
void the();
void our();
void out();
void And();
void Not();
void business();
void that();
void unctuality();
void It();
void very();
void setword(int noword);
// ----------------------- Char Function Class/Queue ---------------
class CharByChar
{
	int front;
	int rear;
	char que[4];
	public:
		   CharByChar()
		   {
		   	 front = rear = -1;
		   }
		   void Reset()
		   {
		   	 front = rear = -1;
		   }
		   void enqueue(char x)
		   {
			 if(front==-1&&rear==-1)
			 {
			 	front=rear=0;
			 	que[rear]=x;
			 }
			 else if(rear==3)
			 {
			 	rear=0;
			 }
			 else
			 {
			 	que[++rear]=x;
			 }
		   }
		   char dequeue()
		   {
		   	 char x = que[front];
		   	 if(front==3)
		   	 {
		   	   front=-1;	
			 }
			 front++;
		   	 return x;
		   	}
};
CharByChar ch1,ch2,ch3,ch4,ch5,ch6;
// ----------------------- Word Function Class/Queue ---------------
class ByWord
{
	int front,rear;
	char que[6];
	public:
		ByWord()
		{
		   	front = rear = -1;
		}
		void Reset()
		{
		   	front = rear = -1;
	    }
		void enqueue(char x,int n)
		{
			if(front==-1&&rear==-1)
			{
			 	front=rear=0;
			 	que[rear]=x;
			}
			else if(rear==n-1)
			{
			 	rear=0;
			}
			else
			 {
			 	que[++rear]=x;
			 }
		   }
		   char dequeue(int X)
		   {
		   	 char x = que[front];
		   	 if(front==X-1)
		   	 {
		   	   front=-1;	
			 }
			 front++;
		   	 return x;
		   }
		   void display(int c,int r,int col)
		   {
		   	 char ch[2];
		   	 int C=0;
		   	 if(col==1)
		   	 setcolor(GREEN);
		   	 else
		   	  setcolor(WHITE);
		   	 for(int i=0;i<=rear;i++)
		   	 {	
		   	 	ch[0]=que[i];
		   	 	settextstyle(6,0,4);
		   	 	outtextxy(c+C,r,ch);
		   	 	C+=32;
			 }
		   }
};
ByWord w1,w2,w3,w4,w5,w6;
// --------------------- Paragraph/sentence Function Class/Queue ---------------
class sentence
{
	int front,rear;
	char que[15];
	public:
		sentence()
		{
		   	front = rear = -1;
		}
		void Reset()
		{
		   	front = rear = -1;
	    }
		void enqueue(char x,int n)
		{
			if(front==-1&&rear==-1)
			{
			 	front=rear=0;
			 	que[rear]=x;
			}
			else if(rear==n-1)
			{
			 	rear=0;
			}
			else
			 {
			 	que[++rear]=x;
			 }
		   }
		char dequeue()
		{
		   	 char x = que[front];
		   	 if(front==rear)
		   	 {
		   	   front=-1;	
			 }
			 front++;
		   	 return x;
		}
		string getnextword()
		{
			char word[rear+1];
			int i;
			for(i=0;i<=rear;i++)
			{
				word[i] = que[i];
			}word[i]='\0';
			return word;
		}
		void display(int c,int r,int col)
		{
		   	 char ch[2];
		   	 int C=0;
		   	 if(col==1)
		   	 setcolor(GREEN);
		   	 else
		   	  setcolor(WHITE);
		   	 for(int i=0;i<=rear;i++)
		   	 {	
		   	 	ch[0]=que[i];
		   	 	settextstyle(8,0,1);
		   	 	outtextxy(c+C,r,ch);
		   	 	C+=11;
			 }
		}
};
sentence word;
// ----------------------- Main Typing Master Class ---------------
class Typing_Master
{
	public:
		    void charbychar();
		    void wordbyword();
		    void paragraph();
};
void Typing_Master::charbychar()
{
	Correct_words=Wrong_words=0;
	progress=0;
	time1=0;
	time1 = gettime();
	char click,p1;
	charbox();
    cleardevice();
    keybord();
    mainfram();
	yourpregrassion();
	int CharNumber=1;
	ch1setdis(CharNumber);
	ch2setdis(CharNumber);
	ch3setdis(CharNumber);
	ch4setdis(CharNumber);
	ch5setdis(CharNumber);
	ch6setdis(CharNumber);
	charbox();
    int t=1,r=0;
    int Main=0,qickloop=0;
    while(1)
	{  
        int A=0,B=0,D=0;
		for(int i=1;i<=5;i++)
		{  char ch; 
		    if(t==1)
		     ch = ch1.dequeue();
		    else if(t==2)
		    {
		      ch = ch2.dequeue();
			  D=550;	
			}
		    else if(t==3)
		    {
		      ch = ch3.dequeue();
		      B=150;	
			}
			else if(t==4)
			{
			  ch = ch4.dequeue();
			  D=550;
			  B=150;	
			}
			else if(t==5)
			{
				ch = ch5.dequeue();
				B=300;
			}
			else if(t==6)
			{
				D=550;
				B=300;
				ch = ch6.dequeue();
			} 
			else 
			   break; 
		    setcolor(GREEN);
			rectangle(100+A+D,150+B,160+A+D,200+B);
			do
			{
			  if(i==5)
			  {
//			  	setcolor(WHITE);
			    rectangle(100+A+D,150+B,160+A+D,200+B);
			  }
			  click = getch();
			  if(i==5)
			  {  
				if(click==' ')
				{
					clicked(1,click);
					setcolor(GREEN);
//					setcolor(WHITE);
					rectangle(100+A+65+D,160+B,160+A+65+D,190+B);
					p1=1;
					
				}
				else
				{
					r = clicked(0,click);
				  	p1=0;
				  	setcolor(RED);
				  	rectangle(100+A+65+D,160+B,160+A+65+D,190+B);
				  	if(r==1)
				      break;
				}
			  }
			  else
			  {
				  if(click==ch)
				  {
				  	 p1=1;
				     clicked(1,click);
			         setcolor(GREEN);
//				     setcolor(WHITE);
				    rectangle(100+D+A,150+B,160+A+D,200+B);
				    if(i!=4)
				    A+=65;
				    if(i==4)
				    {
				      setcolor(GREEN);
				      rectangle(100+A+65+D,160+B,160+A+65+D,190+B); 	
					}
				  }	
				  else
				  {
				  	r = clicked(0,click);
				  	p1=0;
				  	setcolor(RED);
				  	rectangle(100+A+D,150+B,160+A+D,200+B);
				  }
				  if(r==1)
				  break;	   
		       }
			  keybord();
			    if(r==1)
				break;
			}while(p1!=1);
			if(r==1)
			break;	
		}
		if(r==1)
		{
           Result(1);
           break;
		}
		t++;
		Main++;
		if(Main==6)
		{
			cleardevice();
			yourpregrassion();
			keybord();
            mainfram();
	        charbox();
			ch1.Reset();
			ch2.Reset();
			ch3.Reset();
			ch4.Reset();
			ch5.Reset();
			ch6.Reset();
			++CharNumber;
			++qickloop;
			ch1setdis(CharNumber);
			ch2setdis(CharNumber);
			ch3setdis(CharNumber);
			ch4setdis(CharNumber);
			ch5setdis(CharNumber);
			ch6setdis(CharNumber);
			Main=0;
			t=1;
		}
		if(qickloop==6)
		{
			Result(1);
			break;
		}
    }
}
void Typing_Master::wordbyword()
{
	progress=0;
	cleardevice();
    keybord();
    mainfram();
	yourpregrassion();
	Correct_words=Wrong_words=0;
	time1=0;
	time1 = gettime();
	keybord();
    mainfram();
    int y=0,Q,r=0;
    char click,ch;
    int I=1,Cont=0;
    int B=0,A=0,D=0,Number=0;
    int NextObject=1,exitloop=0;
    while(1)
    {
    	B=0,A=0;
    	if(NextObject==1)
    	{
    		Q=0;
    	   w1.Reset();
    	   w1setword(++Number);
	       for(int j=0;j<3;j++)
	       {
	     	   w1.display(200+A,160+D,4);
	     	   A+=300;
		    }  	
		}
    	else if(NextObject==2)
    	{
    		Q=1;
    	   w2.Reset();
    	   w2setword(++Number);
	       for(int j=0;j<3;j++)
	       {
	     	   w2.display(200+A,160+D,4);
	     	   A+=300;
		    }  	
		}
		else if(NextObject==3)
    	{
    	   Q=2;
    	   w3.Reset();
    	   w3setword(++Number);
	       for(int j=0;j<3;j++)
	       {
	     	   w3.display(200+A,160+D,4);
	     	   A+=300;
		    }  	
		} 
		else if(NextObject==4)
    	{
    	   Q=3;
    	   w4.Reset();
    	   w4setword(++Number);
	       for(int j=0;j<3;j++)
	       {
	     	   w4.display(200+A,160+D,4);
	     	   A+=300;
		    }  	
		}
		else if(NextObject==5)
    	{
    		Q=2;
    	   w5.Reset();
    	   w5setword(++Number);
	       for(int j=0;j<3;j++)
	       {
	     	   w5.display(200+A,160+D,4);
	     	   A+=300;
		    }  	
		}
		else
    	{
    		Q=1;
    	   w6.Reset();
    	   w6setword(++Number);
	       for(int j=0;j<3;j++)
	       {
	     	   w6.display(200+A,160+D,4);
	     	   A+=300;
		    }  	
		}
		 A=0;
	    while(1)
	    {
	       	if(NextObject==1)
		     w1.display(200+B,160+D,1);
			else if(NextObject==2)
			 w2.display(200+B,160+D,1);
			else if(NextObject==3)
			 w3.display(200+B,160+D,1);
			else if(NextObject==4)
			 w4.display(200+B,160+D,1);
			else if(NextObject==5)
			 w5.display(200+B,160+D,1); 
			else
			  w6.display(200+B,160+D,1);   
	        for(int i=0;i<3+Q;i++)
	        {
	        	if(NextObject==1)
			     ch=w1.dequeue(3);
				else if(NextObject==2)
				 ch=w2.dequeue(4);
				else if(NextObject==3)
				  ch=w3.dequeue(5);
				else if(NextObject==4)
			     ch=w4.dequeue(6);
				else if(NextObject==5)
				 ch=w5.dequeue(5);
				else
				  ch=w6.dequeue(4);
		    	do{
		    		click=getch();  
		    		if(click==ch)
					{
						y=1;
						clicked(1,click);
						printchar(click,200+A+B,160+D);
						outtextxy(200+A+B,160+D,"  ");
					    A+=32;	
					}
					else
					{
						y=0;
						setcolor(RED);
						printchar(ch,200+A+B,160+D);
						r = clicked(0,click);
						if(r==1)
		                break;
					}
					keybord();
					if(r==1)
		              break;
				}while(y!=1);
				if(r==1)
		          break;	
		    }
		    if(r==1)
		       break;
		    B+=300;
		    A=0;
			++Cont;
			if(Cont==3)
			{
              Cont=0;
			  break;	
			}
		}
		D+=200;
		if(Number==3)
		{
			cleardevice();
			keybord();
            mainfram();
			yourpregrassion();
			NextObject++;
			Number=0,D=0;
			++exitloop;
		}
		if(exitloop==6||r==1)
		{
			Result(1);
			break;
		}	
    }
}
void curser(int c,int r)
{
	setcolor(WHITE);
//    if(1)
//    {
      outtextxy(75+c,350+r,"_");
	  outtextxy(75+c,350+r," ");
//	  curser(c,r);	
//	}
}
void Typing_Master::paragraph()
{
	ab=col=0;
	progress=0;
	cleardevice();
    keybord();
    mainfram();
	yourpregrassion();
	Correct_words=Wrong_words=0;
	time1=0;
	time1 = gettime();
	int i,r=0,c=0,t=1,f=0,Tre=0,number=0,first=0,A=0,s,exitloop=0;
    while(1)
    {  
            char click[15];
	    	string temp;
	    	word.Reset();
	    	setword(++number);
	    	if((number+1)%14==0)
	    	{
	    	  yourpregrassion();
			  ++exitloop;	
			}
			writesentence();
	    	word.display(90+ab,120+col,1);
	    do{
	    	s=c;
	    	first=0;
		    for(i=0;i<20;i++)
		    {
		     do{
		          	t=1;
		          	while(!kbhit()){curser(c,r);}
			    	click[i]=getch();
			    	outtextxy(75+c,350+r,"  ");
			    	if(click[i]==27)
			    	break;
			    	if(click[i]==' ')
			    	{
			    	  	c+=11;
			    	  	
			    	  	break;
					}
					if((click[i]>='a'&&click[i]<='z')||(click[i]>='A'&&click[i]<='Z')||click[i]=='.'||click[i]=='/'||click[i]=='\\'||click[i]=='?'||click[i]==8||click[i]==';'||click[i]==':')
					{
						t=1;
						first++;
					}
			    	if(c>=930)
					{
					   	c=0;
						r+=30;	
					}
					if(click[i]==8)
					{
					  	if(i!=0)
					  	{
					  		c-=11;
					  		--i;
						}
					  	t=0;
					  	outtextxy(75+c,350+r," ");
					}
					else
					{
					  	drawinput(click[i],c,r);
			    	    c+=11;
			        }
			    }while(t!=1);
			    if(click[i]==' ')
			     break;
			    if(click[i]==27)
			    {
			    	Tre=1;
			    	first=1111;
			      break;	
				}
			}click[i]='\0';
		if(first==0)
		   Tre=0;
		else
		  Tre=1; 
	    }while(Tre!=1);
		   if(click!=word.getnextword())
		   {
		   	 setcolor(RED);
		   	 c-=11;
		   	 outtextxy(75+s,350+r,click);
		   	 c+=11;
		   	 ++Wrong_words;
		   }
		   else
		   ++Correct_words;
		if(exitloop==6||first==1111)
		{
		   Result(0);
		   break;	
		}		  	
	}
}
void choices(int x1,int y1,int x2,int y2,char st[],int i)
{
	setcolor(WHITE);
	if(i==1)
	 setcolor(GREEN);
    for(int i=1;i>0;i--)
    rectangle(x1+i,y1+i,x2-i,y2-i);
    settextstyle(4,0,2);
    setcolor(6);
    if(i==1)
    setcolor(GREEN);
    outtextxy(520,y1+12,st);
    setcolor(WHITE);
}
void manue(int i)
{
	cleardevice();
	button(400,200,900,800);
	settextstyle(8,0,6);
	setcolor(14);
	outtextxy(500,270,"MAIN MENUE");
	if(i==1)
	{
	  choices(450,400,850,450,"C H A R A C T E R",1);
	  choices(450,400+100,850,450+100,"       W O R D",0);
	  choices(450,400+200,850,450+200,"P A R A G R A P H",0);
	  choices(450,400+300,850,450+300,"         E X I T",0);	
	}
	else if(i==2)
	{
	  choices(450,400,850,450,"C H A R A C T E R",0);
	  choices(450,400+100,850,450+100,"       W O R D",1);
	  choices(450,400+200,850,450+200,"P A R A G R A P H",0);
	  choices(450,400+300,850,450+300,"         E X I T",0);	
	}
	else
	{
	  choices(450,400,850,450,"C H A R A C T E R",0);
	  choices(450,400+100,850,450+100,"       W O R D",0);
	  choices(450,400+200,850,450+200,"P A R A G R A P H",1);
	  choices(450,400+300,850,450+300,"         E X I T",0);	
	}
}
int main()
{
 	initwindow(1300,1000);
	Typing_Master t;
//----------------------------
    int X1=450,Y1=400,X2=850,Y2=450,T=0;;
    char ch;
    manue(1);    
	do
    {
	    ch=getch();
	    if(ch=='P')
	    {
	    	if(Y1==400 && Y2==450)
	    	{
	    		choices(X1,Y1,X2,Y2,"C H A R A C T E R",0);
	    		Y1+=100;
	    	    Y2+=100;
	    	    choices(X1,Y1,X2,Y2,"       W O R D",1);
			}
			else if(Y1==500 && Y2==550)
			{
				choices(X1,Y1,X2,Y2,"       W O R D",0);
				Y1+=100;
	    	    Y2+=100;
	    	    choices(X1,Y1,X2,Y2,"P A R A G R A P H",1);
			}
			else if(Y1==600 && Y2==650) 
			{
	    	    choices(X1,Y1,X2,Y2,"P A R A G R A P H",0);
	    	    Y1=700;
	    	    Y2=750;
				choices(X1,Y1,X2,Y2,"         E X I T",1);
			}
		} 
		if(ch=='H')
		{
		   	if(Y1==700 && Y2==750) 
			{
				choices(X1,Y1,X2,Y2,"         E X I T",0);
	    	    Y1-=100;
	    	    Y2-=100;
	    	    choices(X1,Y1,X2,Y2,"P A R A G R A P H",1);
			}
			else if(Y1==600 && Y2==650)
		    {
				choices(X1,Y1,X2,Y2,"P A R A G R A P H",0);
				Y1-=100;
	    	    Y2-=100;
	    	    choices(X1,Y1,X2,Y2,"       W O R D",1);
			}
			else if(Y1==500 && Y2==550)
		    {
		    	choices(X1,Y1,X2,Y2,"       W O R D",0);
	    		Y1-=100;
	    	    Y2-=100;
	    	    choices(X1,Y1,X2,Y2,"C H A R A C T E R",1);
			}
		} 
	    if(ch==13)
	    {
	    	if(Y1==400 && Y2==450)
	    	{
	    		t.charbychar();
	    		manue(1);
			}
			else if(Y1==500 && Y2==550)
	    	{
	    		t.wordbyword();
	    		manue(2);
			}
			else if(Y1==600 && Y2==650)
			{
				t.paragraph();
				manue(3);
			}
			if(Y1==700 && Y2==750)
			{
				closegraph();
				T=1;
			}
		}
    }while(T!=1);
}
void button(int x1,int y1,int x2,int y2)
{
	rectangle(x1,y1,x2,y2);
	rectangle(x1+5,y1+5,x2-5,y2-5);
	line(x1,y1,x1+5,y1+5);
	line(x2,y2,x2-5,y2-5);
	line(x2,y1,x2-5,y1+5);
	line(x1+5,y2-5,x1,y2);
}
void keybord()
{
	int a=20;
	for(int i=6;i>1;i--)
	{
		setcolor(i%3);
		rectangle(220-i,690-i,910+i,920+i);
	}
	setcolor(WHITE);
	settextstyle(3,0,2);
	outtextxy(268-a,715,"~");
	button(255-a,705,300-a,740);
	outtextxy(315-a,712,"1");
	button(305-a,705,350-a,740);
	outtextxy(368-20,712,"2");
    button(355-a,705,400-a,740);
    outtextxy(418-a,712,"3");
    button(405-a,705,450-a,740);
    outtextxy(468-a,712,"4");
    button(455-a,705,500-a,740);
    outtextxy(518-a,712,"5");
    button(505-a,705,550-a,740);
    outtextxy(568-a,712,"6");
    button(555-a,705,600-a,740);
    outtextxy(618-a,712,"7");
    button(605-a,705,650-a,740);
    outtextxy(668-a,712,"8");
    button(655-a,705,700-a,740);
    outtextxy(718-a,712,"9");
    button(705-a,705,750-a,740);
    outtextxy(768-a,712,"0");
    button(755-a,705,800-a,740);
    settextstyle(3,0,1);
    outtextxy(818-a,712,"Backspace");
    button(805-a,705,920-a,740);
	// first line
	outtextxy(265-a,713+48,"Tab");
	button(255-a,705+50,310-a,740+50);
	outtextxy(330-a,712+50,"Q");
	button(315-a,705+50,360-a,740+50);
	outtextxy(380-a,712+50,"W");
	button(365-a,705+50,410-a,740+50);
	outtextxy(430-a,712+50,"E");
	button(415-a,705+50,460-a,740+50);
	outtextxy(480-a,712+50,"R");
	button(465-a,705+50,510-a,740+50);
	outtextxy(530-a,712+50,"T");
	button(515-a,705+50,560-a,740+50);
	outtextxy(580-a,712+50,"Y");
	button(565-a,705+50,610-a,740+50);
	outtextxy(630-a,712+50,"U");
	button(615-a,705+50,660-a,740+50);
	outtextxy(680-a,712+50,"I");
	button(665-a,705+50,710-a,740+50);
	outtextxy(730-a,712+50,"O");
	button(715-a,705+50,760-a,740+50);
	outtextxy(780-a,712+50,"P");
	button(765-a,705+50,810-a,740+50);
	outtextxy(830-a,712+50,"?");
	button(815-a,705+50,860-a,740+50);
	outtextxy(885-a,711+50,"\\");
	button(865-a,705+50,920-a,740+50);
	// second line
	outtextxy(265-a,713+88,"Cap");
	button(255-a,705+90,310-a,740+90);
	outtextxy(330-a,712+90,"A");
	button(315-a,705+90,360-a,740+90);
	outtextxy(380-a,712+90,"S");
	button(365-a,705+90,410-a,740+90);
	outtextxy(430-a,712+90,"D");
	button(415-a,705+90,460-a,740+90);
	outtextxy(480-a,712+90,"F");
	button(465-a,705+90,510-a,740+90);
	outtextxy(530-a,712+90,"G");
	button(515-a,705+90,560-a,740+90);
	outtextxy(580-a,712+90,"H");
	button(565-a,705+90,610-a,740+90);
	outtextxy(630-a,712+90,"J");
	button(615-a,705+90,660-a,740+90);
	outtextxy(680-a,712+90,"K");
	button(665-a,705+90,710-a,740+90);
	outtextxy(728-a,711+90,"L");
	button(715-a,705+90,760-a,740+90);
	settextstyle(1,0,3);
	outtextxy(778-a,709+90,": ;");
	button(765-a,705+90,820-a,740+90);
	settextstyle(3,0,2);
	outtextxy(855-a,712+90,"Enter");
	button(825-a,705+90,920-a,740+90);
	// THIRD line
	outtextxy(265-a,713+128,"Shift");
	button(255-a,705+130,310-a,740+130);
	outtextxy(330-a,712+130,"Z");
	button(315-a,705+130,360-a,740+130);
	outtextxy(380-a,712+130,"X");
	button(365-a,705+130,410-a,740+130);
	outtextxy(430-a,712+130,"C");
	button(415-a,705+130,460-a,740+130);
	outtextxy(480-a,712+130,"V");
	button(465-a,705+130,510-a,740+130);
	outtextxy(530-a,712+130,"B");
	button(515-a,705+130,560-a,740+130);
	outtextxy(580-a,712+130,"N");
	button(565-a,705+130,610-a,740+130);
	outtextxy(630-a,712+130,"M");
	button(615-a,705+130,660-a,740+130);
	outtextxy(680-a,712+130,"<");
	button(665-a,705+130,705-a,740+130);
	outtextxy(725-a,712+130,">");
	button(710-a,705+130,750-a,740+130);
	outtextxy(770-a,712+130,"/");
	button(755-a,705+130,795-a,740+130);
	outtextxy(830-a,712+130,"S h i f t");
	button(800-a,705+130,920-a,740+130);
	// last row
	outtextxy(265-a,713+168,"C t r l");
	button(255-a,705+170,320-a,740+170);
	button(325-a,705+170,365-a,740+170);
	outtextxy(380-a,713+168,"Alt");
	button(370-a,705+170,415-a,740+170);
	button(420-a,705+170,745-a,740+170);
	outtextxy(770-a,713+168,"A l t");
	button(750-a,705+170,820-a,740+170);
	outtextxy(845-a,713+168,"C t r l");
	button(825-a,705+170,920-a,740+170);
}
int clicked(int i,char click)
{
	int a=20;
	settextstyle(3,0,2);
	if(i==1)
	{
	   setcolor(GREEN);
	   ind = 1;
	   ++Correct_words;	
	}
	else
	{
		++Wrong_words;
		setcolor(RED);
	}
	switch(click)
	{
		case '~':
			      outtextxy(268-a,715,"~");
	              button(255-a,705,300-a,740); break;
		case '1':
			      outtextxy(315-a,712,"1");
				  button(305-a,705,350-a,740); break;
		case '2':
			      outtextxy(368-20,712,"2");
                  button(355-a,705,400-a,740); break;
		case '3':
			      outtextxy(418-a,712,"3");
                  button(405-a,705,450-a,740); break;
	    case '4':
			      outtextxy(468-a,712,"4");
                  button(455-a,705,500-a,740); break;
	    case '5':
			      outtextxy(518-a,712,"5");
                  button(505-a,705,550-a,740); break;
	    case '6':
			      outtextxy(568-a,712,"6");
                  button(555-a,705,600-a,740); break;
		case '7':
			      outtextxy(618-a,712,"7");
                  button(605-a,705,650-a,740); break;
		case '8':
			      outtextxy(668-a,712,"8");
                  button(655-a,705,700-a,740); break;
		case '9':
			      outtextxy(718-a,712,"9");
                  button(705-a,705,750-a,740); break;
		case '0':
			      outtextxy(768-a,712,"0");
                  button(755-a,705,800-a,740); break;
        case 8:
                  outtextxy(818-a,712,"Backspace");
                  button(805-a,705,920-a,740); break;
        case 9:
        	      outtextxy(265-a,713+48,"Tab");
	              button(255-a,705+50,310-a,740+50);
				  break;
	    case 27:
	    	      settextstyle(8,0,2);
	    	      setcolor(GREEN);
	    	      button(1100,800,1250,850);
				  outtextxy(1120,813,"Next (Esc)");
				  delay(100); 
	              setcolor(WHITE);
	              button(1100,800,1250,850);
	              setcolor(YELLOW);
				  outtextxy(1120,813,"Next (Esc)");
				  setcolor(WHITE);
	    	      return 1;
		case 'q':
		case 'Q': 
	              outtextxy(330-a,712+50,"Q");
	              button(315-a,705+50,360-a,740+50); break;
	    case 'w':
		case 'W': 
	              outtextxy(380-a,712+50,"W");
	              button(365-a,705+50,410-a,740+50); break;
	    case 'e':
		case 'E': 
	              outtextxy(430-a,712+50,"E");
				  button(415-a,705+50,460-a,740+50); break;
	    case 'r':
		case 'R': 
	              outtextxy(480-a,712+50,"R");
				  button(465-a,705+50,510-a,740+50); break;
	    case 't':
		case 'T': 
	              outtextxy(530-a,712+50,"T");
				  button(515-a,705+50,560-a,740+50); break;
	    case 'y':
		case 'Y': 
	              outtextxy(580-a,712+50,"Y");
	              button(565-a,705+50,610-a,740+50); break;
	    case 'u':
		case 'U': 
	              outtextxy(630-a,712+50,"U");
				  button(615-a,705+50,660-a,740+50); break;
	    case 'i':
		case 'I': 
	              outtextxy(680-a,712+50,"I");
	              button(665-a,705+50,710-a,740+50); break;
	    case 'o':
		case 'O': 
	              outtextxy(730-a,712+50,"O");
	              button(715-a,705+50,760-a,740+50); break;
	    case 'p':
		case 'P': 
	              outtextxy(780-a,712+50,"P");
				  button(765-a,705+50,810-a,740+50); break;
		case '?':
			       outtextxy(830-a,712+50,"?");
				   button(815-a,705+50,860-a,740+50); break;
		case '\\':
				   outtextxy(885-a,711+50,"\\");
	                button(865-a,705+50,920-a,740+50); break;
	    case 'a': 
		case 'A': 
	              outtextxy(330-a,712+90,"A");
				  button(315-a,705+90,360-a,740+90); break;
	    case 's':
		case 'S': 
	              outtextxy(380-a,712+90,"S");
	              button(365-a,705+90,410-a,740+90); break;
	    case 'd':
		case 'D': 
	              outtextxy(430-a,712+90,"D");
				  button(415-a,705+90,460-a,740+90); break;
	    case 'f':
		case 'F': 
	              outtextxy(480-a,712+90,"F");
	              button(465-a,705+90,510-a,740+90); break;
		case 'G':
		case 'g':
			       outtextxy(530-a,712+90,"G");
	               button(515-a,705+90,560-a,740+90); break;
	
	    case 'H':
		case 'h': 
	              outtextxy(580-a,712+90,"H");
	              button(565-a,705+90,610-a,740+90); break;
	    case 'j':
		case 'J': 
	              outtextxy(630-a,712+90,"J");
				  button(615-a,705+90,660-a,740+90); break;
	    case 'k':
		case 'K': 
	              outtextxy(680-a,712+90,"K");
				  button(665-a,705+90,710-a,740+90); break;
	    case 'l':
		case 'L': 
	              outtextxy(728-a,711+90,"L");
	              button(715-a,705+90,760-a,740+90); break;
	    case ';':
		case ':': 
	               settextstyle(1,0,3);
				   outtextxy(778-a,709+90,": ;");
				   button(765-a,705+90,820-a,740+90);
	               settextstyle(3,0,2); break;
        case 13:
        	       outtextxy(855-a,712+90,"Enter");
	               button(825-a,705+90,920-a,740+90); break;
	    case 403:
                   outtextxy(265-a,713+128,"Shift");
	               button(255-a,705+130,310-a,740+130); break;
	    case 404:           
                   outtextxy(830-a,712+130,"S h i f t");
	               button(800-a,705+130,920-a,740+130); break;
	    case 'z':
		case 'Z': 
	              outtextxy(330-a,712+130,"Z");
				  button(315-a,705+130,360-a,740+130); break;
	    case 'x':
		case 'X': 
	              outtextxy(380-a,712+130,"X");
				  button(365-a,705+130,410-a,740+130); break; 
	    case 'c':
		case 'C': 
	              	outtextxy(430-a,712+130,"C");
					button(415-a,705+130,460-a,740+130); break;
	    case 'v':
		case 'V': 
	              outtextxy(480-a,712+130,"V");
				  button(465-a,705+130,510-a,740+130); break;
	    case 'b':
		case 'B': 
	              outtextxy(530-a,712+130,"B");
				  button(515-a,705+130,560-a,740+130); break;
	    case 'n':
		case 'N': 
	              outtextxy(580-a,712+130,"N");
				  button(565-a,705+130,610-a,740+130); break;
	    case 'm':
		case 'M': 
	              outtextxy(630-a,712+130,"M");
				  button(615-a,705+130,660-a,740+130); break;
		case '<':
			      outtextxy(680-a,712+130,"<");
	              button(665-a,705+130,705-a,740+130); break;
	    case '>':
	    	      outtextxy(725-a,712+130,">");
	              button(710-a,705+130,750-a,740+130); break;
	    case '/':
	    	       outtextxy(770-a,712+130,"/");
	               button(755-a,705+130,795-a,740+130); break;
	    case ' ': 
	               button(420-a,705+170,745-a,740+170); break;
		case 405:
                    outtextxy(265-a,713+168,"C t r l");
	                button(255-a,705+170,320-a,740+170); break;
	    case 407:
				    outtextxy(770-a,713+168,"A l t");
					button(750-a,705+170,820-a,740+170); break;
		case 406:
					outtextxy(845-a,713+168,"C t r l");
					button(825-a,705+170,920-a,740+170); break;
	
	    default:
	    	      setcolor(WHITE);	 break;
	}
	delay(100); 
	setcolor(WHITE);
	return 0;
}
void mainfram()
{
	char m[1];
	setfillstyle(9,3);
    bar(50,10,1050,70);
    setcolor(GREEN);
    rectangle(50,10,1050,70);
    settextstyle(4,0,5);
    setcolor(15);
    outtextxy(62,17,"              TYPING MASTER          ");
    setcolor(15);
    for(int i=5;i>0;i--)
    rectangle(50-i,90-i,1050+i,650+i);
    button(1100,800,1250,850);
    settextstyle(8,0,2);
    setcolor(YELLOW);
    outtextxy(1120,813,"Next (Esc)");
    setcolor(WHITE);
}
// ----------------------- Pregrassion -------------------------------------
void yourpregrassion()
{
	settextstyle(3,0,3);
	setcolor(YELLOW);
	outtextxy(1090,170,"Your Progress");
	setcolor(WHITE);
	rectangle(1080,130,1100,160);
	rectangle(1110,110,1130,160);
	rectangle(1140,90,1160,160);
	rectangle(1170,70,1190,160);
	rectangle(1200,50,1220,160);
	rectangle(1230,30,1250,160);
	setfillstyle(1,GREEN);
	if(progress==1)
	  bar(1080,130,1100,160);
	else if(progress==2){
      bar(1080,130,1100,160);
	  bar(1110,110,1130,160);}
	else if(progress==3){
	  bar(1080,130,1100,160);
	  bar(1110,110,1130,160);
	  bar(1140,90,1160,160);}
	else if(progress==4){
	  bar(1080,130,1100,160);
	  bar(1110,110,1130,160);
	  bar(1140,90,1160,160);
	  bar(1170,70,1190,160);}
	else if(progress==5){
	  bar(1080,130,1100,160);
	  bar(1110,110,1130,160);
	  bar(1140,90,1160,160);
	  bar(1170,70,1190,160);
	  bar(1200,50,1220,160);}
	else if(progress==6){
	  bar(1080,130,1100,160);
	  bar(1110,110,1130,160);
	  bar(1140,90,1160,160);
	  bar(1170,70,1190,160);
	  bar(1200,50,1220,160);
	  bar(1230,30,1250,160);}
	else 
	  progress=0;
	
	progress++;
}
// ----------------- Charchcer's -------------------------
void charbox()
{
	int A=0,B=0;
	for(int i=1;i<=6;i++)
	{
		rectangle(100+A,150+B,160+A,200+B);
        rectangle(165+A,150+B,225+A,200+B);
	    rectangle(230+A,150+B,290+A,200+B);
	    rectangle(295+A,150+B,355+A,200+B); 
	    settextstyle(3,0,2);
	    outtextxy(365+A,164+B,"space");
	    rectangle(360+A,160+B,420+A,190+B);
	    A=550;
	    if(i%2==0)
	    {
	    	B+=150;
	    	A=0;
		}
	}
}
void ch1setdis(int CharNumber)
{
	if(CharNumber==1)
	{
		ch1.Reset();
		ch1.enqueue('f');
		ch1.enqueue('u');
		ch1.enqueue('b');
		ch1.enqueue('l');
	}
	else if(CharNumber==2)
	{
		ch1.enqueue('L');
		ch1.enqueue('y');
		ch1.enqueue('z');
		ch1.enqueue('m');
	}
	else if(CharNumber==3)
	{
		ch1.enqueue('T');
		ch1.enqueue('h');
		ch1.enqueue('a');
		ch1.enqueue('t');
	}
	else if(CharNumber==4)
	{
		ch1.enqueue('g');
		ch1.enqueue('t');
		ch1.enqueue('b');
		ch1.enqueue('D');
	}
	else if(CharNumber==5)
	{
	    ch1.enqueue('l');
		ch1.enqueue('h');
		ch1.enqueue('q');
		ch1.enqueue('z');	
	}
	else
	{
	    ch1.enqueue('5');
	    ch1.enqueue('3');
	    ch1.enqueue('4');
	    ch1.enqueue('6');	
	}
	char ch[2];
	int d=0;
	for(int i=1;i<=4;i++)
	{
		settextstyle(6,0,4);
		ch[0] = ch1.dequeue();
	    outtextxy(120+d,160,ch);
	    d+=65;
	}
}
void ch2setdis(int CharNumber)
{
	if(CharNumber==1)
	{
	  ch2.Reset();
	  ch2.enqueue('h');
	  ch2.enqueue('k');
	  ch2.enqueue('a');
	  ch2.enqueue('v');	
	}
	else if(CharNumber==2)
	{
	  ch2.enqueue('p');
	  ch2.enqueue('f');
	  ch2.enqueue('q');
	  ch2.enqueue('c');	
	}
	else if(CharNumber==3)
	{
	  ch2.enqueue('b');
	  ch2.enqueue('o');
	  ch2.enqueue('s');
	  ch2.enqueue('s');	
	}
	else if(CharNumber==4)
	{
	  ch2.enqueue('i');
	  ch2.enqueue('R');
	  ch2.enqueue('q');
	  ch2.enqueue('x');	
	}
	else if(CharNumber==5)
	{
	  ch2.enqueue('G');
	  ch2.enqueue('h');
	  ch2.enqueue('f');
	  ch2.enqueue('j');	
	}
	else
	{
	  ch2.enqueue('5');
	  ch2.enqueue('7');
	  ch2.enqueue('0');
	  ch2.enqueue('1');	
	}
	char ch[2];
	int d=0;
	for(int i=1;i<=4;i++)
	{
		settextstyle(6,0,4);
		ch[0] = ch2.dequeue();
	    outtextxy(670+d,160,ch);
	    d+=65;
	}
}
void ch3setdis(int CharNumber)
{
	
	if(CharNumber==1)
	{
		ch3.Reset();
		ch3.enqueue('g');
		ch3.enqueue('s');
		ch3.enqueue('b');
		ch3.enqueue('p');
	}
	else if(CharNumber==2)
	{
		ch3.enqueue('K');
		ch3.enqueue('y');
		ch3.enqueue('Y');
		ch3.enqueue('t');
	}
	else if(CharNumber==3)
	{
		ch3.enqueue('t');
		ch3.enqueue('h');
		ch3.enqueue('e');
		ch3.enqueue('.');
	}
	else if(CharNumber==4)
	{
		ch3.enqueue(';');
		ch3.enqueue('o');
		ch3.enqueue('w');
		ch3.enqueue('q');
	}
	else if(CharNumber==5)
	{
		ch3.enqueue('U');
		ch3.enqueue('i');
		ch3.enqueue('n');
		ch3.enqueue('x');
	}
	else
	{
		ch3.enqueue('5');
		ch3.enqueue('6');
		ch3.enqueue('9');
		ch3.enqueue('6');
	}
	char ch[2];
	int d=0;
	for(int i=1;i<=4;i++)
	{
		settextstyle(6,0,4);
		ch[0] = ch3.dequeue();
	    outtextxy(120+d,310,ch);
	    d+=65;
	}
}
void ch4setdis(int CharNumber)
{
	if(CharNumber==1)
	{
		ch4.Reset();
		ch4.enqueue('n');
		ch4.enqueue('h');
		ch4.enqueue('s');
		ch4.enqueue('y');
	}
	else if(CharNumber==2)
	{
		ch4.enqueue('y');
		ch4.enqueue('o');
		ch4.enqueue('u');
		ch4.enqueue('r');
	}
	else if(CharNumber==3)
	{
		ch4.enqueue('t');
		ch4.enqueue('y');
		ch4.enqueue('E');
		ch4.enqueue('/');
	}
	else if(CharNumber==4)
	{
		ch4.enqueue('I');
		ch4.enqueue('b');
		ch4.enqueue(';');
		ch4.enqueue('F');
	}
	else if(CharNumber==5)
	{
		ch4.enqueue('N');
		ch4.enqueue('i');
		ch4.enqueue('n');
		ch4.enqueue('a');
	}
	else 
	{
		ch4.enqueue('8');
		ch4.enqueue('1');
		ch4.enqueue('5');
		ch4.enqueue('3');
	}
	char ch[2];
	int d=0;
	for(int i=1;i<=4;i++)
	{
		settextstyle(6,0,4);
		ch[0] = ch4.dequeue();
	    outtextxy(670+d,310,ch);
	    d+=65;
	}
}
void ch5setdis(int CharNumber)
{
	if(CharNumber==1)
	{
		ch5.Reset();
		ch5.enqueue('w');
		ch5.enqueue('z');
		ch5.enqueue('l');
		ch5.enqueue('t');
	}
	else if(CharNumber==2)
	{
		ch5.enqueue('x');
		ch5.enqueue('w');
		ch5.enqueue('e');
		ch5.enqueue('c');
	}
	else if(CharNumber==3)
	{
		ch5.enqueue('m');
		ch5.enqueue('s');
		ch5.enqueue('t');
		ch5.enqueue('d');
	}
	else if(CharNumber==4)
	{
		ch5.enqueue('c');
		ch5.enqueue('i');
		ch5.enqueue('L');
		ch5.enqueue('.');
	}
	else if(CharNumber==5)
	{
		ch5.enqueue('w');
		ch5.enqueue('\\');
		ch5.enqueue('L');
		ch5.enqueue('d');
	}
	else
	{
		ch5.enqueue('5');
		ch5.enqueue('6');
		ch5.enqueue('9');
		ch5.enqueue('0');
	}
	char ch[2];
	int d=0;
	for(int i=1;i<=4;i++)
	{
		settextstyle(6,0,4);
		ch[0] = ch5.dequeue();
	    outtextxy(120+d,460,ch);
	    d+=65;
	}
}
void ch6setdis(int CharNumber)
{
	if(CharNumber==1)
	{
		ch6.Reset();
		ch6.enqueue('u');
		ch6.enqueue('a');
		ch6.enqueue('L');
		ch6.enqueue('e');
	}
	else if(CharNumber==2)
	{
		ch6.enqueue('u');
		ch6.enqueue('k');
		ch6.enqueue('o');
		ch6.enqueue('l');
	}
	else if(CharNumber==3)
	{
		ch6.enqueue('s');
		ch6.enqueue('e');
		ch6.enqueue('J');
		ch6.enqueue('w');
	}
	else if(CharNumber==4)
	{
		ch6.enqueue('u');
		ch6.enqueue('z');
		ch6.enqueue('c');
		ch6.enqueue('P');
	}
	else if(CharNumber==5)
	{
		ch6.enqueue('u');
		ch6.enqueue('t');
		ch6.enqueue('c');
		ch6.enqueue('R');
	}
	else
	{
		ch6.enqueue('8');
		ch6.enqueue('7');
		ch6.enqueue('6');
		ch6.enqueue('2');
	}
	char ch[2];
	int d=0;
	for(int i=1;i<=4;i++)
	{
		settextstyle(6,0,4);
		ch[0] = ch6.dequeue();
	    outtextxy(670+d,460,ch);
	    d+=65;
	}
}
// ----------------------- Word's ------------------------
void w1setword(int ind)
{
	if(ind==1)
	{
	  w1.enqueue('b',3);
	  w1.enqueue('u',3);
	  w1.enqueue('t',3);
	}
	else if(ind==2)
	{
		w1.Reset();
		w1.enqueue('y',3);
		w1.enqueue('e',3);
		w1.enqueue('t',3);
	}
	else
	{
		w1.Reset();
		w1.enqueue('b',3);
		w1.enqueue('e',3);
		w1.enqueue('y',3);
	}
}
void w2setword(int ind)
{
	if(ind==1)
	{
	  w2.enqueue('b',4);
	  w2.enqueue('u',4);
	  w2.enqueue('s',4);
	  w2.enqueue('y',4);
	}
	else if(ind==2)
	{
		w2.Reset();
		w2.enqueue('y',4);
		w2.enqueue('e',4);
		w2.enqueue('a',4);
		w2.enqueue('r',4);
	}
	else
	{
		w2.Reset();
		w2.enqueue('y',4);
		w2.enqueue('o',4);
		w2.enqueue('u',4);
		w2.enqueue('r',4);
	}
}
void w3setword(int ind)
{
	if(ind==1)
	{
		w3.Reset();
	  w3.enqueue('b',5);
	  w3.enqueue('e',5);
	  w3.enqueue('r',5);
	  w3.enqueue('r',5);
	  w3.enqueue('y',5);
	}
	else if(ind==2)
	{
		w3.Reset();
		w3.enqueue('y',5);
		w3.enqueue('o',5);
		w3.enqueue('d',5);
		w3.enqueue('l',5);
		w3.enqueue('e',5);
	}
	else
	{
		w3.Reset();
		w3.enqueue('n',5);
		w3.enqueue('a',5);
		w3.enqueue('z',5);
		w3.enqueue('i',5);
		w3.enqueue('r',5);
	}
}
void w4setword(int ind)
{
	if(ind==1)
	{
	  w4.enqueue('b',6);
	  w4.enqueue('a',6);
	  w4.enqueue('b',6);
	  w4.enqueue('b',6);
	  w4.enqueue('l',6);
	  w4.enqueue('e',6);
	}
	else if(ind==2)
	{
		w4.Reset();
		w4.enqueue('y',6);
		w4.enqueue('v',6);
		w4.enqueue('e',6);
		w4.enqueue('t',6);
		w4.enqueue('t',6);
		w4.enqueue('e',6);
	}
	else
	{
		w4.Reset();
		w4.enqueue('v',6);
		w4.enqueue('i',6);
		w4.enqueue('n',6);
		w4.enqueue('c',6);
		w4.enqueue('e',6);
		w4.enqueue('?',6);
	}
}
void w5setword(int ind)
{
	if(ind==1)
	{
		w5.enqueue('p',5);
		w5.enqueue('i',5);
		w5.enqueue('c',5);
		w5.enqueue('k',5);
		w5.enqueue('s',5);
	}
	else if(ind==2)
	{
		w5.Reset();
		w5.enqueue('p',5);
		w5.enqueue('o',5);
		w5.enqueue('w',5);
		w5.enqueue('e',5);
		w5.enqueue('r',5);
	}
	else
	{
		w5.Reset();
		w5.enqueue('e',5);
		w5.enqueue('q',5);
		w5.enqueue('u',5);
		w5.enqueue('i',5);
		w5.enqueue('p',5);
	}
}
void w6setword(int ind)
{
	if(ind==1)
	{
	  w6.enqueue('w',4);
	  w6.enqueue('h',4);
	  w6.enqueue('a',4);
	  w6.enqueue('t',4);
	}
	else if(ind==2)
	{
	  w6.Reset();
	  w6.enqueue('m',4);
	  w6.enqueue('e',4);
	  w6.enqueue('e',4);
	  w6.enqueue('t',4);
	}
	else
	{
	  w6.Reset();
	  w6.enqueue('N',4);
	  w6.enqueue('i',4);
	  w6.enqueue('n',4);
	  w6.enqueue('a',4);
	}
}
void printchar(char click,int c,int r)
{
	char ch[2];
    ch[0]=click;
    settextstyle(6,0,4);
	outtextxy(c,r,ch);
}
//  ---------------------------paragraph---------------------------
void we()
{
	word.Reset();
	word.enqueue('w',2);
	word.enqueue('e',2);
}
void is()
{
	word.Reset();
	word.enqueue('i',2);
	word.enqueue('s',2);
}
void to()
{
	word.Reset();
	word.enqueue('t',2);
	word.enqueue('o',2);
}
void of()
{
	word.Reset();
	word.enqueue('o',2);
	word.enqueue('f',2);
}
void it()
{
	word.Reset();
	word.enqueue('i',2);
	word.enqueue('t',2);
}
void the()
{
	word.Reset();
	word.enqueue('t',3);
	word.enqueue('h',3);
	word.enqueue('e',3);
}
void our()
{
	word.Reset();
	word.enqueue('o',3);
	word.enqueue('u',3);
	word.enqueue('r',3);
}
void out()
{
	word.Reset();
	word.enqueue('o',3);
	word.enqueue('u',3);
	word.enqueue('t',3);
}
void And()
{
	word.Reset();
	word.enqueue('a',3);
	word.enqueue('n',3);
	word.enqueue('d',3);
}
void Not()
{
	word.Reset();
	word.enqueue('n',3);
	word.enqueue('o',3);
	word.enqueue('t',3);
}
void business()
{
	word.Reset();
	word.enqueue('b',8);
	word.enqueue('u',8);
	word.enqueue('s',8);
	word.enqueue('i',8);
	word.enqueue('n',8);
	word.enqueue('e',8);
	word.enqueue('s',8);
	word.enqueue('s',8);
}
void that()
{
	word.Reset();
	word.enqueue('t',4);
	word.enqueue('h',4);
	word.enqueue('a',4);
	word.enqueue('t',4);
}
void unctuality()
{
	word.enqueue('u',11);
	word.enqueue('n',11);
	word.enqueue('c',11);
	word.enqueue('t',11);
	word.enqueue('u',11);
	word.enqueue('a',11);
	word.enqueue('l',11);
	word.enqueue('i',11);
	word.enqueue('t',11);
	word.enqueue('y',11);
}
void It()
{
	word.Reset();
	word.enqueue('i',3);
	word.enqueue('t',3);
	word.enqueue('.',3);
}
void very()
{
	word.enqueue('v',5);
	word.enqueue('e',5);
	word.enqueue('r',5);
	word.enqueue('y',5);
}
void setword(int noword)
{
	if(noword==1)
	{
	  col=0;
	  word.enqueue('P',11);
	  unctuality();	
	}
	else if(noword==2)
	{
	  is();
	  ab=12*11;	
	}
	else if(noword==3)
	{
	  word.Reset();
	  word.enqueue('n',9);
	  word.enqueue('e',9);
	  word.enqueue('c',9);
	  word.enqueue('e',9);
	  word.enqueue('s',9);
	  word.enqueue('s',9);
	  word.enqueue('a',9);
	  word.enqueue('r',9);
	  word.enqueue('y',9);
	  ab+=17*2;
	}
	else if(noword==4)
	{
	  to();
	  ab+=12*9;
	}
	else if(noword==5)
	{
	  word.Reset();
	  word.enqueue('r',8);
	  word.enqueue('e',8);
	  word.enqueue('g',8);
	  word.enqueue('u',8);
	  word.enqueue('l',8);
	  word.enqueue('a',8);
	  word.enqueue('t',8);
	  word.enqueue('e',8);
	  ab+=17*2;
	}
	else if(noword==6)
	{
	  the();
	  ab+=12*8+2;
	}
	else if(noword==7)
	{
	  business();
	  ab+=16*3-2;
	}
	else if(noword==8)
	{
	  of();
	  ab+=12*8;
	}
	else if(noword==9)
	{
	  word.Reset();
	  word.enqueue('l',5);
	  word.enqueue('i',5);
	  word.enqueue('f',5);
	  word.enqueue('e',5);
	  word.enqueue('.',5);
	  ab+=17*2;
	}
	else if(noword==10)
	{
	  word.Reset();
	  word.enqueue('U',14);
	  word.enqueue('n',14);
	  word.enqueue('f',14);
	  word.enqueue('o',14);
	  word.enqueue('r',14);
	  word.enqueue('t',14);
	  word.enqueue('u',14);
	  word.enqueue('n',14);
	  word.enqueue('a',14);
	  word.enqueue('t',14);
	  word.enqueue('e',14);
	  word.enqueue('l',14);
	  word.enqueue('y',14);
	  word.enqueue(',',14);
	  ab+=13*5+3;	
	}
	else if(noword==11)
	{
	  word.Reset();
	  word.enqueue('p',11);
	  unctuality();
	  ab+=12*14-3;	
	}
	else if(noword==12)
	{
	  is();
	  col+=30;
	  ab=0;	
	}
	else if(noword==13)
	{
	  Not();
	  ab+=12*2+8;
	}
	else if(noword==14)
	{
	  word.Reset();
	  word.enqueue('g',5);
	  word.enqueue('i',5);
	  word.enqueue('v',5);
	  word.enqueue('e',5);
	  word.enqueue('n',5);
	  ab+=14*3+3;
	}
	else if(noword==15)
	{
	  word.Reset();
	  word.enqueue('m',4);
	  word.enqueue('u',4);
	  word.enqueue('s',4);
	  word.enqueue('h',4);
	  ab+=13*5;
	}
	else if(noword==16)
	{
	  word.Reset();
	  word.enqueue('i',10);
	  word.enqueue('m',10);
	  word.enqueue('p',10);
	  word.enqueue('o',10);
	  word.enqueue('r',10);
	  word.enqueue('t',10);
	  word.enqueue('a',10);
	  word.enqueue('n',10);
	  word.enqueue('c',10);
	  word.enqueue('e',10);
	  ab+=14*4;	
	}
	else if(noword==17)
	{
	  word.Reset();
	  word.enqueue('o',2);
	  word.enqueue('n',2);
	  ab+=12*10;	
	}
	else if(noword==18)
	{
	  our();
	  ab+=16*2;
	}
	else if(noword==19)
	{
	  word.Reset();
	  word.enqueue('s',8);
	  word.enqueue('o',8);
	  word.enqueue('c',8);
	  word.enqueue('i',8);
	  word.enqueue('e',8);
	  word.enqueue('t',8);
	  word.enqueue('y',8);
	  word.enqueue('.',8);
	  ab+=16*3;
	}
	else if(noword==20)
	{
	  word.Reset();
	  word.enqueue('I',2);
	  word.enqueue('t',2);
	  ab+=12*8;	
	}
	else if(noword==21)
	{
	  is();
	  ab+=14*2+5;	
	}
	else if(noword==22)
	{
	  Not();
	  ab+=17*2-2;
	}
	else if(noword==23)
	{
	  word.Reset();
	  word.enqueue('e',4);
	  word.enqueue('a',4);
	  word.enqueue('s',4);
	  word.enqueue('y',4);
	  ab+=14*3+3;
	}
	else if(noword==24)
	{
	  to();
	  ab+=13*4+4;	
	}
	else if(noword==25)
	{
	  word.Reset();
	  word.enqueue('g',4);
	  word.enqueue('u',4);
	  word.enqueue('s',4);
	  word.enqueue('s',4);
	  ab+=12*2+7;
	}
	else if(noword==26)
	{
	  the();
	  ab+=14*4;
	}
	else if(noword==27)
	{
	  word.Reset();
	  word.enqueue('l',4);
	  word.enqueue('o',4);
	  word.enqueue('s',4);
	  word.enqueue('s',4);
	  ab+=16*3-2;
	}
	else if(noword==28)
	{
	  that();
	  ab+=12*4+8;
	}
	else if(noword==29)
	{
	  we();
	  ab+=13*4;	
	}
	else if(noword==30)
	{
	  word.Reset();
	  word.enqueue('b',4);
	  word.enqueue('e',4);
	  word.enqueue('a',4);
	  word.enqueue('r',4);
	  ab=0;
	  col+=30;
	}
	else if(noword==31)
	{
	  word.Reset();
	  word.enqueue('d',3);
	  word.enqueue('u',3);
	  word.enqueue('e',3);
	  ab+=14*4;
	}
	else if(noword==32)
	{
	  to();
	  ab+=12*4-5;	
	}
	else if(noword==33)
	{
	  It();
	  ab+=14*2; 
	}
	else if(noword==34)
	{
	  word.Reset();
	  word.enqueue('E',5);
	  very();
	  ab+=14*3+5;
	}
	else if(noword==35)
	{
	  of();
	  ab+=12*5+10;	
	}
	else if(noword==36)
	{
	  our();
	  ab+=12*2+8;	
	}
	else if(noword==37)
	{
	  word.Reset();
	  word.enqueue('m',7);
	  word.enqueue('e',7);
	  word.enqueue('e',7);
	  word.enqueue('t',7);
	  word.enqueue('i',7);
	  word.enqueue('n',7);
	  word.enqueue('g',7);
	  ab+=15*3-3;
	}
	else if(noword==38)
	{
	  And();
	  ab+=12*7+5;	
	}
	else if(noword==39)
	{
	  word.Reset();
	  word.enqueue('s',7);
	  word.enqueue('i',7);
	  word.enqueue('t',7);
	  word.enqueue('t',7);
	  word.enqueue('i',7);
	  word.enqueue('n',7);
	  word.enqueue('g',7);
	  ab+=15*3-3;
	}
	else if(noword==40)
	{
	  And();
	  ab+=12*7+5;	
	}
	else if(noword==41)
	{
	  word.Reset();
	  word.enqueue('e',5);
	  very();
	  ab+=14*3+5;
	}
	else if(noword==42)
	{
		business();
		ab+=12*5+5;
	}
	else if(noword==43)
	{
	  word.Reset();
	  word.enqueue('s',6);
	  word.enqueue('t',6);
	  word.enqueue('a',6);
	  word.enqueue('r',6);
	  word.enqueue('t',6);
	  word.enqueue('s',6);
	  ab+=11*9;
	}
	else if(noword==44)
	{
	  word.Reset();
	  word.enqueue('a',5);
	  word.enqueue('f',5);
	  word.enqueue('t',5);
	  word.enqueue('e',5);
	  word.enqueue('r',5);
	  ab+=12*6+5;
	}
	else if(noword==45)
	{
		the();
		ab+=12*5+5;
	}
	else if(noword==46)
	{
	  word.Reset();
	  word.enqueue('f',5);
	  word.enqueue('i',5);
	  word.enqueue('x',5);
	  word.enqueue('e',5);
	  word.enqueue('d',5);
	  ab=0;
	  col+=30;
	}
	else if(noword==47)
	{
	  word.Reset();
	  word.enqueue('t',5);
	  word.enqueue('i',5);
	  word.enqueue('m',5);
	  word.enqueue('e',5);
	  word.enqueue('.',5);
	  ab=12*5+5;
	}
	else if(noword==48)
	{
	  word.Reset();
	  word.enqueue('T',3);
	  word.enqueue('h',3);
	  word.enqueue('e',3);
	  ab+=14*5-4; 
	}
	else if(noword==49)
	{
	  word.Reset();
	  word.enqueue('s',9);
	  word.enqueue('o',9);
	  word.enqueue('r',9);
	  word.enqueue('r',9);
	  word.enqueue('o',9);
	  word.enqueue('w',9);
	  word.enqueue('f',9);
	  word.enqueue('u',9);
	  word.enqueue('l',9);
	  ab+=17*3-5;
	}
	else if(noword==50)
	{
	  word.Reset();
	  word.enqueue('t',5);
	  word.enqueue('h',5);
	  word.enqueue('i',5);
	  word.enqueue('n',5);
	  word.enqueue('g',5);
	  ab+=12*9+2;
	}
	else if(noword==51)
	{
		word.Reset();
	    word.enqueue('i',2);
	    word.enqueue('n',2);
		ab+=12*5+4;
	}
	else if(noword==52)
	{
		that();
		ab+=12*2+8;
	}
	else if(noword==53)
	{
		we();
		ab+=12*4+8;
	}
	else if(noword==54)
	{
		word.Reset();
	    word.enqueue('d',2);
	    word.enqueue('o',2);
		ab+=16*2;
	}
	else if(noword==55)
	{
		Not();
		ab+=15*2+3;
	}
	else if(noword==56)
	{
	  word.Reset();
	  word.enqueue('e',7);
	  word.enqueue('x',7);
	  word.enqueue('p',7);
	  word.enqueue('r',7);
	  word.enqueue('e',7);
	  word.enqueue('s',7);
	  word.enqueue('s',7);
	  ab+=16*3;
	}
	else if(noword==57)
	{
	  word.Reset();
	  word.enqueue('a',3);
	  word.enqueue('n',3);
	  word.enqueue('y',3);
	  ab+=13*7-6; 
	}
	else if(noword==58)
	{
	  word.Reset();
	  word.enqueue('r',6);
	  word.enqueue('e',6);
	  word.enqueue('g',6);
	  word.enqueue('r',6);
	  word.enqueue('e',6);
	  word.enqueue('t',6);
	  ab+=15*3;
	}
	else if(noword==59)
	{
		word.Reset();
	    word.enqueue('a',2);
	    word.enqueue('t',2);
		ab+=13*6;
	}
	else if(noword==60)
	{
	  It();
	  ab+=14*2+1; 
	}
	else if(noword==61)
	{
		word.Reset();
	    word.enqueue('W',2);
	    word.enqueue('e',2);
		ab+=14*3+5;
	}
	else if(noword==62)
	{
	  word.Reset();
	  word.enqueue('h',4);
	  word.enqueue('a',4);
	  word.enqueue('v',4);
	  word.enqueue('e',4);
	  ab+=14*2+4;
	}
	else if(noword==63)
	{
	  word.Reset();
	  word.enqueue('p',7);
	  word.enqueue('o',7);
	  word.enqueue('i',7);
	  word.enqueue('n',7);
	  word.enqueue('t',7);
	  word.enqueue('e',7);
	  word.enqueue('d',7);
	  ab=0;
	  col+=30;
	}
	else if(noword==64)
	{
		out();
		ab+=12*7+3;
	}
	else if(noword==65)
	{
		word.Reset();
	    word.enqueue('a',1);
		ab+=15*3;
	}
	else if(noword==66)
	{
	  word.Reset();
	  word.enqueue('n',8);
	  word.enqueue('a',8);
	  word.enqueue('t',8);
	  word.enqueue('i',8);
	  word.enqueue('o',8);
	  word.enqueue('n',8);
	  word.enqueue('a',8);
	  word.enqueue('l',8);
	  ab+=20;
	}
	else if(noword==67)
	{
	  word.Reset();
	  word.enqueue('a',8);
	  word.enqueue('i',8);
	  word.enqueue('l',8);
	  word.enqueue('m',8);
	  word.enqueue('e',8);
	  word.enqueue('n',8);
	  word.enqueue('t',8);
	  word.enqueue('.',8);
	  ab+=13*8-3;
	}
	else if(noword==68)
	{
	  word.Reset();
	  word.enqueue('N',3);
	  word.enqueue('o',3);
	  word.enqueue('w',3);
	  ab+=12*8+2; 
	}
	else if(noword==69)
	{
		it();
		ab+=14*3+2;
	}
	else if(noword==70)
	{
		is();
		ab+=14*2+4;
	}
	else if(noword==71)
	{
	  word.Reset();
	  word.enqueue('u',4);
	  word.enqueue('p',4);
	  word.enqueue('t',4);
	  word.enqueue('o',4);
	  ab+=14*2+7;
	}
	else if(noword==72)
	{
		the();
		ab+=14*4;
	}
	else if(noword==73)
	{
	  word.Reset();
	  word.enqueue('n',6);
	  word.enqueue('a',6);
	  word.enqueue('t',6);
	  word.enqueue('i',6);
	  word.enqueue('o',6);
	  word.enqueue('n',6);
	  ab+=14*3;
	}
	else if(noword==74)
	{
		to();
		ab+=13*6;
	}
	else if(noword==75)
	{
	  word.Reset();
	  word.enqueue('f',4);
	  word.enqueue('i',4);
	  word.enqueue('n',4);
	  word.enqueue('d',4);
	  ab+=14*2+7;
	}
	else if(noword==76)
	{
		out();
		ab+=13*4;
	}
	else if(noword==77)
	{
	  word.Reset();
	  word.enqueue('w',4);
	  word.enqueue('a',4);
	  word.enqueue('y',4);
	  word.enqueue('s',4);
	  ab+=14*3+4;
	}
	else if(noword==78)
	{
		of();
		ab+=13*4+3;
	}
	else if(noword==79)
	{
	  word.Reset();
	  word.enqueue('g',7);
	  word.enqueue('e',7);
	  word.enqueue('t',7);
	  word.enqueue('t',7);
	  word.enqueue('i',7);
	  word.enqueue('n',7);
	  word.enqueue('g',7);
	  ab+=14*2+4;
	}
	else if(noword==80)
	{
	  word.Reset();
	  word.enqueue('r',3);
	  word.enqueue('i',3);
	  word.enqueue('d',3);
	  ab=0;
	  col+=30; 
	}
	else if(noword==81)
	{
		of();
		ab+=13*3+4;
	}
	else if(noword==82)
	{
	  word.Reset();
	  word.enqueue('t',4);
	  word.enqueue('h',4);
	  word.enqueue('i',4);
	  word.enqueue('s',4);
	  ab+=14*2+4;
	}
	else if(noword==83)
	{
	  word.Reset();
	  word.enqueue('a',8);
	  word.enqueue('l',8);
	  word.enqueue('i',8);
	  word.enqueue('m',8);
	  word.enqueue('e',8);
	  word.enqueue('n',8);
	  word.enqueue('t',8);
	  word.enqueue('.',8);
	  ab+=13*4;
	}
	else
	 noword=0;
	
}
void writesentence()
{
	settextstyle(8,0,1);
	setcolor(7);
	outtextxy(90,120,"Punctuality is necessary to regulate the business of life. Unfortunately, punctuality");
	outtextxy(90,150,"is not given mush importance on our society. It is not easy to guss the loss that we");
	outtextxy(90,180,"bear due to it. Every of our meeting and sitting and every business starts after the"); 
	outtextxy(90,210,"fixed time. The sorrowful thing in that we do not express any regret at it. We have");
	outtextxy(90,240,"pointed out a national ailment. Now it is upto the nation to find out ways of getting");
	outtextxy(90,270,"rid of this aliment.");
	line(60,320,1040,320);
}
void drawinput(char click,int c,int r)
{
	char temp[3];
	setcolor(WHITE);
	temp[0]=click;
    settextstyle(8,0,1);
	outtextxy(75+c,350+r,temp);
}
// ------------------------ Result ----------------------
void resulttable()
{
	setcolor(YELLOW);
    button(300,200,1000,800);
    for(int i=60;i>0;i-=5)
    {
        if(i<50)
        setcolor(12);
        if(i<20)
        setcolor(14);
    	button(370-i,270-i,930+i,730+i);
	}
	settextstyle(8,0,4);
	setcolor(10);
	outtextxy(400+50,400,"Time Used   :");
	outtextxy(400+50,450,"Gross Speed :");
	outtextxy(400+50,500,"Accuracy    :");
	outtextxy(400+50,550,"Net Speed   :");
}
int gettime()
{
	int s=0;
	time_t now = time(0);
	tm *ltm=localtime(&now);
	s=ltm->tm_min*60 + ltm->tm_sec;   	
	return s;
}
void Result(int x)
{
	cleardevice();
	resulttable();
	int total_time,min,sec;
	time2 = gettime();
	total_time = time2-time1;
	char Min[3],Sec[3],Gross[3],Net[4],Accuracy[4];
	settextstyle(3,0,2);
	setcolor(15);
    if(total_time >= 60)
    {
    	min = total_time/60;
    	sec = total_time%60;
    	itoa(min,Min,10);
	    itoa(sec,Sec,10);
	    outtextxy(750,405,Min);
	    outtextxy(722+50,405,"min");
	    if(sec!=0)
	    {
	      outtextxy(760+50,405,",");
	      outtextxy(770+50,405,Sec);
	      outtextxy(793+50,405,"sec");	
		}
	}
	else
	{
		sec = total_time;
		itoa(sec,Sec,10);
		outtextxy(725+50,405,"sec");
	    outtextxy(700+50,405,Sec);
	}
	int gross,net,accuracy;
	if(x==1)
	{
	  	Correct_words = Correct_words/5;
	  	Wrong_words = Wrong_words/5;
	}
	float t = total_time/60.0;
	gross = (Correct_words+Wrong_words)/t;
	net = gross - Wrong_words/t;
	float A = 100.0 * net / gross ;
	accuracy = A;
	itoa(gross,Gross,10);
	itoa(accuracy,Accuracy,10);
	itoa(net,Net,10);
	outtextxy(700+50,455,Gross);
	outtextxy(725+50,455,"WPM");
	outtextxy(700+50,505,Accuracy);
	outtextxy(729+50,505,"%");
	outtextxy(700+50,555,Net);
	outtextxy(725+50,555,"WPM");
	getch();
} 
