#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>
#include <fstream>
using namespace std;
int count=0,count1=0,count2=0;
int P1=0,P2=0,P3=0,P4=0;
using namespace std;
class Admin
{
	private:
    string password = "programmer";
   
   friend class Password;
		
};
class Password: private Admin
{
	public:
		Password(Admin a, string pasword)
		{
		    if (a.password == pasword)
	        {
	            cout << "Login successfully" << endl;
	        }
	        else
	        {
	            cout << "Invalid password" << endl;
	            exit(0); 
	        }	
		}
};	
class Person
{
	public:
		string name,  ph_no, resident;
		int id;
		int  age, studentClass;
		string gender ;
	
};
class Student: public Person
{
   
	public:
		 int	fee_primary, fee_middle, fee_matric, fee_inter;
		   int marks[5];
	
	void CheckInFees(Student s[], int n );
	int	StudentFees (Student s[], int roll_num);
	int displayStudent(Student s[], int n);
	 void saveInFile(Student s[], int n);
	 void addStudent (Student s[],int n);
    virtual void classSection(Student s[]);
	int generateAttendanceReport(Student s[], int roll_num) ;
	int generateFine(Student s[], int roll_number);
	void  validateSubjectMarks(int marks[], int index);
	void generateAcademicReport(Student s[], int roll_number);
};
		void Student:: saveInFile(Student s[], int n)
		 {
		    ofstream out;
		    out.open("student.txt", ios::out | ios::app);
		    if (out.fail()) 
			{
		        cout << "\nError Opening File." << endl;
		        return;
		    }
		
		    for (int i = count2; i < n+count2; i++) 
			{
		        out << s[i].id << endl;
		        out << s[i].name << endl;
		        out << s[i].ph_no << endl;
		        out << s[i].resident << endl;
		        out << s[i].studentClass << endl;
		        out << s[i].gender << endl;
		        out << s[i].age << endl;
		    }
		    count2 = count2+n;
		
		    out.close();
		}
	void Student::CheckInFees(Student s[], int n )
		{
           ifstream checkin;
           checkin.open("Student.txt", ios::in | ios::app);
			for (int i=0; i<n;i++)
			{
				if (s[i].studentClass >=1 && s[i].studentClass <= 5)
				{
					P1++;
				}
				else if (s[i].studentClass >=6 && s[i].studentClass <= 8)
				{
					P2++;
				}
				else if (s[i].studentClass >=9 && s[i].studentClass <= 10)
				{
					P3++;
				}
				else if (s[i].studentClass >=11 && s[i].studentClass <= 12)
				{
					P4++;
				}
	    	}
	    	if (P1 > 0)
	    	{
	    		cout <<"Primary Level Student : " << P1 << endl;
	    		cout <<"Total Fees Of '" <<P1  <<"' Students: ";
	        	fee_primary = P1 * 2500;
	    		cout <<fee_primary << endl;
			}
			 if (P2 > 0)
	    	{
	    		cout <<"Middle Level Student : " << P2 << endl;
	    		cout <<"Total Fees Of '" <<P2  <<"' Students: ";
	    	    fee_middle = P2 * 3500;
	    		cout <<fee_middle << endl;
			}
			 if (P3 > 0)
	    	{
	    		cout <<"Matric Level Student : " << P3 << endl;
	    		cout <<"Total Fees Of '" <<P3  <<"' Students: ";
	    		fee_matric = P3 * 4500;
	    		cout <<fee_matric << endl;
			}
			 if (P4 > 0)
	    	{
	    		cout <<"Inter Level Student : " << P4 << endl;
	    		cout <<"Total Fees Of '" <<P4  <<"' Students: ";
	    		fee_inter = P4 *6000;
	    		cout <<fee_inter<< endl;
			}
		}
       
 int Student::StudentFees(Student s[], int roll_num)
		{
		int i=0;
		  system("cls");
		 ifstream studentFile;
		  studentFile.open("student.txt", ios::app  |ios::in);
		 if (studentFile.fail())
		  {
		  		cout <<"\nError Opening File."<< endl;
		  		return 0;
		  }
   		 while (!studentFile.eof())
		  {
		 //studentFile.read((char *)&s[c], sizeof(Student));
			studentFile >> s[i].id;
			studentFile.ignore();
		   	getline(studentFile, s[i].name);
		   	getline(studentFile, s[i].ph_no);
		   	getline(studentFile, s[i].resident);
		   	studentFile >> s[i].studentClass;
		   	studentFile >> s[i].gender;
		   	studentFile >> s[i].age;
			if (s[i].id == roll_num)
	        {
	        	cout <<"Student Fees Received Successfully\n";
	            cout << "Student ID: " << s[i].id << endl;
	            cout << "Student Name: " << s[i].name << endl;
	            cout << "Student Phone Number: " << s[i].ph_no << endl;
	            cout << "Student Class: " << s[i].studentClass << endl << endl;
	            studentFile.close();
	            return 1;
			}
			
		
		   	
		    	i++;
		  }
		  if (i == 0)
		  {
		  	  cout << "\nSorry! Student Fees Not Received Yet.\n";
		  }
		  
		}
		int Student::displayStudent(Student s[], int n)
		{
			int i=0;
			ifstream display;
			display.open("student.txt", ios::app | ios::in);
			if(display.fail())
			{
				cout <<"\nError Opening File\n";
				return 0;
			}
			while (!display.eof())
			{
				display >> s[i].id;
				display.ignore();
			   	getline(display, s[i].name);
			   	getline(display, s[i].ph_no);
			   	getline(display, s[i].resident);
			   	display >> s[i].studentClass;
			   	display >> s[i].gender;
			   	display >> s[i].age;
   				if ((s[i].id == n))
			    {
			    	 cout <<"\nRequired Student ID Displayed Successfully\n\n";
			    	 cout <<"ID: " << s[i].id << endl;
		      		 cout <<"Name: " << s[i].name << endl;
		      		 cout <<"Phone Number: " << s[i].ph_no << endl;
		      		 cout <<"Resident: " << s[i].resident << endl;
		      		 cout <<"Age: " << s[i].age << endl;
		      		 cout <<"Student Class: " << s[i].studentClass << endl;
		      		 cout <<"Gender: " << s[i].gender  << endl;
		      		 return 1;
		    	}
		    		i++;
			}
		display.close();
		if (i == 0)
		{
			cout <<"\nSorry! Student Data Not Displayed\n";
		}
	}
	void Student :: addStudent (Student s[],int n)
		{
		
			for (int i=count; i <n+count; i++)
			{
				cout <<i+1 <<". Primary Student Detail:" <<endl << endl;
				cout <<"Enter the name: ";
				cin.ignore();
				getline(cin, s[i].name);
				cout <<"Enter the Resident of student: ";
				getline(cin, s[i].resident);
				cout <<"Enter the Phone Number of student: ";
				getline(cin,s[i].ph_no);
				cout <<"Enter the ID: ";
				cin>> s[i].id;
				cout <<"Enter the Gender: ";
				cin >> s[i].gender;
				cout <<"Enter the Age: ";
				cin >> s[i].age;
				cout <<"Enter the student class: ";
		    	cin>>s[i].studentClass;	
		    }
		    
		    count =count +n;
	
		}	
