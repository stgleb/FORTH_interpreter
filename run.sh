g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Stack.d" -MT"Stack.d" -o "Stack.o" "Stack.cc"

g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Stack_interface.d" -MT"Stack_interface.d" -o "Stack_interface.o" "Stack_interface.cc"

g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Stack_test.d" -MT"Stack_test.d" -o "Stack_test.o" "Stack_test.cc"

g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"logic.d" -MT"logic.d" -o "logic.o" "logic.cc"

g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"main.d" -MT"main.d" -o "main.o" "main.cc"

g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"stoi.d" -MT"stoi.d" -o "stoi.o" "stoi.cc"

g++  -o "FORTH_interpreter"  ./Stack.o ./Stack_interface.o ./Stack_test.o ./logic.o ./main.o ./stoi.o 

./FORTH_interpreter