#include<iostream>
using namespace std;
class BaseClass
{
	protected:
		string name;
		int count;
		int id;
	public:
		virtual void add()=0;
		virtual void edit()=0;
		virtual bool search(int idIn)=0;
		virtual bool check(string nameIn)=0;
		virtual bool check(int id)=0;
		virtual void deleteIN()=0;
		virtual void List_all()=0;
		virtual int getIndex(int idIn)=0;
};



class Employee : public BaseClass
{private:
	int age;

public:	

	Employee()
	{
		count=0;
	}
		void add();
		void edit();
		bool search(int idIn);
		bool check(string nameIn);
		bool check(int id);
		void deleteIN();
		void List_all();
		int getIndex(int idIn);
};

class Department : public BaseClass
{
	public:
		Department()
		{
			count=0;
		}
		void add();
		void edit();
		bool search(int idIn);
		bool check(string nameIn);
		bool check(int id);
		void deleteIN();
		void List_all();
		int getIndex(int idIn);
		
		
};
Employee emp[20];
Department dept[20];


	void Employee::add()
	{cout<<"Enter the number of Employees you want to add : ";
	cin>>count;
	int i=0;
		while(i<count)
		{	
				cout<<"Enter the Data of Employee "<<i+1<<" : "<<endl;	
				cout<<"Enter the Employee ID : ";
				cin>>id;
				cout<<"Enter the Employee Name : ";
				cin>>name;
				cout<<"Enter the Age of Employee : ";
				cin>>age;
			
				if(!check(name))
					{
						emp[i].name=name;
						emp[i].age=age;
						emp[i].id=id;
						cout<<"ID of this Employee is : "<<id<<endl;
						cout<<"Employee Details Successfully Added !! "<<endl;	
					}
				else
					cout<<"THIS ENTRY ALREADY EXIST !! "<<endl;
			i++;
			cout<<"__________________________________"<<endl;
		}
				
	}
	
	void Employee::edit()
			{	cout<<"Enter the Employee ID : ";
				cin>>id;
	
				if(search(id))
				{
						
							cout<<"Enter the New Name : ";
							cin>>name;
							cout<<"Enter the New Age : ";
							cin>>age;
							int i=getIndex(id);
							emp[i].name=name;
							emp[i].age=age;
							cout<<"Employee Details Successfully Edited !! "<<endl;	
				}
				else
					cout<<"Employee with this ID doesn't exists"<<endl;
				
			}
		
	void Employee::deleteIN()
			{
				cout<<"Enter the ID of Employee you want to delete : ";
				cin>>id;
				if(check(id))
				{	int i=getIndex(id);
							for(int j=i;j<count;j++)
							{
								emp[j].name=emp[j+1].name;
								emp[j].id=emp[j+1].id;
								emp[j].age=emp[j+1].age;
							}
						cout<<"Employee Details Successfully Deleted !! "<<endl;	
				}
				else
					cout<<"Employee with this ID doesn't exists"<<endl;
					List_all();
			}

	int Employee::getIndex(int idIn)
		{
			for(int i=0;i<count;i++)
			{
				if(emp[i].id==idIn)
				return i;
			}
			return 0;
		}
						
	bool Employee::check(string nameIn)
		{
			for(int i=0;i<count;i++)
			{
				if(emp[i].name==nameIn)
				{
					return 1;	
				}
				
			}
		return 0;
		}
		
	bool Employee::check(int idIn)
		{
			for(int i=0;i<count;i++)
			{
				if(emp[i].id==idIn)
				{
					return 1;	
				}
				
			}
		return 0;
		}
		
		
		bool Employee:: search(int idIn)
		{
		for(int i=0;i<count;i++)
		{
			if(emp[i].id==idIn)
			{cout<<"_________________________"<<endl;
				cout<<"Employee Details"<<endl;	
				cout<<"ID : "<<emp[i].id<<endl;
				cout<<"Name : "<<emp[i].name<<endl;
				cout<<"Age : "<<emp[i].age<<endl;
			cout<<"_________________________"<<endl;
				return 1;
			}
		}
		return 0;	
		}
	
		void Employee:: List_all()
		{
			cout<<"LISTING ALL EMPLOYEES : "<<endl;
			cout<<"---------------------------"<<endl;
			cout<<"ID\t\tNAME\t\tAGE"<<endl;
			for(int i=0;i<count;i++)
			{
				cout<<emp[i].id<<"\t\t"<<emp[i].name<<"\t\t"<<emp[i].age<<endl;
			}
				cout<<"---------------------------"<<endl;
		}
			




		void Department:: List_all()
		{
			cout<<"LISTING ALL DEPARTMENT : "<<endl;
			cout<<"DEPT. ID.\t\tNAME"<<endl;
			cout<<"---------------------------"<<endl;
			for(int i=0;i<count;i++)
			{
				cout<<dept[i].id<<"\t\t"<<dept[i].name<<endl;
			}
			cout<<"---------------------------"<<endl;
		}
		
		void Department::add()
		{cout<<"Enter the number of Departments you want to add : ";
			cin>>count;
			int i=0;  
		while(i<count)
			{
				cout<<"Enter the Department ID : ";
				cin>>id;
				cout<<"Enter the Department Name : ";
				cin>>name;
			
				if(!check(name))
					{
						dept[i].name=name;
						dept[i].id=id;
						cout<<"ID of this Department is : "<<id<<endl;
						cout<<"Department Details Successfully Added !! "<<endl;
					}
				else
					cout<<"THIS ENTRY ALREADY EXIST !! "<<endl;
				
				i++;
				cout<<"____________________________________"<<endl;
			}
				
				
		}

		int Department::getIndex(int idIn)
		{
			for(int i=0;i<count;i++)
			{
				if(dept[i].id==idIn)
				return i;
			}
			return 0;
		}

		void Department::edit()
		{	cout<<"Enter the Department ID : ";
			cin>>id;
			int name;
			if(search(id))
			{
						cout<<"_________"<<endl;
						cout<<"Enter the New Name : ";
						cin>>name;
						int i=getIndex(id);
						dept[i].name=name;
						cout<<"Department Details Successfully Edited !! "<<endl;
						cout<<"____________________________________________"<<endl;
			}
			else
				cout<<"Department with this ID doesn't exists"<<endl;
			
		}
		
		void Department::deleteIN()
		{
			cout<<"Enter the ID of Department you want to delete : ";
			cin>>id;
			int i=getIndex(id);
			for(int j=i;j<count;j++)
			{
				dept[j].name=dept[j+1].name;
				dept[j].id=dept[j+1].id;
				
			}
			cout<<"Department Details Successfully Deleted !! "<<endl;
		}
		
		bool Department::check(int idIn)
		{for(int i=0;i<count;i++)
		{
			if(dept[i].id==idIn)
			{
				return 1;	
			}
			
		}
		return 0;
		}

		bool Department::check(string nameIn)
		{for(int i=0;i<count;i++)
		{
			if(dept[i].name==nameIn)
			{
				return 1;	
			}
			
		}
		return 0;
		}
		
		bool Department::search(int idIn)
		{
		for(int i=0;i<count;i++)
		{
			if(dept[i].id==idIn)
			{cout<<"Department Details"<<endl;
			cout<<"_________________________"<<endl;
				cout<<"name : "<<dept[i].name<<endl;
				cout<<"ID : "<<dept[i].id<<endl;
			cout<<"_________________________"<<endl;
				return 1;
			}
		}
		return 0;
			
		}




	

