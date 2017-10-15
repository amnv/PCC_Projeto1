
all: compile run
compile: 
	@g++ -std=c++11 *.h *.cpp
run:
	@./a.out "abra" "../texto.txt"

clean:
	@rm *.gch
	@rm *.out