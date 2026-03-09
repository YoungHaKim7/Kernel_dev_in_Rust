# link

- [15 Legendary Bit Hacks]
  - [1. Clear lowest set bit]
  - [2. Extract lowest set bit]

<hr />

# 15 Legendary Bit Hacks

| #  | Expression                         | Purpose                        |                               |
| -- | ---------------------------------- | ------------------------------ | ----------------------------- |
| 1  | `x & (x - 1)`                      | [clear lowest set bit]           |                               |
| 2  | `x & -x`                           | [extract lowest set bit]         |                               |
| 3  | `(x & (x - 1)) == 0`               | check power of two             |                               |
| 4  | `x                                 | (x - 1)`                       | set bits below lowest set bit |
| 5  | `x & (x + 1)`                      | clear trailing ones            |                               |
| 6  | `~x & (x + 1)`                     | isolate lowest zero bit        |                               |
| 7  | `x ^ (x >> 1)`                     | binary → Gray code             |                               |
| 8  | `x ^ (x >> 1) ^ (x >> 2) ...`      | Gray → binary                  |                               |
| 9  | `x >> n & 1`                       | test nth bit                   |                               |
| 10 | `x ^ (1 << n)`                     | toggle bit                     |                               |
| 11 | `x & ~(1 << n)`                    | clear bit                      |                               |
| 12 | `x                                 | (1 << n)`                      | set bit                       |
| 13 | `(x + (1 << n)) & ~((1 << n) - 1)` | align to power-of-two boundary |                               |
| 14 | `(x + y) ^ ((x ^ y) & -(x < y))`   | branchless min/max             |                               |
| 15 | `x -= ((x >> 1) & 0x55555555)`     | fast bit count (popcount step) |                               |


## 1. Clear lowest set bit

```c
x & (x - 1)
```

- Example

```bash
x      = 101100
x - 1  = 101011
result = 101000
```

- Used for bit counting loops.

## 2. Extract lowest set bit

```c
x & -x
```

- Example

```bash
101100
000100
```

- Used in
  - Fenwick trees
  - memory allocators
  - bitboards

## 3. Check power of two

```c
(x & (x - 1)) == 0
```

- Example

```bash
100000
&
011111
= 0
```

- Used everywhere:
  - kernel page sizes
  - memory alignment
  - ring buffers
 
## 
