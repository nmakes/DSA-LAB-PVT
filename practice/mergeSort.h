#include <stdio.h>
#include <stdlib.h>

#define var unsigned long int

void merge(var A[], var sa, var ea, var B[], var sb, var eb, var C[], var sc, var ec);
void naiveMergeSort(var A[], var sa, var ea);
void inPlaceMergeSort(var A[], var sa, var ea);