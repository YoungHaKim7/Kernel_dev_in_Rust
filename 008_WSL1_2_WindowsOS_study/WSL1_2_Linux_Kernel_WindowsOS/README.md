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
