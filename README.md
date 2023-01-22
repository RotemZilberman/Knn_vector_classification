# AdvancedProgramming_lastPart
This is our Classification project, as part of Advanced programming course, last exercise.
## Description
Our project's goal was to create a server that creates a database with which we can judge, by a given vectors of information and
different ways of measuring, a classification of the given objects.
We create different kinds of databases for vectors, extending the already existing STL vector (classified and unclassified,
and have multiple ways of checking the similarity between one vector and another, used for deciding the type of
object, by comparisons.
The way we implement those functionalities is by creating a TCP server and client codes, that were made to interact with each other.
We start by activating the server, waiting for clients to connect. once connected, the client shows the user the options menu og the server.
THe user is able to choose an action as it pleases, such as aploading classified and unclassified vectors, execting the KNN algorithn and downloading the results.
Farthemore, we implemented our own classes, used by the server and client: Helper (containing useful functions for analizing data), 
Vector's math (using the last assignment), the Knn algorithm (K-nearest-neighbors), DefaultIO (for establishing communication), Commands (that can be executed for each options) and much more.
Our different approaches of measuring are: Euclidean distance, Manhattan geometry, Chebyshev distance, Canberra distance and Minkowski distance (with permanent p of 2).
Each of the methods stated above requires different logic, thus requiring its own recognition.
For this project, proper input is input according to the requested instructions.
The server requires arguments: port(to listen to). 
The client requires arguments: ip (of the server, including localhost), port(the one the server listens to).
Placing spaces, dots, and various symbols in unusual places will result in an error as expected and the program
will close. Also, division by 0 will carry nan.
Please note, the project is implemented by thread pull and as part of its settings we decided to have a maximum of 5 clients running at the same time, any additional client will not be accepted immediately.
## Getting Started
### Dependencies
* This project was made in C++ language, on Clion, Windows 11.
* and used different libraries such as: vector, iostream, cmath.
### Installing
* You can download this project from our GitHub website we built in order to save and collect
  all the necessary parts and files in one place.
### Executing Program
The executing process is divided into several main parts:
* First, after all the files are arranged as shown on our git site, run the make file in the terminal.
```
make
```
* Second, run the server file.
```
./server.out port
```
* third, run the client file.
```
./client.out ip port
```
* finally, after the process executes, it is recommended to delete the unnecessary files using the makefile in the terminal.
```
make clean
```
## Authors
* Rotem Zilberman 213231418
* Ohad Langer 325774750 
