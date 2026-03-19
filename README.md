# link

- [linux 커널 현재 최신버젼(250911기준 ver. 6.17-rc5)](#linux커널_현재-버젼)


- [Kernel_dev_in_Rust](#kernel_dev_in_rust)

- [Rust로 리눅스 커널 개발 최신 소식](#rust로-linux커널-개발-관련-최신-소식)
  - [(251017)_리눅스 커널 개발을 위한 Rust 언어의 새로운 기능들](#251017리눅스-커널-개발을-위한-rust-언어의-새로운-기능들)
  - [Asterinas - 새로운 Linux-호환 커널 프로젝트(Linux를 대체할 수 있으며, 메모리 안전성 과 개발자 친화성 을 향상시킴)](./001_x86_64_Linux_Kernel_Training#asterinas---%EC%83%88%EB%A1%9C%EC%9A%B4-linux-%ED%98%B8%ED%99%98-%EC%BB%A4%EB%84%90-%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8)


- 커널(Kernel dev.)기초 상식
  - [커널 뉴비 자료 굿](#커널-뉴비-자료-굿)
  - [(250827) Every CPU Architecture Explained in Detail | Tech in a Teacup](#250827-every-cpu-architecture-explained-in-detail--tech-in-a-teacup)

- C언어를 러스트로 전환하는 프로젝트(Rust C interop)
  - [Rust C interop](#rust-c-interop)

<hr />

# Linux커널_현재 버젼[|🔝|](#link)
- (260315기준 ver. 7.0-rc4)
- https://www.kernel.org/

- 260127기준
```
mainline: 	7.0-rc4 	2026-03-15 	
stable: 	6.19.8 	2026-03-13 
longterm: 	6.18.18 	2026-03-13 
longterm: 	6.12.77 	2026-03-13 
longterm: 	6.6.129 	2026-03-05 
longterm: 	6.1.166 	2026-03-05 
longterm: 	5.15.202 	2026-03-04 	
longterm: 	5.10.252 	2026-03-04 
linux-next: 	next-20260318 	2026-03-18 				
```

# 커밋 보면서 커널 공부
- 리눅스 커널 commit 보기
  - https://lore.kernel.org/all/?t=20251105135512
  - https://lore.kernel.org/all/

- [토발즈행님 메일헤더 분석 | 우분투한국커뮤니티](https://discourse.ubuntu-kr.org/t/topic/48700)

# Kernel_dev_in_Rust[|🔝|](#link)
https://docs.kernel.org/rust/quick-start.html

# 커널 디버깅은 GDB나 LLDB로[|🔝|](#link)
- GDB 는 여기에 정리중.
  - https://github.com/YoungHaKim7/GDB_Debugger_Training

- LLDB 는 여기에 정리중.
  - https://github.com/YoungHaKim7/LLDB_Debugging_training

# (250827) Every CPU Architecture Explained in Detail | Tech in a Teacup[|🔝|](#link)
- Harvard / V. Neumann / RISC / EPIC / CISC / x86 / Arm / Hybrid 차이점 그림을 이해하기
  - https://youtu.be/6tbNew87fZU?si=kx0qKpdK2-Xu4jDd

# 커널 뉴비 자료 굿[|🔝|](#link)
- https://kernelnewbies.org/LinuxChanges#Linux_6.16.Networking

# Rust C interop[|🔝|](#link)
- https://www.reddit.com/r/rust/comments/90s2no/rust_c_interop/
- I read that I can use C libraries from Rust using FFI https://doc.rust-lang.org/1.9.0/book/ffi.html .
  - My question is are there any performance issues related to calling C code from Rust? (think Java JNI issue). Are there any gotchas around calling C code from Rust? This book chapter does not say much

<hr />

<hr />

# Pin이거 죽어라 파야함
- https://news.hada.io/topic?id=23716&utm_source=discord&utm_medium=bot&utm_campaign=1480
- https://github.com/rust-lang/rust/pull/146307

- Field Projection (필드 프로젝션)
  - 구조체 포인터에서 특정 필드 포인터를 추출하는 기능으로, C의 &(r->field) 표현을 Rust에서 일반화하려는 시도임
  - 기존에는 참조(&) 와 *포인터(mut) 에서만 가능했으나, 사용자 정의 스마트 포인터에서는 제한이 있었음
  - Rust for Linux는 이를 확장해, 모든 포인터 타입에서 동일 문법으로 필드 접근이 가능하도록 추진 중임
  - 특히 Pin 타입(이동 불가 구조체)을 다루는 경우, 필드 투영 시 Pin<&mut Field> 또는 &mut Field 로 자동 변환되도록 설계됨
  - 이 기능이 구현되면 RCU(Read-Copy-Update) 패턴을 Rust에서 안전하게 지원할 수 있어, 락(lock) 없이도 고성능 데이터 접근이 가능해짐
  - 현재 GitHub의 [tracking issue](https://github.com/rust-lang/rust/pull/146307)에서 논의 중이며, Debian 14(2027) 이전 안정화를 목표로 함


<hr />

# Rust로 Linux커널 개발 관련 최신 소식[|🔝|](#link)

# (251211)러스트 커널 접수 완료 👍[|🔝|](#link)

# (251211)**[리눅스 커널에서의 Rust 실험 (성공적) 종료](<https://news.hada.io/topic?id=24987&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- 리눅스 커널 내 **Rust 통합 작업**이 실험 단계를 마치고 **정식 구성 요소**로 인정됨  
- 연례 **Maintainers Summit**에서 개발자들이 Rust 지원을 **영구적 기능으로 채택**하기로 합의  
- 이에 따라 커널 내 Rust 관련 코드에서 **‘experimental’ 태그가 제거**될 예정  
- LWN 편집자는 “실험은 끝났고, 성공…

# (251017)**[리눅스 커널 개발을 위한 Rust 언어의 새로운 기능들](<https://news.hada.io/topic?id=23716&utm_source=discord&utm_medium=bot&utm_campaign=1480>)**[|🔝|](#link)
- Rust for Linux 프로젝트가 **커널 개발에 필요한 핵심 언어 기능**을 추진하며, Rust 언어 자체 발전에 기여하고 있음  
- **필드 프로젝션(Field Projection)**, **제자리 초기화(In-place Initialization)**, **임의 Self 타입(Arbitrary Self Types)** 세 가지가 핵심  
- 이 기능들은 **스마트 포인터, 고정 메모…
