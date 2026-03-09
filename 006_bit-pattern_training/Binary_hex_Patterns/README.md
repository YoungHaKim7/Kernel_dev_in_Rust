# link

- [15 Legendary Bit Hacks]
  - [1. Clear lowest set bit]
  - [2. Extract lowest set bit]

- [Bit Twiddling Hacks](https://graphics.stanford.edu/~seander/bithacks.html)

<hr />

# 2진수 이쁘게 출력하기

```rs
fn format_bin8(x: u8) -> String {
    let s = format!("{:08b}", x);
    format!("0b{} {}", &s[0..4], &s[4..8])
}

fn main() {
    let x: u8 = 4;
    println!("{}", format_bin8(x));
}
```

- result

```bash
0b0000 0100
```

# 15 Legendary Bit Hacks[|🔝|](#link)

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


## 1. Clear lowest set bit[|🔝|](#link)

```c
x & (x - 1)
```

- Example

```bash
x      = 101100    # 0x2C    44(10dec)
x - 1  = 101011    # 0x2B    43(10dec)
result = 101000    # 0x14    20(10dec)
```

- Used for bit counting loops.

## 2. Extract lowest set bit[|🔝|](#link)

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

- Rust연습

```rs
fn main() {
    let x = 44;        // 0010 1100    // 0x2C
                      //  1101 0100  -x = -44 
    let res = x & -x;
    let res02 = x & !x;
    let res03 = x | !x;
    let minus_x = -x;  // 1101 0100    // -44(10dec)
    let nagative_x = !x;
    println!("res : {res}"); // 0000 0100
    println!("res02 : {res02}");
    println!("res03 : {res03}");
    println!("minus_x : {minus_x}");
    println!("minus_x : {:08b}", minus_x as u8);
    println!("nagative_x : {nagative_x}");
    println!("4(dec) : 0b{:08b}", res as u8); // 0000 0100
    println!("-x(44dec) binary : 0b{:08b}", minus_x as u8);
}
```

- result

```bash
res : 4
res02 : 0
res03 : -1
minus_x : -44
minus_x : 11010100
nagative_x : -45
4(dec) : 0b00000100
-x(44dec) binary : 0b11010100
```

## 3. Check power of two[|🔝|](#link)

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

- rust코드로 연습

```rs
fn main() {
    let x = 47; // 0010 1111
    //&(x-1) dec 46  // 0010 1110
    //       dec 46  // 0010 1110
    let res = (x & (x - 1)) == 0;
    println!("{res}");
}
```

- result

```bash
false
```
 
## 4. Set bits below lowest set bit[|🔝|](#link)

```c
x | (x - 1)
```

Example
```
101100
→
101111
```

- Rust code로 연습

```rs
fn main() {
    let x = 44; // 0010 1100
// (x-1) dec 43 // 0010 1011
//              // 0010 1111
    let res = x | (x - 1);
    println!("{res}");
}
```

- result

```
47   // 0010 1111
```

## 5. Clear trailing ones [|🔝|](#link)

```c
x & (x + 1)
```

- Example

```bash
101111
→
100000
```

- rust로 연습

```rs
fn main() {
    let x = 47; //      0010 1111
    //&(x+1) dec 48  // 0011 0000
    //       dec 32  // 0010 0000
    let res = x & (x + 1);
    println!("{res}");
}
```

- result

```bash
32 # 0010 0000
```



## 6. Find lowest zero bit [|🔝|](#link)

```c
//main.c
~x & (x + 1)
```

- Useful for bit allocation algorithms.

- rust코드로 연습

```rs
fn main() {
    let x = 47; // 0010 1111
    // !x            // 1101 0000
    //&(x+1) dec 48  // 0011 0000
    //       dec 16  // 0001 0000
    let res = !x & (x + 1);
    println!("{res}");
}
```

- result

```bash
16  # 0001 0000
```

# XOR operator truth table

|x|y|x XOR y|
|-|-|-|
|0|	0 |0|
|0|	1|	1|
|1|	0 |1|
|1|	1|	0|

## 7. Binary → Gray code [|🔝|](#link)

```c
// main.c
gray = x ^ (x >> 1)
```

- Example

```bash
binary:  1011
gray:    1110
```

- rust code로 연습

```rs
fn bin4(x: u8) -> String {
    format!("{:04b}", x)
}

fn main() {
    let binary = 11; // 1011
    //        x >> 1 // 0101
    //   x ^ (x >>1) // 1110
    let gray = binary ^ (binary >> 1);

    println!("x    : {}", bin4(binary));
    println!("gray : {}", bin4(gray));
}
```

- result

```bash
binary:  1011
gray:    1110
```


## [|🔝|](#link)
## [|🔝|](#link)
## [|🔝|](#link)
## [|🔝|](#link)
## [|🔝|](#link)
