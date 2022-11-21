<center><h1>Print FooBar Alternately</h1></center>

### Intrudoction

The following code is provided by default, the same instance `FooBar` will be passed to two threads as:
```csharp
class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
```
* Thread `A` call `foo()`
* Thread `B` call `bar()`

The giving code should be modified so that the printed value wiil be `FooBarFooBar...` alternately. 

### Method


### Code
```csharp
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
        for (int i = 0; i < n; i++) {
            BarLock.Wait();
            // printFoo() outputs "foo". Do not change or remove this line.
            printBar();
            FooLock.Release(1);
        }
    }
}
```