SlowIntegerHeap::SlowIntegerHeap(SlowInteger a[], int s,bool empty)
{
    array = new SlowInteger[s];
    size = 0;

    if(empty == false)
    {
        for(int i=0;i<s;i++)
            insert(a[i]);
    }


}

/*
 * Returns the maximum value from the heap
 */
SlowInteger SlowIntegerHeap::findMax()
{
    return array[0];
}

/*
 * Returns and remove from the heap the
 * maximum value from the heap
 */
SlowInteger SlowIntegerHeap::deleteMax()
{
  if(!isEmpty())
    {
        SlowInteger temp = array[0];
        array[0] = array[size-1];
        size--;
        percDown(0);
        return temp;
    }
    else
    {
        cout << "Wrong !!!" << endl;
        return 0;
    }
}

/*
 * Insert the integer 'value' in the heap
 */
void SlowIntegerHeap::insert(SlowInteger value)
{
    array[size] = value;

    for(int c = size, p = parent(c) ;c != 0 ;c = p, p = parent(c))
        {
            if(array[c]>array[p])
            {
                SlowInteger temp;
                temp     = array[p];
                array[p] = array[c];
                array[c] = temp;
            }
        }
    size++;


}

/*
 * Checks if the heap is empty
 */
bool SlowIntegerHeap::isEmpty()
{
    return size == 0;
}

/*
 * Returns the aprant node of node n
 */
int SlowIntegerHeap::parent(int n)
{
   return (n-1)/2;
}

/*
 * Returns the left node of node n
 */
int SlowIntegerHeap::left(int n)
{

    return n*2+1;
}

/*
 * Returns the right node of node n
 */
int SlowIntegerHeap::right(int n)
{

    return n*2+2;
}

/*
 * Percolates down the value at node n.
 * The left and right nodes of node n MUST be heaps.
 */
void SlowIntegerHeap::percDown(int n)
{
       int l = left(n),r=right(n);
       if(r < size || l< size)
       {
        if(array[n] < array[l] || array[n] < array[r])
            {
                if(array[r] <= array[l])
                {
                    SlowInteger temp;
                    temp = array[n];
                    array[n] = array[l];
                    array[l] = temp;
                    percDown(l);
                }
                else
                {
                    SlowInteger temp;
                    temp = array[n];
                    array[n] = array[r];
                    array[r] = temp;
                    percDown(r);
                }
            }

       }


}
/*
 * Performs an heapsort on the array 'array'
 * of size 'size' using a SlowIntegerHeap object
 */
void heapsort(SlowInteger array[], int size)
{

    SlowIntegerHeap heap(array,size,false);

    for(int i = 0;i<size;i++)
        {
            array[i] = heap.deleteMax();
        }
}
