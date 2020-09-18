
#include<string>
#define MAX 30
#include<iostream>
// Doubly Linked List
using namespace std;

struct employee
{
	int E_ID;
	char E_Name[20];
	char P_Name[20];
	int salary;
	int Age;
	struct employee* next;
	struct employee *prev;
};

typedef struct employee NODE;
typedef struct employee* PNODE;
typedef struct employee** PPNODE;

class Employee
{
	public:
		PNODE Head;
		int iSize;
		
		Employee()
		{
			Head=NULL;
			iSize=0;
		}
		
		
		
		
	void InsertLast(int E_ID,char E_Name1[],char P_Name1[],int sal,int age)
	{
		PNODE employn=NULL;
		int i=0,j=0;
		employn=new NODE;
		employn->next=NULL;
		employn->prev=NULL;
	
		employn->E_ID=E_ID;
		while((E_Name1[i]!='\0'))
		{
			employn->E_Name[i]=E_Name1[i];
		
			i++;
		}
		while((P_Name1[j]!='\0'))
		{
		
			employn->P_Name[j]=P_Name1[j];
			j++;
		}
	
		employn->salary=sal;
		employn->Age=age;
	
	
		if(Head==NULL)
		{
			Head=employn;
					
		}
		else
		{
			PNODE temp=Head;
			
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=employn;
			employn->prev=temp;
		}	
		iSize++;
	
	}

	void DeleteByID(int ID)
	{
		PNODE temp=Head;
		PNODE temp2=NULL;
		PNODE temp3=NULL;
		int id=0;
		
		if(Head==NULL)
		{
			printf("No records found: \n");
			return;
		}
		
		else if((Head)->next==NULL)
		{
			delete Head;
			Head=NULL;		
		}
		
		else if(ID==Head->E_ID)
		{
			Head=(Head)->next;
			delete (Head)->prev;
			(Head)->prev=NULL;
		}
		
		else
		{
			while(temp!=NULL)
			{
				id=temp->E_ID;
				
				if(id==ID)
				{
					if(temp->next==NULL)
					{
						temp3=temp;
						temp3->prev->next=NULL;
						delete temp3;
					}
					else
					{
						temp2=temp;
						temp->prev->next=temp2->next;
						temp2->next->prev=temp2->prev;
						delete temp2;
						break;
					}
					
				}
				temp=temp->next;
				
			}
		
		}
		printf("Record deleted: \n");
		iSize--;
	}
	
	
	void Display()
	{
		PNODE temp=Head;
		int icnt=0;
		while(temp!=NULL)
		{
			icnt++;
			
			cout<<"\n";
			cout<<" Employees info :"<<icnt;
			cout<<" ID is: "<<temp->E_ID<<"\n";
			cout<<" Name is: "<<temp->E_Name<<"\n";
			cout<<" Salary is: "<<temp->salary<<"\n";	
			
			
			temp=temp->next;
		}
	
		
	}
	
	void DisplayByID(int ID)
	{
		PNODE temp=Head;
		while(temp!=NULL)
		{
			
			if(ID==temp->E_ID)
			{
				cout<<"Name is: "<<temp->E_Name<<"\n";
				cout<<"Salary is: "<<temp->salary<<"\n";	
			}
			
			temp=temp->next;
		}
	
	}
	
	/*void DisplayByAlpha()
	{
		PNODE temp=Head;
		char alpha[30];
		char alpha1[30];
		int i=0;
		while(temp->E_Name[i]!='\0')
		{
			alpha[i]=temp->E_Name[i];
			i++;
			temp=temp->next;
		}
		int j=0;
		while(temp->next->E_Name[j]!='\0')
		{
			alpha1[j]=temp->next->E_Name[j];
			j++;
			temp=temp->next;
		}
		
		if(alpha[k])
		
	}
	*/


	int Count()
	{
		return iSize;
	}

		
				
};


int main()
{
	
	Employee obj;
	
	int e_ID=0,sal=0;
	char E_Name[MAX];
	char P_Name[MAX];
	char ch2;
	int age=0;
	int N,i;
	int ch1=0,ch=1;
	while(ch!=0)
	{
		
	
	printf("\nEnter your choice: \n");

	cout<<"1. Add Employee.\n";
	cout<<"2. Display \n";
	cout<<"3. Display By ID\n";
	cout<<"4. Count: \n";
	cout<<"5. Delete By ID \n";
	cout<<"6. Display by Alpha.\n";
	int res,i;
	cin>>ch1;
	switch(ch1)
	{
		case 1:
			{
				cout<<"Enter no of Employee to add: \n";
				cin>>N;
				for(i=1;i<=N;i++)
				{
					cout<<"Enter E_ID to add: \n";
					cin>>e_ID;
					
					cout<<"\nEnter E_name to add: \n";
					fflush(stdin);
					cin.getline (E_Name, MAX); 
				
					
					cout<<"\nEnter Project name to add: \n";
					cin.getline (P_Name, MAX);
					
					cout<<"\nEnter"<<i<<" Salary to add: \n";
					cin>>sal;
					
					cout<<"\nEnter"<<i<<" Age to add: \n";
					cin>>age;
					obj.InsertLast(e_ID,E_Name,P_Name,sal,age);
					
				}
				break;
			}
			
		case 2:
			{
				obj.Display();
				break;
			}
		
		case 3:
			{
				int ID=0;
				cout<<"Enter ID to display info: \n";
				cin>>ID;
				
				obj.DisplayByID(ID);
				break;
			}
			
		case 4:
			{
				int ret=0;
				ret=obj.Count();
				cout<<"No of employyee are:"<<ret;
				break;
			}
			
		case 5:
			{
				int ID=0;
				cout<<"Enter ID to delete: \n";
				cin>>ID;
				obj.DeleteByID(ID);
				break;
			}
			
	/*	case 6:
			{
				obj.DisplayByAlpha();
				break;
			}
	*/		
		default:
			cout<<"Do u want to continue: \n";
			cout<<"press 1-> continue.... 0-> exit. \n";
			cin>>ch;

	}
		
	}
	
	return 0;	
} 
