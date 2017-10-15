
all: compile run
compile: 
	@g++ -O3 -std=c++11 *.h *.cpp
run:
	@./a.out "abra" "../texto.txt"

clean:
	@rm *.gch
	@rm *.out