#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char* argv[]) {
	cout << "\nДочерний процесс начал работу\n";

	cout << "Child - id свой: " << getpid() << "\n" << "Child - id родителя:" << getppid() << "\n";

	for (int i = 0; i < argc; i++) {
		cout << "Child arg " << i + 1 << ": " << argv[i] << "\n";
		sleep(1);
    	}

	cout << "Конец работы дочернего процесса\n\n";

	exit(1);
}
