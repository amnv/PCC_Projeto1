
all: compile run
compile: 
	@g++ -std=c++11 *.h *.cpp
run:
	@./a.out

clean:
	@rm *.gch
	@rm *.out