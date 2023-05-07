#include <stdio.h>
#include "ui/gtk_main.h"

int main(int argc, char *argv[]){
    int status = 0;

    status = gtk_main(argc, argv);

    return status;
}