using System.Threading;

public class FooBar {
    private int n;
    private SemaphoreSlim FooLock;
    private SemaphoreSlim BarLock;

    public FooBar(int n) {
        this.n = n;
        FooLock = new SemaphoreSlim(0, 1);
        BarLock = new SemaphoreSlim(0, 1);
        FooLock.Release(1);
    }

    public void Foo(Action printFoo) {
        for (int i = 0; i < n; i++) {
            FooLock.Wait();
            
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            BarLock.Release(1);
        }
    }

    public void Bar(Action printBar) {
        for (int i = 0; i < n; i++ {
            BarLock.Wait();
            
            // printFoo() outputs "foo". Do not change or remove this line.
            printBar();
            FooLock.Release(1);
        }
    }
}