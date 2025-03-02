# Account Management System

## 📌 Description
The Account Management System is a simple C++ console-based application that allows users to create accounts, log in, and manage their personal details. Users can store essential information like their name, date of birth, phone number, gender, and occupation status. The system supports basic validation, ensures secure account management, and provides an interactive menu for ease of use.

## 🚀 Features
- **Create Account:** Users can register an account with a unique ID and password.
- **Login System:** Secure authentication to access user profiles.
- **Edit Profile:** Modify personal details such as name, DOB, phone number, gender, and work status.
- **Occupation Status:** Differentiates between working professionals, students, and idle users.
- **User Limit:** Supports up to 5 accounts.
- **Display All Users:** Admins can view all stored user profiles.
- **Interactive Menu:** Provides user-friendly options for easy navigation.

## 🛠 How to Run
1. **Compile the Code** using a C++ compiler (e.g., g++ for GCC):
   ```sh
   g++ account_management.cpp -o account_management
   ```
2. **Run the Executable:**
   ```sh
   ./account_management
   ```

## 📖 Usage
### Menu Options
Upon running the program, you will be presented with a menu:
1. **Create Account** – Register a new account with an `@hatim.com` email.
2. **Login** – Enter your credentials to access and modify your profile.
3. **Display All Accounts** – View all stored accounts and their details.
4. **Exit** – Quit the application.

### Account Creation
- A valid email must contain `@hatim.com`.
- Passwords must be at least 6 characters long and must not contain spaces.
- After successful registration, users are prompted to enter their personal details.

### Editing Profile Information
- Users can modify their **name**, **date of birth**, **phone number**, **gender**, and **occupation status**.
- Work status is categorized into:
  - **Employed** (specifies job title and annual salary)
  - **Student** (requires institution name and course of study)
  - **Idle** (for those not working or studying)

## 🔐 Account Security
- Accounts require a valid `@hatim.com` email.
- Passwords must be at least 6 characters with no spaces.
- Login credentials must match stored accounts for access.

## ⚠ Limitations
- The system supports a maximum of 5 users.
- Passwords are stored in plain text (no encryption).
- No database integration (all data is stored in runtime memory only).

## 📩 Contact
For any questions, issues, or improvements, feel free to contribute or reach out!

Enjoy using the Account Management System! 🚀

