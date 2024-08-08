#include <stdio.h>

int chucnang1(float mucNumChinh) {
    // Kiểm tra nếu mức núm chỉnh âm
    if (mucNumChinh < 0)
        return -1;

    // Kiểm tra nếu mức núm chỉnh vượt quá giới hạn
    if (mucNumChinh > 10)
        mucNumChinh = 10;

    // Tính góc tương ứng
    int goc = (int)(mucNumChinh * 36);
    return goc;
}

int chucnang2(int soNhanKhau, float m_current, float m_old) {
     // Kiểm tra nếu m_current hoặc m_old là số âm
    if (m_current < 0 || m_old < 0) {
        return -1; // Trả về -1 nếu có số âm
    }

    // Kiểm tra nếu m_current nhỏ hơn m_old
    if (m_current < m_old) {
        return -1; // Trả về -1 nếu m_current < m_old
    }

    // Tính khối lượng nước tiêu thụ
    float m = m_current - m_old;

    // Định mức sử dụng nước cho từng nhân khẩu
    float dinhMuc = m / soNhanKhau;

    // Biểu giá nước theo bậc thang
    float giaNuoc;
    if (dinhMuc <= 4) {
        giaNuoc = 6700; // Đơn giá 6.700/m3
    } else if (dinhMuc <= 6) {
        giaNuoc = 12900; // Đơn giá 12.900/m3
    } else {
        giaNuoc = 14400; // Đơn giá 14.400/m3
    }

    // Tính tiền nước trước thuế
    float tienNuoc = dinhMuc * giaNuoc;

    // Tính tiền thuế GTGT (5%)
    float thueGTGT = 0.05 * tienNuoc;

    // Tính phí dịch vụ xử lý nước thải (20%)
    float phiXuLy = 0.20 * tienNuoc;

    // Tính thuế dịch vụ xử lý nước thải (10%)
    float thuePhiXuLy = 0.10 * tienNuoc;

    // Tổng số tiền phải trả
    float tongTien = tienNuoc + thueGTGT + phiXuLy + thuePhiXuLy;

    return tongTien;
}

int tinhNangLuongThangMayA(int soTangHienTai, int soTangCanDen, int trongLuong) {
    int nangLuong = 0;

    if (soTangCanDen > soTangHienTai) { // Di len
        nangLuong = trongLuong * 12 * (soTangCanDen - soTangHienTai); // 12W/kg/tang
    } else if (soTangCanDen < soTangHienTai) { // Di xuong
        nangLuong = trongLuong * 7 * (soTangHienTai - soTangCanDen); // 7W/kg/tang
    }

    return nangLuong;
}

// Hàm tính năng lượng tiêu thụ của thang máy B (mới)
int tinhNangLuongThangMayB(int soTangHienTai, int soTangCanDen, int trongLuong) {
    int nangLuong = 0;

    if (soTangCanDen > soTangHienTai) { // Di len
        nangLuong = trongLuong * 7 * (soTangCanDen - soTangHienTai); // 7W/kg/tang
    } else if (soTangCanDen < soTangHienTai) { // Di xuong
        nangLuong = trongLuong * 5 * (soTangHienTai - soTangCanDen); // 5W/kg/tang
    }

    return nangLuong;
}

// Hàm tính năng lượng cần cấp cho thang máy dựa trên tải trọng và các thông số tầng
int chucnang3(int soTangHienTai, int soTangCanDen, int trongLuong) {
    int nangLuong = 0;

    if (trongLuong < 0) {
        // Nếu tải trọng âm, trả về -1
        return -1;
    }

    // Xác định loại thang máy cần sử dụng dựa trên tải trọng
    if (trongLuong <= 1000) {
        // Điều phối đi thang máy mới (B)
        nangLuong = tinhNangLuongThangMayB(soTangHienTai, soTangCanDen, trongLuong);
    } else if (trongLuong > 1000 && trongLuong <= 1600) {
        // Điều phối đi đồng thời cả hai thang máy (A và B)
        int nangLuongA = tinhNangLuongThangMayA(soTangHienTai, soTangCanDen,600);
        int nangLuongB = tinhNangLuongThangMayB(soTangHienTai, soTangCanDen,1000);
        nangLuong = nangLuongA + nangLuongB;
    } else if (trongLuong > 1600 && trongLuong <= 2600) {
        // Điều phối đi đồng thời cả hai thang máy cho lượt đầu tiên, và chỉ sử dụng thang máy mới (B) cho các lượt sau
        int nangLuongA = tinhNangLuongThangMayA(soTangHienTai, soTangCanDen, 600);
        int nangLuongB = tinhNangLuongThangMayB(soTangHienTai, soTangCanDen, 1000);
        nangLuong = nangLuongA + nangLuongB;
    } else {
        // Tải trọng vượt quá giới hạn cho phép
        printf("Tải trọng vượt quá giới hạn cho phép. Vui lòng kiểm tra lại.\n");
        return -1;
    }

    return nangLuong;
}

void chucnang4() {
    printf("Ban da chon lua chon 4\n");
}

void chucnang5() {
    printf("Ban da chon lua chon 5\n");
}

int main() {
    int luaChon, n2, n3, n4;
    float n1;

    printf("Nhap lua chon va tham so tuong ung: ");
    scanf("%d", &luaChon);

    // Xử lý dữ liệu dựa trên lựa chọn
    switch (luaChon) {
        case 1:
            scanf("%f", &n1);
            printf("%d", chucnang1(n1));
            break;
        case 2:
            scanf("%d %d %d", &n2,&n3,&n4);
            printf("%d", chucnang2(n2,n3,n4));
            break;
        case 3:
            scanf("%d %d %d", &n2,&n3,&n4);
            printf("%d", chucnang3(n2,n3,n4));
            break;
        case 4:
            chucnang4();
            break;
        case 5:
            chucnang5();
            break;
        default:
            printf("Lua chon khong hop le!\n");
            break;
    }

    return 0;
}
