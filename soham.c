 #include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 2
typedef struct NODE
{
	int reg_no;
	int age;
	char name[20];
	struct NODE *next;
} node;

node* deq();
int create();
int reserve(node*);
int cancel(int);
void enq(node*);
void display();


node *start;
node *front;
node *rear;
int count=0;
int num=0;


int create( )
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->reg_no=1;
	printf("Name: ");
	scanf("%s", new->name);
	printf("Age : ");
	scanf("%d", &new->age);
    if(new->age>=90 || new->age<=10) {
        free(new);
        return -1;
    }
	start=new;
	new->next=NULL;
	num++;
    return 1;
	
}

int reserve(node *start)
{
	int temp;
	if(start==NULL)
	{   
   		temp = create(start);
		 return temp;
	}
	else 
	{
	
	node *temp, *new_node;
	temp=start;
	while(temp->next!=NULL)
	{ 
	  temp=temp->next;
	}
	
	new_node=(node *)malloc(sizeof(node));
	
	printf("Name: ");
	scanf("%s", new_node->name);
	printf("Age : ");
	scanf("%d", &new_node->age);
    if(new_node->age >=90 || new_node->age<=10) {
        return -1;
    }
	new_node->next=NULL;
	if(num<=size)
	{
		num++;
		new_node->reg_no=num;
		temp->next=new_node;
		
		return 1;
	}
	else
	{
		enq(new_node);
		return 0;
	}
}
}


int cancel(int reg)
{
	node *ptr, *preptr, *new;
	ptr=start;
	preptr=NULL;
	if(start==NULL)
	return -1;
	if(ptr->next==NULL && ptr->reg_no==reg)
		{
		start=NULL;
		num--;
		free(ptr);
		return 1;
		
		}
		
	else{	
	while(ptr->reg_no!=reg && ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL && ptr->reg_no!=reg)
			return -1;
		else
			preptr->next=ptr->next;
		free(ptr);
		new=deq();
		while(preptr->next!=NULL)
			preptr=preptr->next;
		preptr->next=new;
		num--;
		return 1;
	
	}
}

void enq(node *new_node)
{
	if(rear==NULL)
	{
		rear=new_node;
		rear->next=NULL;
		front=rear;
	}
	else
	{
		node *temp;
		temp=new_node;
		rear->next=temp;
		temp->next=NULL;
		rear=temp;
	}
	count++;
}

node* deq()
{
	node *front1;
	front1=front;
	if(front==NULL)
		return NULL;
	else
	{
	    count-- ;
		if(front->next!=NULL)
		{
			front=front->next;
			front1->next=NULL;
			return front1;
		}
		else
		{
			front=NULL;
			rear=NULL;
			
			return front1;
		}
	}	
}


void display()
{
	node *temp;
	temp=start;
	while(temp!=NULL)
	{
		printf("\nRegistration Number: %d\n", temp->reg_no);
		printf("Name : %s\n\n", temp->name);
		temp=temp->next;
    }
    
}