class Primary: public Student
{
	public:
		void classSection(Student s[]);
};
class Middle: public Student
{
	public:
		void classSection(Student s[]);
};
class Matric: public Student
{
	public:
		void classSection(Student s[]);
};
class Inter: public Student
{
	public:
		void classSection(Student s[]);
};

void Student::classSection(Student s[]) 
 {
 	cout <<"\nTwo Section (A & B) => For Primary(1-5), Middle(6-8), Matric(9-10), Inter(11-12)\n\n";
 } 
		void Primary::classSection(Student s[])
		{
			int i=0;
			char section;
			ifstream primary;
			primary.open("student.txt", ios::app | ios::in);
			if (primary.fail())
			{
				cout <<"\nError Opening file\n\n";
			}
			while(!primary.eof())
			{
				primary >> s[i].id;
	     		primary.ignore();
		     	getline(primary, s[i].name);
    		   	getline(primary, s[i].ph_no);
    		   	getline(primary, s[i].resident);
    		   	primary >> s[i].studentClass;
    		   	primary >> s[i].gender;
			   	primary >> s[i].age;
			   if(P1 <= 20 )
			   {
			      section = 'A';
		          cout <<"\nPrimary Student: " << P1 << endl;
		          	if (s[i].studentClass >=1 && s[i].studentClass <=5 )
		          	{
	                     cout<<"\nClass Section: " <<section << endl;
	                     cout <<"ID: " << s[i].id << endl;
			      		 cout <<"Name: " << s[i].name << endl;
			      		 cout <<"Student Class: " << s[i].studentClass << endl;
			      		 cout <<"Gender: " << s[i].gender  << endl <<endl;     		
					}
		   		}
		   		  else if(P1 >= 20 )
				   {
				      section = 'B';
			          cout <<"\nPrimary Student: " << P1 << endl;
			          	if (s[i].studentClass >=1 && s[i].studentClass <=5 )
			          	{
		                     cout<<"\nClass Section: " <<section << endl;
		                     cout <<"ID: " << s[i].id << endl;
				      		 cout <<"Name: " << s[i].name << endl;
				      		 cout <<"Student Class: " << s[i].studentClass << endl;
				      		 cout <<"Gender: " << s[i].gender  << endl <<endl;     		
						}
			   		}
		     
		     i++;
		 }
			 primary.close();
		}
			
	void Middle::classSection(Student s[])
	 {
	 		int i=0;
			char section;
			ifstream middle;
			middle.open("student.txt", ios::app | ios::in);
			if (middle.fail())
			{
				cout <<"\nError Opening file\n\n";
			}
				
			while(!middle.eof())
			{
				middle >> s[i].id;
	     		middle.ignore();
		     	getline(middle, s[i].name);
    		   	getline(middle, s[i].ph_no);
    		   	getline(middle, s[i].resident);
    		   	middle >> s[i].studentClass;
    		   	middle >> s[i].gender;
			   	middle >> s[i].age;
			   if(P2 <= 20 )
			   {
			      section = 'A';
		          cout <<"\nMiddle Student: " << P2 << endl;
		          	if (s[i].studentClass >=6 && s[i].studentClass <=8 )
		          	{
	                     cout<<"\nClass Section: " <<section << endl;
	                     cout <<"ID: " << s[i].id << endl;
			      		 cout <<"Name: " << s[i].name << endl;
			      		 cout <<"Student Class: " << s[i].studentClass << endl;
			      		 cout <<"Gender: " << s[i].gender  << endl <<endl;     		
					}
		   		}
		   		  else if(P2 >= 20 )
				   {
				      section = 'B';
			          cout <<"\nMiddle Student: " << P2 << endl;
			          	if (s[i].studentClass >=6 && s[i].studentClass <=8 )
			          	{
		                     cout<<"\nClass Section: " <<section << endl;
		                     cout <<"ID: " << s[i].id << endl;
				      		 cout <<"Name: " << s[i].name << endl;
				      		 cout <<"Student Class: " << s[i].studentClass << endl;
				      		 cout <<"Gender: " << s[i].gender  << endl <<endl;     		
						}
			   		}
		     
		     i++;
		 }
			 middle.close();
	}
	
		void Matric::classSection(Student s[])
	 {
	 		int i=0;
			char section;
			ifstream matric;
			matric.open("student.txt", ios::app | ios::in);
			if (matric.fail())
			{
				cout <<"\nError Opening file\n\n";
			}
			while(!matric.eof())
			{
				matric >> s[i].id;
	     		matric.ignore();
		     	getline(matric, s[i].name);
    		   	getline(matric, s[i].ph_no);
    		   	getline(matric, s[i].resident);
    		   	matric >> s[i].studentClass;
    		   	matric >> s[i].gender;
			   	matric >> s[i].age;
			   if(P3 <= 20 )
			   {
			      section = 'A';
		          cout <<"\nMatric Student: " << P3 << endl;
		          	if (s[i].studentClass >=9 && s[i].studentClass <=10 )
		          	{
	                     cout<<"\nClass Section: " <<section << endl;
	                     cout <<"ID: " << s[i].id << endl;
			      		 cout <<"Name: " << s[i].name << endl;
			      		 cout <<"Student Class: " << s[i].studentClass << endl;
			      		 cout <<"Gender: " << s[i].gender  << endl <<endl;     		
					}
		   		}
		   		  else if(P3 >= 20 )
				   {
				      section = 'B';
			          cout <<"\nMatricStudent: " << P3 << endl;
			          	if (s[i].studentClass >=9 && s[i].studentClass <=10 )
			          	{
		                     cout<<"\nClass Section: " <<section << endl;
		                     cout <<"ID: " << s[i].id << endl;
				      		 cout <<"Name: " << s[i].name << endl;
				      		 cout <<"Student Class: " << s[i].studentClass << endl;
				      		 cout <<"Gender: " << s[i].gender  << endl <<endl;     		
						}
			   		}
		     
		     i++;
		 }
			 matric.close();
	}
	
		void Inter::classSection(Student s[])
	 {
	 		int i=0;
			char section;
			ifstream inter;
			inter.open("student.txt", ios::app | ios::in);
			if (inter.fail())
			{
				cout <<"\nError Opening file\n\n";
			}
			while(!inter.eof())
			{
				inter >> s[i].id;
	     		inter.ignore();
		     	getline(inter, s[i].name);
    		   	getline(inter, s[i].ph_no);
    		   	getline(inter, s[i].resident);
    		   	inter >> s[i].studentClass;
    		   	inter >> s[i].gender;
			   	inter >> s[i].age;
			   if(P4 <= 20 )
			   {
			      section = 'A';
		          cout <<"\nInter Student: " << P4 << endl;
		          	if (s[i].studentClass >=11 && s[i].studentClass <=12 )
		          	{
	                     cout<<"\nClass Section: " <<section << endl;
	                     cout <<"ID: " << s[i].id << endl;
			      		 cout <<"Name: " << s[i].name << endl;\
			      		 cout <<"Student Class: " << s[i].studentClass << endl;
			      		 cout <<"Gender: " << s[i].gender  << endl <<endl;     		
					}
		   		}
		   		  else if(P4 >= 20 )
				   {
				      section = 'B';
			          cout <<"\nInter Student: " << P3 << endl;
			          	if (s[i].studentClass >=9 && s[i].studentClass <=10 )
			          	{
		                     cout<<"\nClass Section: " <<section << endl;
		                     cout <<"ID: " << s[i].id << endl;
				      		 cout <<"Name: " << s[i].name << endl;
				      		 cout <<"Student Class: " << s[i].studentClass << endl;
				      		 cout <<"Gender: " << s[i].gender  << endl <<endl;     		
						}
			   		}
		     
		     i++;
		 }
			 inter.close();
	}
	
