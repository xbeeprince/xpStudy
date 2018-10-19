//
//  XPArrayList.h
//  iOS_MetalDemo
//
//  Created by prince on 2018/10/19.
//  Copyright © 2018 Tencent. All rights reserved.
//

#ifndef XPArrayList_h
#define XPArrayList_h

#include <stdio.h>
#include "XPArray.h"

typedef struct {
    int increase;
    int size;
    int elementTypeSize;
    XPArray elementArray[1];
    
}XPArrayList;

struct AXPArrayList {
    XPArrayList* (*create)(int elementTypeSize);
};

extern struct AXPArrayList AXPArrayList[1];
#endif /* XPArrayList_h */
