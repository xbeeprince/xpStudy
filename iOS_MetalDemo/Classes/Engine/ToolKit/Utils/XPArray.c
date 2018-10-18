//
//  XPArray.c
//  iOS_MetalDemo
//
//  Created by prince on 2018/10/18.
//  Copyright © 2018 Tencent. All rights reserved.
//

#include "XPArray.h"
#include <stdlib.h>

static XPArray* Create(int elementTypeSize, int length)
{
    XPArray* array = (XPArray *) malloc (sizeof(XPArray) + elementTypeSize * length);
    array->data = (char *) array + sizeof(XPArray);
    array->lenght = length;
    return array;
}

struct AXPArray AXPArray[1] =
{
  Create,
};


