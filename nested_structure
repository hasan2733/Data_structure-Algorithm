#include <bits/stdc++.h>
using namespace std;
struct grades
{
    string semester;
    string course_name;
    int credit_hour;
    float cgpa;
    int *p;
};
struct student
{
    string name;
    long long id;
    int batch;
    int section;
    grades res;
    struct student *node;
    
};
void print()
{
   int n;
    cout<<"ENTER THE NUMBER OF STUDENT........."<<endl;
    cin>>n;
    student s1[n];
    for(int i=0; i<n; i++)
    {
        cout<<"ENTER STUDENT DETAILS of "<<i+1<<" NUMBER STUDENT"<<endl;
        cout<<"Enter Name : "<<endl;
        cin>>s1[i].name;
        cout<<"Enter ID : "<<endl;
        cin>>s1[i].id;
        cout<<"Enter Batch : "<<endl;
        cin>>s1[i].batch;
        cout<<"Enter Section : "<<endl;
        cin>>s1[i].section;
        cout<<"Enter Semester : "<<endl;
        cin>>s1[i].res.semester;
        cout<<"Enter Course : "<<endl;
        cin>>s1[i].res.course_name;
        cout<<"Enter Credit Hour : "<<endl;
        cin>>s1[i].res.credit_hour;
        cout<<"Enter Cgpa : "<<endl;
        cin>>s1[i].res.cgpa;
        s1[i].res.p = &s1[i].res.credit_hour;
        s1[i].node=&s1[i];
    }



    for(int i=0; i<n; i++)
    {
        cout<<"DETAILS of "<<i+1<<" NUMBER STUDENT"<<endl;
        cout<<"NAME "<<s1[i].name<<endl;
        cout<<"ID "<<s1[i].id<<endl;
        cout<<"BATCH "<<s1[i].batch<<endl;
        cout<<"SECTION "<<s1[i].section<<endl;
        cout<<"SEMESTER "<<s1[i].res.semester<<endl;
        cout<<"COURSE NAME "<<s1[i].res.course_name<<endl;
        cout<<"CREDIT HOUR "<<s1[i].res.credit_hour<<endl;
        cout<<"CGPA "<<s1[i].res.cgpa<<endl;
        cout<<"POINTER "<<s1[i].res.p <<endl;
        cout<<s1[i].node<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    print();

}
