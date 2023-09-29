clean:
	cd src/ && rm -rf liblinkedlist.so

install:
	cd src/ && g++ -o liblinkedlist.so linkedlist.cpp -fPIC -shared