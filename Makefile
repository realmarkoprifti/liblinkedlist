clean:
	rm -rf build/

install:
	mkdir -p build
	cd src/ && g++ -o liblinkedlist.so linkedlist.cpp -fPIC -shared && mv liblinkedlist.so ../build/