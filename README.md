# 📖 **Bank Management System** 💼🏦  

Welcome to the **Bank Management System** project! This system allows users to manage bank accounts efficiently, supporting operations such as account creation, deletion, transactions, and balance management. This README will guide you through the structure, logic, and usage of the system.

# Author
**Shreyas Mehta**

---

## 🛠️ **Features**  

- **Account Creation**  
  Create new bank accounts with specified account types (Savings or Current). Accounts are created with a unique number.

- **Account Deletion**  
  Delete an existing account by specifying the account holder's name and type (Savings/Current).

- **Transactions**  
  Perform transactions such as deposits and withdrawals.

- **Account Display**  
  Display all accounts sorted by account number, including details such as name, account type, and balance.

- **Low Balance Accounts**  
  List all accounts with balances below a specified threshold.

---

## 🧑‍💻 **Project Structure**  

```plaintext
.
├── bank.c      # Main logic file with all function implementations
└── README.md   # This file
```

---

## 🔑 **Core Concepts**

### 1. **Account Type Enum**  
This enum defines two types of bank accounts:  
```c
typedef enum {
    savings,  // Savings account type
    current   // Current account type
} AccountType;
```

### 2. **AccountInfo Struct**  
Each account has the following fields:
```c
typedef struct AccountInfo{
    int num;                // Unique account number
    char name[max_name];    // Account holder's name
    AccountType type;       // Account type (savings or current)
    float balance;          // Account balance
} AccountInfo;
```

### 3. **Node Struct (Linked List)**  
The linked list is used to store account information:
```c
typedef struct Node{
    AccountInfo data;       // Account data
    struct Node* next;      // Pointer to the next node
} Node;
```

### 4. **Bank Struct**  
The **bank** struct contains a linked list of members (accounts) and the size of the bank:
```c
typedef struct bank{
    linkedlist members;     // Linked list of accounts
    int size;               // Number of accounts
} bank;
```

---

## 📝 **Key Functions**

### 1. **`append(linkedlist l, AccountInfo a)`**  
Adds a new account to the linked list.

### 2. **`sorted(bank *b)`**  
Sorts accounts by account number using the **bubble sort** algorithm.

### 3. **`display(bank b)`**  
Displays all accounts sorted by account number.

### 4. **`checkDuplicates(char* name, AccountType type, bank b)`**  
Checks for duplicate accounts with the same name and type.

### 5. **`createAccount(bank* b)`**  
Creates a new account after checking for duplicates and assigning a unique account number.

### 6. **`deleteAccount(bank* b, AccountType type, char* username)`**  
Deletes an account based on the name and account type.

### 7. **`ADDMONEY(bank*b, int accountNUM, float money)`**  
Adds a specified amount of money to a given account.

### 8. **`WITHDRAWmoney(bank*b, int accountName, float x)`**  
Withdraws money from a specified account, ensuring there are sufficient funds.

### 9. **`lowBalanceAccounts(float x, bank*b)`**  
Displays accounts with balances lower than a specified threshold.

### 10. **`transaction(bank*b)`**  
Performs a transaction (deposit or withdrawal) for a specified account.

---

## 🚀 **How to Run**  

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-repository/bank-management-system.git
   cd bank-management-system
   ```

2. **Compile the program**:
   ```bash
   gcc bank.c -o bank
   ```

3. **Run the program**:
   ```bash
   ./bank
   ```

4. **Interact with the program**:
   - Type one of the following commands to perform actions:
     - `CREATE`: Create a new account
     - `DELETE`: Delete an account
     - `DISPLAY`: Display all accounts
     - `TRANSACTION`: Perform a deposit/withdrawal transaction
     - `LOWBALANCE`: Display accounts with low balances
     - `EXIT`: Exit the program

---

## ⚙️ **Example Workflow**  

**Creating an Account**  
Input:
```plaintext
CREATE
savings
JohnDoe
1500
```
Output:
```plaintext
Account Created Successfully
Account Number: 101
Account Holder: JohnDoe
Account Type: Savings
Balance: Rs 1500.00
```

**Deleting an Account**  
Input:
```plaintext
DELETE
savings
JohnDoe
```
Output:
```plaintext
Account Deleted Successfully
```

**Displaying All Accounts**  
Input:
```plaintext
DISPLAY
```
Output:
```plaintext
ACCOUNT NO.  NAME      ACCOUNT TYPE  BALANCE
------------------------------------------------
101          JohnDoe   Savings       Rs 1500.00
------------------------------------------------
```

---

## 🎯 **Logic Explanation**

1. **Hashing Account Numbers**:  
   The system uses a simple hashing mechanism to ensure that each account number is unique and can be assigned efficiently.

2. **Linked List Operations**:  
   The accounts are stored in a linked list, which allows dynamic resizing and efficient account management.

3. **Transaction Handling**:  
   The system allows both deposits and withdrawals, ensuring that the account balance does not drop below a threshold (in this case, Rs 100).

4. **Account Validation**:  
   Before creating or deleting an account, the system checks for duplicates or non-existing accounts, ensuring that all actions are valid.

---

## 💡 **Potential Enhancements**  
- Implement **file handling** to store and load account information.
- Add **security features**, like password protection for transactions.
- Introduce **interest calculation** for savings accounts.

---

