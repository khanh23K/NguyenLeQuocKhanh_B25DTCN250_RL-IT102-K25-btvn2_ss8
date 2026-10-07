#include <stdio.h>

struct UserAccount {
    int user_id;
    char username[51];
    int plan_type;
    int days_overdue;
    int active_devices;
};

int main() {
    struct UserAccount user_list[100];

    int n;
    int i;

    int total_revenue = 0;
    int downgraded_count = 0;

    int service_fee;
    int penalty_fee;

    do {
        printf("Nhap so luong tai khoan (1 - 100): ");
        scanf("%d", &n);

        if (n < 1 || n > 100) {
            printf("Loi: So luong tai khoan phai tu 1 den 100!\n");
        }

    } while (n < 1 || n > 100);

    for (i = 0; i < n; i++) {

        printf("\n===== TAI KHOAN %d =====\n", i + 1);

        printf("Nhap ma tai khoan: ");
        scanf("%d", &user_list[i].user_id);

        printf("Nhap ten tai khoan: ");
        scanf("%50s", user_list[i].username);

        do {
            printf("Nhap loai goi (1-Free, 2-Personal, 3-Family): ");
            scanf("%d", &user_list[i].plan_type);

            if (user_list[i].plan_type < 1 ||
                user_list[i].plan_type > 3) {
                printf("Loi: Loai goi phai tu 1 den 3!\n");
            }

        } while (user_list[i].plan_type < 1 ||
                 user_list[i].plan_type > 3);

        do {
            printf("Nhap so ngay no cuoc: ");
            scanf("%d", &user_list[i].days_overdue);

            if (user_list[i].days_overdue < 0) {
                printf("Loi: So ngay no cuoc khong duoc am!\n");
            }

        } while (user_list[i].days_overdue < 0);

        do {
            printf("Nhap so thiet bi dang ket noi: ");
            scanf("%d", &user_list[i].active_devices);

            if (user_list[i].active_devices < 0) {
                printf("Loi: So thiet bi khong duoc am!\n");
            }

        } while (user_list[i].active_devices < 0);
    }

    for (i = 0; i < n; i++) {

        service_fee = 0;
        penalty_fee = 0;

        if (user_list[i].plan_type == 1) {
            service_fee = 0;
        } else if (user_list[i].plan_type == 2) {
            service_fee = 120000;
        } else if (user_list[i].plan_type == 3) {
            service_fee = 250000;
        }

        if (user_list[i].days_overdue >= 3) {
            user_list[i].plan_type = 1;
            service_fee = 0;

            downgraded_count++;
        }

        if (user_list[i].plan_type == 2 &&
            user_list[i].active_devices > 1) {

            penalty_fee =
                (user_list[i].active_devices - 1) * 30000;
        }

        service_fee = service_fee + penalty_fee;

        total_revenue = total_revenue + service_fee;

        if (user_list[i].plan_type == 1) {
            service_fee = 0;
        }
    }

    printf("\n\n");
    printf("===============================================================\n");
    printf("       BAO CAO DOI SOAT TAI KHOAN STREAMFLOW SAAS\n");
    printf("===============================================================\n");

    printf("%-10s %-15s %-10s %-15s %-15s %-20s\n",
           "MA TK",
           "TEN TK",
           "MA GOI",
           "SO THIET BI",
           "SO NGAY NO",
           "PHI THUC THU");

    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {

        service_fee = 0;
        penalty_fee = 0;

        if (user_list[i].plan_type == 1) {
            service_fee = 0;
        } else if (user_list[i].plan_type == 2) {
            service_fee = 120000;
        } else if (user_list[i].plan_type == 3) {
            service_fee = 250000;
        }

        if (user_list[i].plan_type == 2 &&
            user_list[i].active_devices > 1) {

            penalty_fee =
                (user_list[i].active_devices - 1) * 30000;
        }

        service_fee = service_fee + penalty_fee;

        printf("%-10d %-15s %-10d %-15d %-15d %-20d\n",
               user_list[i].user_id,
               user_list[i].username,
               user_list[i].plan_type,
               user_list[i].active_devices,
               user_list[i].days_overdue,
               service_fee);
    }

    printf("--------------------------------------------------------------------------\n");

    printf("Tong doanh thu thuc te thu duoc: %d VND\n",
           total_revenue);

    printf("Tong so tai khoan bi ha cap ve Free: %d\n",
           downgraded_count);

    printf("===============================================================\n");

    return 0;
}