int main()
{char c;
	Employee e;
	Department d;
	do
	{
	cout<<"*************MENU*************"<<endl;
	cout<<"1.) Add Employee"<<endl;
	cout<<"2.) Edit Employee"<<endl;
	cout<<"3.) Delete Employee"<<endl;
	cout<<"4.) List All Employee"<<endl;
	cout<<"5.) Add Department "<<endl;
	cout<<"6.) Edit Department "<<endl;
	cout<<"7.) Delete Employee"<<endl;
	cout<<"8.) list Department "<<endl;
	cout<<"9.) Exit "<<endl;
	cout<<"******************************"<<endl;
	int choice;
	cout<<"Enter your choice : ";
	cin>>choice;

cout<"cvmbhjv";

		 if(choice==1)
			{
				e.add();
			}
		else if(choice==2)
			{
			e.edit();
			}

		else if(choice==3)
			{
			e.deleteIN();
			}

		else if(choice==4)
			{
			e.List_all();
			}

		else if(choice==5)
			{
			d.add();
			}

		else if(choice==6)
			{
			d.edit();
			}

		else if(choice==7)
			{
			d.deleteIN();
			}

		else if(choice==8)
			{
			d.List_all();
			}

		else if(choice==9)
			{
			exit(6);
			}
		else
			cout<<"Invalid choice "<<endl;

	cout<<"Do you Want to continue ? ";
	cin>>c;
	}while(c=='y');
	cout<<"Thankyou for using this program !! "<<endl;
	return 0;
}
