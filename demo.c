#include <stdio.h>

int main() {
    int luaChon;
    float thamSo;

    printf("Nhap lua chon va tham so tuong ung (cach nhau boi khoang trang): ");
    scanf("%d %f", &luaChon, &thamSo);

    // Xử lý dữ liệu dựa trên lựa chọn
    switch (luaChon) {
        case 1:
            printf("Ban da chon lua chon 1, voi tham so la: %.2f\n", thamSo);
            break;
        case 2:
            printf("Ban da chon lua chon 2, voi tham so la: %.2f\n", thamSo);
            break;
        default:
            printf("Lua chon khong hop le!\n");
    }

    return 0;
}
