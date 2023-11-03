#include<bits/stdc++.h>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define int long long

/*Structure type data for holding course information*/
typedef struct courses{
    string code, name;
    struct courses *next;
}courses;

/*structure type data to hold Student's information. Including his assignes courses*/
typedef struct students{
    string ID, name, email, phone;
    int courseNum;
    courses *course;
    struct students *next;
}students;

students *start = NULL;

void display();
void landing();
void exitProgram();
void addNew();
bool exists(string SID, string type, string ID);
void SearchByID();
void returnMenu();
void slowTxt(string s);


signed main(){
    while(true){
        system("cls"); //Cleares previous output
        landing();
        int ope;
        cin>>ope;
        switch(ope){
            case 0:
                exitProgram();
                break;
            case 1:
                addNew();
                break;
            case 2:
                SearchByID();
                break;
            case 7:
                display();
                break;

            default:
                string invalid = "\n\tInvalid Choise...";
                slowTxt(invalid);
                Sleep(300);
                break;
        }
    }
}

void landing(){
    cout<<"\n\n";
    cout<<"   ****Student Management System****"<<endl<<endl; Sleep(10);
    cout<<"\t\tMain Menu"<<endl; Sleep(10);
    cout<<"     *****************************"<<endl; Sleep(10);
    cout<<"\t[1] Add new Student."<<endl; Sleep(10);
    cout<<"\t[2] Search a Student."<<endl; Sleep(10);
    cout<<"\t[3] Show all Student."<<endl; Sleep(10);
    cout<<"\t[4] Delete Student."<<endl; Sleep(10);
    cout<<"\t[5] Delete all Student."<<endl; Sleep(10);
    cout<<"\t[6] About Us"<<endl; Sleep(10);
    cout<<"\t[7] Display All Students"<<endl; Sleep(10);
    cout<<"\t[0] Exit the Program."<<endl; Sleep(10);
    cout<<"     *****************************"<<endl; Sleep(10);
    cout<<"\tEnter your Choise: ";

}


void slowTxt(string s){
    system("cls");
    cout<<"\n\n"<<endl;
    cout<<"\t";
    for(auto it : s){
        cout<<it;
        Sleep(20);
    }
    cout<<"\n\n";
}

void SearchByID(){
    string s = "To search a student, please Enter following information. ";
    slowTxt(s);
    cout<<"\tStident ID: ";
    string ID;
    cin>>ID;
    students *st = start;
    bool found = false;
    while(st!=NULL){
        if(st->ID==ID){
            system("cls");
            cout<<"\tStudent ID: "<<st->ID<<endl;
            cout<<"\tName: "<<st->name<<endl;
            cout<<"\tPhone: "<<st->phone<<endl;
            cout<<"\tE-mail: "<<st->email<<endl;
            cout<<"\tEnrolled courses: "<<endl;
            courses *q = st->course;
            int c = 1;
            while(q!=NULL){
                cout<<"\t\tCourse-"<<c<<": "<<endl;
                cout<<"\t\t\tCourse Name: "<<q->name<<endl;
                cout<<"\t\t\tCourse Code: "<<q->code<<endl;
                c++;
                q = q->next;
            }
            found = true;
        }
        st = st->next;
    }
    if(found==false){
        slowTxt("Student Information can not be found.");
    }
    returnMenu();
}

bool exists(string tocmp, string type, string ID){
    bool ide = false;
    bool phn = false;
    bool email = false;
    students *s = start;
    while(s!=NULL){
        if(s->ID==tocmp && s->ID==ID){
            ide = true;
        }
        if(s->phone==tocmp && s->ID==ID){
            phn = true;
        }
        if(s->email==tocmp && s->ID==ID){
            email = true;
        }
        s = s->next;
    }

    if(type == "id"){
        return ide;
    }
    else if(type == "phn"){
        return phn;
    }
    else if(type == "mail"){
        return email;
    }
    else{
        return false;
    }
}