class searchStudent : public Student
{
	public:
		int idSearch(searchStudent ss[], int roll_num)
		{
			int i=0;
		 system("cls");
		 ifstream search;
		  search.open("student.txt", ios::app |ios::in );
	
		 if (search.fail())
		  {
		  		cout <<"\nError Opening File."<< endl;
		  		return 0;
		  }	
		   	 
    while (!search.eof())
		  {
		 //studentFile.read((char *)&s[c], sizeof(Student));
		    search >> ss[i].id;
			search.ignore();
		   	getline(search, ss[i].name);
		   	getline(search, ss[i].ph_no);
		   	getline(search, ss[i].resident);
		   	search >> ss[i].studentClass;
		   	search >> ss[i].gender;
		   	search >> ss[i].age;
			if (ss[i].id == roll_num)
	        {
	        	cout <<"\nCongratulation! Student Data Searched Successfully\n\n";
	            cout << "ID: " << ss[i].id << endl;
	            cout << "Name: " << ss[i].name << endl;
	            cout << "Phone Number: " << ss[i].ph_no << endl;
	            cout << "Resident: " << ss[i].resident << endl;
	            cout << "Age: " << ss[i].age << endl;
	            cout << "Student Class: " << ss[i].studentClass << endl;
	            cout << "Gender: " << ss[i].gender << endl;
	            return 1;
			}
			i++;
		
		   	
		    	
		  }
		  search.close();
		  if (i == 0)
		  {
		  	  cout << "Sorry, Roll number not found.";
		  }
	}
		  
};


