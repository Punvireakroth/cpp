## Why pointer

Normal program can access only code section itself and stack but not heap. If we want program to access heap we need to use pointer.
Another thing is a program can access a file through pointer it means program can't access file directly. The same happend to things like keyboard, monitor, printer...
So it's an advantage for Cpp language to have pointer thus we can't write things close to hardware as well as OS. Unlike Cpp, C# and Java doesn't have pointer.

## heap memory allocation

Normal array will located in stack. If we declare \*p it's also created in stack but after we put the `p = new int[5]` the memory will located in heap.

```Cpp
int A[5] = {1,2,3,4,5}; // located in stack
int *p; // located in stack
p = new int[5]; // located in heap
```

But it also need to deallocated when you're not using it by using `delete []p`

advantage is it allow us to modify the size of the array

```Cpp
  int *p = new int[20];

  delete []p;
  p = new int[40];

```
