# 출처:
- https://makelinux.github.io/kernel/map/

# 유튜브 영상
- [커널 지도 ) 최고  This is How The Kernel Works - An Interactive Map of the Kernel and its Systems. | SavvyNik](https://youtu.be/BW60nfDU-Os?si=lRdaPXJuwS3NUTT2)

# LinuxKernel Source(ver 7.0 미리 살펴보자)
- https://elixir.bootlin.com/linux/v7.0-rc4/source/tools/perf/util/mutex.h

# 리눅스 커널 정리 /with MINZKN
- Linux 커널 개발자를 위한 종합 한글 레퍼런스
  - https://www.minzkn.com/linuxkernel/index.html

# C 언어 완전 가이드 & 커널 C 관용어
- 리눅스 커널 코드베이스가 실제로 사용하는 C 관용어를 표준 문법 설명을 넘어 실전 규약으로 정리합니다. GNU 확장(`__attribute__`, `typeof`, statement expression), 타입 안정 매크로(Macro)(`container_of`, `BUILD_BUG_ON`), 메모리 모델 보조 매크로(`READ_ONCE`, `WRITE_ONCE`, 배리어), 오류 포인터/정리 경로 패턴, sparse 어노테이션과 lockless 코드 주석 규칙까지 유지보수와 리뷰 관점에서 상세히 다룹니다.
- https://www.minzkn.com/linuxkernel/pages/c-language.html

# 이미지

<img src="./475277236_1022688503211799_4727994723488223723_n.jpg" />

# Figure 01: Linux Kernel Architecture Diagram
- https://dev.to/bytehackr/unlocking-the-power-of-linux-device-drivers-1llh

<img src="https://media2.dev.to/dynamic/image/width=800%2Cheight=%2Cfit=scale-down%2Cgravity=auto%2Cformat=auto/https%3A%2F%2Fdev-to-uploads.s3.amazonaws.com%2Fuploads%2Farticles%2Fu8vo44af5r456zywodbr.png" />

## 6. Writing a Simple Character Device Driver
- 간단한 리눅스 드라이버 작성해 보기
- A character device driver handles devices like serial ports that send and receive data as a stream of bytes. Below is an example of a simple character device driver that can be loaded as a kernel module.

- Example: Simple Character Device Driver

```c
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "simple_char_dev"
#define BUF_LEN 80

static char msg[BUF_LEN]; // Buffer to hold the data

// Function prototypes for character driver
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

// File operations structure
static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

static int major_num;

// Driver initialization function
static int __init simple_char_init(void) {
    major_num = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_num < 0) {
        printk(KERN_ALERT "Failed to register character device\n");
        return major_num;
    }
    printk(KERN_INFO "Simple char driver loaded with major number %d\n", major_num);
    return 0;
}

// Driver cleanup function
static void __exit simple_char_exit(void) {
    unregister_chrdev(major_num, DEVICE_NAME);
    printk(KERN_INFO "Simple char driver unloaded\n");
}

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t len, loff_t *offset) {
    int bytes_read = 0;
    if (*msg == 0)
        return 0;
    while (len && *msg) {
        put_user(*(msg++), buffer++);
        len--;
        bytes_read++;
    }
    return bytes_read;
}

static ssize_t device_write(struct file *filp, const char *buffer, size_t len, loff_t *off) {
    int i;
    for (i = 0; i < len && i < BUF_LEN; i++)
        get_user(msg[i], buffer + i);
    return i;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

module_init(simple_char_init);
module_exit(simple_char_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Author");
MODULE_DESCRIPTION("Simple Character Device Driver");
```