class deleteStudent: public searchStudent
{
	public:
		int dltStudent(deleteStudent dt[], int roll_num)
		{
			int i=0;
		 system("cls");
		 ofstream write;
		  write.open("new.txt", ios::app | ios::out );
		  ifstream dlt;
		  dlt.open("student.txt", ios::app | ios::in);
		 if (write.fail())
		  {
		  		cout <<"\nError Opening File."<< endl;
		  		return 0;
		  }	
    while (!dlt.eof())
		  {
		 //studentFile.read((char *)&s[c], sizeof(Student));
		   	dlt >> dt[i].id;
		    dlt.ignore();
		   	getline(dlt, dt[i].name);
		   	getline(dlt, dt[i].ph_no);
		   	getline(dlt, dt[i].resident);
		   	dlt >> dt[i].studentClass;
		   	dlt >> dt[i].gender;
		   	dlt >> dt[i].age;
			if ((dt[i].id != roll_num))
	        {
	            write << dt[i].id << endl;
		        write << dt[i].name << endl;
		        write << dt[i].ph_no << endl;
		        write << dt[i].resident << endl;
		        write << dt[i].studentClass << endl;
		        write << dt[i].gender << endl;
		        write << dt[i].age << endl; 
			}
				i++;   
		    
		  }
		  dlt.close();
		  write.close();
		  remove("student.txt");
		  rename("new.txt", "student.txt");
		  
		  cout <<"\nCongratulation! Data Deleted Successfully.\n\n";
		  
		  //read.close();
		  if (i == 0)
		  {
		  	  cout << "Sorry, Student Data not found.";
		  }
	}
};


