# 🧪 OOP Labs – C++

This repository contains a collection of OOP labs implemented in C++ as part of the ITI training program.  
Each lab focuses on a specific Object-Oriented Programming concept such as classes, inheritance, polymorphism.

---

### ✅ Lab 7 – Classes & Object-Oriented Basics

Lab 7 covers the fundamentals of object-oriented programming, including:

- Defining classes & objects  
- Constructors and accessors  
- Operator overloading  
- Simple stack implementation  
- Bank account simulation  

**Files included:**
- `bankAccount.cpp`
- `complex.cpp`
- `stack.cpp`
- `main.cpp`
- Executables: `.exe`, `.o`

---

### 🧪 Lab 8 – Extended OOP Practice

Lab 8 extends Lab 7 with more structured code and multiple compilation units, practicing:

- Improved class design  
- Separate modules for each feature  
- Multiple executables for testing  

**Files included:**
- `bankAccount.cpp`
- `bankAccount.exe`
- `complex.cpp`
- `complex.exe`
- `main.cpp`
- `main.exe`
- `main.o`
- `stack.cpp`
- `stack.exe`

---

### 🧩 Lab 9 – Composition, Aggregation & Copy Control

Lab 9 introduces more advanced OOP concepts:

- Composition (Book → Author)
- Aggregation (Library → Books)
- Copy Constructor & Assignment Operator
- Dynamic memory handling
- Passing objects by reference

**Files included:**
- `main.cpp`
- `main2.cpp`
- `main.exe`
- `main2.exe`
- `main.o`

---
## 🔷 Lab 10 – Simple Graphics Library (Drawing Shapes)

Lab 10 focuses on implementing a lightweight graphics engine in C++ that draws basic shapes on a console window using OOP principles:

- Classes & Header/Source separation

- Encapsulation

- Simple drawing API

- Handling shapes using functions

- Structuring a multi-file project (cpp, h, layout, depend…)

**Features:**

- Drawing lines

- Drawing rectangles

- Drawing circles

- Rendering simple 2D shapes

**Files included:**

Inside Lab10/:

- `main.cpp`

- `main.exe`

- `main.o`

Inside Lab10/SimpleGraphics/:

- `SimpleGraphics.cpp`

- `SimpleGraphics.h`

- `SimpleGraphics.cbp`

- `SimpleGraphics.layout`

- `SimpleGraphics.depend`
---
## 🔶 Lab 11 – Advanced Inheritance & Polymorphism (Shapes Library)

Lab 11 focuses on building a complete geometric shapes framework using **inheritance**, **abstract classes**,  
**virtual functions**, and **polymorphism**.  
It demonstrates how OOP concepts scale when designing reusable mini-libraries.

### **📌 Concepts Covered**
- Abstract classes & pure virtual functions  
- Hierarchical & multilevel inheritance  
- Virtual methods & overriding  
- Polymorphism using base-class pointers  
- Sorting objects polymorphically by area  
- Operator overloading (assignment operator)  
- Dynamic memory handling with pointers & vectors  

### **📐 Shapes Implemented**
- Rectangle  
- Square  
- Circle  
- Triangle (Heron's Formula)  
- Rhombus  
- Cube (3D extension of Square)  

### **✨ Main Features**
- Compute area, perimeter, and volume (for 3D shapes)  
- Display shape information with overridden `printShape()`  
- Compare shapes by area using virtual functions  
- Sort a vector of base-class pointers (`Geoshape*`)  
- Demonstrate deep copy using the assignment operator  

### **📁 Files Included (Lab11/)**
- `main.cpp`  
- `main.exe`  
- `main.o`
  
---

## 📂 Project Structure
```
/
├── Lab7/
│   ├── bankAccount.cpp
│   ├── complex.cpp
│   ├── stack.cpp
│   ├── main.cpp
│   └── *.exe / *.o
│
├── Lab8/
│   ├── bankAccount.cpp
│   ├── bankAccount.exe
│   ├── complex.cpp
│   ├── complex.exe
│   ├── main.cpp
│   ├── main.exe
│   ├── main.o
│   ├── stack.cpp
│   └── stack.exe
│
├── Lab9/
│   ├── main.cpp
│   ├── main2.cpp
│   ├── main.exe
│   ├── main2.exe
│   └── main.o
│
├── Lab10/
│   ├── main.cpp
│   ├── main.exe
│   ├── main.o
│   └── SimpleGraphics/
│       ├── SimpleGraphics.cpp
│       ├── SimpleGraphics.h
│       ├── SimpleGraphics.cbp
│       ├── SimpleGraphics.layout
│       ├── SimpleGraphics.depend
│       ├── bin/Debug/
│       └── obj/Debug/
├── Lab11/
│   ├── main.cpp
│   ├── main.exe
│   └── main.o

```

---

## 👨‍💻 Author

**Mohanad Tarek (Honda)**  
OOP Labs – ITI Training

