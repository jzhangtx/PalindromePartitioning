PalindromePartitioning: PalindromePartitioning.o
	g++ -g -o PalindromePartitioning.exe PalindromePartitioning.o -pthread    

PalindromePartitioning.o: PalindromePartitioning/PalindromePartitioning.cpp
	g++ -g  -c -pthread PalindromePartitioning/PalindromePartitioning.cpp