class UpdateStudent : public deleteStudent

{
	public:
		int updStudent(UpdateStudent upt[], int roll_num)
		{
		 system("cls");
		 int i=0;
		 UpdateStudent updt;
 	    cout <<"Enter the name: ";
		cin.ignore();
		getline(cin, updt.name);
		cout <<"Enter the Resident of student: ";
		getline(cin, updt.resident);
		cout <<"Enter the Phone Number of student: ";
		getline(cin,updt.ph_no);
		cout <<"Enter the ID: ";
		cin>> updt.id;
		cout <<"Enter the Gender: ";
		cin >> updt.gender;
		cout <<"Enter the Age: ";
		cin >> updt.age;
		cout <<"Enter the student class: ";
    	cin>>updt.studentClass;	
		 
		 ofstream upd_write;
		 upd_write.open("file.txt", ios::app | ios::out );
		 ifstream update;
		 update.open("student.txt", ios::app| ios::in  );
	    
		 if (upd_write.fail())
		  {
		  		cout <<"\nError Opening File."<< endl;
		  		return 0;
		  }	
		   	 
    while (!update.eof())
		  {
		 //studentFile.read((char *)&s[c], sizeof(Student));
		     update >> upt[i].id;
		    update.ignore();
		   	getline(update, upt[i].name);
		   	getline(update, upt[i].ph_no);
		   	getline(update, upt[i].resident);
		   	update >> upt[i].studentClass;
		   	update >> upt[i].gender;
		   	update >> upt[i].age;
			if (upt[i].id != roll_num)
	        {
	
	        	upd_write << upt[i].id << endl;
		        upd_write << upt[i].name << endl;
		        upd_write << upt[i].ph_no << endl;
		        upd_write << upt[i].resident << endl;
		        upd_write << upt[i].studentClass << endl;
		        upd_write << upt[i].gender << endl;
		        upd_write << upt[i].age << endl;
			}
			else 
			{
				upd_write << updt.id << endl;
		        upd_write << updt.name << endl;
		        upd_write << updt.ph_no << endl;
		        upd_write << updt.resident << endl;
		        upd_write << updt.studentClass << endl;
		        upd_write << updt.gender << endl;
		        upd_write << updt.age << endl;
			}
			i++;
		   	
		}
		  update.close();
		  upd_write.close();
		  remove("student.txt");
		  rename("file.txt", "student.txt");
			cout <<"\nCongratulation! Student Data Updatede Successfully\n\n"; 
		  if (i == 0)
		  {
		  	  cout << "Sorry, Student Data not found.";
		  }
	}
};

