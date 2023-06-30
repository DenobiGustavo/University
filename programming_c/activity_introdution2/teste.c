    #include <stdio.h>

    int main() {
        int x, y, z;

        int verification_biggest_1, verification_biggest_2, verification_biggest_3;
        
        int verification_second_1, verification_second_2, verification_second_3;
       
        int verification_less_1, verification_less_2, verification_less_3;

        int verifications_biggest[3];
        int verifications_second[3];
        int verifications_less[3];

        printf("x: ");
        scanf("%d", &x);
        printf("y: ");
        scanf("%d", &y);
        printf("z: ");
        scanf("%d", &z);

        verification_biggest_1 = (x > y && x > z);
        verification_biggest_2 = (y > x && y > z);
        verification_biggest_3 = (z > y && z > x);
        
        verification_second_1 = (x < y && x > z) || (x > y && x < z);
        verification_second_2 = (y < z && y > z) || (y > x && y < z);
        verification_second_3 = (z < x && z > y) || (z > x && z < y);
        
        verification_less_1 = (x < y && x < z);
        verification_less_2 = (y < x && y < z);
        verification_less_3 = (z < y && z < x);

        verifications_biggest[0] = verification_biggest_1;
        verifications_biggest[1] = verification_biggest_2;
        verifications_biggest[2] = verification_biggest_3;

        verifications_second[0] = verification_second_1;
        verifications_second[1] = verification_second_2;
        verifications_second[2] = verification_second_3;

        verifications_less[0] = verification_less_1;
        verifications_less[1] = verification_less_2;
        verifications_less[2] = verification_less_3;

        for (int i = 0; i <= 3; i++) {
            if (verifications_biggest[i] == 1) {
                printf("%d Funcionouy!!", verifications_biggest[i]);
            }
        }
    }