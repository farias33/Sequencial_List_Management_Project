# **Sequential List Management Project**

## **Overview**

This project implements a simple system to manage a sequential list of **`pessoa`** structures, each containing a **`nome`** (name) and an **`rg`** (identification number). The project includes functionalities to add, remove, and search for elements in the list, as well as to print the list's contents. It is an open-source project and contributions are welcome.

## **Technical Details**

The project is written in C++ and utilizes basic structures and dynamic memory management techniques to manipulate the sequential list. The main components are:

- **Structures**: **`pessoa`** containing **`nome`** and **`rg`**.
- **Functions**:
    - **`imprimeSequencial`**: Prints the list.
    - **`adcComecoSequencial`**: Adds an element at the start.
    - **`adcFimSequencial`**: Adds an element at the end.
    - **`adcPosicaoSequencial`**: Adds an element at a specific position.
    - **`removeInicioSequencial`**: Removes the first element.
    - **`removeFimSequencial`**: Removes the last element.
    - **`removePosicaoSequencial`**: Removes an element from a specific position.
    - **`retornaNomeSequencial`**: Searches for an element by **`rg`**.
    - **`limpaTela`**: Clears the console screen.
    
    ## **Execution Instructions**
    
    1. **Compile the Code**: Ensure you have a C++ compiler installed (e.g., g++). Compile the code using the following command:
        
        ```css
        cssCopiar código
        g++ -o SequentialListManagement main.cpp
        ```
        
    2. **Run the Program**: Execute the compiled binary:
        
        ```
        Copiar código
        ./SequentialListManagement
        ```
        
    
    ## **Project Description**
    
    The project is designed to demonstrate basic dynamic memory allocation and manipulation in C++. It provides a menu-driven interface for managing a sequential list of persons (**`pessoa`**). The user can perform various operations such as adding, removing, and searching for persons within the list.
    
    ## **How to Contribute**
    
    We welcome contributions to enhance the functionalities and improve the code quality. Here are the steps to contribute:
    
    1. **Fork the Repository**: Create a fork of this repository on GitHub.
    2. **Clone the Repository**: Clone your forked repository to your local machine.
        
        ```bash
        bashCopiar código
        git clone https://github.com/your-username/sequential-list-management.git
        ```
        
    3. **Create a Branch**: Create a new branch for your feature or bug fix.
        
        ```css
        cssCopiar código
        git checkout -b feature-name
        ```
        
    4. **Make Changes**: Implement your changes and commit them with descriptive messages.
        
        ```sql
        sqlCopiar código
        git commit -m "Description of the feature or fix"
        ```
        
    5. **Push Changes**: Push your changes to your forked repository.
        
        ```perl
        perlCopiar código
        git push origin feature-name
        ```
        
    6. **Create a Pull Request**: Open a pull request in the original repository, describing your changes in detail.
    
    ## **Use instructions**
    
    1. **Compilar o Código**: Certifique-se de ter um compilador C++ instalado (por exemplo, g++). Compile o código usando o comando:
        
        ```css
        cssCopiar código
        g++ -o SequentialListManagement main.cpp
        ```
        
    2. **Executar o Programa**: Execute o binário compilado:
        
        ```
        Copiar código
        ./SequentialListManagement
        ```
        
    
    Este projeto é um sistema simples para gerenciar uma lista sequencial de estruturas **`pessoa`**, permitindo a adição, remoção e busca de elementos na lista, além de imprimir o conteúdo da lista.
