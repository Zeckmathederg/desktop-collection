#include <gnu/libc-version.h>
#include <stdio.h>
#include <string.h>
int main() {
	//const char* glibcVersion = gnu_get_libc_version();
	printf("/usr/lib/libc.so.6 is glibc-%s\n",gnu_get_libc_version());
	return 0;
}
