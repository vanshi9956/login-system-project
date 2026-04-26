# login-system-project
C++ file-based login system + Flask MySQL backend


# 🔐 Login System Project

## 📌 Overview

This project demonstrates a login system implemented in two stages:

1. C++ file-based authentication system
2. Flask + MySQL backend authentication system

---

## 🧠 Technologies Used

* C++
* Python (Flask)
* MySQL
* REST APIs
* Thunder Client (for testing)

---

## 💻 Part 1: C++ Login System

* Uses file handling (`fstream`)
* Stores user data in `loginData.txt`
* Features:

  * Signup
  * Login
  * Forget Password
  * Password encoding/decoding
  * Duplicate user checks

---

## 🌐 Part 2: Flask + MySQL Backend

* REST API based system
* Data stored in MySQL database

### 🔹 Features:

* `/signup` API
* `/login` API
* Database integration
* Tested using Thunder Client

---

## 🔁 Project Evolution

C++ File System ➝ Flask API ➝ MySQL Database

---

## 🚀 How to Run

### 🔹 C++ Project

```bash
g++ main.cpp -o main
./main
```

### 🔹 Flask Backend

```bash
pip install flask mysql-connector-python
python app.py
```

---

## 🎯 Future Improvements

* Password hashing (bcrypt)
* Frontend integration
* Android app integration

---

## 👩‍💻 Author

Vanshika Jain
