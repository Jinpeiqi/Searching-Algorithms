Display.exe	: Display.o graphics.o puzzle.o algorithm.o
	g++ -Wl,-s -o Display.exe Display.o graphics.o puzzle.o algorithm.o
			
Display.o	: Display.cpp graphics.h puzzle.h algorithm.h
	g++ -c -fpermissive -fconserve-space Display.cpp
	
puzzle.o		: puzzle.cpp puzzle.h
	g++ -c -fpermissive -fconserve-space puzzle.cpp
	
algorithm.o	: algorithm.cpp algorithm.h
	g++ -c -fpermissive -fconserve-space algorithm.cpp
graphics.o  : graphics.cpp graphics.h
	g++ -c -fpermissive -fconserve-space graphics.cpp
	

