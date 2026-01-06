#include "loading.h"
#include <stdio.h>
#include <unistd.h> // для usleep и sleep

void showLoading() {
    const char* frames[] = {
        "[=             ]", "[==            ]", "[====          ]",
        "[======        ]", "[=========     ]", "[==========    ]",
        "[===========   ]", "[============  ]", "[============= ]",
        "[==============]"
    };

    int frameCount = sizeof(frames) / sizeof(frames[0]);

    for (int i = 0; i < frameCount; i++) {
        printf("\033[2J\033[H"); // очистка экрана
        printf("%s\n", frames[i]);
        fflush(stdout);
        usleep(200000); // 0.2 секунды
    }

    printf("\033[2J\033[H");
    printf("========== Загрузка завершена ==========\n");
    fflush(stdout);
    sleep(1);
}
