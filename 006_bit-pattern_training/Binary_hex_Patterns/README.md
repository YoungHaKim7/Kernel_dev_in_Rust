# link

- [Why programmers group bits in 4](#why-programmers-group-bits-in-4)

- [Real kernel example(13번 참고하면됨.](#real-kernel-example13번-참고하면됨--13-align-to-power-of-two-boundary)
  - [`align up` vs `align down` vs `check aligned`](#related-famous-alignment-tricks)

- [15 Legendary Bit Hacks](#15-legendary-bit-hacks)
  - [1. Clear lowest set bit](#1-clear-lowest-set-bit)
  - [2. Extract lowest set bit](#2-extract-lowest-set-bit)
  - [3. Check power of two](#3-check-power-of-two)
  - [4. Set bits below lowest set bit](#4-set-bits-below-lowest-set-bit)
  - [5. Clear trailing ones](#5-clear-trailing-ones-)
  - [6. Find lowest zero bit](#6-find-lowest-zero-bit-)
  - [7. Binary → Gray code](#7-binary--gray-code-)
  - [8. Gray → Binary](#8-gray--binary)
  - [9. Test bit](#9-test-bit-)
  - [10. Toggle bit](#10-toggle-bit)
  - [11. Clear bit](#11-clear-bit)
  - [12. Set bit](#12-set-bit-)
  - [13. Align to power-of-two boundary](#13-align-to-power-of-two-boundary)
  - [14. Branchless min/max]()
  - [15. Fast popcount step]()

- [(외부링크) Bit Twiddling Hacks](https://graphics.stanford.edu/~seander/bithacks.html)

- [Boolean Logic](#boolean-logic)
  - https://introcs.cs.princeton.edu/java/71boolean/

- Operator Truth Table 기초
  - [NOT](#not-operator-truth-table)
  - [AND](#and-operator-truth-table)
  - [OR](#or--operator-truth-table)
  - [XOR](#xor-operator-truth-table)

<hr />

# 2진수 이쁘게 출력하기[|🔝|](#link)

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

# Boolean Logic[|🔝|](#link)
- https://introcs.cs.princeton.edu/java/71boolean/

||logic|java boolean|java bitwise|circuit design|
|-|-|-|-|-|
|NOT|$\neg x$|`!x`|`~x`|x'|
|AND|$x\land y$|`x && y`|`x & y`|xy|
|OR|$x\lor y$|`x \|\| y`|`x \| y`| x+y|
|XOR|$x \oplus y$|`x ^ y`|`x ^ y`|$x \oplus y$|

# NOT operator truth table[|🔝|](#link)

|x|x'<br />$\neg x$<br />`~x`<br />`!x`|
|-|-|
|0|	1 |
|1|	0|

# AND operator truth table[|🔝|](#link)

|x|y|x AND y<br />xy<br />$x\land y$<br />`x && y`|
|-|-|-|
|0|	0 |0|
|0|	1 |0|
|1|	0 |0|
|1|	1 |1|

# OR  operator truth table[|🔝|](#link)

|x|y|x OR y<br />x+y<br />$x\lor y$<br />`x \|\| y`|
|-|-|-|
|0|	0 |0|
|0|	1 |1|
|1|	0 |1|
|1|	1 |1|

# XOR operator truth table[|🔝|](#link)

|x|y|x XOR y<br />$x \oplus y$<br />`x ^ y`|
|-|-|-|
|0|	0 |0|
|0|	1|	1|
|1|	0 |1|
|1|	1|	0|


# Real kernel example(13번 참고하면됨. | 13. Align to power-of-two boundary)[|🔝|](#link)
- [13. Align to power-of-two boundary](#13-align-to-power-of-two-boundary)

Linux uses similar macros:

```c
// macro_c_lang.c
#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))
```

- Example:

```bash
ALIGN(13,8) = 16
ALIGN(16,8) = 16
ALIGN(17,8) = 24
```

- Rust version used in allocators

```rs
// main.rs
fn align_up(x: usize, align: usize) -> usize {
    debug_assert!(align.is_power_of_two());
    (x + align - 1) & !(align - 1)
}
```

- The `debug_assert!` ensures correctness.

## Related famous alignment tricks

| Purpose       | Expression               |
| ------------- | ------------------------ |
| align up      | `(x + a - 1) & !(a - 1)` |
| align down    | `x & !(a - 1)`           |
| check aligned | `x & (a - 1) == 0`       |


# 15 Legendary Bit Hacks[|🔝|](#link)

| #  | Expression                         | Purpose                        |      쓰이는 곳                |
| -- | ---------------------------------- | ------------------------------ | ----------------------------- |
| 1  | `x & (x - 1)`                      | [clear lowest set bit](#1-clear-lowest-set-bit)           |  Used for bit counting loops.|
| 2  | `x & -x`                           | [extract lowest set bit](#2-extract-lowest-set-bit)
| 3  | `(x & (x - 1)) == 0`               | [check power of two](#3-check-power-of-two)             |   kernel page sizes<br />memory alignment <br />ring buffers|
| 4  | `x \| (x - 1)`                     | [set bits below lowest set bit](#4-set-bits-below-lowest-set-bit) |                                |
| 5  | `x & (x + 1)`                      | [clear trailing ones](#5-clear-trailing-ones-)            |                               |
| 6  | `~x & (x + 1)`                     | [isolate lowest zero bit](#6-find-lowest-zero-bit-)        |                               |
| 7  | `x ^ (x >> 1)`                     | [binary → Gray code](#7-binary--gray-code-)             |  rotary encoders<br /> hardware counters<br />error correction |
| 8  | `x ^ (x >> 1) ^ (x >> 2) ...`      | [Gray → binary](#8-gray--binary)                  | Used in hardware decoding.  |
| 9  | `x >> n & 1`                       | [test nth bit](#9-test-bit-)                   | CPU flags<br />protocol parsers|
| 10 | `x ^ (1 << n)`                     | [toggle bit](#10-toggle-bit)                     |                               |
| 11 | `x & ~(1 << n)`                    | [clear bit](#11-clear-bit)                      |                               |
| 12 | `x \| (1 << n)`                    | [set bit](#12-set-bit-)                       |                                |
| 13 | `(x + (1 << n)) & ~((1 << n) - 1)` | [align to power-of-two boundary](#13-align-to-power-of-two-boundary) |memory allocators<br />page alignment<br />kernel slabs|
| 14 | `(x + y) ^ ((x ^ y) & -(x < y))`   | branchless min/max             |Advantages: avoids branch misprediction <br />useful in SIMD |
| 15 | `x -= ((x >> 1) & 0x55555555)`     | fast bit count (popcount step) |Part of the SWAR popcount algorithm.<br /> Counts bits in parallel inside a register. |


# Why programmers group bits in 4[|🔝|](#link)

- Because 1 hex digit = 4 bits

- Example:

```bash
0000 0100  = 0x04 = 4(decimal)
0010 1100  = 0x2C = 44(decimal)
1111 1111  = 0xFF = 255(decimal)
```

- So this format makes debugging:
  - CPU registers
  - kernel bitmasks
  - network packets
  - SIMD values
- much easier.

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
// main.rs

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
// main.rs

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
// main.rs

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
// main.rs

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
// main.rs

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
// main.rs

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

### 쓰이는곳

- Property:
- Only one bit changes between consecutive numbers, which is why Gray code is used in:
  - rotary encoders
  - Karnaugh maps
  - digital circuits
  - error-resistant counters


## 8. Gray → Binary[|🔝|](#link)

```c
// main.c
b = g
b ^= b >> 1
b ^= b >> 2
b ^= b >> 4
b ^= b >> 8
b ^= b >> 16
```

Used in hardware decoding.

- Rust Code로 연습

```rs
// main.rs

fn gray_to_binary(mut b: u32) -> u32 {
    b ^= b >> 1;
    b ^= b >> 2;
    b ^= b >> 4;
    b ^= b >> 8;
    b ^= b >> 16;
    b
}

fn main() {
    let gray: u32 = 0b1110; // Gray code
    let binary = gray_to_binary(gray);

    println!("gray   : {:04b}", gray);
    println!("binary : {:04b}", binary);
}
```

- result

```bash
gray   : 1110
binary : 1011
```

- 똑같은 기능(이게 더 눈에 들어온다.ㅋ)

```rs
// main.rs

fn gray_to_binary(mut x: u32) -> u32 {
    let mut shift = 1;
    while shift < 32 {
        x ^= x >> shift;
        shift <<= 1;
    }
    x
}
```

## 9. Test bit [|🔝|](#link)

```c
// main.c
(x >> n) & 1
```

- Example

```bash
x = 101101
n = 2
→ 1
```

- Used in:
  - CPU flags
  - protocol parsers

- Rust code로 연습

```rs
// main.rs

fn main() {
    let n = 2; //  0000 0010
    let x = 45; // 0010 1101
    // 1             // 0000 0001
    //&(x >> 2)dec11 // 0000 1011
    //       dec 1   // 0000 0001
    let res = (x >> n) & 1;
    println!("{res}");
}
```

- result

```bash
1
```

## 10. Toggle bit[|🔝|](#link)

```c
// main.c
x ^ (1 << n)
```

```bash
101100
toggle bit2
→ 101000
```

```rs
// main.rs

fn main() {
    let n = 2; //  0000 0010
    let x = 44; // 0010 1100
//   let x: u8 = 0b101100; 44dec
    // 1             // 0000 0001
    // XOR ^
    //^(1 >> 2)dec11 // 0000 0100
    //       dec 1   // 0000 0001
    // res      40   // 0010 1000
    let res = x ^ (1 << n);
    println!("{res}");
}
```

- result

```bash
40
```

## 11. Clear bit[|🔝|](#link)

```c
// main.c
x & ~(1 << n)
```

- Rust Code로 연습

```rs
// main.rs

fn main() {
    let negative_x = !(1 << 2);
    let n = 2; //   0000 0010
    let x = 45; //  0010 1101
    //  1            //  0000 0001
    // (1 << 2) 4dec //  0000 0100
    //\!(1 << 2)-5dec//  1111 1101
    //&!(1 << 2)     //  0000 1011
    //  res  41 dec  //  0010 1001
    let res = x & !(1 << n);
    println!("{negative_x}");
    println!("negative x binariy : {:8b}", negative_x as u8);
    println!("{res}");
}

```

- result

```bash
-5
negative x binari : 11111011
41
```

## 12. Set bit [|🔝|](#link)

```c
// main.c
x | (1 << n)
```

- Example

```bash
101000
set bit2
→ 101100
```


```rs
// main.rs

fn main() {
    //         1dec //   0000 0001
    let n = 2; //   0000 0010
    let x = 45; //  0010 1101
    // (1 << 2) 4dec //  0000 0100
    //| (1 << 2)     //
    //  res  45 dec  //  0010 1101
    let res = x | (1 << n);
    println!("{res}");
}
```

- result

```bash
45
```

## 13. Align to power-of-two boundary[|🔝|](#link)

```c
// main.c 
(x + (a - 1)) & ~(a - 1)
```

- is a very famous systems-programming trick used to align a number x up to the nearest multiple of a, where a is typically a power of two.

- Example align to 16

```bash
x = 37
→ 48
```
- Used in:
  - memory allocators
  - page alignment
  - kernel slabs


- This appears in:
  - OS kernels
  - memory allocators
  - page alignment
  - SIMD buffers

- Rust Code로 연습하기

```rs
// (a - 1) // 7  , a = 8
// 8   0000 1000
// 7   0000 0111
// 13  0000 1101
// +   0001 0100  (20dec)

//                       0001 0100  (20dec)
// !(a - 1) // 248u8   0b1111 1000
//                       0001 0000  (16dec)  align 16

fn align_up(x: usize, a: usize) -> usize {
    (x + (a - 1)) & !(a - 1)
}

fn main() {
    let x = 13;
    let a = 8;

    let aligned = align_up(x, a);

    let negative_a_minus = !(a - 1);

    println!("x       : {}", x);
    println!("aligned : {}", aligned);

    println!(" ~~~~");
    println!("negative!(8 -1) : {}", negative_a_minus as u8);
    println!("negative!(8 -1) : {:08b}", negative_a_minus as u8);
}
```

- result

```bash
x       : 13
aligned : 16
 ~~~~
negative!(8 -1) : 248
negative!(8 -1) : 11111000
```

## 14. Branchless min/max[|🔝|](#link)

```c
// main.c

min = y ^ ((x ^ y) & -(x < y))
```

- Advantages:
  - avoids branch misprediction
  - useful in SIMD

- Rust code로 연습하기

- MIN

```rs
fn branchless_min(x: i32, y: i32) -> i32 {
    y ^ ((x ^ y) & -((x < y) as i32))
}
```

- MAX

```rs
fn branchless_max(x: i32, y: i32) -> i32 {
    x ^ ((x ^ y) & -((x < y) as i32))
}
```

### MIN

```rs
// 10   // 0000 1010
// 6    // 0000 0110
// x ^ y // 0000 1100    // 10 dec

fn branchless_min(x: i32, y: i32) -> i32 {
    y ^ ((x ^ y) & -((x < y) as i32))
}

fn main() {
    let x = 10;
    let y = 6;

    let min = branchless_min(x, y);

    println!("x   : {}", x);
    println!("y   : {}", y);
    println!("min : {}", min);

    let test_eval = x < y as i32;
    println!("10 < 6 as i32 : {}", test_eval);
    println!("-(10 < 6 as i32) : {}", -(test_eval as i32));
    // println!("10 < 6 as i32 : {:08b}", test_eval);
}

```

- result(MIN)

```bash
x   : 10
y   : 6
min : 6
10 < 6 as i32 : false
-(10 < 6 as i32) : 0
```

### MAX

```rs
// 10   // 0000 1010
// 6    // 0000 0110
// x ^ y // 0000 1100    // 10 dec

fn branchless_max(x: i32, y: i32) -> i32 {
    x ^ ((x ^ y) & -((x < y) as i32))
}

fn main() {
    let x = 10;
    let y = 6;

    let max = branchless_max(x, y);

    println!("x   : {}", x);
    println!("y   : {}", y);
    println!("max : {}", max);

    let test_eval = x < y as i32;
    println!("10 < 6 as i32 : {}", test_eval);
    println!("-(10 < 6 as i32) : {}", -(test_eval as i32));
    // println!("10 < 6 as i32 : {:08b}", test_eval);
}

- result(MAX)

```bash
x   : 10
y   : 6
max : 10
10 < 6 as i32 : false
-(10 < 6 as i32) : 0
```
### Why this trick exists

- This appears in:
  - CPU micro-optimizations
  - vectorized math libraries
  - GPU shaders
  - compilers
  - cryptography

- because branches can cause pipeline stalls.

- Modern compilers often convert

```rs
// max
x.max(y);

// min
x.min(y);
```

- into branchless instructions automatically.

## 15. Fast popcount step [|🔝|](#link)

```c
// main.c

x -= (x >> 1) & 0x55555555
```

- is the first step of the SWAR popcount algorithm

- Counts bits in parallel inside a register.
  - (SIMD Within A Register) used to count bits in parallel.

### What 0x55555555 means

```bash
0x55555555
= 01010101 01010101 01010101 01010101
```

- It selects alternating bits.


```rs
// 214_dec                                    1101 0110
// 0x5555_5555  (1,431,655,765_dec)
// 0x5555_5555  0101 0101 0101 0101 0101 0101 0101 0101
// (x >> 1)                                   0110 1011
// &         65_dec                           0100 0001
//
// result (149_dec)
//              0000_0000_0000_0000_0000_0000_1001_0101
fn main() {
    let mut x: u32 = 0b1101_0110;

    x -= (x >> 1) & 0x5555_5555;

    println!("result: {:032b}", x);
}
```

- result

```bash
result: 0000 0000 0000 0000 0000 0000 1001 0101
```
