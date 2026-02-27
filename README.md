README
￼
🏦 Bank Management System (OOP)
￼

￼ ￼ ￼ ￼ ￼ ￼ ￼ ￼

📝 Introduction
￼

A high-performance Console-based Bank Management System built with C++. This project focuses on Object-Oriented Programming (OOP) principles, providing a secure and visually intuitive way to manage banking operations, currency exchange, and user activities.

🚀 Main Features
🔐 1. Authentication & Access
￼

Secure Login System: The gateway to the system with credential verification.
Dynamic Permissions: Each user has specific access rights (Admin/User).
Colored Status Indicators: Visual markers that change color based on permissions before you even click.
👥 2. Client & User Management
￼

Client Operations: Full CRUD (Add, Delete, Update, Find) with encrypted storage.
User Operations: Complete management of system users and their security levels.
Permissions Display: A dedicated screen to view what each user is allowed to do.
💰 3. Banking & Transactions
￼

Balance Management: Deposit, Withdraw, and Total Balances.
Transfer System: Secure money transfer between accounts with real-time validation.
Transfer Logs: Recording all financial movements between clients for auditing.
🌍 4. Currency Exchange System
￼

Live-Style Rates: View currency rates relative to the USD.
Currency Finder: Search for any currency by code or country.
Currency Calculator: Perform instant conversions between different global currencies.
🛡️ 5. Security & Logs (Audit Trail)
￼

User Move Tracking: The system records every single action by the user (Login, Edits, Views).
Logs Viewer: A clean, formatted table for admins to review all system activities (Login Logs & Transfer Logs).
Security Refresh: A tool to re-encrypt data files to ensure maximum protection.
🎨 User Interface (UI)
￼

Full Color Support: A professional color-coded terminal experience for better UX.
Modular Menus: Intuitive navigation through nested, organized screens.
Formatted Tables: Data is displayed in neat, structured, and colored tables.
🔐 Encryption Engine (5-Layers)
￼

The system protects sensitive data using a custom-built cryptographic logic:

XOR Cipher (Initial encryption)
Random Padding (Noise injection)
Case Inversion (Casing flip)
Nested XOR (Double security)
Hexadecimal (Final storage format)
📂 Project Structure (Layered Architecture)
Layer	Responsibility	Key Files	****
Core	Business Logic & Models	clsBankClient.h, clsUser.h, clsCurrency.h	💻
Libs	Logic Utilities & Security	clsCrypt.h, clsInputValidation.h, clsUtility.h	🔧
Screens	UI: Management & Logic	clsLoginScreen.h, clsMainScreen.h, clsScreen.h	📈
Screens/Bank	Client UI Operations	clsAddNewClientScreen.h, clsClientListScreen.h	💰
Screens/Curr	Currency UI Operations	clsCurrencyExhangeScreen.h, clsCalculationScreen.h	💵
Screens/Trans	Financial UI Operations	clsDepositScreen.h, clsTransfareScreen.h	💳
Screens/Logs	Auditing UI Operations	clsSystemLogsScreen.h, clsTransferLogsScreen.h	📚
🛠 Tools & Technologies
Language: C++
Paradigm: Object-Oriented Programming (OOP)
Key Concepts: Encapsulation, Inheritance, Polymorphism, Abstraction, File Handling.
👨‍💻 Author
Anwer El-sayed 
Email: anwr2021alssayed@gmail.com
phone:967775624272
"Building secure and scalable software solutions."
