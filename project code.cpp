#include <iostream>
#include <string>
#include <limits>
using namespace std;
string edit_name();
string edit_dob();
string edit_phone();
string edit_gender();
string edit_work();

string edit_work(){
    char emp;
    cout << "-----------------------------------" << endl;
    cout << "Currently Working? (y/n) : ";
    cin >> emp;
    if(emp == 'y'){
        int sal;
        string work;
        cout << "salary/month : ";
        cin >> sal;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "working as : ";
        getline(cin, work);
        return ("working, as " + work + " for rupees " + to_string(sal * 12) + " (" + to_string(sal) + "/month)");
    }
    else{
        char stu;
        cout << "currently studying? (y/n) : ";
        cin >> stu;
        if(stu == 'y'){
            string ins, course;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "name of institute : ";
            getline(cin, ins);
            cout << "course : ";
            getline(cin, course);
            return ("studying, at " + ins + "(" + course + ")");
        }
        else
            return ("idle");
    }
}

string edit_gender(){
    char gen;
    do{
        cout << "-----------------------------------" << endl;
        cout << "gender (M/F) : ";
        cin >> gen;
    }while(gen != 'm' && gen != 'f');
    if(gen == 'm')
        return ("male");
    else
        return ("female");
}

string edit_phone(){
    string no;
    do{
        cout << "-----------------------------------" << endl;
        cout << "enter the phone number : ";
        cin >> no;
    }while(no.size() != 10);
    return no;
}

string edit_name(){
    string first, last;
    cout << "-----------------------------------" << endl;
    cout << "enter the first name : ";
    cin >> first;
    cout << "enter the last name : ";
    cin >> last;
    return first + " " + last;
}

string edit_dob(){
    int day, month, year;
    do{
        cout << "-----------------------------------" << endl;
        cout << "date of birth (year) : ";
        cin >> year;
    }while(!(year > 1900 && year < 2026));
    do{
        cout << "dob (month) : ";
        cin >> month;
    }while(!(month > 0 && month < 13));
    do{
        cout << "dob (day) : ";
        cin >> day;
    }while(!(day > 0 && day < 32));
    return to_string(day) + "|" + to_string(month) + "|" + to_string(year);
}

class Account {
private:
    string id, password;
    string name, dob, phone, gender, work;

public:
    void edit() {
        cout << "-----------------------------------" << endl;
        cout << "Enter details for account: " << id << endl;
        name = edit_name();
        dob = edit_dob();
        phone = edit_phone();
        gender = edit_gender();
        work = edit_work();
    }

    void display(int display_all = 0) {
        cout << "-----------------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Phone Number: " << phone << endl;
        cout << "Gender: " << gender << endl;
        cout << "Occupation Status: " << work << endl;
       // cout << "-----------------------------------" << endl;

        if (display_all == 0) {
            int choice;
            cout << "Press 1 to edit info" << endl;
            cout << "Press 2 to logout" << endl;
            cout << "Choose: ";
            cin >> choice;
            if (choice == 1)
                edit();
            else if (choice == 2) {
                cout << "Logged out!" << endl;
                return;
            } else
                cout << "Invalid choice!" << endl;
        }
    }

    void setCredentials(string id, string password) {
        this->id = id;
        this->password = password;
    }

    bool login(string mail, string pass) {
        return (mail == id && pass == password);
    }
};

Account users[5];
int userCount = 0;

void createAccount() {
    if (userCount >= 5) {
        cout << "Max accounts reached!" << endl;
        return;
    }

    string id, password;
    cout << "Enter account (e.g., example@hatim.com): ";
    cin >> id;
    if (id.find("@hatim.com") == string::npos) {
        cout << "Address must contain '@hatim.com' and no spaces." << endl;
        return;
    }

    cout << "Enter password (min 6 chars, no spaces): ";
    cin >> password;
    if (password.length() < 6 || password.find(' ') != string::npos) {
        cout << "Invalid password!" << endl;
        return;
    }

    users[userCount].setCredentials(id, password);
    users[userCount].edit();
    userCount++;
}

void login() {
    string mail, pass;
    cout << "Enter account: ";
    cin >> mail;
    cout << "Enter password: ";
    cin >> pass;

    for (int i = 0; i < userCount; i++) {
        if (users[i].login(mail, pass)) {
            users[i].display();
            return;
        }
    }
    cout << "Invalid login!" << endl;
}

void displayAllAccounts() {
    for (int i = 0; i < userCount; i++) {
        users[i].display(1);
    }
}

void menu() {
    int choice;
    while (true) {
        cout << "-----------------------------------" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Display All Accounts" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: login(); break;
            case 3: displayAllAccounts(); break;
            case 4: return;
            default: cout << "Invalid choice!" << endl;
        }
    }
}

int main() {
    menu();
    return 0;
}
