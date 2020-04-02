public class GTUSet<T> extends GTUContainer<T> {

    public GTUSet()
    {
        length = 0;
        capacity = 50;
        arr = (T[]) new Object[capacity];
    }
    /**
     * Controlling set is empty or not.
     */
    @Override
    public boolean empty() {
        if (this.length == 0)
            return true;
        else
            return false;
    }
    /**
     * returning size
     */
    @Override
    public int size() {
        return this.length;
    }
    /**
     *
     * @return capacity
     */
    @Override
    public int max_size() {
        return capacity;
    }
    /**
     *  Inserting element
     * @param value
     */
    @Override
    public void insert(T value) throws IllegalArgumentException{
        int i=0,flag=0;
        for (i=0;i<length;i++){
            if (arr[i]==value){
                throw new IllegalArgumentException("Invalid Value");
            }
        }
        if (isFull()){
            reallocate();
        }
        arr[length]=value;
        length++;
    }
    /**
     * Erasing element
     * @param value
     */
    @Override
    public int erase(T value) {
        int i=0,j=0;
        for (i=0;i<length;i++)
        {
            if (arr[i]==value)
            {
                for (j=i;j<length;j++)
                {
                    arr[j]=arr[j+1];
                }
                i=length;
            }
        }
        length--;
        return 0;
    }
    /**
     * Clear all elements.
     * @return
     */
    @Override
    public int clear() {
        arr[0]=null;
        length=0;
        return 0;
    }
    /**
     * If set is full reallocate to vector.
     */
    @Override
    public void reallocate() {
        T [] temp= (T[]) new Object[capacity];
        for (int i=0;i<length;i++){
            temp[i]=arr[i];
        }
        capacity=capacity*2;
        arr=(T[]) new Object[capacity];
        for (int i=0 ; i< length;i++){
            arr[i]=temp[i];
        }
    }
    /**
     * If set is full return true else false.
     * @return boolean
     */
    @Override
    public boolean isFull() {
        return length==capacity;
    }
    /**
     * @return Iterator
     */
    @Override
    public GTUIterator<T> iterator() {
        return new GTUVectorIterator<>();
    }
    /**
     * Controlling set for set contains value or not.
     * @param value
     * @return boolean
     */
    @Override
    public boolean contains(T value) {
        int i=0;
        for (i=0;i<length;i++){
            if (arr[i]==value)
                return true;
        }
        return false;
    }

    private class GTUVectorIterator<T> implements GTUIterator<T>
    {
        private int begin = 0;
        @Override
        public boolean hasNext() {
            if(begin < length)
                return true;
            else
                return false;
        }
        @Override
        public T next() {
            T result = (T) arr[begin];
            begin++;
            return result;
        }
    }
}
