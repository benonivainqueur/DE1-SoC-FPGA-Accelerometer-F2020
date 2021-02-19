DE1SoChps.o: DE1SoChps.h DE1SoChps.cpp
	g++ -g -Wall -c DE1SoChps.cpp

DE1SoCfpga.o: DE1SoCfpga.h DE1SoCfpga.cpp
	g++ -g -Wall -c DE1SoCfpga.cpp

GSensor.o: GSensor.h GSensor.cpp
	g++ -g -Wall -c GSensor.cpp

PIOControl.o: PIOControl.h PIOControl.cpp
	g++ -g -Wall -c PIOControl.cpp

GSensorMain.o: GSensorMain.cpp GSensor.o PIOControl.o
	g++ -g -Wall -c GSensorMain.cpp

project: GSensorMain.o GSensor.o DE1SoChps.o DE1SoCfpga.o PIOControl.o 
	g++ GSensorMain.o DE1SoChps.o DE1SoCfpga.o GSensor.o PIOControl.o -o project

clean:
	rm GSensor.o DE1SoChps.o PIOControl.o GSensorMain.o DE1SoCfpga.o project
