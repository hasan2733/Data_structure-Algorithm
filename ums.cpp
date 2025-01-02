#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

// Data structure for student Management (using queue)
struct student
{
    string student_name;
    long long id;
    string semester;
    int total_credit_in_semester;
    string cgpa;
};

// Data structure for Course Management (using Binary Search Tree)
struct Course_node
{
    string course_name;
    string course_code;
    Course_node* left;
    Course_node* right;
};

// Data structure for Faculty Management (using Stack)
struct Faculty
{
    string name;
    string department;
    string email;
};

//STL instead of doing  manually
queue<student>studentQueue;
stack<Faculty>facultyStack;

Course_node *root=NULL;

// Function to handle login
void login()
{
    int attemps=0;
    string uname,pass;
    string user_name="SEU_CSE";
    string password="SEU_CSE";
    do
    {
        system("cls");
        cout<<"\n  =========================  LOGIN FORM  =========================  ";
        cout<<"\n                       ENTER USERNAME: ";
        cin>>uname;
        cout<<"\n                       ENTER PASSWORD: ";
        char c;
        pass.clear();
        while(true)
        {
            c=getch();
            if(c=='\r')//enter key
            {
                break;
            }
            else if(c=='\b')//backspace
            {
                if(!pass.empty())
                {
                    pass.pop_back();
                    cout<<"\b \b";//erase from console
                }
            }
            else
            {
                pass.push_back(c);
                cout<<"*";
            }
        }
        if(uname==user_name && pass==password)
        {
            cout << "\n\n\n                WELCOME TO OUR SYSTEM! LOGIN IS SUCCESSFUL";
            cout << "\n\n\n\t\tPress any key to continue...";
            getch(); // Holds the screen
            break;
        }
        else
        {
            cout << "\n        SORRY! LOGIN IS UNSUCCESSFUL";
            attemps++;
            getch();
        }
    }
    while(attemps<3);

    if(attemps >= 3)
    {
        cout << "\nSorry, you have entered the wrong username and password too many times!";
        getch();
        exit(0);
    }
    system("cls");
}

// Function to add a course to the Binary Search Tree
Course_node* addcourse(Course_node* root,string course_name,string course_code)
{
    if(root==NULL)
    {
        //Course_node* n = (Course_node*)malloc(sizeof(Course_node));
        Course_node *n=new Course_node;
        n->course_name=course_name;
        n->course_code=course_code;
        n->left=n->right=NULL;
        return n;
    }

    if (course_code < root->course_code)
    {
        root->left = addcourse(root->left, course_name, course_code);
    }
    else
    {
        root->right = addcourse(root->right, course_name, course_code);
    }
    return root;
}


//inorder travarsal for course Management
void printcourse(Course_node *root)
{
    if(root==NULL)
    {
        return;
    }
    printcourse(root->left);
    cout << "Course Name: " << root->course_name << " | Course Code: " << root->course_code << endl;
    printcourse(root->right);
}


// Function to add a student to the queue (Student Registration)
void register_student()
{
    student stnt;
    cout<<"Enter student fullname : ";
    cin.ignore();
    getline(cin,stnt.student_name);
    cout<<"Enter student ID : ";
    cin.ignore();
    cin>>stnt.id;
    cout<<"Enter semester : ";
    cin.ignore();
    cin>>stnt.semester;
    cout<<"Enter total credit hour in the semester : ";
    cin.ignore();
    cin>>stnt.total_credit_in_semester;
    cout<<"Enter CGPA of previous semester (NULL for new student) : ";
    cin.ignore();
    cin>>stnt.cgpa;
    studentQueue.push(stnt);
    cout << "Student registered successfully!" << endl;
}


// Function to manage faculty (using Stack)
void manageFaculty()
{
    Faculty f;
    cout<<"Enter faculty name : ";
    cin.ignore();
    getline(cin,f.name);
    cout<<"Enter department : ";
    cin>>f.department;
    cout<<"Enter email address of the faculty : ";
    cin>>f.email;
    facultyStack.push(f);
    cout << "Faculty added successfully!" << endl;
}


// Function to view faculty details (Pop faculty from stack)
void veiwfaculty()
{
    if(facultyStack.empty())
    {
        cout<<"No faculty members available ! "<<endl;
        return;
    }
    Faculty f = facultyStack.top();
    cout<<"Faculty name : "<<f.name<<" | Department : "<<f.department<<" | Email : "<<f.email<<endl;
    facultyStack.pop();
}


// Main menu function
void mainmenu()
{
    const int width = 80;
    string title = "University Management System - SEU";
    string line = "====================================";
    string options[]=
    {
        "1. Rgister Student ",
        "2. Veiw Student ",
        "3. Add Course ",
        "4. Veiw Course List ",
        "5. Manage Faculty ",
        "6. Veiw Faculty ",
        "7. Exit "
    };
    // Center-align and display the title
    cout << string((width - title.length()) / 2, ' ') << title << endl;
    cout << string((width - line.length()) / 2, ' ') << line << endl;

    // Center-align and display each menu option
    for (const string& option : options)
    {
        cout << string((width - option.length()) / 2, ' ') << option << endl;
    }

    // Center-align and display the prompt
    string prompt = "Enter your choice: ";
    cout << string((width - prompt.length()) / 2, ' ') << prompt;
}



//print the student in the queue
void veiwstudent()
{
    if(studentQueue.empty())
    {
        cout<<"No student in the queue !"<<endl;
        return;
    }
    else
    {
        cout<<"student in the Queue : "<<endl;
        queue<student>tempque=studentQueue;
        while(!tempque.empty())
        {
            student stu = tempque.front();
            tempque.pop();
            cout<<"Name : "<<stu.student_name<<" | ID : "<<stu.id<<" | Semester : "<<stu.semester<<" | Total credit"<<stu.total_credit_in_semester<<" | CGPA "<<stu.cgpa<<endl;
        }
    }
}

void ums()
{
    login();
    int choice;
    do
    {
        mainmenu();
        cin>>choice;
        switch (choice)
        {
        case 1:
            register_student();
            break;
        case 2:
            veiwstudent();
            break;
        case 3:
        {
            string courseName;
            string courseCode;
            cout<<"Enter Course Name : ";
            cin.ignore();
            getline(cin,courseName);
            cout<<"Enter Course Code : ";
            cin>>courseCode;
            root=addcourse(root,courseName,courseCode);
            cout<<"Course Added Successfully ! "<<endl;
        }
        break;
        case 4:
            cout<<"Course List : \n";
            printcourse(root);
            break;
        case 5:
            manageFaculty();
            break;
        case 6:
            cout<<"Faculty Stack : \n ";
            veiwfaculty();
            break;
        case 7:
            cout<<"Exiting System....... \n";
            break;
        default:
            cout<<"Invalid choice try again"<<endl;
        }
    }
    while(choice!=7);
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tThank You For Using UMS SEU\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    getch();
}

int main()
{
    ums();
}
