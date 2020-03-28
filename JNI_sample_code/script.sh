javac -h . test.java
javac test.java
gcc -o libhello.so -lc -shared  -I/usr/lib/jvm/java-8-openjdk-amd64/include  -I/usr/lib/jvm/java-8-openjdk-amd64/include/linux helloworld.c
export LD_LIBRARY_PATH=.
java HelloWorld
