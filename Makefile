make:
	g++ -lm -std=c++11 -o check.exe main.cpp

runk:
	./check.exe kcore.txt kcore_cmp.txt k
runc:
	./check.exe clique.txt clique_cmp.txt c

.PHONY: clean

clean:
ifeq ($(OS),Windows_NT)
	del main.exe *.o
else
	rm main *.o
endif