Program for generating a random variable in one processor and communicate it to another processor with mpi
Code based on the round_robin program from : https://www.youtube.com/watch?v=c0C9mQaxsD4


Round Robin:
1) Generate a random value on one processor.
2) Send this random value to another processor.
3) Receive a random value from another processor.
4) Repeat these steps for all the processors.

All the processors in the global space in divided in two types : even and odd based on their rank
- The even ranked processor send the value and then receives
- The odd ranked processor receives the value and then sends its value

This is done to reduce the wait time
if all the procesors are sending at once the processors need to finish their send to start the receive.
