#include <iostream> 
#include <conio.h> 
#include <vector>
using namespace std;
int numberOfAccounts=-1;
int  givenAccount;
class BankAccount{
    private :
        string name;
        unsigned long long mobileNumber;
        int accountNumber;
        string password;
        int balance;
        int age;
    public :
        friend void printAll(vector<BankAccount> &acounts); 
        void openAccount();
        void withdrawMoney();
        void depositMoney();
        friend void display(vector<BankAccount> &accounts);
};
void BankAccount:: openAccount(){
    cout<<"enter your name :"<<endl;
    cin>>this->name;
    cout<<"enter your age :"<<endl;
    cin>>age;
    cout<<"ENter your mobile number :"<<endl;
    cin>>mobileNumber;
    cout<<"enter the 4 digit number you want as account number :"<<endl;
    cin>>accountNumber;
    cout<<"Enter the password you like to keep :"<<endl;
    while(true){
        string p1,p2;
        cin>>p1;
        cout<<"Enter the password again to confirm  :"<<endl;
        cin>>p2;
        if(p1.compare(p2)==0){
            cout<<"the password is accepted "<<endl;
            password=p1;
            break;
        }
        cout<<"the passwords do not match enter a password again  "<<endl;
    }
    cout<<"the bank account is successfully created and don't share your password with others ";
    cout<<"enter the amount you want to deposit "<<endl;
    cin>>balance;
    cout<<endl<<"the account is created successfully press any key to continue"<<endl;
    char temp;
    temp=getche();
    return;
}
void BankAccount:: withdrawMoney(){
    while(true){
        cout<<"enter your account number :"<<endl;
        int number;
        cin>>number;
        if(number==accountNumber){
            cout<<"the account number is found :"<<endl;
            break;
        }
    }
    while(true){
        cout<<"enter the password of your account :"<<endl;
        string temp;
        cin>>temp;
        if(temp.compare(password)==0){
            cout<<"the passwords matched : "<<endl;
            break;
        }
    }
}
void BankAccount:: depositMoney(){
    while(true){
        cout<<"enter your account number :"<<endl;
        int number;
        cin>>number;
        if(number==accountNumber){
            cout<<"the account number is found :"<<endl;
            break;
        }
    }
    while(true){
        cout<<"enter the password of your account :"<<endl;
        string temp;
        cin>>temp;
        if(temp.compare(password)==0){
            cout<<"the passwords matched : "<<endl;
            break;
        }
    }
}
void printAll(vector<BankAccount> &accounts){
    for(int givenAccount=0;givenAccount<accounts.size();givenAccount++){
        cout<<endl<<endl;
        cout<<"the name associated with the account number is "<<accounts.at(givenAccount).name<<endl;
        cout<<"the age of the customer is "<<accounts.at(givenAccount).age<<endl;
        cout<<"the phone number of the customer is "<<accounts.at(givenAccount).mobileNumber<<endl;
        cout<<"the balance of the account is "<<accounts.at(givenAccount).balance<<endl;
    }
}
void display(vector<BankAccount> &accounts){
    cout<<"enter your account number :"<<endl;
    int number;
    cin>>number;
    bool found=false;
    for(int i=0;i<=numberOfAccounts;i++){
        if(accounts.at(i).accountNumber==number){
            cout<<"the account number is found :"<<endl;
            givenAccount=i;
            found=true;
            break;
        }
    }
    if(!found){
        cout<<"the account entered not found "<<endl;
        char ch;
        cout<<"press any key to continue"<<endl;
        ch = getche();
        return;
    }
    while(true){
        cout<<"enter the password of your account :"<<endl;
        string temp;
        cin>>temp;
        if(temp.compare(accounts.at(givenAccount).password)==0){
            cout<<"the passwords matched : "<<endl;
            break;
        }
    }
    cout<<"the name associated with the account number is "<<accounts.at(givenAccount).name<<endl;
    cout<<"the age of the customer is "<<accounts.at(givenAccount).age<<endl;
    cout<<"the phone number of the customer is "<<accounts.at(givenAccount).mobileNumber<<endl;
    cout<<"the balance of the account is "<<accounts.at(givenAccount).balance<<endl;
    char ch;
    cout<<"press any key to continue"<<endl;
    ch=getche();
    return;
}
using namespace std;
int main(){
    vector<BankAccount> accounts;
    while(true){
        char choice;
        system("cls");
        cout<<"  *       *       *  *******   *         ****    *****  *      *  * * * *  "<<endl;
        cout<<"   *      *      *   *         *        *       *     * * *  * *  *        "<<endl;
        cout<<"    *    *  *   *    *******   *       *        *     * *   *  *  * * * *  "<<endl;
        cout<<"     *  *    *  *    *         *        *       *     * *      *  *        "<<endl;
        cout<<"      *       *      *******   *******   ****    *****  *      *  * * * *  "<<endl;
        cout<<endl;
        cout<<"             enter 0 to exit "<<endl;
        cout<<"             enter 1 to open an account "<<endl;
        cout<<"             enter 2 to display an account "<<endl;
        cout<<"             enter 3 to deposit money "<<endl;
        cout<<"             enter 4 to withdraw some money "<<endl;
        choice=getche();
        system("cls");
        if(choice=='0'){
            cout<<"thank you for using or bank have a nice day "<<endl;
            break;
        }
        switch(choice){
            case '1':
                numberOfAccounts++;
                accounts.push_back(BankAccount());
                accounts.at(numberOfAccounts).openAccount();
                break;
            case '2':
                display(accounts);
                break;
            case '3':
                break;
            case '4':
                break;
            default :
                break;
        }
    }
    cout<<"thank you for using all accounts created are :"<<endl;
    printAll(accounts);
}

