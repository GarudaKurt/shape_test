#include <stdio.h>
#include <stdarg.h>

void PrintLogs(const char * format, ...) { 

     char buffer[256];
     va_list args;
     va_start(args, format);
     vsprintf(buffer, format,args);
     perror(buffer);
     va_end(args);

}

int main() 
{
    PrintLogs("Stack trace logs %s\n%s\n",
             "[ERROR]: Uninitialize variable", 
	     "[WARN] Missing declartions!");
    return 0;
}