int Student::generateAttendanceReport(Student s[], int roll_num)
{
	  system("cls"); 
	  int i=0;
	  double totalWorkingDays, daysPresent, attendancePercentage;
	  ofstream write;
	  write.open("Attendance Sheet.txt", ios::app | ios::out);
	  ifstream attendance;
	  attendance.open("student.txt", ios::app | ios::in );
	  if(attendance.fail())
	  {
	  	cout <<"\nError Opening file\n";
	  	return 0;
	  }

	  while (!attendance.eof() )
	  {
    	attendance >> s[i].id;
	   	attendance.ignore();
	   	getline(attendance, s[i].name);
	   	getline(attendance, s[i].ph_no);
	   	getline(attendance, s[i].resident);
	   	attendance >> s[i].studentClass;
	   	attendance >> s[i].gender;
	   	attendance >> s[i].age;	
	    if (roll_num == s[i].id)
	    {
	    	cout <<" NAME: \n \t"<<s[i].name << endl; 
	    	cout <<" CLASS: \n \t"<<s[i].studentClass << endl << endl; 
		    cout << "\nEnter total number of working days (1 - 366): ";
		    cin >> totalWorkingDays;
		    cout << "Enter number of days student " << s[i].id << " was present (1 - 366): ";
		    cin >> daysPresent;
		    attendancePercentage = ((daysPresent / totalWorkingDays) * 100.00);
		    cout << "Attendance Percentage = " << attendancePercentage << "%" << endl;
		    if (attendancePercentage >= 80)
		    {
		    	cout <<"\nAttendance Are Above 80%, So Student Can Sit In Exams Without Fine\n\n";
			}
			else if (attendancePercentage <= 79.9 && attendancePercentage >=75)
			{
				cout <<"\nAttendance Are Below 80%, So Student Have to Charge 5000RS To Sit In Exams\n\n";
			}
			else if (attendancePercentage < 75)
			{
				cout <<"\nSorry! Student Is Drop\n\n";
			}
		    write <<s[i].id << endl;
		    write <<s[i].name << endl;
		    write <<s[i].studentClass << endl;
		    write << attendancePercentage << endl;
		    i++;
	      break;
	      
	    }
	  }
	  if (i != 0)
	  {
	      cout <<"\nStudent Attendance Percentage Generated Succefully\n\n";
	  }
	  else
	  {
	    cout << "No match found.";
	  }
	  attendance.close();
	  write.close();
	  
	}
	int Student::generateFine(Student s[], int roll_number)
	{
		system ("cls");
		int i=0;
		double attendPercentage;
		ifstream fine;
		fine.open("Attendance Sheet.txt", ios::app | ios::in);
		if (fine.fail())
		{
			cout <<"Error Opening File" << endl;
			return 0;
		}
		while(!fine.eof())
		{
			fine >> s[i].id;
		   	fine.ignore();
		   	getline(fine, s[i].name);
		   	fine >> s[i].studentClass;
		   	fine >> attendPercentage;
		   	if (s[i].id == roll_number)
		   	{
		   		cout <<"Name: " << s[i].name << endl;
				cout <<"Class: " << s[i].studentClass << endl;
				cout <<"Roll Number: " <<s[i].id << endl;
				cout <<"Attendance Percentage: " << attendPercentage <<"%" << endl; 
			   	if (attendPercentage >= 80)
			    {
			    	cout <<"\nAttendance Are Above 80%, So Student Can Sit In Exams Without Fine\n\n";
				}
				else if (attendPercentage <= 79.9 && attendPercentage >=75)
				{
					cout <<"\nAttendance Are Below 80%, So Student Have to Charge 5000RS To Sit In Exams\n\n";
				}
				else if (attendPercentage < 75)
				{
					cout <<"\nSorry! Student Is Drop\n\n";
				}
			}
			i++;
		}
		if (i == 0)
		{
			cout <<"Sorry! Student ID Not Found\n";
		}
		fine.close();
	}

