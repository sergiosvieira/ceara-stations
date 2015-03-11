all:
	g++ main.cpp -o canvas --std=c++11 `pkg-config --cflags --libs gtk+-3.0`
