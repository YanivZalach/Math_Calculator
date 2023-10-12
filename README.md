# 🚀 Math Calculator Project

Welcome to my awesome calculator project! This C++ program can take a mathematical expression as a string and calculate the result. It supports the basic arithmetic operations `(`, `+`, `-`, `*`, `/`, `)`

The project is being compiled using `Makefiles` with means that you need a Unix system to run it (MacOS, Linux, WSL).

And supports the order of operations.

## 🧑💻 Beginner's Journey

This project represents the knowledge I've acquired so far in my journey of learning C++.

## 📚 Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Pay Attention](#pay-attention)
- [License](#license)

## ✨ Features

- Perform arithmetic operations `(`, `+`, `-`, `*`, `/`, `)`
- Handle complex expressions with parentheses.
- Easy-to-use interface that support the regular way of writing mathematical expressions.
- Written in C++ for efficiency and performance.
- The project uses only the standard library so if you have a Compiler, you already set.

## 🚀 Getting Started

To use this calculator in your project, follow these simple steps:

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/YanivZalach/Math_Calculator.git ~/Documents/calculate
   ```

2. Compile the C++ source code using `Makefiles`:

   ```bash
   make all
   ```

3. Run the program:

   ```bash
   ./calculator
   ```

4. Add to `.bashrc`:

   ```bash
   alias calc="$HOME/Documents/calculate/calculator"
   ```

   Now you can run the calculator from  everywhere using:

   ```bash
   calc
   ```


## 📝 Usage

You can use the calculator by providing a mathematical expression. For example:

```bash
$ calc
Math exasperation: (5 + 3) * 2 / (7 - 2)
>> 3.2
```
Here are some examples to try:

- `2 + 3`
- `(5 - 2) * 4 / 2`
- `10 / (2 + 3)`

## 🌟Pay Attention

You can't write decimal numbers by using the `.` operator, instead use the `/` operator.

```
0.8 = (8/10)
```

## 📄 License

This project is licensed under the [MIT License](LICENSE).

