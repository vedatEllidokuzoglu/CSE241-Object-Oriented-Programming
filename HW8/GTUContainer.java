public abstract class GTUContainer<T> {
    protected int capacity;
    protected T [] arr;
    protected int length;

    public abstract boolean empty();
    public abstract int size();
    public abstract int max_size();
    public abstract void insert(T value);
    public abstract int erase(T value);
    public abstract int clear();
    public abstract void reallocate();
    public abstract boolean isFull();
    public abstract GTUIterator<T> iterator();
    public abstract boolean contains(T value);

}
