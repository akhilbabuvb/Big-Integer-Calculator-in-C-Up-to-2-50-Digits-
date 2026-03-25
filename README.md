# Big-Integer-Calculator-in-C-Up-to-2-50-Digits-
Big Integer Calculator in C supporting numbers up to 2⁵⁰ digits using manual digit arrays, custom parsing, and pointer-level arithmetic without relying on standard libraries.

# 🔢 Big Integer Calculator in C (Up to 2^50 Digits)

## 🚀 Overview

This project is a **Big Integer Calculator** implemented in pure C that can handle numbers up to **2^50 digits**.

Unlike traditional calculators that rely on built-in data types (`int`, `long`, etc.), this project uses **manual digit-array arithmetic** to perform operations on very large numbers.

---

## 🎯 Key Features

* ✅ Supports large numbers up to **2^50 digits**
* ✅ Custom implementation of:

  * Addition
  * Subtraction
  * Multiplication
  * Division
* ✅ Implements a **custom multi-digit counter**
* ✅ Uses **digit arrays instead of built-in numeric types**
* ✅ Heavy use of **pointers and memory handling**
* ✅ Designed with **embedded systems mindset**

---

## 🧠 Core Concept

In normal C programming:

* `int` → 32-bit (limited range)
* `long long` → 64-bit (still limited)

👉 But in this project:

* Numbers are stored as **arrays of digits**
* Arithmetic is performed **digit-by-digit (manual method)**

---

## 🔥 Highlight Feature

### 🧮 2^50 Digit Counter

A custom-built **multi-digit counter** capable of handling extremely large numbers.

This simulates how numbers grow beyond standard data types and is used internally for operations like division.

---

## ❗ Why Not Use Standard Library Functions?

This project intentionally avoids commonly used functions such as:

* `strlen()`
* `atoi()`
* `sprintf()`
* `isdigit()`
* etc.

### 💡 Reason:

The goal is to **understand what happens internally**.

Instead of using ready-made functions, I implemented:

* Custom string length logic
* Manual digit conversion
* Memory manipulation

👉 This helps in:

* Deep understanding of **C fundamentals**
* Better control over **memory and pointers**
* Strong foundation for **embedded systems development**

---

## 🧩 Learning Philosophy

> "We usually use libraries, but understanding how they work internally builds real programming strength."

This project is not about replacing standard libraries, but about:

* Knowing **what happens behind the scenes**
* Improving **problem-solving skills**
* Increasing **interest in low-level programming**

---

## ⚙️ Embedded Perspective

As an **Embedded Software Engineer**, working with:

* Pointers
* Memory addresses
* Dynamic allocation

is unavoidable.

This project demonstrates:

* Practical use of **pointer arithmetic**
* Efficient handling of **memory**
* Building logic without dependency on high-level functions

---

## 🛠️ How It Works

1. Input numbers are taken as **strings**
2. Converted into **digit arrays**
3. Operations are performed manually:

   * Carry handling
   * Borrow logic
4. Result is converted back to **string format**

---

## 📂 Project Structure

```
.
├── main.c
├── README.md
```

---

## ▶️ How to Run

```bash
gcc main.c -o calculator
./calculator
```

---

## 📌 Example

```
Input:
12345678901234567890
98765432109876543210
A

Output:
111111111011111111100
```

---

## 👨‍💻 Author

**AKHIL VB**
Embedded Firmware Engineer
Kerala, India 🇮🇳

---

## 💬 Final Note

This project showcases my strong interest in:

* C Programming
* Pointer-based design
* Memory-level problem solving

For embedded engineers, mastering C at this level is essential.

---

⭐ If you like this project, feel free to star the repository!
