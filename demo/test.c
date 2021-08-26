// You need those libraries to work with sockets
//---------------------------
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <memory.h>
//----------------------------
//"chipdom()" function comes from here
#include "functions.h"

/*
 *
 * int argument1 = number of how many arguments you pass into console
 * bash$: ./prog.exe param1 param2
 * int argument1 = 3
 *              (1 = "./prom.exe", 2 = "param1", 3 = "param2")
 * char* arguments2[] = all arguments that you pass into console, are stored in this array
 * arguments2[0] = "./prog.exe"
 * arguments2[1] = "param1"
 * arguments2[2] = "param2"
 *
 */
int main(int argument1, char *argument2[]) {
	//create object of type "addrinfo". This object will store all neccessary data for being able to "speak" on the Internet
	struct addrinfo template__for__server__info;
	//this object will be automatically filled by getaddrinfo() function and will store not only data for interconnection, but also
	//information gained from hosts it tries to connect to
	struct addrinfo *server;
	//clone of "server" in order NOT to manipulate with raw data
	struct addrinfo *pointer;
	//this will store numerical result of "getaddrinfo()" (0 if good, any other number = error)
	int status;
	//this will be used and therefore describe later...
	char ip__buffer[INET6_ADDRSTRLEN];



	fprintf(stdout, "\n-------------------- S W I P --------------------\n");
	//if "argument1 less than 2, this means, that we only entered program name into console "./prog"
	if (argument1 != 2) {
        fprintf(stderr, "\nusage: ./swip domain_name or ip\n");
        //our program is "./swip domain/ip", if param2 is added, then will cause error, since isn't expected
        if (argument1 > 2) {
            fprintf(stderr, "\nUnfortunately, only one domain name/ip can be resolved\n");
            return 1;
        	}
		return 1;
    	}
	return 0;
}
