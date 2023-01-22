server: server.o client.o ThreadPool.o ServerTask.o CLI.o Settings.o Command1.o Command2.o Command3.o Command4.o Command5.o Command8.o UnclassifiedCollection.o SocketIO.o KNN.o ClassifiedCollection.o TestFinding.o ClassifiedVector.o MathVector.o CanberraDistance.o EuclideanDistance.o ManhattanDistance.o MinkowskiDistance.o ChebyshevDistance.o AbstractMeasurer.h Helper.o
	g++ -std=c++11 -o server.out server.o ThreadPool.o ServerTask.o CLI.o Settings.o Command1.o Command2.o Command3.o Command4.o Command5.o Command8.o UnclassifiedCollection.o SocketIO.o KNN.o ClassifiedCollection.o TestFinding.o ClassifiedVector.o MathVector.o CanberraDistance.o EuclideanDistance.o ManhattanDistance.o MinkowskiDistance.o ChebyshevDistance.o Helper.o
	g++ -std=c++11 -o client.out client.o ThreadPool.o ServerTask.o CLI.o Settings.o Command1.o Command2.o Command3.o Command4.o Command5.o Command8.o UnclassifiedCollection.o SocketIO.o KNN.o ClassifiedCollection.o TestFinding.o ClassifiedVector.o MathVector.o CanberraDistance.o EuclideanDistance.o ManhattanDistance.o MinkowskiDistance.o ChebyshevDistance.o Helper.o
MathVector.o: MathVector.cpp MathVector.h
	g++ -std=c++11 -c MathVector.cpp
ClassifiedCollection.o: ClassifiedCollection.cpp ClassifiedCollection.h
	g++ -std=c++11 -c ClassifiedCollection.cpp
ClassifiedVector.o: ClassifiedVector.cpp ClassifiedVector.h
	g++ -std=c++11 -c ClassifiedVector.cpp
KNN.o: KNN.cpp KNN.h
	g++ -std=c++11 -c KNN.cpp
TestFinding.o: TestFinding.cpp TestFinding.h
	g++ -std=c++11 -c TestFinding.cpp
server.o: server.cpp
	g++ -std=c++11 -c server.cpp
MinkowskiDistance.o: MinkowskiDistance.cpp MinkowskiDistance.h AbstractMeasurer.h
	g++ -std=c++11 -c MinkowskiDistance.cpp
ManhattanDistance.o: ManhattanDistance.cpp ManhattanDistance.h AbstractMeasurer.h
	g++ -std=c++11 -c ManhattanDistance.cpp
Helper.o: Helper.cpp Helper.h
	g++ -std=c++11 -c Helper.cpp
EuclideanDistance.o: EuclideanDistance.cpp EuclideanDistance.h AbstractMeasurer.h
	g++ -std=c++11 -c EuclideanDistance.cpp
client.o:
	g++ -std=c++11 -c client.cpp
ChebyshevDistance.o: ChebyshevDistance.cpp ChebyshevDistance.h AbstractMeasurer.h
	g++ -std=c++11 -c ChebyshevDistance.cpp
CanberraDistance.o: CanberraDistance.cpp CanberraDistance.h AbstractMeasurer.h
	g++ -std=c++11 -c CanberraDistance.cpp
Command1.o: Command1.cpp Command1.h Command.h
	g++ -std=c++11 -c Command1.cpp
Command2.o: Command2.cpp Command2.h Command.h
	g++ -std=c++11 -c Command2.cpp
Command3.o: Command3.cpp Command3.h Command.h
	g++ -std=c++11 -c Command3.cpp
Command4.o: Command4.cpp Command4.h Command.h
	g++ -std=c++11 -c Command4.cpp
Command5.o: Command5.cpp Command5.h Command.h
	g++ -std=c++11 -c Command5.cpp
Command8.o: Command8.cpp Command8.h Command.h
	g++ -std=c++11 -c Command8.cpp
ServerTask.o: ServerTask.cpp ServerTask.h Task.h
	g++ -std=c++11 -c ServerTask.cpp
ThreadPool.o: ThreadPool.cpp ThreadPool.h
	g++ -std=c++11 -c ThreadPool.cpp
CLI.o: CLI.cpp CLI.h
	g++ -std=c++11 -c CLI.cpp
SocketIO.o: SocketIO.cpp SocketIO.h
	g++ -std=c++11 -c SocketIO.cpp
Settings.o: Settings.cpp Settings.h
	g++ -std=c++11 -c Settings.cpp
UnclassifiedCollection.o: UnclassifiedCollection.cpp UnclassifiedCollection.h
	g++ -std=c++11 -c UnclassifiedCollection.cpp
clean:
	rm server.o client.o KNN.o ClassifiedCollection.o TestFinding.o ClassifiedVector.o MathVector.o CanberraDistance.o EuclideanDistance.o ManhattanDistance.o MinkowskiDistance.o ChebyshevDistance.o Helper.o
