# Build main from myHeader.cpp and main.cpp
#
# all:  ../ch4/SimpleArray.o ../ch6/Point.o ../ch6/Line.o solution1.o
# 	g++-9 -c ../ch4/SimpleArray.cpp
# 	g++-9 -c ../ch6/Point.cpp
# 	g++-9 -c ../ch6/Line.cpp
# 	g++-9 -c solution1.cpp
# 	g++-9 -o sol1 ../ch4/SimpleArray.o ../ch6/Point.o ../ch6/Line.o solution1.o 
# 	./sol1


all:  ../ch4/SimpleArray.o ../ch6/Point.o ../ch6/Line.o Element.o Mesh.o solution2.o
	g++-9 -c ../ch4/SimpleArray.cpp
	g++-9 -c ../ch6/Point.cpp
	g++-9 -c ../ch6/Line.cpp
	g++-9 -c Element.cpp
	g++-9 -c Mesh.cpp
	g++-9 -c solution2.cpp
	g++-9 -o sol2 ../ch4/SimpleArray.o ../ch6/Point.o ../ch6/Line.o Element.o Mesh.o solution2.o 
	./sol2

clean:
	rm *.o	
	
#include "../ch6/Point.h"