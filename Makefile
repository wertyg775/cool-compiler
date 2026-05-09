coolc: src/main.c
	cc -std=c11 -Wall -Wextra -Iinclude src/main.c -o coolc

clean:
	rm -f coolc