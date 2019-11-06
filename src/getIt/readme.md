# getIt
This folder will contain the functions that get input from the user

GetValues function
   This function pulls input from stdin into buffer on stack and copy's it into heap.
   The buffersize is set to 100 characters. Since fget will copy \n into the buffer, strchr is used to locate \n and replace it with \0. A pointer to the heap is returned to the calling function.
