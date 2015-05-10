rm obj/*

g++ -std=c++11 -pthread -I"include/" -g3 -Wall -c -o "obj/Stack.o" "src/Stack.cc"

g++ -std=c++11 -pthread -I"include/" -g3 -Wall -c -o "obj/Stack_interface.o" "src/Stack_interface.cc"

g++ -std=c++11 -pthread -I"include/" -g3 -Wall -c -o "obj/Stack_test.o" "src/Stack_test.cc"

g++ -std=c++11 -pthread -I"include/" -g3 -Wall -c -o "obj/main.o" "src/main.cc"

g++ -std=c++11 -pthread -I"include/" -g3 -Wall -c -o "obj/stoi.o" "helpers/stoi.cc"

g++  -std=c++11 -pthread -o "bin/FORTH_interpreter"  ./obj/Stack.o ./obj/Stack_interface.o ./obj/Stack_test.o ./obj/main.o ./obj/stoi.o