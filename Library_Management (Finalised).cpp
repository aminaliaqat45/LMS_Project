#include  <iostream>
#include  <conio.h>
using namespace std;                          

 //Encapsulates the password working logic   
class library{
	private:
		struct Node
		{
			int id;
			int day, month, year;
			string name,author,Student;
			Node *next_add;
		};
	public:
		Node *head = NULL;
		void menu();
		void insert();
		void search();
		void update();
		void del();
		void sort();
		void show();
};
void library::menu()
{
	p:
	system("cls");
	int choice;
	cout<<"\n\n\t\t\t============================================"<<endl;		//Main Menu
    cout<<"\n\n\t\t\t=        Library Management System         ="<<endl;
    cout<<"\n\n\t\t\t============================================"<<endl;
        cout<<"\n\n1. Insert New Book Record"<<endl;
        cout<<"\n\n2. Search Record"<<endl;
        cout<<"\n\n3. Update Record"<<endl;
        cout<<"\n\n4. Delete Record"<<endl;        
        cout<<"\n\n5. Show all Records"<<endl;
        cout<<"\n\n6. Exit"<<endl;
        cout<<"______________________________________"<<endl;
        cout<<"Enter the option.no: ";
        cin>>choice;
        cout<<endl;
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
        	search();
            break;
        case 3:
        	update();
            break;
        case 4:
        	del();
            break;
        case 5:
        	sort();
        	show();
            break;
        case 6:
            exit(0);
            break;    
        default:
            cout<<"Invalid number input\n";
            
        }
        getch();
        goto p;
}
   

 void library::insert()
    {
    	system("cls");
	    cout<<"\n\n\t\t\t============================================"<<endl;		//Main Heading for Style
        cout<<"\n\n\t\t\t=        Library Management System         ="<<endl;
        cout<<"\n\n\t\t\t============================================"<<endl;
        Node *new_node =new Node;
        cout<<"\n\n Book ID : ";
        cin>>new_node  -> id;
        cout<<"\n\n Book Name  : ";
        cin>>new_node  -> name;
        cout<<"\n\n Author Name :";
        cin>>new_node ->author;
        cout<<"\n\n Student Name :";
        cin>>new_node ->Student;
		cout<<"\n\n Date of issuance ";
		cout<<" Day:";
		cin>>new_node ->day;
		cout<<" Month:";
		cin>>new_node ->month;
		cout<<" Year:";
		cin>>new_node ->year;

        new_node -> next_add = NULL;
        if(head==NULL)
        {
        	head = new_node;
		}
		else
		{
			Node *ptr = head;
			while(ptr -> next_add !=NULL)
			{
				ptr = ptr -> next_add;
			}
			ptr -> next_add = new_node;
		}
		cout<<"\n\n\t\tNew Book Inserted Successfully..... ";
        
        
	}
	void library::search()
	{
		system("cls");
		int t_id,found=0;
	    cout<<"\n\n\t\t\t============================================"<<endl;		//Main heading for style
        cout<<"\n\n\t\t\t=        Library Management System         ="<<endl;
        cout<<"\n\n\t\t\t============================================"<<endl;
        if(head == NULL)
        {
        	cout<<"\n\n Linked List is Empty....";
		}
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>t_id;
			Node *ptr = head;
			while(ptr!=NULL)
			{
				if(t_id == ptr -> id)
				{
					system("cls");
	                cout<<"\n\n\t\t\t============================================"<<endl;		//Main heading for style
                    cout<<"\n\n\t\t\t=        Library Management System         ="<<endl;
                    cout<<"\n\n\t\t\t============================================"<<endl;
					cout<<"\n\n Book ID : "<<ptr -> id;
					cout<<"\n\n Book Name :"<<ptr -> name;
					cout<<"\n\n Author Name :"<<ptr -> author;
					cout<<"\n\n Student Name :"<<ptr -> Student;
					cout<<"\n\n Date of issue "<<"(Day: "<<ptr -> day<<"/Month: "<<ptr -> month<<"/Year: "<<ptr -> year<<")";
					found++;
					
				}
				ptr = ptr -> next_add;
			}
			if(found == 0)
			{
				cout<<"\n\n Book ID is invalid.....";
			}
		}
	}
	void library::update()
	{
		
		system("cls");
		int t_id,found=0;
	    cout<<"\n\n\t\t\t============================================"<<endl;		//Main Menu
        cout<<"\n\n\t\t\t=        Library Management System         ="<<endl;
        cout<<"\n\n\t\t\t============================================"<<endl;
        if(head == NULL)
        {
        	cout<<"\n\n Linked List is Empty....";
		}
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>t_id;
			Node *ptr = head;
			while(ptr!=NULL)
			{
				if(t_id == ptr -> id)
				{
					system("cls");
	                cout<<"\n\n\t\t\t============================================"<<endl;		//Main Menu
                    cout<<"\n\n\t\t\t=        Library Management System         ="<<endl;
                    cout<<"\n\n\t\t\t============================================"<<endl;
					cout<<"\n\n Book ID : ";
					cin>>ptr -> id;
					cout<<"\n\n Book Nmae :";
					cin>>ptr -> name;
					cout<<"\n\n Author Name :";
					cin>>ptr -> author;
					cout<<"\n\n Student Name :";
					cin>>ptr -> Student;
					cout<<"\n\n Date of issue "<<"(Day: "<<ptr -> day<<"/ Month: "<<ptr -> month<<"/ Year: "<<ptr -> year<<")";
					found++;
					cout<<"\n\n\t\tUpdate Book Successfully...";
					
				}
				ptr = ptr -> next_add;
			}
			if(found == 0)
			{
				cout<<"\n\n Book ID is invalid.....";
			}
		}
	}
	void library::del()
	{
		
		system("cls");
		int t_id,found=0;
	    cout<<"\n\n\t\t\t============================================"<<endl;		//Main Menu
        cout<<"\n\n\t\t\t=        Library Management System         ="<<endl;
        cout<<"\n\n\t\t\t============================================"<<endl;
        if(head == NULL)
        {
        	cout<<"\n\n Linked List is Empty....";
		}
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>t_id;
			if(t_id == head -> id)
			{
				Node *ptr = head;
				head = head -> next_add;
				delete ptr;
				cout<<"\n\n Delete Book Successfully....";
				found++;
			}
			else
			{
				Node *pre = head;
				Node *ptr = head;
				while(ptr != NULL)
				{
					if(t_id == ptr -> id)
					{
						pre -> next_add = ptr -> next_add;
						delete ptr;
						cout<<"\n\n Delete Book Successfully....";
						found++;
						break;
					}
					pre = ptr;
					ptr = ptr -> next_add;
				}
			}
			if(found ==0)
			{
				cout<<"\n\n Book is Invalid....";
			}
		}
	}
	void library::sort()
	{
		if(head == NULL)
		{
			system("cls");
			cout<<"\n\n\t\t\t============================================"<<endl;		//Main Menu
            cout<<"\n\n\t\t\t=        Library Management System         ="<<endl;
            cout<<"\n\n\t\t\t============================================"<<endl;
			cout<<"\n\nLinked List is Empty....";
			getch();
			menu();
		}
		int count=0,t_id;
		string t_name,t_author,t_Student;
		Node *ptr = head;
		while(ptr !=NULL)
		{
			count++;
			ptr = ptr -> next_add;
			
		}
		for(int i=1;i<=count;i++)
		{
			Node *ptr = head;
			for(int j=1;j<count;j++)
			{
				if(ptr -> id > ptr -> next_add -> id)
				{
					// Save data into temporary variable
					t_id = ptr-> id;
					t_name = ptr -> name;
					t_author = ptr -> author;
					t_Student = ptr -> Student;
					// save data into current node
					ptr -> id = ptr -> next_add -> id;
					ptr -> name = ptr -> next_add -> name;
					ptr -> author = ptr -> next_add -> author;
					ptr -> Student = ptr -> next_add -> Student;
					// save data into next node
					ptr -> next_add -> id = t_id;
					ptr -> next_add -> name = t_name;
					ptr -> next_add -> author = t_author;
					ptr -> next_add -> Student = t_Student;
				}
				ptr = ptr -> next_add;
			}
		}
	}
	void library::show()
	{
		system("cls");
	    cout<<"\n\n\t\t\t============================================"<<endl;		//Main Menu
        cout<<"\n\n\t\t\t=        Library Management System         ="<<endl;
        cout<<"\n\n\t\t\t============================================"<<endl;
			Node *ptr = head;
			while(ptr!=NULL)
			{
				cout<<"\n\n Book ID : "<<ptr -> id;
				cout<<"\n\n Book Name :"<<ptr -> name;
				cout<<"\n\n Author Name :"<<ptr -> author;
				cout<<"\n\n Student Name :"<<ptr -> Student;
				cout<<"\n\n Date of issue "<<"(Day: "<<ptr -> day<<"/ Month: "<<ptr -> month<<"/ Year: "<<ptr -> year<<")";
				cout<<"\n\n\n===================================";
				ptr = ptr -> next_add;
		    }
		
	}

	


int main()
{ 
	library obj;
	 cout<<"\n\t\t===================================="<<endl;
    cout<<"\n\t\t=     Library Management System    ="<<endl;
    cout<<"\n\t\t===================================="<<endl;
    cout<<"\n\t\t              Welcome!              "<<endl;
    string user_name;
    cout<<"\tEnter your name: ";
    cin>>user_name;
    cout<<"\tHello "<<user_name<<" !"<<endl;
    int attempts=0;                                                  //Checker for condition
    while (attempts<3)
    {
        int pass_word;
        cout<<"\tEnter Password: ";
        cin>>pass_word;
        if(pass_word==0000){
        cout<<"\tYour password is correct. Access Granted"<<endl;
		obj.menu();
        }
        else{
        cout<<"\tYour password is incorrect"<<endl;
        }
        attempts++;
    }
    if(attempts == 3) {                                                 //Specifier for the number of attempts
        cout <<"You've exceeded the maximum number of attempts. Access denied." <<endl;
    }
}
 
