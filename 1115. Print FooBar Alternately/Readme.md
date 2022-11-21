<center><h1>Print FooBar Alternately</h1></center>

[Leetcode Link](https://leetcode.com/problems/print-foobar-alternately/)
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
As mentioned, two functions will be called by two different threads, what we need to do is to lock a thread til another is done.  
`Semaphore` can achieve that easily.

### SemaphoreSlim
`Semaphore` can be imagined as a car park, where a limited number of cars can be parked:
1. No cars can be entered when the car park is entire.
2. When a car leaves, open a space (release).
3. When a car enters, keep a space for that car (wait/wait async).

`SemaphoreSlim` is a light implementation of `Semaphore` in C#, which is more flexible for users:
```csharp
public SemaphoreSlim(int initialCount);
public SemaphoreSlim(int initialCount, int maxCount);
```
The `initialCount` indicates how many threads can enter in default, call `Release()` to add one, and call `Wait()` or `WaitAsync()` to minus one.
The `maxCount` indicates the max number of threads that can enter.
```csharp
Lock.WaitAsync();
Lock.Release();
```

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
        for (int i = 0; i < n; i++ {
            BarLock.Wait();
            
            // printFoo() outputs "foo". Do not change or remove this line.
            printBar();
            FooLock.Release(1);
        }
    }
}
```