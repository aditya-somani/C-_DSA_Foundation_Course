/*
Q.Implement a Phone directory application using doubly linked lists.


 So, I am creating phone directory with doubly ll
 as it is always in sorted order so , have to make sure that i put name lexicographically

 -also only update of number and address is allowed as they not primary imp but name will be used for searching so , updating
 it will mess up my order of lexicographical

 Same name will be arranged based on order of insertion

 In whole code name is being used as primary key hence it is immutable
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;
struct cell{
    string name;
    int phone_no;
    string address;
};

class Node{
public:
    cell data;
    Node* next;
    Node* prev;
    Node(string n,int p,string ad){
        data.name=n;
        data.address=ad;
        data.phone_no=p;
        next=prev=NULL;
    }
};

class PhoneDirectory{
public:
    Node* head;
    Node* tail;
    PhoneDirectory(){
        head=NULL;
        tail=NULL;
    }

    int findpos(string s){
        int pos=0;
        Node* temp=head;
        int i=0;
        while(temp->next!=NULL && tolower(s[i])>=tolower(temp->data.name[i])){
            if(tolower(s[i])==tolower(temp->data.name[i])){
                i++;
                if(i==s.size() || i==temp->data.name.size()){
                    if(i==temp->data.name.size()){
                        temp=temp->next;
                        i=0;
                        pos++;
                    }
                    else{
                        temp=temp->next;
                        i=0;
                    }
                }
            }
            else{
                temp=temp->next;
                pos++;
            }
        }
        return pos;
    }

    int present(string s){
        Node* temp=head;
        int i=0;
        while(temp!=NULL){
            if (temp->data.name==s){
                return i;
            }
            i++;
            temp=temp->next;
        }
        if (temp==NULL) return -1;
    }

    void add_node(){
        cin.ignore();
        cout<<"Enter the name :";
        string s;
        getline(cin,s);
        if (s.size()==0){
            cout<<"Entered name is empty!"<<endl;
            return;
        }
        cout<<"Enter the number :";
        int ph;
        if (!(cin>>ph)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input!"<<endl;
            return;
        }
        cin.ignore();
        cout<<"Enter the address :";
        string adr;
        cin.ignore();
        getline(cin,adr);
        Node* newNode=new Node(s,ph,adr);
        if(tail==NULL && head==NULL){
            //when dll is empty i.e. inserting the first node
            head=newNode;
            tail=newNode;
            return;
        }
        int pos=findpos(s);
        Node* temp = head;
        int curr=0;
        if(pos==0){
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
            return;
        }
        while (temp!=NULL && curr<pos-1){
            temp=temp->next;
            curr++;
        }

        if (temp==tail){
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        //what if temp is null -> i will get segmentation fault
        if(temp!=NULL){
            newNode->next=temp->next;
            temp->next=newNode;
            newNode->prev=temp;
            newNode->next->prev=newNode;
        }
        return;
    }

    void delete_node(){
        if(head==NULL && tail==NULL){
            cout<<"Directory is empty! "<<endl;
            return;
        }
        cin.ignore();
        cout<<"Enter the name to be deleted :";
        string s;
        getline(cin,s);
        if (present(s)==-1){
            cout<<"User Not Found!"<<endl;
            return;
        }
        cout<<"User : "<<s<<" has been deleted "<<endl;
        int pos=present(s);
        if(head==tail){
            Node* temp=head;
            head=tail=NULL;
            free(temp);
            return;
        }
        int curr=0;
        Node* temp=head;
        while(temp!=NULL && curr<pos){
            temp=temp->next;
            curr++;
        }
        if (temp==head){
            head=head->next;
            temp->next=NULL;
            free(temp);
            return;
        }
        if (temp==tail){
            Node* de=temp;
            tail=tail->prev;
            tail->next->prev=NULL;
            tail->next=NULL;
            free(de);
        }
        else{
            Node* de=temp;
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(de);
        }
        return;
    }

    void fetchDetails(){
        if(head==NULL && tail==NULL){
            cout<<"Directory is empty! "<<endl;
            return;
        }
        cin.ignore();
        cout<<"Enter full name :";
        string s;
        getline(cin,s);
        if (!present(s)){
            cout<<"User Not Found!"<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data.name==s){
                cout<<"Details are :"<<endl;
                cout<<"Name :"<<temp->data.name<<endl<<"Phone No. :"<<temp->data.phone_no<<endl<<"Address :"<<temp->data.address<<endl;
                return;
            }
            temp=temp->next;
        }
    }

    void full_details(){
        if(head==NULL && tail==NULL){
            cout<<"Directory is empty! "<<endl;
            return;
        }
        Node* temp=head;
        cout<<"Details are :"<<endl;
        while(temp!=NULL){
            cout<<"Name :"<<temp->data.name<<" , "<<"Phone No. :"<<temp->data.phone_no<<" , "<<"Address :"<<temp->data.address<<endl;
            temp=temp->next;
        }
        return;
    }

    void update_details(){
        cin.ignore();
        cout<<"Enter the name whose details you wish to update :";
        string s;
        getline(cin,s);
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data.name==s){
                cout<<"What do you want to update :"<<endl;
                cout<<"\t1.Phone Number"<<endl<<"\t2.Address"<<endl<<"\t3.Both"<<endl;
                int n;
                cout<<"Enter choice number :";
                //handling case for non-numeric input
                if (!(cin>>n)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout<<"Invalid Input!"<<endl;
                    return;
                }
                switch (n) {
                    case 3:
                        //both
                        cin.ignore();
                        cout<<"Enter the new number :";
                        if (!(cin>>temp->data.phone_no)){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout<<"Invalid Input!"<<endl;
                            return;
                        }
                        cin.ignore();
                        cout<<"Enter the new address :";
                        getline(cin,temp->data.address);
                        break;
                    case 2:
                        cin.ignore();
                        cout<<"Enter the new address :";
                        getline(cin,temp->data.address);
                        break;
                    case 1:
                        cin.ignore();
                        cout<<"Enter the new number :";
                        if (!(cin>>temp->data.phone_no)){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout<<"Invalid Input!"<<endl;
                            return;
                        }
                        break;
                    default:
                        cout<<"Invalid choice "<<endl;
                        break;

                }
                return;
            }
            temp=temp->next;
        }
        if (temp==NULL) cout<<"User Not Found!"<<endl;
    }
};


int main(){
    cout<<"\t \t \t \t \t \tWelcome to Somani Ji Ki Phone Directory"<<endl;
    PhoneDirectory dll;
    do {
        cout<<"What do you wish to do :"<<endl<<"1.Add User"<<endl<<"2.Fetch details"<<endl<<"3.Update Details"<<endl<<"4.Delete User"<<endl<<"5.Display Full directory"<<endl<<"6.Exit"<<endl;
        int n;
        cout<<"Enter choice number :";
        //handling cases when input is not numeric -> learned from GPT
        //need to understand this whole case once again thoroughly
        //This case has been handled at multiple places throughout the code
        //It is the only thing that has been done using internet
        if (!(cin>>n)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input!"<<endl;
            continue;
        }
        switch (n) {
            case 1:
                dll.add_node();
                break;
            case 2:
                //fetch details
                dll.fetchDetails();
                break;
            case 3:
                //update details
                dll.update_details();
                break;
            case 4:
                //delete details
                dll.delete_node();
                break;
            case 5:
                dll.full_details();
                break;
            case 6:
                return 0;
            default:
                cout<<"Invalid Choice "<<endl;
                break;
        }
    }while(true);
    return 0;
}
