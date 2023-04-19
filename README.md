# hotrl

Proof of concept for hot reloading MVC controllers eventually written in C

## Idea

One can outsource parts of a web application into shared libraries that compile individually and loaded dynamically by the core.

## Compile

How to compile the example?

`gcc -c greet_controller.c -fPIC -o greet_controller.o`

`gcc -shared greet_controller.o -o greet_controller.so`

`gcc program.c -ldl -o program`