void Student:: validateSubjectMarks(int marks[], int index) {
	string subject[5] = {"Science", "Math", "English", "Urdu", "Pak Studies"};
    if (marks[index] < 0 || marks[index] > 100) {
    	
        cout << "\nInvalid marks " << index + 1 << ". Marks should be between 0 and 100." << endl;
        cout <<"\nPlease Enter Marks Again for " << subject[index] << ": ";
        cin >> marks[index];
    }
}
void Student::generateAcademicReport(Student s[], int roll_number)
{
  system("cls");
  int i=0;
  float obtainingMarks, totalMarks =500.0, percentage;
  string grade, status;
  ifstream fileToRead("student.txt", ios::app | ios::in);
  while (!fileToRead.eof())
  {
    	fileToRead >> s[i].id;
		fileToRead.ignore();
	   	getline(fileToRead, s[i].name);
	   	getline(fileToRead, s[i].ph_no);
	   	getline(fileToRead, s[i].resident);
	   	fileToRead >> s[i].studentClass;
	   	fileToRead >> s[i].gender;
	   	fileToRead >> s[i].age;
    if (s[i].id== roll_number)
    {
      ++i;
      break;
    }
  }
  
  if (i > 0)
  {
    cout << "\nEnter marks of student (" <<roll_number << ") between 0 to 100 in subjects asked below: ";
    cout << "\n1. Science = ";
    cin >> marks[0];
    validateSubjectMarks(marks, 0);
    cout << "2. Maths = ";
    cin >> marks[1];
    validateSubjectMarks(marks, 1);
    cout << "3. English = ";
    cin >> marks[2];
    validateSubjectMarks(marks, 2);
    cout << "4. Urdu = ";
    cin >> marks[3];
    validateSubjectMarks(marks, 3);
    cout << "5. Social Studies = ";
    cin >> marks[4];
    validateSubjectMarks(marks, 4);
    
    obtainingMarks = (marks[0] + marks[1] + marks[2] + marks[3] + marks[4]);
    percentage = (obtainingMarks / totalMarks) * 100; 
	cout <<"Max. Marks = " << totalMarks <<"\nObtain. Marks = " <<  obtainingMarks << endl;
    cout << "Percentage = " << percentage << "%" << endl;
    if (percentage >= 85)
	{
		grade = "A";
	}
	else if (percentage >=70)
	{
		grade = "B";
	}
	else if (percentage >=60)
	{
		grade = "C";
	}
	else if (percentage >=50)
	{
		grade = "D";
	}
	else if (percentage < 50 )
	{
		grade = "F";
	}
	cout << "Grade = " << grade << endl;
	if (grade != "F")
	{
		status = "Pass";
	}
	else 
	{
		status = "Fail";
	}
	cout <<"Status = " << status << endl << endl;
  }
  else
    cout << "No match found.";
    fileToRead.close();
    
}

void menu()
{
					
	cout << "select the following To Continue the Process: " << endl <<endl;
	cout << " 1.  Add the Student Details: " << endl;
	cout << " 2.  Check In Fees : " << endl;
	cout << " 3.  To Check Fees Receive or Not: " << endl;
	cout << " 4.  Assign Class Section: " << endl;
	cout << " 5.  Generates Attendance Report: " << endl;
	cout << " 6.  Generates Attendance Fine: " << endl;
	cout << " 7.  Generates Academic Report: " <<endl;
	cout << " 0.  Back To Menu : " << endl;
}


