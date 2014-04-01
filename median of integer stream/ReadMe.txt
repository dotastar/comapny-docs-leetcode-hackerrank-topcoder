Numbers are randomly generated and passed to a method. Write a program to find and 
maintain the median value as new values are generated.

设计两个堆，其中一个保存不比中数小的数字minHeap，    
另一个保存不比中数大的数字maxHeap。
保持maxHeap的大小不小于minHeap

follow up:
如果内存有限，无法放入那么大的 heap如何处理?
