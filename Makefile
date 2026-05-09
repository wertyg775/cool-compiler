coolc: src/main.c
	cc -std=c11 -Wall -Wextra -Iinclude src/main.c -0 coolc

clean:
	rm -f coolc