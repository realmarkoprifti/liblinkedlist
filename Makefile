clean:
	rm -rf build/

build:
	mkdir -p build
	cd src/ && g++ -o liblinkedlist.so linkedlist.cpp -fPIC -shared && mv liblinkedlist.so ../build/

install:
	mkdir -p build
	cd src/ && g++ -o liblinkedlist.so linkedlist.cpp -fPIC -shared && mv liblinkedlist.so ../build/
	cd build/ && sudo mv liblinkedlist.so /usr/local/lib 
	rm -rf build/