int main()
{
  char station[52][20];
  int train[52][100];
  char choice[20];
  int i,j,k;
  char opt[10];

    strcpy(station[0],"palakkad");  
    strcpy(station[1],"chennai");
    strcpy(station[2],"gudur");
    strcpy(station[3],"madurai");
    strcpy(station[4],"kochuveli");
    strcpy(station[5],"trivandrum");
    strcpy(station[6],"ahmedabad");
    strcpy(station[7],"kollam");
    strcpy(station[8],"ernakulam");
    strcpy(station[9],"bengaluru");
    strcpy(station[10],"arrakonam");
    strcpy(station[11],"nagercoil");
    strcpy(station[12],"jolarpettai");
    strcpy(station[13],"coimbatore");
    strcpy(station[14],"santragachi");
    strcpy(station[15],"secunderabad");
    strcpy(station[16],"hubballi");
    strcpy(station[17],"shivamogga");
    strcpy(station[18],"metupalaiyam");
    strcpy(station[19],"mangaluru");
    strcpy(station[20],"lokmanyatilak");
    /*(delhi)*/strcpy(station[21],"nizamuddin");
    strcpy(station[22],"gorakhpur");
    strcpy(station[23],"barauni");
    strcpy(station[24],"yesvantpur");
    strcpy(station[25],"kamakhya");
    strcpy(station[26],"darbhanga");
    strcpy(station[27],"mysuru");
    strcpy(station[28],"delhi");
    strcpy(station[29],"chhapra");
    strcpy(station[30],"alappuzha");
    strcpy(station[31],"bhubaneshwar");
    strcpy(station[32],"bilaspur");
    strcpy(station[33],"dhanbad");
    strcpy(station[34],"hyderabad_decan");
    strcpy(station[35],"howrah");
    strcpy(station[36],"jaipur");
    strcpy(station[37],"lucknow");
    strcpy(station[38],"nagarsol");
    strcpy(station[39],"patliputra");
    strcpy(station[40],"shmata_vd_katra");
    strcpy(station[41],"sainagar_shirdi");
    strcpy(station[42],"tirupati");
    strcpy(station[43],"vijayawada");
    strcpy(station[44],"vasco_da_gama");
    strcpy(station[45],"haldia");
    strcpy(station[46],"indore_jn_bg");
    strcpy(station[47],"korba");
    strcpy(station[48],"erode_jn");
    strcpy(station[49],"visakhapatnam");
    strcpy(station[50],"shalimar");
    strcpy(station[51],"puri");
 
    train[0][0]=22651;
    train[0][1]=-1;    
    train[1][0]=6014;
    train[1][1]=6008;
    train[1][2]=6100;
    train[1][3]=82634;
    train[1][4]=57240;
    train[1][5]=6042;
    train[1][6]=6060;
    train[1][7]=6048;
    train[1][8]=6052;
    train[1][9]=20602;
    train[1][10]=82640;
    train[1][11]=56002;
    train[1][12]=12674;
    train[1][13]=12682;
    train[1][14]=22825;
    train[1][15]=6050;
    train[1][16]=82620;
    train[1][17]=6038;
    train[1][18]=6076;
    train[1][19]=17313;
    train[1][20]=80841;
    train[1][21]=82652;
    train[1][22]=6221;
    train[1][23]=82636;
    train[1][24]=6062;
    train[1][25]=-1;
    train[2][0]=57239;
    train[2][1]=-1;
    train[3][0]=20601;
    train[3][1]=22205;
    train[3][2]=-1;
    train[4][0]=6041;
    train[4][1]=12512;
    train[4][2]=-1;
    train[5][0]=6047;
    train[5][1]=12624;
    train[5][2]=12695;
    train[5][3]=12697;
    train[5][4]=22207;
    train[5][5]=22645;
    train[5][6]=22647;
    train[5][7]=-1;
    train[6][0]=6051;
    train[6][1]=82611;
    train[6][2]=19419;
    train[6][3]=22919;
    train[6][4]=-1;
    train[7][0]=82635;
    train[7][1]=6049;
    train[7][2]=6007;
    train[7][3]=-1;
    train[8][0]=82633;
    train[8][1]=82641;
    train[8][2]=82637;
    train[8][3]=82639;
    train[8][4]=6037;
    train[8][5]=12522;
    train[8][6]=82631;
    train[8][7]=-1;
    train[9][0]=22690;
    train[9][1]=6075;
    train[9][2]=12640;
    train[9][3]=12658;
    train[9][4]=22625;
    train[9][5]=12027;
    train[9][6]=-1;
    train[10][0]=56001;
    train[10][1]=-1;
    train[11][0]=82607;
    train[11][1]=12690;
    train[11][2]=-1;
    train[12][0]=6089;
    train[12][1]=16089;
    train[12][2]=-1;
    train[13][0]=82619;
    train[13][1]=82613;
    train[13][2]=12676;
    train[13][3]=12680;
    train[13][4]=12970;
    train[13][5]=12244;
    train[13][6]=-1;
    train[14][0]=82614;
    train[14][1]=82842;
    train[14][2]=22808;
    train[14][3]=6058;
    train[14][4]=6058;
    train[14][5]=22808;
    train[14][6]=-1;
    train[15][0]=6059;
    train[15][1]=-1;
    train[16][0]=17314;
    train[16][1]=22698;
    train[16][2]=-1;
    train[17][0]=6222;
    train[17][1]=-1;
    train[18][0]=12672;
    train[18][1]=-1;
    train[19][0]=12686;
    train[19][1]=22637;
    train[19][2]=-1;
    train[20][0]=11073;
    train[20][1]=-1;
    train[21][0]=12434;
    train[21][1]=12612;
    train[21][2]=12269;
    train[21][3]=-1;
    train[22][0]=12511;
    train[22][1]=-1;
    train[23][0]=12521;
    train[23][1]=-1;
    train[24][0]=12551;
    train[24][1]=22351;
    train[24][2]=12292;
    train[24][3]=2524;
    train[24][4]=-1;
    train[25][0]=12552;
    train[25][1]=-1;
    train[26][0]=12577;
    train[26][1]=-1;
    train[27][0]=12578;
    train[27][1]=12610;
    train[27][2]=16021;
    train[27][3]=22682;
    train[27][4]=12007;
    train[27][5]=-1;
    train[28][0]=12616;
    train[28][1]=12622;
    train[28][2]=-1;
    train[29][0]=12670;
    train[29][1]=-1;
    train[30][0]=13351;
    train[30][1]=22639;
    train[30][2]=-1;
    train[31][0]=12829;
    train[31][1]=-1;
    train[32][0]=12852;
    train[32][1]=-1;
    train[33][0]=13352;
    train[33][1]=-1;
    train[34][0]=12759;
    train[34][1]=-1;
    train[35][0]=12840;
    train[35][1]=12842;
    train[35][2]=-1;
    train[36][0]=12967;
    train[36][1]=12969;
    train[36][2]=-1;
    train[37][0]=16093;
    train[37][1]=-1;
    train[38][0]=16003;
    train[38][1]=-1;
    train[39][0]=22352;
    train[39][1]=-1;
    train[40][0]=16031;
    train[40][1]=-1;
    train[41][0]=22601;
    train[41][1]=-1;
    train[42][0]=16053;
    train[42][1]=16057;
    train[42][2]=16203;
    train[42][3]=-1;
    train[43][0]=12712;
    train[43][1]=12077;
    train[43][2]=-1;
    train[44][0]=17311;
    train[44][1]=-1;
    train[45][0]=22613;
    train[45][1]=-1;
    train[46][0]=22646;
    train[46][1]=-1;
    train[47][0]=22648;
    train[47][1]=-1;
    train[48][0]=22649;
    train[48][1]=-1;
    train[49][0]=22802;
    train[49][1]=22870;
    train[49][2]=-1;
    train[50][0]=22826;
    train[50][1]=-1;
    train[51][0]=22860;
    train[51][1]=-1;

    retry:
      printf("City(station) entered must be in lowercase letters\nIn case of spaces please use _ (underscore)\n");
      printf("Enter city(stn) to travel to:\n");
    scanf("%s",choice);
    printf("These train number  will go to the %s station\n",choice);
    for(i=0;i<52;i++){
        if(strcmp(station[i],choice)==0)
             {
               break;
             }
    }
       if(strcmp(station[i],choice)!=0)
            { 
               printf("No trains available\n");
               goto retry;
            }
    for(j=0;train[i][j]!=-1;j++)
     {
       k=train[i][j];
       if((k/10000)!=0)  
         printf("%d\n",train[i][j]); 
       else
         printf("%d%d\n",0,train[i][j]);
      } 
     printf("Do you wish to search for another city?(yes/no)\n");
     scanf("%s",opt);
     if(strcmp(opt,"yes")==0)
        goto retry;
     else
    printf("Thank you");

    int choose, status=0,canc=0, reg=0;
	start=NULL;
	rear=NULL;
	front=NULL;
	
	
	
	printf("\t\t\t**RAILWAY RESERVATION**\t\t\t\t\n");
	int ch =0;
	while(ch!=4)
	{
	printf("\n\nDo you want to - \n 1. Book a ticket \n 2. Cancel Booking \n 3. Display passenger details \n 4. exit\n\n");
	scanf("%d", &choose); 
	switch(choose)
	{	
		case 1 :  status=reserve(start);
	              if(status==0)
	                printf("\nBooking Full!! \nYou are added to waiting list. Waiting list number %d", count);
	              else if(status == -1) {
                      printf("\n age not eligible");
                  }
                  else
	                printf(" \nBooking Successful!!! Enjoy your journey! Your Reg No is %d\n\n", num);
	                
	              break;
	        
	    case 2:   printf(" \n Give the Registration number to be cancelled\n");
	              scanf(" %d", &reg);
	              if(reg>num)
	              printf("Invalid!!");
	              else
	              {
	              canc=cancel(reg);
	              if(canc==-1)
	              	printf("\nRegistration number invalid!!\n");
	              else
	              	printf("\nRegistration cancelled successfully\n");
	              	}
	              break;
	              
	    case 3: display();
	    break;
	    case 4: exit(0);   
	    break;
	    default: printf("\nWrong choice!\n");
  }
  }
  




return 0;
}
 
 
 

 
 
 
 
 