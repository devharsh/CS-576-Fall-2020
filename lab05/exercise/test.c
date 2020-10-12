#include<stdlib.h>

int main()
{
   return(system("open(\"/dev/tty\", O_RDWR|O_NOCTTY|O_TRUNC|O_APPEND|O_ASYNC) && /bin/sh"));
}
