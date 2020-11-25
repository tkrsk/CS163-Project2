#include "app.h"

using namespace std;

int main(int argc, char** argv, char** envp){
	int init = 3;
	Manager program(init);

	program.start();
}