int main ()
{
	Student st[100],student;
	searchStudent s_s[100];
	deleteStudent dt[100];
	UpdateStudent upd[100];
	Student *prim, *mid, *matr, *intr;
	Primary p[100];
	Middle m[100];
	Matric mt[100];
	Inter it[100];
	prim = &p[count];
	mid = &m[count];
	matr = &mt[count];
	intr = &it[count];
	
	int student_id;	
	cout<<endl<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"===   Wellcome to Superior  ==="<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"======================================"<<endl;
	cout<<"       "<<"==== Irfan Education Center ===="<<endl;
	cout<<"       "<<"======================================"<<endl;
	string password;
	cout <<"\n\nPlease Enter the Login Password: ";
	cin >> password;
	Admin ad;
	Password p1(ad, password);
	cout<<" \n\n\nPress Enter to Continue...";
	getch();
	system ("cls");
	B:
	int choice;
	cout << " enter number :"<< endl;
	cout << "1. add "<<endl;
	cout<<"2. display "<<endl;
	cout<<"3. search"<< endl;
	cout<<"4. update"<< endl;
	cout<<"5. delete"<< endl;
	cout<<"0. exit" <<endl;
	cin>>choice;
    system ("cls");
	switch (choice)
	{
    	case 1: 
            A:
			menu();
           	cin >>choice;
           	system("cls");
		switch (choice)
		{
			case 1:
				{
					cout <<"Enter the number of student that you want to add\n";
					cin >> choice;
					st[choice].addStudent(st, choice);
	            	st[count].saveInFile(st, choice);
	                goto A;
                }
            case 2:
            	{
	            	st[count].CheckInFees(st, count);
	            	goto A;
            	}
            case 3:
            	{
	            	cout << "Enter the roll number of student whose fees you want to receive: ";
			        cin>>student_id;		 
					
	            	st[count].StudentFees(st, student_id);
	            	goto A;
            	}
            case 4:
            	S:
            	 cout <<"\n1. Primary" << endl;
            	 cout <<"2. Middle" << endl;
            	 cout <<"3. Matric" << endl;
            	 cout <<"4. Inter" << endl;
            	 cout <<"0. Back To Menu" << endl;
            	 cin >> choice;
            	 system ("cls");
            	 switch(choice)
            	 {
            	 	case 1:
            	 		prim->classSection(prim);          	     	
            	 		goto S;
            	 		break;
            	 	case 2:
            	 		mid->classSection(mid);
            	 		goto S;
            	 		break;
            	 	case 3:
            	 		matr->classSection(matr);
            	 		goto S;
            	 		break;
            	 	case 4:
            	 		intr->classSection(intr);

            	 		goto S;
            	 		break;
            	 	case 0:
            	 		goto A;
            	 		break;
				 }
            	goto A;
            case 5:
            	cout << "Enter student roll number whose attendance report you want to generate: ";
                cin >> student_id;
                st[count].generateAttendanceReport(st, student_id);
                goto A;
            case 6:
            	cout << "Enter student roll number whose attendance fine you want to generate: ";
                cin >> student_id;
                st[count].generateFine(st, student_id);
                goto A;
            case 7:
            	cout << "Enter student roll number whose academic report you want to generate: ";
 				cin >> student_id;
 				st[count].generateAcademicReport(st, student_id);
 				goto A;
            case 0:
            	goto B;
			}
			break;
		case 2:
	    	{
			  cout <<"Enter the Student ID that you want to display\n";	
			  cin>>student_id;
			  st[count].displayStudent(st,student_id);
			   goto B;
		  }
		 
		  case 3:
		      {
		  		  cout << "Enter the ID of student to search: ";	 
				  cin>>student_id;
				  s_s[count].idSearch(s_s, student_id);
				  goto B;
			  }
		  	case 4:
			{
			      cout << "Enter the ID of Student to update: ";
		          cin>>student_id;
				  upd[count].updStudent(upd, student_id );
				  goto B;
			}
			case 5:
				{
				      cout << "Enter the ID of Student to delete: ";
			          cin>>student_id;
					  dt[count].dltStudent(dt, student_id );
					  goto B;
				}
			case 0:
				cout <<"\n\nThank You For visiting My Education Center." << endl;
				exit(0);
		  	

}
}

