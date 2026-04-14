# 📌 Expression Conversion App (C Language)

## 📖 Overview

This project is a menu-driven application written in C that converts mathematical expressions between different notations:

* Infix → Postfix
* Infix → Prefix

It uses the **stack data structure** to handle operator precedence and associativity.

---

## 🚀 Features

* Convert Infix expression to Postfix
* Convert Infix expression to Prefix
* Simple menu-driven interface
* Efficient use of stack operations
* Easy to understand and modify

---

## 🧠 Concepts Used

* Stack (Array Implementation)
* Operator Precedence
* Expression Conversion Algorithms
* String Manipulation

---

## ⚙️ Technologies Used

* Programming Language: C
* Compiler: GCC / Turbo C

---

## ▶️ How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/expression-conversion.git
   ```

2. Navigate to the project folder:

   ```bash
   cd expression-conversion
   ```

3. Compile the program:

   ```bash
   gcc program.c -o app
   ```

4. Run the program:

   ```bash
   ./app
   ```

---

## 🧪 Sample Input & Output

**Input:**

```
Enter Infix Expression: A+B*C
```

**Output:**

```
Postfix Expression: ABC*+
Prefix Expression: +A*BC
```

---

## 📌 Example Conversions

| Infix   | Postfix | Prefix |
| ------- | ------- | ------ |
| A+B     | AB+     | +AB    |
| A*B+C   | AB*C+   | +*ABC  |
| (A+B)*C | AB+C*   | *+ABC  |

---

## 📈 Future Improvements

* Add Postfix → Infix conversion
* Add Prefix → Infix conversion
* Add Expression Evaluation
* Add GUI interface

---

## 👨‍💻 Author

* Your Name

---

## 📜 License

This project is open-source and free to use for educational purposes.
