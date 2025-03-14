- folder structure

```vim
.
├── mystack
│   ├── C   🔥
│   │   ├── main.c
│   │   ├── mystack.c
│   │   └── mystack.h
│   ├── Cpp  🔥
│   │   ├── main.cpp
│   │   ├── mystack.cpp
│   │   └── mystack.hpp
│   └── README.md

```


-   **Static Stack (Fixed Size)**
```sql
    +---------+
    |   30    |  <- Top (index 2)
    +---------+
    |   20    |
    +---------+
    |   10    |
    +---------+
    |         |  (Unused)
    +---------+
    |         |  (Unused)
    +---------+


    Top = 2 (Index of the last pushed element)
    Fixed size, cannot grow beyond its limit.
    Elements are stored inside the structure.
```


- Dynamic Stack (Heap Allocated)
```sql

 struct Stack_t (Heap-allocated)
 +-------------------+
 | top = 2          |
 | capacity = 5     |
 | stack_array * ---|-----> Points to heap memory
 +-------------------+
```

```sql
 Heap Memory (Dynamic Array):
    +---------+
    |   30    |  <- Top (index 2)
    +---------+
    |   20    |
    +---------+
    |   10    |
    +---------+
    |         |  (Unused)
    +---------+
    |         |  (Unused)
    +---------+


Top = 2 (Last inserted element).
Heap allocated, can grow dynamically when needed.
```

- Push Operation (Adding 40)

```sql

Before:
    +---------+
    |   30    |  <- Top
    +---------+
    |   20    |
    +---------+
    |   10    |
    +---------+

After Push(40):
    +---------+
    |   40    |  <- New Top
    +---------+
    |   30    |
    +---------+
    |   20    |
    +---------+
    |   10    |
    +---------+
```

- Pop Operation (Removing 40)

```sql

Before Pop():
    +---------+
    |   40    |  <- Top
    +---------+
    |   30    |
    +---------+
    |   20    |
    +---------+

After Pop():
    +---------+
    |   30    |  <- New Top
    +---------+
    |   20    |
    +---------+
    |   10    |
    +---------+
```

- Stack Overflow (Static Stack)

```sql

Stack Full (MAX_SIZE = 5):

    +---------+
    |   50    |  <- Top (index 4)
    +---------+
    |   40    |
    +---------+
    |   30    |
    +---------+
    |   20    |
    +---------+
    |   10    |
    +---------+

PUSH(60) -> ERROR: Stack Overflow!
Cannot push because the array is full.
```

- Dynamic Stack Resizing (Heap Stack)
```sql

Before Resizing (Capacity = 5):
    +---------+
    |   50    |  <- Top
    +---------+
    |   40    |
    +---------+
    |   30    |
    +---------+
    |   20    |
    +---------+
    |   10    |
    +---------+

PUSH(60) -> Stack Resized (Capacity Doubled)

After Resizing (Capacity = 10):
    +---------+
    |   60    |  <- New Top
    +---------+
    |   50    |
    +---------+
    |   40    |
    +---------+
    |   30    |
    +---------+
    |   20    |
    +---------+
    |   10    |
    +---------+
    |         |  (New space)
    +---------+
    |         |  (New space)
    +---------+

Heap stack grows dynamically when full.
Capacity doubles to accommodate more elements.
```