#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
#include <stdint.h>

static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  printf ("system call!\n");
  thread_exit ();
}

void
halt(void){
  shutdown_power_off ();
}



void
exit(int status){
  struct thread *t = thread_current();
  //status
  //child needs to exit
  printf ("%s: exit(%d)\n", t->file_name, t->children->exit_status);
  thread_exit();
}

pid_t
exec(const char* cmd_line){

}

int 
wait(pid_t pid) {

}

bool 
create (const char *file, unsigned initial_size) {

}

bool 
remove (const char *file) {

}

int 
open (const char *file) {

}

int 
filesize (int fd) {

}


int 
read (int fd, void *buffer, unsigned size) {

}


int 
write (int fd, const void *buffer, unsigned size) {



}


void 
seek (int fd, unsigned position) {

}


unsigned 
tell (int fd) {

}




void 
close (int fd) {

}
