#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
/* 1. 모듈 초기화 함수: insmod 시 호출 */
static int __init hello_init(void)
{
    pr_info("Hello, Kernel World!\\n");
    pr_info("Module loaded at %s:%d\\n", __FILE__, __LINE__);
    return 0;  /* 0 = 성공 */
}
/* 2. 모듈 종료 함수: rmmod 시 호출 */
static void __exit hello_exit(void)
{
    pr_info("Goodbye, Kernel World!\\n");
}
/* 3. 진입점 등록 */
module_init(hello_init);
module_exit(hello_exit);
/* 4. 메타데이터 */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name <your@email.com>");
MODULE_DESCRIPTION("A simple Hello World kernel module");
MODULE_VERSION("1.0");
