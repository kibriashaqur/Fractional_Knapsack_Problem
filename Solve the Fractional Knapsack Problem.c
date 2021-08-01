#include <stdio.h>

int number = 5; ///Total number of Object
int cost[10] = {12, 1, 2, 1, 4}; ///cost of the objet
int value[10] = {4, 2, 2, 1, 10}; ///value of the object
int weight = 15; ///maximum weight can take
void simple_fill() {
    int carried_weight;
    float total_value;
    int i, max_i;
    int used[10];

    for (i = 0; i < number; ++i){
        used[i] = 0; ///carried value is empty
    }
    carried_weight = weight;
    while (carried_weight > 0) { ///Hear we are finding the best object which are abaleable in the room
        max_i = -1;
        for (i = 0; i < number; ++i)
            if ((used[i] == 0) && ((max_i == -1) || ((float)value[i]/cost[i] > (float)value[max_i]/cost[max_i]))){
                max_i = i;
            }
        used[max_i] = 1;
        carried_weight -= cost[max_i]; ///minimum value can take in the bag.
        total_value += value[max_i];
        if (carried_weight >= 0){
            printf("\nTaken object %d (%dtk, %dKg) : %d.\n", max_i + 1, value[max_i]);
            printf("Completely in the bag. : %d.\n", cost[max_i]);
            printf("Space left: %d.\n", carried_weight);

        }
        else {
            printf("\nTaken %d (%dtk, %dKg) of object %d in the bag.\n", (int)((1 + (float)carried_weight/cost[max_i]) * 100), value[max_i], cost[max_i], max_i + 1);
            total_value -= value[max_i];
            total_value += (1 + (float)carried_weight/cost[max_i]) * value[max_i];
        }
    }

    printf("Filled the bag with objects worth %.2ftk.\n", total_value);
}

int main(int argc, char *argv[]) {
    simple_fill();

    return 0;
}
