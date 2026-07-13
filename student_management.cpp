
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    float marks;

    Student(int i,string n,int a,float m){
        id=i; name=n; age=a; marks=m;
    }

    char grade() const{
        if(marks>=90) return 'A';
        if(marks>=80) return 'B';
        if(marks>=70) return 'C';
        if(marks>=60) return 'D';
        return 'F';
    }
};

vector<Student> students;

int findIndex(int id){
    for(int i=0;i<students.size();i++)
        if(students[i].id==id) return i;
    return -1;
}

void addStudent(){
    int id,age; float marks; string name;
    cout<<"Enter ID: "; cin>>id;
    if(findIndex(id)!=-1){ cout<<"ID already exists!\n"; return; }
    cin.ignore();
    cout<<"Enter Name: "; getline(cin,name);
    cout<<"Enter Age: "; cin>>age;
    cout<<"Enter Marks: "; cin>>marks;
    students.push_back(Student(id,name,age,marks));
    cout<<"Student Added Successfully!\n";
}

void displayStudents(){
    if(students.empty()){ cout<<"No Records!\n"; return; }
    cout<<"\nID\tName\tAge\tMarks\tGrade\n";
    for(auto &s:students){
        cout<<s.id<<"\t"<<s.name<<"\t"<<s.age<<"\t"<<s.marks<<"\t"<<s.grade()<<"\n";
    }
}

void searchStudent(){
    int id; cout<<"Enter ID: "; cin>>id;
    int idx=findIndex(id);
    if(idx==-1){ cout<<"Student Not Found!\n"; return; }
    auto &s=students[idx];
    cout<<"Name: "<<s.name<<"\nAge: "<<s.age<<"\nMarks: "<<s.marks<<"\nGrade: "<<s.grade()<<"\n";
}

void updateStudent(){
    int id; cout<<"Enter ID: "; cin>>id;
    int idx=findIndex(id);
    if(idx==-1){ cout<<"Student Not Found!\n"; return; }
    cin.ignore();
    cout<<"Enter New Name: "; getline(cin,students[idx].name);
    cout<<"Enter New Age: "; cin>>students[idx].age;
    cout<<"Enter New Marks: "; cin>>students[idx].marks;
    cout<<"Updated Successfully!\n";
}

void deleteStudent(){
    int id; cout<<"Enter ID: "; cin>>id;
    int idx=findIndex(id);
    if(idx==-1){ cout<<"Student Not Found!\n"; return; }
    students.erase(students.begin()+idx);
    cout<<"Deleted Successfully!\n";
}

void sortMarks(){
    sort(students.begin(),students.end(),[](Student &a, Student &b){
        return a.marks>b.marks;
    });
    cout<<"Sorted by Marks!\n";
}

void topper(){
    if(students.empty()){ cout<<"No Records!\n"; return; }
    auto t=max_element(students.begin(),students.end(),[](Student&a,Student&b){
        return a.marks<b.marks;
    });
    cout<<"Topper: "<<t->name<<" ("<<t->marks<<" marks)\n";
}

int main(){
    int ch;
    do{
        cout<<"\n====== STUDENT MANAGEMENT SYSTEM ======\n";
        cout<<"1.Add Student\n2.Display Students\n3.Search Student\n4.Update Student\n5.Delete Student\n6.Sort by Marks\n7.Find Topper\n8.Exit\nChoice: ";
        cin>>ch;
        switch(ch){
            case 1:addStudent();break;
            case 2:displayStudents();break;
            case 3:searchStudent();break;
            case 4:updateStudent();break;
            case 5:deleteStudent();break;
            case 6:sortMarks();break;
            case 7:topper();break;
            case 8:cout<<"Thank You!\n";break;
            default:cout<<"Invalid Choice!\n";
        }
    }while(ch!=8);
    return 0;
}
