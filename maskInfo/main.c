//
//  main.c
//  maskInfo
//
//  Created by Fabio Martino on 19/08/2015.
//  Copyright (c) 2015 Fabio Martino. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

void csrInfo(int crsValue, bool custom);

int main()
{
    int crsValue = 255; // 0xFF
    if ( (crsValue >= 0) && (crsValue <= 255) ) {
        csrInfo(crsValue, 1);
    } else {
        csrInfo(3, 0);
    }
}

void csrInfo(int csrValue, bool custom)
{
    int mask = 0x080;
    printf("\nSystem Integrity Protection status: %s ", (csrValue == 0) ? "enabled":"disabled");
    printf("(%s Configuration).\nCsrActiveConfig = 0x%02X (", custom ? "Custom":"Default", csrValue);
    ((csrValue & 0x020) == 0) ? printf("0"): printf("1");
    while (mask != 0) {
        ( ((csrValue & mask) == 0) ? printf("0") : printf("1") );
        mask = mask >> 1;
    }
    printf(")\n");
    if (csrValue != 0){
        printf("\nConfiguration:\n");
        printf("Untrusted Kexts: %s\n", ((csrValue & 0x001) == 0) ? "enabled":"disabled");           /* (1 << 0) Allow untrusted kexts */           //
        printf("Unrestricted FS: %s\n", ((csrValue & 0x002) == 0) ? "enabled":"disabled"); /* (1 << 1) Allow unrestricted file system. */ //
        printf("Task for PID: %s\n", ((csrValue & 0x004) == 0) ? "enabled":"disabled");           /* (1 << 2) */                                 //
        printf("Kernel Debugger: %s\n", ((csrValue & 0x008) == 0) ? "enabled":"disabled"); /* (1 << 3) */                                 //
        printf("Apple Internal: %s\n", ((csrValue & 0x010) == 0) ? "enabled":"disabled");         /* (1 << 4) */                                 //
        printf("Unrestricted DTrace: %s\n", ((csrValue & 0x020) == 0) ? "enabled":"disabled");    /* (1 << 5) Allow unrestricted dtrace */       //
        printf("Unrestricted NVRAM: %s\n", ((csrValue & 0x040) == 0) ? "enabled":"disabled");      /* (1 << 6) Allow unrestricted NVRAM */        //
        printf("Device Configuration: %s\n", ((csrValue & 0x080) == 0) ? "enabled":"disabled");      /* (1 << 7) Device Configuration */        //
        printf("Any Recovery OS: %s\n\n", ((csrValue & 0x100) == 0) ? "enabled":"disabled");      /* (1 << 8) Any Recovery OS */        //
    }
}

