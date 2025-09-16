# Linux현재 버젼은(250911기준 ver. 6.17-rc5)
- https://www.kernel.org/

- 250912기준
```
mainline: 	6.17-rc5 	2025-09-07 	
stable: 	6.16.7 	2025-09-11 	
stable: 	6.15.11 [EOL] 	2025-08-20 	
longterm: 	6.12.47 	2025-09-11 	
longterm: 	6.6.106 	2025-09-11 
longterm: 	6.1.152 	2025-09-11 	
longterm: 	5.15.193 	2025-09-11 	
longterm: 	5.10.244 	2025-09-11 	
longterm: 	5.4.299 	2025-09-09 	
linux-next: 	next-20250911 	2025-09-11
```

# zig로 만든 커널
- https://github.com/popovicu/zig-time-sharing-kernel
- **[처음부터 직접 운영체제 커널 만들기](<https://news.hada.io/topic?id=23105&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**
- **RISC-V 아키텍처**에서 **타임셰어링 운영체제 프로토타입 커널**을 구현한 경험을 공유  
- **시분할(time-sharing) 커널**의 개념과 동작 방식을 실습 중심으로 설명하며, C 대신 **Zig**로 구현해 재현성을 높임  
- 커널과 사용자 코드를 하나의 바이너리로 묶는 **unikernel** 접근을 취하고, 콘솔 출력과 타이…


# Kernel_dev_in_Rust
https://docs.kernel.org/rust/quick-start.html

# 커널 디버깅은 GDB나 LLDB로
- GDB 는 여기에 정리중.
  - https://github.com/YoungHaKim7/GDB_Debugger_Training

- LLDB 는 여기에 정리중.
  - https://github.com/YoungHaKim7/LLDB_Debugging_training
