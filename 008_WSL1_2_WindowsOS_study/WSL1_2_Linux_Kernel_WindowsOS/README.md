# link

- wsl
  - https://wsl.dev/
- wsl1(Windows Subsystem for Linux)
  - https://github.com/microsoft/WSL
- WSL2이제 오픈소스됨 github(250319)
  - The source for the Linux kernel used in Windows Subsystem for Linux 2 (WSL2) 
    - https://github.com/microsoft/WSL2-Linux-Kernel
  - [관련 블로그) May 19, 2025 | The Windows Subsystem for Linux is now open source By Pierre Boulay](https://blogs.windows.com/windowsdeveloper/2025/05/19/the-windows-subsystem-for-linux-is-now-open-source/)
 

<hr />

# The Windows Subsystem for Linux is now open source | May 19, 2025 | By Pierre Boulay

- 번역 원본 https://blogs.windows.com/windowsdeveloper/2025/05/19/the-windows-subsystem-for-linux-is-now-open-source/
  - 파파고로 번역하였음

- 오늘 저희는 Linux용 Windows 서브시스템의 오픈 소스 출시를 발표하게 되어 매우 기쁩니다. 이는 이를 준비하기 위한 다년간의 노력과 Microsoft/WSL 보고서에서 제기된 첫 번째 이슈인 오픈 소스가 될 수 있을까요? · Issue #1 · Microsoft/WSL.

즉, 이제 WSL을 구동하는 코드가 Microsoft/WSL의 GitHub에서 사용할 수 있으며 커뮤니티에 오픈 소스로 제공됩니다! 소스에서 WSL을 다운로드하고 빌드한 후 새로운 수정 사항과 기능을 추가하고 WSL의 활발한 개발에 참여할 수 있습니다.

# WSL component overview

- WSL은 일련의 배포 구성 요소로 구성되어 있습니다. 일부는 Windows에서 실행되고 일부는 WSL 2 가상 머신 내부에서 실행됩니다. 다음은 WSL의 아키텍처 개요입니다:

<img width="1000" height="934" alt="Image" src="https://github.com/user-attachments/assets/ac51b1c7-e4a5-43bc-813f-4fd680c9c8cf" />

## WSL’s code can be broken up into these main areas:

- Command line executables that are the entry points to interact with WSL
  - `wsl.exe`, `wslconfig.ex`e and `wslg.exe`
- The WSL service that starts the WSL VM, starts distros, mounts file access shares and more
  - `wslservice.exe`
- Linux init and daemon processes, binaries that run in Linux to provide WSL functionality
  - init for start up, gns for networking, localhost for port forwarding, etc.
- File sharing Linux files to Windows with WSL’s plan9 server implementation
  - plan9
- Head over to https://wsl.dev to learn more about each component.

- This comes as an addition to the already open sourced WSL components:

  - [microsoft/wslg: Enabling the Windows Subsystem for Linux to include support for Wayland and X server related scenarios](https://github.com/microsoft/wslg)

  - [microsoft/WSL2-Linux-Kernel: The source for the Linux kernel used in Windows Subsystem for Linux 2 (WSL2)](https://github.com/microsoft/WSL2-Linux-Kernel)

- The following components are still part of the Windows image and are not open sourced at this time:

  - `Lxcore.sys`, the kernel side driver that powers WSL 1

  - `P9rdr.sys` and `p9np.dll`, which runs the `\\wsl.localhost` filesystem redirection (from Windows to Linux)

<hr />

## 한글 번역본

### WSL의 코드는 다음과 같은 주요 영역으로 나눌 수 있습니다:
- WSL과 상호작용하기 위한 진입 지점인 명령줄 실행 파일
  - `wsl.exe`, `wslconfig.exe` and `wslg.exe`
- WSL VM을 시작하고, 디스트로를 시작하며, 파일 액세스 공유를 마운트하는 WSL 서비스 등
  - `wslservice.exe`
- Linux init 및 데몬 프로세스, WSL 기능을 제공하기 위해 Linux에서 실행되는 바이너리
  - 시작을 위한 init, 네트워킹을 위한 gns, 포트 포워딩을 위한 localhost 등.
- WSL의 plan9 서버 구현을 통해 Windows에 Linux 파일 공유
  - 플랜9

- 각 구성 요소에 대해 자세히 알아보려면 https://wsl.dev로 이동하세요.

- 이는 이미 오픈 소스 WSL 구성 요소에 추가된 것입니다:

  - Microsoft/wslg: Wayland 및 X 서버 관련 시나리오에 대한 지원을 포함하도록 Windows 하위 시스템을 Linux용으로 활성화하기

  - Microsoft/WSL2-Linux-Kernel: Windows 서브시스템 for Linux 2 (WSL2)에서 사용되는 Linux 커널의 소스

- 다음 구성 요소는 여전히 Windows 이미지의 일부이며 현재 오픈 소스가 아닙니다:

  - Lxcore.sys, WSL 1을 구동하는 커널 사이드 드라이버

  - P9rdr.sys 및 p9np.dll, "\\wsl.localhost" 파일 시스템 리디렉션을 실행합니다(Windows에서 Linux로)
