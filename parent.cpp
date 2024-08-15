#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/wait.h>
#include "iostream"

using namespace std;

int main(int argc, char* argv[]) {

	struct timespec start;
    cout << "\nРодитель начал работу\n";

    char s[256] = "SHELL = text";
    argv[0] = s;

    int status = 0;

    cout << "РОДИТЕЛЬ - id свой: " << getpid() << "\n"
        << "РОДИТЕЛЬ - id родителя:" << getppid() << "\n";

    pid_t pid = fork();

    if (pid == 0) {
    	execv("child", argv);
    	}
    else if (pid == -1) {
        perror("Error: ");
    }
    else {
	cout << "РОДИТЕЛЬ - id дочернего процесса: " << pid << "\n";
	while (waitpid(pid, &status, WNOHANG) == 0) {
		clock_gettime(CLOCK_REALTIME, &start);
		cout << "\nВремя ( секунды ): " << start.tv_sec << "\n\n";
	    sleep(0.5);
	    }
    }
    cout << "Код завершения дочернего процесса: " << WEXITSTATUS(status) << "\n";

    cout << "Конец работы родителя\n";

    return 0;
    }
