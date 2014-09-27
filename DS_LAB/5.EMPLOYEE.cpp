#include <iostream>
using namespace std;
class employ
{
    int emp_id;
    int Basic_salary;
    int Allowance;
    int Income_tax;
    int Net_sal;
    char name[100];
    int gross_salary;
    public:
        void get_data();
        void calNet_sal();
        void display();
}obj[20];
void employ::get_data()
{
   cout<<"\nEnter the employ id";
    cin>>emp_id;
    cout<<"\nEnter the basic salary";
    cin>>Basic_salary;
    cout<<"\nname";
    cin>>name;
}
void employ::calNet_sal()
{
    Allowance=1.23*Basic_salary;
    gross_salary=Basic_salary+Allowance;
    Income_tax=.3*gross_salary;
    Net_sal=gross_salary-Income_tax;

}
void employ::display()
{
    cout<<"\nemploy name is:"<<name;
    cout<<"\nAllowance is:"<<Allowance;
    cout<<"\nincome tax is:"<<Income_tax;
    cout<<"\nnet salary is:"<<Net_sal;
    cout<<"\ngross salary is:"<<gross_salary;

}
int main(void)
{
    int i,n;
    cout<<"Enter the number of employs\n";
    cin>>n;
    for(i=0;i<n;i++)
    {
        obj[i].get_data();
        obj[i].calNet_sal();
        obj[i].display();
    }
    return 0;
}