void addNew(){
    string ID, name, phone, email, Cname, Ccode;
    int courseNum;
    bool valid = false;
    system("cls");
    cout<<"\n\n"<<endl;
    string s = "You wanted to add a new student. \n\tPlease enter his/her detailed information";
    slowTxt(s);

    cin.ignore();
    while(!valid){
        cout<<"\tEnter Student ID: ";
        getline(cin, ID);
        if(exists(ID,"id", ID)){
            cout<<"\tID "<<ID<<" already exists.\n\n";
        }
        else if(ID.size()>15){
            cout<<"\tInvalid! ID can not be more then 15 characters\n\n";
        }
        else if(ID.size()==0){
            cout<<"\tInvalid! ID can not be empty\n\n";
        }
        else{
            valid = true;
        }
    }
    valid = false;
    while(!valid){
        cout<<"\tEnter Student Name: ";
        getline(cin, name);
        if(name.size()>25){
            cout<<"\tName can not be more than 25 character\n\n";
        }
        else if(name.size()==0){
            cout<<"\tName can not be empty\n\n";
        }
        else{
            valid = true;
        }
    }
    valid = false;
    while(!valid){
        cout<<"\tEnter The E-mail Address: ";
        getline(cin, email);
        if(exists(email,"mail", ID)){
            cout<<"\t\tE-mail "<<email<<" already exists.\n\n";
        }
        else if(name.size()>35){
            cout<<"\t\tE-mail can not be more than 35 character\n\n";
        }
        else if(name.size()==0){
            cout<<"\t\tE-mail can not be empty\n\n";
        }
        else{
            valid = true;
        }
    }
    valid = false;
    while(!valid){
        cout<<"\tEnter The Phone Number: ";
        getline(cin, phone);
        if(exists(phone,"phn", ID)){
            cout<<"\t\tPhone "<<email<<" is already being Used.\n\n";
        }
        else if(phone.size()>11){
            cout<<"\t\tPhone can not be more than 11 character\n\n";
        }
        else if(phone.size()==0){
            cout<<"\t\tPhone can not be empty\n\n";
        }
        else{
            valid = true;
        }
    }


    //Node creation and vallue Assiging
    students *student = new students();
    student->ID = ID;
    student->name = name;
    student->email = email;
    student->phone = phone;

    cout<<"\tEnter The Number of Courses: ";
    cin>>courseNum;

    courses *cp = student->course;
    if(cp!=NULL){
        while(cp->next!=NULL){
            cp = cp->next;
        }
    }

    //cin.ignore();
    for(int i = 1;i<=courseNum;i++){
        cout<<"\tCourse-"<<i<<": \n";
        valid = false;
        //cin.ignore();
        while(!valid){
            cout<<"\tEnter course Code: ";
            //getline(cin, Ccode);
            cin>>Ccode;
            if(Ccode.size()>8){
                cout<<"\t\tCourse code can not be more than 8 character\n\n";
            }
            else if(Ccode.size()==0){
                cout<<"\t\tCourse code can not be empty\n\n";
            }
            else{
                valid = true;
            }
        }
        valid = false;
        //cin.ignore();
        while(!valid){
            cin.ignore();
            cout<<"\tEnter course Name: ";
            getline(cin, Cname);
            if(Cname.size()>30){
                cout<<"\t\tCourse name can not be more than 30 character\n\n";
            }
            else if(Cname.size()==0){
                cout<<"\t\tCourse name can not be empty\n\n";
            }
            else{
                valid = true;
            }
        }
        courses *c = new courses();
        c->code = Ccode;
        c->name = Cname;
        c->next = NULL;
        if(cp==NULL){
            student->course = c;
            cp = c;
        }
        else{
            cp->next = c;
            cp = c;
        }
    }
    if(start == NULL){
        start = student;
    }
    else{
        students *p = start;
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = student;
    }
    display();

}

void display(){
    string s = "Viewing All the Student Information: ";
    slowTxt(s);
    students *p = start;
    int st = 0;
    while(p!=NULL){
        st++;
        cout<<"\n\t*****Student-"; if(st<10){cout<<"0";}cout<<st<<"*****"<<endl;
        cout<<"\tStudent ID: "<<p->ID<<endl;
        cout<<"\tName: "<<p->name<<endl;
        cout<<"\tPhone: "<<p->phone<<endl;
        cout<<"\tE-mail: "<<p->email<<endl;
        cout<<"\tEnrolled courses: "<<endl;
        courses *q = p->course;
        int c = 1;
        while(q!=NULL){
            cout<<"\t\tCourse-"<<c<<": "<<endl;
            cout<<"\t\t\tCourse Name: "<<q->name<<endl;
            cout<<"\t\t\tCourse Code: "<<q->code<<endl;
            c++;
            q = q->next;
        }
        p = p->next;
    }
    returnMenu();
}

void returnMenu(){
    cout<<"\n\tTo return Main menu[M]\n\tTo Close the Programme[0]\n\tEnter yout choise: ";
    char x;
    cin>>x;
    if(x=='0'){
        exitProgram();
    }
}

void exitProgram(){
    string thank = "Thank Your for using our service...";
    slowTxt(thank);
    Sleep(500);
    exit(0);
}
